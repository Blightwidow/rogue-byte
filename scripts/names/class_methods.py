#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/class_methods.py - matches methods inside the class pairs of the class diff, in vtable order.

  python3 scripts/names/class_methods.py config/recovered/ [--evaluate]

For each Sly 2 class mapped to a Sly 1 class (config/recovered/class_diff.tsv, confidence high or medium), the class's own methods
on both sides are listed in slot order and aligned by scripts/names/match.py's monotone alignment on its score: a class keeps the
relative order of its virtual methods between the games even where the slot numbers moved (only 4 Sly 1 slots map
globally: Init 0 -> 6, LoadFromBrx 10 -> 13, PostLoad 16 -> 14, Update 17 -> 15). Each pair also needs BSim cosine
>= 0.3 and passes scripts/names/match.py's vetoes (method 'slot': size ratio, call count, SDK block).

--evaluate: blind test on the own-method pairs other passes already matched inside mapped classes: hide them and see
whether the alignment pairs them the same way. Without it: writes config/recovered/class_method_pairs.tsv, which scripts/names/match.py reads as
seeds (method 'slot') before its rounds.
"""
import csv
import importlib.util
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))


def load_module(name):
    spec = importlib.util.spec_from_file_location(name, os.path.join(HERE, f'{name}.py'))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def own_methods(record, parent, classes_slots_of_parent):
    slots = record['slots']
    parent_slots = classes_slots_of_parent or []
    return [s for k, s in enumerate(slots) if s and (k >= len(parent_slots) or parent_slots[k] != s)]


def main():
    if len(sys.argv) not in (2, 3):
        sys.exit(__doc__)
    out = sys.argv[1]
    evaluate = len(sys.argv) == 3 and sys.argv[2] == '--evaluate'
    match, diff = load_module('match'), load_module('class_diff')
    sly1, sly2 = match.load('work/export/sly1.jsonl'), match.load('work/export/sly2.jsonl')
    match.load_bsim(['work/export/sly1_bsim.jsonl', 'work/export/sly2_bsim.jsonl'], sly1, sly2)
    classes1 = diff.sly1_classes(diff.Image('work/elf/SCUS_971.98'), sly1)
    classes2 = diff.sly2_classes(diff.Image('work/elf/SCUS_973.16'), sly2)
    by_name1 = {}
    for record in classes1.values():
        if record['name']:
            by_name1.setdefault(record['name'], record)
    pairs = []
    with open(os.path.join(out, 'class_diff.tsv'), encoding='utf-8') as f:
        for row in csv.DictReader(f, delimiter='\t'):
            if row['confidence'] in ('high', 'medium') and row['sly1_class'] in by_name1:
                pairs.append((classes2[int(row['cid'])], by_name1[row['sly1_class']], row['confidence']))
    matcher = match.Matcher(sly1, sly2)
    with open(os.path.join(out, 'matches.tsv'), encoding='utf-8') as f:
        known = [(int(r['sly1_entry'], 16), int(r['sly2_entry'], 16), r['method']) for r in csv.DictReader(f, delimiter='\t')]
    own = []
    for record2, record1, confidence in pairs:
        parent2 = classes2.get(record2['parent'])
        parent1 = classes1.get(record1['parent_vtable'])
        own.append((own_methods(record2, parent2, parent2['slots'] if parent2 else None),
                    own_methods(record1, parent1, parent1['slots'] if parent1 else None), confidence, record2['cid'], record1['name']))

    def align(hidden=frozenset()):
        matcher.forward, matcher.backward = {}, {}
        for entry1, entry2, method in known:
            if (entry1, entry2) not in hidden:
                matcher.forward[entry1] = entry2
                matcher.backward[entry2] = (entry1, method, 1.0)
        proposals = []
        for methods2, methods1, confidence, cid, name in own:
            xs = [e for e in dict.fromkeys(methods1) if e not in matcher.forward]
            ys = [e for e in dict.fromkeys(methods2) if e not in matcher.backward]
            if not xs or not ys:
                continue
            for x, y in matcher.monotone_alignment(xs, ys, 0.5):
                if matcher.cosine_of(x, y) >= 0.3 and not matcher.veto(x, y, 'slot'):
                    proposals.append((x, y, round(matcher.score(x, y), 3), cid, name, confidence))
        return proposals

    if evaluate:
        inside = {(e1, e2) for e1, e2, _m in known if any(e2 in m2 and e1 in m1 for m2, m1, *_ in own)}
        got = align(frozenset(inside))
        recovered = {(x, y) for x, y, *_ in got}
        right = len(recovered & inside)
        wrong = sum(1 for x, y, *_ in got if (x, y) not in inside and any(x == a for a, _b in inside))
        print(f'{len(inside)} already-matched own-method pairs inside mapped classes hidden; alignment re-pairs '
              f'{right} the same way, {wrong} differently; {len(got)} proposals in all')
        return
    proposals = align()
    with open(os.path.join(out, 'class_method_pairs.tsv'), 'w', encoding='utf-8') as f:
        f.write('sly2_entry\tsly1_entry\tname\tscore\tcid\tclass\tconfidence\n')
        for x, y, score, cid, name, confidence in proposals:
            f.write(f'0x{y:X}\t0x{x:X}\t{sly1[x]["name"] or ""}\t{score}\t{cid}\t{name}\t{confidence}\n')
    print(f'{len(pairs)} class pairs, {len(proposals)} new method pairs ({sum(1 for p in proposals if sly1[p[0]]["name"])} named)')


if __name__ == '__main__':
    main()
