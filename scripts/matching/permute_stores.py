#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""permute_stores.py [--min N] [--max N] [--budget N] [--jobs N] [--out DIR] [address ...] - the store-order search over the near misses.

  .venv/bin/python scripts/matching/permute_stores.py --min 1 --max 4 --budget 30     (from the repository root)

For every non-matching source of nonmatching/MANIFEST.tsv whose score is between --min and --max (or the addresses given), finds the
straight-line regions of the function (consecutive simple statements, no braces or control flow) that hold at least two stores to memory
(a `->` member, an `M2C_FIELD(...)`, a dereference or an index on the left), marks those stores `//P` and runs permute.py's marked search
on them, one region at a time, largest first, with at most --budget compiles per function. A source that scores lower is written to
--out (default work/matching/permute-stores/<ADDRESS>.<ext>), and a later run starts from it; the repository is never changed. Prints one line per improved function and
the totals. Use the .venv python so that permute.py scores in process."""
import argparse
import concurrent.futures
import csv
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import permute  # noqa: E402
from progress import Progress  # noqa: E402

STORE = re.compile(r'^\s+(?:\*\s*\(|\*\w|M2C_FIELD\(|[\w.]+\s*->\s*\w+|[\w.]+\s*\[[^\]]*\]|\(\*)[^=;]*=(?!=)[^;]*;\s*(//.*)?$')


def regions(lines):
    """[[line index, ...]] of the stores of each straight-line region that has at least two, largest region first."""
    found, current, stores = [], [], []
    for index, line in enumerate(lines):
        simple = bool(permute.SIMPLE.match(line)) and not permute.CONTROL.match(line)
        if simple:
            if STORE.match(line) and not permute.MARK.search(line):
                stores.append(index)
        elif stores or current:
            current = []
            if len(stores) >= 2:
                found.append(stores)
            stores = []
    if len(stores) >= 2:
        found.append(stores)
    return sorted(found, key=len, reverse=True)


def search(address, source, budget, seed=1):
    lang = 'c' if source.endswith('.c') else 'c++'
    text = open(os.path.join(ROOT, source), encoding='utf-8').read()
    start = permute.judge(address, text, lang)
    if start in (None, 0):
        return start, start, text
    best_score, best_text = start, text
    spent = 0
    for region in regions(text.split('\n'))[:3]:
        if spent >= budget or best_score == 0:
            break
        lines = best_text.split('\n')
        marked = [line + ' //P' if index in region else line for index, line in enumerate(lines)]
        score, candidate, used = permute.marked_search(address, '\n'.join(marked), budget - spent, 1, lang, budget - spent, seed=seed)
        spent += used
        if score is not None and score < best_score:
            best_score, best_text = score, '\n'.join(line[:-4] if line.endswith(' //P') else line for line in candidate.split('\n'))
    return start, best_score, best_text


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('addresses', nargs='*')
    parser.add_argument('--min', type=int, default=1)
    parser.add_argument('--max', type=int, default=4)
    parser.add_argument('--budget', type=int, default=30)
    parser.add_argument('--jobs', type=int, default=6)
    parser.add_argument('--seed', type=int, default=1, help='the random sample of orders (another seed tries other orders)')
    parser.add_argument('--out', default=os.path.join('work', 'matching', 'permute-stores'))
    arguments = parser.parse_args()
    os.chdir(ROOT)
    wanted = {int(address, 16) for address in arguments.addresses}
    rows = [row for row in csv.DictReader(open(os.path.join('nonmatching', 'MANIFEST.tsv'), encoding='utf-8'), delimiter='\t')
            if (int(row['address'], 16) in wanted if wanted else arguments.min <= int(row['score']) <= arguments.max)]
    rows = [row for row in rows if regions(open(os.path.join('nonmatching', row['file']), encoding='utf-8').read().split('\n'))]
    os.makedirs(arguments.out, exist_ok=True)
    improved = matched = 0

    def run(row):
        address = f"0x{int(row['address'], 16):06X}"
        source = os.path.join('nonmatching', row['file'])
        previous = os.path.join(arguments.out, f'{int(row["address"], 16):06X}' + ('.c' if source.endswith('.c') else '.cpp'))
        if os.path.exists(previous):  # a better order found by an earlier run is the starting point
            source = os.path.abspath(previous)
        return row, address, source, search(address, source, arguments.budget, arguments.seed)

    progress = Progress(len(rows), 'permute-stores')
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        for row, address, source, (start, score, text) in pool.map(run, rows):
            progress.tick(f'{address}: {start} -> {score}')
            if score is not None and start is not None and score < start:
                improved += 1
                matched += score == 0
                extension = '.c' if source.endswith('.c') else '.cpp'
                with open(os.path.join(arguments.out, f'{int(row["address"], 16):06X}{extension}'), 'w', encoding='utf-8') as handle:
                    handle.write(text)
                print(f'{address} {row["name"]}: {start} -> {score}', flush=True)
    progress.done()
    print(f'{len(rows)} functions searched, {improved} improved, {matched} match')


if __name__ == '__main__':
    main()
