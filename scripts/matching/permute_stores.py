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
import search_guard  # noqa: E402

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


CONSTANT_STORE = re.compile(r'[^=;]*[^=!<>]=(?!=)\s*(-?(?:0[xX][0-9a-fA-F]+|\d+(?:\.\d*)?f?))\s*;\s*(?://.*)?$')


def constant_of(line):
    """The literal a store assigns (`-1`, `0x20`, `1.0f`), or None for a store of anything else (a chain `a = b = 0;` counts as None)."""
    match = CONSTANT_STORE.match(line.strip())
    return match.group(1) if match and line.count('=') == 1 else None


def dead_constant_orders(stores):
    """Candidate orders of a region's store lines from one rule of gcc 2.95's first scheduler: a store that is the last use of its constant (the
    constant's register dies there, REG_DEAD) is ranked ahead of one that is not, then source order decides. So among the stores that share a
    constant, the one written LAST in the source is the one emitted first. Found on InitMurray, which 2,500 random orders did not reach: the
    -1 stores wanted one in the group written last (0x17F4) and the -60 pair the other way round. Returns the orders that differ from the given
    one: the last store of each constant group moved to the group's first place (every group together, then each group alone), and every group
    reversed. At most about ten, tried before the random search."""
    groups = {}
    for position, line in enumerate(stores):
        constant = constant_of(line)
        if constant is not None:
            groups.setdefault(constant, []).append(position)
    groups = {constant: places for constant, places in groups.items() if len(places) >= 2}
    if not groups:
        return []

    def reordered(chosen, how):
        order = list(stores)
        for constant in chosen:
            places = groups[constant]
            members = [stores[place] for place in places]
            members = [members[-1]] + members[:-1] if how == 'rotate' else members[::-1]
            for place, line in zip(places, members):
                order[place] = line
        return order

    found = []
    for candidate in [reordered(groups, 'rotate'), reordered(groups, 'reverse')] + [reordered([constant], 'rotate') for constant in groups] \
            + [reordered([constant], 'reverse') for constant in groups if len(groups[constant]) > 2]:
        if candidate != stores and candidate not in found:
            found.append(candidate)
    return found[:10]


def climb(address, lines, region, lang, budget, start_score):
    """Hill climb over the order of the stores of one region: every move of one store to another place of the region (the other lines stay), the first
    that scores lower is kept and the climb restarts from it; a move to an equal score is kept too (at most 30 times in a row: a plateau is crossed by
    a move that changes nothing visible). Returns (score, lines, compiles). Random orders (permute.marked_search) cannot reach an order that is
    ten moves from the start in a region of 14 stores; a climb gets there in a few hundred compiles."""
    stores = [lines[index] for index in region]
    best_score, spent, sideways = start_score, 0, 0
    seen = {tuple(stores)}

    def placed(order):
        changed = list(lines)
        for index, line in zip(region, order):
            changed[index] = line
        return changed

    improved = True
    while improved and best_score > 0 and spent < budget:
        improved = False
        for source in range(len(stores)):
            for target in range(len(stores)):
                if source == target:
                    continue
                order = list(stores)
                order.insert(target, order.pop(source))
                if tuple(order) in seen:
                    continue
                seen.add(tuple(order))
                score = permute.judge(address, '\n'.join(placed(order)), lang)
                spent += 1
                if score is not None and (score < best_score or (score == best_score and sideways < 30)):
                    sideways = sideways + 1 if score == best_score else 0
                    best_score, stores, improved = score, order, True
                    break
                if spent >= budget:
                    break
            if improved or spent >= budget:
                break
    return best_score, placed(stores), spent


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
        for order in dead_constant_orders([lines[index] for index in region]):  # one rule of the first scheduler, before any random order
            trial = list(lines)
            for index, line in zip(region, order):
                trial[index] = line
            score = permute.judge(address, '\n'.join(trial), lang)
            spent += 1
            if score is not None and score < best_score:
                best_score, best_text, lines = score, '\n'.join(trial), trial
        if best_score == 0:
            break
        marked = [line + ' //P' if index in region else line for index, line in enumerate(lines)]
        score, candidate, used = permute.marked_search(address, '\n'.join(marked), budget - spent, 1, lang, budget - spent, seed=seed)
        spent += used
        if score is not None and score < best_score:
            best_score, best_text = score, '\n'.join(line[:-4] if line.endswith(' //P') else line for line in candidate.split('\n'))
        if best_score > 0 and len(region) > 5:  # too many orders for a random sample: climb from the best order found
            score, climbed, used = climb(address, best_text.split('\n'), region, lang, budget, best_score)
            spent += used
            if score < best_score:
                best_score, best_text = score, '\n'.join(climbed)
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
    left_out = [row for row in rows if search_guard.skipped(int(row['address'], 16))]
    rows = [row for row in rows if row not in left_out]
    if left_out:
        print(f'{len(left_out)} functions left out (config/matching/walls.tsv, boundary suspects)')
    rows = [row for row in rows if regions(open(os.path.join('nonmatching', row['file']), encoding='utf-8').read().split('\n'))]
    os.makedirs(arguments.out, exist_ok=True)
    improved = matched = 0
    progress = Progress(len(rows), 'permute-stores')

    def run(row):
        address = f"0x{int(row['address'], 16):06X}"
        progress.begin(address[2:])
        source = os.path.join('nonmatching', row['file'])
        previous = os.path.join(arguments.out, f'{int(row["address"], 16):06X}' + ('.c' if source.endswith('.c') else '.cpp'))
        if os.path.exists(previous):  # a better order found by an earlier run is the starting point
            source = os.path.abspath(previous)
        found = search(address, source, arguments.budget, arguments.seed)
        progress.tick(f'{address[2:]}: {found[0]} -> {found[1]}', address[2:])
        return row, address, source, found

    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        for row, address, source, (start, score, text) in pool.map(run, rows):
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
