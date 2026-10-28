#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""rename.py [--apply] <old> <new> [<old> <new> ...] - renames functions of the matching workspace.

  python3 scripts/matching/rename.py CloneLo CLo_Clone            (dry run: what would change)
  python3 scripts/matching/rename.py --apply CloneLo CLo_Clone    (from the lab root)

Changes, for each pair: the registry row (data/matching/functions.tsv; functions.py would take the name from the split,
so the split is changed too), the entry in config/matching/symbol_addrs.txt and work/matching/split/symbol_addrs.txt (added when the
old name was the split's own `func_<address>`), the split's assembly (work/matching/split/asm: file name, `nonmatching`/label lines
and every mention in other functions), and every matching source under data/matching/src (definitions and extern
declarations, whole-word). Notes, diffs and the recovered name files (config/names/resolutions.tsv) are not touched: record the rename there first. Refuses a new name that already exists.
"""
import csv
import glob
import os
import re
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
SYMBOL_FILES = [os.path.join(LAB, 'config', 'matching', 'symbol_addrs.txt'), os.path.join(LAB, 'work', 'matching', 'split', 'symbol_addrs.txt')]
SPLIT = os.path.join(LAB, 'work', 'matching', 'split', 'asm', 'functions', 'SCUS_973')
SPLIT_ALL = os.path.join(LAB, 'work', 'matching', 'split', 'asm')


def replace_word(path, old, new, apply):
    text = open(path, encoding='utf-8', errors='surrogateescape').read()
    pattern = re.compile(rf'(?<![\w$]){re.escape(old)}(?![\w$])')
    count = len(pattern.findall(text))
    if count and apply:
        open(path, 'w', encoding='utf-8', errors='surrogateescape').write(pattern.sub(new, text))
    return count


def main():
    arguments = sys.argv[1:]
    apply = '--apply' in arguments
    arguments = [a for a in arguments if a != '--apply']
    if not arguments or len(arguments) % 2:
        sys.exit(__doc__)
    pairs = list(zip(arguments[0::2], arguments[1::2]))
    rows = list(csv.DictReader(open(REGISTRY, encoding='utf-8'), delimiter='\t'))
    by_name = {row['name']: row for row in rows}
    taken = {name: int(row['address'], 16) for name, row in by_name.items()}
    for path in SYMBOL_FILES:
        for name, address in re.findall(r'^(\w+) = (0x[0-9A-Fa-f]+);', open(path, encoding='utf-8').read(), re.M):
            taken.setdefault(name, int(address, 16))
    sources = [path for path in glob.glob(os.path.join(LAB, 'data', 'matching', 'src', '**', '*'), recursive=True) if os.path.isfile(path)]
    for old, new in pairs:
        if old not in by_name:
            sys.exit(f'{old} is not a registry name')
        if new in taken and taken[new] != int(by_name[old]['address'], 16):  # the same address: a half-done earlier run
            sys.exit(f'{new} already stands for 0x{taken[new]:08X}')
    for old, new in pairs:
        row = by_name[old]
        address = int(row['address'], 16)
        in_symbols = 0
        for path in SYMBOL_FILES:
            in_symbols += replace_word(path, old, new, apply)
        if not in_symbols and new not in taken and apply:  # the split's own func_<address>: give the new name an entry
            for path in SYMBOL_FILES:
                with open(path, 'a', encoding='utf-8') as out:
                    out.write(f'{new} = 0x{address:08X}; // type:func size:0x{int(row["size"]):X}\n')
        file_count = sum(replace_word(path, old, new, apply) for path in sources)
        assembly = glob.glob(os.path.join(SPLIT_ALL, '**', '*.s'), recursive=True)  # again: an earlier pair renamed a file
        asm_count = sum(replace_word(path, old, new, apply) for path in assembly)
        old_file = os.path.join(SPLIT, old + '.s')
        if os.path.exists(old_file) and apply:
            os.rename(old_file, os.path.join(SPLIT, new + '.s'))
        row['name'] = new
        print(f'{old} -> {new}: symbol entries {in_symbols}, source mentions {file_count}, asm mentions {asm_count}, file {"yes" if os.path.exists(old_file) or apply else "no"}')
    if apply:
        with open(REGISTRY, 'w', encoding='utf-8', newline='') as out:
            writer = csv.DictWriter(out, list(rows[0].keys()), delimiter='\t', lineterminator='\n')
            writer.writeheader()
            writer.writerows(rows)
    else:
        print('dry run: nothing written')


if __name__ == '__main__':
    main()
