#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""boundaries.py - functions the split cut in two, found by branches that cross a boundary, and the merged sizes for the registry.

  .venv/bin/python scripts/matching/boundaries.py find [--write]    list (and with --write record) the groups in config/matching/merges.tsv
  .venv/bin/python scripts/matching/boundaries.py apply             rewrite data/matching/functions.tsv with the merges (functions.py does it too)

The split ends a function at its last `jr $ra` it can see, so a function with an early return, or whose switch cases lie behind a
second return, comes out as several "functions". Retail's compiler produced one: a conditional branch in one piece lands inside another,
and the other branches back. A piece of the registry with the wrong size can never match, and a source written for the whole function is
compared with a part of it. Evidence for a merge: a conditional branch (or a plain `b`) whose target lies in another function but not at
its first instruction (a branch to a first instruction is a tail call). Pieces connected that way, and every function between them, form
one group; the sidecar file lists each group as lead address, end address, members and the evidence, and `functions.py` applies it when
it rebuilds the registry. Functions of the SDK range are left alone (their objects come from Sony's libraries)."""
import argparse
import bisect
import csv
import os
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
REGISTRY = os.path.join(LAB, 'data', 'matching', 'functions.tsv')
MERGES = os.path.join(LAB, 'config', 'matching', 'merges.tsv')
FIELDS = ['lead', 'end', 'members', 'evidence']


def read_registry():
    with open(REGISTRY, encoding='utf-8') as handle:
        reader = csv.DictReader(handle, delimiter='\t')
        return reader.fieldnames, list(reader)


def read_merges():
    if not os.path.exists(MERGES):
        return []
    with open(MERGES, encoding='utf-8') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def apply_merges(rows, merges):
    """The registry rows with each merge group folded into its lead: the lead takes the whole span, the other members are dropped.
    A lead that already has the merged size (the registry was merged before) is left as it is."""
    by_address = {int(row['address'], 16): row for row in rows}
    dropped = set()
    for merge in merges:
        lead, end = int(merge['lead'], 16), int(merge['end'], 16)
        if lead not in by_address:
            continue
        if by_address[lead]['size'] != str(end - lead):
            by_address[lead]['size'] = str(end - lead)
            by_address[lead]['best'] = ''  # a score kept from the old, partial size says nothing about the whole function
        for member in merge['members'].split(','):
            address = int(member, 16)
            if address != lead:
                dropped.add(address)
    return [row for row in rows if int(row['address'], 16) not in dropped]


def crossings(rows):
    """[(branch address, target address, owner start)] for each conditional or unconditional branch (not a call) whose target is inside
    another function and not at its start."""
    import callee_sigs
    base, words = callee_sigs.load_code()
    functions = sorted((int(row['address'], 16), int(row['size']), row['status']) for row in rows if row['size'])
    starts = [function[0] for function in functions]
    found = []
    for address, size, status in functions:
        if status == 'library':
            continue
        first = (address - base) // 4
        for index in range(first, min(first + size // 4, len(words))):
            instruction = callee_sigs.decode(words[index])
            if not instruction.isBranch() or instruction.isJump():
                continue
            target = base + index * 4 + 4 + instruction.getBranchOffset()
            if address <= target < address + size:
                continue
            position = bisect.bisect_right(starts, target) - 1
            if position >= 0 and starts[position] != target and functions[position][2] != 'library':
                found.append((base + index * 4, target, starts[position], address))  # (target may be in a gap after starts[position]'s end)
    return found


def groups_of(rows, found):
    """Connected groups of function starts, widened to cover every function between their first and last member."""
    parent = {}

    def root(item):
        parent.setdefault(item, item)
        while parent[item] != item:
            parent[item] = parent[parent[item]]
            item = parent[item]
        return item

    for _branch, _target, owner, source in found:
        parent[root(owner)] = root(source)
    components = {}
    for item in list(parent):
        components.setdefault(root(item), []).append(item)
    functions = sorted((int(row['address'], 16), int(row['size'])) for row in rows if row['size'])
    result = []
    starts = [start for start, _ in functions]
    ends = {start: start + size for start, size in functions}
    for members in components.values():
        low, high = min(members), max(members)
        span = [start for start in starts if low <= start <= high]
        end = ends[high]
        following = starts[starts.index(high) + 1] if starts.index(high) + 1 < len(starts) else end
        if any(end <= target < following for _branch, target, _owner, source in found if low <= source <= high):
            end = following  # a branch lands in the gap after the last piece: the split lost the end of the function
        result.append((low, end, span))
    return sorted(result)


def find(arguments):
    _fields, rows = read_registry()
    rows = apply_merges(rows, read_merges())  # a group already merged does not show up again
    found = crossings(rows)
    groups = groups_of(rows, found)
    status = {int(row['address'], 16): row for row in rows}
    print(f'{len(found)} crossing branches, {len(groups)} groups')
    records = []
    for low, end, span in groups:
        evidence = '; '.join(f'{branch:#x}->{target:#x}' for branch, target, owner, source in found if low <= owner <= end and low <= source <= end)
        print(f'{low:#x}-{end:#x} ({end - low} bytes): ' + ', '.join(f'{status[member]["name"][:28]} [{status[member]["status"]}]' for member in span))
        records.append({'lead': f'{low:#x}'.upper().replace('0X', '0x'), 'end': f'{end:#x}'.upper().replace('0X', '0x'),
                        'members': ','.join(f'{member:#x}'.upper().replace('0X', '0x') for member in span), 'evidence': evidence})
    if arguments.write:
        merges = read_merges()
        known = {merge['lead'] for merge in merges}
        merges += [record for record in records if record['lead'] not in known]
        os.makedirs(os.path.dirname(MERGES), exist_ok=True)
        with open(MERGES, 'w', encoding='utf-8', newline='') as handle:
            writer = csv.DictWriter(handle, FIELDS, delimiter='\t', lineterminator='\n')
            writer.writeheader()
            writer.writerows(merges)
        print(f'{len(merges)} groups in {MERGES}')


def apply(_arguments):
    fields, rows = read_registry()
    merged = apply_merges(rows, read_merges())
    with open(REGISTRY, 'w', encoding='utf-8', newline='') as handle:
        writer = csv.DictWriter(handle, fields, delimiter='\t', lineterminator='\n')
        writer.writeheader()
        writer.writerows(merged)
    print(f'{len(rows)} -> {len(merged)} functions')


def main():
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest='command', required=True)
    finder = sub.add_parser('find')
    finder.add_argument('--write', action='store_true')
    sub.add_parser('apply')
    arguments = parser.parse_args()
    {'find': find, 'apply': apply}[arguments.command](arguments)
    return 0


if __name__ == '__main__':
    sys.exit(main())
