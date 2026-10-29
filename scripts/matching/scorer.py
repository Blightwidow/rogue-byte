#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scorer.py - judge many candidate sources for one function without a process per try.

  from scorer import judge, report
  judge(0x13A688, source_text)          # score (0 = match), or None when the compile fails
  report(0x13A688, source_text)         # the side-by-side diff of try.py, as text

`scripts/matching/try.py` starts Python, reads the registry and starts `compare.py` for every try; a search that judges thousands of
candidates paid that each time (0.14 s of 0.34 s). Here the registry, the target words and the symbol table are read once per process and
the comparison runs in the calling thread, so a search keeps its threads busy with the compiler (ee-gcc under wibo, then ps2eeas) only.
Scores are also kept on disk, keyed by the source, the language and a fingerprint of everything that changes a result (compiler flags,
assembler and its function lists, the include directory), in work/matching/scorecache/<ADDRESS>.tsv: a search that revisits a source
(a restart from the best, the same seed run again, two searches that reach one rewrite) pays nothing for it.

  python3 scripts/matching/scorer.py --bench 0x13A688 data/matching/src/fn/13A688.cpp [--count N]     compile speed against try.py"""
import argparse
import csv
import hashlib
import itertools
import os
import sys
import tempfile
import threading
import time

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.join(LAB, 'scripts', 'build'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import compile_unit  # noqa: E402
try:
    import compare  # noqa: E402  (needs rabbitizer and pyelftools: the repository's .venv has them)
except ImportError:
    compare = None

REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
SYMBOLS = os.path.join(LAB, 'config', 'matching', 'symbol_addrs.txt')
INCLUDE = os.path.join(LAB, 'data', 'matching', 'include')
ELF = os.path.join(LAB, 'work', 'elf', 'SCUS_973.16')
BUILD = os.path.join(LAB, 'work', 'matching', 'build', 'scorer')
CACHE = os.path.join(LAB, 'work', 'matching', 'scorecache')

_lock = threading.Lock()
_counter = itertools.count()
_rows = None
_fingerprint = None
_cache = {}  # address -> {key: score or None}


def registry():
    """address -> registry row, read once."""
    global _rows
    with _lock:
        if _rows is None:
            with open(REGISTRY, encoding='utf-8') as handle:
                _rows = {int(row['address'], 16): row for row in csv.DictReader(handle, delimiter='\t')}
        return _rows


def fingerprint():
    """A short hash of what a score depends on besides the source."""
    global _fingerprint
    with _lock:
        if _fingerprint is None:
            digest = hashlib.sha1()
            digest.update(' '.join(compile_unit.FLAGS).encode())
            for path in (compile_unit.PS2EEAS, os.path.join(LAB, 'config', 'us', 'gnu_as.txt'), os.path.join(LAB, 'config', 'us', 'ps2eeas_loop5.txt'), os.path.join(LAB, 'config', 'us', 'sony_gcc29.txt'), SYMBOLS):
                digest.update(f'{path}:{os.path.getmtime(path) if os.path.exists(path) else 0}'.encode())
            for directory, _, names in os.walk(INCLUDE):
                for name in sorted(names):
                    digest.update(f'{name}:{os.path.getmtime(os.path.join(directory, name))}'.encode())
            _fingerprint = digest.hexdigest()[:12]
        return _fingerprint


def address_of(address):
    return int(address, 16) if isinstance(address, str) else address


def cache_for(address):
    with _lock:
        if address not in _cache:
            entries = {}
            path = os.path.join(CACHE, f'{address:06X}.tsv')
            if os.path.exists(path):
                with open(path, encoding='utf-8') as handle:
                    for line in handle:
                        fields = line.rstrip('\n').split('\t')
                        if len(fields) == 2:
                            entries[fields[0]] = None if fields[1] == 'error' else int(fields[1])
            _cache[address] = entries
        return _cache[address]


def remember(address, key, score):
    cache_for(address)[key] = score
    os.makedirs(CACHE, exist_ok=True)
    with _lock, open(os.path.join(CACHE, f'{address:06X}.tsv'), 'a', encoding='utf-8') as handle:
        handle.write(f'{key}\t{"error" if score is None else score}\n')


def compare_object(address, path, quiet, symbol=None):
    row = registry()[address]
    arguments = argparse.Namespace(object=path, address=address, elf=ELF, symbol=symbol or row['name'], size=int(row['size']), export=None, quiet=quiet, symbols=SYMBOLS)
    try:
        return compare.compare(arguments)
    except SystemExit:  # the registry's name is not in the object: the only function in it
        arguments.symbol = None
        try:
            return compare.compare(arguments)
        except SystemExit as error:
            return f'error {error}'


def compile_and_compare(address, text, lang, quiet):
    """The report of one candidate, or None when it does not compile."""
    os.makedirs(BUILD, exist_ok=True)
    stem = os.path.join(BUILD, f'{address:06X}-{os.getpid()}-{next(_counter)}')
    source, path = stem + ('.cpp' if lang == 'c++' else '.c'), stem + '.o'
    with open(source, 'w') as handle:
        handle.write(text)
    try:
        ok, _message = compile_unit.compile_object(lang, source, path, assembler=os.environ.get('TRY_ASSEMBLER') or compile_unit.assembler_for(address), include=INCLUDE, localize=False)
        if not ok:
            return None
        return compare_object(address, path, quiet)
    finally:
        for leftover in (source, path, path + '.tmp', path + '.s'):
            if os.path.exists(leftover):
                os.remove(leftover)


def score_of(output):
    return int(output.split()[1]) if output and output.startswith('score ') else None


def judge(address, text, lang='c++'):
    """The score of the source for the function at `address` (0 = match), None when it fails to compile or compare."""
    address = address_of(address)
    key = hashlib.sha1(f'{fingerprint()}\0{lang}\0{text}'.encode()).hexdigest()[:20]
    entries = cache_for(address)
    if key in entries:
        return entries[key]
    score = score_of(compile_and_compare(address, text, lang, quiet=True))
    remember(address, key, score)
    return score


def report(address, text, lang='c++'):
    """The full diff try.py prints, or the text 'compile error'."""
    output = compile_and_compare(address_of(address), text, lang, quiet=False)
    return 'compile error' if output is None else output


def bench(address, path, count, lang):
    with open(path, encoding='utf-8') as handle:
        text = handle.read()
    address = address_of(address)
    registry()
    started = time.time()
    scores = [judge(address, text + f'\n// {next(_counter)}-{time.time()}\n', lang) for _ in range(count)]  # a distinct source each time: no cache hit
    seconds = (time.time() - started) / count
    print(f'in process: {seconds:.3f} s per compile ({set(scores)})')
    import subprocess
    started = time.time()
    for _ in range(count):
        subprocess.run([sys.executable, os.path.join(LAB, 'scripts', 'matching', 'try.py'), hex(address), path, '--quiet'], capture_output=True)
    print(f'try.py:     {(time.time() - started) / count:.3f} s per compile')


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--bench', nargs=2, metavar=('ADDRESS', 'SOURCE'))
    parser.add_argument('--count', type=int, default=20)
    parser.add_argument('--lang', default='c++', choices=['c', 'c++'])
    arguments = parser.parse_args()
    if arguments.bench:
        bench(arguments.bench[0], arguments.bench[1], arguments.count, arguments.lang)
        return 0
    parser.print_help()
    return 1


if __name__ == '__main__':
    sys.exit(main())
