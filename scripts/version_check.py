#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""version_check.py [--other work/elf/SCES_525.29] [--jobs N] [--limit N] - does the C of a matched US function reproduce the other version's code?

  .venv/bin/python scripts/version_check.py        (after scripts/pair_versions.py: it reads config/eu/map.tsv)

Each matched function (data/matching/functions.tsv, status `matched`) is compiled the way try.py compiles it and compared with the
function that config/eu/map.tsv pairs it with in the other executable: the fields the object relocates (the targets of calls, the
%hi/%lo of an address) are masked on both sides, the rest must be equal. A score of 0 means the same C gives the other version's
instructions: the function counts for that version, whatever addresses its calls and data have there. `--symbols` is not used: what the
masked fields point at is the next step.

Writes config/eu/c_status.tsv (us_address, name, other_address, pair status, score, addresses: `ok`, the number of mismatching sites, or empty
without a score) and prints the counts."""
import argparse
import concurrent.futures
import csv
import os
import sys
import types
from collections import Counter

LAB = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
sys.path.insert(0, os.path.join(LAB, 'scripts', 'matching'))
sys.path.insert(0, os.path.join(LAB, 'scripts', 'build'))
import compile_unit  # noqa: E402
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


def check(row, other_address, other_elf):
    """(score, sites) of the function's own source against the other executable; the score is None when it does not compile or compare."""
    address = int(row['address'], 16)
    source = os.path.join(LAB, row['source'])
    if not os.path.isfile(source):
        return None, []
    language = 'c' if source.endswith('.c') else 'c++'
    stem = os.path.join(scorer.BUILD, f'v{address:06X}-{os.getpid()}-{next(scorer._counter)}')
    os.makedirs(scorer.BUILD, exist_ok=True)
    path = stem + '.o'
    try:
        ok, _ = compile_unit.compile_object(language, source, path, assembler=compile_unit.assembler_for(address), include=scorer.INCLUDE, localize=False)
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
    rows = [row for row in csv.DictReader(open(scorer.REGISTRY, encoding='utf-8'), delimiter='\t') if row['status'] == 'matched' and row['source']]
    rows.sort(key=lambda row: int(row['address'], 16))
    if arguments.limit:
        rows = rows[:arguments.limit]
    progress = Progress(len(rows), 'version-check')

    def work(row):
        address = int(row['address'], 16)
        pair = pairs.get(address)
        name = row['address'][2:]
        progress.begin(name)
        score, found = check(row, int(pair['other_address'], 16), arguments.other) if pair else (None, [])
        progress.tick(f'{name}: {score}', name)
        return row, pair, score, found

    results = []
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        results = list(pool.map(work, rows))
    progress.done()
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
