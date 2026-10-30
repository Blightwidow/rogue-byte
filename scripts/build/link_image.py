#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""link_image.py: the image with the compiled C swapped in for the assembly of the functions it reproduces.

Needs build/splat (make elf's split) and the objects of src/ compiled by ninja (build/units/<file>.o). For every matched
function whose object is usable, the function's assembly is dropped from build/splat/asm/text.s and the object is
linked at the function's address instead; the rest of the assembly is assembled in runs. After linking, every swapped
function's bytes are compared with the retail ones and the ones that differ (relocations into the object's own data,
unresolved names, size) fall back to assembly. Writes build/image/image.bin and config/us/swapped.tsv (address, name)."""
import concurrent.futures
import hashlib
import os
import re
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.chdir(ROOT)
BINUTILS = os.path.join('tools', 'binutils-mips-ps2-decompals', 'mips-ps2-decompals')
SPLAT = os.path.join('build', 'splat')
BUILD = os.path.join('build', 'image')
RUNS = os.path.join(BUILD, 'runs')
UNITS = os.path.join('build', 'units')
RETAIL = os.path.join('work', 'elf', 'SCUS_973.16')
TEXT_START, TEXT_END, FILE_OFFSET_OF_TEXT = 0x100000, 0x259DF0, 0x80
RODATA_START, RODATA_END = 0x262380, 0x2AC864
ADDRESS_NAME = re.compile(r'^([A-Z]{1,3})_([0-9A-Fa-f]{8})$')

os.makedirs(RUNS, exist_ok=True)
os.makedirs(os.path.join(BUILD, 'data'), exist_ok=True)
retail = open(RETAIL, 'rb').read()
# the rodata and data pieces Splat cut out (gen_splat_config.py --pieces), as one byte string from RODATA_START on
piece_list = [(name, int(start, 16), int(size)) for name, start, size in (line.rstrip('\n').split('\t') for line in open(os.path.join('config', 'us', 'pieces.tsv')))]
piece_starts = {start for _, start, _ in piece_list}
region_end = piece_list[-1][1] + piece_list[-1][2]
region_offset = FILE_OFFSET_OF_TEXT + RODATA_START - TEXT_START
region = retail[region_offset:region_offset + region_end - RODATA_START]
# a piece is linked from its per-symbol assembly (build/splat/asm/data/<name>.<kind>.s) unless that did not reproduce the retail
# bytes (or a swapped function's own rodata sits inside it): then the raw bytes stand in for it
piece_ranges = {(start, start + size): name for name, start, size in piece_list}

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from asm_units import read_units  # noqa: E402
header, functions = read_units(SPLAT)
by_address = {function['address']: function for function in functions}

symbols = {}  # name -> address, from Splat's input
for line in open(os.path.join('config', 'us', 'symbol_addrs.txt')):
    match = re.match(r'(\S+) = (0x[0-9A-Fa-f]+);', line)
    if match:
        symbols[match.group(1)] = int(match.group(2), 16)
for line in open(os.path.join(SPLAT, 'undefined_syms_auto.txt')):
    match = re.match(r'(\S+) = (0x[0-9A-Fa-f]+);', line)
    if match:
        symbols.setdefault(match.group(1), int(match.group(2), 16))

def function_offset(object_path, name):
    """Offset of the function in the object's .text (the compiler can emit a local helper in front of it), or 0."""
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        text_index = elf.get_section_index('.text')
        offsets = [symbol['st_value'] for symbol in elf.get_section_by_name('.symtab').iter_symbols()
                   if symbol['st_shndx'] == text_index and (symbol.name == name or symbol.name.startswith(name + '__'))]
    return offsets[0] if len(offsets) == 1 else 0

def trim_object(object_path, start, size, keep):
    """A copy of the object whose .text (and the relocations in it) is the `size` bytes from `start`, padded to `keep`: the compiler emits the local
    helpers a function needs (a destructor, say) before or behind it, which the retail image keeps elsewhere. The section is
    rewritten in place and only its header changes size."""
    blob = bytearray(open(object_path, 'rb').read())
    section_table, entry_size, count, names_index = (int.from_bytes(blob[at:at + width], 'little') for at, width in ((0x20, 4), (0x2E, 2), (0x30, 2), (0x32, 2)))
    header = lambda index, field, width=4: int.from_bytes(blob[section_table + index * entry_size + field:section_table + index * entry_size + field + width], 'little')
    name_at = lambda index: header(names_index, 16) + header(index, 0)
    name = lambda index: bytes(blob[name_at(index):blob.index(0, name_at(index))]).decode()
    text_index = next(index for index in range(count) if name(index) == '.text')
    relocation_index = next(index for index in range(count) if header(index, 4) == 9 and header(index, 28) == text_index)
    entries = [bytes(blob[header(relocation_index, 16) + at:header(relocation_index, 16) + at + 8]) for at in range(0, header(relocation_index, 20), 8)]
    kept = [(int.from_bytes(entry[:4], 'little') - start).to_bytes(4, 'little') + entry[4:] for entry in entries
            if start <= int.from_bytes(entry[:4], 'little') < start + keep]
    symbol_table = next(index for index in range(count) if header(index, 4) == 2)  # SHT_SYMTAB: move the symbols into the cut text
    symbols_at = header(symbol_table, 16)
    for entry in range(0, header(symbol_table, 20), 16):
        value, shndx = (int.from_bytes(blob[symbols_at + entry + at:symbols_at + entry + at + width], 'little') for at, width in ((4, 4), (14, 2)))
        if shndx != text_index:
            continue
        if start <= value < start + keep:
            blob[symbols_at + entry + 4:symbols_at + entry + 8] = (value - start).to_bytes(4, 'little')
        else:  # the helper that was cut away: an inert local symbol
            blob[symbols_at + entry + 4:symbols_at + entry + 12] = bytes(8)
            blob[symbols_at + entry + 12] = 0
    text_at = header(text_index, 16)
    blob[text_at:text_at + keep] = blob[text_at + start:text_at + start + size] + bytes(keep - size)  # the padding is nops
    blob[header(relocation_index, 16):header(relocation_index, 16) + 8 * len(kept)] = b''.join(kept)
    blob[section_table + relocation_index * entry_size + 20:section_table + relocation_index * entry_size + 24] = (8 * len(kept)).to_bytes(4, 'little')
    blob[section_table + text_index * entry_size + 20:section_table + text_index * entry_size + 24] = keep.to_bytes(4, 'little')
    trimmed = os.path.join(BUILD, 'trimmed', os.path.relpath(object_path, UNITS).replace(os.sep, '_'))
    os.makedirs(os.path.dirname(trimmed), exist_ok=True)
    open(trimmed, 'wb').write(blob)
    return trimmed

def trim_rodata(object_path):
    """A copy of the object whose .rodata ends where its content ends: the compiler pads the section to its alignment (a 14-entry jump table
    becomes 64 bytes in a 16-aligned section), and the padding would overwrite the retail bytes that follow the table. The content ends at the
    last non-zero byte or the last relocated word (a jump table's entries are relocations, zero in the object); at most the alignment minus one
    byte is cut. Returns (path, new size); the path is unchanged when nothing is cut."""
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        rodata = elf.get_section_by_name('.rodata')
        if rodata is None or not rodata['sh_size']:
            return object_path, 0
        data = rodata.data()
        end = len(data.rstrip(b'\0'))
        relocations = elf.get_section_by_name('.rel.rodata')
        for relocation in (relocations.iter_relocations() if relocations else []):
            end = max(end, relocation['r_offset'] + 4)
        end = (end + 3) & ~3
        size = max(end, len(data) - (rodata['sh_addralign'] - 1)) if rodata['sh_addralign'] > 1 else len(data)
        index = elf.get_section_index('.rodata')
    if size >= len(data):
        return object_path, len(data)
    blob = bytearray(open(object_path, 'rb').read())
    section_table, entry_size = (int.from_bytes(blob[at:at + width], 'little') for at, width in ((0x20, 4), (0x2E, 2)))
    blob[section_table + index * entry_size + 20:section_table + index * entry_size + 24] = size.to_bytes(4, 'little')
    trimmed = os.path.join(BUILD, 'trimmed', 'ro_' + os.path.relpath(object_path, UNITS).replace(os.sep, '_').replace(BUILD + os.sep, ''))
    os.makedirs(os.path.dirname(trimmed), exist_ok=True)
    open(trimmed, 'wb').write(blob)
    return trimmed, size

def inspect(object_path):
    """(text size, undefined symbol names) of an object, or None when it cannot stand in for assembly: a relocation
    into a section other than .text means the function uses its own data (jump table, literal), which the image
    keeps elsewhere."""
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        text = elf.get_section_by_name('.text')
        if text is None:
            return None
        symbol_table = elf.get_section_by_name('.symtab')
        undefined = set()
        uses_rodata = False
        relocations = elf.get_section_by_name('.rel.text')
        for relocation in (relocations.iter_relocations() if relocations else []):
            symbol = symbol_table.get_symbol(relocation['r_info_sym'])
            if symbol['st_shndx'] == 'SHN_UNDEF':
                undefined.add(symbol.name)
            elif isinstance(symbol['st_shndx'], int):
                section_name = elf.get_section(symbol['st_shndx']).name
                if section_name == '.rodata':
                    uses_rodata = True
                elif section_name != '.text':
                    return None
        rodata = elf.get_section_by_name('.rodata')
        return text['sh_size'], undefined, (rodata['sh_size'] if uses_rodata and rodata else 0)

def derive_rodata_base(address, object_path):
    """Where the object's own .rodata (jump tables, literals) sits in the retail image: the hi/lo pairs against the
    section symbol give base + offset in the retail instructions; None unless every pair agrees."""
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        data = elf.get_section_by_name('.text').data()
        symbol_table = elf.get_section_by_name('.symtab')
        entries = [(r['r_offset'], r['r_info_type'], symbol_table.get_symbol(r['r_info_sym'])) for r in elf.get_section_by_name('.rel.text').iter_relocations()]
        rodata_index = elf.get_section_index('.rodata')
    base = FILE_OFFSET_OF_TEXT + address - TEXT_START
    signed = lambda value: value - 0x10000 if value & 0x8000 else value
    word = lambda offset, blob, origin: int.from_bytes(blob[origin + offset:origin + offset + 4], 'little')
    bases = set()
    for index, (offset, kind, symbol) in enumerate(entries):
        if kind != 5 or symbol['st_shndx'] != rodata_index:
            continue
        low = next(((o, k) for o, k, s in entries[index + 1:] if k == 6 and s['st_shndx'] == rodata_index), None)
        if low is None:
            return None
        retail_value = ((word(offset, retail, base) & 0xFFFF) << 16) + signed(word(low[0], retail, base) & 0xFFFF)
        object_value = ((word(offset, data, 0) & 0xFFFF) << 16) + signed(word(low[0], data, 0) & 0xFFFF)
        bases.add(retail_value - object_value)
    return next(iter(bases)) if len(bases) == 1 else None

def retarget_rodata(address, object_path):
    """For an object whose rodata is string literals the retail keeps in another order (so no single base fits): a copy of the object
    whose hi/lo immediates are the retail ones, with its own .rodata linked where nothing is loaded (address 0, NOLOAD). Every literal
    is checked: the string the object holds at the offset must be the string the retail has at the address. None if it does not hold."""
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        text = elf.get_section_by_name('.text')
        rodata = elf.get_section_by_name('.rodata')
        symbol_table = elf.get_section_by_name('.symtab')
        if elf.get_section_by_name('.rel.rodata') is not None:
            return None
        entries = [(r['r_offset'], r['r_info_type'], symbol_table.get_symbol(r['r_info_sym'])) for r in elf.get_section_by_name('.rel.text').iter_relocations()]
        data, rodata_data, text_offset = text.data(), rodata.data(), text['sh_offset']
        rodata_index = elf.get_section_index('.rodata')
    base = FILE_OFFSET_OF_TEXT + address - TEXT_START
    signed = lambda value: value - 0x10000 if value & 0x8000 else value
    word = lambda offset, blob, origin: int.from_bytes(blob[origin + offset:origin + offset + 4], 'little')
    cstring = lambda blob, start: blob[start:blob.find(0, start)] if blob.find(0, start) >= 0 else None
    patched = bytearray(open(object_path, 'rb').read())
    for index, (offset, kind, symbol) in enumerate(entries):
        if kind != 5 or symbol['st_shndx'] != rodata_index:
            continue
        low = next(((o, k) for o, k, s in entries[index + 1:] if k == 6 and s['st_shndx'] == rodata_index), None)
        if low is None:
            return None
        retail_value = ((word(offset, retail, base) & 0xFFFF) << 16) + signed(word(low[0], retail, base) & 0xFFFF)
        object_value = ((word(offset, data, 0) & 0xFFFF) << 16) + signed(word(low[0], data, 0) & 0xFFFF)
        retail_at = FILE_OFFSET_OF_TEXT + retail_value - TEXT_START
        if not 0 <= object_value < len(rodata_data) or retail_at < 0 or cstring(rodata_data, object_value) is None or cstring(rodata_data, object_value) != cstring(retail, retail_at):
            return None
        for at in (offset, low[0]):
            patched[text_offset + at:text_offset + at + 2] = retail[base + at:base + at + 2]
    path = os.path.join(BUILD, 'retargeted', os.path.relpath(object_path, UNITS).replace(os.sep, '_'))
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, 'wb').write(patched)
    return path

def derive_addresses(address, object_path, names):
    """Addresses of names the symbol table lacks, read from the retail instructions at their relocation sites: a jal
    gives its target, a lui/addiu or load pair its hi/lo halves; the addend the object carries is subtracted."""
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        text_section = elf.get_section_by_name('.text')
        data = text_section.data()
        symbol_table = elf.get_section_by_name('.symtab')
        entries = [(r['r_offset'], r['r_info_type'], symbol_table.get_symbol(r['r_info_sym']).name)
                   for r in elf.get_section_by_name('.rel.text').iter_relocations()]
    base = FILE_OFFSET_OF_TEXT + address - TEXT_START
    word = lambda offset, blob, origin: int.from_bytes(blob[origin + offset:origin + offset + 4], 'little')
    found = {}
    for index, (offset, kind, name) in enumerate(entries):
        if name not in names:
            continue
        if kind == 4:  # R_MIPS_26
            value = ((word(offset, retail, base) & 0x3FFFFFF) << 2) - ((word(offset, data, 0) & 0x3FFFFFF) << 2)
        elif kind == 5:  # R_MIPS_HI16: pair it with the next LO16 of the same name
            low = next((o, k, n) for o, k, n in entries[index + 1:] if k == 6 and n == name) if any(k == 6 and n == name for _, k, n in entries[index + 1:]) else None
            if low is None:
                continue
            signed = lambda value: value - 0x10000 if value & 0x8000 else value
            retail_value = ((word(offset, retail, base) & 0xFFFF) << 16) + signed(word(low[0], retail, base) & 0xFFFF)
            object_value = ((word(offset, data, 0) & 0xFFFF) << 16) + signed(word(low[0], data, 0) & 0xFFFF)
            value = retail_value - object_value
        else:
            continue
        found.setdefault(name, set()).add(value & 0xFFFFFFFF)
    return {name: next(iter(values)) for name, values in found.items() if len(values) == 1}

candidates = {}
retargeted = set()  # addresses whose object keeps its rodata out of the image (retarget_rodata)  # address -> (object path, undefined names)
for line in list(open(os.path.join('src', 'MANIFEST.tsv')))[1:]:
    address_text, name, size, file = line.rstrip('\n').split('\t')
    address = int(address_text, 16)
    object_path = os.path.join(UNITS, file + '.o')
    if address not in by_address or not os.path.isfile(object_path):
        continue
    function = by_address[address]
    found = inspect(object_path)
    keep = (int(size) + 7) & ~7
    start = function_offset(object_path, name) if found is not None else 0
    if found is not None and found[0] > keep and keep <= function['end'] - address:
        object_path = trim_object(object_path, start, int(size), keep)
        found = inspect(object_path)
    if found is None or found[0] > function['end'] - address:
        continue
    rodata_base = None
    if found[2]:
        object_path, rodata_size = trim_rodata(object_path)
        found = (found[0], found[1], rodata_size)
        rodata_base = derive_rodata_base(address, object_path)
        if rodata_base is None:
            object_path = retarget_rodata(address, object_path)
            if object_path is None:
                continue
            retargeted.add(address)
            found = (found[0], found[1], 0)
        elif not RODATA_START <= rodata_base < RODATA_END:
            continue
    candidates[address] = (object_path, found[1], found[2], rodata_base)
# two functions can share a string (the later one's literal is the tail of the earlier one's): their rodata holes overlap, so the later
# object links like a string-only one whose rodata stays out of the image and whose literal addresses are the retail ones
holes_taken = []
for address in sorted(candidates, key=lambda a: candidates[a][3] or 0):
    object_path, names, size, base = candidates[address]
    if not size:
        continue
    if any(base < end and start < base + size for start, end in holes_taken):
        retargeted_path = retarget_rodata(address, object_path)
        if retargeted_path is None:
            del candidates[address]
            continue
        retargeted.add(address)
        candidates[address] = (retargeted_path, names, 0, None)
    else:
        holes_taken.append((base, base + size))
print(f'{len(candidates)} of {len(functions)} functions have a usable object', flush=True)

def assemble_run(run_lines, address):
    text = ''.join(header + run_lines)
    digest = hashlib.sha1(text.encode()).hexdigest()[:10]
    source = os.path.join(RUNS, f'run_{address:06X}_{digest}.s')
    object_path = source[:-2] + '.o'
    if not os.path.exists(object_path):
        open(source, 'w').write(text)
        subprocess.check_call([BINUTILS + '-as', '-EL', '-march=r5900', '-mabi=eabi', '-G0', '-no-pad-sections',
                               '-I', 'include', '-I', os.path.join(SPLAT, 'asm'), '-o', object_path, source])
    return object_path

def link(swapped):
    # contiguous assembly functions form a run
    runs, current, last_unit = [], None, None
    for function in functions:
        if function['address'] in swapped:
            current = None
            continue
        if current is None or function['unit'] != last_unit:
            current = (function['address'], [])
            runs.append(current)
        last_unit = function['unit']
        current[1].extend(function['lines'])
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as pool:
        run_objects = list(pool.map(lambda run: assemble_run(run[1], run[0]), runs))
    placed = [(address, path) for (address, _), path in zip(runs, run_objects)]
    placed += [(address, candidates[address][0]) for address in swapped]
    defined = {function['name'] for function in functions if function['address'] not in swapped}
    return placed, defined

derived = {}

def definitions(swapped, defined):
    lines = []
    seen = set()
    for address in swapped:
        name = by_address[address]['name']
        lines.append(f'{name} = 0x{address:X};')
        seen.add(name)
    for address in swapped:
        for name in candidates[address][1]:
            if name in seen or name in defined:
                continue
            seen.add(name)
            match = ADDRESS_NAME.match(name)
            if match:
                lines.append(f'{name} = 0x{match.group(2)};')
            elif name in symbols:
                lines.append(f'{name} = 0x{symbols[name]:X};')
            else:
                derived.setdefault(name, derive_addresses(address, candidates[address][0], {name}).get(name))
                if derived[name] is not None:
                    lines.append(f'{name} = 0x{derived[name]:X};')
    lines += [line.rstrip('\n') for line in open(os.path.join(SPLAT, 'undefined_syms_auto.txt'))]
    return lines

def assemble_piece(name, start):
    stem = os.path.join(BUILD, 'data', f'{start:06X}_asm')
    source = os.path.join(SPLAT, 'asm', 'data', f"{name}.{name.split('/')[0]}.s")
    piece_sources[stem + '.o'] = source
    subprocess.check_call([BINUTILS + '-as', '-EL', '-march=r5900', '-mabi=eabi', '-G0', '-no-pad-sections',
                           '-I', 'include', '-I', os.path.join(SPLAT, 'asm'), '-o', stem + '.o', source])
    return stem + '.o'

PROVIDED_NAME = re.compile(r'^[A-Za-z]{1,6}_([0-9A-F]{8})$')  # D_002A4E80, jtbl_002A4160

def piece_definitions(pieces):
    """PROVIDE lines for the names the assembly refers to that no object defines (an address inside a raw piece, a symbol of the
    retail's code): the address comes from the name or from Splat's symbol list. PROVIDE only defines a name that is referenced
    and still undefined, so it never clashes with a label of the per-symbol data."""
    lines = []
    for name in sorted(referenced_names):
        match = PROVIDED_NAME.match(name)
        if match:
            lines.append(f'PROVIDE({name} = 0x{match.group(1)});')
        elif name in symbols:
            lines.append(f'PROVIDE({name} = 0x{symbols[name]:X});')
    return lines

referenced_names = set()
for directory, _, files in os.walk(os.path.join(SPLAT, 'asm')):
    for file in files:
        if file.endswith('.s'):
            referenced_names.update(re.findall(r'[A-Za-z_][A-Za-z0-9_]*', open(os.path.join(directory, file)).read()))
piece_sources = {}

def build(swapped, raw_pieces):
    placed, defined = link(swapped)
    sections = [f'    .t_{address:06X} 0x{address:X} : SUBALIGN(1) {{ */{os.path.basename(path)}(.text) }}'
                for address, path in sorted(placed)]
    sections += [f'    .nl_{address:06X} 0x0 (NOLOAD) : SUBALIGN(1) {{ */{os.path.basename(candidates[address][0])}(.rodata) }}' for address in sorted(swapped & retargeted)]
    # rodata and data are linked as pieces (config/us/pieces.tsv); a function's own rodata goes where the retail image
    # has it, so the pieces are cut around those holes
    holes = sorted((candidates[address][3], candidates[address][3] + candidates[address][2], address)
                   for address in swapped if candidates[address][2])
    for (_, previous_end, _), (next_start, _, address) in zip(holes, holes[1:]):
        if next_start < previous_end:
            raise SystemExit(f'rodata of {address:#X} overlaps another one')
    cuts = {RODATA_START, region_end} | set(piece_starts)
    for hole_start, hole_end, _ in holes:
        cuts |= {hole_start, hole_end}
    cuts = sorted(cut for cut in cuts if RODATA_START <= cut <= region_end)
    inside_hole = lambda address: any(hole_start <= address < hole_end for hole_start, hole_end, _ in holes)
    jobs = [(a, b) for a, b in zip(cuts, cuts[1:]) if not inside_hole(a)]
    def wrap(job):
        a, b = job
        name = piece_ranges.get((a, b))
        if name and name not in raw_pieces:
            return a, assemble_piece(name, a), '.' + name.split('/')[0]
        stem = os.path.join(BUILD, 'data', f'{a:06X}_{hashlib.sha1(region[a - RODATA_START:b - RODATA_START]).hexdigest()[:8]}')
        if not os.path.exists(stem + '.o'):
            open(stem + '.bin', 'wb').write(region[a - RODATA_START:b - RODATA_START])
            symbol = f'D_{a:08X}' if a in piece_starts else f'data_piece_{a:06X}'
            subprocess.run(f'printf \'.section .data, "aw"\\n.global {symbol}\\n{symbol}:\\n.incbin "{stem}.bin"\\n\' | {BINUTILS}-as -EL -march=r5900 -o {stem}.o -',
                           shell=True, check=True)
        return a, stem + '.o', '.data'
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as pool:
        pieces = list(pool.map(wrap, jobs))
    pieces += [(candidates[address][3], candidates[address][0], '.rodata') for _, _, address in holes]
    rodata_sections = [f'    .ro_{piece[0]:06X} 0x{piece[0]:X} : SUBALIGN(1) {{ */{os.path.basename(piece[1])}({piece[2]}) }}'
                       for piece in sorted(pieces)]
    tail = [line.rstrip('\n') for line in open(os.path.join('config', 'us', 'image.ld'))
            if not line.lstrip().startswith(('SECTIONS', '. = 0x100000', '.text', '}', '. = 0x262380', '.rodata', '. = 0x2ac880', '.data'))]
    script = ['SECTIONS {'] + sections + rodata_sections + tail + ['}'] + definitions(swapped, defined) + piece_definitions(pieces)
    open(os.path.join(BUILD, 'link.ld'), 'w').write('\n'.join(script) + '\n')
    objects = list(dict.fromkeys([path for _, path in placed] + [piece[1] for piece in pieces] + [os.path.join(BUILD, f'{name}.o') for name in ('vutext', 'irx_gap', 'irx')]))
    subprocess.check_call([BINUTILS + '-ld', '-EL', '-T', os.path.join(BUILD, 'link.ld'), '-o', os.path.join(BUILD, 'image.elf'),
                           *objects, '--no-warn-mismatch', '--unresolved-symbols=ignore-all'])
    subprocess.check_call([BINUTILS + '-objcopy', '-O', 'binary', os.path.join(BUILD, 'image.elf'), os.path.join(BUILD, 'image.bin')])
    return open(os.path.join(BUILD, 'image.bin'), 'rb').read(), {piece[0] for piece in pieces if piece[1].endswith('_asm.o')}

swapped = set(candidates)
differences = {}
raw_pieces = set()
for attempt in range(1, 12):
    image, asm_pieces = build(swapped, raw_pieces)
    failing = set()
    bad_pieces = {piece_ranges[(start, end)] for start in asm_pieces for end in [start + next(size for _, begin, size in piece_list if begin == start)]
                  if image[start - TEXT_START:end - TEXT_START] != region[start - RODATA_START:end - RODATA_START]}
    raw_pieces |= bad_pieces
    for address in swapped:
        end = by_address[address]['end']
        expected = retail[FILE_OFFSET_OF_TEXT + address - TEXT_START:FILE_OFFSET_OF_TEXT + end - TEXT_START]
        if image[address - TEXT_START:end - TEXT_START] != expected:
            failing.add(address)
            if attempt == 1:
                actual = image[address - TEXT_START:end - TEXT_START]
                differences[address] = next((f'bytes differ at +{k:#x}' for k in range(0, min(len(actual), len(expected)), 4) if actual[k:k + 4] != expected[k:k + 4]), 'bytes differ')
        elif candidates[address][2]:
            start = candidates[address][3]
            retail_ro = retail[FILE_OFFSET_OF_TEXT + start - TEXT_START:FILE_OFFSET_OF_TEXT + start - TEXT_START + candidates[address][2]]
            if image[start - TEXT_START:start - TEXT_START + candidates[address][2]] != retail_ro:
                failing.add(address)
    print(f'attempt {attempt}: {len(swapped)} swapped, {len(failing)} differ; {len(asm_pieces) - len(bad_pieces)} pieces from assembly, {len(bad_pieces)} differ', flush=True)
    if not failing and not bad_pieces:
        break
    if attempt == 1:
        defined_names = {function['name'] for function in functions} | set(symbols)
        with open(os.path.join(BUILD, 'fallbacks.tsv'), 'w') as handle:
            for address in sorted(failing):
                missing = sorted(name for name in candidates[address][1] if name not in defined_names and not ADDRESS_NAME.match(name))
                handle.write(f"{address:#X}\t{by_address[address]['name']}\t{'unresolved: ' + ' '.join(missing[:4]) if missing else differences.get(address, 'rodata differs')}\n")
    swapped -= failing
else:
    sys.exit('did not settle')
with open(os.path.join('config', 'us', 'swapped.tsv'), 'w') as handle:
    for address in sorted(swapped):
        handle.write(f"{address:#X}\t{by_address[address]['name']}\n")
with open(os.path.join(BUILD, 'derived.tsv'), 'w') as handle:
    for name, address in sorted(derived.items()):
        if address is not None:
            handle.write(f'{name}\t{address:#X}\n')
print(f'{len(swapped)} functions come from C, {len(functions) - len(swapped)} from assembly')
