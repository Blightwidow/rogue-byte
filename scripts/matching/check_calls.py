#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""check_calls.py [--out FILE] : flags the drafts in nonmatching/ whose declarations disagree with the matched code in src/.

Two checks, each a lead for a worker, not a verdict:
- arity: a callee that src/ declares or defines with one agreed number of arguments (the agreed count needs three times the
  votes of all others) is declared with another count in the draft;
- global type: a global that src/ declares `extern` with a struct type (SW, SAVE ...) is declared as a byte or int array or an int
  in the draft.

A definition in C++ counts five votes; a C definition counts one, like a declaration: a matched C function that never reads an
argument compiles the same without it, and m2c's signatures often leave it out.

A wrong prototype or a global read as raw bytes was the real cause behind most matches of 2026-11-12 (an extra argument costs
instructions and moves registers; a char-array global changes how its address is built). Confirm each flag in the diff: the
argument registers retail sets before the `jal`. In a C draft, `f()` declares unspecified arguments and is not counted; a struct
returned by value counts one argument (its hidden address). A matched callee that ignores an argument can be declared without it
and still match, so its own definition can outvote the truth: the registers decide.

Writes one row per flagged draft (address, name, size, score, flags; largest first) to FILE (default build/check_calls.tsv)
and prints a summary line."""
import argparse
import collections
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
PROTOTYPE = re.compile(r'(?:^|[;{}\n])\s*(?:extern\s+"C"\s+)?(?:static\s+|inline\s+|virtual\s+)*'
                       r'([A-Za-z_][\w\s\*&:]*?[\s\*&])([A-Za-z_]\w*)\s*\(([^;{}()]*(?:\([^()]*\)[^;{}()]*)*)\)\s*(?:const\s*)?([;{])')
GLOBAL = re.compile(r'(?:^|\n)\s*extern\s+(?:"C"\s+)?(?:const\s+)?(?:struct\s+)?([A-Za-z_]\w*)\s*(\*?)\s*([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*;')
KEYWORDS = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'else', 'do', 'case'}
SCALARS = {'char', 'u8', 's8', 'int', 's32', 'u32', 'unsigned', 'short', 's16', 'u16', 'float', 'long', 'QW', 'u128', 's128',
           'void', 'f32', 'f64', 'double', 's64', 'u64', 'M2C_UNK'}
RAW = {'char', 'u8', 's8', 'int', 's32', 'u32'}


def strip_comments(text):
    text = re.sub(r'/\*.*?\*/', ' ', text, flags=re.S)
    return re.sub(r'//[^\n]*', ' ', text)


def arity(parameters, c_file=False):
    """The number of parameters in a declaration's list, or None when it is unknown (`...`, or `()` in C)."""
    parameters = parameters.strip()
    if parameters == '' and c_file:
        return None
    if parameters in ('', 'void'):
        return 0
    if '...' in parameters:
        return None
    depth = 0
    count = 1
    for character in parameters:
        if character in '(<':
            depth += 1
        elif character in ')>':
            depth -= 1
        elif character == ',' and depth == 0:
            count += 1
    return count


AGGREGATE = re.compile(r'\b(?:struct|class|union)\s+([A-Za-z_]\w*)\s*(?::[^{;]*)?\{')


def shared_aggregates():
    names = set()
    folder = os.path.join(ROOT, 'include')
    for name in os.listdir(folder) if os.path.isdir(folder) else ():
        if name.endswith('.h'):
            names.update(AGGREGATE.findall(strip_comments(open(os.path.join(folder, name), errors='ignore').read())))
    return names


SHARED_AGGREGATES = shared_aggregates()


def scan(text, c_file=False):
    """(functions, globals) declared or defined in one source: [(name, arity, is_definition)], [(name, type, pointer, array)]."""
    text = strip_comments(text)
    aggregates = SHARED_AGGREGATES | set(AGGREGATE.findall(text))
    functions = []
    for match in PROTOTYPE.finditer(text):
        returns, name, parameters, end = match.group(1).strip(), match.group(2), match.group(3), match.group(4)
        if name in KEYWORDS or returns.split()[-1:] in (['return'], ['else'], ['new'], ['delete']):
            continue
        if '::' in returns or name.startswith('operator'):
            continue
        count = arity(parameters, c_file)
        if count is not None:
            words = returns.split()
            if words and '*' not in returns and '&' not in returns and words[-1] in aggregates:
                count += 1  # a struct returned by value: g++ passes the result's address first (CRef RefEval(...) = 3 registers)
            functions.append((name, count, end == '{'))
    globals_ = [(match.group(3), match.group(1), bool(match.group(2)), bool(match.group(4))) for match in GLOBAL.finditer(text)]
    return functions, globals_


def sources(folder):
    for base, _, files in os.walk(folder):
        for name in sorted(files):
            if name.endswith(('.c', '.cpp')):
                yield os.path.join(base, name)


def learn(texts):
    """What matched code agrees on, from (text, is_c) pairs: callee -> arity votes, global -> struct type votes."""
    arities = collections.defaultdict(collections.Counter)
    types = collections.defaultdict(collections.Counter)
    for text, c_file in texts:
        functions, globals_ = scan(text, c_file)
        for name, count, definition in functions:
            arities[name][count] += 5 if definition and not c_file else 1  # a C definition is often m2c's guess (fun_00153638.c drops an argument it never reads)
        for name, type_name, pointer, array in globals_:
            if not pointer and not array and type_name not in SCALARS:
                types[name][type_name] += 1
    return arities, types


def flags(text, c_file, function, arities, types):
    """The disagreements of one draft (`function` is its own name, never checked against itself)."""
    functions, globals_ = scan(text, c_file)
    found = []
    seen = set()
    for name, count, definition in functions:
        if definition or name == function or name in seen or name not in arities:
            continue
        votes = arities[name]
        agreed, weight = votes.most_common(1)[0]
        if agreed != count and weight >= 2 and weight >= 3 * (sum(votes.values()) - weight):
            found.append(f'{name}: {count} args, matched code {agreed}')
            seen.add(name)
    for name, type_name, pointer, array in globals_:
        if name in types and not pointer and (array or type_name in RAW):
            found.append(f'global {name}: declared {type_name}{"[]" if array else ""}, matched code {types[name].most_common(1)[0][0]}')
    return found


def read_flags(path=None):
    """{address: flags} from the last run's table (build/check_calls.tsv), or {} when it was never written."""
    path = path or os.path.join(ROOT, 'build', 'check_calls.tsv')
    if not os.path.exists(path):
        return {}
    rows = [line.rstrip('\n').split('\t') for line in open(path).read().splitlines()[1:]]
    return {int(row[0], 16): row[4] for row in rows if len(row) > 4}


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('--out', default=os.path.join(ROOT, 'build', 'check_calls.tsv'))
    arguments = parser.parse_args()
    arities, types = learn((open(path, errors='ignore').read(), path.endswith('.c')) for path in sources(os.path.join(ROOT, 'src')))
    rows = []
    manifest = os.path.join(ROOT, 'nonmatching', 'MANIFEST.tsv')
    for line in open(manifest).read().splitlines()[1:]:
        address, name, size, file, score = line.split('\t')[:5]
        path = os.path.join(ROOT, 'nonmatching', file)
        found = flags(open(path, errors='ignore').read(), path.endswith('.c'), name, arities, types)
        if found:
            rows.append((int(size), int(score), address, name, '; '.join(found)))
    rows.sort(reverse=True)
    os.makedirs(os.path.dirname(arguments.out), exist_ok=True)
    with open(arguments.out, 'w') as handle:
        handle.write('address\tname\tsize\tscore\tflags\n')
        for size, score, address, name, found in rows:
            handle.write(f'{address}\t{name}\t{size}\t{score}\t{found}\n')
    print(f'check_calls: {len(rows)} drafts with a declaration that disagrees with src/ ({sum(row[0] for row in rows)} bytes) -> '
          f'{os.path.relpath(arguments.out, ROOT)}')


if __name__ == '__main__':
    main()
