#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/check.py - call-graph consistency of config/recovered/matches.tsv: for each match whose Sly 1 function calls other matched
functions, the share of those callees whose match is called by the Sly 2 function too. Correct matches agree."""
import collections, csv, json
def load(p): return {f['entry']: f for f in map(json.loads, open(p))}
sly1, sly2 = load('work/export/sly1.jsonl'), load('work/export/sly2.jsonl')
rows = list(csv.DictReader(open('config/recovered/matches.tsv'), delimiter='\t'))
forward = {int(r['sly1_entry'], 16): int(r['sly2_entry'], 16) for r in rows}
by_method = collections.defaultdict(list)
for r in rows:
    e1, e2 = int(r['sly1_entry'], 16), int(r['sly2_entry'], 16)
    mapped = [forward[c] for c in set(sly1[e1]['calls']) if c in forward]
    if len(mapped) < 2:
        continue
    agree = sum(1 for m in mapped if m in set(sly2[e2]['calls'])) / len(mapped)
    by_method[r['method']].append(agree)
print('method    checkable  mean-agree  share>=0.8  share<0.5')
for m, v in sorted(by_method.items()):
    print(f'{m:9} {len(v):9}  {sum(v)/len(v):10.2f}  {sum(x>=0.8 for x in v)/len(v):10.2f}  {sum(x<0.5 for x in v)/len(v):9.2f}')
