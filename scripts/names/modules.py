#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/modules.py - cuts Sly 2 into modules that follow source files, and modules into batches of contiguous functions.

  python3 scripts/names/modules.py config/recovered/

Sly 1's source files come from the decomp's splat layout (config/sly1/sly1.yaml: file offset + 0xFF000 = address), so each
Sly 1 function has a file. Sly 2 keeps a file's functions together and in order, so:
  matched function            its Sly 1 counterpart's file
  unmatched, same file on both sides   that file
  unmatched, Sly 2-only cluster (config/recovered/sly2_only.tsv, a run with no file on either side)   new_<first address>
  unmatched at a file boundary          <file before>+<file after>
  0x2319E8-0x256CE8                     sdk
Batches are contiguous address windows of at most 40 functions or 4,000 instructions, breaking at
a module change only past 10 functions (small fragments of other files stay with their neighbours), never across the
SDK edge, and named after their most common module.

Writes config/recovered/modules.tsv (entry, module, batch) and config/recovered/batches.json (batch -> entries), and prints a summary.

Frozen: the units of config/us and the folders of src/ are named after config/recovered/modules.tsv, so re-cutting would rename them.
It has been edited since (the game-code tail of the SDK range was appended as sdktail#1/#2); don't rerun this on it.
"""
import bisect
import collections
import csv
import json
import os
import re
import sys

SDK_START, SDK_END = 0x2319E8, 0x254CA0  # library code ends at 0x254CA0; the tail up to 0x256CE8 is game code (2026-10-21)
FILE_OFFSET_TO_ADDRESS = 0xFF000
BATCH_FUNCTIONS, BATCH_INSTRUCTIONS, MIN_BATCH = 40, 4000, 10


def sly1_files(path):
    starts = []
    for line in open(path, encoding='utf-8'):
        m = re.match(r'^\s+- \[(0x[0-9A-Fa-f]+), (c|cpp|asm|s), ([^\],]+)', line)
        if m:
            starts.append((int(m.group(1), 16) + FILE_OFFSET_TO_ADDRESS, m.group(3).strip().removeprefix('P2/')))
    starts.sort()
    return starts


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    out = sys.argv[1]
    files = sly1_files('config/sly1/sly1.yaml')
    file_starts = [a for a, _ in files]

    def file_of(entry1):
        position = bisect.bisect_right(file_starts, entry1) - 1
        return files[position][1] if position >= 0 else None

    sly2 = {f['entry']: len(f['words']) for f in map(json.loads, open('work/export/sly2.jsonl', encoding='utf-8'))}
    with open(os.path.join(out, 'matches.tsv'), encoding='utf-8') as f:
        counterpart = {int(r['sly2_entry'], 16): int(r['sly1_entry'], 16) for r in csv.DictReader(f, delimiter='\t')}
    with open(os.path.join(out, 'sly2_only.tsv'), encoding='utf-8') as f:
        only = {int(r['sly2_entry'], 16) for r in csv.DictReader(f, delimiter='\t') if r['status'] == 'new'}
    order = sorted(sly2)
    known = {}
    for entry in order:
        if SDK_START <= entry < SDK_END:
            known[entry] = 'sdk'
        elif entry in counterpart:
            known[entry] = file_of(counterpart[entry])

    module = {}
    index = 0
    while index < len(order):
        entry = order[index]
        if entry in known:
            module[entry] = known[entry]
            index += 1
            continue
        end = index
        while end < len(order) and order[end] not in known:
            end += 1
        before = known.get(order[index - 1]) if index > 0 else None
        after = known.get(order[end]) if end < len(order) else None
        run = order[index:end]
        if before and before == after:
            name = before
        elif sum(1 for e in run if e in only) * 2 >= len(run):
            name = f'new_{run[0]:06x}'
        else:
            name = f'{before or "start"}+{after or "end"}'
        for e in run:
            module[e] = name
        index = end

    # Batches are contiguous address windows: Sly 2 interleaves small fragments of other files (a function matched into
    # another Sly 1 file), so a batch only breaks at a module change once it has MIN_BATCH functions; it is named after
    # its most common module.
    batches = collections.OrderedDict()
    counter = collections.Counter()
    current, size = [], 0

    def flush():
        nonlocal current, size
        if current:
            name = collections.Counter(module[e] for e in current).most_common(1)[0][0]
            counter[name] += 1
            batches[f'{name}#{counter[name]}'] = current
        current, size = [], 0

    for entry in order:
        full = len(current) >= BATCH_FUNCTIONS or size + sly2[entry] > BATCH_INSTRUCTIONS
        boundary = current and module[entry] != module[current[-1]] and len(current) >= MIN_BATCH
        sdk_edge = current and (module[entry] == 'sdk') != (module[current[-1]] == 'sdk')
        if full or boundary or sdk_edge:
            flush()
        current.append(entry)
        size += sly2[entry]
    flush()
    batch_of = {e: b for b, entries in batches.items() for e in entries}

    with open(os.path.join(out, 'modules.tsv'), 'w', encoding='utf-8') as f:
        f.write('sly2_entry\tmodule\tbatch\tinstructions\n')
        for entry in order:
            f.write(f'0x{entry:X}\t{module[entry]}\t{batch_of[entry]}\t{sly2[entry]}\n')
    with open(os.path.join(out, 'batches.json'), 'w', encoding='utf-8') as f:
        json.dump({b: [f'0x{e:X}' for e in entries] for b, entries in batches.items()}, f, indent=0)

    kinds = collections.Counter()
    for entry in order:
        name = module[entry]
        kind = 'sdk' if name == 'sdk' else 'new' if name.startswith('new_') else 'boundary' if '+' in name else 'file'
        kinds[kind] += 1
    modules_by_kind = collections.Counter('sdk' if m == 'sdk' else 'new' if m.startswith('new_') else 'boundary' if '+' in m else 'file' for m in set(module.values()))
    print(f'{len(order)} functions in {len(set(module.values()))} modules and {len(batches)} batches')
    print('functions by kind:', dict(kinds), '| modules by kind:', dict(modules_by_kind))
    biggest = collections.Counter(module.values()).most_common(12)
    print('largest modules:', ', '.join(f'{m} ({n})' for m, n in biggest))


if __name__ == '__main__':
    main()
