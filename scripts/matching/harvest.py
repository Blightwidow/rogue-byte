#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""harvest.py - which unsourced functions a plain decompiler draft already matches.

  .venv/bin/python scripts/matching/harvest.py [--max-size N] [--limit N] [--write] [--m2c PATH]

Runs m2c (https://github.com/matt-kempster/m2c, GPL-3.0; clone it, `--m2c` or work/matching/tools/m2c/m2c.py) on the split assembly of
every function that has no source yet, makes the draft compile (m2c's own macro header, unknown types taken as int, the callee
declarations in an `extern "C"` block), judges it with scripts/matching/scorer.py, and tries a second variant whose callee return types
come from callee_sigs.py (`void` where the code says no result). A draft that scores 0 needs no editing: `--write` saves it as
data/matching/src/fn/<ADDRESS>.cpp, and scripts/matching/record_round.py then registers it. The others are kept in
work/matching/harvest/ with their scores, so `--near` lists the closest first (the drafts to edit by hand).

m2c cannot handle every R5900 instruction (unaligned loads, VU0 and multimedia instructions): such drafts are skipped and counted."""
import argparse
import concurrent.futures
import csv
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scorer  # noqa: E402

LAB = scorer.LAB
SPLIT = os.path.join(LAB, 'work', 'matching', 'split', 'asm', 'functions', 'SCUS_973')
M2C = os.path.join(LAB, 'work', 'matching', 'tools', 'm2c', 'm2c.py')
OUT = os.path.join(LAB, 'work', 'matching', 'harvest')
SOURCES = os.path.join(LAB, 'data', 'matching', 'src', 'fn')
SIGNATURES = os.path.join(LAB, 'work', 'matching', 'callee_sigs.tsv')
PRELUDE = '''typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
'''
REJECT = re.compile(r'M2C_ERROR|M2C_LWL|M2C_FIRST3BYTES|M2C_UNALIGNED|Decompilation failure|unknown instruction')
DECLARATION = re.compile(r'^(M2C_UNK|s32|void|f32|\w+)(\s+\**)(\w+)\((.*)\);\s*(/\*.*\*/)?\s*$')


def candidates(arguments):
    with open(scorer.REGISTRY, encoding='utf-8') as handle:
        rows = [row for row in csv.DictReader(handle, delimiter='\t') if row['status'] == 'todo' and arguments.min_size <= int(row['size']) <= arguments.max_size]
    rows.sort(key=lambda row: int(row['size']))
    return rows[:arguments.limit] if arguments.limit else rows


SCALARS = {'void', 'char', 'short', 'int', 'long', 'float', 'double', 'unsigned', 's8', 's16', 's32', 's64', 'u8', 'u16', 'u32', 'u64', 'f32', 'f64'}
SIGNATURE_KIND = {'void': 'void', 'unknown': 'void', 'int': 's32', 'int?': 's32', 'float': 'f32', 'float?': 'f32'}


def c_type(text):
    """A C type m2c's parser accepts for a type written in a source: scalars stay, every pointer is `void *`, the rest an int."""
    words = text.replace('const', ' ').replace('struct', ' ').split()
    if not words:
        return 's32'
    if '*' in text:
        return 'void *'
    if all(word in SCALARS for word in words):
        return ' '.join(words)
    return 's128' if 'QW' in words else 's32'


def source_signature(name, text):
    """(return type, [parameter types]) of the definition of `name` in a matched source, in C types, or None."""
    match = re.search(rf'^(?:extern "C"\s+)?([A-Za-z_][\w \*]*?)\s*\b{re.escape(name)}\s*\(([^)]*)\)\s*(?:\{{|$)', text, re.M)
    if not match:
        return None
    parameters = [] if match.group(2).strip() in ('', 'void') else [c_type(re.sub(r'\b\w+\s*(\[\d*\])?\s*$', '', part) if re.search(r'[\w\*]\s+\**\w+\s*(\[\d*\])?\s*$', part) else part) for part in match.group(2).split(',')]
    return c_type(match.group(1)), parameters


def build_context(path):
    """Writes a C file of prototypes for every function: the real signature from its matched source, else the one the code implies
    (callee_sigs.py: return kind and the number of integer parameters). m2c reads it with --context. Returns the number of prototypes."""
    with open(scorer.REGISTRY, encoding='utf-8') as handle:
        registry = list(csv.DictReader(handle, delimiter='\t'))
    inferred = {}
    if os.path.exists(SIGNATURES):
        with open(SIGNATURES, encoding='utf-8') as handle:
            inferred = {row['name']: row for row in csv.DictReader(handle, delimiter='\t')}
    lines = ['typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;', 'typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;', 'typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));']
    count = 0
    for row in registry:
        name = row['name']
        if not re.fullmatch(r'[A-Za-z_]\w*', name):
            continue
        signature = None
        if row['status'] == 'matched' and row['source']:
            source = os.path.join(LAB, row['source'])
            if os.path.exists(source):
                with open(source, encoding='utf-8') as handle:
                    signature = source_signature(name, handle.read())
        if signature is None and name in inferred:
            kind = SIGNATURE_KIND[inferred[name]['inferred']]
            signature = (kind, None)  # the parameter count read from the code is only a lower bound: leave the list open
        if signature:
            lines.append(f'{signature[0]} {name}({"" if signature[1] is None else ", ".join(signature[1]) or "void"});')
            count += 1
    with open(path, 'w', encoding='utf-8') as handle:
        handle.write('\n'.join(lines) + '\n')
    return count


def run_m2c(arguments, row):
    """The draft text for a function, from the cache or a fresh m2c run; None when m2c fails."""
    folder = 'm2c-context' if arguments.context else 'm2c-stack'
    os.makedirs(os.path.join(OUT, folder), exist_ok=True)
    cached = os.path.join(OUT, folder, f'{int(row["address"], 16):06X}.c')
    if os.path.exists(cached):
        with open(cached, encoding='utf-8') as handle:
            return handle.read()
    path = os.path.join(SPLIT, row['name'] + '.s')
    if not os.path.exists(path):
        return None
    command = [sys.executable, arguments.m2c, '-t', 'mipsee-gcc-c', '--valid-syntax', '--stack-structs'] + (['--context', arguments.context] if arguments.context else []) + [path]
    result = subprocess.run(command, capture_output=True, text=True, timeout=120)
    if result.returncode or not result.stdout.strip():
        return None
    with open(cached, 'w', encoding='utf-8') as handle:
        handle.write(result.stdout)
    return result.stdout


def build(draft, signatures=None):
    """C++ source for a draft: prelude, then everything in an extern "C" block. `signatures` (name -> 'void'|'int'|'float') retypes callees."""
    if REJECT.search(draft):
        return None
    lines = []
    for line in draft.split('\n'):
        if line.startswith('#include') or line.startswith('/* Warning'):
            continue
        match = DECLARATION.match(line)
        if signatures is not None and match and match.group(3) in signatures and line.rstrip().endswith(('*/', ');')) and not line.startswith(' '):
            line = f'{signatures[match.group(3)]}{match.group(2)}{match.group(3)}({match.group(4)});'
        lines.append(line)
    body = re.sub(r'\bvoid\s*\*', 's8 *', '\n'.join(lines))  # C++ forbids arithmetic on void *
    stack = re.search(r'struct _m2c_stack_(\w+) \{.*?\};\s*/\* size = (0x[0-9A-Fa-f]+) \*/', body, re.S)
    if stack and re.search(r'(?<![\w.>])sp(?!\w)', body):  # `sp` is the address of the function's stack area: a local buffer of that size
        body = re.sub(rf'(\b{re.escape(stack.group(1))}\([^)]*\)\s*\{{\n)', rf'\1    s8 sp[{stack.group(2)}] __attribute__((aligned(16)));\n', body, count=1)
    return PRELUDE + 'extern "C" {\n' + body + '\n}\n'


def read_signatures():
    if not os.path.exists(SIGNATURES):
        return {}
    kinds = {'void': 'void', 'unknown': 'void', 'int': 's32', 'int?': 's32', 'float': 'f32', 'float?': 'f32'}
    with open(SIGNATURES, encoding='utf-8') as handle:
        return {row['name']: kinds[row['inferred']] for row in csv.DictReader(handle, delimiter='\t')}


CAST_RULES = (
    (re.compile(r"assignment to `([^']+)' from `[^']+'"), 'assign'),
    (re.compile(r"passing `[^']+' (?:to|as) argument (\d+) of `([^']+)'"), 'argument'),
    (re.compile(r"argument passing to `[^']+' from `[^']+'"), None),
)


def split_arguments(text):
    """The top-level comma-separated pieces of an argument list."""
    pieces, depth, current = [], 0, ''
    for character in text:
        if character in '([':
            depth += 1
        elif character in ')]':
            depth -= 1
        if character == ',' and depth == 0:
            pieces.append(current)
            current = ''
        else:
            current += character
    return pieces + [current]


def parameter_types(signature):
    """The parameter types in a compiler message's `name(type, type)` text."""
    inner = signature[signature.index('(') + 1:signature.rindex(')')]
    return [part.strip() for part in split_arguments(inner)] if inner.strip() else []


def repair_once(text, message):
    """One edit that answers the first pointer or integer conversion error of a compile message, or None: the right side of an assignment or
    the argument the compiler names gets a cast to the type it expects."""
    error = re.search(r'^[^:]+:(\d+): (?!warning)(.*)$', message, re.M)
    if not error:
        return None
    number, reason = int(error.group(1)) - 1, error.group(2)
    lines = text.split('\n')
    if number >= len(lines):
        return None
    line = lines[number]
    assign = re.search(r"assignment to `([^']+)' from", reason)
    if assign and '=' in line:
        match = re.match(r'^(\s*[^=]*[^=!<>+\-*/&|^]=)\s*([^=].*?);\s*$', line)
        if match:
            lines[number] = f'{match.group(1)} ({assign.group(1)})({match.group(2)});'
            return '\n'.join(lines)
    argument = re.search(r"argument (\d+) of `([^']+)'", reason)
    if argument:
        index = int(argument.group(1)) - 1
        types = parameter_types(argument.group(2))
        name = argument.group(2).split('(')[0].split()[-1]
        call = re.search(rf'\b{re.escape(name)}\s*\(', line)
        if call and index < len(types):
            start, depth, end = call.end(), 1, call.end()
            while end < len(line) and depth:
                depth += (line[end] == '(') - (line[end] == ')')
                end += 1
            pieces = split_arguments(line[start:end - 1])
            if index < len(pieces):
                pieces[index] = f' ({types[index]})({pieces[index].strip()})' if index else f'({types[index]})({pieces[index].strip()})'
                lines[number] = line[:start] + ','.join(pieces) + line[end - 1:]
                return '\n'.join(lines)
    return None


def judge_with_repair(address, text, attempts=8):
    """(score, text): the draft judged, after up to `attempts` cast repairs when it does not compile."""
    import compile_unit
    for _ in range(attempts):
        score = scorer.judge(address, text)
        if score is not None:
            return score, text
        os.makedirs(scorer.BUILD, exist_ok=True)
        stem = os.path.join(scorer.BUILD, f'repair-{address:06X}-{os.getpid()}-{next(scorer._counter)}')
        with open(stem + '.cpp', 'w') as handle:
            handle.write(text)
        ok, message = compile_unit.compile_object('c++', stem + '.cpp', stem + '.o', assembler=compile_unit.assembler_for(address), include=scorer.INCLUDE, localize=False)
        for leftover in (stem + '.cpp', stem + '.o', stem + '.o.tmp', stem + '.o.s'):
            if os.path.exists(leftover):
                os.remove(leftover)
        if ok:
            return None, text
        edited = repair_once(text, message)
        if edited is None or edited == text:
            return None, text
        text = edited
    return scorer.judge(address, text), text


def harvest_one(arguments, signatures, row):
    address = int(row['address'], 16)
    draft = run_m2c(arguments, row)
    if draft is None:
        return address, 'no draft', None, None
    results = []
    for text in (build(draft), build(draft, signatures)):
        if text is None:
            return address, 'unsupported', None, None
        results.append(judge_with_repair(address, text) if arguments.repair else (scorer.judge(address, text), text))
    scored = [(score, text) for score, text in results if score is not None]
    if not scored:
        return address, 'does not compile', None, None
    score, text = min(scored, key=lambda item: item[0])
    return address, 'ok', score, text


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--m2c', default=M2C)
    parser.add_argument('--min-size', type=int, default=8)
    parser.add_argument('--max-size', type=int, default=4096)
    parser.add_argument('--limit', type=int, default=0)
    parser.add_argument('--jobs', type=int, default=12)
    parser.add_argument('--write', action='store_true', help='save drafts that score 0 as data/matching/src/fn/<ADDRESS>.cpp')
    parser.add_argument('--context', action='store_true', help='give m2c prototypes of every function (real signatures from matched sources, the rest inferred from the code)')
    parser.add_argument('--repair', action='store_true', help='when a draft does not compile, add the casts the compiler asks for (up to 8 edits)')
    parser.add_argument('--keep', type=int, default=-1, metavar='SCORE', help='also save drafts scoring at most SCORE as sources (for mutate.py, neighborhood.py)')
    parser.add_argument('--near', type=int, default=0, metavar='N', help='list the N closest drafts')
    arguments = parser.parse_args()
    if not scorer.compare:
        sys.exit('needs rabbitizer and pyelftools: run with .venv/bin/python')
    scorer.registry()
    signatures = read_signatures()
    if arguments.context:
        context = os.path.join(OUT, 'context.h')
        os.makedirs(OUT, exist_ok=True)
        print(f'{build_context(context)} prototypes in {context}')
        arguments.context = context
    rows = candidates(arguments)
    print(f'{len(rows)} functions without source, {arguments.min_size}-{arguments.max_size} bytes')
    outcomes = {}
    scores = []
    table = []
    sizes = {int(row['address'], 16): int(row['size']) for row in rows}
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        for address, outcome, score, text in pool.map(lambda row: harvest_one(arguments, signatures, row), rows):
            outcomes[outcome] = outcomes.get(outcome, 0) + 1
            table.append((address, sizes[address], outcome, score))
            if score is None:
                continue
            scores.append((score, address, text))
            if score == 0 or (arguments.write and score <= arguments.keep):
                if score == 0:
                    print(f'{address:#x}: matches', flush=True)
                if arguments.write:
                    path = os.path.join(SOURCES, f'{address:06X}.cpp')
                    if not os.path.exists(path):
                        with open(path, 'w', encoding='utf-8') as handle:
                            handle.write(text)
    scores.sort()
    os.makedirs(OUT, exist_ok=True)
    with open(os.path.join(OUT, 'scores.tsv'), 'w', encoding='utf-8') as handle:
        handle.write('address\tscore\n')
        for score, address, _text in scores:
            handle.write(f'{address:#x}\t{score}\n')
    with open(os.path.join(OUT, 'blockers.tsv'), 'w', encoding='utf-8') as handle:
        handle.write('address\tsize\toutcome\tscore\n')
        for address, size, outcome, score in sorted(table):
            handle.write(f'{address:#x}\t{size}\t{outcome}\t{"" if score is None else score}\n')
    print(', '.join(f'{count} {name}' for name, count in sorted(outcomes.items())))
    print('by size (bytes): functions / draft compiles / within 5 words / match')
    for low, high in ((8, 64), (65, 128), (129, 256), (257, 512), (513, 1024), (1025, 4096)):
        group = [entry for entry in table if low <= entry[1] <= high]
        compiled = [entry for entry in group if entry[3] is not None]
        print(f'  {low:5d}-{high:<5d} {len(group):5d} {len(compiled):5d} {sum(1 for e in compiled if e[3] <= 5):5d} {sum(1 for e in compiled if e[3] == 0):4d}')
    print(f'{sum(1 for score, _, _ in scores if score == 0)} match, {sum(1 for score, _, _ in scores if 0 < score <= 5)} within 5, {sum(1 for score, _, _ in scores if 5 < score <= 20)} within 20')
    for score, address, _text in scores[:arguments.near]:
        print(f'  {address:#x} score {score}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
