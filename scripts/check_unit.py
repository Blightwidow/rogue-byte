#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""check_unit.py [module | address | src file]: after `make elf`, says for the matched functions of src/ (src/MANIFEST.tsv) whether each one
links from C in the verified image (config/us/swapped.tsv) and why not when it fell back (build/image/fallbacks.tsv). Without an
argument it checks every module. Exit 1 when a function of the selection falls back to assembly."""
import os
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))

def rows(path):
    return [line.rstrip('\n').split('\t') for line in list(open(path))[1:]] if os.path.exists(path) else []

def matches(entry, selector):
    address, name, _, file = entry
    return selector is None or selector in (file.split('/')[0], file, address.upper(), name) or os.path.normpath(selector) == os.path.join('src', file)

def main():
    selector = sys.argv[1] if len(sys.argv) > 1 else None
    swapped_path = os.path.join(ROOT, 'config', 'us', 'swapped.tsv')
    if not os.path.exists(swapped_path):
        sys.exit('run `make elf` first: config/us/swapped.tsv is written by the image link')
    swapped = {line.split('\t')[0].upper() for line in open(swapped_path)}
    reasons = {line.split('\t')[0].upper(): line.rstrip('\n').split('\t')[2] for line in open(os.path.join(ROOT, 'build', 'image', 'fallbacks.tsv'))} \
        if os.path.exists(os.path.join(ROOT, 'build', 'image', 'fallbacks.tsv')) else {}
    chosen = [entry for entry in rows(os.path.join(ROOT, 'src', 'MANIFEST.tsv')) if matches(entry, selector)]
    if not chosen:
        sys.exit(f'nothing in src/MANIFEST.tsv matches {selector}')
    failing = [entry for entry in chosen if entry[0].upper() not in swapped]
    for address, name, size, file in failing:
        print(f"{address:>9} {name} ({size} bytes, src/{file}): from assembly{': ' + reasons[address.upper()] if address.upper() in reasons else ''}")
    print(f'{len(chosen) - len(failing)} of {len(chosen)} functions link from C')
    sys.exit(1 if failing else 0)

if __name__ == '__main__':
    main()
