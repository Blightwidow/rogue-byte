#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/combine.py - one Sly 2 symbol file from both name sources, each name tagged with where it came from.

  python3 scripts/names/combine.py config/recovered/

  sly1   config/recovered/matches.tsv: Sly 1 decomp names moved over by scripts/names/match.py (the original Sucker Punch names, mangled)
  bevy   config/recovered/bevy_functions.tsv / bevy_globals.tsv: the Rust port's own names, prefixed with their module from the file
         path (engine/camera/follow.rs `activate` -> bevy_camera_follow_activate); its placeholders (FUN_..., ee_sub_...)
         keep only the module, which still tells the subsystem: bevy_camera_cm_14d478

A function named by both keeps the Sly 1 name (the original one); the Rust module goes into the comment.
config/recovered/sdk_symbol_addrs.txt (SDK function names, identified from library objects) fills functions that have none. Last,
config/recovered/provisional_symbol_addrs.txt (names chosen while reading the code: provisional) overrides. Writes
config/recovered/sly2_combined_symbol_addrs.txt (splat format, readable by ApplySplatSymbols.java) and prints the counts.
"""
import csv
import os
import re
import sys

PLACEHOLDER = re.compile(r'^(FUN_|ee_sub_|sub_|DAT_|LAB_|func_)|_[0-9a-f]{6}$')


def module(path):
    parts = path.replace('\\', '/').removesuffix('.rs').split('/')
    if parts and parts[0] == 'engine':
        parts = parts[1:]
    return '_'.join(p for p in parts if p != 'mod')


def read_tsv(path):
    with open(path, encoding='utf-8') as f:
        return list(csv.DictReader(f, delimiter='\t'))


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    out = sys.argv[1]
    names = {}  # address -> (name, comment)
    for row in read_tsv(os.path.join(out, 'matches.tsv')):
        if row['name']:
            names[int(row['sly2_entry'], 16)] = (row['name'], f"source:sly1 match:{row['method']} score:{row['score']} sly1:{row['sly1_entry']}")
    sly1_count = len(names)
    bevy_count = both = module_only = 0
    for row in read_tsv(os.path.join(out, 'bevy_functions.tsv')):
        address = int(row['address'], 16)
        if address in names:
            both += 1
            name, comment = names[address]
            names[address] = (name, f"{comment} bevy:{module(row['file'])}")
        elif not PLACEHOLDER.search(row['name']):
            names[address] = (f"bevy_{module(row['file'])}_{row['name']}", f"source:bevy file:{row['file']}")
            bevy_count += 1
        else:
            names[address] = (f"bevy_{module(row['file'])}_{address:x}", f"source:bevy-module file:{row['file']}")
            module_only += 1
    sdk_count = 0
    sdk_path = os.path.join(out, 'sdk_symbol_addrs.txt')
    if os.path.exists(sdk_path):  # names of Sony SDK functions (scripts/sdk/identify_sdk.py); never replaces another name
        for line in open(sdk_path, encoding='utf-8'):
            match = re.match(r'^(\S+) = (0x[0-9A-Fa-f]+); // type:func (.*)$', line.rstrip('\n'))
            if match and int(match.group(2), 16) not in names:
                names[int(match.group(2), 16)] = (match.group(1), match.group(3))
                sdk_count += 1
    provisional_count = 0
    provisional_path = os.path.join(out, 'provisional_symbol_addrs.txt')
    if os.path.exists(provisional_path):
        for line in open(provisional_path, encoding='utf-8'):
            match = re.match(r'^(\S+) = (0x[0-9A-Fa-f]+); // type:func (.*)$', line.rstrip('\n'))
            if match:
                names[int(match.group(2), 16)] = (match.group(1), match.group(3))
                provisional_count += 1
    globals_count = 0
    labels = {}
    for row in read_tsv(os.path.join(out, 'bevy_globals.tsv')):
        labels[int(row['address'], 16)] = (row['name'], f"source:bevy file:{row['file']}")
        globals_count += 1

    used = {}
    with open(os.path.join(out, 'sly2_combined_symbol_addrs.txt'), 'w', encoding='utf-8') as f:
        f.write('// Sly 2 (SCUS-97316) names. source:sly1 = Sly 1 decomp names moved by code matching (unverified);\n')
        f.write('// source:bevy = names from sly2-bevy-of-thieves (MIT) address comments, prefixed with their Rust module;\n// source:provisional = readings of the code (config/recovered/provisional_symbol_addrs.txt), not Sucker Punch names.\n')
        for address, (name, comment) in sorted(names.items()):
            used[name] = used.get(name, 0) + 1
            unique = name if used[name] == 1 else f'{name}_{used[name]}'
            f.write(f'{unique} = 0x{address:X}; // type:func {comment}\n')
        for address, (name, comment) in sorted(labels.items()):
            used[name] = used.get(name, 0) + 1
            unique = name if used[name] == 1 else f'{name}_{used[name]}'
            f.write(f'{unique} = 0x{address:X}; // {comment}\n')
    print(f'functions: {len(names)} ({sly1_count} from Sly 1, {bevy_count} bevy names, {module_only} bevy module only, {both} in both, {provisional_count} provisional, {sdk_count} from the SDK libraries); globals: {globals_count}')


if __name__ == '__main__':
    main()
