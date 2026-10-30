#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""fix_stack.py [--jobs N] [--out DIR] [address ...] - the real size of the placeholder `sp[0x400]` stack buffer of the non-matching sources.

  .venv/bin/python scripts/matching/fix_stack.py        (from the repository root)

An m2c draft of a function with a stack area gets a local `char sp[N]` (N is 0x400 in 349 of the near misses: a placeholder, not a size). The
frame of the retail function is its `addiu $sp, $sp, -F`, and the local is what is left of it after the saved registers and `$ra`, so only
a few sizes are possible. For each source whose buffer is at least 0x100 bytes this tries every multiple of 0x10 below the frame size, keeps
the lowest score and writes the source to --out (default work/matching/fix-stack/<ADDRESS>.<ext>) when it beats the original. The repository
is never changed. Use the .venv python so that permute.py scores in process."""
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

BUFFER = re.compile(r'\b((?:char|s8|u8)\s+sp\[)(0x[0-9A-Fa-f]+)(\])')
FRAME = re.compile(r'addiu\s+\$sp,\s*\$sp,\s*-(0x[0-9A-Fa-f]+|\d+)')
SPLIT = os.path.join('work', 'matching', 'split', 'asm', 'functions', 'SCUS_973')


def frame_size(name):
    path = os.path.join(ROOT, SPLIT, name + '.s')
    if not os.path.exists(path):
        return None
    found = FRAME.search(open(path, encoding='utf-8').read())
    return int(found.group(1), 0) if found else None


def search(row):
    address = f"0x{int(row['address'], 16):06X}"
    source = os.path.join(ROOT, 'nonmatching', row['file'])
    lang = 'c' if source.endswith('.c') else 'c++'
    text = open(source, encoding='utf-8').read()
    found = BUFFER.search(text)
    frame = frame_size(row['name'])
    if not found or not frame:
        return None
    start = permute.judge(address, text, lang)
    if start in (None, 0):
        return None
    best_score, best_text = start, text
    for size in range(0x10, min(frame, 0x200), 0x10):
        candidate = text[:found.start(2)] + hex(size).upper().replace('X', 'x') + text[found.end(2):]
        score = permute.judge(address, candidate, lang)
        if score is not None and score < best_score:
            best_score, best_text = score, candidate
    return (address, row['name'], lang, start, best_score, best_text) if best_score < start else None


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('addresses', nargs='*')
    parser.add_argument('--jobs', type=int, default=6)
    parser.add_argument('--out', default=os.path.join('work', 'matching', 'fix-stack'))
    arguments = parser.parse_args()
    os.chdir(ROOT)
    wanted = {int(address, 16) for address in arguments.addresses}
    rows = []
    for row in csv.DictReader(open(os.path.join('nonmatching', 'MANIFEST.tsv'), encoding='utf-8'), delimiter='\t'):
        if wanted and int(row['address'], 16) not in wanted:
            continue
        found = BUFFER.search(open(os.path.join('nonmatching', row['file']), encoding='utf-8').read())
        if found and int(found.group(2), 16) >= 0x100:
            rows.append(row)
    os.makedirs(arguments.out, exist_ok=True)
    improved = matched = 0
    progress = Progress(len(rows), 'fix-stack')
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        for result in pool.map(search, rows):
            progress.tick()
            if result:
                address, name, lang, start, score, text = result
                improved += 1
                matched += score == 0
                extension = '.c' if lang == 'c' else '.cpp'
                with open(os.path.join(arguments.out, f'{int(address, 16):06X}{extension}'), 'w', encoding='utf-8') as handle:
                    handle.write(text)
                print(f'{address} {name}: {start} -> {score}', flush=True)
    progress.done()
    print(f'{len(rows)} sources with a large buffer, {improved} improved, {matched} match')


if __name__ == '__main__':
    main()
