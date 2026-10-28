#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""make_objdiff.py: objdiff.json and the objects it compares, then site/data/objdiff-report.json.

Per module unit (build/splat/asm/<unit>.s): the target object is that assembly assembled (the retail code); the base
object links the unit's compiled functions from src/ (`ld -r`), with their symbols renamed to the names the assembly
uses (function labels, D_<address> for data) so objdiff pairs functions and relocations by name. A unit without C gets an
empty base object. Needs `make elf` (build/image/derived.tsv, build/units) and tools/objdiff/objdiff-cli."""
import concurrent.futures
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
CATEGORY = {'id': 'game', 'name': 'Game code'}

header, functions = read_units('build/splat')
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
        trimmed = os.path.join('build', 'image', 'trimmed', file.replace(os.sep, '_').replace('/', '_') + '.o') if file else None
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

configuration = {
    '$schema': 'https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json',
    'custom_make': 'true', 'custom_args': [], 'build_target': False, 'build_base': False, 'watch_patterns': [],
    'units': [{'name': unit, 'target_path': os.path.join(EXPECTED, unit + '.o'), 'base_path': os.path.join(BASE, unit + '.o'),
               'metadata': {'progress_categories': [CATEGORY['id']], 'complete': all(function['address'] in manifest for function in units[unit])}} for unit in sorted(units)],
    'progress_categories': [CATEGORY],
}
with open('objdiff.json', 'w') as handle:
    json.dump(configuration, handle, indent=2)
print(f'objdiff.json: {len(units)} units')
os.makedirs(os.path.join('site', 'data'), exist_ok=True)
subprocess.run([OBJDIFF, 'report', 'generate', '-p', '.', '-o', os.path.join('site', 'data', 'objdiff-report.json')], check=True)
report = json.load(open(os.path.join('site', 'data', 'objdiff-report.json')))
measures = report['measures']
print({key: measures[key] for key in ('fuzzy_match_percent', 'total_code', 'matched_code', 'matched_code_percent', 'total_functions', 'matched_functions') if key in measures})
