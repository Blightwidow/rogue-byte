#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""assembler_scan.py [--jobs N] [--write] - which functions score better with ps2eeas-loop5 than with their current assembler.

  python3 scripts/matching/assembler_scan.py --write      (from the repository root)

Judges every source of data/matching/src/fn twice with scripts/matching/try.py: with the assembler it gets without
config/us/ps2eeas_loop5.txt (GNU as for config/us/gnu_as.txt, else ps2eeas; the list itself is ignored) and with ps2eeas-loop5 (docs/build/assembler.md). A function
whose score is lower the second way goes into config/us/ps2eeas_loop5.txt (--write); a match lost the other way never does. Prints the
counts and the new matches."""
import argparse
import concurrent.futures
import glob
import os
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 'scripts', 'build'))
import compile_unit  # noqa: E402

LIST = os.path.join(ROOT, 'config', 'us', 'ps2eeas_loop5.txt')
HEADER = """# Functions assembled with ps2eeas-loop5 (SN's ps2eeas with its short-loop padding one nop shorter, scripts/build/compile_unit.py).
# One address per line; derived by scoring every source with it and with its other assembler (scripts/matching/assembler_scan.py).
"""


def judge(path, assembler):
    address = os.path.splitext(os.path.basename(path))[0]
    result = subprocess.run(['python3', 'scripts/matching/try.py', address, path, '--quiet'], capture_output=True, text=True, cwd=ROOT,
                            env={**os.environ, 'TRY_ASSEMBLER': assembler})
    first = (result.stdout.strip().splitlines() or [''])[0]
    return int(first.split()[1]) if first.startswith('score ') else None


def scan(path):
    address = int(os.path.splitext(os.path.basename(path))[0], 16)
    current = judge(path, 'gnu' if address in compile_unit.gnu_functions() else 'ps2eeas')
    return address, current, judge(path, 'ps2eeas-loop5')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--jobs', type=int, default=10)
    parser.add_argument('--write', action='store_true')
    arguments = parser.parse_args()
    sources = sorted(glob.glob(os.path.join(ROOT, 'data', 'matching', 'src', 'fn', '*.cpp')))
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        rows = list(pool.map(scan, sources))
    better = [(address, current, loop5) for address, current, loop5 in rows if current is not None and loop5 is not None and loop5 < current]
    gained = [address for address, current, loop5 in better if loop5 == 0]
    print(f'{len(rows)} sources: {len(better)} score lower with ps2eeas-loop5, {len(gained)} of them match: ' + ' '.join(f'{address:#x}' for address in gained))
    if arguments.write:
        with open(LIST, 'w') as handle:
            handle.write(HEADER + ''.join(f'0x{address:X}\n' for address, _, _ in sorted(better)))


if __name__ == '__main__':
    main()
