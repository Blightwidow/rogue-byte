#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""handwritten.py [--check] - lists the functions retail wrote in assembly: config/us/handwritten_asm.txt.

  python3 scripts/matching/handwritten.py           (from the repository root: writes the list)
  python3 scripts/matching/handwritten.py --check   (exits 1 when the committed list is stale)

Evidence is spimdisasm's own marker (`/* Handwritten function */` in the split of work/matching/split/asm/functions/SCUS_973), the
same source OpenRAC's triage uses. Each row says what else shows it: `syscall`, `trap` (add/addi/sub that can trap), `at` ($at read
or written as a register), `mmi` (128-bit integer MMI), `vu0` (COP2). A function without one of those tags carries the marker alone.
The list says where C would misrepresent retail's origin; it does not count anything and it does not stop anyone from matching one
(a lead dealing out work should leave them out of a pool). One line per function: `0xADDRESS name size tags`, `#` comments,
the same format as the other lists in config/us/."""
import argparse
import glob
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
SPLIT = os.path.join(ROOT, 'work', 'matching', 'split', 'asm', 'functions', 'SCUS_973')
OUTPUT = os.path.join(ROOT, 'config', 'us', 'handwritten_asm.txt')
HEADER = '''# Functions retail wrote in assembly (scripts/matching/handwritten.py): spimdisasm's `Handwritten function` marker, plus the instruction
# kinds that show it (syscall, trap = add/addi/sub that can trap, at = $at used as a register, mmi, vu0). One per line:
# 0xADDRESS name size tags. Nothing counts from this list and matching one is allowed; leave them out of a worker pool.
'''
INSTRUCTION = re.compile(r'^\s*/\* [0-9A-Fa-f]+ ([0-9A-Fa-f]{8}) [0-9A-Fa-f]{8} \*/\s+(\S+)\s*(.*)$')
GLABEL = re.compile(r'^glabel (\S+)')
MMI = re.compile(r'^(p[a-z0-9]+|qfsrv|mfhi1|mflo1|mthi1|mtlo1|mult1|multu1|div1|divu1|madd1|maddu1|pmfhl\S*|pmthl\S*)$')
TRAPPING = {'add', 'addi', 'sub'}


def scan(path):
    marked = False
    name = None
    first = None
    count = 0
    tags = set()
    for line in open(path, encoding='utf-8', errors='replace'):
        if 'Handwritten function' in line:
            marked = True
        glabel = GLABEL.match(line)
        if glabel and name is None:
            name = glabel.group(1)
        found = INSTRUCTION.match(line)
        if not found:
            continue
        address, mnemonic, operands = int(found.group(1), 16), found.group(2), found.group(3)
        first = address if first is None else first
        count += 1
        if mnemonic == 'syscall':
            tags.add('syscall')
        if mnemonic in TRAPPING:
            tags.add('trap')
        if re.search(r'\$at\b', operands):
            tags.add('at')
        if MMI.match(mnemonic) and mnemonic not in ('pref',):
            tags.add('mmi')
        if mnemonic.startswith('v') and mnemonic not in ('vmulq',) or mnemonic in ('qmtc2', 'qmfc2', 'lqc2', 'sqc2', 'ctc2', 'cfc2'):
            tags.add('vu0')
    return (first, name, count * 4, sorted(tags)) if marked and first is not None else None


def build():
    rows = []
    for path in glob.glob(os.path.join(SPLIT, '*.s')):
        found = scan(path)
        if found:
            rows.append(found)
    rows.sort()
    lines = [f'0x{address:06X} {name} {size} {",".join(tags) or "marker"}' for address, name, size, tags in rows]
    return HEADER + '\n'.join(lines) + '\n', rows


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--check', action='store_true')
    arguments = parser.parse_args()
    if not os.path.isdir(SPLIT):
        sys.exit(f'no split at {SPLIT} (make elf writes it)')
    text, rows = build()
    if arguments.check:
        current = open(OUTPUT, encoding='utf-8').read() if os.path.exists(OUTPUT) else ''
        if current != text:
            sys.exit('config/us/handwritten_asm.txt is stale: run python3 scripts/matching/handwritten.py')
        print(f'ok: {len(rows)} hand-written functions')
        return
    with open(OUTPUT, 'w', encoding='utf-8') as output:
        output.write(text)
    print(f'{len(rows)} functions -> config/us/handwritten_asm.txt')


if __name__ == '__main__':
    main()
