#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""loop_pad.py classify|scan : find the near misses that stop at ps2eeas's short-loop padding, before a worker spends compiles on them.

Before 2026-11-05 the build's assembler padded a short backward-branch loop to six instructions and retail pads to five, so a function whose
C is right differed from retail by one extra `nop` and branch offsets that moved by one; no C wording changes that. Wave N2 lost most of
its score 3 workers to it. The build's assembler now pads to five (docs/build/assembler.md, "Short loops"), so what this tool finds is
what is left: padding that cascades from another difference, or a build that runs the unpatched assembler (assembler_probe.py).

A draft is the wall when its try.py diff has the same instructions as retail once `nop`s are dropped and immediates, branch offsets and
relocation notes are masked (registers stay: a register swap is real work), and the `nop` counts differ.

  python3 scripts/matching/loop_pad.py classify ADDRESS [FILE]          wall | open, with the reason
  python3 scripts/matching/loop_pad.py scan [--min-score 1] [--near 16] [--open-out FILE] [--wall-out FILE]
                                                                         classify every open draft of the registry; the files are address
                                                                         lists for `claim.py init W --addresses FILE`

`scan` compiles each draft once (about a second each, a few at a time) and skips permanent blockers.
"""
import argparse
import concurrent.futures
import csv
import os
import re
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

ROW = re.compile(r'^[0-9a-f]{8}\s')
MARKER, OURS = 48, 50  # compare.py prints the retail instruction from column 9, a `|`/`>`/`<` marker at 48 and ours from 50
IMMEDIATE = re.compile(r'-?0x[0-9A-Fa-f]+|\(\s*-?0x[0-9A-Fa-f]+\s*<<\s*2\s*\)')
RELOCATION = re.compile(r'\[[^\]]*\]')


def normal(instruction):
    """An instruction with immediates, branch offsets and relocation notes masked, registers and mnemonic kept."""
    instruction = RELOCATION.sub('', instruction)
    instruction = IMMEDIATE.sub('#', instruction)
    instruction = re.sub(r'\bfunc_[0-9A-Fa-f]+\b', 'FUNCTION', instruction)
    instruction = re.sub(r'\. \+ 4 \+ #', 'PC', instruction)
    return re.sub(r'\s+', ' ', instruction).strip()


def columns(report):
    """The retail and the compiled instruction lists of a try.py report (header and note lines skipped)."""
    retail, ours = [], []
    for line in report.splitlines():
        marker = line[MARKER:MARKER + 1]
        if marker == '>' and not line[:MARKER].strip():  # inserted in ours
            ours.append(line[OURS:].strip())
            continue
        if not ROW.match(line):
            continue
        left, right = line[9:MARKER].strip(), line[OURS:].strip()
        if left:
            retail.append(left)
        if right and marker != '<':
            ours.append(right)
    return retail, ours


def loop_nops(instructions):
    """How many nops sit in a run directly before a backward branch (the padding of a short loop)."""
    count = 0
    for index, instruction in enumerate(instructions):
        if re.search(r'\(-0x[0-9A-Fa-f]+ << 2\)', instruction):
            back = index - 1
            while back >= 0 and instructions[back] == 'nop':
                count += 1
                back -= 1
    return count


def classify_report(report):
    """('wall', reason) when the diff is only short-loop padding, else ('open', reason)."""
    if not report or not report.startswith('score '):
        return 'open', 'no diff'
    if int(report.split()[1]) == 0:
        return 'open', 'already scores 0'
    retail, ours = columns(report)
    retail_nops = sum(1 for instruction in retail if instruction == 'nop')
    ours_nops = sum(1 for instruction in ours if instruction == 'nop')
    if retail_nops == ours_nops:
        return 'open', 'same number of nops'
    if ours_nops - retail_nops != loop_nops(ours) - loop_nops(retail):
        return 'open', 'extra nops are not before a backward branch'
    left = [normal(instruction) for instruction in retail if instruction != 'nop']
    right = [normal(instruction) for instruction in ours if instruction != 'nop']
    if left != right:
        return 'open', 'instructions differ beyond nops'
    return 'wall', f'{ours_nops - retail_nops:+d} nop (retail {retail_nops}, ours {ours_nops}), everything else identical'


def draft_text(address):
    import claim
    path = claim.draft_source(f'{address:X}')
    if not path:
        return None, None
    with open(path, encoding='utf-8') as handle:
        return handle.read(), 'c' if path.endswith('.c') else 'c++'


def classify(address, text=None, lang='c++'):
    import scorer
    if text is None:
        text, lang = draft_text(address)
        if text is None:
            return 'open', 'no draft'
    scorer.registry()
    return classify_report(scorer.report(address, text, lang))


def scan(arguments):
    import claim
    sys.path.insert(0, os.path.join(LAB, 'scripts'))
    import classify_blockers
    rows = list(csv.DictReader(open(os.path.join(LAB, 'data/matching/functions.tsv'), encoding='utf-8'), delimiter='\t'))
    blockers = classify_blockers.names()
    queue = [(int(row['address'], 16), row['name']) for row in rows
             if row['status'] in ('tried', 'todo') and row['best'].isdigit() and arguments.min_score <= int(row['best']) <= arguments.near
             and claim.draft_source(row['address']) and row['name'] not in blockers]
    queue.sort()
    with concurrent.futures.ThreadPoolExecutor(max_workers=arguments.jobs) as pool:
        results = list(pool.map(lambda item: classify(item[0]), queue))
    walls, opens = [], []
    for (address, name), (verdict, reason) in zip(queue, results):
        (walls if verdict == 'wall' else opens).append(address)
        print(f'{verdict}\t0x{address:06X}\t{name}\t{reason}')
    print(f'{len(walls)} loop-padding wall, {len(opens)} open, of {len(queue)}', file=sys.stderr)
    for path, addresses in ((arguments.wall_out, walls), (arguments.open_out, opens)):
        if path:
            with open(path, 'w', encoding='utf-8') as handle:
                handle.writelines(f'0x{address:06X}\n' for address in addresses)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest='command', required=True)
    one = sub.add_parser('classify')
    one.add_argument('address')
    one.add_argument('file', nargs='?')
    many = sub.add_parser('scan')
    many.add_argument('--min-score', type=int, default=1)
    many.add_argument('--near', type=int, default=16)
    many.add_argument('--jobs', type=int, default=4)
    many.add_argument('--open-out')
    many.add_argument('--wall-out')
    arguments = parser.parse_args()
    if arguments.command == 'scan':
        scan(arguments)
        return 0
    address = int(arguments.address, 16)
    if arguments.file:
        with open(arguments.file, encoding='utf-8') as handle:
            verdict, reason = classify(address, handle.read(), 'c' if arguments.file.endswith('.c') else 'c++')
    else:
        verdict, reason = classify(address)
    print(f'{verdict}: {reason}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
