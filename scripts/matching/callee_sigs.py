#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""callee_sigs.py - what every function in the executable returns, read from the code around it, and the source declarations that disagree.

  .venv/bin/python scripts/matching/callee_sigs.py build                  writes work/matching/callee_sigs.tsv
  .venv/bin/python scripts/matching/callee_sigs.py check [--control]      sources whose extern declarations disagree with it
  .venv/bin/python scripts/matching/callee_sigs.py apply ADDRESS [--write]  rewrite one source's declarations to the inferred types, judge it
  .venv/bin/python scripts/matching/callee_sigs.py sweep [--max-score N] [--write]  single and paired return-type changes on every near miss

Why: a callee's declared return type steers register allocation and scheduling around its call even when the caller throws the result
away (flipping `void` to `int` on a callee matched four near misses at once). The search found those by chance; the executable says it
directly. Evidence, strongest first:
  * a caller reads `$v0` (or `$f0`) after the call before writing it: the callee returns an int-class (float) value;
  * the callee's own code writes `$v0` (`$f0`) in the last instructions before a `jr $ra`, delay slot included;
  * neither: `void` (no sign of a result), or `unknown` when no caller is known.
A caller that discards an int result looks the same as a call of a void function, so "never read" alone is weak; the callee's tail decides
that case. The tool reports the evidence counts next to the verdict."""
import argparse
import collections
import csv
import os
import re
import struct
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
SYMBOLS = os.path.join(LAB, 'config', 'matching', 'symbol_addrs.txt')
ELF = os.path.join(LAB, 'work', 'elf', 'SCUS_973.16')
OUTPUT = os.path.join(LAB, 'work', 'matching', 'callee_sigs.tsv')
SOURCES = os.path.join(LAB, 'data', 'matching', 'src', 'fn')
V0, RA = 2, 31
WINDOW = 32
FLOAT_WRITERS = re.compile(r'^(lwc1|mtc1|ctc1|cfc1|(add|sub|mul|div|mov|neg|abs|sqrt|rsqrt|madd|msub|max|min|cvt\.\w+|trunc\.\w+|floor\.\w+|ceil\.\w+|round\.\w+)(\.\w+)?)$')


def load_code():
    """(base address, words) of .text."""
    from elftools.elf.elffile import ELFFile
    with open(ELF, 'rb') as handle:
        section = ELFFile(handle).get_section_by_name('.text')
        data = section.data()
        return section['sh_addr'], struct.unpack(f'<{len(data) // 4}I', data)


def decode(word):
    import rabbitizer
    return rabbitizer.Instruction(word, category=rabbitizer.InstrCategory.R5900)


def register_value(register):
    return getattr(register, 'value', register)


def reads_v0(instruction):
    return ((instruction.readsRs() and register_value(instruction.rs) == V0) or (instruction.readsRt() and register_value(instruction.rt) == V0)
            or (instruction.readsRd() and register_value(instruction.rd) == V0))


def writes_v0(instruction):
    destination = instruction.getDestinationGpr()
    return destination is not None and register_value(destination) == V0


def float_use(text):
    """'read', 'write' or None: what an instruction does with $f0 (by its text)."""
    parts = text.replace(',', ' ').split()
    if not parts or '$f0' not in parts[1:]:
        return None
    mnemonic = parts[0]
    if mnemonic.startswith('c.'):
        return 'read'
    return 'write' if parts[1] == '$f0' and FLOAT_WRITERS.match(mnemonic) else 'read'


def call_use(words, index):
    """What the code after the call at words[index] does with the result: 'int', 'float', 'unused' or 'tail' (falls out of the function)."""
    integer_dead = float_dead = False
    position = index + 1  # the delay slot runs before the callee: it cannot read the result
    for step in range(WINDOW):
        position += 1
        if position >= len(words):
            break
        instruction = decode(words[position])
        text = ' '.join(instruction.disassemble().split())
        if not integer_dead:
            if reads_v0(instruction):
                return 'int'
            if writes_v0(instruction):
                integer_dead = True
        if not float_dead:
            use = float_use(text)
            if use == 'read':
                return 'float'
            if use == 'write':
                float_dead = True
        if instruction.isJump() or instruction.isBranch():
            delay = decode(words[position + 1]) if position + 1 < len(words) else None
            if delay is not None:
                delay_text = ' '.join(delay.disassemble().split())
                if not integer_dead and reads_v0(delay):
                    return 'int'
                if not float_dead and float_use(delay_text) == 'read':
                    return 'float'
            if instruction.isJumpWithAddress() or (instruction.isJump() and register_value(instruction.rs) != RA):
                return 'unused'  # another call or jump: the arguments were set up before it
            if instruction.isJump():  # jr $ra: the caller itself returns what is in $v0, unless it overwrote it
                return 'unused' if integer_dead else 'tail'
            return 'unused'  # a conditional branch: only the fall-through is followed, so a read on the other path is missed
    return 'unused'


def returns_in_tail(words, start, end):
    """(int, float): whether the function's last instructions before a `jr $ra` write $v0 / $f0."""
    wrote_int = wrote_float = False
    for position in range(start, end):
        instruction = decode(words[position])
        if instruction.isJump() and not instruction.isJumpWithAddress() and register_value(instruction.rs) == RA:
            for back in range(max(start, position - 4), min(end, position + 2)):
                if back == position:
                    continue
                previous = decode(words[back])
                if previous.isJump() and previous.isJumpWithAddress():
                    continue
                if writes_v0(previous):
                    wrote_int = True
                if float_use(' '.join(previous.disassemble().split())) == 'write':
                    wrote_float = True
    return wrote_int, wrote_float


def build():
    base, words = load_code()
    with open(REGISTRY, encoding='utf-8') as handle:
        rows = list(csv.DictReader(handle, delimiter='\t'))
    functions = sorted((int(row['address'], 16), int(row['size']), row['name']) for row in rows if row['size'])
    evidence = collections.defaultdict(collections.Counter)
    for address, size, _name in functions:
        start = (address - base) // 4
        for index in range(start, start + size // 4):
            if index >= len(words) or words[index] >> 26 != 3:  # jal
                continue
            target = (((base + index * 4 + 4) & 0xF0000000) | ((words[index] & 0x3FFFFFF) << 2)) & 0x1FFFFFFF
            evidence[target][call_use(words, index)] += 1
    os.makedirs(os.path.dirname(OUTPUT), exist_ok=True)
    counts = collections.Counter()
    with open(OUTPUT, 'w', encoding='utf-8') as out:
        out.write('address\tname\tcallers\tint\tfloat\tunused\ttail\tends_v0\tends_f0\tinferred\n')
        for address, size, name in functions:
            start = (address - base) // 4
            ends_int, ends_float = returns_in_tail(words, start, start + size // 4) if size else (False, False)
            counter = evidence.get(address, collections.Counter())
            callers = sum(counter.values())
            if counter['int']:
                inferred = 'int'
            elif counter['float'] and (counter['float'] * 2 >= callers or ends_float):  # a stray read of $f0 after one call is not a float result
                inferred = 'float'
            elif ends_int:
                inferred = 'int?'
            elif ends_float:
                inferred = 'float?'
            elif callers:
                inferred = 'void'
            else:
                inferred = 'unknown'
            counts[inferred] += 1
            out.write(f'{address:#x}\t{name}\t{callers}\t{counter["int"]}\t{counter["float"]}\t{counter["unused"]}\t{counter["tail"]}\t{int(ends_int)}\t{int(ends_float)}\t{inferred}\n')
    print(f'{len(functions)} functions -> {OUTPUT}: {dict(counts)}')


def load_signatures():
    import compare
    addresses = compare.read_symbol_addresses(SYMBOLS)
    by_name = {}
    with open(OUTPUT, encoding='utf-8') as handle:
        for row in csv.DictReader(handle, delimiter='\t'):
            by_name[row['name']] = row
            by_name.setdefault(row['name'].split('__')[0], row)
    by_address = {int(row['address'], 16): row for row in by_name.values()}
    return addresses, by_name, by_address


DECLARATION = re.compile(r'^(extern "C"\s+)?(void|int|unsigned|float|char|short|long|unsigned int|[A-Za-z_][A-Za-z_0-9]*\s*\*)\s+([A-Za-z_][A-Za-z_0-9]*)\s*\(([^;{]*)\);\s*$')


def declared_kind(type_text):
    type_text = type_text.strip()
    if type_text == 'void':
        return 'void'
    if type_text == 'float':
        return 'float'
    return 'int'


def inferred_kind(row):
    verdict = row['inferred'].rstrip('?')
    return None if verdict == 'unknown' else verdict


def lookup(name, addresses, by_name, by_address):
    row = by_name.get(name) or by_name.get(name.split('__')[0])
    if row:
        return row
    address = addresses.get(name)
    return by_address.get(address) if address is not None else None


def disagreements(path, addresses, by_name, by_address):
    """[(line number, name, declared kind, row)] for the extern declarations of a source whose kind differs from the inferred one."""
    found = []
    with open(path, encoding='utf-8') as handle:
        lines = handle.read().split('\n')
    for number, line in enumerate(lines):
        match = DECLARATION.match(line.strip()) if 'extern' in line or line.lstrip().startswith(('void ', 'int ')) else None
        if not match or not match.group(1):
            continue
        row = lookup(match.group(3), addresses, by_name, by_address)
        kind = inferred_kind(row) if row else None
        if kind and kind != declared_kind(match.group(2)) and not (row['inferred'].endswith('?') and kind == 'void'):
            found.append((number, match.group(3), declared_kind(match.group(2)), row))
    return found


def check(arguments):
    addresses, by_name, by_address = load_signatures()
    with open(REGISTRY, encoding='utf-8') as handle:
        registry = {int(row['address'], 16): row for row in csv.DictReader(handle, delimiter='\t')}
    agree = differ = 0
    flagged = []
    for name in sorted(os.listdir(SOURCES)):
        address = int(name.split('.')[0], 16)
        row = registry.get(address)
        if not row or (arguments.control and row['status'] != 'matched') or (not arguments.control and row['status'] == 'matched'):
            continue
        path = os.path.join(SOURCES, name)
        with open(path, encoding='utf-8') as handle:
            text = handle.read()
        total = sum(1 for line in text.split('\n') if DECLARATION.match(line.strip()) and 'extern' in line)
        mismatches = disagreements(path, addresses, by_name, by_address)
        differ += len(mismatches)
        agree += total - len(mismatches)
        if mismatches:
            flagged.append((row['best'], address, mismatches))
    print(f'{"control (matched sources)" if arguments.control else "unmatched sources"}: {agree} declarations agree, {differ} disagree')
    if not arguments.control:
        for best, address, mismatches in sorted(flagged, key=lambda item: int(item[0]) if item[0].isdigit() else 9999)[:arguments.limit]:
            print(f'{address:#x} score {best}: ' + ', '.join(f'{name} declared {declared}, code says {row["inferred"]}' for _, name, declared, row in mismatches))


def rewrite(path, addresses, by_name, by_address):
    with open(path, encoding='utf-8') as handle:
        text = handle.read().split('\n')
    changed = []
    for number, name, declared, row in disagreements(path, addresses, by_name, by_address):
        kind = inferred_kind(row)
        text[number] = re.sub(r'\b(void|int|unsigned|float|char|short|long)\b(?=\s+' + re.escape(name) + r'\s*\()', kind, text[number], count=1)
        changed.append(name)
    return '\n'.join(text), changed


def apply(arguments):
    import scorer
    addresses, by_name, by_address = load_signatures()
    address = int(arguments.address, 16)
    path = os.path.join(SOURCES, f'{address:06X}.cpp')
    with open(path, encoding='utf-8') as handle:
        original = handle.read()
    text, changed = rewrite(path, addresses, by_name, by_address)
    if not changed:
        print('no declaration disagrees')
        return 0
    before, after = scorer.judge(address, original), scorer.judge(address, text)
    print(f'{address:#x}: changed {", ".join(changed)}: score {before} -> {after}')
    if arguments.write and after is not None and (before is None or after < before):
        with open(path, 'w', encoding='utf-8') as handle:
            handle.write(text)
        print('written')
    return 0


def declaration_lines(text):
    """[(line number, type text, name)] of the extern "C" function declarations of a source whose return type is a plain scalar or void."""
    found = []
    for number, line in enumerate(text.split('\n')):
        match = DECLARATION.match(line.strip())
        if match and match.group(1) and match.group(2) in ('void', 'int', 'float', 'unsigned', 'char', 'short', 'long', 'unsigned int'):
            found.append((number, match.group(2), match.group(3)))
    return found


def with_type(text, number, name, kind):
    lines = text.split('\n')
    lines[number] = re.sub(r'\b(void|int|unsigned int|unsigned|float|char|short|long)\b(?=\s+' + re.escape(name) + r'\s*\()', kind, lines[number], count=1)
    return '\n'.join(lines)


def sweep_function(address, path, best, budget, addresses, by_name, by_address, scorer):
    """Tries single return-type changes of the declarations, then pairs of the ones the inference disputes; (best score, best text, compiles)."""
    with open(path, encoding='utf-8') as handle:
        original = handle.read()
    declarations = declaration_lines(original)
    options = []  # (priority, number, name, kind)
    for number, kind, name in declarations:
        row = lookup(name, addresses, by_name, by_address)
        inferred = inferred_kind(row) if row else None
        for alternative in ('void', 'int', 'float'):
            if alternative != declared_kind(kind):
                options.append((0 if inferred == alternative else 1, number, name, alternative))
    options.sort()
    best_text, best_score, used = original, best, 0
    candidates = [[option] for option in options]
    preferred = [option for option in options if option[0] == 0]
    candidates += [[first, second] for index, first in enumerate(preferred) for second in preferred[index + 1:] if first[2] != second[2]]
    for combination in candidates[:budget]:
        text = original
        for _, number, name, kind in combination:
            text = with_type(text, number, name, kind)
        used += 1
        score = scorer.judge(address, text)
        if score is not None and score < best_score:
            best_score, best_text = score, text
            if score == 0:
                break
    return best_score, best_text, used


def sweep(arguments):
    import concurrent.futures
    import scorer
    addresses, by_name, by_address = load_signatures()
    registry = scorer.registry()
    pool = []
    for name in sorted(os.listdir(SOURCES)):
        address = int(name.split('.')[0], 16)
        row = registry.get(address)
        if row and row['status'] == 'tried' and row['best'].isdigit() and arguments.min_score <= int(row['best']) <= arguments.max_score:
            pool.append((int(row['best']), address, os.path.join(SOURCES, name)))
    pool.sort()
    print(f'{len(pool)} functions, score {arguments.min_score}-{arguments.max_score}, up to {arguments.budget} compiles each')
    improved = matched = 0
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as executor:
        futures = {executor.submit(sweep_function, address, path, best, arguments.budget, addresses, by_name, by_address, scorer): (best, address, path) for best, address, path in pool}
        for future in concurrent.futures.as_completed(futures):
            best, address, path = futures[future]
            score, text, used = future.result()
            if score < best:
                improved += 1
                matched += score == 0
                print(f'{address:#x}: {best} -> {score} ({used} compiles)', flush=True)
                if arguments.write:
                    with open(path, 'w', encoding='utf-8') as handle:
                        handle.write(text)
    print(f'{improved} improved, {matched} reach 0')


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest='command', required=True)
    sub.add_parser('build')
    checker = sub.add_parser('check')
    checker.add_argument('--control', action='store_true', help='compare with the matched sources instead: how often the inference agrees with what matched')
    checker.add_argument('--limit', type=int, default=40)
    sweeper = sub.add_parser('sweep', help='single and paired return-type changes of the declarations of every near miss')
    sweeper.add_argument('--min-score', type=int, default=1)
    sweeper.add_argument('--max-score', type=int, default=40)
    sweeper.add_argument('--budget', type=int, default=40)
    sweeper.add_argument('--jobs', type=int, default=12)
    sweeper.add_argument('--write', action='store_true')
    applier = sub.add_parser('apply')
    applier.add_argument('address')
    applier.add_argument('--write', action='store_true')
    arguments = parser.parse_args()
    {'build': lambda _: build(), 'check': check, 'apply': apply, 'sweep': sweep}[arguments.command](arguments)
    return 0


if __name__ == '__main__':
    sys.exit(main())
