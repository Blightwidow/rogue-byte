#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/struct_layout.py - Sly 2 struct layouts from the field map, named from the Sly 1 decomp's headers.

  python3 scripts/names/struct_layout.py config/recovered/

Inputs: config/recovered/field_map.tsv (scripts/names/field_layout.py), work/export/sly2_fields.jsonl (ExportFieldAccesses.java),
config/sly1/sly1_decomp_fields.json (named fields with their Sly 1 offsets, from the decomp's headers),
config/recovered/sly1_field_names.json (scripts/names/projectcane_layout.py: more Sly 1 names, pc_ prefixed, about 81% exact) and
config/sly1/sly1_inheritance.json (an offset not declared in a class itself can belong to a base class).

Each Sly 2 struct gets:
  mapped fields      at their Sly 2 offset; named after the Sly 1 field (decomp name, else s1_0x<sly1 offset>);
                     typed as a pointer to the decomp's struct when the decomp says so, else from how the code accesses it
  Sly 2-only fields  offsets the Sly 2 code accesses that no mapping covers: field_0x<offset>, typed from the access
A large Sly 1 offset landing below 0x80 in Sly 2 is not a field move but a Sly 2 function receiving a pointer into the
object (a sub-object): those are left out of the layout and listed in config/recovered/sly2_subobject_hints.tsv.
Two fields that overlap keep the one with more evidence (mapped before observed, then votes). Offsets that only show up
as a field address passed to a call (size unknown) become 1-byte markers so they still get a name.

Writes config/recovered/sly2_structs.json (for ApplyStructs.java) and config/recovered/sly2_structs.h (C definitions with offset comments).
"""
import collections
import csv
import json
import os
import re
import sys

PRIMITIVE = {('f', 4): 'float', ('i', 4): 'int', ('i', 2): 'short', ('i', 1): 'char', ('i', 8): 'long long',
             ('p', 4): 'void *', ('v', 16): 'undefined16', ('i', 16): 'undefined16'}


def field_type(size, value, decomp_type, known_structs):
    if decomp_type:
        pointer = re.match(r'^(?:struct\s+)?([A-Z][A-Za-z0-9_]*)\s*\*$', decomp_type)
        if pointer and pointer.group(1) in known_structs and size in (0, 4):
            return pointer.group(1) + ' *', 4
    if size == 0:
        return 'char', 1  # address-only evidence: mark the offset, size unknown
    return PRIMITIVE.get((value, size), f'undefined{size}'), size


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    out = sys.argv[1]
    decomp = {s: {int(o): tuple(v) for o, v in d.items()} for s, d in json.load(open('config/sly1/sly1_decomp_fields.json')).items()}
    base_of = json.load(open('config/sly1/sly1_inheritance.json'))
    estimated = {}
    if os.path.isfile(os.path.join(out, 'sly1_field_names.json')):
        estimated = {s: {int(o): v for o, v in d.items()} for s, d in json.load(open(os.path.join(out, 'sly1_field_names.json'))).items()}

    def decomp_field(struct, offset):
        seen = set()
        while struct and struct not in seen:
            seen.add(struct)
            if offset in decomp.get(struct, {}):
                return decomp[struct][offset]
            struct = base_of.get(struct)
        return None

    structs = collections.defaultdict(dict)  # struct -> offset2 -> field
    known_structs = set()
    with open(os.path.join(out, 'field_map.tsv'), encoding='utf-8') as f:
        rows = list(csv.DictReader(f, delimiter='\t'))
    for row in rows:
        known_structs.add(row['struct'])
    known_structs |= set(decomp) | set(base_of) | set(base_of.values())
    hints = []
    for row in rows:
        struct, offset1, offset2 = row['struct'], int(row['sly1_offset'], 16), int(row['sly2_offset'], 16)
        size, value, votes = int(row['size']), row['value'], float(row['votes'])
        if offset2 < 0x80 and offset1 - offset2 > 0x400:
            hints.append(row)
            continue
        named = decomp_field(struct, offset1)
        if named and not named[0].startswith('unk'):
            name = re.sub(r'_0x[0-9A-Fa-f]+$', '', named[0])
        elif offset1 in estimated.get(struct, {}):
            name = estimated[struct][offset1][0]
        else:
            name = f's1_0x{offset1:x}'
        c_type, length = field_type(size, value, named[1] if named else None, known_structs)
        field = {'offset': offset2, 'name': name, 'type': c_type, 'size': length, 'source': 'mapped', 'votes': votes,
                 'sly1_offset': offset1, 'decomp': bool(named) and not named[0].startswith('unk'), 'projectcane': name.startswith('pc_')}
        current = structs[struct].get(offset2)
        if current is None or current['votes'] < votes:
            structs[struct][offset2] = field

    observed = collections.defaultdict(collections.Counter)
    with open('work/export/sly2_fields.jsonl', encoding='utf-8') as f:
        for line in f:
            for _slot, struct, offset, size, _kind, value in json.loads(line)['accesses']:
                observed[struct][(offset, size, value)] += 1
    for struct, accesses in observed.items():
        best = {}
        for (offset, size, value), count in accesses.items():
            if offset not in best or (size, count) > (best[offset][0], best[offset][2]):
                best[offset] = (size, value, count)
        for offset, (size, value, count) in best.items():
            if offset in structs[struct]:
                continue
            c_type, length = field_type(size, value, None, known_structs)
            structs[struct][offset] = {'offset': offset, 'name': f'field_0x{offset:x}', 'type': c_type, 'size': length,
                                       'source': 'observed', 'votes': count / 100, 'sly1_offset': None, 'decomp': False, 'projectcane': False}

    layouts = {}
    for struct, by_offset in structs.items():
        kept = []
        for field in sorted(by_offset.values(), key=lambda fl: (fl['source'] != 'mapped', -fl['votes'])):
            if all(field['offset'] + field['size'] <= other['offset'] or other['offset'] + other['size'] <= field['offset'] for other in kept):
                kept.append(field)
        layouts[struct] = sorted(kept, key=lambda fl: fl['offset'])

    with open(os.path.join(out, 'sly2_subobject_hints.tsv'), 'w', encoding='utf-8') as f:
        f.write('struct\tsly1_offset\tsly2_offset\tvotes\n')
        for row in hints:
            f.write(f"{row['struct']}\t{row['sly1_offset']}\t{row['sly2_offset']}\t{row['votes']}\n")
    with open(os.path.join(out, 'sly2_structs.json'), 'w', encoding='utf-8') as f:
        json.dump(layouts, f, indent=0, sort_keys=True)
    with open(os.path.join(out, 'sly2_structs.h'), 'w', encoding='utf-8') as f:
        f.write('/* Sly 2 struct layouts (partial) recovered by scripts/names/field_layout.py + scripts/names/struct_layout.py. Mapped fields carry the Sly 1\n')
        f.write(' * decomp\'s name or s1_0x<Sly 1 offset>; field_0x<offset> fields are only seen in Sly 2 code. Gaps are unknown.\n')
        f.write(' * Sizes are the extent of known fields, not the real struct size. Unverified. */\n\n')
        f.write('typedef unsigned char undefined1;\ntypedef struct { unsigned char b[16]; } undefined16;\n\n')
        referenced = {fl['type'][:-2] for fields in layouts.values() for fl in fields if fl['type'].endswith(' *') and fl['type'] != 'void *'}
        for struct in sorted(set(layouts) | referenced):
            f.write(f'typedef struct {struct} {struct};\n')
        f.write('\n')
        for struct in sorted(layouts):
            f.write(f'struct {struct} {{\n')
            position = 0
            for field in layouts[struct]:
                if field['offset'] > position:
                    f.write(f'    undefined1 gap_0x{position:x}[0x{field["offset"] - position:x}];\n')
                origin = f'sly1 +0x{field["sly1_offset"]:x}' if field['sly1_offset'] is not None else 'sly2 only'
                if re.match(r'^undefined(\d+)$', field['type']) and field['type'] != 'undefined16':
                    declaration = f'undefined1 {field["name"]}[{field["size"]}]'
                else:
                    declaration = f'{field["type"]} {field["name"]}'
                f.write(f'    {declaration}; /* 0x{field["offset"]:x} {origin} */\n')
                position = field['offset'] + field['size']
            f.write('};\n\n')
    mapped = sum(1 for fields in layouts.values() for fl in fields if fl['source'] == 'mapped')
    named = sum(1 for fields in layouts.values() for fl in fields if fl['decomp'])
    observed_count = sum(1 for fields in layouts.values() for fl in fields if fl['source'] == 'observed')
    estimated_count = sum(1 for fields in layouts.values() for fl in fields if fl['projectcane'])
    print(f'{len(layouts)} structs: {mapped} mapped fields ({named} decomp names, {estimated_count} ProjectCane names), {observed_count} Sly 2-only fields, {len(hints)} sub-object hints')


if __name__ == '__main__':
    main()
