#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""idioms.py - which source shapes the matched functions needed, and which of them a near miss does not use yet.

  python3 scripts/matching/idioms.py mine                  table of idioms over the matched sources (count, share, examples)
  python3 scripts/matching/idioms.py suggest 0x13A688      idioms of the matched functions that call the same things, absent here

A function matches only when its source takes the shape the original compiler saw, and the shapes that were needed once are needed again
in functions that do the same work: a packet writer, a loop the compiler must not strength-reduce, a clamp, an out-parameter read back
through memory. `mine` counts them over every source in data/matching/src/fn that matches (the control: how common each shape is where the
answer is known) and `suggest` ranks, for one unmatched source, the idioms that its nearest matched neighbours (by the callees they share)
use and it does not. A shape is a lead, not a fix: judge the rewrite (mutate.py has one rewrite for several of them)."""
import argparse
import collections
import csv
import os
import re
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
SOURCES = os.path.join(LAB, 'data', 'matching', 'src', 'fn')

IDIOMS = {
    'volatile slot read': r'volatile\s*\*',
    'goto loop': r'\bgoto\s+\w+;',
    'inline helper': r'\bstatic inline\b',
    'inline asm': r'\basm\b',
    'cursor push (store, bump, write)': r'\bslot\s*=\s*\w+->cursor|->cursor\s*=\s*\w+\s*\+\s*1',
    'clamp ternary': r'\?\s*[-\w.]+\s*:\s*\(?[^;]*\?',
    'unsigned local': r'^\s+unsigned(?: int)?\s+\w+\s*(=|;)',
    'byte-offset cast': r'\(\(?(?:char|unsigned char) \*\)\s*\w+\s*\+\s*0x[0-9A-Fa-f]+\)',
    'tail call (return f(...))': r'^\s+return\s+\w+\(.*\);\s*$',
    'do/while': r'\bdo\s*\{',
    'switch': r'\bswitch\s*\(',
    'struct by value / QW': r'\bQW\b',
    'float constant': r'\b\d+\.\d+f\b',
    'int callee (extern returns int)': r'extern "C" int \w+\(',
    'void callee (extern returns void)': r'extern "C" void \w+\(',
}
CALL = re.compile(r'\b([A-Za-z_][A-Za-z_0-9]*)\s*\(')
KEYWORDS = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'asm', 'volatile', 'void', 'int', 'float', 'char', 'unsigned'}


def load():
    with open(REGISTRY, encoding='utf-8') as handle:
        registry = {int(row['address'], 16): row for row in csv.DictReader(handle, delimiter='\t')}
    sources = {}
    for name in sorted(os.listdir(SOURCES)):
        address = int(name.split('.')[0], 16)
        row = registry.get(address)
        if row:
            with open(os.path.join(SOURCES, name), encoding='utf-8') as handle:
                sources[address] = (row['status'], handle.read())
    return sources


def idioms_of(text):
    return {name for name, pattern in IDIOMS.items() if re.search(pattern, text, re.MULTILINE)}


def callees(text):
    return {name for name in CALL.findall(text) if name not in KEYWORDS} - {'Slot'}


def mine(sources):
    matched = {address: text for address, (status, text) in sources.items() if status == 'matched'}
    counts = collections.Counter()
    examples = collections.defaultdict(list)
    for address, text in matched.items():
        for name in idioms_of(text):
            counts[name] += 1
            if len(examples[name]) < 3:
                examples[name].append(f'{address:#x}')
    print(f'{len(matched)} matched sources')
    for name, count in counts.most_common():
        print(f'{count:5d} {100 * count / len(matched):5.1f}%  {name:<36} {" ".join(examples[name])}')


def suggest(sources, address, neighbours):
    status, text = sources[address]
    own = callees(text)
    own_idioms = idioms_of(text)
    scored = []
    for other, (other_status, other_text) in sources.items():
        if other == address or other_status != 'matched':
            continue
        shared = len(own & callees(other_text))
        if shared:
            scored.append((shared / len(own | callees(other_text)), other, other_text))
    scored.sort(reverse=True)
    near = scored[:neighbours]
    votes = collections.Counter()
    for _, _, other_text in near:
        votes.update(idioms_of(other_text) - own_idioms)
    print(f'{address:#x}: {len(near)} nearest matched sources by shared callees (best similarity {near[0][0]:.2f})' if near else f'{address:#x}: no matched source shares a callee')
    for name, count in votes.most_common():
        print(f'  {count}/{len(near)} neighbours use "{name}"')
    for similarity, other, _ in near[:5]:
        print(f'  {other:#x} similarity {similarity:.2f}')


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest='command', required=True)
    sub.add_parser('mine')
    suggester = sub.add_parser('suggest')
    suggester.add_argument('address')
    suggester.add_argument('--neighbours', type=int, default=10)
    arguments = parser.parse_args()
    sources = load()
    if arguments.command == 'mine':
        mine(sources)
    else:
        suggest(sources, int(arguments.address, 16), arguments.neighbours)
    return 0


if __name__ == '__main__':
    sys.exit(main())
