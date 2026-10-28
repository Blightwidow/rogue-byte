#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""prologue_profile.py <executable> [--functions FILE] [--step HEX] - tells code built by different compilers apart by how functions save registers.

  .venv/bin/python scripts/build/prologue_profile.py work/elf/SCUS_973.16          (from the repository root)

A compiler decides how a prologue spills the callee-saved registers: store instruction (`sd`, `sq`, `sw`), the distance between slots (8 or
16 bytes), whether `$ra` goes first, and whether floating point registers are saved with `swc1`. Those choices are the same for every
function one compiler built and differ between compiler builds, so a change in the mix along the addresses marks a unit boundary or
another compiler (another SDK or library build). The tool finds the first `addiu $sp, $sp, -N` of every function, reads the stores to the
frame that follow, and prints per address window how many functions fall in each class, plus the windows whose mix differs from the one
before. Function starts come from the registry (`data/matching/functions.tsv` by default), a text file with one hexadecimal address per line
or the first column of a TSV."""
import argparse
import collections
import os
import struct

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
SAVED = set(range(16, 24)) | {30, 31}
OPCODES = {0x2B: 'sw', 0x3F: 'sd', 0x1F: 'sq'}


def instructions(elf, start, count):
    """The words of .text from start (address) on."""
    base = elf['address']
    offset = start - base
    if offset < 0 or offset + count * 4 > len(elf['data']):
        return []
    return list(struct.unpack_from(f'<{count}I', elf['data'], offset))


def classify(words):
    """A class name for the prologue in words, or None when it has no frame."""
    frame = None
    for position, word in enumerate(words[:4]):
        if word >> 16 == 0x27BD and word & 0x8000:  # addiu $sp, $sp, -N
            frame = 0x10000 - (word & 0xFFFF)
            start = position + 1
            break
    if frame is None:
        return None
    saves = []
    float_saves = 0
    for word in words[start:start + 20]:
        opcode, base, register, offset = word >> 26, (word >> 21) & 31, (word >> 16) & 31, word & 0xFFFF
        if base != 29:
            continue
        if opcode in OPCODES and register in SAVED:
            saves.append((OPCODES[opcode], register, offset))
        elif opcode == 0x39:  # swc1
            float_saves += 1
    if not saves:
        return 'frame, no saves'
    kinds = ''.join(sorted({kind for kind, _, _ in saves}))
    offsets = [offset for _, _, offset in saves]
    strides = sorted({abs(second - first) for first, second in zip(offsets, offsets[1:])})
    stride = 'single' if not strides else '/'.join(str(value) for value in strides[:2])
    order = 'ra first' if saves[0][1] == 31 else 'ra later' if any(register == 31 for _, register, _ in saves) else 'no ra'
    return f'{kinds} stride {stride}, {order}{", fpr" if float_saves else ""}'


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('executable')
    parser.add_argument('--functions', default=os.path.join(ROOT, 'data', 'matching', 'functions.tsv'))
    parser.add_argument('--step', default='0x10000', help='window size in bytes (default 0x10000)')
    parser.add_argument('--range', nargs=2, metavar=('START', 'END'), help='only functions in this address range (hexadecimal); the columns are the classes of that range')
    arguments = parser.parse_args()
    from elftools.elf.elffile import ELFFile
    section = ELFFile(open(arguments.executable, 'rb')).get_section_by_name('.text')
    elf = {'address': section['sh_addr'], 'data': section.data()}
    starts = []
    for line in open(arguments.functions):
        field = line.split('\t')[0].strip()
        if field.startswith('0x'):
            starts.append(int(field, 16))
    starts.sort()
    if arguments.range:
        low, high = (int(value, 16) for value in arguments.range)
        starts = [address for address in starts if low <= address < high]
    step = int(arguments.step, 16)
    windows = collections.defaultdict(collections.Counter)
    for address in starts:
        label = classify(instructions(elf, address, 24))
        if label:
            windows[address // step * step][label] += 1
    totals = collections.Counter()
    for counter in windows.values():
        totals.update(counter)
    top = [label for label, _ in totals.most_common(6)]
    print('classes overall:', dict(totals.most_common(8)))
    print(f'{"window":>10}  ' + '  '.join(f'{label[:22]:>22}' for label in top) + '   other')
    previous = None
    for window in sorted(windows):
        counter = windows[window]
        row = [counter.get(label, 0) for label in top]
        other = sum(counter.values()) - sum(row)
        dominant = counter.most_common(1)[0][0]
        mark = '  <-' if previous is not None and dominant != previous else ''
        print(f'{window:#10x}  ' + '  '.join(f'{value:22d}' for value in row) + f'   {other:5d}{mark}')
        previous = dominant


if __name__ == '__main__':
    main()
