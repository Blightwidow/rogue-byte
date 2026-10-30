#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""pair_versions.py [--other work/elf/SCES_525.29] [--out config/eu/map.tsv] - pairs the functions of the US executable with the other version's.

  .venv/bin/python scripts/pair_versions.py

Both `.text` sections are read as words and normalised: the target of a j/jal, the immediate of a lui/ori/addiu/load/store (an address part,
or a constant: the two cannot be told apart without relocations) are dropped, so a function that moved but did not change reads the same in
both versions. Each US function (data/matching/functions.tsv) is then looked up in the other `.text`: a function whose whole normalised
sequence occurs there, in order after the previous pair, is `same` (and `identical` when its raw bytes are equal too: no address inside it
moved); the functions between two paired anchors are paired by position when the two gaps hold the same number of words (`gap`, the
code changed in place or its layout did) and `none` when they cannot be paired.

Writes the map as `us_address, other_address, size, other_size, status` (addresses only, no game bytes) and prints the counts."""
import argparse
import csv
import os
import struct
import sys
from collections import defaultdict

from elftools.elf.elffile import ELFFile

LAB = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
LOADS_STORES = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B, 0x2E, 0x31, 0x39, 0x37, 0x3F, 0x1E, 0x1F, 0x36, 0x3D, 0x32, 0x3A}
IMMEDIATES = {0x08, 0x09, 0x0C, 0x0D, 0x0E, 0x0F, 0x0A, 0x0B} | LOADS_STORES
SHINGLE = 6
WINDOW = 2000  # words around the expected position (the whole text grows by 660 words)


def text_of(path):
    with open(path, 'rb') as handle:
        section = ELFFile(handle).get_section_by_name('.text')
        base, data = section['sh_addr'], section.data()
    return base, list(struct.unpack(f'<{len(data) // 4}I', data))


def normalise(word):
    opcode = word >> 26
    if opcode in (0x02, 0x03):  # j, jal: the target moves
        return word & 0xFC000000
    if opcode in IMMEDIATES:  # an address part or a constant
        return word & 0xFFFF0000
    return word


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--us', default=os.path.join(LAB, 'work', 'elf', 'SCUS_973.16'))
    parser.add_argument('--other', default=os.path.join(LAB, 'work', 'elf', 'SCES_525.29'))
    parser.add_argument('--out', default=os.path.join(LAB, 'config', 'eu', 'map.tsv'))
    arguments = parser.parse_args()
    us_base, us_words = text_of(arguments.us)
    other_base, other_words = text_of(arguments.other)
    us_norm, other_norm = [normalise(word) for word in us_words], [normalise(word) for word in other_words]
    index = defaultdict(list)
    for position in range(len(other_norm) - SHINGLE):
        index[tuple(other_norm[position:position + SHINGLE])].append(position)
    functions = []
    for row in csv.DictReader(open(os.path.join(LAB, 'data', 'matching', 'functions.tsv'), encoding='utf-8'), delimiter='\t'):
        address, size = int(row['address'], 16), int(row['size'])
        if us_base <= address < us_base + len(us_words) * 4 and size >= 4:
            functions.append((address, size, row['name']))
    functions.sort()
    pairs = {}
    cursor, drift = 0, (other_base - us_base) // 4
    for address, size, _ in functions:
        start = (address - us_base) // 4
        count = size // 4
        wanted = us_norm[start:start + count]
        if count < SHINGLE:
            continue
        expected = start + drift  # the layout moves slowly: a real counterpart sits near where the previous pair put the drift
        candidates = [position for position in index.get(tuple(wanted[:SHINGLE]), ()) if position >= cursor and abs(position - expected) <= WINDOW
                      and other_norm[position:position + count] == wanted]
        if candidates:
            position = min(candidates, key=lambda candidate: abs(candidate - expected))
            pairs[address] = (other_base + position * 4, 'identical' if other_words[position:position + count] == us_words[start:start + count] else 'same')
            cursor, drift = position + count, position - start
    # the functions between two anchors: paired by position when the gaps have the same length
    paired = sorted(pairs)
    status = {}
    for address, size, _ in functions:
        if address in pairs:
            status[address] = (pairs[address][0], pairs[address][1])
    anchors = [(a, pairs[a][0]) for a in paired]
    previous_us_end, previous_other_end = us_base, other_base
    gap_groups = []
    for address, other in anchors + [(us_base + len(us_words) * 4, other_base + len(other_words) * 4)]:
        gap_groups.append((previous_us_end, address, previous_other_end, other))
        size = next((s for a, s, _ in functions if a == address), 0)
        previous_us_end, previous_other_end = address + size, other + size
    by_address = {address: (size, name) for address, size, name in functions}
    for us_start, us_end, other_start, other_end in gap_groups:
        inside = [(a, by_address[a][0]) for a, _, _ in functions if us_start <= a < us_end and a not in pairs]
        if not inside:
            continue
        if us_end - us_start == other_end - other_start:  # same length: the same layout, the code changed in place
            for a, _ in inside:
                status[a] = (other_start + (a - us_start), 'gap')
    os.makedirs(os.path.dirname(arguments.out), exist_ok=True)
    counts = defaultdict(int)
    bytes_by = defaultdict(int)
    with open(arguments.out, 'w', encoding='utf-8') as handle:
        handle.write('us_address\tother_address\tsize\tstatus\n')
        for address, size, _ in functions:
            other, kind = status.get(address, (None, 'none'))
            counts[kind] += 1
            bytes_by[kind] += size
            handle.write(f'{address:#X}\t{other:#X}\t{size}\t{kind}\n' if other is not None else f'{address:#X}\t\t{size}\tnone\n')
    total, total_bytes = len(functions), sum(size for _, size, _ in functions)
    for kind in ('identical', 'same', 'gap', 'none'):
        print(f'{kind:10} {counts[kind]:5} functions  {bytes_by[kind]:8} bytes  {100 * bytes_by[kind] / total_bytes:5.1f}%')
    print(f'{total} US functions, {total_bytes} bytes; the other .text is {len(other_words) * 4} bytes ({len(other_words) * 4 - len(us_words) * 4:+d})')
    return 0


if __name__ == '__main__':
    sys.exit(main())
