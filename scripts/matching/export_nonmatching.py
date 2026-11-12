#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""export_nonmatching.py [--sweep results.json] [--jobs N]: publishes, for every function that is not matched yet, the best source that
compiles with the original compiler, to nonmatching/<module>/<function>.<c|cpp> and nonmatching/MANIFEST.tsv (address, name, size, file, score).

Candidates: a hand-written draft in data/matching/src/fn/<ADDRESS>.cpp or .c (the SDK range included, scored with its own
compiler through try.py) and the best m2c draft the sweep found (work/matching/sweep/results.json).
A candidate that holds a construct AGENTS.md bans (scripts/matching/record.py `scan`: volatile on ordinary data, register pins, an empty asm,
mfc1 asm) is left out, so a published score never leans on a trick. Each is scored with scripts/matching/try.py (instructions that differ
from the retail function; 0 would be a match) and the lowest score wins, a hand-written draft on a tie. Sources that do not compile are left
out. The registry (data/matching/functions.tsv) gets that score as `best` for every unmatched function with a published source, so an
honest rewrite of an inflated draft lowers or raises it to the truth. The files are never part of the image: they only give
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

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from progress import Progress  # noqa: E402
from record import scan  # noqa: E402  (what AGENTS.md bans because it only steers the compiler)

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


TRACKER = []  # the Progress of main(), for the worker threads


def evaluate(job):
    address, candidates = job
    tracker = TRACKER[0] if TRACKER else None
    if tracker:
        tracker.begin(f'{address:06X}')
    best = choose([(score(address, path, language), path, language) for path, language in candidates])
    if tracker:
        tracker.tick(f'{address:06X}: {best[0] if best else None}', f'{address:06X}')
    return address, best


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--sweep', default=os.path.join('work', 'matching', 'sweep', 'results.json'))
    parser.add_argument('--jobs', type=int, default=8)
    arguments = parser.parse_args()
    os.chdir(ROOT)
    report = json.load(open(os.path.join('work', 'report.json')))
    swept = {address: (path, 'c' if path.endswith('.c') else 'c++') for address, _, _, path in json.load(open(arguments.sweep)) if path}
    jobs, functions, banned_dropped = [], {}, []
    fragments = {int(row['address'], 16) for row in csv.DictReader(open(os.path.join('data', 'matching', 'functions.tsv'), encoding='utf-8'), delimiter='\t')
                 if row['status'] == 'fragment'}  # words between two functions: no source to publish for them
    for function in report['functions']:
        address = int(function['address'], 16)
        if function['status'] == 'c' or address in fragments:
            continue
        functions[address] = function
        candidates = []
        hand = [(os.path.join('data', 'matching', 'src', 'fn', f'{address:06X}{extension}'), language)
                for extension, language in (('.cpp', 'c++'), ('.c', 'c'))]
        for candidate in [entry for entry in hand if os.path.exists(entry[0])] + ([swept[address]] if address in swept else []):
            if scan(open(candidate[0], encoding='utf-8').read()):
                banned_dropped.append(address)
            else:
                candidates.append(candidate)
        if candidates:
            jobs.append((address, candidates))
    progress = Progress(len(jobs), 'nonmatching')
    TRACKER.append(progress)
    results = []
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        for address, best in pool.map(evaluate, jobs):
            if best:
                results.append((address, best))
    progress.done()
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
    registry_path = os.path.join('data', 'matching', 'functions.tsv')
    if os.path.exists(registry_path):
        rows = list(csv.DictReader(open(registry_path, encoding='utf-8'), delimiter='\t'))
        honest = {address: points for address, (points, _, _) in results}
        changed = 0
        for row in rows:
            address = int(row['address'], 16)
            if address in honest and row['status'] in ('tried', 'todo') and row['best'] != str(honest[address]):
                row['best'] = str(honest[address])
                changed += 1
        with open(registry_path, 'w', encoding='utf-8', newline='') as out:
            writer = csv.DictWriter(out, list(rows[0].keys()), delimiter='\t', lineterminator='\n')
            writer.writeheader()
            writer.writerows(rows)
        print(f'registry: best set from the published source for {changed} functions')
    print(f'{len(banned_dropped)} candidates left out for a banned construct')
    print(f'{len(manifest)} of {len(functions)} unmatched functions have a source that compiles -> {OUTPUT}/')


if __name__ == '__main__':
    main()
