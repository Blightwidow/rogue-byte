#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""match.py: compare functions of compiled objects with a target ELF (relocated fields masked).

  match.py --elf <target elf> --map <name\taddr tsv> <obj.o>...
Prints per function: status (exact / sizediff / N words differ), and a summary line.
Library use: compare_object(obj_path, target_words_at, name_to_address) -> list of results.
"""
import struct, argparse
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

def load_target(path):
    data = open(path, 'rb').read()
    phoff = struct.unpack_from('<I', data, 0x1c)[0]
    phentsize, phnum = struct.unpack_from('<HH', data, 0x2a)
    segments = []
    for index in range(phnum):
        kind, offset, vaddr, paddr, filesz, memsz, flags, align = struct.unpack_from('<8I', data, phoff + index * phentsize)
        if kind == 1: segments.append((vaddr, offset, filesz))
    def word_at(address):
        for vaddr, offset, filesz in segments:
            if vaddr <= address < vaddr + filesz:
                return struct.unpack_from('<I', data, offset + address - vaddr)[0]
        return None
    return word_at

RELOC_MASK = {4: 0xfc000000, 5: 0xffff0000, 6: 0xffff0000, 7: 0xffff0000}  # R_MIPS_26, HI16, LO16, GPREL16

def object_functions(path):
    elf = ELFFile(open(path, 'rb'))
    text_index = None; text = None
    for index, section in enumerate(elf.iter_sections()):
        if section.name == '.text': text_index = index; text = section.data()
    masks = {}
    for section in elf.iter_sections():
        if isinstance(section, RelocationSection) and section['sh_info'] == text_index:
            symtab = elf.get_section(section['sh_link'])
            for relocation in section.iter_relocations():
                masks[relocation['r_offset']] = (RELOC_MASK.get(relocation['r_info_type'], 0), symtab.get_symbol(relocation['r_info_sym']).name)
    functions = []
    symtab = elf.get_section_by_name('.symtab')
    for symbol in symtab.iter_symbols():
        if symbol['st_info']['type'] == 'STT_FUNC' and symbol['st_shndx'] == text_index and symbol['st_size'] > 0:
            start = symbol['st_value']; size = symbol['st_size']
            words = list(struct.unpack_from('<%dI' % (size // 4), text, start))
            word_masks = [masks.get(start + 4 * position, (0xffffffff, None))[0] for position in range(size // 4)]
            functions.append((symbol.name, words, word_masks))
    return functions

def compare(words, word_masks, word_at, address, target_size=None):
    target = [word_at(address + 4 * position) for position in range(len(words))]
    # trailing nops in the object (alignment) are allowed when the target's function is shorter
    trimmed = len(words)
    if target_size is not None:
        while trimmed > target_size // 4 and words[trimmed - 1] == 0: trimmed -= 1
        if trimmed != target_size // 4: return 'size %d vs %d' % (trimmed * 4, target_size), None
    differing = [position for position in range(trimmed) if target[position] is None or (words[position] & word_masks[position]) != (target[position] & word_masks[position])]
    return ('exact' if not differing else '%d/%d differ' % (len(differing), trimmed)), differing

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--elf', required=True); parser.add_argument('--map', required=True)
    parser.add_argument('objects', nargs='+')
    arguments = parser.parse_args()
    word_at = load_target(arguments.elf)
    name_to = {}
    for line in open(arguments.map):
        parts = line.rstrip('\n').split('\t')
        if len(parts) >= 2 and parts[1]:
            name_to[parts[0]] = (int(parts[1], 16), int(parts[2]) if len(parts) > 2 and parts[2] else None)
    exact = total = 0
    for path in arguments.objects:
        for name, words, word_masks in object_functions(path):
            if name not in name_to: continue
            address, size = name_to[name]
            status, differing = compare(words, word_masks, word_at, address, size)
            total += 1; exact += status == 'exact'
            print('%-8x %-40s %s' % (address, name[:40], status))
    print('SUMMARY exact %d of %d' % (exact, total))
