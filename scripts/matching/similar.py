#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""similar.py <address> [--n 5] [--check] - the matched functions most like one function, with their matching sources.

  python3 scripts/matching/similar.py 0x11A6B8      (from the lab root)

Finds already-matched functions similar to an open one, as examples to match from. Candidates are the functions matched with a
hand-written source (data/matching/src/fn: the `auto` sources are m2c output verbatim).
Similarity of two functions: cosine of their opcode-trigram counts (instruction shape, register names and immediates ignored),
plus the overlap of the functions they call (Jaccard), 0.7 / 0.3; candidates within a factor of 2 in size only.
No model, no new dependency. Prints one line per example: address, name, size, similarity, shared callees, source path.

--check: measures it on the matched set (leave one out): the mean similarity of the top example against a random same-size
function, and how often the top-5 share a callee with the target (the control a heuristic needs before it is trusted).
"""
import argparse
import collections
import csv
import math
import os
import random
import re
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
SPLIT = os.path.join(LAB, 'work', 'matching', 'split', 'asm', 'functions', 'SCUS_973')
CALL = re.compile(r'\b(?:jal|j)\s+([A-Za-z_][\w$.]*)')
LINE = re.compile(r'^\s*/\*[^*]*\*/\s+(\w[\w.]*)\b(.*)$')


def features(row):
    """(opcode trigram counts, norm, callee names) of one function's split assembly, or None."""
    path = os.path.join(SPLIT, row['name'] + '.s')
    if not os.path.exists(path):
        return None
    opcodes, callees = [], set()
    for line in open(path, encoding='utf-8'):
        match = LINE.match(line)
        if not match:
            continue
        opcodes.append(match.group(1))
        call = CALL.search(match.group(1) + match.group(2))
        if call:
            callees.add(call.group(1))
    grams = collections.Counter(zip(opcodes, opcodes[1:], opcodes[2:])) or collections.Counter([tuple(opcodes)])
    return grams, math.sqrt(sum(count * count for count in grams.values())) or 1.0, callees


def similarity(left, right):
    grams_a, norm_a, callees_a = left
    grams_b, norm_b, callees_b = right
    small, large = (grams_a, grams_b) if len(grams_a) <= len(grams_b) else (grams_b, grams_a)
    cosine = sum(count * large.get(gram, 0) for gram, count in small.items()) / (norm_a * norm_b)
    union = callees_a | callees_b
    return 0.7 * cosine + 0.3 * (len(callees_a & callees_b) / len(union) if union else 0.0)


def index():
    rows = list(csv.DictReader(open(os.path.join(LAB, 'data', 'matching', 'functions.tsv'), encoding='utf-8'), delimiter='\t'))
    gold = {}
    for row in rows:
        if row['status'] == 'matched' and '/src/fn/' in row['source']:
            found = features(row)
            if found:
                gold[int(row['address'], 16)] = (row, found)
    return rows, gold


def similar(address, count, rows, gold):
    target = next(row for row in rows if int(row['address'], 16) == address)
    found = gold[address][1] if address in gold else features(target)
    size = int(target['size'])
    scored = []
    for other, (row, other_found) in gold.items():
        if other != address and size / 2 <= int(row['size']) <= size * 2:
            scored.append((similarity(found, other_found), other, row, sorted(found[2] & other_found[2])))
    return sorted(scored, key=lambda item: -item[0])[:count]


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('address', nargs='?', type=lambda text: int(text, 16))
    parser.add_argument('--n', type=int, default=5)
    parser.add_argument('--check', action='store_true')
    arguments = parser.parse_args()
    rows, gold = index()
    if arguments.check:
        rng = random.Random(1)
        sample = rng.sample(sorted(gold), 300)
        top, control, shared = [], [], 0
        for address in sample:
            best = similar(address, 5, rows, gold)
            if not best:
                continue
            top.append(best[0][0])
            same_size = [other for other in gold if other != address and int(gold[other][0]['size']) // 2 <= int(gold[address][0]['size']) <= int(gold[other][0]['size']) * 2]
            control.append(similarity(gold[address][1], gold[rng.choice(same_size)][1]))
            shared += any(item[3] for item in best)
        print(f'{len(top)} functions: mean top-1 similarity {sum(top) / len(top):.2f}, random same-size {sum(control) / len(control):.2f}; '
              f'top-5 share a callee with the target in {100 * shared / len(top):.0f}%')
        return
    if arguments.address is None:
        parser.error('an address, or --check')
    for score, other, row, shared in similar(arguments.address, arguments.n, rows, gold):
        print(f'0x{other:06X} {row["name"]} ({row["size"]} bytes) similarity {score:.2f} shared calls {",".join(shared) or "-"} {row["source"]}')


if __name__ == '__main__':
    sys.exit(main())
