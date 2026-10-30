#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""adopt.py [--dry-run] [DIR ...] - takes the better sources of the search tools' work folders into data/matching/src/fn.

fix_stack.py and permute_stores.py never change the repository: they write the sources they improved to work/matching/fix-stack/ and
work/matching/permute-stores/ (named <ADDRESS>.cpp or .c). This judges each of them and the source the function has now, in process, and
copies a file over the current source only when it scores strictly lower (a .c file is judged as C; one for a function that has no source
yet is taken). Run `make adopt` after `make fix-stack` or `make permute-stores`; then register the matches with try.py --record."""
import argparse
import os
import re
import shutil
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scorer  # noqa: E402

LAB = scorer.LAB
SOURCES = os.path.join(LAB, 'data', 'matching', 'src', 'fn')
FOLDERS = [os.path.join(LAB, 'work', 'matching', name) for name in ('fix-stack', 'permute-stores')]
FILE = re.compile(r'([0-9A-Fa-f]{6})\.(cpp|c)$')


def language(path):
    return 'c' if path.endswith('.c') else 'c++'


def read(path):
    with open(path, encoding='utf-8') as handle:
        return handle.read()


def adopt(folders, dry_run=False):
    """(candidates judged, sources adopted, sources that reached 0)."""
    judged = adopted = reached = 0
    for folder in folders:
        if not os.path.isdir(folder):
            continue
        for name in sorted(os.listdir(folder)):
            found = FILE.match(name)
            if not found:
                continue
            address = int(found.group(1), 16)
            candidate = os.path.join(folder, name)
            current = next((os.path.join(SOURCES, f'{address:06X}{extension}') for extension in ('.cpp', '.c')
                            if os.path.exists(os.path.join(SOURCES, f'{address:06X}{extension}'))), None)
            new_score = scorer.judge(address, read(candidate), language(candidate))
            if new_score is None:
                continue
            judged += 1
            old_score = scorer.judge(address, read(current), language(current)) if current else None
            if current is not None and old_score is not None and new_score >= old_score:
                continue
            destination = os.path.join(SOURCES, f'{address:06X}{os.path.splitext(name)[1]}')
            print(f'{address:#X}: {old_score} -> {new_score} ({os.path.relpath(candidate, LAB)})')
            if not dry_run:
                if current and current != destination:
                    os.remove(current)
                shutil.copyfile(candidate, destination)
            adopted += 1
            reached += new_score == 0
    return judged, adopted, reached


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('folders', nargs='*', help='work folders (default: work/matching/fix-stack and permute-stores)')
    parser.add_argument('--dry-run', action='store_true')
    arguments = parser.parse_args()
    if not scorer.compare:
        sys.exit('needs rabbitizer and pyelftools: run with .venv/bin/python')
    scorer.registry()
    judged, adopted, reached = adopt(arguments.folders or FOLDERS, arguments.dry_run)
    print(f'{judged} candidates judged, {adopted} {"would be " if arguments.dry_run else ""}adopted, {reached} reach 0')
    return 0


if __name__ == '__main__':
    sys.exit(main())
