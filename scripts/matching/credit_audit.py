#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""credit_audit.py - how much of the matched code is plain C, and how much leans on a trick to match.

  python3 scripts/matching/credit_audit.py [--list FLAG] [--directory src]

A match is a match, but not all matches are the same kind of source. Some keep an empty `asm` barrier or a register-pinned local that no
human wrote, some carry inline assembly the function really needs (VU0 instructions have no C), some read memory through a volatile
cast to reproduce a reload, some define a helper inline. This sorts every matched source into the strictest tier it falls in and prints the
share of functions and bytes per tier, so progress can be quoted as "C with nothing forced" next to the byte-exact figure.

  barrier      an empty or memory-only `asm` statement, or a register-pinned local (`register T x asm("$s0")`): written only to steer the compiler
  asm          inline assembly with an instruction (VU0 and coprocessor moves are counted apart as `vu0`: no C expresses them)
  raw data     `.word`, `.byte` or `.long` inside an `asm` string
  volatile     a read or write through a volatile pointer cast (reproduces a reload from the stack)
  helper       a `static inline` helper defined in the source (a packet writer, a field accessor)
  plain        none of the above

Any source can carry several; the tier is the first of the list above that applies."""
import argparse
import collections
import csv
import os
import re
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
ASM = re.compile(r'\b(?:__asm__|asm)\s*(?:volatile|__volatile__)?\s*\(\s*("(?:[^"\\]|\\.)*"(?:\s*"(?:[^"\\]|\\.)*")*)', re.S)
VU0 = re.compile(r'^\s*(qmtc2|qmfc2|lqc2|sqc2|cfc2|ctc2|cfc2\.i|vcallms|vcallmsr|v[a-z0-9]+)(\.\w+)?\b')
TIERS = ['barrier', 'asm', 'raw data', 'volatile', 'helper', 'plain']


def flags_of(text):
    """The set of flags a source raises, and the number of VU0 asm statements."""
    flags = set()
    if re.search(r'\bregister\b[^;]*\b(?:asm|__asm__)\s*\(\s*"\$', text):
        flags.add('barrier')
    vu0_only = True
    has_asm = False
    for match in ASM.finditer(text):
        has_asm = True
        body = ''.join(re.findall(r'"((?:[^"\\]|\\.)*)"', match.group(1)))
        lines = [line.strip() for line in re.split(r'\\n|\\t|;', body) if line.strip()]
        if not lines:
            flags.add('barrier')
            continue
        if any(re.match(r'\.(word|byte|long|half|short)\b', line) for line in lines):
            flags.add('raw data')
        if not all(VU0.match(line) or line == 'nop' for line in lines):
            vu0_only = False
    if has_asm and 'barrier' not in flags and not vu0_only:
        flags.add('asm')
    elif has_asm and vu0_only:
        flags.add('vu0')
    if re.search(r'volatile\s*\*', text):
        flags.add('volatile')
    if re.search(r'\bstatic inline\b', text):
        flags.add('helper')
    return flags


def tier_of(flags):
    for tier in TIERS[:-1]:
        if tier in flags:
            return tier
    return 'plain'


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--list', metavar='TIER', help='list the matched sources in a tier')
    parser.add_argument('--directory', default=os.path.join(LAB, 'data', 'matching', 'src', 'fn'), help='where a source is looked for when the registry names none')
    arguments = parser.parse_args()
    with open(REGISTRY, encoding='utf-8') as handle:
        rows = [row for row in csv.DictReader(handle, delimiter='\t') if row['status'] == 'matched']
    functions = collections.Counter()
    sizes = collections.Counter()
    vu0 = missing = 0
    listed = []
    for row in rows:
        path = os.path.join(LAB, row['source']) if row['source'] else os.path.join(arguments.directory, f'{int(row["address"], 16):06X}.cpp')
        if not os.path.exists(path):
            missing += 1
            continue
        with open(path, encoding='utf-8') as handle:
            flags = flags_of(handle.read())
        tier = tier_of(flags)
        functions[tier] += 1
        sizes[tier] += int(row['size'])
        vu0 += 'vu0' in flags
        if arguments.list == tier:
            listed.append(f'{row["address"]} {row["name"]} ({row["size"]} bytes)')
    total, total_size = sum(functions.values()), sum(sizes.values())
    print(f'{total} matched sources, {total_size} bytes' + (f' ({missing} matched functions have no source file here)' if missing else ''))
    for tier in TIERS:
        print(f'  {tier:<9} {functions[tier]:5d} functions {100 * functions[tier] / total:5.1f}%   {sizes[tier]:7d} bytes {100 * sizes[tier] / total_size:5.1f}%')
    print(f'  ({vu0} sources use VU0 instructions in asm: they are in the `plain`/`helper` tiers unless they have other asm)')
    for line in listed:
        print(line)
    return 0


if __name__ == '__main__':
    sys.exit(main())
