#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""permute.py <address> <source.cpp> [--budget N] [--jobs N] [--write] - decomp.wtf's permuter for near misses: tries
other orders of independent statements and keeps the best.

  python3 scripts/matching/permute.py 0x11A060 data/matching/src/fn/11A060.cpp --write      (from the lab root)

gcc 2.95 emits independent stores and loads in an order that follows the source in no simple way, and the order of
local declarations decides stack slots and registers, so many near misses (the same instructions, another order) are
one reordering away. The source is scanned for runs of consecutive simple statements at one indentation (assignments,
calls, declarations: not control flow, labels or braces); each run of 2-6 statements gets its orderings (all of them
up to 5 statements, else every rotation and adjacent swap), runs are improved one after another, and every candidate
goes through scripts/matching/try.py (the score with the link check) on --jobs threads, within --budget compiles. Prints
`best N` and, with --write, saves the best source over the input when it beats the input's score. Exit 0 at score 0.
"""
import argparse
import concurrent.futures
import itertools
import os
import re
import subprocess
import sys
import tempfile

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
CONTROL = re.compile(r'^\s*(return|if|else|for|while|do|switch|case|default|break|continue|goto|asm|__asm__)\b')
SIMPLE = re.compile(r'^(\s+)[^\s{}#/][^{}]*;\s*(//.*)?$')


def runs(lines):
    """[(start, end)] of runs of 2+ consecutive simple statements at one indentation."""
    found, start = [], None
    for index in range(len(lines) + 1):
        line = lines[index] if index < len(lines) else ''
        simple = bool(SIMPLE.match(line)) and not CONTROL.match(line) and line.count('(') == line.count(')')
        same = start is not None and simple and SIMPLE.match(lines[start]).group(1) == SIMPLE.match(line).group(1)
        if start is not None and not same:
            if index - start >= 2:
                found.append((start, index))
            start = None
        if start is None and simple:
            start = index
    return found


def orders(count):
    if count <= 5:
        return list(itertools.permutations(range(count)))[1:]
    base = list(range(count))
    variants = []
    for shift in range(1, count):
        variants.append(tuple(base[shift:] + base[:shift]))
    for position in range(count - 1):
        swapped = base[:]
        swapped[position], swapped[position + 1] = swapped[position + 1], swapped[position]
        variants.append(tuple(swapped))
    return variants


def judge(address, text, lang):
    """The score of a source, in process when scorer.py can run (the repository's .venv python), else through try.py."""
    scorer = in_process_scorer()
    if scorer:
        return scorer.judge(address, text, lang)
    return judge_with_try(address, text, lang)


_scorer = []


def in_process_scorer():
    if not _scorer:
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import scorer
        _scorer.append(scorer if scorer.compare else None)
    return _scorer[0]


def judge_with_try(address, text, lang):
    with tempfile.NamedTemporaryFile('w', suffix='.cpp' if lang == 'c++' else '.c', delete=False, dir=os.path.join(LAB, 'work', 'matching')) as handle:
        handle.write(text)
        path = handle.name
    try:
        result = subprocess.run(['python3', os.path.join(LAB, 'scripts', 'matching', 'try.py'), address, path, '--quiet', '--lang', lang],
                                capture_output=True, text=True, cwd=LAB)
    finally:
        os.remove(path)
    first = (result.stdout.strip().splitlines() or [''])[0]
    return int(first.split()[1]) if first.startswith('score ') else None


def permute(address, text, budget=200, jobs=8, lang='c++', log=None):
    """(best score, best source, compiles used)."""
    best_score = judge(address, text, lang)
    best_text, used = text, 1
    if best_score in (None, 0):
        return best_score, best_text, used
    improved = True
    while improved and used < budget and best_score:
        improved = False
        lines = best_text.split('\n')
        for start, end in sorted(runs(lines), key=lambda span: span[1] - span[0]):
            count = min(end - start, 6)
            end = start + count
            candidates = []
            for order in orders(count):
                block = [lines[start + index] for index in order]
                candidates.append('\n'.join(lines[:start] + block + lines[end:]))
            candidates = candidates[:max(0, budget - used)]
            if not candidates:
                break
            with concurrent.futures.ThreadPoolExecutor(jobs) as pool:
                scores = list(pool.map(lambda candidate: judge(address, candidate, lang), candidates))
            used += len(candidates)
            ranked = [(score, candidate) for score, candidate in zip(scores, candidates) if score is not None]
            if ranked:
                score, candidate = min(ranked, key=lambda pair: pair[0])
                if score < best_score:
                    best_score, best_text, improved = score, candidate, True
                    if log:
                        log(f'reordered lines {start + 1}-{end}: score {score}')
                    break  # line numbers changed: rescan the runs
            if best_score == 0 or used >= budget:
                break
    return best_score, best_text, used


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('address')
    parser.add_argument('source')
    parser.add_argument('--budget', type=int, default=200)
    parser.add_argument('--jobs', type=int, default=8)
    parser.add_argument('--write', action='store_true')
    arguments = parser.parse_args()
    lang = 'c' if arguments.source.endswith('.c') else 'c++'
    original = open(arguments.source, encoding='utf-8').read()
    start = judge(arguments.address, original, lang)
    score, text, used = permute(arguments.address, original, arguments.budget, arguments.jobs, lang, log=print)
    print(f'best {score} (was {start}, {used} compiles)')
    if arguments.write and score is not None and (start is None or score < start):
        open(arguments.source, 'w', encoding='utf-8').write(text)
        print(f'wrote {arguments.source}')
    return 0 if score == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
