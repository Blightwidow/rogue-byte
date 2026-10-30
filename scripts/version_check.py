#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""version_check.py [--other work/elf/SCES_525.29] [--jobs N] [--limit N] - does the C of a matched US function reproduce the other version's code?

  .venv/bin/python scripts/version_check.py        (after scripts/pair_versions.py: it reads config/eu/map.tsv)

Each matched function (data/matching/functions.tsv, status `matched`) is compiled the way try.py compiles it and compared with the
function that config/eu/map.tsv pairs it with in the other executable: the fields the object relocates (the targets of calls, the
%hi/%lo of an address) are masked on both sides, the rest must be equal. A score of 0 means the same C gives the other version's
instructions: the function counts for that version, whatever addresses its calls and data have there. `--symbols` is not used: what the
masked fields point at is the next step.

Writes config/eu/c_status.tsv (us_address, name, other_address, pair status, score: empty when the C does not compile or the function has
no pair) and prints the counts."""
import argparse
import concurrent.futures
import csv
import os
import sys
import types
from collections import Counter

LAB = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
sys.path.insert(0, os.path.join(LAB, 'scripts', 'matching'))
sys.path.insert(0, os.path.join(LAB, 'scripts', 'build'))
import compile_unit  # noqa: E402
import scorer  # noqa: E402
from progress import Progress  # noqa: E402

compare = scorer.compare


def check(row, other_address, other_elf):
    """The score of the function's own source against the other executable, or None when it does not compile or compare."""
    address = int(row['address'], 16)
    source = os.path.join(LAB, row['source'])
    if not os.path.isfile(source):
        return None
    language = 'c' if source.endswith('.c') else 'c++'
    stem = os.path.join(scorer.BUILD, f'v{address:06X}-{os.getpid()}-{next(scorer._counter)}')
    os.makedirs(scorer.BUILD, exist_ok=True)
    path = stem + '.o'
    try:
        ok, _ = compile_unit.compile_object(language, source, path, assembler=compile_unit.assembler_for(address), include=scorer.INCLUDE, localize=False)
        if not ok:
            return None
        arguments = types.SimpleNamespace(object=path, address=other_address, elf=other_elf, symbol=row['name'], size=int(row['size']), export=None, quiet=True, symbols=None)
        try:
            output = compare.compare(arguments)
        except SystemExit:
            arguments.symbol = None
            try:
                output = compare.compare(arguments)
            except SystemExit:
                return None
        return scorer.score_of(output)
    finally:
        for leftover in (path, path + '.tmp', path + '.s'):
            if os.path.exists(leftover):
                os.remove(leftover)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--other', default=os.path.join(LAB, 'work', 'elf', 'SCES_525.29'))
    parser.add_argument('--map', default=os.path.join(LAB, 'config', 'eu', 'map.tsv'))
    parser.add_argument('--out', default=os.path.join(LAB, 'config', 'eu', 'c_status.tsv'))
    parser.add_argument('--jobs', type=int, default=8)
    parser.add_argument('--limit', type=int, default=0, help='only the first N matched functions (to try it)')
    arguments = parser.parse_args()
    if not compare:
        sys.exit('needs rabbitizer and pyelftools: run with .venv/bin/python')
    pairs = {int(row['us_address'], 16): row for row in csv.DictReader(open(arguments.map, encoding='utf-8'), delimiter='\t') if row['other_address']}
    rows = [row for row in csv.DictReader(open(scorer.REGISTRY, encoding='utf-8'), delimiter='\t') if row['status'] == 'matched' and row['source']]
    rows.sort(key=lambda row: int(row['address'], 16))
    if arguments.limit:
        rows = rows[:arguments.limit]
    progress = Progress(len(rows), 'version-check')

    def work(row):
        address = int(row['address'], 16)
        pair = pairs.get(address)
        name = row['address'][2:]
        progress.begin(name)
        score = check(row, int(pair['other_address'], 16), arguments.other) if pair else None
        progress.tick(f'{name}: {score}', name)
        return row, pair, score

    results = []
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        results = list(pool.map(work, rows))
    progress.done()
    os.makedirs(os.path.dirname(arguments.out), exist_ok=True)
    counts, sizes = Counter(), Counter()
    with open(arguments.out, 'w', encoding='utf-8') as handle:
        handle.write('us_address\tname\tother_address\tpair\tscore\n')
        for row, pair, score in results:
            other = pair['other_address'] if pair else ''
            handle.write(f'{row["address"]}\t{row["name"]}\t{other}\t{pair["status"] if pair else "none"}\t{"" if score is None else score}\n')
            kind = 'unpaired' if not pair else 'no result' if score is None else 'exact' if score == 0 else 'near' if score <= 5 else 'different'
            counts[kind] += 1
            sizes[kind] += int(row['size'])
    total, total_size = len(results), sum(sizes.values())
    for kind in ('exact', 'near', 'different', 'no result', 'unpaired'):
        print(f'{kind:10} {counts[kind]:5} functions  {sizes[kind]:8} bytes  {100 * sizes[kind] / total_size:5.1f}%')
    print(f'{total} matched US functions checked against {os.path.basename(arguments.other)}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
