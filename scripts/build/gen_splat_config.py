#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""gen_splat_config.py [--reset | --pieces]: writes config/us/sly2.us.yaml, the Splat configuration, with the code split into one unit per
module: each run of consecutive functions that config/recovered/modules.tsv gives the same module (the Sly 1 source file the
code matcher placed it in) becomes one assembly file `build/splat/asm/<module>.s`, named like the folders of src/.
A module that appears in several runs gets the run's address as a suffix after the first.

Rodata and data are cut into per-module pieces too (config/us/pieces.tsv): `--pieces` (after a split with the pieces
removed, `make config` does both) reads the assembly in build/splat/asm and gives every address of the two regions that
the code refers to by name (`D_<address>`) to the first unit, in code order, that refers to it; each run of one owner
becomes a piece named rodata/<unit> or data/<unit>. `--reset` goes back to one piece per region.

Layout of the retail file (file offset -> vram): .text 0x100000, .vutext 0x259df0 (VU1 microcode, raw), .rodata 0x262380,
.data 0x2ac880, then the embedded IOP modules (.irx) at 0x472200."""
import csv
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
TEXT_START, TEXT_END, FILE_OFFSET = 0x100000, 0x259DF0, 0x80
RODATA_START, DATA_START, DATA_END = 0x262380, 0x2AC880, 0x2DD230
PIECES = os.path.join(ROOT, 'config', 'us', 'pieces.tsv')

def directory_name(module):
    return re.sub(r'[^A-Za-z0-9_-]+', '-', module).strip('-') or 'unsorted'

entries = sorted((int(row['sly2_entry'], 16), row['module'])
                 for row in csv.DictReader(open(os.path.join(ROOT, 'config', 'recovered', 'modules.tsv')), delimiter='\t')
                 if int(row['sly2_entry'], 16) < TEXT_END)
runs = []
for address, module in entries:
    if not runs or runs[-1][1] != module:
        runs.append([address, module])
runs[0][0] = TEXT_START  # the first function (0x100000) has no entry of its own

seen = {}
subsegments = []
for address, module in runs:
    name = directory_name(module)
    seen[name] = seen.get(name, 0) + 1
    if seen[name] > 1:
        name += f'_{address:06x}'
    subsegments.append(f'          - [{address - TEXT_START + FILE_OFFSET:#x}, asm, {name}]')

def compute_pieces():
    """[(name, vram, end)] for rodata and data, from the assembly of build/splat/asm."""
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from asm_units import read_units
    _, functions = read_units(os.path.join(ROOT, 'build', 'splat'))
    first = {}
    for function in functions:
        first.setdefault(function['unit'], function['address'])
    owner = {}
    pattern = re.compile(r'\b[A-Z]{1,3}_([0-9A-Fa-f]{6,8})\b')
    for unit in sorted(first, key=first.get):
        for line in open(os.path.join(ROOT, 'build', 'splat', 'asm', unit + '.s')):
            for match in pattern.finditer(line):
                address = int(match.group(1), 16)
                if RODATA_START <= address < DATA_END:
                    owner.setdefault(address, unit)
    pieces, used = [], {}
    for start, end, kind in ((RODATA_START, DATA_START, 'rodata'), (DATA_START, DATA_END, 'data')):
        runs = [[start, None]]  # the prefix before the first reference has no owner
        for address in sorted(a for a in owner if start <= a < end):
            if runs[-1][1] != owner[address]:
                runs.append([address, owner[address]])
        if len(runs) > 1 and runs[1][0] == start:
            runs.pop(0)
        for index, (address, unit) in enumerate(runs):
            name = f'{kind}/{directory_name(unit) if unit else "start"}'
            used[name] = used.get(name, 0) + 1
            if used[name] > 1:
                name += f'_{address:06x}'
            pieces.append((name, address, runs[index + 1][0] if index + 1 < len(runs) else end))
    return pieces

mode = sys.argv[1] if len(sys.argv) > 1 else ''
if mode == '--pieces':
    pieces = compute_pieces()
    with open(PIECES, 'w') as handle:
        for name, start, end in pieces:
            handle.write(f'{name}\t{start:#x}\t{end - start}\n')
elif mode == '--reset' or not os.path.exists(PIECES):
    pieces = [('rodata/all', RODATA_START, DATA_START), ('data/all', DATA_START, DATA_END)]
    if os.path.exists(PIECES):
        os.remove(PIECES)
else:
    pieces = [(name, int(start, 16), int(start, 16) + int(size)) for name, start, size in (line.split('\t') for line in open(PIECES))]

def piece_lines(kind):
    return [f'          - [{start - TEXT_START + FILE_OFFSET:#x}, {kind}, {name}]' for name, start, end in pieces if name.startswith(kind + '/')]

header = '''name: Sly 2 Band of Thieves (US)
sha1: de2af92a54de71e33edc8a160c31c0337a95e6f5
options:
    basename: SCUS_973.16
    target_path: ../../work/elf/SCUS_973.16
    base_path: ../../build/splat
    asm_path: asm
    src_path: ../../src
    build_path: build
    asset_path: assets
    compiler: EEGCC
    find_file_boundaries: False
    platform: ps2
    string_encoding: ASCII
    create_undefined_funcs_auto: False
    create_undefined_syms_auto: True
    undefined_funcs_auto_path: undefined_funcs_auto.txt
    undefined_syms_auto_path: undefined_syms_auto.txt
    symbol_addrs_path: ../../config/us/symbol_addrs.txt
    section_order: [".text", ".data", ".rodata", ".sbss", ".bss"]
    disasm_unknown: True
    subalign: 4
    named_regs_for_c_funcs: False
    ld_bss_is_noload: true

# Generated by scripts/build/gen_splat_config.py: one asm unit per module run.
segments:
    - [0x0, databin, elf_header]
    - name: main
      type: code
      start: 0x80
      vram: 0x100000
      align: 1
      subalign: 4
      subsegments:
'''
footer = '''          - [0x1dd2b0, databin, irx_gap]
    - name: irx
      type: code
      start: 0x1dd380
      vram: 0x472200
      align: 1
      subsegments:
          - [0x1dd380, databin, irx]
    - name: elf_tail
      type: code
      start: 0x250fc0
      vram: 0x0
      align: 1
      subsegments:
          # section data outside the loaded segments (overlay tables, .mdebug...) and the section header table
          - [0x250fc0, databin, elf_tail]
    - [0x27a0b8]
'''
body = subsegments + ['          - [0x159e70, databin, vutext]'] + piece_lines('rodata') + piece_lines('data')
open(os.path.join(ROOT, 'config', 'us', 'sly2.us.yaml'), 'w').write(header + '\n'.join(body) + '\n' + footer)
print(len(subsegments), 'units,', len(pieces), 'data pieces')
