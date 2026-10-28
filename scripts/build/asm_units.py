# SPDX-License-Identifier: GPL-3.0-or-later
"""asm_units.py: reads the per-module assembly Splat wrote (build/splat/asm/**/*.s, one file per unit, see
gen_splat_config.py) into a list of functions in address order."""
import os
import re

TEXT_END = 0x259DF0
ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
INSTRUCTION = re.compile(r'\s*/\* \S+ ([0-9A-F]{8}) ')

def split_points():
    """Addresses where a matched function (src/MANIFEST.tsv) starts or ends. Splat does not always cut the assembly there: a
    function can sit in the middle of a chunk, or be followed by code that has no label of its own."""
    points = set()
    manifest = os.path.join(ROOT, 'src', 'MANIFEST.tsv')
    if os.path.exists(manifest):
        for line in list(open(manifest))[1:]:
            address, _, size, _ = line.rstrip('\n').split('\t')
            points |= {int(address, 16), (int(address, 16) + int(size) + 7) & ~7}  # the object ends padded to 8
    return points

def manifest_spans():
    """{address: size} of the matched functions (src/MANIFEST.tsv)."""
    manifest = os.path.join(ROOT, 'src', 'MANIFEST.tsv')
    if not os.path.exists(manifest):
        return {}
    return {int(line.split('\t')[0], 16): int(line.split('\t')[2]) for line in list(open(manifest))[1:]}


def merge_spans(functions, spans):
    """The functions with every chunk that starts inside a matched function's span folded into it: Splat can end a chunk at a
    `jr ra` that a jump table or a branch targets, although the function goes on. The folded label stays, so references to it resolve."""
    merged = []
    for function in sorted(functions, key=lambda entry: entry['address']):
        owner = merged[-1] if merged else None
        if owner and owner['address'] in spans and owner['address'] < function['address'] < owner['address'] + spans[owner['address']]:
            owner['lines'] = owner['lines'] + function['lines']
        else:
            merged.append(function)
    return merged


def split_chunk(lines, points):
    """The chunk cut in front of every instruction that sits at one of the points; each new piece gets a `glabel` unless it has one."""
    pieces, current = [], []
    for index, line in enumerate(lines):
        match = INSTRUCTION.match(line)
        if match and int(match.group(1), 16) in points and any(INSTRUCTION.match(earlier) for earlier in current):
            carried = []
            while current and not INSTRUCTION.match(current[-1]) and current[-1].strip().startswith(('glabel', '.L', 'jlabel', 'dlabel')):
                carried.insert(0, current.pop())
            pieces.append(current)
            current = carried
            if not any(carried_line.strip().startswith('glabel ') for carried_line in carried):
                current.append(f'glabel func_{int(match.group(1), 16):08X}\n')
        current.append(line)
    pieces.append(current)
    for index, piece in enumerate(pieces):  # a `.size` must stay with the label it measures
        labels = {line.split()[1] for line in piece if line.strip().startswith('glabel ')}
        pieces[index] = [line for line in piece if not line.startswith('.size ') or line.split()[1].rstrip(',') in labels]
    return pieces

def read_units(splat_directory):
    """(header lines, functions): each function is a dict with address, end, name, lines (the function and the padding
    after it, starting at its `.align 3`) and unit (the file's name without .s)."""
    asm_directory = os.path.join(splat_directory, 'asm')
    paths = []
    for directory, subdirectories, names in os.walk(asm_directory):
        if directory == asm_directory:
            subdirectories[:] = [name for name in subdirectories if name != 'data']
        paths += [os.path.join(directory, name) for name in names if name.endswith('.s')]
    header, functions = None, []
    points = split_points()
    for path in paths:
        unit = os.path.relpath(path, asm_directory)[:-2]
        unit_header, chunks = [], []
        for line in open(path):
            if line.startswith('.align 3'):
                chunks.append([])
            (chunks[-1] if chunks else unit_header).append(line)
        header = header or unit_header
        chunks = [piece for lines in chunks for piece in split_chunk(lines, points)]
        for lines in chunks:
            name = next(line.split()[1] for line in lines if line.strip().startswith('glabel '))
            address = next(int(match.group(1), 16) for line in lines if (match := re.match(r'\s*/\* \S+ ([0-9A-F]{8}) ', line)))
            functions.append({'address': address, 'name': name, 'lines': lines, 'unit': unit})
    functions = merge_spans(functions, manifest_spans())
    for index, function in enumerate(functions):
        function['end'] = functions[index + 1]['address'] if index + 1 < len(functions) else TEXT_END
    return header, functions
