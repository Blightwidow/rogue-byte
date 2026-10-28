#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""identify_sdk.py <library dir or .a file>... [--elf FILE] [--out FILE] - finds the objects of Sony's SDK libraries inside the executable.

  python3 scripts/sdk/identify_sdk.py work/sdk/sce_ps2_sdk_24 --out work/sdk/identified.tsv      (from the repository root)

Retail linked the SDK's static libraries into the executable, so each member (an object file) of a library sits in it as one run of code,
unchanged except for the fields the linker filled in: call targets (R_MIPS_26), `%hi`/`%lo` halves and `$gp`-relative offsets. For
every member of every library given, the code section is compared word for word with the executable's code, the relocated fields
masked (their positions come from the member's relocation table). A member that matches at an address names the functions in it.
Libraries are never copied or published: the tool reads them from wherever the user keeps them, and the output holds addresses, names and
library/member names only (address, length in bytes, library, member, how many places it matched, symbols as name@offset).

The match needs three consecutive unrelocated words as an anchor, so members shorter than that are skipped."""
import argparse
import collections
import os
import struct
import sys

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

MASK_26, MASK_16, MASK_32 = 0x03FFFFFF, 0x0000FFFF, 0xFFFFFFFF
RELOCATION_MASKS = {2: MASK_32, 4: MASK_26, 5: MASK_16, 6: MASK_16, 7: MASK_16, 10: MASK_16, 11: MASK_32}  # R_MIPS_32, 26, HI16, LO16, GPREL16, PC16, GPREL32


def archive_members(path):
    """(member name, bytes) of a Unix `ar` archive, GNU long names resolved."""
    data = open(path, 'rb').read()
    if data[:8] != b'!<arch>\n':
        return
    names, position = b'', 8
    while position + 60 <= len(data):
        header = data[position:position + 60]
        name, size = header[:16].decode('latin1').strip(), int(header[48:58])
        body = data[position + 60:position + 60 + size]
        position += 60 + size + (size & 1)
        if name == '//':
            names = body
            continue
        if name in ('/', '/SYM64/'):
            continue
        if name.startswith('/') and name[1:].isdigit():
            end = names.index(b'\n', int(name[1:]))
            name = names[int(name[1:]):end].decode('latin1').rstrip('/')
        yield name.rstrip('/'), body


def object_text(blob):
    """(code bytes, mask words, [(offset, symbol name)]) of an object's .text, or None."""
    import io
    elf = ELFFile(io.BytesIO(blob))
    text = elf.get_section_by_name('.text')
    if text is None or text['sh_size'] < 12:
        return None
    code = text.data()
    masks = [0] * (len(code) // 4)
    index = elf.get_section_index('.text')
    for section in elf.iter_sections():
        if isinstance(section, RelocationSection) and section['sh_info'] == index:
            for relocation in section.iter_relocations():
                offset = relocation['r_offset']
                if offset // 4 < len(masks):
                    masks[offset // 4] |= RELOCATION_MASKS.get(relocation['r_info_type'], MASK_32)
    symbols = []
    table = elf.get_section_by_name('.symtab')
    if table is not None:
        for symbol in table.iter_symbols():
            if symbol['st_shndx'] == index and symbol.name and not symbol.name.startswith(('$', '.')) and symbol['st_info']['type'] in ('STT_FUNC', 'STT_NOTYPE'):
                symbols.append((symbol['st_value'], symbol.name))
    return code, masks, sorted(set(symbols))


def executable_words(path, low, high):
    """{address: word} of the executable's loadable bytes inside [low, high)."""
    words = {}
    with open(path, 'rb') as handle:
        elf = ELFFile(handle)
        for segment in elf.iter_segments():
            if segment['p_type'] != 'PT_LOAD':
                continue
            data, start = segment.data(), segment['p_vaddr']
            for offset in range(0, len(data) - 3, 4):
                address = start + offset
                if low <= address < high:
                    words[address] = struct.unpack_from('<I', data, offset)[0]
    return words


def near_match(member_words, masks, words, pairs):
    """(share of equal unrelocated words, start address) of the best placement of a member, anchored on any two consecutive unrelocated words."""
    best = None
    seen = set()
    for index in range(len(member_words) - 1):
        if masks[index] or masks[index + 1]:
            continue
        for candidate in pairs.get((member_words[index], member_words[index + 1]), []):
            start = candidate - index * 4
            if start in seen:
                continue
            seen.add(start)
            total = equal = 0
            for position, word in enumerate(member_words):
                if masks[position] == MASK_32:
                    continue
                total += 1
                equal += ((words.get(start + 4 * position, ~word) ^ word) & ~masks[position] & 0xFFFFFFFF) == 0
            if total and (best is None or equal / total > best[0]):
                best = (equal / total, start)
    return best


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('libraries', nargs='+')
    parser.add_argument('--elf', default='work/elf/SCUS_973.16')
    parser.add_argument('--low', type=lambda text: int(text, 0), default=0x2319E8)
    parser.add_argument('--high', type=lambda text: int(text, 0), default=0x256CE8)
    parser.add_argument('--out', default='work/sdk/identified.tsv')
    parser.add_argument('--near', type=float, default=0.0, help='also report members without an exact match whose unrelocated words equal the executable\'s at least this share (0.8 is a good start), as `near` rows')
    arguments = parser.parse_args()
    paths = []
    for entry in arguments.libraries:
        paths += sorted(os.path.join(root, name) for root, _, files in os.walk(entry) for name in files if name.endswith('.a')) if os.path.isdir(entry) else [entry]
    words = executable_words(arguments.elf, arguments.low, arguments.high)
    addresses = sorted(words)
    anchors = collections.defaultdict(list)
    for address in addresses:
        if address + 8 in words and address + 4 in words:
            anchors[(words[address], words[address + 4], words[address + 8])].append(address)
    pairs = collections.defaultdict(list)
    for address in addresses:
        if address + 4 in words:
            pairs[(words[address], words[address + 4])].append(address)
    rows, skipped = [], 0
    for path in paths:
        library = os.path.basename(path)
        for member, blob in archive_members(path):
            try:
                found = object_text(blob)
            except Exception:
                found = None
            if not found:
                skipped += 1
                continue
            code, masks, symbols = found
            member_words = struct.unpack(f'<{len(code) // 4}I', code[:len(code) // 4 * 4])
            anchor = next((index for index in range(len(member_words) - 2) if not (masks[index] | masks[index + 1] | masks[index + 2])), None)
            if anchor is None:
                skipped += 1
                continue
            hits = []
            for candidate in anchors.get(tuple(member_words[anchor:anchor + 3]), []):
                start = candidate - anchor * 4
                if all(((words.get(start + 4 * index, ~word) ^ word) & ~masks[index] & 0xFFFFFFFF) == 0 for index, word in enumerate(member_words)):
                    hits.append(start)
            for start in hits:
                rows.append((start, len(member_words) * 4, library, member, len(hits), ' '.join(f'{name}@{offset:X}' for offset, name in symbols), 'exact'))
            if not hits and arguments.near:
                best = near_match(member_words, masks, words, pairs)
                if best and best[0] >= arguments.near:
                    rows.append((best[1], len(member_words) * 4, library, member, 1, ' '.join(f'{name}@{offset:X}' for offset, name in symbols), f'near {best[0]:.2f}'))
    rows.sort()
    os.makedirs(os.path.dirname(arguments.out) or '.', exist_ok=True)
    with open(arguments.out, 'w') as out:
        out.write('address\tbytes\tlibrary\tmember\tplaces\tsymbols\tkind\n')
        for start, size, library, member, places, symbols, kind in rows:
            out.write(f'0x{start:X}\t{size}\t{library}\t{member}\t{places}\t{symbols}\t{kind}\n')
    print(f'{len(rows)} member matches from {len(paths)} libraries ({skipped} members too short or without code) -> {arguments.out}')


if __name__ == '__main__':
    sys.exit(main())
