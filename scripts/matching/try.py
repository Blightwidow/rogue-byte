#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""try.py <address> <source.cpp> [--symbol NAME] [--record] [--quiet] - decomp.wtf's compile_and_diff for Sly 2.

  python3 scripts/matching/try.py 0x116e30 data/matching/src/ary.cpp --record      (from the lab root)

Compiles the source with Sly 2's compiler (SN ProDG ee-gcc 2.95.3 build 1.36, -O2 -G0 -ffast-math -fno-exceptions,
through wibo) and compares the function at <address> with the binary (scripts/matching/compare.py): instructions with
relocated fields masked, then the link check (every call and %hi/%lo pair must resolve through
config/matching/symbol_addrs.txt to the address the binary has). Prints `score N` (0 = byte-identical once linked) and a
side-by-side diff (binary left, ours right). The function in the object is the one named --symbol, else the
registry's name for the address, else the only function in the object.

--record: counts the try in data/matching/functions.tsv (tries, best score; status `tried`, or `matched` with the
source path at score 0). The size compared is the split's (work/matching/split: spimdisasm, jump tables included).
"""
import argparse
import csv
import hashlib
import os
import subprocess
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
COMPILER = os.path.join(LAB, 'work', 'matching', 'compilers', 'ee-gcc2.95.3-136')
WIBO = os.path.join(LAB, 'work', 'matching', 'tools', 'wibo-macos')
PYTHON = os.path.join(LAB, 'work', 'matching', 'venv', 'bin', 'python')
FLAGS = ['-O2', '-G0', '-ffast-math', '-fno-exceptions']
REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
SYMBOLS = os.path.join(LAB, 'config', 'matching', 'symbol_addrs.txt')
INCLUDE = os.path.join(LAB, 'data', 'matching', 'include')


def registry():
    return list(csv.DictReader(open(REGISTRY, encoding='utf-8'), delimiter='\t'))


def note_repeat(address, source, score):
    """Remembers every source judged (not --quiet: the permuter judges thousands) in
    work/matching/judged/<ADDRESS>.tsv and says so when this exact source was judged before: the same source is easy to
    resubmit by accident."""
    digest = hashlib.sha1(open(source, 'rb').read()).hexdigest()
    path = os.path.join(LAB, 'work', 'matching', 'judged', f'{address:06X}.tsv')
    os.makedirs(os.path.dirname(path), exist_ok=True)
    earlier = [line.split('\t')[1] for line in open(path, encoding='utf-8').read().splitlines() if line.split('\t')[0] == digest] if os.path.exists(path) else []
    with open(path, 'a', encoding='utf-8') as handle:
        handle.write(f'{digest}\t{"error" if score is None else score}\n')
    if earlier:
        return f'NOTE: this exact source was judged {len(earlier)} time(s) before (score {", ".join(earlier)}): the result will not change, change the code.'
    return ''


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('address', type=lambda text: int(text, 16))
    parser.add_argument('source')
    parser.add_argument('--symbol')
    parser.add_argument('--record', action='store_true')
    parser.add_argument('--quiet', action='store_true')
    parser.add_argument('--lang', default='c++', choices=['c', 'c++'], help='source language (m2c drafts are C)')
    arguments = parser.parse_args()
    rows = registry()
    row = next((row for row in rows if int(row['address'], 16) == arguments.address), None)
    if not row:
        sys.exit(f'0x{arguments.address:X} is not a function start in the split')
    compiler = COMPILER if os.path.isdir(os.path.join(COMPILER, 'bin')) else os.path.join(COMPILER, 'cc')
    version = os.listdir(os.path.join(compiler, 'lib', 'gcc-lib', 'ee'))[0]
    build = os.path.join(LAB, 'work', 'matching', 'build', 'try')
    os.makedirs(build, exist_ok=True)
    source = os.path.abspath(arguments.source)
    obj = os.path.join(build, f'{arguments.address:06X}-{os.getpid()}.o')  # one per run: the permuter judges in parallel
    sys.path.insert(0, os.path.join(LAB, 'scripts', 'build'))
    import compile_unit
    ok, message = compile_unit.compile_object(arguments.lang, source, obj, assembler=os.environ.get('TRY_ASSEMBLER') or compile_unit.assembler_for(arguments.address), include=INCLUDE, localize=False)
    compile_result = subprocess.CompletedProcess([], 0 if ok else 1, '', message)
    if compile_result.returncode != 0:
        print('compile error')
        print((compile_result.stdout + compile_result.stderr).strip()[-3000:])
        score = None
    else:
        symbol = arguments.symbol or row['name']
        command = [PYTHON, os.path.join(LAB, 'scripts', 'matching', 'compare.py'), obj, hex(arguments.address),
                   '--elf', os.path.join(LAB, 'work', 'elf', 'SCUS_973.16'), '--size', row['size'], '--symbols', SYMBOLS]
        if arguments.quiet:
            command.append('--quiet')
        result = subprocess.run(command + ['--symbol', symbol], capture_output=True, text=True)
        if result.returncode != 0 and arguments.symbol is None:  # the registry's name isn't in the object: the only function
            result = subprocess.run(command, capture_output=True, text=True)
        output = (result.stdout + result.stderr).strip()
        print(output)
        if not arguments.quiet:  # the last full diff, for the progress page's drawer (scripts/serve_progress.sh)
            diffs = os.path.join(LAB, 'work', 'matching', 'diffs')
            os.makedirs(diffs, exist_ok=True)
            open(os.path.join(diffs, f'{arguments.address:06X}.txt'), 'w', encoding='utf-8').write(output + '\n')
        score = int(output.split()[1]) if output.startswith('score ') else None
    if os.path.exists(obj):
        os.remove(obj)
    if not arguments.quiet:
        repeated = note_repeat(arguments.address, source, score)
        if repeated:
            print(repeated)
    if arguments.record:
        row['tries'] = str(int(row['tries'] or 0) + 1)
        if score is not None and (row['best'] == '' or score < int(row['best'])):
            row['best'] = str(score)
        if row['status'] != 'matched':
            row['status'] = 'matched' if score == 0 else 'tried'
        if score == 0:
            row['source'] = os.path.relpath(source, LAB)
        with open(REGISTRY, 'w', encoding='utf-8', newline='') as out:
            writer = csv.DictWriter(out, list(rows[0].keys()), delimiter='\t', lineterminator='\n')
            writer.writeheader()
            writer.writerows(rows)
    return 0 if score == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
