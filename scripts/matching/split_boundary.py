#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""split_boundary.py [--apply] ADDRESS... - a function whose first 8 bytes are the end of the function before it.

  python3 scripts/matching/split_boundary.py --apply 0x210ED0 0x259D58      (from the repository root)

The split ends a function at its last `jr`, so a leading `addiu $sp,$sp,0x10 ; nop` (the epilogue of the previous function: its delay slot and
the padding word) can come out as the first two instructions of the next "function", which then can never match as C: its true start is 8
bytes later (a jump table or a call points there). For each ADDRESS this
  - adds `func_<ADDRESS+8> = 0x<ADDRESS+8>; // type:func` to config/matching/symbol_addrs.txt, config/recovered/sly2_combined_symbol_addrs.txt
    (`make config` / export_splat_symbols.py turn it into config/us/symbol_addrs.txt, the build's list) and work/matching/split/symbol_addrs.txt,
  - cuts the split's assembly file (work/matching/split/asm/functions/SCUS_973/func_<ADDRESS>.s) in two: the first two instructions stay under
    the old name (they stay assembled: a fragment), the rest becomes func_<ADDRESS+8>.s,
  - moves the registry row and the matching source (data/matching/src/fn/<ADDRESS>.cpp) to the new address.
Without --apply it only prints what it would do. Run `python3 scripts/matching/functions.py`, then `make land PROGRESS=0` afterwards (`make elf` splits
the executable again from config/us/symbol_addrs.txt)."""
import argparse
import csv
import os
import re
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
SPLIT = os.path.join(LAB, 'work', 'matching', 'split', 'asm', 'functions', 'SCUS_973')
REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
SYMBOLS = [os.path.join(LAB, 'config', 'matching', 'symbol_addrs.txt'), os.path.join(LAB, 'config', 'recovered', 'sly2_combined_symbol_addrs.txt'),
           os.path.join(LAB, 'work', 'matching', 'split', 'symbol_addrs.txt')]
INSTRUCTION = re.compile(r'^\s*/\*(?: [0-9A-F]+)? [0-9A-F]{8}\s')


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('addresses', nargs='+', type=lambda text: int(text, 16))
    parser.add_argument('--apply', action='store_true')
    arguments = parser.parse_args()
    rows = list(csv.DictReader(open(REGISTRY, encoding='utf-8'), delimiter='\t'))
    fields = list(rows[0].keys())
    for address in arguments.addresses:
        row = next((r for r in rows if int(r['address'], 16) == address), None)
        if not row:
            sys.exit(f'0x{address:X} is not in the registry')
        new = address + 8
        old_name, new_name = row['name'], f'func_{new:08X}'
        size = int(row['size'])
        path = os.path.join(SPLIT, old_name + '.s')
        lines = open(path, encoding='utf-8').read().split('\n')
        glabel = next(i for i, line in enumerate(lines) if line.startswith('glabel '))
        end = next(i for i, line in enumerate(lines) if line.startswith('endlabel '))
        body = [line for line in lines[glabel + 1:end]]
        taken, rest, count = [], [], 0
        for line in body:
            (taken if count < 2 else rest).append(line)
            if INSTRUCTION.match(line):
                count += 1
        if count < 3 or any(l.strip().endswith(':') for l in taken if not INSTRUCTION.match(l)):
            sys.exit(f'0x{address:X}: fewer than 3 instructions, or a label inside the first two')
        header = [line for line in lines[:glabel - 1] if line.strip() and not line.startswith('nonmatching')]
        head_file = header + [f'nonmatching {old_name}, 0x8', '', f'glabel {old_name} # 0'] + taken + [f'endlabel {old_name}']
        tail_file = [f'nonmatching {new_name}, 0x{size - 8:X}', '', f'glabel {new_name} # 0'] + rest + [f'endlabel {new_name}'] + lines[end + 1:]
        print(f'0x{address:X} {old_name} ({size} bytes) -> head 8 bytes stay, {new_name} at 0x{new:X} ({size - 8} bytes)')
        if not arguments.apply:
            continue
        open(path, 'w', encoding='utf-8').write('\n'.join(head_file) + '\n')
        open(os.path.join(SPLIT, new_name + '.s'), 'w', encoding='utf-8').write('\n'.join(tail_file))
        for symbols in SYMBOLS:
            text = open(symbols, encoding='utf-8').read()
            if not re.search(rf'^{new_name}\s*=', text, re.M):
                open(symbols, 'a', encoding='utf-8').write(('' if text.endswith('\n') else '\n') + f'{new_name} = 0x{new:08X}; // type:func source:boundary size:0x{size - 8:X}\n')
        row['address'], row['name'], row['size'] = f'0x{new:06X}', new_name, str(size - 8)
        for suffix in ('cpp', 'c'):
            source = os.path.join(LAB, 'data', 'matching', 'src', 'fn', f'{address:06X}.{suffix}')
            if os.path.exists(source):
                os.replace(source, os.path.join(LAB, 'data', 'matching', 'src', 'fn', f'{new:06X}.{suffix}'))
                if row['source']:
                    row['source'] = row['source'].replace(f'{address:06X}', f'{new:06X}')
    if arguments.apply:
        with open(REGISTRY, 'w', encoding='utf-8', newline='') as out:
            writer = csv.DictWriter(out, fields, delimiter='\t', lineterminator='\n')
            writer.writeheader()
            writer.writerows(rows)


if __name__ == '__main__':
    main()
