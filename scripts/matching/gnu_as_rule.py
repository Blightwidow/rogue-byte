#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""gnu_as_rule.py [--write] - the functions whose retail code has a five-instruction loop (a backward branch with offset -5).

  python3 scripts/matching/gnu_as_rule.py --write      (from the repository root, after `make elf`)

`ps2eeas` pads every backward-branch loop shorter than six instructions up to six, so no function it assembled has a branch with offset
-5: among the 3,500 matched functions that were measured, 31 of the ones that need GNU `as` have one and none of the `ps2eeas` ones does.
So a function whose retail code has a -5 branch was assembled with GNU `as`. Prints how many such functions config/us/gnu_as.txt lacks;
--write adds them to it (the file stays sorted, one address per line)."""
import argparse
import glob
import os
import re

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
WORD = re.compile(r'\s*/\* \S+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+(\S+)')
BRANCH = re.compile(r'^(b|beq|bne|beqz|bnez|bgez|bgtz|blez|bltz|bc1[tf]l?|beql|bnel|bnezl|beqzl|bgezl|bgtzl|blezl|bltzl)$')
BACKWARD_FIVE = 0xFFFB


def functions_with_short_loop():
    """Start addresses of the functions of build/splat/asm that contain a backward branch of offset -5."""
    found = set()
    for path in glob.glob(os.path.join(ROOT, 'build', 'splat', 'asm', '*.s')):
        start = None
        for line in open(path):
            if line.startswith('glabel'):
                start = None
                continue
            match = WORD.match(line)
            if not match:
                continue
            address = int(match.group(1), 16)
            start = address if start is None else start
            word = match.group(2)
            if BRANCH.match(match.group(3)) and int(word[2:4] + word[0:2], 16) == BACKWARD_FIVE:
                found.add(start)
    return found


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--write', action='store_true')
    arguments = parser.parse_args()
    path = os.path.join(ROOT, 'config', 'us', 'gnu_as.txt')
    lines = open(path).read().splitlines()
    listed = {int(line.split()[0], 16) for line in lines if line.strip() and not line.startswith('#')}
    missing = sorted(functions_with_short_loop() - listed)
    print(f'{len(missing)} functions with a five-instruction loop are not in {os.path.relpath(path, ROOT)}')
    if arguments.write and missing:
        with open(path, 'a') as handle:
            handle.write('# A five-instruction loop in retail: ps2eeas pads those, so GNU as (scripts/matching/gnu_as_rule.py)\n')
            handle.writelines(f'0x{address:X}\n' for address in missing)


if __name__ == '__main__':
    main()
