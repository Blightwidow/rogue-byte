#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""flag_report.py [FILE] - what scripts/matching/flag_sweep.py found, per variant and per module.

For every variant: of the unmatched functions how many get a lower score than under the base flags (and how many reach 0), and of the
matched control sample how many stop matching. A module is a candidate for a variant when some of its unmatched functions improve under it
and none of its matched ones (in the sample) break."""
import collections
import os
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, 'work', 'matching', 'flagsweep.tsv')
scores = collections.defaultdict(dict)
meta = {}
for line in open(path):
    address, module, status, variant, score = line.rstrip('\n').split('\t')
    scores[address][variant] = int(score) if score else None
    meta[address] = (module, status)
overall = collections.defaultdict(collections.Counter)
modules = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))
for address, by_variant in scores.items():
    base = by_variant.get('base')
    module, status = meta[address]
    if base is None:
        continue
    for variant, score in by_variant.items():
        if variant == 'base':
            continue
        if status == 'tried':
            if score is not None and score < base:
                overall[variant]['better'] += 1
                modules[module][variant]['better'] += 1
                if score == 0:
                    overall[variant]['to0'] += 1
                    modules[module][variant]['to0'] += 1
            elif score is None or score > base:
                overall[variant]['worse'] += 1
        elif base == 0:
            kept = score == 0
            overall[variant]['kept' if kept else 'broken'] += 1
            modules[module][variant]['kept' if kept else 'broken'] += 1
print(f'{"variant":14} {"better":>7} {"to 0":>5} {"worse":>6} | {"kept":>5} {"broken":>6}   (unmatched | matched control)')
for variant, count in sorted(overall.items(), key=lambda item: -item[1]['better']):
    print(f'{variant:14} {count["better"]:7} {count["to0"]:5} {count["worse"]:6} | {count["kept"]:5} {count["broken"]:6}')
print('\ncandidate modules (improved, no control broken):')
for module, by_variant in sorted(modules.items()):
    for variant, count in sorted(by_variant.items()):
        if count['better'] and not count['broken']:
            print(f'  {module:28} {variant:14} better {count["better"]} to0 {count["to0"]} kept {count["kept"]}')
