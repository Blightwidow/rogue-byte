#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/class_diff.py - the class-by-class diff between Sly 1 and Sly 2, the map for one shared engine.

  python3 scripts/names/class_diff.py config/recovered/

Sly 2 keeps a class table at 0x2BAAE8: 199 records of 0x14 bytes (parent record, cid, cid end, sizeof, factory). Each
factory allocates sizeof bytes and stores the class vtable at +0xC; slot k's method pointer is at vtable + 0xC + 8k
(2026-10-20, checked: 198/198 parent links nest, children are never smaller).
Sly 1's vtables carry a 16-byte header (parent vtable, cid, flag, sizeof) and then 4-byte method pointers.

A class's own methods are the slots that differ from its parent's. Sly 1 classes are named after the demangled class
of their own methods (InitAlo__FP3ALO -> ALO). Classes are mapped in two ways:
  role     the methods with a fixed role are matched directly between the games: Init (Sly 1 slot 0, Sly 2 slot 6) and
           LoadFromBrx (Sly 1 slot 10, Sly 2 slot 13), each Sly 2 class's own one against every Sly 1 class's own one,
           scored with scripts/names/match.py's score (callee agreement, constants, profile, BSim), assigned one-to-one best first
  votes    the Sly 1 class that most of its matched own methods belong to (config/recovered/matches.tsv)
Role matches count double; a Sly 2 class with no clear winner stays unmapped.

Each mapping gets a confidence from checks the mapping didn't use: our recovered Sly 2 layout for that class name
(config/recovered/sly2_structs.json) must fit inside the Sly 2 class size. high = ends within 0x20 of it (a random mapping lands
there 1.6 times in 30, 2026-10-20); medium = fits loosely or has no layout; rejected = overflows, or a
second Sly 2 class claimed the same Sly 1 class with more votes. Rejected mappings are listed but not used.

Per mapped class: both sizes, own methods split into identical (exact match), changed (other matches), new in Sly 2
(no Sly 1 counterpart) and Sly 1 methods not found in Sly 2, and the mapped fields (config/recovered/field_map.tsv).
Writes config/recovered/class_diff.tsv and config/recovered/class_diff.md (the tree, with the diff per class), and prints a summary.
"""
import collections
import csv
import json
import os
import re
import struct
import sys

SLY2_TABLE, SLY2_RECORDS, RECORD_SIZE = 0x2BAAE8, 199, 0x14
ROLES = {'Init': (0, 6), 'LoadFromBrx': (10, 13)}  # Sly 1 slot, Sly 2 slot (measured: 132 and 140 Sly 1 vtables agree)


class Image:
    """The loaded segments of an ELF, read by virtual address."""

    def __init__(self, path):
        data = open(path, 'rb').read()
        program_headers, = struct.unpack_from('<I', data, 0x1C)
        count, = struct.unpack_from('<H', data, 0x2C)
        self.segments = []
        for index in range(count):
            kind, offset, vaddr, _paddr, file_size = struct.unpack_from('<IIIII', data, program_headers + index * 32)
            if kind == 1:
                self.segments.append((vaddr, data[offset:offset + file_size]))

    def word(self, address):
        for vaddr, blob in self.segments:
            if vaddr <= address and address + 4 <= vaddr + len(blob):
                return struct.unpack_from('<I', blob, address - vaddr)[0]
        return None


def load_functions(path):
    return {f['entry']: f for f in map(json.loads, open(path, encoding='utf-8'))}


def owner(name):
    """The class a mangled method belongs to: Name__<n>Class... (member) or Name__FP<n>Class... (first argument)."""
    if not name or '__' not in name:
        return None
    rest = name.split('__', 1)[1]
    member = re.match(r'^(\d+)([A-Za-z_]\w*)', rest)
    if member:
        return member.group(2)[:int(member.group(1))]
    first = re.match(r'^FP(\d+)([A-Za-z_]\w*)', rest)
    if first:
        return first.group(2)[:int(first.group(1))]
    return None


def factory_vtable(image, entry, size_limit=160):
    """The constant a factory stores at +0xC of the new object, lui/addiu (or ori) pairs tracked per register. The
    last store wins: constructors run base class first, so earlier stores at +0xC are a parent's vtable (taking the
    first one agreed with the Rust port's cid -> vtable pairs 51/79 times, the last one is checked in main)."""
    high = {}
    found = None
    for index in range(size_limit):
        word = image.word(entry + 4 * index)
        if word is None:
            break
        opcode, rs, rt, immediate = word >> 26, (word >> 21) & 31, (word >> 16) & 31, word & 0xFFFF
        if opcode == 0x0F:  # lui rt, imm
            high[rt] = immediate << 16
        elif opcode in (0x09, 0x0D) and rs in high:  # addiu / ori rt, rs, imm
            value = high[rs] + (immediate - 0x10000 if opcode == 0x09 and immediate & 0x8000 else immediate)
            high[rt] = value & 0xFFFFFFFF
        elif opcode == 0x2B and immediate == 0xC and rt in high:  # sw rt, 0xc(rs)
            found = high[rt]
        elif word == 0x03E00008:  # jr ra
            break
    return found


def sly2_classes(image, functions):
    classes = {}
    by_record = {}
    for index in range(SLY2_RECORDS):
        address = SLY2_TABLE + index * RECORD_SIZE
        parent, cid, end, size, factory = (image.word(address + 4 * k) for k in range(5))
        by_record[address] = cid
        classes[cid] = {'cid': cid, 'parent_record': parent, 'end': end, 'size': size, 'factory': factory}
    for record in classes.values():
        record['parent'] = by_record.get(record['parent_record'])
        vtable = factory_vtable(image, record['factory']) if record['factory'] else None
        record['vtable'] = vtable
        slots = []
        if vtable:
            for k in range(160):
                pointer = image.word(vtable + 0xC + 8 * k)
                if pointer not in functions:
                    break
                slots.append(pointer)
        record['slots'] = slots
    return classes


def sly1_classes(image, functions):
    """Sly 1 vtables: a header (parent vtable or 0, small cid, flag, sizeof) followed by method pointers."""
    candidates = {}
    for vaddr, blob in image.segments:
        for offset in range(0, len(blob) - 24, 4):
            parent, cid, flag, size, first = struct.unpack_from('<IIIII', blob, offset)
            if cid < 0x400 and flag < 0x100 and 0 < size < 0x10000 and first in functions:
                candidates[vaddr + offset] = (parent, cid, flag, size)
    classes = {}
    starts = set(candidates)
    for address, (parent, cid, _flag, size) in candidates.items():
        if parent and parent not in candidates:
            continue
        # null slots belong to the table (unused virtuals): it ends at a pointer that isn't a function or at the next
        # vtable's header, trailing nulls dropped (stopping at the first null cut every table to the 11 LO slots)
        slots = []
        for k in range(200):
            slot_address = address + 16 + 4 * k
            if k and slot_address in starts:
                break
            pointer = image.word(slot_address)
            if pointer != 0 and pointer not in functions:
                break
            slots.append(pointer or None)
        while slots and slots[-1] is None:
            slots.pop()
        classes[address] = {'vtable': address, 'parent_vtable': parent or None, 'cid': cid, 'size': size, 'slots': slots}
    for record in classes.values():
        parent = classes.get(record['parent_vtable'])
        own = [s for k, s in enumerate(record['slots']) if s and (not parent or k >= len(parent['slots']) or parent['slots'][k] != s)]
        record['own'] = own
        # the class in its own Init or LoadFromBrx signature (InitSm__FP2SM -> SM); a majority vote over all own
        # methods names too many vtables LO, since methods are often typed with the base class
        named = None
        for slot in (0, 10):
            entry = own_slot(record, parent, slot)
            if entry and re.match(r'^(Init|Load)', functions[entry]['name'] or ''):
                named = owner(functions[entry]['name'])
                if named:
                    break
        votes = collections.Counter(owner(functions[s]['name']) for s in own if owner(functions[s]['name']))
        record['name'] = named or (votes.most_common(1)[0][0] if votes else None)
    return classes


def own_slot(record, parent, k):
    slots = record['slots']
    if k >= len(slots):
        return None
    if parent and k < len(parent['slots']) and parent['slots'][k] == slots[k]:
        return None  # inherited
    return slots[k]


def role_matches(classes1, classes2, out, threshold=0.62, margin=0.04):
    """{(sly2 cid, role): (sly1 vtable, score)} from direct Init / LoadFromBrx matching."""
    import importlib.util
    spec = importlib.util.spec_from_file_location('match', os.path.join(os.path.dirname(os.path.abspath(__file__)), 'scripts/names/match.py'))
    match = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(match)
    sly1, sly2 = match.load('work/export/sly1.jsonl'), match.load('work/export/sly2.jsonl')
    match.load_bsim(['work/export/sly1_bsim.jsonl', 'work/export/sly2_bsim.jsonl'], sly1, sly2)
    matcher = match.Matcher(sly1, sly2)
    with open(os.path.join(out, 'matches.tsv'), encoding='utf-8') as f:
        for row in csv.DictReader(f, delimiter='\t'):
            entry1, entry2 = int(row['sly1_entry'], 16), int(row['sly2_entry'], 16)
            matcher.forward[entry1] = entry2
            matcher.backward[entry2] = (entry1, row['method'], row['score'])
    found = {}
    for role, (slot1, slot2) in ROLES.items():
        side1 = {}
        for vtable, record in classes1.items():
            entry = own_slot(record, classes1.get(record['parent_vtable']), slot1)
            if entry and entry in sly1:
                side1.setdefault(entry, vtable)
        side2 = {}
        for cid, record in classes2.items():
            entry = own_slot(record, classes2.get(record['parent']), slot2)
            if entry and entry in sly2:
                side2.setdefault(entry, cid)
        scored = []
        for entry2 in side2:
            row = sorted(((matcher.score(entry1, entry2), entry1) for entry1 in side1), reverse=True)[:2]
            if row and row[0][0] >= threshold and (len(row) == 1 or row[0][0] - row[1][0] >= margin):
                scored.append((row[0][0], entry2, row[0][1]))
        used1 = set()
        for score, entry2, entry1 in sorted(scored, reverse=True):
            if entry1 in used1:
                continue
            used1.add(entry1)
            found[(side2[entry2], role)] = (side1[entry1], round(score, 3))
    return found


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    out = sys.argv[1]
    sly1 = load_functions('work/export/sly1.jsonl')
    sly2 = load_functions('work/export/sly2.jsonl')
    image1, image2 = Image('work/elf/SCUS_971.98'), Image('work/elf/SCUS_973.16')
    classes1 = sly1_classes(image1, sly1)
    classes2 = sly2_classes(image2, sly2)
    matches = {}
    with open(os.path.join(out, 'matches.tsv'), encoding='utf-8') as f:
        for row in csv.DictReader(f, delimiter='\t'):
            matches[int(row['sly2_entry'], 16)] = (int(row['sly1_entry'], 16), row['method'])
    reverse = {entry1: entry2 for entry2, (entry1, _m) in matches.items()}
    owners1 = collections.defaultdict(set)  # Sly 1 function -> classes owning it as an own method
    for record in classes1.values():
        for slot in record['own']:
            owners1[slot].add(record['vtable'])
    fields = collections.Counter()
    with open(os.path.join(out, 'field_map.tsv'), encoding='utf-8') as f:
        for row in csv.DictReader(f, delimiter='\t'):
            fields[row['struct']] += 1

    roles = role_matches(classes1, classes2, out)
    layouts = json.load(open(os.path.join(out, 'sly2_structs.json'), encoding='utf-8'))
    extent = {name: max((f['offset'] + f['size'] for f in fields), default=0) for name, fields in layouts.items()}
    rows = []
    for cid, record in sorted(classes2.items()):
        parent = classes2.get(record['parent'])
        own = [s for k, s in enumerate(record['slots']) if not parent or k >= len(parent['slots']) or parent['slots'][k] != s]
        record['own'] = own
        votes = collections.Counter()
        for slot in own:
            if slot in matches:
                for vtable in owners1.get(matches[slot][0], ()):
                    votes[vtable] += 1.0 / len(owners1[matches[slot][0]])
        for role in ROLES:
            if (cid, role) in roles:
                votes[roles[(cid, role)][0]] += 2
        best = votes.most_common(2)
        mapped = None
        if best and best[0][1] >= 1 and (len(best) == 1 or best[0][1] >= 1.5 * best[1][1]):
            mapped = classes1[best[0][0]]
        identical = sum(1 for s in own if s in matches and matches[s][1] == 'exact')
        changed = sum(1 for s in own if s in matches and matches[s][1] != 'exact')
        new = len(own) - identical - changed
        dropped = None
        name = None
        if mapped:
            name = mapped['name']
            dropped = sum(1 for s in mapped['own'] if s not in reverse)
        rows.append({'cid': cid, 'parent': record['parent'], 'size2': record['size'], 'vtable': record['vtable'],
                     'slots': len(record['slots']), 'own': len(own), 'identical': identical, 'changed': changed, 'new': new,
                     'sly1_class': name, 'sly1_size': mapped['size'] if mapped else None,
                     'sly1_own': len(mapped['own']) if mapped else None, 'dropped': dropped,
                     'votes': round(best[0][1], 1) if best else 0, 'fields_mapped': fields.get(name, 0) if name else 0,
                     'confidence': None})
    for row in rows:
        if not row['sly1_class']:
            continue
        end = extent.get(row['sly1_class'])
        if end is not None and end > row['size2']:
            row['confidence'] = 'rejected'
        elif end is not None and row['size2'] - end <= 0x20:
            row['confidence'] = 'high'
        else:
            row['confidence'] = 'medium'
    claimed = collections.defaultdict(list)
    for row in rows:
        if row['confidence'] in ('high', 'medium'):
            claimed[row['sly1_class']].append(row)
    for name, claimants in claimed.items():
        rank = {'high': 1, 'medium': 0}
        claimants.sort(key=lambda r: (rank[r['confidence']], r['votes']), reverse=True)
        for loser in claimants[1:]:
            loser['confidence'] = 'rejected'
    for row in rows:
        if row['confidence'] == 'rejected':
            row['rejected_as'] = row['sly1_class']
        else:
            row['rejected_as'] = None

    with open(os.path.join(out, 'class_diff.tsv'), 'w', encoding='utf-8') as f:
        keys = list(rows[0])
        f.write('\t'.join(keys) + '\n')
        for row in rows:
            f.write('\t'.join('' if row[k] is None else (f'0x{row[k]:x}' if k in ('size2', 'sly1_size', 'vtable') and row[k] is not None else str(row[k])) for k in keys) + '\n')

    children = collections.defaultdict(list)
    for row in rows:
        children[row['parent']].append(row)
    lines = ['# Sly 1 -> Sly 2 class diff', '',
             'Generated by scripts/names/class_diff.py. Each Sly 2 class (cid from the class table at 0x2BAAE8) with its Sly 1 counterpart when',
             'its own methods point to one. Methods: = identical, ~ changed, + new in Sly 2, - Sly 1 own methods not found. Unverified.', '']

    def walk(row, depth):
        label = row['sly1_class'] if row['confidence'] in ('high', 'medium') else '?'
        if row['confidence'] in ('high', 'medium'):
            label += f" ({row['confidence']})"
        elif row['rejected_as']:
            label += f" (not {row['rejected_as']})"
        size = f"0x{row['size2']:x}" + (f" (Sly 1 0x{row['sly1_size']:x})" if row['sly1_size'] and row['confidence'] != 'rejected' else '')
        methods = f"={row['identical']} ~{row['changed']} +{row['new']}" + (f" -{row['dropped']}" if row['dropped'] is not None else '')
        lines.append(f"{'  ' * depth}- cid {row['cid']} **{label}** size {size}, {row['own']} own methods ({methods})")
        for child in children.get(row['cid'], []):
            walk(child, depth + 1)

    for root in children.get(None, []):
        walk(root, 0)
    with open(os.path.join(out, 'class_diff.md'), 'w', encoding='utf-8') as f:
        f.write('\n'.join(lines) + '\n')

    mapped_rows = [r for r in rows if r['confidence'] in ('high', 'medium')]
    print('confidence:', dict(collections.Counter(r['confidence'] for r in rows if r['confidence'])))
    with_vtable = [r for r in rows if r['vtable']]
    print(f'Sly 2: {len(rows)} classes, {len(with_vtable)} with a vtable; Sly 1: {len(classes1)} vtables, {sum(1 for c in classes1.values() if c["name"])} named')
    print(f'mapped to a Sly 1 class: {len(mapped_rows)}; distinct Sly 1 classes: {len({r["sly1_class"] for r in mapped_rows})}')
    totals = collections.Counter()
    for r in rows:
        totals['identical'] += r['identical']
        totals['changed'] += r['changed']
        totals['new'] += r['new']
    print(f'own methods: {totals["identical"]} identical, {totals["changed"]} changed, {totals["new"]} with no Sly 1 counterpart')


if __name__ == '__main__':
    main()
