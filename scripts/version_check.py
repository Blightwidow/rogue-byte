#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""version_check.py [--other work/elf/SCES_525.29] [--jobs N] [--limit N] - does the C of a matched US function reproduce the other version's code?

  .venv/bin/python scripts/version_check.py        (after scripts/pair_versions.py: it reads config/eu/map.tsv)

Each matched function (data/matching/functions.tsv, status `matched`) is compiled the way try.py compiles it and compared with the
function that config/eu/map.tsv pairs it with in the other executable (a function inside a whole file, src/MANIFEST.tsv `whole_file`, is
read from that file's object at its offset instead, the file compiled once as `make elf` compiles it): the fields the object relocates (the targets of calls, the
%hi/%lo of an address) are masked on both sides, the rest must be equal. A score of 0 means the same C gives the other version's
instructions: the function counts for that version, whatever addresses its calls and data have there. `--symbols` is not used: what the
masked fields point at is the next step.

Writes config/eu/c_status.tsv (us_address, name, other_address, pair status, score, addresses: `ok`, the number of mismatching sites, or empty
without a score) and prints the counts."""
import argparse
import concurrent.futures
import csv
import hashlib
import os
import pickle
import sys
import types
from collections import Counter

LAB = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
sys.path.insert(0, os.path.join(LAB, 'scripts', 'matching'))
sys.path.insert(0, os.path.join(LAB, 'scripts', 'build'))
import compile_unit  # noqa: E402
from asm_units import whole_files  # noqa: E402
import make_whole_files  # noqa: E402
import scorer  # noqa: E402
from progress import Progress  # noqa: E402

compare = scorer.compare


US_ELF = os.path.join(LAB, 'work', 'elf', 'SCUS_973.16')


def address_of(hi_word, lo_word):
    """The address a lui/lo pair forms (an ori zero-extends its immediate, every other consumer sign-extends it)."""
    low = lo_word & 0xFFFF
    if lo_word >> 26 != 0x0D and low >= 0x8000:
        low -= 0x10000
    return ((hi_word & 0xFFFF) << 16) + low & 0xFFFFFFFF


def sites(object_path, symbol, us_address, other_address, size, other_elf):
    """[(kind, US address, other address)] of the relocation sites of the object's function: `call` for a jal/j, `data` for a %hi/%lo pair."""
    try:
        _, object_words, relocations, _ = compare.read_object_function(object_path, symbol)
    except SystemExit:
        try:
            _, object_words, relocations, _ = compare.read_object_function(object_path, None)
        except SystemExit:
            return []
    count = len(object_words)
    us_words = compare.read_target_words(US_ELF, us_address, size)
    other_words = compare.read_target_words(other_elf, other_address, size)
    if len(us_words) < count or len(other_words) < count:
        return []
    found, pending = [], {}
    for index in sorted(relocations):
        kind, name = relocations[index]
        if kind == 4:  # R_MIPS_26
            found.append(('call', (us_words[index] & 0x03FFFFFF) << 2, (other_words[index] & 0x03FFFFFF) << 2))
        elif kind == 5:  # R_MIPS_HI16
            pending[name] = index
        elif kind == 6 and name in pending:  # R_MIPS_LO16
            high = pending[name]
            found.append(('data', address_of(us_words[high], us_words[index]), address_of(other_words[high], other_words[index])))
    return found


def whole_rows(manifest_path=None):
    """{address: (whole file, start of its range)} of the matched functions inside a whole file (src/MANIFEST.tsv `whole_file`): the whole
    file is their source."""
    starts = {file: start for start, _, file in whole_files()}
    path = manifest_path or os.path.join(LAB, 'src', 'MANIFEST.tsv')
    found = {}
    for row in csv.DictReader(open(path, encoding='utf-8'), delimiter='\t'):
        if row.get('whole_file') and row['whole_file'] in starts:
            found[int(row['address'], 16)] = (row['whole_file'], starts[row['whole_file']])
    return found


def compile_whole(file, start):
    """(object path, {offset: symbol}) of a whole file compiled as `make elf` compiles it (INCLUDE_ASM from build/splat), or (None, {})."""
    os.makedirs(scorer.BUILD, exist_ok=True)
    path = os.path.join(scorer.BUILD, f'whole-{start:06X}-{os.getpid()}.o')
    ok, _ = compile_unit.compile_object('c' if file.endswith('.c') else 'c++', os.path.join(LAB, 'src', file), path, assembler=compile_unit.assembler_for(start),
                                        localize=False, vu0=compile_unit.vu0_for(start), movables=compile_unit.movables_for(start))
    return (path, make_whole_files.function_symbols(path)) if ok else (None, {})


def check(row, other_address, other_elf, whole=None):
    """(score, sites) of the function's own source against the other executable; the score is None when it does not compile or compare.
    `whole` is (object, symbols, start) for a function inside a whole file: it is read from that object at its offset (start + symbol value)."""
    address = int(row['address'], 16)
    if whole is not None:
        object_path, symbols, start = whole
        symbol = symbols.get(address - start)
        if object_path is None or symbol is None:
            return None, []
        arguments = types.SimpleNamespace(object=object_path, address=other_address, elf=other_elf, symbol=symbol, size=int(row['size']), export=None, quiet=True, symbols=None)
        try:
            output = compare.compare(arguments)
        except SystemExit:
            return None, []
        return scorer.score_of(output), sites(object_path, symbol, address, other_address, int(row['size']), other_elf)
    source = os.path.join(LAB, row['source'])
    if not os.path.isfile(source):
        return None, []
    language = 'c' if source.endswith('.c') else 'c++'
    stem = os.path.join(scorer.BUILD, f'v{address:06X}-{os.getpid()}-{next(scorer._counter)}')
    os.makedirs(scorer.BUILD, exist_ok=True)
    path = stem + '.o'
    try:
        ok, _ = compile_unit.compile_object(language, source, path, assembler=compile_unit.assembler_for(address), include=scorer.INCLUDE, localize=False, vu0=compile_unit.vu0_for(address), movables=compile_unit.movables_for(address))
        if not ok:
            return None, []
        arguments = types.SimpleNamespace(object=path, address=other_address, elf=other_elf, symbol=row['name'], size=int(row['size']), export=None, quiet=True, symbols=None)
        try:
            output = compare.compare(arguments)
        except SystemExit:
            arguments.symbol = None
            try:
                output = compare.compare(arguments)
            except SystemExit:
                return None, []
        return scorer.score_of(output), sites(path, arguments.symbol, address, other_address, int(row['size']), other_elf)
    finally:
        for leftover in (path, path + '.tmp', path + '.s'):
            if os.path.exists(leftover):
                os.remove(leftover)


CACHE_PATH = os.path.join(LAB, 'work', 'matching', 'pal_cache.pkl')


def tree_digest(directory, suffixes):
    """sha1 over the names, sizes and modification times of every file under `directory` that ends in one of `suffixes`, in name order. Not the
    bytes: reading all of build/splat/asm took seconds on each run. A file that is touched without a change only costs a recompile; make elf
    keeps the times of the files Splat rewrites unchanged (configure.py)."""
    digest = hashlib.sha1()
    for folder, names_below, names in sorted(os.walk(directory)):
        names_below.sort()
        for name in sorted(names):
            if name.endswith(suffixes):
                path = os.path.join(folder, name)
                status = os.stat(path)
                digest.update(f'{os.path.relpath(path, directory)}\0{status.st_size}\0{status.st_mtime_ns}\n'.encode())
    return digest.hexdigest()


def cache_context():
    """What every cached result depends on besides the function itself: the toolchain, the headers the sources include and the split assembly
    the whole files include from."""
    digest = hashlib.sha1(scorer.fingerprint().encode())
    digest.update(tree_digest(scorer.INCLUDE, ('.h', '.hpp')).encode())
    digest.update(tree_digest(os.path.join(LAB, 'build', 'splat', 'asm'), ('.s',)).encode())
    return digest.hexdigest()


def row_key(context, row, other_address, other_elf, whole_file):
    """The cache key of one matched function: the context, its source text (the whole file's text for a function inside one), the other
    version's bytes it is compared with, and the flags it is compiled with. Two runs with the same key give the same score and sites."""
    address = int(row['address'], 16)
    path = os.path.join(LAB, 'src', whole_file[0]) if whole_file else os.path.join(LAB, row['source'])
    start = whole_file[1] if whole_file else address
    if not os.path.isfile(path):
        return None
    with open(path, 'rb') as handle:
        source = handle.read()
    words = compare.read_target_words(other_elf, other_address, int(row['size']))
    digest = hashlib.sha1(context.encode())
    for part in (source, repr(tuple(words)).encode(), f"{row['name']}\0{row['size']}\0{address}\0{other_address}\0{start}".encode(),
                 repr((compile_unit.assembler_for(start), compile_unit.vu0_for(start), compile_unit.movables_for(start))).encode()):
        digest.update(part)
    return digest.hexdigest()


def load_cache():
    try:
        with open(CACHE_PATH, 'rb') as handle:
            return pickle.load(handle)
    except (OSError, EOFError, pickle.UnpicklingError, AttributeError):
        return {}


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--other', default=os.path.join(LAB, 'work', 'elf', 'SCES_525.29'))
    parser.add_argument('--map', default=os.path.join(LAB, 'config', 'eu', 'map.tsv'))
    parser.add_argument('--out', default=os.path.join(LAB, 'config', 'eu', 'c_status.tsv'))
    parser.add_argument('--jobs', type=int, default=8)
    parser.add_argument('--limit', type=int, default=0, help='only the first N matched functions (to try it)')
    arguments = parser.parse_args()
    if not compare:
        sys.exit('needs rabbitizer and pyelftools: run with .venv/bin/python')
    pairs = {int(row['us_address'], 16): row for row in csv.DictReader(open(arguments.map, encoding='utf-8'), delimiter='\t') if row['other_address']}
    inside = whole_rows()
    ranges = [(start, end) for start, end, _ in whole_files()]
    # a matched function inside a whole file counts once the whole file holds it (export_src.py publishes nothing else for it)
    rows = [row for row in csv.DictReader(open(scorer.REGISTRY, encoding='utf-8'), delimiter='\t') if row['status'] == 'matched' and row['source']
            and (int(row['address'], 16) in inside or not any(start <= int(row['address'], 16) < end for start, end in ranges))]
    rows.sort(key=lambda row: int(row['address'], 16))
    if arguments.limit:
        rows = rows[:arguments.limit]
    context = cache_context()
    cache = load_cache()
    keys = {}
    for row in rows:
        address = int(row['address'], 16)
        if address in pairs:
            keys[address] = row_key(context, row, int(pairs[address]['other_address'], 16), arguments.other, inside.get(address))
    stale = [row for row in rows if int(row['address'], 16) in pairs and keys.get(int(row['address'], 16)) not in cache]
    needed = sorted({inside[int(row['address'], 16)] for row in stale if int(row['address'], 16) in inside})
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        wholes = dict(zip(needed, pool.map(lambda entry: compile_whole(*entry), needed)))
    print(f'version-check: {len(rows) - len(stale)} of {len(rows)} results cached, {len(stale)} to compile ({len(needed)} whole files)')
    progress = Progress(len(rows), 'version-check')
    fresh = {}

    def work(row):
        address = int(row['address'], 16)
        pair = pairs.get(address)
        name = row['address'][2:]
        progress.begin(name)
        key = keys.get(address)
        if pair and key in cache:
            score, found = cache[key]
            fresh[key] = (score, found)
        else:
            whole = (*wholes[inside[address]], inside[address][1]) if pair and address in inside else None
            score, found = check(row, int(pair['other_address'], 16), arguments.other, whole) if pair else (None, [])
            if pair and key is not None:
                fresh[key] = (score, found)
        progress.tick(f'{name}: {score}', name)
        return row, pair, score, found

    results = []
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        results = list(pool.map(work, rows))
    progress.done()
    os.makedirs(os.path.dirname(CACHE_PATH), exist_ok=True)
    with open(CACHE_PATH, 'wb') as handle:  # only the keys of this run: a result of a function that changed or went away is dropped
        pickle.dump(fresh, handle)
    for object_path, _ in wholes.values():
        if object_path and os.path.exists(object_path):
            os.remove(object_path)
    pair_of = {address: int(row['other_address'], 16) for address, row in pairs.items()}
    votes = {}
    for _, _, _, found in results:
        for kind, us_target, other_target in found:
            if kind == 'data':
                votes.setdefault(us_target, Counter())[other_target] += 1
    consensus = {us_target: counter.most_common(1)[0][0] for us_target, counter in votes.items()}

    def mismatches(found):
        count = 0
        for kind, us_target, other_target in found:
            expected = pair_of.get(us_target) if kind == 'call' else consensus.get(us_target)
            count += expected is not None and expected != other_target
        return count

    os.makedirs(os.path.dirname(arguments.out), exist_ok=True)
    counts, sizes = Counter(), Counter()
    with open(arguments.out, 'w', encoding='utf-8') as handle:
        handle.write('us_address\tname\tother_address\tpair\tscore\taddresses\n')
        for row, pair, score, found in results:
            other = pair['other_address'] if pair else ''
            wrong = mismatches(found) if score is not None else None
            handle.write(f'{row["address"]}\t{row["name"]}\t{other}\t{pair["status"] if pair else "none"}\t{"" if score is None else score}\t'
                         f'{"" if wrong is None else "ok" if not wrong else wrong}\n')
            kind = ('unpaired' if not pair else 'no result' if score is None else 'different' if score > 5 else 'near' if score
                    else 'exact, addresses differ' if wrong else 'exact')
            counts[kind] += 1
            sizes[kind] += int(row['size'])
    with open(os.path.join(os.path.dirname(arguments.out), 'addresses.tsv'), 'w', encoding='utf-8') as handle:
        handle.write('us_address\tother_address\tsites\tagree\n')
        for us_target in sorted(votes):
            handle.write(f'{us_target:#X}\t{consensus[us_target]:#X}\t{sum(votes[us_target].values())}\t{votes[us_target][consensus[us_target]]}\n')
    total, total_size = len(results), sum(sizes.values())
    for kind in ('exact', 'exact, addresses differ', 'near', 'different', 'no result', 'unpaired'):
        print(f'{kind:10} {counts[kind]:5} functions  {sizes[kind]:8} bytes  {100 * sizes[kind] / total_size:5.1f}%')
    print(f'{len(votes)} data addresses mapped; {total} matched US functions checked against {os.path.basename(arguments.other)}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
