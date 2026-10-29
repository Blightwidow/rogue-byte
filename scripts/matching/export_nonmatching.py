#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""export_nonmatching.py [--sweep results.json] [--jobs N]: publishes, for every function that is not matched yet, the best source that
compiles with the original compiler, to nonmatching/<module>/<function>.<c|cpp> and nonmatching/MANIFEST.tsv (address, name, size, file, score).

Candidates: a hand-written draft in data/matching/src/fn/<ADDRESS>.cpp and the best m2c draft the sweep found (work/matching/sweep/results.json).
Each is scored with scripts/matching/try.py (instructions that differ from the retail function; 0 would be a match) and the lowest score
wins, a hand-written draft on a tie. Sources that do not compile are left out. The files are never part of the image: they only give
objdiff something to compare (`make objdiff`), so the progress report counts partial work. Run from the repository root after
`make elf`; needs the compiler (see docs/build/compiler-identification.md) and your executable."""
import argparse
import concurrent.futures
import csv
import json
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
OUTPUT = 'nonmatching'


def choose(candidates):
    """The (score, path, language) with the lowest score; the first wins a tie (so list a hand-written draft first)."""
    scored = [candidate for candidate in candidates if candidate[0] is not None]
    return min(scored, key=lambda candidate: candidate[0]) if scored else None


def directory_name(module):
    return re.sub(r'[^A-Za-z0-9_-]+', '-', module).strip('-') or 'unsorted'


def file_name(name):
    name = 'fun_' + name[len('func_'):].lower() if name.startswith('func_') else name
    return re.sub(r'[^A-Za-z0-9_]', '_', name)


def score(address, path, language):
    out = subprocess.run([sys.executable, 'scripts/matching/try.py', f'{address:#x}', path, '--quiet', '--lang', language], capture_output=True, text=True).stdout
    found = re.match(r'score (\d+)', out)
    return int(found.group(1)) if found else None


def evaluate(job):
    address, candidates = job
    return address, choose([(score(address, path, language), path, language) for path, language in candidates])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--sweep', default=os.path.join('work', 'matching', 'sweep', 'results.json'))
    parser.add_argument('--jobs', type=int, default=8)
    arguments = parser.parse_args()
    os.chdir(ROOT)
    report = json.load(open(os.path.join('site', 'data', 'report.json')))
    swept = {address: (path, 'c' if path.endswith('.c') else 'c++') for address, _, _, path in json.load(open(arguments.sweep)) if path}
    jobs, functions = [], {}
    fragments = {int(row['address'], 16) for row in csv.DictReader(open(os.path.join('data', 'matching', 'functions.tsv'), encoding='utf-8'), delimiter='\t')
                 if row['status'] == 'fragment'}  # words between two functions: no source to publish for them
    for function in report['functions']:
        address = int(function['address'], 16)
        if function['status'] == 'c' or function['module'] == 'sdk' or address in fragments:
            continue
        functions[address] = function
        candidates = []
        hand = os.path.join('data', 'matching', 'src', 'fn', f'{address:06X}.cpp')
        if os.path.exists(hand):
            candidates.append((hand, 'c++'))
        if address in swept:
            candidates.append(swept[address])
        if candidates:
            jobs.append((address, candidates))
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        results = [(address, best) for address, best in pool.map(evaluate, jobs) if best]
    readme = open(os.path.join(OUTPUT, 'README.md')).read() if os.path.exists(os.path.join(OUTPUT, 'README.md')) else None  # documentation, not generated
    shutil.rmtree(OUTPUT, ignore_errors=True)
    manifest = []
    for address, (points, path, language) in results:
        function = functions[address]
        folder = os.path.join(OUTPUT, directory_name(function['module']))
        os.makedirs(folder, exist_ok=True)
        extension = '.c' if language == 'c' else '.cpp'
        destination = os.path.join(folder, file_name(function['name']) + extension)
        if os.path.exists(destination):
            destination = os.path.join(folder, f"{file_name(function['name'])}_{address:X}{extension}")
        shutil.copyfile(path, destination)
        manifest.append((f'{address:#X}', function['name'], str(function['size']), destination[len(OUTPUT) + 1:], str(points)))
    with open(os.path.join(OUTPUT, 'MANIFEST.tsv'), 'w') as handle:
        handle.write('address\tname\tsize\tfile\tscore\n')
        for entry in sorted(manifest):
            handle.write('\t'.join(entry) + '\n')
    if readme is not None:
        with open(os.path.join(OUTPUT, 'README.md'), 'w') as handle:
            handle.write(readme)
    print(f'{len(manifest)} of {len(functions)} unmatched functions have a source that compiles -> {OUTPUT}/')


if __name__ == '__main__':
    main()
