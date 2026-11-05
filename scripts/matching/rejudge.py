#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""rejudge.py [--write] [--jobs N] : scores every matched function again with the current toolchain and lists the ones that no longer score 0.

Run it after anything that changes what a source compiles to (the assembler, the compiler, a flag, include/): a match is retail's bytes in
the current build, so a function that scores above 0 is not matched any more. With --write each regression is parked (park.py, reason
regression: status tried, its source kept as a draft with its new score) and `make land` rebuilds without it; without --write nothing changes.
Also prints the scores to work/matching/rejudge.tsv (address, score; empty when the source did not compile)."""
import argparse
import concurrent.futures
import csv
import os
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.chdir(ROOT)
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import park  # noqa: E402


def judge(row):
    lines = subprocess.run([sys.executable, 'scripts/matching/try.py', row['address'], row['source'], '--quiet'], capture_output=True, text=True).stdout.strip().splitlines()
    last = lines[-1] if lines else ''
    return row['address'], int(last.split()[1]) if last.startswith('score ') else None


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--write', action='store_true', help='park the regressions in data/matching/functions.tsv')
    parser.add_argument('--jobs', type=int, default=8)
    arguments = parser.parse_args()
    with open(park.REGISTRY, encoding='utf-8') as handle:
        rows = list(csv.DictReader(handle, delimiter='\t'))
    matched = [row for row in rows if row['status'] == 'matched' and row['source'] and os.path.exists(row['source'])]
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        scores = dict(pool.map(judge, matched))
    lost = {address: score for address, score in scores.items() if score != 0}
    os.makedirs('work/matching', exist_ok=True)
    with open('work/matching/rejudge.tsv', 'w', encoding='utf-8') as handle:
        handle.writelines(f'{address}\t{"" if score is None else score}\n' for address, score in sorted(scores.items()))
    print(f'judged {len(scores)} matched functions: {len(lost)} no longer score 0 ({sum(1 for score in lost.values() if score is None)} did not compile)')
    for address, score in sorted(lost.items()):
        print(f'  {address}: {score}')
    if arguments.write:
        for row in rows:
            if row['address'] in lost and row['status'] == 'matched':
                park.park(row, 'regression', lost[row['address']])
        with open(park.REGISTRY, 'w', encoding='utf-8', newline='') as handle:
            writer = csv.DictWriter(handle, list(rows[0].keys()), delimiter='\t', lineterminator='\n')
            writer.writeheader()
            writer.writerows(rows)
        print(f'{len(lost)} parked as regressions; run `make land`')
    return 1 if lost else 0


if __name__ == '__main__':
    sys.exit(main())
