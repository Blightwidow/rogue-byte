#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/field_layout.py - maps struct field offsets from Sly 1 to Sly 2 through the matched functions.

  python3 scripts/names/field_layout.py config/recovered/

Inputs: work/export/sly1_fields.jsonl and work/export/sly2_fields.jsonl (ExportFieldAccesses.java), config/recovered/matches.tsv (scripts/names/match.py).
For every matched pair, the field accesses through the same parameter are aligned in p-code order on their shape
(load/store/address, size, value kind); each aligned pair votes "STRUCT+off1 in Sly 1 is STRUCT+off2 in Sly 2". Votes
are weighted by the match's trust (exact and call-graph matches count more than fuzzy ones).

A field's mapping is kept when it sits in a block of consecutive fields with the same shift (fields move in blocks: a
member added in Sly 2 shifts what follows by the same amount), or alone with strong evidence; see `decide`.

Outputs config/recovered/field_map.tsv (struct, sly1 offset, sly2 offset, votes, share, shape) and a summary per struct.
"""
import collections
import csv
import difflib
import json
import os
import sys

TRUST = {'exact': 3.0, 'strings': 2.0, 'calls': 2.0, 'callers': 2.0, 'bsim': 1.5, 'vtable': 1.0, 'global': 1.0, 'class': 0.5}


def load_accesses(path):
    by_function = {}
    with open(path, encoding='utf-8') as f:
        for line in f:
            record = json.loads(line)
            by_function[record['entry']] = record['accesses']
    return by_function


def by_slot(accesses):
    slots = collections.defaultdict(list)
    for slot, struct, offset, size, kind, value in accesses:
        slots[slot].append((struct, offset, size, kind, value))
    return slots


def votes_for_pair(accesses1, accesses2, weight, votes):
    slots1, slots2 = by_slot(accesses1), by_slot(accesses2)
    for slot, list1 in slots1.items():
        list2 = slots2.get(slot)
        if not list2:
            continue
        shape1 = [(kind, size, value) for _, _, size, kind, value in list1]
        shape2 = [(kind, size, value) for _, _, size, kind, value in list2]
        matcher = difflib.SequenceMatcher(None, shape1, shape2, autojunk=False)
        for block in matcher.get_matching_blocks():
            for k in range(block.size):
                struct1, offset1, size, kind, value = list1[block.a + k]
                struct2, offset2, *_ = list2[block.b + k]
                if struct1 != struct2:
                    continue  # repaired or retyped slot: the struct itself differs
                votes[struct1][offset1][(offset2, size, value)] += weight


def decide(votes, single_votes=4, single_share=0.9):
    """Per struct: {offset1: (offset2, votes, share, size, value)}. Fields move in blocks (a member added or removed in
    Sly 2 shifts what follows by the same amount), so a mapping is kept when it sits in a block: two or more consecutive
    Sly 1 fields with the same shift. A lone field needs strong evidence. Misaligned targets are dropped: they come from
    sequence alignment slipping, not from the game."""
    decided = {}
    for struct, fields in votes.items():
        best = {}
        for offset1, candidates in fields.items():
            (offset2, size, value), count = candidates.most_common(1)[0]
            if size and offset2 % min(size, 4):
                continue
            best[offset1] = (offset2, count, count / sum(candidates.values()), size, value)
        ordered = sorted(best.items())
        kept = {}
        index = 0
        while index < len(ordered):
            shift = ordered[index][1][0] - ordered[index][0]
            end = index
            while end + 1 < len(ordered) and ordered[end + 1][1][0] - ordered[end + 1][0] == shift:
                end += 1
            block = ordered[index:end + 1]
            if len(block) >= 2:
                kept.update(block)
            else:
                offset1, (offset2, count, share, size, value) = block[0]
                if count >= single_votes and share >= single_share:
                    kept[offset1] = block[0][1]
            index = end + 1
        decided[struct] = kept
    return decided


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    out = sys.argv[1]
    fields1 = load_accesses('work/export/sly1_fields.jsonl')
    fields2 = load_accesses('work/export/sly2_fields.jsonl')
    votes = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))
    pairs = 0
    with open(os.path.join(out, 'matches.tsv'), encoding='utf-8') as f:
        for row in csv.DictReader(f, delimiter='\t'):
            entry1, entry2 = int(row['sly1_entry'], 16), int(row['sly2_entry'], 16)
            if entry1 in fields1 and entry2 in fields2:
                pairs += 1
                votes_for_pair(fields1[entry1], fields2[entry2], TRUST.get(row['method'], 1.0), votes)
    decided = decide(votes)
    with open(os.path.join(out, 'field_map.tsv'), 'w', encoding='utf-8') as f:
        f.write('struct\tsly1_offset\tsly2_offset\tshift\tvotes\tshare\tsize\tvalue\n')
        for struct in sorted(decided):
            for offset1, (offset2, n, share, size, value) in sorted(decided[struct].items()):
                f.write(f'{struct}\t0x{offset1:X}\t0x{offset2:X}\t{offset2 - offset1:+#x}\t{n:g}\t{share:.2f}\t{size}\t{value}\n')
    total = sum(len(v) for v in decided.values())
    print(f'{pairs} matched pairs with field accesses on both sides; {total} fields mapped in {sum(1 for v in decided.values() if v)} structs')
    ranked = sorted(decided.items(), key=lambda kv: -len(kv[1]))[:15]
    for struct, mapping in ranked:
        shifts = collections.Counter(o2 - o1 for o1, (o2, *_) in mapping.items())
        print(f'  {struct:10} {len(mapping):4} fields  shifts {", ".join(f"{s:+#x}x{c}" for s, c in shifts.most_common(4))}')


if __name__ == '__main__':
    main()
