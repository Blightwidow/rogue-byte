#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""classify_diffs.py [--refresh] [--jobs N] [--out FILE] - sorts the near misses by what kind of difference keeps them from matching.

  python3 scripts/matching/classify_diffs.py --refresh      (from the repository root)

Reads the side-by-side diff scripts/matching/try.py keeps for every unmatched function (work/matching/diffs/<ADDRESS>.txt; --refresh judges
every `tried` function again first) and classifies each hunk (a run of differing lines):

  nop        only nop instructions are extra or missing: usually the assembler (see docs/build/assembler.md), not the source
  immediate  same instructions and registers, other numbers: a constant, an offset or a size is wrong
  register   same instructions, other registers: allocation, operand order (`addu a,b` against `addu b,a`), a variable's type or lifetime
  opcode     same registers and length, another mnemonic: signed/unsigned, a shift against a multiply, a branch sense
  order      the same instructions in another order: statement order, scheduling, which instruction fills a delay slot
  moved      extra and missing hunks that hold the same instructions overall: something moved (a load hoisted, a delay slot filled
             otherwise, stores in another order): the permuter's work
  extra      our code has more instructions than retail in the hunk; missing: fewer (the structure differs: a temporary, an inline, a cast)
  link       the instructions are equal but a call or a global points elsewhere (the name or the prototype)
  follows    the hunk differs only in branch offsets, a consequence of an `extra`/`missing` elsewhere

A function's class is its hunks' class when they all agree, else `mixed`; no diff means it does not compile. Prints the count per class and,
by score, how many are within reach of the cheap fixes, and writes one row per function (address, score, class, hunk classes) to the output."""
import argparse
import collections
import concurrent.futures
import csv
import os
import re
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
LINE = re.compile(r'^(?:[0-9a-f]{8}|\s{8}) (.*?)\s+([|<>!]) (.*)$')
OFFSET = re.compile(r'\. \+ 4 \+ \(-?0x[0-9A-F]+ << 2\)')
NUMBER = re.compile(r'-?0x[0-9A-Fa-f]+|-?\d+')
REGISTER = re.compile(r'\$\w+')
RELOCATION = re.compile(r'\s*\[%\w+ [^\]]*\]|\s*LINK:.*')


def clean(text):
    return RELOCATION.sub('', text).strip()


def shape(text):
    """The instruction with registers and numbers blanked and branch offsets normalised."""
    return NUMBER.sub('#', REGISTER.sub('$', OFFSET.sub('BR', clean(text))))


def mnemonic(text):
    return clean(text).split(' ')[0]


def classify_hunk(left, right):
    left_text, right_text = [clean(text) for text in left], [clean(text) for text in right]
    if not left and right and all(mnemonic(text) == 'nop' for text in right) or not right and left and all(mnemonic(text) == 'nop' for text in left):
        return 'nop'
    if len(left) == len(right):
        if [OFFSET.sub('BR', text) for text in left_text] == [OFFSET.sub('BR', text) for text in right_text]:
            return 'follows'
        if all(mnemonic(a) == mnemonic(b) for a, b in zip(left, right)):
            if [NUMBER.sub('#', text) for text in left_text] == [NUMBER.sub('#', text) for text in right_text] or \
                    all(REGISTER.sub('$', a) == REGISTER.sub('$', b) for a, b in zip(left_text, right_text)):
                return 'register' if [NUMBER.sub('#', text) for text in left_text] == [NUMBER.sub('#', text) for text in right_text] else 'immediate'
            return 'immediate'
        if sorted(shape(text) for text in left) == sorted(shape(text) for text in right):
            return 'order'
        return 'opcode'
    if sorted(shape(text) for text in left) == sorted(shape(text) for text in right):
        return 'order'
    return 'extra' if len(right) > len(left) else 'missing'


def hunks_of(path):
    """(score, [(left lines, right lines)], link error count, compiled) of a diff file."""
    lines = open(path, encoding='utf-8', errors='replace').read().splitlines()
    if not lines or not lines[0].startswith('score '):
        return None, [], 0, False
    score = int(lines[0].split()[1])
    links = 0
    hunks, left, right = [], [], []
    for line in lines[1:]:
        found = LINE.match(line)
        marker = found.group(2) if found else None
        if marker == '!':
            links += 1
        if marker in ('|', '<', '>'):
            if marker in ('|', '<'):
                left.append(found.group(1))
            if marker in ('|', '>'):
                right.append(found.group(3))
        elif left or right:
            hunks.append((left, right))
            left, right = [], []
    if left or right:
        hunks.append((left, right))
    return score, hunks, links, True


def refresh(rows, jobs):
    def judge(row):
        address = int(row['address'], 16)
        for pattern, language in ((f'data/matching/src/fn/{address:06X}.cpp', 'c++'), (f'work/matching/autopilot/{address:06X}.c', 'c'), (f'data/matching/src/auto/{address:06X}.c', 'c')):
            if os.path.exists(os.path.join(ROOT, pattern)):
                subprocess.run([sys.executable, 'scripts/matching/try.py', hex(address), pattern, '--lang', language], capture_output=True, cwd=ROOT)
                return
    with concurrent.futures.ThreadPoolExecutor(jobs) as pool:
        list(pool.map(judge, rows))


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--refresh', action='store_true')
    parser.add_argument('--jobs', type=int, default=12)
    parser.add_argument('--out', default=os.path.join(ROOT, 'work', 'matching', 'classes.tsv'))
    arguments = parser.parse_args()
    rows = [row for row in csv.DictReader(open(os.path.join(ROOT, 'data', 'matching', 'functions.tsv'), encoding='utf-8'), delimiter='\t') if row['status'] == 'tried']
    if arguments.refresh:
        refresh(rows, arguments.jobs)
    result = []
    for row in rows:
        path = os.path.join(ROOT, 'work', 'matching', 'diffs', f'{int(row["address"], 16):06X}.txt')
        score, hunks, links, compiled = hunks_of(path) if os.path.exists(path) else (None, [], 0, False)
        if not compiled:
            result.append((row['address'], row['name'], '', 'no-compile', ''))
            continue
        kinds = [classify_hunk(left, right) for left, right in hunks]
        real = [kind for kind in kinds if kind != 'follows']
        if links:
            real.append('link')
        distinct = sorted(set(real))
        every_left = [shape(text) for left, _ in hunks for text in left]
        every_right = [shape(text) for _, right in hunks for text in right]
        if distinct and set(distinct) <= {'extra', 'missing', 'order', 'follows'} and sorted(every_left) == sorted(every_right):
            distinct = ['moved']  # the same instructions overall, in other places: scheduling, a delay slot, store order, a hoisted load
        kind = distinct[0] if len(distinct) == 1 else ('mixed' if distinct else 'follows')
        result.append((row['address'], row['name'], str(score), kind, '+'.join(distinct)))
    os.makedirs(os.path.dirname(arguments.out), exist_ok=True)
    with open(arguments.out, 'w') as out:
        out.write('address\tname\tscore\tclass\thunks\n')
        for entry in result:
            out.write('\t'.join(entry) + '\n')
    counts = collections.Counter(kind for _, _, _, kind, _ in result)
    print(f'{len(result)} unmatched functions with a source')
    for kind, count in counts.most_common():
        within = sum(1 for _, _, score, k, _ in result if k == kind and score and int(score) <= 10)
        print(f'  {kind:11} {count:4}   (score <= 10: {within})')


if __name__ == '__main__':
    main()
