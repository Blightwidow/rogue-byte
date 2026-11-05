#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""assembler_probe.py --assembler PATH [--args "-G0"] [--sample N] [--jobs N] [--out FILE] : measures a candidate assembler against the one the build
uses, before anyone changes the build (docs/build/assembler.md, "Before changing the assembler").

Both are run on the same sources, with the same compiler and flags, through scripts/matching/try.py (the candidate by setting EE_AS_EXE and
EE_AS_ARGS, which compile_unit.py reads; nothing in the repository changes). Two groups, from the registry (data/matching/functions.tsv):

  near     every unmatched function whose best draft scores 1 to 5 and has a source in data/matching/src/fn (what a better assembler can win)
  matched  N matched functions, seeded (default 120) that have a source (what it must not lose)

Prints, per group, how many score 0 under each and the functions that change, and writes every score to --out (a tsv: group, address, build,
candidate) when given. A candidate is worth a full re-judge (scripts/matching/rejudge.py) when it wins `near` and loses next to nothing in
`matched`; record the numbers in docs/build/assembler.md either way."""
import argparse
import concurrent.futures
import csv
import os
import random
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.chdir(ROOT)


def source_of(address):
    stem = f'data/matching/src/fn/{address[2:].upper()}'
    for extension in ('.cpp', '.c'):
        if os.path.exists(stem + extension):
            return stem + extension
    return None


def groups(sample, seed):
    with open('data/matching/functions.tsv', encoding='utf-8') as handle:
        rows = list(csv.DictReader(handle, delimiter='\t'))
    near = [row['address'] for row in rows if row['status'] in ('tried', 'todo') and row['best'].isdigit() and 1 <= int(row['best']) <= 5
            and int(row['size']) >= 16 and source_of(row['address'])]
    matched = [row['address'] for row in rows if row['status'] == 'matched' and source_of(row['address'])]
    random.Random(seed).shuffle(matched)
    return {'near': near, 'matched': matched[:sample]}


def score(address, environment):
    lines = subprocess.run([sys.executable, 'scripts/matching/try.py', address, source_of(address), '--quiet'], capture_output=True, text=True,
                           env=environment).stdout.strip().splitlines()
    last = lines[-1] if lines else ''
    return int(last.split()[1]) if last.startswith('score ') else None


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--assembler', required=True, help='the candidate executable (run through wibo like the build)')
    parser.add_argument('--args', default='-G0', help='its arguments before -o (default -G0)')
    parser.add_argument('--sample', type=int, default=120)
    parser.add_argument('--seed', type=int, default=7)
    parser.add_argument('--jobs', type=int, default=8)
    parser.add_argument('--out')
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.assembler):
        sys.exit(f'{arguments.assembler}: not a file')
    build = dict(os.environ)
    build.pop('EE_AS_EXE', None)
    build.pop('EE_AS_ARGS', None)
    candidate = dict(os.environ, EE_AS_EXE=os.path.abspath(arguments.assembler), EE_AS_ARGS=arguments.args)
    jobs = [(group, address) for group, addresses in groups(arguments.sample, arguments.seed).items() for address in addresses]
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        base = list(pool.map(lambda job: score(job[1], build), jobs))
        other = list(pool.map(lambda job: score(job[1], candidate), jobs))
    rows = [(group, address, b, c) for (group, address), b, c in zip(jobs, base, other)]
    for group in ('near', 'matched'):
        chosen = [row for row in rows if row[0] == group]
        win = [row for row in chosen if row[3] == 0 and row[2] != 0]
        lose = [row for row in chosen if row[2] == 0 and row[3] != 0]
        print(f'{group}: {len(chosen)} functions; score 0 with the build {sum(1 for row in chosen if row[2] == 0)}, with the candidate '
              f'{sum(1 for row in chosen if row[3] == 0)}; candidate wins {len(win)}, loses {len(lose)}')
        for label, picked in (('wins', win), ('loses', lose)):
            if picked:
                print(f'  {label}: ' + ' '.join(row[1] for row in picked[:40]) + (' ...' if len(picked) > 40 else ''))
    if arguments.out:
        with open(arguments.out, 'w', encoding='utf-8') as handle:
            handle.write('group\taddress\tbuild\tcandidate\n')
            handle.writelines(f'{g}\t{a}\t{b}\t{c}\n' for g, a, b, c in rows)
    return 0


if __name__ == '__main__':
    sys.exit(main())
