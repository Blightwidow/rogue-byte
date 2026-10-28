#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""flag_sweep.py [--jobs N] [--controls N] [--out FILE] - scores every unmatched source, and a sample of matched ones, under other compiler flags.

  python3 scripts/matching/flag_sweep.py      (from the repository root)

Retail may have been built with other flags in some source files. Each source of a function that is `tried` (and a random sample of
`matched` ones, as a control that a variant is not just noise) is judged by scripts/matching/try.py under the base flags and under each
variant of VARIANTS (compile_unit.py reads COMPILE_FLAGS). One row per (function, variant) goes to the output file
(work/matching/flagsweep.tsv: address, module, status, variant, score); rows already there are skipped, so a run can be resumed. Then
scripts/matching/flag_report.py groups the rows by module."""
import argparse
import concurrent.futures
import csv
import json
import os
import random
import re
import subprocess

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
BASE = ['-O2', '-G0', '-ffast-math', '-fno-exceptions']
VARIANTS = {
    'base': BASE,
    'O1': ['-O1', '-G0', '-ffast-math', '-fno-exceptions'],
    'O3': ['-O3', '-G0', '-ffast-math', '-fno-exceptions'],
    'G8': ['-O2', '-G8', '-ffast-math', '-fno-exceptions'],
    'G4': ['-O2', '-G4', '-ffast-math', '-fno-exceptions'],
    'no-fast-math': ['-O2', '-G0', '-fno-exceptions'],
    'exceptions': ['-O2', '-G0', '-ffast-math'],
    'no-gcse': BASE + ['-fno-gcse'],
    'no-sched1': BASE + ['-fno-schedule-insns'],
    'no-sched2': BASE + ['-fno-schedule-insns2'],
    'no-strength': BASE + ['-fno-strength-reduce'],
    'no-cse-jumps': BASE + ['-fno-cse-follow-jumps'],
    'no-rerun-cse': BASE + ['-fno-rerun-cse-after-loop'],
    'no-delayed': BASE + ['-fno-delayed-branch'],
    'no-peephole': BASE + ['-fno-peephole'],
    'no-inline': BASE + ['-fno-inline'],
    'frame-pointer': BASE + ['-fno-omit-frame-pointer'],
}


def source_of(address, row):
    if row['status'] == 'matched' and row['source']:
        return row['source']
    for pattern in ('data/matching/src/fn/%06X.cpp', 'data/matching/src/auto/%06X.c', 'data/matching/src/twin/%06X.cpp'):
        if os.path.exists(os.path.join(ROOT, pattern % address)):
            return pattern % address
    return None


def judge(job):
    address, source, variant = job
    environment = dict(os.environ, COMPILE_FLAGS=' '.join(VARIANTS[variant]))
    result = subprocess.run(['python3', 'scripts/matching/try.py', hex(address), source, '--lang', 'c' if source.endswith('.c') else 'c++', '--quiet'],
                            capture_output=True, text=True, cwd=ROOT, env=environment)
    match = re.match(r'score (\d+)', result.stdout)
    return address, variant, int(match.group(1)) if match else None


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--jobs', type=int, default=12)
    parser.add_argument('--controls', type=int, default=300)
    parser.add_argument('--out', default=os.path.join(ROOT, 'work', 'matching', 'flagsweep.tsv'))
    arguments = parser.parse_args()
    rows = {int(row['address'], 16): row for row in csv.DictReader(open(os.path.join(ROOT, 'data', 'matching', 'functions.tsv')), delimiter='\t')}
    modules = {int(function['address'], 16): function['module'] for function in json.load(open(os.path.join(ROOT, 'site', 'data', 'report.json')))['functions']}
    tried = sorted(address for address, row in rows.items() if row['status'] == 'tried' and source_of(address, row))
    matched = sorted(address for address, row in rows.items() if row['status'] == 'matched' and source_of(address, row))
    random.Random(1).shuffle(matched)
    chosen = [(address, 'tried') for address in tried] + [(address, 'matched') for address in matched[:arguments.controls]]
    done = set()
    if os.path.exists(arguments.out):
        done = {(int(line.split('\t')[0], 16), line.split('\t')[3]) for line in open(arguments.out) if line.strip()}
    jobs = [(address, source_of(address, rows[address]), variant) for address, status in chosen for variant in VARIANTS if (address, variant) not in done]
    status_of = dict(chosen)
    os.makedirs(os.path.dirname(arguments.out), exist_ok=True)
    with open(arguments.out, 'a') as out, concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        for address, variant, score in pool.map(judge, jobs):
            out.write(f'0x{address:X}\t{modules.get(address, "")}\t{status_of[address]}\t{variant}\t{"" if score is None else score}\n')
            out.flush()
    print(f'{len(jobs)} compiles for {len(chosen)} functions')


if __name__ == '__main__':
    main()
