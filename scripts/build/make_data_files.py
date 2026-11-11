#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""make_data_files.py: writes typed C++ for the `.data` pieces of the image (config/us/pieces.tsv `data/...`), or with --section rodata for the
`.rodata` pieces (`rodata/...`, as `extern const` globals), and proves each one against retail before it is listed in config/us/data_files.tsv
(docs/ROADMAP.md item 3, docs/contributing/exceptions.md "Game data defined in source"). In .rodata it leaves out what a compiled object may own
(build/image/owned_rodata.tsv, from link_image.py), jump tables of unmatched functions and plain word arrays over 64 elements (untyped).

A piece is one retail data region that Splat cut at symbol boundaries (build/splat/asm/data/data/<piece>.data.s). The source defines one global per
Splat label, spanning the label's bytes up to the next label (retail's padding is part of the object before it, as the 16-byte vectors showed):
  - words are `unsigned int` (`void *` when one of them is an address: `(void *)name`, `(void *)((char *)name + 0x20)`), floats `float`,
    shorts `short`, bytes `unsigned char`, strings `char name[span] = "..."`; a label that mixes kinds is an anonymous struct of one member per run;
  - every name the data points at is declared `extern` (a function as `extern "C" void name();`, anything else as `extern char name[];`);
  - each definition carries `// data-ok: retail's bytes at 0xADDRESS`.
The object is compiled like any source (scripts/build/compile_unit.py) and a piece is proved when its `.data` is exactly the retail bytes (a word
the object relocates is checked as symbol address + stored addend instead), it has no other data section, and its globals sit where retail's labels
are. scripts/build/link_image.py links it at the piece's address and checks the bytes again.

  .venv/bin/python scripts/build/make_data_files.py --list                 # the pieces and their size
  .venv/bin/python scripts/build/make_data_files.py [--only data/rumble] [--no-pointers] [--write] [--report FILE]

--write writes src/data/<piece>.cpp for the proved pieces and rows in config/us/data_files.tsv (kept sorted); it never touches other rows."""
import argparse
import concurrent.futures
import os
import re
import struct
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)

ELF = os.path.join('work', 'elf', 'SCUS_973.16')
SPLAT = os.path.join('build', 'splat')
SCRATCH = os.path.join('work', 'boundaries', 'data_build')
DATA_LIST = os.path.join('config', 'us', 'data_files.tsv')
TEXT_START, FILE_OFFSET_OF_TEXT = 0x100000, 0x80
LINE = re.compile(r'^\s+/\* [0-9A-F]+ ([0-9A-F]{8})(?: ([0-9A-F]*))? \*/\s+(\.\w+)\s*(.*?)\s*$')
IDENTIFIER = re.compile(r'^[A-Za-z_][A-Za-z0-9_]*$')
POINTER = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)(?: \+ (0x[0-9A-Fa-f]+))?$')


def retail_bytes(address, size):
    with open(ELF, 'rb') as handle:
        handle.seek(FILE_OFFSET_OF_TEXT + address - TEXT_START)
        return handle.read(size)


def pieces(section='data'):
    """[(name, start, size)] of the pieces of one section ('data' or 'rodata')."""
    rows = [line.rstrip('\n').split('\t') for line in open(os.path.join('config', 'us', 'pieces.tsv'))]
    return [(name, int(start, 16), int(size)) for name, start, size in rows if name.startswith(section + '/')]


def owned_ranges():
    """[(start, end)] of the .rodata that compiled objects may own (a function's or a whole file's literals and jump tables), as
    scripts/build/link_image.py wrote it on its last run (build/image/owned_rodata.tsv, after `make elf`): a .rodata label inside one stays theirs."""
    path = os.path.join('build', 'image', 'owned_rodata.tsv')
    if not os.path.isfile(path):
        raise SystemExit('build/image/owned_rodata.tsv is missing: run make elf first')
    return [(int(low, 16), int(high, 16)) for low, high in (line.rstrip('\n').split('\t') for line in list(open(path))[1:])]


def known_names():
    """({address: name} of every label Splat wrote, set of the function names)."""
    import asm_units
    _, functions = asm_units.read_units(SPLAT)
    by_address = {function['address']: function['name'] for function in functions}
    labels = dict(by_address)
    for directory, _, files in os.walk(os.path.join(SPLAT, 'asm', 'data')):
        for file in files:
            if file.endswith('.s') and not file.startswith('all.'):
                for match in re.finditer(r'^glabel (\S+)\n\s+/\* [0-9A-F]+ ([0-9A-F]{8})', open(os.path.join(directory, file)).read(), re.M):
                    labels.setdefault(int(match.group(2), 16), match.group(1))
    # names Splat's labels lack: the symbol list and the auto-generated ones (an address inside an object); a small value (< TEXT_START) is a number, not an address
    for path in (os.path.join('config', 'us', 'symbol_addrs.txt'), os.path.join(SPLAT, 'undefined_syms_auto.txt')):
        for line in open(path):
            match = re.match(r'(\S+) = (0x[0-9A-Fa-f]+);', line)
            if match and int(match.group(2), 16) >= TEXT_START:
                labels.setdefault(int(match.group(2), 16), match.group(1))
    return labels, {function['name'] for function in functions}


def parse_piece(name):
    """[{name, address, items: [(address, directive, argument)]}] of a piece's Splat assembly."""
    labels = []
    path = os.path.join(SPLAT, 'asm', 'data', name + '.' + name.split('/')[0] + '.s')
    for line in open(path):
        label = re.match(r'^glabel (\S+)', line)
        if label:
            labels.append({'name': label.group(1), 'items': []})
            continue
        match = LINE.match(line)
        if match and labels:
            address, _, directive, argument = match.groups()
            labels[-1]['items'].append((int(address, 16), directive, argument))
    for label in labels:
        label['address'] = label['items'][0][0]
    return labels


def float_literal(bits):
    """The shortest C float literal that round-trips `bits`, or None for a NaN or infinity."""
    value = struct.unpack('<f', struct.pack('<I', bits))[0]
    if value != value or value in (float('inf'), float('-inf')):
        return None
    for precision in range(1, 10):
        text = '%.*g' % (precision, value)
        try:
            if struct.pack('<f', float(text)) == struct.pack('<I', bits):
                break
        except OverflowError:
            continue
    if bits == 0x80000000:
        return '-0.0f'
    return text + ('' if re.search(r'[.eE]', text) else '.0') + 'f'


def build_runs(label, end, names, functions):
    """[(kind, [element texts], size in bytes, referenced names)] of a label's span, or a string with the reason it cannot be typed."""
    items, runs = label['items'], []
    for index, (address, directive, argument) in enumerate(items):
        following = items[index + 1][0] if index + 1 < len(items) else end
        size = following - address
        data = retail_bytes(address, size)
        if directive == '.word' and argument.startswith('.L'):
            return 'a jump table (its entries are code labels)'
        if directive == '.word' and size == 4:
            word = struct.unpack('<I', data)[0]
            pointer = POINTER.match(argument)
            if pointer and not argument.startswith('0x') and pointer.group(1) in names:
                target, offset = pointer.group(1), int(pointer.group(2) or '0', 16)
                text = f'(void *){target}' if not offset else f'(void *)((char *){target} + {offset:#x})'
                runs.append(('ptr', text, 4, target))
            else:
                runs.append(('word', f'{word:#x}' if word >= 0x100 else str(word), 4, None))
        elif directive == '.float' and size == 4:
            literal = float_literal(struct.unpack('<I', data)[0])
            runs.append(('float', literal, 4, None) if literal else ('word', hex(struct.unpack("<I", data)[0]), 4, None))
        elif directive == '.short' and size == 2:
            runs.append(('short', str(struct.unpack('<h', data)[0]), 2, None))
        elif directive == '.byte' and size == 1:
            runs.append(('byte', str(data[0]), 1, None))
        elif directive in ('.asciz', '.ascii'):
            content = data.split(b'\0', 1)[0]  # Splat splits some strings over lines: the literal comes from the bytes
            if b'\0' not in data:
                return 'a string without its terminator'
            runs.append(('str', '"' + ''.join(chr(byte) if 0x20 <= byte < 0x7F and chr(byte) not in '"\\?' else '\\%03o' % byte for byte in content) + '"', size, None))
        else:
            return f'{directive} of {size} bytes'
    grouped = []
    for kind, text, size, target in runs:
        kind = 'w4' if kind in ('word', 'ptr') else kind
        if grouped and grouped[-1][0] == kind and kind != 'str':
            grouped[-1][1].append(text)
            grouped[-1][2] += size
            grouped[-1][3].update([target] if target else [])
        else:
            grouped.append([kind, [text], size, set([target] if target else [])])
    return grouped


HAND_TYPED = 'Typed by hand (make_data_files.py keeps this file)'
WORD_ARRAY_LIMIT = 64  # as BYTE_DUMP_LIMIT in scripts/matching/check_source.py, for a run of plain `unsigned int`
BYTE_DUMP_LIMIT = 64  # as in scripts/matching/check_source.py: a longer byte array (not a string) is a dump


def untyped(runs):
    """Why a label's runs would be a dump rather than typed data (docs/contributing/exceptions.md "Game data defined in source"), or None: a
    plain word array over WORD_ARRAY_LIMIT elements (its type has to come from the code that reads it) or a byte array over BYTE_DUMP_LIMIT."""
    for kind, elements, size, targets in runs:
        if kind == 'w4' and not targets and len(elements) > WORD_ARRAY_LIMIT:
            return f'a plain word array over {WORD_ARRAY_LIMIT} elements needs a type from the code that reads it'
        if kind == 'byte' and len(elements) > BYTE_DUMP_LIMIT:
            return f'a byte array over {BYTE_DUMP_LIMIT} elements is a dump'
    return None


CTYPE = {'w4': 'unsigned int', 'float': 'float', 'short': 'short', 'byte': 'unsigned char', 'str': 'char'}


def member(kind, elements, size, name, as_pointer):
    """(declaration text, initializer text) of one run: a scalar or an array of the run's type."""
    ctype = 'void *' if kind == 'w4' and as_pointer else CTYPE[kind]
    if kind == 'w4' and as_pointer:
        elements = [element if element.startswith('(void *)') else ('0' if element in ('0x0', '0') else f'(void *){element}') for element in elements]
    if kind == 'str':
        return f'char {name}[{size}]', elements[0]
    unit = {'w4': 4, 'float': 4, 'short': 2, 'byte': 1}[kind]
    if len(elements) == 1 and size == unit:
        return f'{ctype}{"" if ctype.endswith("*") else " "}{name}', elements[0]
    return f'{ctype}{"" if ctype.endswith("*") else " "}{name}[{size // unit}]', '{' + ', '.join(elements) + '}'


def natural_alignment(runs, size):
    """The alignment this compiler gives a global made of `runs`: 8 once it is 8 bytes or more (arrays and structs alike), else its widest element."""
    if size >= 8:
        return 8
    return max({'w4': 4, 'float': 4, 'short': 2, 'byte': 1, 'str': 1}[run[0]] for run in runs)


def groups_of(name, start, size, names, functions, owned=None):
    """[(start, size, labels)]: the piece cut where the compiler's layout would leave retail's (one source, one object per group, linked at its own
    address): retail packs some aggregates at 4 where this compiler aligns them to 8. A string that cannot be typed returns the reason instead.
    With `owned` (the .rodata pass), a label inside an owned range or one that cannot be typed is left to its owner or the assembly, and the
    groups are cut around it; the second value lists those labels with the reason."""
    labels = parse_piece(name)
    if not labels or labels[0]['address'] != start:
        return 'the first label is not at the start of the piece'
    groups, current, origin, offset, skipped = [], [], start, 0, []
    for index, label in enumerate(labels):
        end = labels[index + 1]['address'] if index + 1 < len(labels) else start + size
        runs = build_runs(label, end, names, functions)
        if owned is not None:
            why = 'owned by a compiled object' if any(low < end and label['address'] < high for low, high in owned) else (runs if isinstance(runs, str) else untyped(runs))
            if why:
                skipped.append((label['name'], label['address'], end - label['address'], why))
                if current:
                    groups.append((origin, label['address'] - origin, current))
                current, origin, offset = [], end, 0
                continue
        if isinstance(runs, str):
            return f'{label["name"]}: {runs}'
        alignment = natural_alignment(runs, end - label['address'])
        expected = (offset + alignment - 1) // alignment * alignment
        if current and label['address'] - origin != expected:
            groups.append((origin, label['address'] - origin, current))
            current, origin, offset = [], label['address'], 0
            expected = 0
        if not current:
            origin, offset = label['address'], 0
        current.append(label)
        offset = label['address'] - origin + (end - label['address'])
    if current:
        groups.append((origin, start + size - origin, current))
    return (groups, skipped) if owned is not None else groups


def make_source(name, start, size, names, functions, allow_pointers=True, labels=None, section='data'):
    """(text, why not): the C++ source of a group of labels (a whole piece when `labels` is None). For .rodata every global is `const` (with
    `extern`, so it keeps external linkage in C++), which this compiler places in .rodata."""
    constant = section == 'rodata'
    labels = labels if labels is not None else parse_piece(name)
    if not labels or labels[0]['address'] != start:
        return None, 'the first label is not at the start of the piece'
    defined = {label['name'] for label in labels}
    externs, bodies, aliases, seen = {}, [], {}, set()
    for index, label in enumerate(labels):
        end = labels[index + 1]['address'] if index + 1 < len(labels) else start + size
        runs = build_runs(label, end, names, functions)
        if isinstance(runs, str):
            return None, f'{label["name"]}: {runs}'
        if not IDENTIFIER.match(label['name']):
            return None, f'name {label["name"]}'
        has_pointer = any(run[3] for run in runs)
        if has_pointer and not allow_pointers:
            return None, f'{label["name"]} holds addresses'
        for run in runs:
            for target in run[3]:
                if target not in defined:
                    externs[target] = target in functions
                elif target in seen:  # defined above in this file: its address
                    run[1][:] = [re.sub(rf'\(void \*\){target}\b', f'(void *)&{target}', re.sub(rf'\(char \*\){target}\b', f'(char *)&{target}', element)) for element in run[1]]
                else:  # defined further down: an alias for its symbol (an `asm` label, as the retail-name exception does)
                    run[1][:] = [re.sub(rf'\b{target}\b', f'forward_{target}', element) for element in run[1]]
                    aliases[target] = f'forward_{target}'
        # a run of words next to a pointer run is part of the same address table: one `void *` array
        if len(runs) > 1 and all(run[0] == 'w4' for run in runs):
            merged = [elements for run in runs for elements in run[1]]
            runs = [['w4', merged, sum(run[2] for run in runs), set().union(*(run[3] for run in runs))]]
        marker = f"// data-ok: retail's bytes at {label['address']:#X}"
        if untyped(runs):
            return None, f'{label["name"]}: {untyped(runs)}'
        if len(runs) == 1:
            declaration, initializer = member(runs[0][0], runs[0][1], runs[0][2], label['name'], has_pointer)
            if constant:
                declaration = 'extern ' + (declaration.replace('void *', 'void *const ', 1) if declaration.startswith('void *') else 'const ' + declaration)
            bodies.append(f'{marker}\n{declaration} = {initializer};')
        else:
            members, values = [], []
            for number, run in enumerate(runs):
                declaration, initializer = member(run[0], run[1], run[2], f'm{number}', bool(run[3]))
                members.append(f'    {declaration};')
                values.append(f'    {initializer}')
            bodies.append(f'{marker}\n{"extern const " if constant else ""}struct {{\n' + '\n'.join(members) + f'\n}} {label["name"]} = {{\n' + ',\n'.join(values) + '\n};')
        seen.add(label['name'])
    lines = ['// SPDX-License-Identifier: GPL-3.0-or-later',
             f'// Retail .{section} {start:#X}-{start + size:#X} (piece {name}), one global per Splat label: written by scripts/build/make_data_files.py,',
             '// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).', '']
    for target in sorted(externs):
        lines.append(f'extern "C" void {target}();' if externs[target] else f'extern char {target}[];')
    for target in sorted(aliases):
        lines.append(f'extern char {aliases[target]}[] asm("{target}");')
    if externs or aliases:
        lines.append('')
    lines.append('\n\n'.join(bodies))
    return '\n'.join(lines) + '\n', None


def prove(path, name, start, size, names, section_name='data'):
    """None when the object's .data (.rodata for section 'rodata') is retail's bytes (relocated words checked as symbol address + addend), else
    the cause."""
    from elftools.elf.elffile import ELFFile
    import compile_unit
    os.makedirs(SCRATCH, exist_ok=True)
    stem = os.path.join(SCRATCH, name.replace('/', '__'))
    ok, message = compile_unit.compile_object('c++', path, stem + '.o')
    if not ok:
        return 'compile: ' + message.strip().replace('\n', ' ')[:200]
    with open(stem + '.o', 'rb') as handle:
        elf = ELFFile(handle)
        own = '.' + section_name
        for section in elf.iter_sections():
            if section.name in ('.data', '.rodata', '.bss', '.sdata', '.sbss', '.sdata2') and section.name != own and section['sh_size']:
                return f'the object has a {section.name}'
        data = elf.get_section_by_name(own)
        if data is None or not size <= data['sh_size'] <= size + 7 or data.data()[size:].strip(b'\0'):  # the compiler pads the section to 8: link_image trims it
            return f'size {0 if data is None else data["sh_size"]:#x}, retail {size:#x}'
        content = data.data()[:size]
        relocations = elf.get_section_by_name('.rel' + own)
        symbols = elf.get_section_by_name('.symtab')
        masked = {}
        for relocation in (relocations.iter_relocations() if relocations else []):
            symbol = symbols.get_symbol(relocation['r_info_sym'])
            masked[relocation['r_offset']] = (symbol.name, int.from_bytes(content[relocation['r_offset']:relocation['r_offset'] + 4], 'little'), relocation['r_info_type'])
    target = retail_bytes(start, size)
    address_of = names
    for offset in range(0, size, 4):
        if offset in masked:
            symbol, addend, kind = masked[offset]
            if kind != 2:
                return f'relocation type {kind} at {start + offset:#X}'
            wanted = int.from_bytes(target[offset:offset + 4], 'little')
            where = address_of.get(symbol)
            if where is None:
                return f'no address for {symbol}'
            if where + addend != wanted:
                return f'{symbol}+{addend:#x} is {where + addend:#X}, retail {wanted:#X} at {start + offset:#X}'
        elif content[offset:offset + 4] != target[offset:offset + 4]:
            return f'bytes differ at {start + offset:#X}'
    return None


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('--list', action='store_true')
    parser.add_argument('--only')
    parser.add_argument('--no-pointers', action='store_true', help='only pieces without a stored address')
    parser.add_argument('--write', action='store_true')
    parser.add_argument('--report')
    parser.add_argument('--jobs', type=int, default=os.cpu_count())
    parser.add_argument('--section', choices=('data', 'rodata'), default='data',
                        help='rodata: const globals for the .rodata pieces, leaving out what compiled objects own (needs make elf) and jump tables')
    parser.add_argument('--skipped', help='rodata: write the labels left out, with the reason, to this file')
    arguments = parser.parse_args()
    labels, functions = known_names()
    names = {name: address for address, name in labels.items()}
    chosen = [piece for piece in pieces(arguments.section) if not arguments.only or piece[0] == arguments.only]
    owned = owned_ranges() if arguments.section == 'rodata' else []  # .data: no compiled object owns any; the untyped labels are still left out
    skipped_labels = []
    if arguments.list:
        for name, start, size in chosen:
            print(f'{name}\t{start:#X}\t{size}')
        return
    os.makedirs(SCRATCH, exist_ok=True)

    def work(piece):
        name, start, size = piece
        groups = groups_of(name, start, size, names, functions, owned)
        if isinstance(groups, str):
            return [((name, start, size), None, groups)]
        groups, skipped = groups
        skipped_labels.extend(skipped)
        found = []
        for origin, length, labels in groups:
            file = name if len(groups) == 1 and origin == start else f'{name}_{origin:06x}'
            text, why = make_source(name, origin, length, names, functions, not arguments.no_pointers, labels, arguments.section)
            if text is None:
                found.append(((file, origin, length), None, why))
                continue
            path = os.path.join(SCRATCH, file.replace('/', '__') + '.cpp')
            open(path, 'w').write(text)
            found.append(((file, origin, length), text, prove(path, file, origin, length, names, arguments.section)))
        return found

    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        results = [result for group in pool.map(work, chosen) for result in group]
    proved = [(piece, text) for piece, text, why in results if text is not None and why is None]
    report = [f'{piece[0]}\t{piece[1]:#X}\t{piece[2]}\t{"proved" if why is None else "failed"}\t{why or ""}' for piece, _, why in results]
    if arguments.report:
        open(arguments.report, 'w').write('piece\tstart\tsize\tstatus\tcause\n' + '\n'.join(report) + '\n')
    print(f'{len(proved)} of {len(results)} {arguments.section} groups proved ({len(chosen)} pieces), {sum(piece[2] for piece, _ in proved)} of {sum(piece[2] for piece in chosen)} bytes')
    if arguments.skipped:
        open(arguments.skipped, 'w').write('label\taddress\tsize\treason\n' + ''.join(f'{label}\t{address:#X}\t{size}\t{why}\n' for label, address, size, why in sorted(skipped_labels, key=lambda row: row[1])))
    if arguments.write:
        existing = [line.rstrip('\n').split('\t') for line in list(open(DATA_LIST))[1:]]
        kept = [row for row in existing if not row[2].startswith(arguments.section + '/')] if not arguments.only else [row for row in existing if not row[2].startswith(arguments.only + '.') and not row[2].startswith(arguments.only + '_')]
        # a file typed by hand (HAND_TYPED in its text: a table typed from the code that reads it) stays, and so does its row
        hand = [row for row in existing if row[2].startswith(arguments.section + '/') and row not in kept
                and os.path.isfile(os.path.join('src', row[2])) and HAND_TYPED in open(os.path.join('src', row[2])).read()]
        rows = list(kept) + hand
        for (name, start, size), text in proved:
            if any(int(row[0], 16) < start + size and start < int(row[1], 16) for row in hand):
                continue
            file = name + '.cpp'
            os.makedirs(os.path.dirname(os.path.join('src', file)), exist_ok=True)
            open(os.path.join('src', file), 'w').write(text)
            rows.append([f'{start:#X}', f'{start + size:#X}', file])
        rows.sort(key=lambda row: int(row[0], 16))
        open(DATA_LIST, 'w').write('start\tend\tfile\n' + ''.join('\t'.join(row) + '\n' for row in rows))


if __name__ == '__main__':
    main()
