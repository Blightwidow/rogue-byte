#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""gen_context.py: site/data/context.json, what the Naming Desk (site/naming.html) shows beside each function: who calls it, what it
calls, which short identifier-like strings it refers to, and where its name comes from.

Needs `make elf` first (build/splat). Callers and callees come from the `jal`/`j` targets of the assembly (virtual calls are not
seen). Strings are the text in the executable at the data addresses the code points at (`%hi`/`%lo`), kept only when they look like identifiers, file names or format
tags: 3 to 48 characters from [A-Za-z0-9_./:%-], at most eight per function. Sentences and dialogue are left out on purpose, and
no other bytes of the executable are written. Keys are the addresses of site/data/report.json."""
import json
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
LIMIT = {'callers': 12, 'callees': 12, 'strings': 8}
STRING_SHAPE = re.compile(r'^[A-Za-z0-9_./:%-]{3,48}$')
CALL = re.compile(r'^\s*/\*.*?\*/\s+(?:jal|j|bal)\s+(\S+)')
REFERENCE = re.compile(r'%(?:hi|lo)\(([A-Za-z_]\w*)(?: \+ (0x[0-9A-Fa-f]+))?\)')
ADDRESS_NAME = re.compile(r'^[A-Za-z]{1,6}_([0-9A-F]{8})$')


def parse_function(lines):
    """(call target names, [(data symbol, offset)]) of one function's assembly lines."""
    calls, references = [], []
    for line in lines:
        found = CALL.match(line)
        if found:
            calls.append(found.group(1))
        for name, offset in REFERENCE.findall(line):
            references.append((name, int(offset, 16) if offset else 0))
    return calls, references


def readable(text):
    """The string if it may be published as a hint (identifier-like, not prose), else None."""
    return text if STRING_SHAPE.match(text) and not text.isdigit() else None


def string_reader(image, base=0x100000, offset=0x80):
    """A function address -> the NUL-terminated ASCII string there in the executable's loaded segment (None when it is not text)."""
    def read(address):
        start = address - base + offset
        if not 0 <= start < len(image):
            return None
        end = image.find(b'\0', start, start + 64)
        if end <= start:
            return None
        chunk = image[start:end]
        return chunk.decode('ascii') if all(32 <= byte < 127 for byte in chunk) else None
    return read


def build_context(functions, read_string, symbols, origins):
    """{address key: {callers, callees, strings, origin}} from the functions of asm_units.read_units."""
    key = lambda address: f'{address:#X}'
    by_name = {function['name']: function['address'] for function in functions}
    callees, callers = {}, {}
    context = {}
    for function in functions:
        calls, references = parse_function(function['lines'])
        targets = sorted({by_name[name] for name in calls if name in by_name} - {function['address']})
        callees[function['address']] = targets
        for target in targets:
            callers.setdefault(target, []).append(function['address'])
        texts = []
        for name, offset in references:
            found = ADDRESS_NAME.match(name)
            address = int(found.group(1), 16) if found else symbols.get(name)
            text = read_string(address + offset) if address is not None else None
            if text is not None and readable(text) and text not in texts:
                texts.append(text)
        context[function['address']] = {'strings': texts[:LIMIT['strings']]}
    for function in functions:
        address = function['address']
        context[address].update({'callers': [key(a) for a in sorted(callers.get(address, []))[:LIMIT['callers']]],
                                 'callees': [key(a) for a in callees[address][:LIMIT['callees']]],
                                 'origin': origins.get(address, 'none')})
    return {key(address): {field: value for field, value in entry.items() if value} for address, entry in context.items()}


def read_origins(path):
    """{address: where the name comes from} out of the generated combined symbol file."""
    origins = {}
    for line in open(path):
        found = re.match(r'\S+ = (0x[0-9A-Fa-f]+);.*?source:(\S+)', line)
        if found:
            origins[int(found.group(1), 16)] = 'bevy' if found.group(2).startswith('bevy') else found.group(2)
    return origins


def main():
    os.chdir(ROOT)
    sys.path.insert(0, os.path.join(ROOT, 'scripts', 'build'))
    from asm_units import read_units
    _, functions = read_units('build/splat')
    symbols = {}
    for line in open(os.path.join('config', 'us', 'symbol_addrs.txt')):
        found = re.match(r'(\S+) = (0x[0-9A-Fa-f]+);', line)
        if found:
            symbols[found.group(1)] = int(found.group(2), 16)
    context = build_context(functions, string_reader(open(os.path.join('work', 'elf', 'SCUS_973.16'), 'rb').read()), symbols,
                            read_origins(os.path.join('config', 'recovered', 'sly2_combined_symbol_addrs.txt')))
    os.makedirs(os.path.join('site', 'data'), exist_ok=True)
    with open(os.path.join('site', 'data', 'context.json'), 'w') as handle:
        json.dump(context, handle, separators=(',', ':'), sort_keys=True)
    with_strings = sum(1 for entry in context.values() if entry.get('strings'))
    print(f'site/data/context.json: {len(context)} functions, {with_strings} with strings, '
          f'{sum(1 for entry in context.values() if entry.get("callers"))} with callers')


if __name__ == '__main__':
    main()
