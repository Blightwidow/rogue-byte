#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""mutate.py <address> <source.cpp> [--budget N] [--jobs N] [--write] | mutate.py --batch [--max-score N] [--budget N] - decomp-permuter's idea for near misses.

  python3 scripts/matching/mutate.py 0x116D70 data/matching/src/fn/116D70.cpp --write      (from the repository root)
  python3 scripts/matching/mutate.py --batch --max-score 10 --budget 300                   (every `tried` function at or under that score)

permute.py only reorders statements. gcc 2.95 also ties on register allocation and instruction choice with how an expression is
written, so this tries small source rewrites that mean the same thing: swapped operands of + * & | ^, flipped comparisons (a < b -> b > a),
`x == 0` against `!x`, `x++` against `++x`, `x += y` against `x = x + y`, a declaration split from or merged with its assignment, int
against unsigned for a local, the order of declarations and of independent statements, and the arms of an if/else swapped under a negated
test. It climbs: each generation judges a few mutated copies of the current source (scripts/matching/try.py), keeps the best (an equal
score is accepted now and then, to cross plateaus) and stops at score 0 or when the budget of compiles is spent. Lines with inline asm,
declarations of types and the function header are never touched. --write saves the best source over the input when it beats it; --batch
does that for every unmatched function with a source in data/matching/src/fn, lowest score first (re-judge them afterwards with
scripts/matching/record_round.py)."""
import argparse
import concurrent.futures
import csv
import hashlib
import os
import random
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import permute  # noqa: E402

LAB = permute.LAB
SKIP = re.compile(r'^\s*(#|struct\b|typedef\b|extern\b|union\b|class\b|enum\b|template\b)|\basm\b|__asm__')
NEGATED = {'<': '>=', '>': '<=', '<=': '>', '>=': '<'}
FLIPPED = {'<': '>', '>': '<', '<=': '>=', '>=': '<='}
TOKEN = r'[A-Za-z_][A-Za-z_0-9]*(?:->[A-Za-z_0-9]+|\.[A-Za-z_0-9]+|\[[A-Za-z_0-9]+\])*|0x[0-9A-Fa-f]+|\d+'


def body_lines(lines):
    """Indices of the lines inside a function: indented and not a declaration of a type or inline asm."""
    return [index for index, line in enumerate(lines) if line.startswith((' ', '\t')) and not SKIP.search(line)]


def replace_once(lines, index, pattern, builder, rng):
    matches = list(re.finditer(pattern, lines[index]))
    if not matches:
        return None
    match = rng.choice(matches)
    return lines[:index] + [lines[index][:match.start()] + builder(match) + lines[index][match.end():]] + lines[index + 1:]


def commute(lines, index, rng):
    return replace_once(lines, index, rf'({TOKEN}) ([+*&|^]) ({TOKEN})', lambda m: f'{m.group(3)} {m.group(2)} {m.group(1)}', rng)


def flip_comparison(lines, index, rng):
    if rng.random() < 0.5:
        return replace_once(lines, index, rf'({TOKEN}) (<=|>=|<|>) ({TOKEN})', lambda m: f'{m.group(3)} {FLIPPED[m.group(2)]} {m.group(1)}', rng)
    return replace_once(lines, index, rf'\b(if|while) \(({TOKEN}) (<=|>=|<|>) ({TOKEN})\)', lambda m: f'{m.group(1)} (!({m.group(2)} {NEGATED[m.group(3)]} {m.group(4)}))', rng)


def zero_test(lines, index, rng):
    options = [(rf'\bif \(({TOKEN}) == 0\)', lambda m: f'if (!{m.group(1)})'), (rf'\bif \(!({TOKEN})\)', lambda m: f'if ({m.group(1)} == 0)'),
               (rf'\bif \(({TOKEN}) != 0\)', lambda m: f'if ({m.group(1)})'), (rf'\bif \(({TOKEN})\)', lambda m: f'if ({m.group(1)} != 0)')]
    pattern, builder = rng.choice(options)
    return replace_once(lines, index, pattern, builder, rng)


def increment(lines, index, rng):
    options = [(rf'\b({TOKEN})\+\+;', lambda m: f'++{m.group(1)};'), (rf'\+\+({TOKEN});', lambda m: f'{m.group(1)}++;'),
               (rf'\b({TOKEN}) \+= ({TOKEN});', lambda m: f'{m.group(1)} = {m.group(1)} + {m.group(2)};'),
               (rf'\b({TOKEN}) = \1 \+ ({TOKEN});', lambda m: f'{m.group(1)} += {m.group(2)};'),
               (rf'\b({TOKEN}) \+= 1;', lambda m: f'{m.group(1)}++;')]
    pattern, builder = rng.choice(options)
    return replace_once(lines, index, pattern, builder, rng)


def split_declaration(lines, index, rng):
    match = re.match(r'^(\s+)((?:unsigned |signed |const )*[A-Za-z_][A-Za-z_0-9]*\s*\**)\s*([A-Za-z_][A-Za-z_0-9]*) = (.+);\s*$', lines[index])
    if match and not match.group(2).startswith(('return', 'else', 'goto')):
        return lines[:index] + [f'{match.group(1)}{match.group(2)} {match.group(3)};', f'{match.group(1)}{match.group(3)} = {match.group(4)};'] + lines[index + 1:]
    return None


def merge_declaration(lines, index, rng):
    if index + 1 >= len(lines):
        return None
    declaration = re.match(r'^(\s+)((?:unsigned |signed |const )*[A-Za-z_][A-Za-z_0-9]*\s*\**)\s*([A-Za-z_][A-Za-z_0-9]*);\s*$', lines[index])
    assignment = re.match(rf'^\s+{re.escape(declaration.group(3))} = (.+);\s*$', lines[index + 1]) if declaration else None
    if assignment and not declaration.group(2).startswith(('return', 'else', 'goto')):
        return lines[:index] + [f'{declaration.group(1)}{declaration.group(2)} {declaration.group(3)} = {assignment.group(1)};'] + lines[index + 2:]
    return None


def toggle_type(lines, index, rng):
    match = re.match(r'^(\s+)(unsigned int|unsigned|int|short|unsigned short|char|unsigned char)\s+([A-Za-z_][A-Za-z_0-9]*)\b(.*)$', lines[index])
    if not match:
        return None
    kind = match.group(2)
    swaps = {'int': ['unsigned int'], 'unsigned int': ['int'], 'unsigned': ['int'], 'short': ['unsigned short', 'int'], 'unsigned short': ['short', 'unsigned int'],
             'char': ['unsigned char'], 'unsigned char': ['char']}
    return lines[:index] + [f'{match.group(1)}{rng.choice(swaps[kind])} {match.group(3)}{match.group(4)}'] + lines[index + 1:]


def swap_adjacent(lines, index, rng):
    """Swaps two adjacent simple lines (declarations or independent statements) at one indentation."""
    if index + 1 >= len(lines):
        return None
    first, second = lines[index], lines[index + 1]
    if not (permute.SIMPLE.match(first) and permute.SIMPLE.match(second)) or permute.CONTROL.match(first) or permute.CONTROL.match(second):
        return None
    if permute.SIMPLE.match(first).group(1) != permute.SIMPLE.match(second).group(1) or SKIP.search(second):
        return None
    return lines[:index] + [second, first] + lines[index + 2:]


def block_end(lines, start):
    """Index of the line holding the `}` that closes the `{` ending lines[start], or None."""
    depth = 0
    for index in range(start, len(lines)):
        depth += lines[index].count('{') - lines[index].count('}')
        if depth == 0:
            return index
    return None


def swap_arms(lines, index, rng):
    """if (c) { A } else { B }  ->  if (!(c)) { B } else { A }  for braced arms."""
    match = re.match(r'^(\s*)if \((.+)\) \{\s*$', lines[index])
    if not match:
        return None
    first_end = block_end(lines, index)
    if first_end is None or not re.match(r'^\s*\} else \{\s*$', lines[first_end]):
        return None
    second_end = block_end(lines, first_end)
    if second_end is None or not re.match(r'^\s*\}\s*$', lines[second_end]):
        return None
    indent, condition = match.group(1), match.group(2)
    condition = condition[2:-1] if condition.startswith('!(') and condition.endswith(')') else f'!({condition})'
    return lines[:index] + [f'{indent}if ({condition}) {{'] + lines[first_end + 1:second_end] + [f'{indent}}} else {{'] + lines[index + 1:first_end] + lines[second_end:]


MUTATIONS = [commute, commute, flip_comparison, zero_test, increment, split_declaration, merge_declaration, toggle_type, swap_adjacent, swap_adjacent, swap_arms]


def mutate(text, rng, count=1):
    lines = text.split('\n')
    for _ in range(count):
        for _attempt in range(30):
            candidates = body_lines(lines)
            if not candidates:
                return None
            changed = rng.choice(MUTATIONS)(lines, rng.choice(candidates), rng)
            if changed and changed != lines:
                lines = changed
                break
        else:
            return None
    return '\n'.join(lines)


def climb(address, text, budget, jobs, lang, seed=0, log=None):
    """(best score, best source, compiles used)."""
    rng = random.Random(seed)
    current_score = permute.judge(address, text, lang)
    current, best_score, best, used = text, current_score, text, 1
    if current_score in (None, 0):
        return current_score, current, used
    seen = {hashlib.sha1(text.encode()).hexdigest()}
    stale = empty = 0
    with concurrent.futures.ThreadPoolExecutor(jobs) as pool:
        while used < budget and best_score:
            batch = []
            for _ in range(jobs * 4):
                candidate = mutate(current, rng, 1 if rng.random() < 0.7 - 0.1 * empty else 2 + empty // 3)
                if candidate:
                    digest = hashlib.sha1(candidate.encode()).hexdigest()
                    if digest not in seen:
                        seen.add(digest)
                        batch.append(candidate)
            if not batch:
                empty += 1
                if empty > 12:
                    break
                continue
            empty = 0
            batch = batch[:jobs * 2]
            scores = list(pool.map(lambda candidate: permute.judge(address, candidate, lang), batch[:max(1, budget - used)]))
            used += len(scores)
            ranked = sorted((score, index) for index, score in enumerate(scores) if score is not None)
            if not ranked:
                continue
            score, index = ranked[0]
            if score < current_score or (score == current_score and rng.random() < 0.5):
                current, current_score = batch[index], score
            if score < best_score:
                best_score, best, stale = score, batch[index], 0
                if log:
                    log(f'score {score} after {used} compiles')
            else:
                stale += 1
            if stale >= 6:  # restart from the best with a bigger step
                current, current_score, stale = best, best_score, 0
    return best_score, best, used


def batch(arguments):
    rows = list(csv.DictReader(open(os.path.join(LAB, 'data', 'matching', 'functions.tsv'), encoding='utf-8'), delimiter='\t'))
    pool = []
    for row in rows:
        path = os.path.join(LAB, 'data', 'matching', 'src', 'fn', f'{int(row["address"], 16):06X}.cpp')
        if row['status'] == 'tried' and row['best'] != '' and arguments.min_score <= int(row['best']) <= arguments.max_score and os.path.exists(path):
            pool.append((int(row['best']), row['address'], path))
    pool.sort()
    matched = improved = 0
    for position, (best, address, path) in enumerate(pool, 1):
        original = open(path, encoding='utf-8').read()
        score, text, used = climb(address, original, arguments.budget, arguments.jobs, 'c++', seed=int(address, 16))
        if score is not None and score < best:
            open(path, 'w', encoding='utf-8').write(text)
            improved += 1
            matched += score == 0
        print(f'[{position}/{len(pool)}] {address}: {best} -> {score} ({used} compiles){"  MATCH" if score == 0 else ""}', flush=True)
    print(f'{len(pool)} functions: {improved} improved, {matched} reach 0')


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('address', nargs='?')
    parser.add_argument('source', nargs='?')
    parser.add_argument('--budget', type=int, default=300)
    parser.add_argument('--jobs', type=int, default=12)
    parser.add_argument('--seed', type=int, default=0)
    parser.add_argument('--write', action='store_true')
    parser.add_argument('--batch', action='store_true')
    parser.add_argument('--min-score', type=int, default=1)
    parser.add_argument('--max-score', type=int, default=10)
    arguments = parser.parse_args()
    if arguments.batch:
        batch(arguments)
        return 0
    lang = 'c' if arguments.source.endswith('.c') else 'c++'
    original = open(arguments.source, encoding='utf-8').read()
    start = permute.judge(arguments.address, original, lang)
    score, text, used = climb(arguments.address, original, arguments.budget, arguments.jobs, lang, arguments.seed, log=print)
    print(f'best {score} (was {start}, {used} compiles)')
    if arguments.write and score is not None and (start is None or score < start):
        open(arguments.source, 'w', encoding='utf-8').write(text)
        print(f'wrote {arguments.source}')
    return 0 if score == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
