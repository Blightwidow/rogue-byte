#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""boundary_suspects.py [--write] - near misses whose score is probably a split artifact, not a difference in the code.

  .venv/bin/python scripts/matching/boundary_suspects.py            prints them
  .venv/bin/python scripts/matching/boundary_suspects.py --write    writes work/matching/boundary_suspects.tsv (the search tools skip these)

The split ends a function at the last `jr $ra` it sees, and sometimes before the delay slot or the whole epilogue. Two shapes, both seen:
  * `delay slot cut`: the function's last word is a `jr $ra`, so retail's `addiu $sp,$sp,N` (its delay slot) is the first word of the next piece
    (func_001C7B08, SelectCoinLootDef: 44 of 44 instructions identical, score 1, fixed by moving the boundary). The next piece is a fragment or
    a function that starts with a positive `addiu $sp,$sp,N`.
  * `epilogue tail`: a piece of 8 to 16 bytes that is only the end of the function above (`jr $ra` with an `addiu $sp,$sp,N`, loads of saved
    registers, no prologue): 11 of the 26 SDK-range near misses at score 1 to 5 were this, and the function above them is still `library`.
A search spends its whole budget on these and cannot find a source for them. The fix is a boundary (`split_boundary.py`, `merges.tsv`), done by hand."""
import argparse
import csv
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
LAB = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
OUTPUT = os.path.join(LAB, 'work', 'matching', 'boundary_suspects.tsv')
JR_RA = 0x03E00008
ADDIU_SP = 0x27BD0000


def is_positive_stack_pop(word):
    """`addiu $sp,$sp,N` with N > 0: the epilogue's stack release."""
    return word & 0xFFFF0000 == ADDIU_SP and 0 < word & 0xFFFF < 0x8000


def is_stack_push(word):
    """`addiu $sp,$sp,-N`: a prologue."""
    return word & 0xFFFF0000 == ADDIU_SP and word & 0x8000


def suspects(rows, words, base):
    """[(address, name, size, reason)] for the registry rows (address, size, name) whose code is cut at a boundary. `words` is the executable's code
    from `base`; a row outside it is skipped."""
    ordered = sorted(rows)
    found = []

    def word_at(address):
        index = (address - base) // 4
        return words[index] if 0 <= index < len(words) else None

    for position, (address, size, name) in enumerate(ordered):
        if size < 4 or size % 4:
            continue
        last = word_at(address + size - 4)
        following = ordered[position + 1] if position + 1 < len(ordered) else None
        if last == JR_RA and following and following[0] == address + size and size > 16:
            first_after = word_at(following[0])
            if first_after is not None and is_positive_stack_pop(first_after):
                found.append((address, name, size, f'delay slot cut: ends at a jr $ra, the next piece {following[0]:#x} starts with addiu $sp,$sp,N'))
        if size <= 16:
            piece = [word_at(address + offset) for offset in range(0, size, 4)]
            if None not in piece and JR_RA in piece and any(is_positive_stack_pop(word) for word in piece) and not any(is_stack_push(word) for word in piece):
                found.append((address, name, size, 'epilogue tail: only the end of the function above (jr $ra, addiu $sp,$sp,N, no prologue)'))
    return found


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--write', action='store_true')
    arguments = parser.parse_args()
    import callee_sigs
    base, words = callee_sigs.load_code()
    with open(REGISTRY, encoding='utf-8') as handle:
        rows = [(int(row['address'], 16), int(row['size']), row['name']) for row in csv.DictReader(handle, delimiter='\t') if row['size']]
    found = suspects(rows, words, base)
    for address, name, size, reason in found:
        print(f'{address:#08x} {name} ({size} bytes): {reason}')
    print(f'{len(found)} boundary suspects')
    if arguments.write:
        os.makedirs(os.path.dirname(OUTPUT), exist_ok=True)
        with open(OUTPUT, 'w', encoding='utf-8', newline='') as handle:
            writer = csv.writer(handle, delimiter='\t', lineterminator='\n')
            writer.writerow(['address', 'name', 'size', 'reason'])
            for address, name, size, reason in found:
                writer.writerow([f'{address:#x}', name, size, reason])
        print(f'wrote {OUTPUT}')


if __name__ == '__main__':
    main()
