#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""make_whole_files.py: writes whole-file sources (config/us/whole_files.tsv, docs/ROADMAP.md item 2) from the file boundaries of the
constructor list and the per-function sources of src/, and proves each one against retail before it is listed.

A whole file holds the functions of one retail file in address order: a matched function's source (src/MANIFEST.tsv) and
`INCLUDE_ASM(0xADDRESS);` at file scope for each function that is not matched yet. The per-function sources are merged: their includes go to
the top once; a top-level item (type, declaration, helper) that two sources write the same way is kept once; a type or a helper that two
sources define differently keeps its name in the first and takes the function's address as a suffix in the later ones; a declaration of a
function the file defines is dropped when it disagrees with the definition. M2C_UNK becomes s32 (what include/m2c_macros.h defines it as),
tabs become four spaces. A file whose matched sources are all C stays C; otherwise it is C++ and its C sources go inside `extern "C" { }`,
the linkage their per-function objects had. The constructor wrapper and the static initializer stay as they are.

  .venv/bin/python scripts/build/make_whole_files.py --boundaries work/boundaries/file_boundaries.tsv --list
  .venv/bin/python scripts/build/make_whole_files.py --boundaries ... --prove [--write] [--limit N] [--report work/boundaries/stage4_report.tsv]

--prove compiles every candidate (scripts/build/compile_unit.py, INCLUDE_ASM expanded from build/splat) in a scratch directory and compares
the object's .text with retail's bytes of the range, relocated fields masked on both sides (scripts/matching/compare.py's masks); a file is
proved when the sizes are equal, every word is equal and the object uses no data of its own (what scripts/build/link_image.py needs to link it
whole). --write writes the proved files to src/ and prints their config/us/whole_files.tsv rows (it never edits that list)."""
import argparse
import concurrent.futures
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'scripts', 'matching'))

ELF = os.path.join(ROOT, 'work', 'elf', 'SCUS_973.16')
SCRATCH = os.path.join(ROOT, 'work', 'boundaries', 'whole_build')
HEADER = '// SPDX-License-Identifier: GPL-3.0-or-later\n'
CLEANUP_LEFT = re.compile(r'M2C_FIELD\b|/\* Error|\b(?:unk_[0-9A-Fa-f]+|phi_[a-z0-9_]+|saved_reg_\w+)\b')
GENERIC_NAME = re.compile(r'^(?:func|fun|sub|FUN)_[0-9A-Fa-f]+$|[0-9A-Fa-f]{6,}')


# ---------------------------------------------------------------- reading the inputs

def read_table(path):
    """The rows of a tab-separated file with a header line, as dicts."""
    lines = [line.rstrip('\n') for line in open(path) if line.strip()]
    names = lines[0].split('\t')
    return [dict(zip(names, line.split('\t'))) for line in lines[1:]]


def manifest(path=None):
    """{address: (name, size, source relative to src/)} of src/MANIFEST.tsv."""
    rows = read_table(path or os.path.join(ROOT, 'src', 'MANIFEST.tsv'))
    return {int(row['address'], 16): (row['name'], int(row['size']), row['file']) for row in rows}


def listed_addresses(name):
    """Addresses of config/us/<name> (one per line, `#` comments)."""
    path = os.path.join(ROOT, 'config', 'us', name)
    if not os.path.exists(path):
        return set()
    return {int(line.split()[0], 16) for line in open(path) if line.strip() and not line.startswith('#')}


def evidenced_rows(boundaries_path):
    """The boundary rows whose end is the constructor list and whose confidence is high or medium, as (start, end, row)."""
    rows = []
    for row in read_table(boundaries_path):
        if row['confidence'] in ('high', 'medium') and row['end_evidence'].startswith('ctor_list'):
            rows.append((int(row['start'], 16), int(row['end'], 16), row))
    return rows


def object_data_use(object_path):
    """'rodata' when the object's .text reads its own .rodata, 'data' when it relocates against another section of its own, else None."""
    from elftools.elf.elffile import ELFFile
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        relocations = elf.get_section_by_name('.rel.text')
        symbols = elf.get_section_by_name('.symtab')
        use = None
        for relocation in (relocations.iter_relocations() if relocations else []):
            symbol = symbols.get_symbol(relocation['r_info_sym'])
            if isinstance(symbol['st_shndx'], int):
                section = elf.get_section(symbol['st_shndx']).name
                if section == '.rodata':
                    use = use or 'rodata'
                elif section != '.text':
                    use = 'data'
        return use


def exclusion(functions, matched, swapped):
    """Why a file cannot take the whole-file path as it is (None when it can): a matched function with its own .rodata or data (the link
    sends those back to the per-function path), one in a per-function flag list, or one that does not link from C today."""
    flagged = listed_addresses('move_movables.txt') | listed_addresses('vu0_regs.txt') | listed_addresses('sony_gcc29.txt')
    for address in functions:
        if address not in matched:
            continue
        if address in flagged:
            return f'per-function flag list ({address:#X})'
        object_path = os.path.join(ROOT, 'build', 'units', matched[address][2] + '.o')
        if not os.path.isfile(object_path):
            return f'no per-function object ({address:#X})'
        use = object_data_use(object_path)
        if use:
            return f'own {use} ({address:#X})'
        if address not in swapped:
            return f'not linked from C today ({address:#X})'
    return None


# ---------------------------------------------------------------- splitting a source into top-level items

def skip_literal(text, index):
    """The index after the comment, string or character literal that starts at `index`, or `index` when none starts there."""
    if text.startswith('//', index):
        end = text.find('\n', index)
        return len(text) if end < 0 else end
    if text.startswith('/*', index):
        end = text.find('*/', index + 2)
        return len(text) if end < 0 else end + 2
    if text[index] in '"\'':
        quote, position = text[index], index + 1
        while position < len(text) and text[position] != quote:
            position += 2 if text[position] == '\\' else 1
        return position + 1
    return index


def code_only(text):
    """`text` with comments removed and string contents kept (for classifying an item)."""
    pieces, index = [], 0
    while index < len(text):
        after = skip_literal(text, index)
        if after != index:
            if text[index] in '"\'':
                pieces.append(text[index:after])
            else:
                pieces.append(' ')
            index = after
        else:
            pieces.append(text[index])
            index += 1
    return ''.join(pieces)


def split_items(text):
    """The top-level items of a source, in order, each as its exact text (leading comments and whitespace included): a preprocessor line, a
    function definition (ends at its closing brace), an `extern "C" { }` block, or anything else ending with a semicolon at depth 0."""
    items, start, index, depth, mode = [], 0, 0, 0, None

    def finish(end):
        # a comment on the same line after the item belongs to it
        position = end
        while position < len(text) and text[position] in ' \t':
            position += 1
        if text.startswith('/*', position) or text.startswith('//', position):
            after = skip_literal(text, position)
            if '\n' not in text[position:after] or text.startswith('//', position):
                position = after
            else:
                position = end
        else:
            position = end
        items.append(text[start:position])
        return position

    while index < len(text):
        character = text[index]
        if depth == 0 and character == '#' and not code_only(text[start:index]).strip():
            line_start = text.rfind('\n', 0, index) + 1
            if not text[line_start:index].strip():
                end = index
                while True:
                    end = text.find('\n', end)
                    if end < 0:
                        end = len(text)
                        break
                    if text[end - 1] != '\\':
                        break
                    end += 1
                index = start = finish(end)
                continue
        after = skip_literal(text, index)
        if after != index:
            index = after
            continue
        if character == '{':
            if depth == 0:
                head = code_only(text[start:index]).strip()
                if re.search(r'\)\s*(?:const\s*)?$', head) or re.search(r'\)\s*:\s*\w', head):
                    mode = 'function'
                elif re.fullmatch(r'extern\s*"C(?:\+\+)?"', head) or head.startswith('namespace'):
                    mode = 'block'
                else:
                    mode = 'statement'
            depth += 1
        elif character == '}':
            depth -= 1
            if depth == 0 and mode in ('function', 'block'):
                index = start = finish(index + 1)
                mode = None
                continue
        elif character == ';' and depth == 0:
            index = start = finish(index + 1)
            mode = None
            continue
        index += 1
    if text[start:].strip():
        items.append(text[start:])
    return items


def classify(item):
    """(kind, name) of an item: kind is preprocessor, function, type, block or declaration; name is what it defines or declares (or None)."""
    code = code_only(item).strip()
    if code.startswith('#'):
        return 'preprocessor', code
    if not code:
        return 'comment', None
    if re.match(r'extern\s*"C(?:\+\+)?"\s*\{', code) or code.startswith('namespace'):
        return 'block', None
    head = code.split('{', 1)[0]
    if re.match(r'(?:typedef\b|(?:struct|union|enum|class)\s+\w+\s*(?:[:{]|$))', code) and not re.search(r'\)\s*(?:const\s*)?$', head.strip()):
        if code.startswith('typedef'):
            body = re.sub(r'\{.*\}', ' ', code, flags=re.S)
            pointer = re.search(r'\(\s*\*\s*(\w+)\s*\)', body)
            names = re.findall(r'(\w+)\s*(?:\[[^\]]*\]\s*)*;\s*$', body)
            return 'type', (pointer.group(1) if pointer else names[0] if names else None)
        return 'type', re.match(r'(?:struct|union|enum|class)\s+(\w+)', code).group(1)
    if code.rstrip().endswith('}') and '(' in head:
        return 'function', function_name(head)
    if '(' in code.split('=', 1)[0] and not re.match(r'[^(]*\(\s*\*', code):
        return 'declaration', function_name(code)
    names = re.findall(r'(\w+)\s*(?:\[[^\]]*\]\s*)*(?:=|;|,)', code.split('=', 1)[0] + ('=' if '=' in code else ''))
    return 'declaration', (names[0] if names else None)


def function_name(head):
    """The (possibly qualified) name in front of the first parenthesis of a function head."""
    match = re.search(r'((?:\w+\s*::\s*)*~?\w+)\s*\(', head)
    return re.sub(r'\s+', '', match.group(1)) if match else None


def normalized(item):
    """An item's code with comments and whitespace runs collapsed, for comparing two sources' items."""
    return re.sub(r'\s+', ' ', code_only(item)).strip()


def rename(text, name, new_name):
    """`text` with every identifier token `name` (outside comments and strings) replaced by `new_name`."""
    pieces, index = [], 0
    pattern = re.compile(r'(?<![\w$])%s(?![\w$])' % re.escape(name))
    while index < len(text):
        after = skip_literal(text, index)
        if after != index:
            pieces.append(text[index:after])
            index = after
            continue
        next_literal = min([position for position in (text.find('//', index), text.find('/*', index), text.find('"', index), text.find("'", index)) if position >= 0] or [len(text)])
        pieces.append(pattern.sub(new_name, text[index:next_literal]))
        index = next_literal
    return ''.join(pieces)


def clean_text(text):
    """The mechanical cleanups a whole file takes from its per-function sources: M2C_UNK as the s32 it is, tabs as four spaces, no trailing
    whitespace, no SPDX line (the whole file has one)."""
    text = re.sub(r'\bM2C_UNK(?:32)?\b', 's32', text)
    lines = [line.replace('\t', '    ').rstrip() for line in text.split('\n')]
    lines = [line for line in lines if 'SPDX-License-Identifier' not in line]
    return '\n'.join(lines).strip('\n') + '\n'


# ---------------------------------------------------------------- building one whole file

def whole_file_name(start, functions, matched, module_hint):
    """src/-relative path of the whole file: the module directory of its first matched function and that function's name (unmangled) with
    `_file`, or `<module>_<start>` when the name is generic."""
    first = next((address for address in functions if address in matched), None)
    if first is None:
        module = module_hint
        return f'{module}/{module}_{start:x}'
    name, _, source = matched[first]
    module = os.path.dirname(source)
    plain = name.split('__')[0] if '__' in name[1:] else name
    if not plain or GENERIC_NAME.search(plain) or not re.fullmatch(r'\w+', plain):
        return f'{module}/{os.path.basename(module).replace("-", "_")}_{start:x}'
    return f'{module}/{plain}_file'


def is_struct_definition(item):
    """True for a struct, union, class or enum with a body, or a typedef of one: the items whose clash takes a rename, not a drop."""
    code = code_only(item).strip()
    return '{' in code and bool(re.match(r'(?:typedef\s+)?(?:struct|union|class|enum)\b', code))


def to_c(text):
    """A C++ source's linkage spelled as C: `extern "C" T f();` becomes `extern T f();`, an `extern "C" { }` block its contents."""
    text = re.sub(r'extern\s*"C"\s*\{', '/* extern "C" { */', text)
    return re.sub(r'extern\s*"C"\s*', 'extern ', text)


def declared_name(item):
    """The name a declaration item declares, with its linkage and storage words ignored."""
    return classify(item)[1]


def build_whole_file(start, end, functions, matched, read_source=None, language=None, wrap_c=True, rename_declarations=False):
    """(language, text, notes) of the whole file over [start, end): `functions` are the retail function starts in the range (build/splat),
    `matched` src/MANIFEST.tsv. `read_source(path)` returns a per-function source's text (default: from src/). The language is C when every
    matched source is C, else C++ (`language` forces one); in C++ the C sources go inside `extern "C" { }` unless `wrap_c` is false. notes
    lists the renames for the report. With `rename_declarations`, a declaration that disagrees with an earlier declaration or with a
    definition of another source is renamed in its source (address suffix) instead of being left to resolve(): every source then keeps the
    prototypes its per-function build saw, and the link finds the callee by its call site (scripts/build/link_image.py derive_addresses)."""
    read_source = read_source or (lambda path: open(os.path.join(ROOT, 'src', path)).read())
    sources = [(address, matched[address][2]) for address in functions if address in matched]
    if language is None:
        language = 'c' if sources and all(path.endswith('.c') for _, path in sources) else 'c++'
    includes, body, notes = [], [], []
    seen_text = set()
    defined = {}  # name -> normalized text of its first struct-like or function definition
    declared = {}  # name -> (normalized text, address of the source) of its first declaration or function definition
    if rename_declarations:
        for address in functions:
            if address in matched:
                for item in split_items(clean_text(read_source(matched[address][2]))):
                    kind, name = classify(item)
                    if kind == 'function' and name:
                        declared.setdefault(name, (normalized(item.split('{', 1)[0]), address))
    for address in functions:
        if address not in matched:
            body.append(f'INCLUDE_ASM({address:#X});\n')
            continue
        text = clean_text(read_source(matched[address][2]))
        if language == 'c':
            text = to_c(text)
        # a struct or helper this source defines differently from an earlier one takes the function's address as a suffix
        for _ in range(50):
            clash = None
            for item in split_items(text):
                kind, name = classify(item)
                if name and '::' not in name and name in defined and defined[name] != normalized(item) and \
                        ((kind == 'type' and is_struct_definition(item)) or kind == 'function'):
                    clash = name
                    break
            if clash is None:
                break
            new_name = f'{clash}_{address:X}'
            notes.append(f'{clash} -> {new_name}')
            text = rename(text, clash, new_name)
        if rename_declarations:
            for item in split_items(text):
                kind, name = classify(item)
                if kind != 'declaration' or not name or '::' in name:
                    continue
                key = re.sub(r'^extern\s*(?:"C"\s*)?', '', normalized(item)).rstrip(';').strip()
                first = declared.setdefault(name, (key, address))
                if first[1] != address and first[0] != key and re.sub(r'^extern\s*(?:"C"\s*)?', '', first[0]) != key:
                    notes.append(f'declaration {name} -> {name}_{address:X}')
                    text = rename(text, name, f'{name}_{address:X}')
        kept = []
        for item in split_items(text):
            kind, name = classify(item)
            key = normalized(item)
            if kind == 'preprocessor' and key.startswith('#include'):
                if key not in includes:
                    includes.append(key)
                continue
            if kind == 'comment' or (key and key in seen_text):
                continue
            seen_text.add(key)
            if name and ((kind == 'type' and is_struct_definition(item)) or kind == 'function'):
                defined.setdefault(name, key)
            kept.append(item.strip('\n') + '\n')
        chunk = '\n'.join(kept)
        if language == 'c++' and wrap_c and matched[address][2].endswith('.c') and chunk.strip():
            chunk = 'extern "C" {\n' + chunk + '}\n'
        body.append(chunk)
    lines = [HEADER, f'// Retail {start:#X}-{end:#X}: one source file, its end from the constructor list (config/us/whole_files.tsv).\n',
             '// Generated by scripts/build/make_whole_files.py from the per-function sources of src/MANIFEST.tsv; the rest come from assembly.\n']
    if any(line.startswith('INCLUDE_ASM') for line in body):
        includes = includes + ['#include "include_asm.h"']
    lines += [include + '\n' for include in includes]
    text = ''.join(lines) + '\n' + '\n'.join(body)
    return language, text, notes


CONFLICT = re.compile(r'conflicting types for|new declaration|declaration of C function .* conflicts with|redefinition of|ambiguates old declaration|'
                      r'previous declaration of .* with C\+\+ linkage|redeclaration of|conflicts with previous declaration|'
                      r'conflicting declaration|declared with C\+\+ linkage|declared .* with C linkage')
ERROR_LINE = re.compile(r'^(.*?):(\d+): (.*)$')


def item_spans(text):
    """[(first line, last line, item text)] of the top-level items of `text` (1-based line numbers, an extern "C" block's items one by one)."""
    spans, offset = [], 0
    for item in split_items(text):
        first = text.count('\n', 0, offset) + 1
        code = code_only(item)
        inner = re.match(r'(\s*extern\s*"C"\s*\{)(.*)\}\s*$', code, flags=re.S)
        if inner and code.strip().startswith('extern'):
            block_start = offset + item.index('{') + 1
            inner_text = item[item.index('{') + 1:item.rindex('}')]
            inner_offset = block_start
            for inner_item in split_items(inner_text):
                inner_first = text.count('\n', 0, inner_offset) + 1
                spans.append((inner_first, inner_first + inner_item.rstrip('\n').count('\n'), inner_offset, inner_item))
                inner_offset += len(inner_item)
        else:
            spans.append((first, first + item.rstrip('\n').count('\n'), offset, item))
        offset += len(item)
    return spans


def remove_item_at(text, line):
    """(text without the top-level declaration or type that covers `line`, removed item) or (text, None) when a function body covers it."""
    for first, last, offset, item in item_spans(text):
        if first <= line <= last:
            kind, _ = classify(item)
            if kind in ('declaration', 'type'):
                return text[:offset] + '\n' * item.count('\n') + text[offset + len(item):], item
            return text, None
    return text, None


def resolve(text, language, compile_source, limit=60):
    """(text, notes, error): the whole file after removing, one compile at a time, every later declaration or type that conflicts with an
    earlier one (the first declaration of a name wins, as one header would give it). error is the first compile error left, or None."""
    notes = []
    for _ in range(limit):
        ok, message = compile_source(text, language)
        if ok:
            return text, notes, None
        errors = [ERROR_LINE.match(line) for line in message.split('\n')]
        errors = [match for match in errors if match and 'warning:' not in match.group(3)]
        own = [match for match in errors if match.group(1).endswith(('.c', '.cpp')) and not match.group(1).startswith(os.path.join(ROOT, 'include'))]
        first = errors[0] if errors else None
        if first is None or not CONFLICT.search(first.group(3)):
            return text, notes, (first.group(3) if first else message.strip().split('\n')[-1])[:300]
        removed = None
        if first in own:
            text, removed = remove_item_at(text, int(first.group(2)))
        if removed is None:
            # the conflict is reported on a definition (or on a header line): drop the earlier declaration it names instead
            earlier = [match for match in own if match is not first and int(match.group(2)) != int(first.group(2))]
            for match in earlier[:1]:
                text, removed = remove_item_at(text, int(match.group(2)))
        if removed is None:
            return text, notes, first.group(3)[:300]
        notes.append('dropped: ' + normalized(removed)[:120])
    return text, notes, 'too many conflicts'


# ---------------------------------------------------------------- proving one whole file

def retail_words(address, size):
    import compare
    return compare.read_target_words(ELF, address, size)


def compare_object(object_path, start, end):
    """None when the object's .text is retail's [start, end) with relocated fields masked and it uses no data of its own, else the cause."""
    import compare
    from elftools.elf.elffile import ELFFile
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        text = elf.get_section_by_name('.text')
        data = text.data()
        masks = {}
        relocations = elf.get_section_by_name('.rel.text')
        symbols = elf.get_section_by_name('.symtab')
        for relocation in (relocations.iter_relocations() if relocations else []):
            symbol = symbols.get_symbol(relocation['r_info_sym'])
            if isinstance(symbol['st_shndx'], int) and elf.get_section(symbol['st_shndx']).name not in ('.text',):
                return f"relocation into its own {elf.get_section(symbol['st_shndx']).name}"
            masks[relocation['r_offset'] // 4] = compare.MASK_BY_RELOCATION_TYPE.get(relocation['r_info_type'], 0xFFFFFFFF)
    if len(data) != end - start:
        return f'size {len(data):#x}, retail {end - start:#x}'
    target = retail_words(start, end - start)
    for index in range(len(data) // 4):
        word = int.from_bytes(data[index * 4:index * 4 + 4], 'little')
        mask = masks.get(index, 0xFFFFFFFF)
        if word & mask != target[index] & mask:
            return f'bytes differ at {start + index * 4:#X}'
    return None


def compiler(name):
    """A compile_source(text, language) -> (ok, message) for resolve(), compiling in the scratch directory under `name`."""
    import compile_unit
    os.makedirs(SCRATCH, exist_ok=True)

    def compile_source(text, language):
        source = os.path.join(SCRATCH, name + ('.c' if language == 'c' else '.cpp'))
        with open(source, 'w') as handle:
            handle.write(text)
        return compile_unit.compile_object(language, source, os.path.join(SCRATCH, name + '.o'))
    return compile_source


def tidy(text):
    """No run of more than one blank line (removed items leave their lines empty while the resolver works)."""
    return re.sub(r'\n{3,}', '\n\n', text).rstrip('\n') + '\n'


def make_and_prove(start, end, relative, functions, matched):
    """(file with extension, text, notes, cause or None): the whole file, resolved and compared with retail. A mixed file that does not
    compile as C++ is tried as C."""
    name = relative.replace('/', '__')
    compile_source = compiler(name)
    first_language, _, _ = build_whole_file(start, end, functions, matched)
    # the ways tried, in order: C++ with the C sources under extern "C" (their per-function linkage), C++ without it, then C
    attempts = [(first_language, True, False)] + ([('c++', False, False), ('c', True, False)] if first_language == 'c++' else []) + \
        [(first_language, True, True)] + ([('c++', False, True)] if first_language == 'c++' else [])
    cause = None
    for language, wrap_c, rename_declarations in attempts:
        _, text, notes = build_whole_file(start, end, functions, matched, language=language, wrap_c=wrap_c, rename_declarations=rename_declarations)
        text, dropped, error = resolve(text, language, compile_source)
        text = tidy(text)
        file = relative + ('.c' if language == 'c' else '.cpp')
        # the cause reported is the furthest any way got: differing bytes before a compile error, the most permissive way's compile error
        if error:
            cause = cause if cause and not cause.startswith('compile') else f'compile ({language}): {error}'
            continue
        ok, message = compile_source(text, language)
        if not ok:
            cause = cause if cause and not cause.startswith('compile') else f'compile ({language}): {message.strip()[:200]}'
            continue
        difference = compare_object(os.path.join(SCRATCH, name + '.o'), start, end)
        if difference:
            cause = difference
            continue
        way = f'{language}{"" if language == "c" or wrap_c else ", C sources without extern C"}{", declarations renamed" if rename_declarations else ""}'
        return file, text, [way] + notes + dropped, None
    return relative + ('.c' if first_language == 'c' else '.cpp'), text, notes, cause


# ---------------------------------------------------------------- the command line

def candidates(boundaries_path):
    """[(start, end, relative path or None, exclusion or None, functions)] of the evidenced rows."""
    from asm_units import read_units, whole_files
    functions = sorted(function['address'] for function in read_units(os.path.join(ROOT, 'build', 'splat'))[1])
    matched = manifest()
    swapped = {int(line.split('\t')[0], 16) for line in open(os.path.join(ROOT, 'config', 'us', 'swapped.tsv')) if line.strip()}
    existing = {start: file for start, _, file in whole_files()}
    per_function = {source.lower() for _, _, source in matched.values()}  # a whole file never takes a per-function source's name
    result, used = [], set()
    for start, end, row in evidenced_rows(boundaries_path):
        inside = [address for address in functions if start <= address < end]
        if start in existing:
            result.append((start, end, existing[start], 'already a whole file', inside))
            continue
        reason = exclusion(inside, matched, swapped)
        hint = row['modules'].split(',')[0].replace('+', '-')
        relative = whole_file_name(start, inside, matched, hint)
        while relative.lower() in used or any(relative.lower() + extension in per_function for extension in ('.c', '.cpp')):
            relative = f'{relative}_{start:x}'
        used.add(relative.lower())
        result.append((start, end, relative, reason, inside))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--boundaries', required=True, help='work/boundaries/file_boundaries.tsv')
    parser.add_argument('--list', action='store_true', help='print the candidates and why the others are left out')
    parser.add_argument('--write', action='store_true', help='write the proved files to src/ and print their whole_files.tsv rows')
    parser.add_argument('--limit', type=int, help='only the first N candidates')
    parser.add_argument('--only', help='only the candidate starting at this address')
    parser.add_argument('--jobs', type=int, default=os.cpu_count())
    parser.add_argument('--report', help='write the stage report (start, end, file, status, cause) here')
    parser.add_argument('--dump', help='write every generated text to this directory, proved or not')
    arguments = parser.parse_args()
    rows = candidates(arguments.boundaries)
    if arguments.list:
        for start, end, relative, reason, inside in rows:
            print(f'{start:#X}\t{end:#X}\t{relative}\t{reason or "candidate"}\t{len(inside)}')
        return
    matched = manifest()
    chosen = [row for row in rows if row[3] is None]
    if arguments.only:
        chosen = [row for row in chosen if row[0] == int(arguments.only, 16)]
    if arguments.limit:
        chosen = chosen[:arguments.limit]
    generated = {}  # start -> (file, text, notes, cause, end)
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        futures = {pool.submit(make_and_prove, start, end, relative, inside, matched): (start, end) for start, end, relative, _, inside in chosen}
        for future in concurrent.futures.as_completed(futures):
            start, end = futures[future]
            file, text, notes, cause = future.result()
            left = sorted({match.group(0) for match in CLEANUP_LEFT.finditer(text)})
            if cause is None and left:
                cause = 'cleanup left in a per-function source: ' + ', '.join(left[:3])
            generated[start] = (file, text, notes, cause, end)
    if arguments.dump:
        os.makedirs(arguments.dump, exist_ok=True)
        for file, text, _, _, _ in generated.values():
            open(os.path.join(arguments.dump, file.replace('/', '__')), 'w').write(text)
    for start in sorted(generated):
        file, _, notes, cause, end = generated[start]
        print(f'{start:#X}\t{end:#X}\t{file}\t{"converted" if cause is None else "failed"}\t{cause or ""}\t{"; ".join(notes)}')
    if arguments.report:
        with open(arguments.report, 'w') as handle:
            handle.write('start\tend\tfile\tstatus\tcause\n')
            for start, end, relative, reason, _ in rows:
                if start in generated:
                    file, _, _, cause, _ = generated[start]
                    handle.write(f'{start:#X}\t{end:#X}\t{file}\t{"converted" if cause is None else "failed"}\t{cause or ""}\n')
                else:
                    handle.write(f'{start:#X}\t{end:#X}\t{relative}\t{"existing" if reason == "already a whole file" else "out of scope"}\t{reason}\n')
    if arguments.write:
        for start in sorted(generated):
            file, text, _, cause, end = generated[start]
            if cause is not None:
                continue
            path = os.path.join(ROOT, 'src', file)
            os.makedirs(os.path.dirname(path), exist_ok=True)
            with open(path, 'w') as handle:
                handle.write(text)
            sys.stderr.write(f'{start:#X}\t{end:#X}\t{file}\n')


if __name__ == '__main__':
    main()
