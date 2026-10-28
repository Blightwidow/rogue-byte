#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/sly2_only.py - a map of the code Sly 2 has and Sly 1 doesn't.

  python3 scripts/names/sly2_only.py config/recovered/

A Sly 2 function counts as Sly 2-only when it has no Sly 1 match (config/recovered/matches.tsv), sits outside the SDK block, and its
best BSim cosine against every Sly 1 function is low (under 0.3: unrelated pairs reach that 1% of the time, true pairs
whose code changed mostly stay above it). Functions of one source file sit together in the binary, so consecutive
Sly 2-only functions (at most 2 matched or library functions in between) form a cluster: a likely new source file or
system. Each cluster is labelled with what we know about it: the Rust port's module for functions inside it
(config/recovered/bevy_functions.tsv), the strings its functions reference, the names of the functions it calls, and the Sly 2
classes whose vtables point into it (class table at 0x2BAAE8).

Writes config/recovered/sly2_only.tsv (one row per function) and config/recovered/sly2_only.md (clusters, largest first).
"""
import collections
import csv
import importlib.util
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
SDK_START, SDK_END = 0x2319E8, 0x256CE8
NEW_COSINE = 0.3
GAP = 2


def load_module(name):
    spec = importlib.util.spec_from_file_location(name, os.path.join(HERE, f'{name}.py'))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def best_cosines(sly1, sly2, match, common=400):
    """For each Sly 2 function: the best cosine against any Sly 1 function (index shortlist, exact cosine)."""
    index = collections.defaultdict(list)
    for entry, function in sly1.items():
        for feature in function.get('bsim', {}):
            index[feature].append(entry)
    best = {}
    for entry, function in sly2.items():
        vector = function.get('bsim')
        if not vector:
            continue
        totals = collections.Counter()
        for feature, x in vector.items():
            postings = index.get(feature, ())
            if len(postings) <= common:
                for other in postings:
                    totals[other] += x * sly1[other]['bsim'][feature]
        shortlist = [match.cosine(vector, sly1[other]['bsim']) for other, _ in totals.most_common(5)]
        best[entry] = max(shortlist) if shortlist else 0.0
    return best


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    out = sys.argv[1]
    match, diff = load_module('match'), load_module('class_diff')
    sly1, sly2 = match.load('work/export/sly1.jsonl'), match.load('work/export/sly2.jsonl')
    match.load_bsim(['work/export/sly1_bsim.jsonl', 'work/export/sly2_bsim.jsonl'], sly1, sly2)
    with open(os.path.join(out, 'matches.tsv'), encoding='utf-8') as f:
        matched = {int(r['sly2_entry'], 16) for r in csv.DictReader(f, delimiter='\t')}
    bevy = {}
    with open(os.path.join(out, 'bevy_functions.tsv'), encoding='utf-8') as f:
        for r in csv.DictReader(f, delimiter='\t'):
            bevy[int(r['address'], 16)] = (r['name'], r['file'].removesuffix('.rs').removeprefix('engine/'))
    names = {}
    with open(os.path.join(out, 'sly2_combined_symbol_addrs.txt'), encoding='utf-8') as f:
        for line in f:
            m = re.match(r'^(\S+) = (0x[0-9A-F]+);', line)
            if m:
                names[int(m.group(2), 16)] = m.group(1)
    classes = diff.sly2_classes(diff.Image('work/elf/SCUS_973.16'), sly2)
    class_of = collections.defaultdict(set)
    for cid, record in classes.items():
        for slot in record['slots']:
            class_of[slot].add(cid)

    cosine = best_cosines(sly1, sly2, match)
    order = sorted(sly2)
    status = {}
    for entry in order:
        if SDK_START <= entry < SDK_END:
            status[entry] = 'sdk'
        elif entry in matched:
            status[entry] = 'matched'
        elif cosine.get(entry, 0.0) < NEW_COSINE:
            status[entry] = 'new'
        else:
            status[entry] = 'unmatched-similar'

    clusters, current, gap = [], [], 0
    for entry in order:
        if status[entry] == 'new':
            current.append(entry)
            gap = 0
        elif current:
            gap += 1
            if gap > GAP:
                clusters.append(current)
                current, gap = [], 0
    if current:
        clusters.append(current)

    def describe(cluster):
        modules = collections.Counter(bevy[e][1] for e in cluster if e in bevy)
        strings = collections.Counter(s for e in cluster for s in set(sly2[e]['strings']))
        callees = collections.Counter(names[c].split('__')[0] for e in cluster for c in set(sly2[e]['calls'])
                                      if c in names and not names[c].startswith('bevy_'))
        cids = collections.Counter(cid for e in cluster for cid in class_of.get(e, ()))
        size = sum(len(sly2[e]['words']) for e in cluster)
        return modules, strings, callees, cids, size

    with open(os.path.join(out, 'sly2_only.tsv'), 'w', encoding='utf-8') as f:
        f.write('sly2_entry\tstatus\tbest_cosine\tinstructions\tbevy_module\n')
        for entry in order:
            f.write(f"0x{entry:X}\t{status[entry]}\t{cosine.get(entry, 0.0):.3f}\t{len(sly2[entry]['words'])}\t{bevy.get(entry, ('', ''))[1]}\n")

    counts = collections.Counter(status.values())
    new_total = counts['new']
    ranked = sorted(clusters, key=lambda c: -sum(len(sly2[e]['words']) for e in c))
    lines = ['# Sly 2-only code', '',
             f"Of {len(order)} Sly 2 functions: {counts['matched']} matched to Sly 1, {counts['sdk']} in the SDK block, "
             f"{counts['unmatched-similar']} unmatched but similar to some Sly 1 function (best BSim cosine >= {NEW_COSINE}: likely "
             f"changed counterparts not found yet), **{new_total} Sly 2-only** (best cosine under {NEW_COSINE}).", '',
             f"{len(clusters)} clusters of consecutive Sly 2-only functions (likely new source files or systems), "
             f"{sum(1 for c in clusters if len(c) >= 10)} with 10 or more functions. Largest first; labels come from the "
             'Rust port\'s modules, referenced strings, named callees and the classes whose vtables point in.', '',
             '| # | Address range | Functions | Instructions | Rust port modules | Calls (named) | Classes (cid) | Strings |',
             '|---|---|---|---|---|---|---|---|']
    for number, cluster in enumerate(ranked[:40], 1):
        modules, strings, callees, cids, size = describe(cluster)
        cell = lambda counter, k=3: ', '.join(f'{name}' for name, _ in counter.most_common(k)).replace('|', '/') or '-'
        strings_cell = ', '.join(s[:24] for s, _ in strings.most_common(2)).replace('|', '/').replace('\n', ' ') or '-'
        lines.append(f"| {number} | 0x{cluster[0]:X}-0x{cluster[-1]:X} | {len(cluster)} | {size} | {cell(modules)} | "
                     f"{cell(callees)} | {cell(cids, 4)} | {strings_cell} |")
    with open(os.path.join(out, 'sly2_only.md'), 'w', encoding='utf-8') as f:
        f.write('\n'.join(lines) + '\n')
    print(lines[2])
    print(lines[4])


if __name__ == '__main__':
    main()
