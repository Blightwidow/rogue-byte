#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""functions.py - builds the matching registry data/matching/functions.tsv from the split (work/matching/split, made
by spimdisasm from the ELF with work/matching/split/symbol_addrs.txt).

  python3 scripts/matching/functions.py      (from the lab root)

One row per function the split found: address, name (the symbol spimdisasm used), size in bytes, status, best score,
tries, source. Status: `todo`, `library` (the Sony SDK range 0x2319E8-0x254CA0, built from Sony's own objects), or
`fragment` (a chunk of at most 32 bytes with no jump: the words between two functions, never matched as C), or
whatever an earlier run recorded (`tried`, `matched`): rows already in the registry keep their status, score, tries
and source.

spimdisasm sometimes ends a function at its last jump and makes the jump's delay slot a 4-byte function of its own
(`func_<address>`, one `addiu $sp` or `nop`): such a slot is folded back into the function before it.
"""
import csv
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import boundaries  # noqa: E402

SPLIT = 'work/matching/split/asm/functions/SCUS_973'
REGISTRY = 'data/matching/functions.tsv'
SDK = (0x2319E8, 0x254CA0)
TEXT_END = 0x259DF0  # .text ends here; the split's .late_rodata files (jump tables) sit above it and are not functions
FIELDS = ['address', 'name', 'size', 'status', 'best', 'tries', 'source', 'name_source', 'option_name']  # name_source: where the name comes from
JUMP = re.compile(r'\*/\s+(jr|j|jal|jalr|b[a-z]*)\s')


def main():
    old = {}
    if os.path.exists(REGISTRY):
        old = {row['address']: row for row in csv.DictReader(open(REGISTRY, encoding='utf-8'), delimiter='\t')}
    rows = []
    for path in glob.glob(os.path.join(SPLIT, '*.s')):
        text = open(path, encoding='utf-8').read()
        head = re.search(r'^nonmatching (\S+), 0x([0-9A-Fa-f]+)', text, flags=re.M)
        if not head:
            continue
        # The function's own address: the first instruction after its glabel. A function with a jump table or float constants has
        # a `.late_rodata` part first, and the first address in the file is then the constant's (rodata), not the function's.
        label = re.search(rf'^glabel {re.escape(head.group(1))}\b.*\n', text, flags=re.M)
        body = text[label.end():] if label else text
        first = re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ', body)
        if not first:
            continue
        address = int(first.group(1), 16)
        if address >= TEXT_END:
            continue
        key = f'0x{address:06X}'
        row = old.get(key) or {'address': key, 'name': head.group(1), 'size': str(int(head.group(2), 16)),
                               'status': 'library' if SDK[0] <= address < SDK[1] else 'todo', 'best': '', 'tries': '0', 'source': '', 'name_source': '', 'option_name': ''}
        row['name'], row['size'] = head.group(1), str(int(head.group(2), 16))
        lines = [line for line in body.split('\n') if re.match(r'\s*/\* [0-9A-F]+ [0-9A-F]{8} ', line)]
        row['_ends_in_jump'] = bool(lines and JUMP.search(lines[-1]))
        # A chunk with no jump or return at all (a lone `addiu $sp`, a stray store) is words between two functions that stay assembled from the
        # retail bytes: C cannot express it, so it is not a function to match (status `fragment`).
        if (row['name'].startswith('func_') and int(row['size']) <= 32 and not any(JUMP.search(line) for line in lines)
                and row['status'] in ('todo', 'tried', '')):
            row['status'] = 'fragment'
        rows.append(row)
    rows.sort(key=lambda row: int(row['address'], 16))
    folded = []
    for row in rows:
        before = folded[-1] if folded else None
        if (before and before['_ends_in_jump'] and row['size'] == '4' and row['name'].startswith('func_')
                and int(before['address'], 16) + int(before['size']) == int(row['address'], 16)):
            before['size'] = str(int(before['size']) + 4)
            before['_ends_in_jump'] = False
            continue
        folded.append(row)
    rows = [{key: value for key, value in row.items() if not key.startswith('_')} for row in folded]
    rows = boundaries.apply_merges(rows, boundaries.read_merges())  # functions the split cut in two (scripts/matching/boundaries.py)
    os.makedirs(os.path.dirname(REGISTRY), exist_ok=True)
    with open(REGISTRY, 'w', encoding='utf-8', newline='') as out:
        writer = csv.DictWriter(out, FIELDS, delimiter='\t', lineterminator='\n')
        writer.writeheader()
        writer.writerows(rows)
    counts = {}
    for row in rows:
        counts[row['status']] = counts.get(row['status'], 0) + 1
    print(f'{len(rows)} functions, {sum(int(row["size"]) for row in rows)} bytes: ' + ', '.join(f'{count} {status}' for status, count in sorted(counts.items())))


if __name__ == '__main__':
    main()
