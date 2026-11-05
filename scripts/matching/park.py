#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""park.py REASON ADDRESS... : takes functions out of the matched set and says why, by hand. REASON is
  asm          the source holds a banned construct: its source moves to data/matching/asm-archive
  cleanup      the source breaks the cleanup rules: it moves to data/matching/cleanup-pending until rewritten
  regression   a toolchain change made it score above 0: it stays a draft in data/matching/src/fn with its new score (--score N)
The registry row (data/matching/functions.tsv) becomes `tried` with no source. record.py parks by itself what it finds on a new match;
use this for what a re-judge or a review turns up (scripts/matching/rejudge.py calls park() for regressions). Addresses: hex, one per
argument; `-` reads them from standard input, one per line."""
import argparse
import csv
import os
import shutil
import sys

REGISTRY = 'data/matching/functions.tsv'
FOLDERS = {'asm': 'asm-archive', 'cleanup': 'cleanup-pending'}


def park(row, reason, score=None):
    """Marks one registry row (a dict) as parked for `reason`, moving its source when the reason says so. Returns the new source path or ''."""
    destination = ''
    source = row.get('source', '')
    if reason in FOLDERS and source and os.path.exists(source):
        folder = os.path.join('data', 'matching', FOLDERS[reason])
        os.makedirs(folder, exist_ok=True)
        destination = os.path.join(folder, os.path.basename(source))
        shutil.move(source, destination)
    row['status'] = 'tried'
    row['source'] = ''
    row['best'] = '' if score is None else str(score)
    return destination


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('reason', choices=['asm', 'cleanup', 'regression'])
    parser.add_argument('addresses', nargs='+')
    parser.add_argument('--score', type=int, help='the new best score of a regression')
    arguments = parser.parse_args()
    addresses = [line.strip() for line in sys.stdin if line.strip()] if arguments.addresses == ['-'] else arguments.addresses
    wanted = {int(address, 16) for address in addresses}
    with open(REGISTRY, encoding='utf-8') as handle:
        rows = list(csv.DictReader(handle, delimiter='\t'))
    done = 0
    for row in rows:
        if int(row['address'], 16) in wanted and row['status'] == 'matched':
            destination = park(row, arguments.reason, arguments.score)
            print(f'parked {row["address"]} {row["name"]}: {arguments.reason}' + (f' -> {destination}' if destination else ''))
            done += 1
    with open(REGISTRY, 'w', encoding='utf-8', newline='') as handle:
        writer = csv.DictWriter(handle, list(rows[0].keys()), delimiter='\t', lineterminator='\n')
        writer.writeheader()
        writer.writerows(rows)
    print(f'{done} of {len(wanted)} functions parked')
    return 0 if done == len(wanted) else 1


if __name__ == '__main__':
    sys.exit(main())
