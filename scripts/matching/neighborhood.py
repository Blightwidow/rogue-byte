#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""neighborhood.py - the complete one-edit neighbourhood of a near miss, then a beam search from the edits that did not hurt.

  .venv/bin/python scripts/matching/neighborhood.py 0x13A688 [source.cpp] [--depth 3] [--beam 8] [--budget 4000] [--write]
  .venv/bin/python scripts/matching/neighborhood.py --batch [--min-score N] [--max-score N] [--budget N] [--write]

mutate.py climbs by random single rewrites, so it can miss an edit that needs two steps and cannot say it has looked everywhere. This
applies every rewrite of mutate.py at every line it fits (each rewrite with several choices of which operator or declaration it touches),
and every order of a block of declarations (up to five, 120 orders), judges them all in process (scorer.py: about 50 compiles a second and
every judged source remembered on disk), then repeats from the best few sources, which include equal scores (a plateau is crossed by
an edit that changes nothing visible). It stops at score 0 or when the budget of compiles is spent, and says when a depth found no source
better than before: the neighbourhood is then exhausted for these rewrites."""
import argparse
import concurrent.futures
import csv
import itertools
import os
import random
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import mutate  # noqa: E402
import scorer  # noqa: E402

LAB = scorer.LAB
SOURCES = os.path.join(LAB, 'data', 'matching', 'src', 'fn')
DECLARATION = re.compile(r'^\s+(?:const |unsigned |struct )*[A-Za-z_][A-Za-z_0-9]*(?:\s+\*+|\*+\s+|\s+)\*?[A-Za-z_][A-Za-z_0-9]*(?:\[[^\]]*\])?(?: = [^;]*)?;\s*$')
NOT_DECLARATION = re.compile(r'^\s+(return|goto|break|continue|else|case|delete|new)\b')


def single_edits(text, choices):
    """{source: (rewrite name, line)} for every rewrite at every line it applies to, `choices` random choices each."""
    lines = text.split('\n')
    edits = {}
    names = []
    for rewrite in mutate.MUTATIONS:
        if rewrite not in names:
            names.append(rewrite)
    for index in mutate.body_lines(lines):
        for rewrite in names:
            for choice in range(choices):
                changed = rewrite(list(lines), index, random.Random(choice * 7919 + index))
                if changed and changed != lines:
                    edits.setdefault('\n'.join(changed), (rewrite.__name__, index))
    return edits


def declaration_orders(text, limit=5):
    """Every order of each block of consecutive declaration lines (blocks of up to `limit` lines; longer ones give adjacent windows)."""
    lines = text.split('\n')
    edits = {}
    index = 0
    while index < len(lines):
        if DECLARATION.match(lines[index]) and not NOT_DECLARATION.match(lines[index]) and '(' not in lines[index].split('=')[0]:
            end = index
            while end < len(lines) and DECLARATION.match(lines[end]) and not NOT_DECLARATION.match(lines[end]) and '(' not in lines[end].split('=')[0]:
                end += 1
            for start in range(index, max(index + 1, end - limit + 1)):
                window = list(range(start, min(end, start + limit)))
                if len(window) < 2:
                    continue
                for order in itertools.permutations(window):
                    if list(order) == window:
                        continue
                    changed = list(lines)
                    for position, source in zip(window, order):
                        changed[position] = lines[source]
                    edits.setdefault('\n'.join(changed), ('declaration order', start))
            index = end
        else:
            index += 1
    return edits


def search(address, text, depth, beam, budget, jobs, choices, log=None):
    """(best score, best source, compiles used, whether the last depth improved on its input)."""
    base_score = scorer.judge(address, text)
    if base_score in (None, 0):
        return base_score, text, 1, False
    best_score, best_text, used = base_score, text, 1
    frontier = [(base_score, text)]
    seen = {text}
    improved = False
    with concurrent.futures.ThreadPoolExecutor(jobs) as pool:
        for level in range(1, depth + 1):
            candidates = {}
            for _, source in frontier:
                for edits in (single_edits(source, choices), declaration_orders(source) if level == 1 else {}):
                    for changed, how in edits.items():
                        if changed not in seen:
                            seen.add(changed)
                            candidates[changed] = how
            if not candidates:
                break
            candidates_list = list(candidates)[:max(0, budget - used)]
            if not candidates_list:
                break
            scores = list(pool.map(lambda source: scorer.judge(address, source), candidates_list))
            used += len(candidates_list)
            ranked = sorted((score, index) for index, score in enumerate(scores) if score is not None)
            if not ranked:
                break
            if ranked[0][0] < best_score:
                best_score, best_text = ranked[0][0], candidates_list[ranked[0][1]]
                improved = True
                if log:
                    log(f'depth {level}: score {best_score} ({candidates[best_text][0]} at line {candidates[best_text][1] + 1}), {used} compiles')
                if best_score == 0:
                    break
            elif log:
                log(f'depth {level}: nothing under {best_score} in {len(candidates_list)} sources')
            floor = ranked[0][0]
            frontier = [(score, candidates_list[index]) for score, index in ranked if score <= max(floor, best_score)][:beam]
            if used >= budget:
                break
    return best_score, best_text, used, improved


def read(path):
    with open(path, encoding='utf-8') as handle:
        return handle.read()


def write(path, text):
    with open(path, 'w', encoding='utf-8') as handle:
        handle.write(text)


def pool_of(arguments):
    registry = scorer.registry()
    pool = []
    for name in sorted(os.listdir(SOURCES)):
        address = int(name.split('.')[0], 16)
        row = registry.get(address)
        if row and row['status'] == 'tried' and row['best'].isdigit() and arguments.min_score <= int(row['best']) <= arguments.max_score:
            pool.append((int(row['best']), address, os.path.join(SOURCES, name)))
    return sorted(pool)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('address', nargs='?')
    parser.add_argument('source', nargs='?')
    parser.add_argument('--batch', action='store_true')
    parser.add_argument('--min-score', type=int, default=1)
    parser.add_argument('--max-score', type=int, default=40)
    parser.add_argument('--depth', type=int, default=3)
    parser.add_argument('--beam', type=int, default=8)
    parser.add_argument('--budget', type=int, default=4000)
    parser.add_argument('--choices', type=int, default=6, help='random choices per rewrite and line')
    parser.add_argument('--jobs', type=int, default=12)
    parser.add_argument('--write', action='store_true')
    arguments = parser.parse_args()
    if not scorer.compare:
        sys.exit('needs rabbitizer and pyelftools: run with .venv/bin/python')
    scorer.registry()
    if arguments.batch:
        pool = pool_of(arguments)
        print(f'{len(pool)} functions, score {arguments.min_score}-{arguments.max_score}, budget {arguments.budget}, depth {arguments.depth}')
        improved = reached = 0
        for index, (best, address, path) in enumerate(pool, 1):
            score, text, used, _ = search(address, read(path), arguments.depth, arguments.beam, arguments.budget, arguments.jobs, arguments.choices)
            print(f'[{index}/{len(pool)}] {address:#X}: {best} -> {score} ({used} compiles)', flush=True)
            if score is not None and score < best:
                improved += 1
                reached += score == 0
                if arguments.write:
                    write(path, text)
        print(f'{len(pool)} functions: {improved} improved, {reached} reach 0')
        return 0
    if not arguments.address:
        parser.error('an address or --batch')
    address = int(arguments.address, 16)
    path = arguments.source or os.path.join(SOURCES, f'{address:06X}.cpp')
    original = read(path)
    score, text, used, _ = search(address, original, arguments.depth, arguments.beam, arguments.budget, arguments.jobs, arguments.choices, log=print)
    print(f'best {score} ({used} compiles)')
    if arguments.write and score is not None and text != original and score < (scorer.judge(address, original) or 10 ** 9):
        write(path, text)
        print('written')
    return 0


if __name__ == '__main__':
    sys.exit(main())
