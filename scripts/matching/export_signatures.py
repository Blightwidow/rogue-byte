#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""export_signatures.py [OUT.json] - the real prototypes of the matched functions, in the format scripts/ghidra/ApplySignatures.java reads.

  .venv/bin/python scripts/matching/export_signatures.py work/matching/matched_signatures.json

A matched source is the one place where a function's return type and parameter types are known to compile to the retail code, so they
are worth more than the guesses the demangler and the decompiler make. This writes one entry per matched function whose source defines it
with scalar and pointer types only and a name that is not a mangled one (those carry their parameter types already; `--all-names` includes them) (a struct passed by value or a 128-bit type is left to Ghidra), with Ghidra's names for the types.
Apply it to a backed-up project (docs/build/name-recovery.md: ApplySignatures takes only the functions that are new, never all of
them), then decompile the callers again: their calls then show the right result and arguments."""
import csv
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import harvest  # noqa: E402

GHIDRA_TYPE = {'s8': 'char', 's16': 'short', 's32': 'int', 's64': 'longlong', 'u8': 'uchar', 'u16': 'ushort', 'u32': 'uint', 'u64': 'ulonglong',
               'f32': 'float', 'f64': 'double', 'unsigned': 'uint', 'long': 'int', 'void *': 'void *', 'void': 'void', 'char': 'char', 'short': 'short',
               'int': 'int', 'float': 'float', 'double': 'double', 'unsigned int': 'uint', 'unsigned char': 'uchar', 'unsigned short': 'ushort'}


def entries(all_names=False):
    with open(harvest.scorer.REGISTRY, encoding='utf-8') as handle:
        rows = [row for row in csv.DictReader(handle, delimiter='\t') if row['status'] == 'matched' and row['source']]
    for row in rows:
        if not all_names and '__' in row['name']:
            continue  # a mangled name already carries the parameter types (demangled and applied earlier); a matched source says `void *` for most structs
        path = os.path.join(harvest.LAB, row['source'])
        if not os.path.exists(path):
            continue
        with open(path, encoding='utf-8') as handle:
            signature = harvest.source_signature(row['name'], handle.read())
        if not signature:
            continue
        kinds = [signature[0]] + signature[1]
        if any(kind not in GHIDRA_TYPE for kind in kinds):
            continue
        yield {'address': int(row['address'], 16), 'name': row['name'], 'return': GHIDRA_TYPE[signature[0]], 'parameters': [GHIDRA_TYPE[kind] for kind in signature[1]]}


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(harvest.LAB, 'work', 'matching', 'matched_signatures.json')
    found = list(entries('--all-names' in sys.argv))
    with open(out, 'w', encoding='utf-8') as handle:
        handle.write('[\n' + ',\n'.join('  ' + json.dumps(entry) for entry in found) + '\n]\n')
    print(f'{len(found)} signatures -> {out}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
