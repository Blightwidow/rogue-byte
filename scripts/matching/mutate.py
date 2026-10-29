#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""mutate.py <address> <source.cpp> [--budget N] [--jobs N] [--write] | mutate.py --batch [--max-score N] [--budget N] - decomp-permuter's idea for near misses.

  python3 scripts/matching/mutate.py 0x116D70 data/matching/src/fn/116D70.cpp --write      (from the repository root)
  python3 scripts/matching/mutate.py --batch --max-score 10 --budget 300                   (every `tried` function at or under that score)

permute.py only reorders statements. gcc 2.95 also ties on register allocation and instruction choice with how an expression is
written, so this tries small source rewrites that mean the same thing: swapped operands of + * & | ^, flipped comparisons (a < b -> b > a),
`x == 0` against `!x`, `x++` against `++x`, `x += y` against `x = x + y`, a declaration split from or merged with its assignment, int
against unsigned for a local, the order of declarations and of independent statements, and the arms of an if/else swapped under a negated
test, one exit (`result = X; goto done;` for every return) and the element type of pointer casts. It climbs: each generation judges a few mutated copies of the current source (scripts/matching/try.py), keeps the best (an equal
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


def function_span(lines, index):
    """(header index, open brace index, close brace index) of the function holding lines[index], or None."""
    header = index
    while header >= 0 and not (lines[header] and not lines[header][0].isspace() and '(' in lines[header] and not lines[header].rstrip().endswith(';')
                               and not lines[header].startswith(('#', 'struct', 'typedef', 'extern "C" {'))):
        header -= 1
    if header < 0:
        return None
    opening = header
    while opening < len(lines) and '{' not in lines[opening]:
        opening += 1
    closing = block_end(lines, opening) if opening < len(lines) else None
    return (header, opening, closing) if closing is not None and opening <= index <= closing else None


RETURN = re.compile(r'\breturn\b([^;]*);')


def single_exit(lines, index, rng):
    """Every `return X;` of the function becomes `{ result = X; goto done; }` and one `done: return result;` ends it: gcc 2.95 cross-jumps
    two equal returns only some of the time, and retail often has one epilogue where a straight transcription has two."""
    if not RETURN.search(lines[index]):
        return None
    span = function_span(lines, index)
    if not span:
        return None
    header, opening, closing = span
    body = range(opening + 1, closing)
    returns = [position for position in body if RETURN.search(lines[position]) and not SKIP.search(lines[position])]
    if len(returns) < 2 or any(re.search(r'\bdone\b', lines[position]) for position in range(header, closing + 1)):
        return None
    name = re.search(r'(~?[A-Za-z_][A-Za-z_0-9:]*)\s*\(', lines[header])
    kind = lines[header][:name.start()].replace('extern "C"', '').replace('static', '').replace('inline', '').strip() if name else None
    if kind is None or not kind:
        return None
    result = list(lines)
    chosen = set(returns) if rng.random() < 0.6 else set(rng.sample(returns, rng.randint(2, len(returns))))
    for position in chosen:
        if kind == 'void':
            result[position] = RETURN.sub('{ goto done; }', lines[position])
        else:
            result[position] = RETURN.sub(lambda match: '{ result = ' + (match.group(1).strip() or '0') + '; goto done; }', lines[position])
    tail = ['done:', '    return;'] if kind == 'void' else ['done:', '    return result;']
    declaration = [] if kind == 'void' else [f'    {kind} result;']
    return result[:opening + 1] + declaration + result[opening + 1:closing] + tail + result[closing:]


def toggle_cast(lines, index, rng):
    """A pointer cast of another element type: int * -> unsigned * -> long * -> short *, so a load or store is lw, ld or lh."""
    kinds = ['int', 'unsigned int', 'unsigned', 'long', 'unsigned long', 'short', 'unsigned short', 'char', 'unsigned char']
    matches = list(re.finditer(r'\(((?:unsigned )?(?:int|long|short|char)|unsigned) \*\)', lines[index]))
    if not matches:
        return None
    match = rng.choice(matches)
    replacement = rng.choice([kind for kind in kinds if kind != match.group(1)])
    return lines[:index] + [lines[index][:match.start()] + f'({replacement} *)' + lines[index][match.end():]] + lines[index + 1:]


EXTERN = re.compile(r'^(extern "C" )(void|int)(\s+)([A-Za-z_][A-Za-z_0-9]*)(\s*\(.*\);\s*)$')


def flip_callee_return(lines, index, rng):
    """A callee declared `void` becomes `int` or back: a discarded result still steers register allocation and scheduling around the call
    (a `lui $3` right after a call whose result is ignored means the callee returns a value). `int` to `void` only when every call of the
    function is a statement of its own."""
    declarations = [position for position, line in enumerate(lines) if EXTERN.match(line)]
    if not declarations:
        return None
    position = rng.choice(declarations)
    match = EXTERN.match(lines[position])
    name, kind = match.group(4), match.group(2)
    statements = sum(1 for line in lines if re.match(rf'^\s+{re.escape(name)}\(.*\);\s*$', line))
    uses = sum(len(re.findall(rf'\b{re.escape(name)}\(', line)) for index_, line in enumerate(lines) if index_ != position)
    if kind == 'int' and statements != uses:
        return None
    flipped = 'int' if kind == 'void' else 'void'
    return lines[:position] + [f'{match.group(1)}{flipped}{match.group(3)}{name}{match.group(5)}'] + lines[position + 1:]


def while_to_goto(lines, index, rng):
    """while (c) { body }  ->  goto test; top: body test: if (c) goto top;  the loop the compiler does not strength-reduce."""
    match = re.match(r'^(\s*)while \((.+)\) \{\s*$', lines[index])
    if not match:
        return None
    end = block_end(lines, index)
    if end is None or any(re.search(r'\b(break|continue)\b', line) for line in lines[index + 1:end]):
        return None
    indent, condition = match.group(1), match.group(2)
    top, test = f'loop_{index}', f'test_{index}'
    if any(top in line for line in lines):
        return None
    return (lines[:index] + [f'{indent}goto {test};', f'{top}:'] + lines[index + 1:end] + [f'{test}:', f'{indent}if ({condition}) goto {top};'] + lines[end + 1:])


def tail_return(lines, index, rng):
    """The last statement of a function, a call, gains or loses its `return`: for a void function `f(x); return;` or `return f(x);`
    makes the compiler end with a jump to the callee (a tail call) or with a call and a return."""
    span = function_span(lines, index)
    if not span:
        return None
    header, opening, closing = span
    last = closing - 1
    while last > opening and not lines[last].strip():
        last -= 1
    if last <= opening:
        return None
    call = re.match(r'^(\s+)([A-Za-z_][A-Za-z_0-9:>.-]*\(.*\));\s*$', lines[last])
    if call and not re.match(r'^\s*(return|goto)\b', lines[last]):
        if rng.random() < 0.5:
            return lines[:last] + [f'{call.group(1)}return {call.group(2)};'] + lines[last + 1:]
        return lines[:last + 1] + [f'{call.group(1)}return;'] + lines[last + 1:]
    returned = re.match(r'^(\s+)return (.+\(.*\));\s*$', lines[last])
    if returned:
        return lines[:last] + [f'{returned.group(1)}{returned.group(2)};'] + lines[last + 1:]
    if re.match(r'^\s+return;\s*$', lines[last]) and last - 1 > opening:
        return lines[:last] + lines[last + 1:]
    return None


def volatile_slot(lines, index, rng):
    """A local pointer whose address is handed to a call (`f(..., &p)`) is re-read from the stack before every use in retail; reading it
    through a volatile pointer does that: `p[1] = x` becomes `(*(T *volatile *)&p)[1] = x`, and again for the one use that undoes it."""
    declared = {}
    for line in lines:
        match = re.match(r'^\s+((?:const |unsigned |struct )*[A-Za-z_][A-Za-z_0-9]*)\s*(\*+)\s*([A-Za-z_][A-Za-z_0-9]*)\s*(?:=[^;]*)?;\s*$', line)
        if match and not match.group(1).startswith('return'):
            declared[match.group(3)] = match.group(1) + ' ' + match.group(2)
    escaped = [name for name in declared if any(re.search(rf'&{name}\b', line) for line in lines)]
    if not escaped:
        return None
    name = rng.choice(escaped)
    volatile = f'(*({declared[name]} volatile *)&{name})'
    plain = re.compile(rf'(?<![\w&.>]){name}\[')
    cast = re.compile(rf'\(\(([A-Za-z_][A-Za-z_0-9 ]*\s*\*+)\)\s*{name}\)\[')
    undo = re.compile(rf'\(\*\([^()]*volatile \*\)&{name}\)\[')
    line = lines[index]
    if undo.search(line):
        changed = undo.sub(f'{name}[', line, count=1)
    elif cast.search(line):
        changed = cast.sub(lambda match: f'(({match.group(1)})*(void *volatile *)&{name})[', line, count=1)
    elif plain.search(line):
        changed = plain.sub(volatile + '[', line, count=1)
    else:
        return None
    return lines[:index] + [changed] + lines[index + 1:]


LEGACY_MUTATIONS = [single_exit, single_exit, toggle_cast, toggle_cast, commute, commute, flip_comparison, zero_test, increment, split_declaration, merge_declaration, toggle_type, swap_adjacent, swap_adjacent, swap_arms]
MUTATIONS = LEGACY_MUTATIONS + [flip_callee_return, flip_callee_return, while_to_goto, tail_return, tail_return, volatile_slot, volatile_slot]


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
    if arguments.classes:  # only functions of these kinds of difference (scripts/matching/classify_diffs.py, work/matching/classes.tsv), plus any with two returns
        wanted = set(arguments.classes.split(','))
        classes = {int(row['address'], 16): row['class'] for row in csv.DictReader(open(os.path.join(LAB, 'work', 'matching', 'classes.tsv'), encoding='utf-8'), delimiter='\t')}
        pool = [entry for entry in pool if classes.get(int(entry[1], 16)) in wanted or len(re.findall(r'\breturn\b', open(entry[2], encoding='utf-8').read())) >= 2]
    pool.sort()
    matched = improved = 0
    for position, (best, address, path) in enumerate(pool, 1):
        original = open(path, encoding='utf-8').read()
        score, text, used = climb(address, original, arguments.budget, arguments.jobs, 'c++', seed=int(address, 16) + arguments.seed)
        if score is not None and score < best:
            if not arguments.no_write:
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
    parser.add_argument('--mutations', choices=('all', 'legacy'), default='all', help='legacy: the rewrites before flip_callee_return, while_to_goto and tail_return')
    parser.add_argument('--no-write', action='store_true', help='--batch: report only, leave the sources alone')
    parser.add_argument('--classes', help='comma list of classify_diffs.py classes to restrict --batch to')
    arguments = parser.parse_args()
    if arguments.mutations == 'legacy':
        global MUTATIONS
        MUTATIONS = LEGACY_MUTATIONS
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
