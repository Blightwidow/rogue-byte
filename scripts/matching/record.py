#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""record.py [--jobs N] [--dry-run] [--no-scan] - judges every source in data/matching/src/fn and records it in the registry.

  python3 scripts/matching/record.py       (from the repository root; `make land` runs it first)

Each data/matching/src/fn/<ADDRESS>.cpp (or .c, judged as C) is judged by scripts/matching/try.py, which picks the assembler by
address (config/us). The registry row (data/matching/functions.tsv) gets status `matched` with the source at score 0, else `tried` with
the best score so far and one more try. A function of the SDK range (status `library`) is registered the same way.

A new match is scanned for what AGENTS.md bans because it only steers the compiler: `volatile` on ordinary data (a pointer to a hardware
register, an address from 0x10000000 up, is allowed), `register` pins, an empty `asm` with clobbers, and `mfc1` asm that moves a register.
The scan prints every hit and the run exits 1 after recording: review them (`--no-scan` skips the scan). Prints the totals and the
functions that matched this time."""
import argparse
import concurrent.futures
import csv
import glob
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from progress import Progress  # noqa: E402

REGISTRY = 'data/matching/functions.tsv'
STAMP = 'work/matching/last_record'  # sources older than the last record were counted already
SOURCES = 'data/matching/src/fn'

HARDWARE_ADDRESS = re.compile(r'0x1[0-9A-Fa-f]{7}\b')
BANNED = [
    ('volatile', re.compile(r'(?<!asm )(?<!asm\t)\bvolatile\b')),  # not the `asm volatile` of a statement: the asm checks cover those
    ('register pin', re.compile(r'\bregister\b[^;]*\basm\b|\basm\s*\(\s*"\$')),
    ('empty asm', re.compile(r'\basm\s*(?:volatile\s*)?\(\s*""')),
    ('mfc1 asm', re.compile(r'\basm\b[^;]*\bmfc1\b')),
]
VU_ASM = re.compile(r'asm\s+volatile\s*\(\s*"(?:lqc2|sqc2|qmtc2|qmfc2|v[a-z]|prot|pext|pcpy|ppac)')


def scan(text):
    """[(line number, what, line)] of the constructs AGENTS.md bans in a source."""
    found = []
    for number, line in enumerate(text.split('\n'), 1):
        code = line.split('//')[0]
        for what, pattern in BANNED:
            if pattern.search(code):
                if what == 'volatile' and (HARDWARE_ADDRESS.search(code) or VU_ASM.search(code)):
                    continue  # a hardware register, or the VU0 asm of a matched source
                found.append((number, what, line.strip()[:100]))
    return found


def judge(path):
    address = os.path.splitext(os.path.basename(path))[0]
    result = subprocess.run([sys.executable, 'scripts/matching/try.py', address, path, '--quiet'], capture_output=True, text=True)
    first = (result.stdout.strip().splitlines() or [''])[-1]
    return int(address, 16), (int(first.split()[1]) if first.startswith('score ') else None), path


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--jobs', type=int, default=8)
    parser.add_argument('--dry-run', action='store_true', help='judge and report, change nothing')
    parser.add_argument('--no-scan', action='store_true', help='do not scan the new matches for banned constructs')
    arguments = parser.parse_args()
    rows = list(csv.DictReader(open(REGISTRY, encoding='utf-8'), delimiter='\t'))
    by_address = {int(row['address'], 16): row for row in rows}
    sources = sorted(glob.glob(f'{SOURCES}/*.cpp') + glob.glob(f'{SOURCES}/*.c'))
    progress = Progress(len(sources), 'record')
    results = []
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        for result in pool.map(judge, sources):
            results.append(result)
            progress.tick(f'{result[0]:06X}: {result[1]}')
    progress.done()
    new_matches, tried = [], 0
    since = os.path.getmtime(STAMP) if os.path.exists(STAMP) else 0
    for address, score, path in results:
        row = by_address.get(address)
        if not row or row['status'] == 'matched':
            continue
        if os.path.getmtime(path) > since:
            row['tries'] = str(int(row['tries'] or 0) + 1)
        if score is not None and (row['best'] == '' or score < int(row['best'])):
            row['best'] = str(score)
        if score == 0:
            row['status'], row['source'] = 'matched', path
            new_matches.append(row)
        else:
            row['status'] = 'tried'
            tried += 1
    for note in glob.glob('data/matching/notes/*.md'):
        row = by_address.get(int(os.path.splitext(os.path.basename(note))[0], 16))
        if row and row['status'] == 'todo':
            row['status'], row['tries'] = 'tried', str(int(row['tries'] or 0) + 1)
            tried += 1
    if not arguments.dry_run:
        os.makedirs(os.path.dirname(STAMP), exist_ok=True)
        open(STAMP, 'w').close()
        with open(REGISTRY, 'w', encoding='utf-8', newline='') as out:
            writer = csv.DictWriter(out, list(rows[0].keys()), delimiter='\t', lineterminator='\n')
            writer.writeheader()
            writer.writerows(rows)
    matched = [row for row in rows if row['status'] == 'matched']
    print(f'{len(sources)} sources judged{" (dry run)" if arguments.dry_run else ""}: {len(new_matches)} new matches '
          f'({sum(int(row["size"]) for row in new_matches)} bytes), {tried} tried; registry: {len(matched)} of {len(rows)} matched')
    flagged = 0
    if not arguments.no_scan:
        for row in new_matches:
            hits = scan(open(row['source'], encoding='utf-8').read())
            for number, what, line in hits:
                print(f'review: {row["source"]}:{number}: {what}: {line}')
            flagged += bool(hits)
        if flagged:
            print(f'{flagged} new match(es) contain a construct AGENTS.md bans: review them, or run again with --no-scan')
    return 1 if flagged else 0


if __name__ == '__main__':
    sys.exit(main())
