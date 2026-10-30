#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""make_objdiff.py: objdiff.json and the objects it compares, then site/data/objdiff-report.json.

Per module unit (build/splat/asm/<unit>.s): the target object is that assembly assembled (the retail code); the base
object links the unit's compiled functions from src/ (`ld -r`), with their symbols renamed to the names the assembly
uses (function labels, D_<address> for data) so objdiff pairs functions and relocations by name. A unit without C gets an
empty base object. Needs `make elf` (build/image/derived.tsv, build/units) and tools/objdiff/objdiff-cli."""
import bisect
import concurrent.futures
import csv
import json
import os
import re
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, 'scripts', 'build'))
from asm_units import read_units  # noqa: E402

BINUTILS = os.path.join('tools', 'binutils-mips-ps2-decompals', 'mips-ps2-decompals')
OBJDIFF = os.path.join('tools', 'objdiff', 'objdiff-cli')
EXPECTED, BASE = os.path.join('build', 'objdiff', 'expected'), os.path.join('build', 'objdiff', 'base')
ADDRESS_NAME = re.compile(r'^([A-Z]{1,3})_([0-9A-Fa-f]{8})$')

header, functions = read_units('build/splat')
CATEGORY_CONFIG = json.load(open(os.path.join('config', 'us', 'categories.json')))
module_entries = sorted((int(row['sly2_entry'], 16), row['module']) for row in csv.DictReader(open(os.path.join('config', 'recovered', 'modules.tsv')), delimiter='\t'))
entry_addresses = [address for address, _ in module_entries]

def module_at(address):
    """The module (modules.tsv) of the function at or before the address."""
    return module_entries[max(bisect.bisect_right(entry_addresses, address) - 1, 0)][1]

def subsystem_of(index):
    """Subsystem category of the module entry at `index`: by its first Sly 1 file; a Sly 2-only run takes the one of the run before it."""
    while index >= 0:
        module = module_entries[index][1]
        if module in CATEGORY_CONFIG.get('modules', {}):
            return CATEGORY_CONFIG['modules'][module]
        if module != 'sdk' and not module.startswith('new_'):
            token = module.split('+')[0]
            return CATEGORY_CONFIG['files'].get(token) or CATEGORY_CONFIG['files'].get(module.split('+')[-1])
        index -= 1
    return None

def categories_of(unit):
    """Category ids of a unit: origin (sdk / sly1 / new), game code unless SDK, and the subsystem."""
    address = units[unit][0]['address']
    module = module_at(address)
    if module == 'sdk':
        return ['sdk']
    ids = ['game', 'new' if module.startswith('new_') else 'sly1']
    subsystem = subsystem_of(max(bisect.bisect_right(entry_addresses, address) - 1, 0))
    return ids + ([subsystem] if subsystem else [])
function_name = {function['address']: function['name'] for function in functions}
units = {}
for function in functions:
    units.setdefault(function['unit'], []).append(function)

# address -> the name the assembly uses for data (Splat's undefined symbols), and derived addresses of unknown names
data_name, symbols = {}, {}
for line in open('build/splat/undefined_syms_auto.txt'):
    match = re.match(r'(\S+) = (0x[0-9A-Fa-f]+);', line)
    if match:
        data_name.setdefault(int(match.group(2), 16), match.group(1))
for line in open('config/us/symbol_addrs.txt'):
    match = re.match(r'(\S+) = (0x[0-9A-Fa-f]+);', line)
    if match:
        symbols[match.group(1)] = int(match.group(2), 16)
for line in open('build/image/derived.tsv'):
    name, address = line.rstrip('\n').split('\t')
    symbols.setdefault(name, int(address, 16))

def target_name(name):
    """The name the assembly uses for the same thing as the object's undefined `name`."""
    match = ADDRESS_NAME.match(name)
    address = int(match.group(2), 16) if match else symbols.get(name)
    if address is None:
        return None
    return function_name.get(address) or data_name.get(address) or f'D_{address:08X}'

def run(command):
    result = subprocess.run(command, capture_output=True, text=True)
    if result.returncode:
        sys.exit(' '.join(command[:3]) + ' failed: ' + result.stderr.strip())

manifest = {int(line.split('\t')[0], 16): line.rstrip('\n').split('\t')[3] for line in list(open('src/MANIFEST.tsv'))[1:]}
drafts = {int(line.split('\t')[0], 16): line.rstrip('\n').split('\t')[3] for line in list(open('nonmatching/MANIFEST.tsv'))[1:]} if os.path.exists('nonmatching/MANIFEST.tsv') else {}
manifest_size = {int(line.split('\t')[0], 16): int(line.split('\t')[2]) for line in list(open('src/MANIFEST.tsv'))[1:]}

def unit_source(unit):
    """The unit's assembly from asm_units' chunks (cut at the matched functions' bounds), each function with a `.size` of its own."""
    lines = list(header)
    for function in units[unit]:
        body = [line for line in function['lines'] if not line.startswith('.size ')] if function['address'] in manifest_size else function['lines']
        lines += body
        if not any(line.startswith('.size ') for line in body):
            lines.append(f".size {function['name']}, {manifest_size.get(function['address'], function['end'] - function['address'])}\n")
    return ''.join(lines)

def assemble_target(unit):
    destination = os.path.join(EXPECTED, unit + '.o')
    os.makedirs(os.path.dirname(destination), exist_ok=True)
    source = destination[:-2] + '.s'
    open(source, 'w').write(unit_source(unit))
    run([BINUTILS + '-as', '-EL', '-march=r5900', '-mabi=eabi', '-G0', '-no-pad-sections', '-I', 'include',
         '-I', os.path.join('build', 'splat', 'asm'), '-o', destination, source])

def build_base(unit):
    destination = os.path.join(BASE, unit + '.o')
    os.makedirs(os.path.dirname(destination), exist_ok=True)
    renamed = []
    for function in units[unit]:
        file = manifest.get(function['address'])
        path = os.path.join('build', 'units', file + '.o') if file else None
        if not file and function['address'] in drafts:  # a source that compiles but does not match: objdiff counts the partial work
            file = drafts[function['address']]
            path = os.path.join('build', 'nonmatching', file + '.o')
        trimmed = os.path.join('build', 'image', 'trimmed', file.replace(os.sep, '_').replace('/', '_') + '.o') if function['address'] in manifest else None
        if trimmed and os.path.isfile(trimmed):
            path = trimmed
        if not path or not os.path.isfile(path):
            continue
        with open(path, 'rb') as handle:
            elf = ELFFile(handle)
            text_index = elf.get_section_index('.text')
            renames = {}
            for symbol in elf.get_section_by_name('.symtab').iter_symbols():
                if symbol['st_shndx'] == text_index and symbol['st_info']['type'] == 'STT_FUNC' and function['name'] not in renames.values():
                    renames[symbol.name] = function['name']
                elif symbol['st_shndx'] == 'SHN_UNDEF' and symbol.name:
                    target = target_name(symbol.name)
                    if target and target != symbol.name and target not in renames.values():
                        renames[symbol.name] = target
        renamed_path = os.path.join(BASE, 'parts', os.path.basename(path))
        os.makedirs(os.path.dirname(renamed_path), exist_ok=True)
        rename_file = renamed_path + '.syms'
        open(rename_file, 'w').write(''.join(f'{old} {new}\n' for old, new in renames.items()))
        run([BINUTILS + '-objcopy', '--redefine-syms', rename_file, '-R', '.mdebug', path, renamed_path])
        renamed.append(renamed_path)
    if renamed:
        run([BINUTILS + '-ld', '-EL', '-r', '--no-warn-mismatch', '-o', destination, *renamed])
    else:
        run(f'printf \'.section .text, "ax"\\n\' | {BINUTILS}-as -EL -march=r5900 -o {destination} -'.split() if False else ['sh', '-c', f'printf \'.section .text, "ax"\\n\' | {BINUTILS}-as -EL -march=r5900 -o {destination} -'])

with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as pool:
    list(pool.map(assemble_target, units))
    list(pool.map(build_base, units))

# Data units: one per retail data section, sized from the retail image. The target holds the section as object symbols; the base holds
# the rodata that compiled C objects own (their own jump tables and literals, linked where retail has them: the .ro_<address> sections of the
# linked image), so those ranges count as matched data and the rest stays unmatched until C owns it. Only sizes and percentages
# reach the report, never the bytes.
DATA_SECTIONS = [('rodata', '.rodata'), ('data', '.data'), ('vutext', '.vutext'), ('irx', '.irx')]
data_units = []

def owned_rodata():
    """[(address, bytes)] of the rodata that compiled C objects own: the `.ro_<address>` sections of the linked image (build/image/image.elf)
    that link.ld fills from an object rather than from the assembly pieces. The bytes are the linked ones, with a jump table's relocations resolved."""
    pattern = re.compile(r'(\S+) (0x[0-9A-Fa-f]+) .*\{ \*/(\S+?)\(\.rodata\) \}')
    labels = {}
    for line in open(os.path.join('build', 'image', 'link.ld')):
        match = pattern.match(line.strip())
        if match and '_asm.o' not in match.group(3) and 'NOLOAD' not in line:
            labels[match.group(1)] = int(match.group(2), 16)
    found = []
    with open(os.path.join('build', 'image', 'image.elf'), 'rb') as handle:
        linked = ELFFile(handle)
        for label, address in labels.items():
            section = linked.get_section_by_name(label)
            if section is not None and section['sh_size']:
                found.append((address, section.data()))
    return sorted(found)

def data_symbols(address, size, owned):
    """[(start, size, is_owned)] pieces of a section: each owned range, and the gaps between them."""
    pieces, cursor = [], address
    for start, blob in owned:
        if start < cursor or start + len(blob) > address + size:
            continue
        if start > cursor:
            pieces.append((cursor, start - cursor, False))
        pieces.append((start, len(blob), True))
        cursor = start + len(blob)
    if cursor < address + size:
        pieces.append((cursor, address + size - cursor, False))
    return pieces

def build_data_units():
    elf_path = os.path.join('work', 'elf', 'SCUS_973.16')
    if not os.path.isfile(elf_path):
        return
    with open(elf_path, 'rb') as handle:
        image = ELFFile(handle)
        for name, section_name in DATA_SECTIONS:
            section = image.get_section_by_name(section_name)
            if section is None or not section['sh_size']:
                continue
            blob_directory = os.path.join('build', 'objdiff', 'data', name)
            os.makedirs(blob_directory, exist_ok=True)
            retail, address = section.data(), section['sh_addr']
            owned = owned_rodata() if name == 'rodata' else []
            header_line = f'.section {section_name}, "a", @progbits\n'
            # objdiff counts a data section as matched only when all of it matches, so the C-owned ranges are a unit of their own
            groups = {'': ([header_line], [header_line]), '-c': ([header_line], [header_line])}
            for start, size, is_owned in data_symbols(address, section['sh_size'], owned):
                symbol = f'D_{start:08X}'
                blob = os.path.join(blob_directory, symbol + '.bin')
                open(blob, 'wb').write(retail[start - address:start - address + size])
                target_lines, base_lines = groups['-c' if is_owned else '']
                target_lines.append(f'.globl {symbol}\n.type {symbol}, @object\n{symbol}:\n.incbin "{blob}"\n.size {symbol}, {size}\n')
                if is_owned:
                    compiled_blob = os.path.join(blob_directory, symbol + '.compiled.bin')
                    open(compiled_blob, 'wb').write(next(data for place, data in owned if place == start))
                    base_lines.append(f'.globl {symbol}\n.type {symbol}, @object\n{symbol}:\n.incbin "{compiled_blob}"\n.size {symbol}, {size}\n')
            for suffix, (target_lines, base_lines) in groups.items():
                if len(target_lines) == 1:
                    continue
                unit = 'data/' + name + suffix
                expected, base = os.path.join(EXPECTED, unit + '.o'), os.path.join(BASE, unit + '.o')
                os.makedirs(os.path.dirname(expected), exist_ok=True)
                os.makedirs(os.path.dirname(base), exist_ok=True)
                source, base_source = expected[:-2] + '.s', base[:-2] + '.s'
                open(source, 'w').write(''.join(target_lines))
                open(base_source, 'w').write(''.join(base_lines))
                run([BINUTILS + '-as', '-EL', '-march=r5900', '-mabi=eabi', '-G0', '-o', expected, source])
                run([BINUTILS + '-as', '-EL', '-march=r5900', '-mabi=eabi', '-G0', '-o', base, base_source])
                data_units.append({'name': unit, 'target_path': expected, 'base_path': base, 'metadata': {'progress_categories': ['data'], 'complete': suffix == '-c'}})

build_data_units()

configuration = {
    '$schema': 'https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json',
    'custom_make': 'true', 'custom_args': [], 'build_target': False, 'build_base': False, 'watch_patterns': [],
    'units': [{'name': unit, 'target_path': os.path.join(EXPECTED, unit + '.o'), 'base_path': os.path.join(BASE, unit + '.o'),
               'metadata': {'progress_categories': categories_of(unit), 'complete': all(function['address'] in manifest for function in units[unit])}} for unit in sorted(units)] + data_units,
    'progress_categories': [{'id': category['id'], 'name': category['name']} for category in CATEGORY_CONFIG['categories']],
}
with open('objdiff.json', 'w') as handle:
    json.dump(configuration, handle, indent=2)
print(f'objdiff.json: {len(units)} units, {len(data_units)} data units')
os.makedirs(os.path.join('site', 'data'), exist_ok=True)
subprocess.run([OBJDIFF, 'report', 'generate', '-p', '.', '-o', os.path.join('site', 'data', 'objdiff-report.json')], check=True)
report = json.load(open(os.path.join('site', 'data', 'objdiff-report.json')))
measures = report['measures']
print({key: measures[key] for key in ('fuzzy_match_percent', 'total_code', 'matched_code', 'matched_code_percent', 'total_functions', 'matched_functions', 'total_data', 'matched_data', 'matched_data_percent') if key in measures})
