#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""frame_diff.py <address> <source> [--search N] - the stack frame of retail's function next to the frame of ours.

  python3 scripts/matching/frame_diff.py 0x13DA18 work/matching/waves/bg1/b2/13DA18/a1.cpp
  python3 scripts/matching/frame_diff.py 0x13DA18 a1.cpp --search 200       (permute the order of the local declarations, keep the best frame)

A function whose frame is laid out differently (another frame size, a spill slot at another offset, a local that does not share a slot) scores far
from 0 even when the code is right, and a score gives no hint which slot moved. This reads every `sp`-relative access of both functions (offset, width
and the instructions that touch it) and prints one row per stack offset: what retail does there and what ours does, `!` where they differ, the frame
size, the saved registers and the stack addresses handed out (`addiu rX, sp, N`: an address-taken local, which GCC lays out in declaration order).

The `frame distance` is the number of offsets whose accesses differ plus 8 for each word the frame sizes differ by. --search N compiles up to N
declaration orders of the function's locals (neighborhood.declaration_orders), prints the frame distance and the score of each and keeps the order with
the lowest (distance, score): the frame distance is flat where the score is not, so it crosses plateaus a score search cannot.
"""
import argparse
import os
import re
import sys
import collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import compare  # noqa: E402
import scorer  # noqa: E402

sys.path.insert(0, os.path.join(scorer.LAB, 'scripts', 'build'))
import compile_unit  # noqa: E402

ACCESS = re.compile(r'^(lq|sq|ld|sd|lw|sw|lwu|lh|lhu|sh|lb|lbu|sb|lwc1|swc1|lqc2|sqc2|ldc1|sdc1)\s+(\$\w+),\s*(-?0x[0-9A-Fa-f]+|-?\d+)\(\$sp\)')
ADDRESS = re.compile(r'^addiu\s+(\$\w+),\s*\$sp,\s*(-?0x[0-9A-Fa-f]+|-?\d+)')
FRAME = re.compile(r'^addiu\s+\$sp,\s*\$sp,\s*(-?0x[0-9A-Fa-f]+|-?\d+)')


def number(text):
    return int(text, 16) if '0x' in text.lower() else int(text)


def profile(words):
    """(frame size, {offset: [accesses]}, [stack addresses], saved registers) of the instruction words of one function."""
    size, slots, addresses, saved = 0, collections.defaultdict(list), [], []
    for index, word in enumerate(words):
        text = compare.disassemble(word)
        frame = FRAME.match(text)
        if frame and size == 0 and number(frame.group(1)) < 0:
            size = -number(frame.group(1))
            continue
        access = ACCESS.match(text)
        if access:
            offset = number(access.group(3))
            kind = access.group(1)
            if index < 24 and kind in ('sq', 'sd') and re.match(r'\$(s\d|ra|fp)', access.group(2)):
                saved.append(access.group(2))
            slots[offset].append(f'{kind} {access.group(2)}')
            continue
        address = ADDRESS.match(text)
        if address:
            addresses.append(number(address.group(2)))
            slots[number(address.group(2))].append('&')
    return size, dict(slots), addresses, saved


def shape(accesses):
    """The accesses of one offset without the registers: `sq`, `lq`, `&` ..., in order."""
    return ' '.join(item.split(' ')[0] for item in accesses)


def distance(retail, ours):
    offsets = set(retail[1]) | set(ours[1])
    differing = sum(1 for offset in offsets if sorted(shape(retail[1].get(offset, [])).split()) != sorted(shape(ours[1].get(offset, [])).split()))
    return differing + 8 * abs(retail[0] - ours[0]) // 4


def retail_profile(address):
    row = scorer.registry()[address]
    return profile(compare.read_target_words(scorer.ELF, address, int(row['size'])))


def our_profile(address, source, language):
    path = os.path.join(scorer.BUILD, f'frame-{address:06X}-{os.getpid()}.o')
    os.makedirs(scorer.BUILD, exist_ok=True)
    ok, message = compile_unit.compile_object(language, source, path, assembler=os.environ.get('TRY_ASSEMBLER') or compile_unit.assembler_for(address),
                                              include=scorer.INCLUDE, localize=False, vu0=compile_unit.vu0_for(address), movables=compile_unit.movables_for(address))
    if not ok:
        return None
    try:
        row = scorer.registry()[address]
        try:
            _, words, _, _ = compare.read_object_function(path, row['name'])
        except SystemExit:
            _, words, _, _ = compare.read_object_function(path, None)
        return profile(words)
    finally:
        for leftover in (path, path + '.tmp', path + '.s'):
            if os.path.exists(leftover):
                os.remove(leftover)


def show(retail, ours):
    print(f'frame size   retail 0x{retail[0]:X}   ours 0x{ours[0]:X}   {"" if retail[0] == ours[0] else "!"}')
    print(f'saved        retail {" ".join(retail[3])}   ours {" ".join(ours[3])}')
    print(f'addresses    retail {" ".join("0x%X" % a for a in retail[2])}')
    print(f'             ours   {" ".join("0x%X" % a for a in ours[2])}')
    print(f'{"offset":>8}  {"retail":<34} {"ours":<34}')
    for offset in sorted(set(retail[1]) | set(ours[1])):
        left, right = ' '.join(retail[1].get(offset, [])), ' '.join(ours[1].get(offset, []))
        mark = '' if sorted(shape(retail[1].get(offset, [])).split()) == sorted(shape(ours[1].get(offset, [])).split()) else '!'
        print(f'{offset:>#8x}  {left[:33]:<34} {right[:33]:<34} {mark}')
    print(f'frame distance {distance(retail, ours)}')


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('address', type=lambda text: int(text, 16))
    parser.add_argument('source')
    parser.add_argument('--search', type=int, default=0)
    arguments = parser.parse_args()
    language = 'c' if arguments.source.endswith('.c') else 'c++'
    retail = retail_profile(arguments.address)
    ours = our_profile(arguments.address, arguments.source, language)
    if ours is None:
        sys.exit('does not compile')
    show(retail, ours)
    if arguments.search:
        import neighborhood
        text = open(arguments.source, encoding='utf-8').read()
        best = (distance(retail, ours), scorer.score_of(scorer.compile_and_compare(arguments.address, text, language, True)) or 10 ** 6, text)
        tried = 0
        for candidate in neighborhood.declaration_orders(text, 5):
            if tried >= arguments.search:
                break
            tried += 1
            temporary = os.path.join(scorer.BUILD, f'frame-search-{os.getpid()}.cpp')
            with open(temporary, 'w', encoding='utf-8') as handle:
                handle.write(candidate)
            profiled = our_profile(arguments.address, temporary, language)
            os.remove(temporary)
            if profiled is None:
                continue
            key = (distance(retail, profiled), scorer.score_of(scorer.compile_and_compare(arguments.address, candidate, language, True)) or 10 ** 6)
            if key < best[:2]:
                best = (key[0], key[1], candidate)
                print(f'order {tried}: frame distance {key[0]}, score {key[1]}')
        out = arguments.source + '.frame'
        open(out, 'w', encoding='utf-8').write(best[2])
        print(f'best: frame distance {best[0]}, score {best[1]} -> {out}')


if __name__ == '__main__':
    main()
