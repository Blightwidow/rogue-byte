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
whole). --write writes the proved files to src/ and prints their config/us/whole_files.tsv rows (it never edits that list).

A whole file is the only record of the functions in its range (scripts/matching/export_src.py publishes no per-function copy of them).

  .venv/bin/python scripts/build/make_whole_files.py --land 0xADDRESS [--source PATH] [--dry-run --output PATH]

--land puts a function that scores 0 on its own (its per-function source, by default the registry's) into its whole file in place of its
INCLUDE_ASM line, merged as above, and writes the file only when the whole range proves again; scripts/matching/record.py does it for every
new match inside a whole file. cut_function() gives one function of a whole object (objdiff), function_symbols() their offsets (PAL)."""
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
MANGLED = re.compile(r'^(?:__[a-z]{2,3}__\w+|__\d+[A-Za-z_]\w*|\w+?__(?:F|C?\d+[A-Za-z_])\w*)$')  # a g++ 2.95 mangled function name
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
    """Why a file cannot take the whole-file path as it is (None when it can): a matched function with its own data other than .rodata
    (the link sends it back to the per-function path), one in a per-function flag list, or one that does not link from C today."""
    flagged = listed_addresses('move_movables.txt') | listed_addresses('vu0_regs.txt') | listed_addresses('sony_gcc29.txt') | listed_addresses('sony_gcc29_01.txt')
    for address in functions:
        if address not in matched:
            continue
        if address in flagged:
            return f'per-function flag list ({address:#X})'
        object_path = os.path.join(ROOT, 'build', 'units', matched[address][2] + '.o')
        if not os.path.isfile(object_path):
            return f'no per-function object ({address:#X})'
        use = object_data_use(object_path)
        if use == 'data':  # own .rodata links (link_image.py), proves (compare_object) and cuts (cut_function); other data does not yet
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


def leading_comments_length(item):
    """Length of the whitespace and comments in front of an item's first code character."""
    index = 0
    while index < len(item):
        if item[index].isspace():
            index += 1
        elif item.startswith('//', index):
            newline = item.find('\n', index)
            index = len(item) if newline < 0 else newline + 1
        elif item.startswith('/*', index):
            close = item.find('*/', index + 2)
            index = len(item) if close < 0 else close + 2
        else:
            break
    return index


def flatten_extern_c(text):
    """`text` with each top-level `extern "C" { }` block opened into items of its own, so that the merge compares (and renames) the
    declarations inside it one by one: a function declaration or definition and an `extern` variable declaration take the `extern "C"`
    prefix (the same linkage), written after the item's leading comments; a variable definition keeps a block of its own (with the prefix
    alone it would become a declaration); a `static` item, a type, a comment or a preprocessor line goes out as it is (linkage does not
    apply to it, and `extern "C" static` is not valid)."""
    pieces = []
    for item in split_items(text):
        code = code_only(item).strip()
        if not re.match(r'extern\s*"C"\s*\{', code):
            pieces.append(item)
            continue
        inner = item[item.index('{', item.index('extern')) + 1:item.rindex('}')]
        for part in split_items(inner):
            kind, _ = classify(part)
            part_code = code_only(part).strip()
            if kind in ('function', 'declaration') and part_code and not re.match(r'static\b', part_code):
                is_function = kind == 'function' or '(' in part_code.split('=', 1)[0]
                if part_code.startswith('extern') or is_function:
                    lead_length = leading_comments_length(part)
                    lead, body = part[:lead_length], part[lead_length:]
                    body = body if body.startswith('extern "C"') else 'extern "C" ' + re.sub(r'^extern\s+(?!")', '', body)
                    pieces.append(lead + body)
                else:
                    pieces.append('\nextern "C" {\n' + part.strip('\n') + '\n}\n')
            else:
                pieces.append(part)
    return ''.join(piece if piece.endswith('\n') else piece + '\n' for piece in pieces)


def clean_text(text):
    """The mechanical cleanups a whole file takes from its per-function sources: M2C_UNK as the s32 it is, tabs as four spaces, no trailing
    whitespace, no SPDX line (the whole file has one), and every `extern "C" { }` block opened into its items (flatten_extern_c)."""
    text = re.sub(r'\bM2C_UNK(?:32)?\b', 's32', text)
    lines = [line.replace('\t', '    ').rstrip() for line in text.split('\n')]
    lines = [line for line in lines if 'SPDX-License-Identifier' not in line]
    return flatten_extern_c('\n'.join(lines).strip('\n') + '\n')


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


class Merge:
    """What a whole file holds while per-function sources are merged into it: its includes, the items already written (a later identical
    item is dropped), the struct-like and function definitions by name (a later different one is renamed) and, with `rename_declarations`,
    the first declaration of each name."""

    def __init__(self, language, wrap_c=True, rename_declarations=False):
        self.language, self.wrap_c, self.rename_declarations = language, wrap_c, rename_declarations
        self.includes, self.notes = [], []
        self.seen_text = set()
        self.defined = {}  # name -> normalized text of its first struct-like or function definition
        self.declared = {}  # name -> (normalized text, address of the source) of its first declaration or function definition

    def declare_definitions(self, text, address, source_is_c=False):
        """Records the function definitions of `text` as the first declarations of their names (rename_declarations), with their linkage:
        a C++ declaration of a function another source defines with C linkage (or the reverse) names another function."""
        source_linkage = 'C' if self.language == 'c' or (source_is_c and self.wrap_c) else 'C++'
        for item in split_items(text):
            kind, name = classify(item)
            if kind == 'function' and name:
                head = normalized(item.split('{', 1)[0])
                linkage = 'C' if re.match(r'extern\s*"C"', head) else source_linkage
                self.declared.setdefault(name, (linkage + ' ' + re.sub(r'^extern\s*(?:"C"\s*)?', '', head), address))

    def absorb(self, address, text, source_is_c):
        """The chunk a per-function source adds at its function's place: its includes are collected, an item written before is dropped, a
        struct or helper defined differently before takes the function's address as a suffix, a C source in C++ goes inside extern "C"."""
        text = clean_text(text)
        if self.language == 'c':
            text = to_c(text)
        for _ in range(50):
            clash = None
            for item in split_items(text):
                kind, name = classify(item)
                if name and '::' not in name and name in self.defined and self.defined[name] != normalized(item) and \
                        ((kind == 'type' and is_struct_definition(item)) or kind == 'function'):
                    clash = name
                    break
            if clash is None:
                break
            new_name = f'{clash}_{address:X}'
            self.notes.append(f'{clash} -> {new_name}')
            text = rename(text, clash, new_name)
        if self.rename_declarations:
            source_linkage = 'C' if self.language == 'c' or (source_is_c and self.wrap_c) else 'C++'
            for item in split_items(text):
                kind, name = classify(item)
                if kind != 'declaration' or not name or '::' in name:
                    continue
                code = normalized(item)
                linkage = 'C' if re.match(r'extern\s*"C"', code) else source_linkage
                key = linkage + ' ' + re.sub(r'^extern\s*(?:"C"\s*)?', '', code).rstrip(';').strip()
                if linkage == 'C' and self.language == 'c++' and MANGLED.match(name):
                    # a C declaration spelled with a C++ mangled name is the same symbol as the C++ declaration it mangles (g++ 2.95 also
                    # reads a name opening with `__` as an operator): it takes a name of its own, the link finds the callee by call site
                    new_name = f'c{address:X}{name}' if name.startswith('__') else f'{name}_{address:X}'
                    self.notes.append(f'declaration {name} -> {new_name}')
                    text = rename(text, name, new_name)
                    continue
                first = self.declared.setdefault(name, (key, address))
                if first[1] != address and first[0] != key:
                    self.notes.append(f'declaration {name} -> {name}_{address:X}')
                    text = rename(text, name, f'{name}_{address:X}')
        kept = []
        for item in split_items(text):
            kind, name = classify(item)
            key = normalized(item)
            if kind == 'preprocessor' and key.startswith('#include'):
                if key not in self.includes:
                    self.includes.append(key)
                continue
            if kind == 'comment' or (key and key in self.seen_text):
                continue
            self.seen_text.add(key)
            if name and ((kind == 'type' and is_struct_definition(item)) or kind == 'function'):
                self.defined.setdefault(name, key)
            kept.append(item.strip('\n') + '\n')
        chunk = '\n'.join(kept)
        if self.language == 'c++' and self.wrap_c and source_is_c and chunk.strip():
            chunk = 'extern "C" {\n' + chunk + '}\n'
        return chunk


HEADER_DEFINED = '<defined by a shared header>'


def header_types(names, directory=None):
    """The struct, class and union names that the shared headers `names` (and the headers of include/ they include in turn) define with a
    body: a per-function source that defines one of them locally takes the address suffix in a whole file holding that header, since one
    unit cannot hold both definitions."""
    directory = directory or os.path.join(ROOT, 'include')
    found, pending, seen = set(), list(names), set()
    while pending:
        name = pending.pop()
        path = os.path.join(directory, name)
        if name in seen or not os.path.isfile(path):
            continue
        seen.add(name)
        text = code_only(open(path).read())
        pending += re.findall(r'^\s*#\s*include\s*"([^"]+)"', text, flags=re.M)
        found.update(re.findall(r'\b(?:struct|class|union)\s+(\w+)\s*(?::[^{;]*)?\{', text))
    return found


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
    merge = Merge(language, wrap_c, rename_declarations)
    includes_used = set()
    for address, path in sources:
        includes_used.update(re.findall(r'^\s*#\s*include\s*"([^"]+)"', read_source(path), flags=re.M))
    for name in header_types(includes_used):
        merge.defined.setdefault(name, HEADER_DEFINED)
    body = []
    if rename_declarations:
        for address in functions:
            if address in matched:
                merge.declare_definitions(clean_text(read_source(matched[address][2])), address, matched[address][2].endswith('.c'))
    for address in functions:
        if address not in matched:
            body.append(f'INCLUDE_ASM({address:#X});\n')
            continue
        body.append(merge.absorb(address, read_source(matched[address][2]), matched[address][2].endswith('.c')))
    lines = [HEADER, f'// Retail {start:#X}-{end:#X}: one source file, its end from the constructor list (config/us/whole_files.tsv).\n',
             '// Generated by scripts/build/make_whole_files.py from the per-function sources of src/MANIFEST.tsv; the rest come from assembly.\n']
    includes = merge.includes
    if any(line.startswith('INCLUDE_ASM') for line in body):
        includes = includes + ['#include "include_asm.h"']
    lines += [include + '\n' for include in includes]
    text = ''.join(lines) + '\n' + '\n'.join(body)
    return language, text, merge.notes


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


def rodata_cause(elf, text_data, start):
    """None when the object's own .rodata (what its code reads, trimmed as scripts/build/link_image.py trims it) is retail's bytes at the one
    base its hi/lo pairs give, relocated words (jump table entries) masked; else the cause. The base is where the file's own .rodata sits."""
    import compare
    rodata, relocations = elf.get_section_by_name('.rodata'), elf.get_section_by_name('.rel.text')
    symbols, index = elf.get_section_by_name('.symtab'), elf.get_section_index('.rodata')
    entries = [(r['r_offset'], r['r_info_type'], symbols.get_symbol(r['r_info_sym'])) for r in relocations.iter_relocations()]
    signed = lambda value: value - 0x10000 if value & 0x8000 else value
    word = lambda blob, offset: int.from_bytes(blob[offset:offset + 4], 'little')
    retail = retail_words(start, len(text_data))
    bases = set()
    for position, (offset, kind, symbol) in enumerate(entries):
        if kind != 5 or symbol['st_shndx'] != index:
            continue
        low = next((o for o, k, s in entries[position + 1:] if k == 6 and s['st_shndx'] == index), None)
        if low is None:
            return 'rodata: a hi16 without a lo16'
        retail_value = ((retail[offset // 4] & 0xFFFF) << 16) + signed(retail[low // 4] & 0xFFFF)
        object_value = ((word(text_data, offset) & 0xFFFF) << 16) + signed(word(text_data, low) & 0xFFFF)
        bases.add(retail_value - object_value)
    if len(bases) != 1:
        return f'rodata: {len(bases)} bases'
    base = next(iter(bases))
    data = rodata.data()
    masked = {r['r_offset'] // 4 for r in (elf.get_section_by_name('.rel.rodata').iter_relocations() if elf.get_section_by_name('.rel.rodata') else [])}
    end = len(data.rstrip(b'\0'))
    end = max([end] + [4 * word_index + 4 for word_index in masked])
    end = (end + 3) & ~3
    target = retail_words(base, end)
    for word_index in range(end // 4):
        if word_index in masked:
            continue
        if word(data, word_index * 4) != target[word_index]:
            return f'rodata differs at {base + word_index * 4:#X}'
    return None


def compare_object(object_path, start, end):
    """None when the object's .text is retail's [start, end) with relocated fields masked and its own .rodata (if it reads any) is retail's
    bytes where its code points, else the cause. Data other than .rodata is not handled yet."""
    import compare
    from elftools.elf.elffile import ELFFile
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        text = elf.get_section_by_name('.text')
        data = text.data()
        masks = {}
        relocations = elf.get_section_by_name('.rel.text')
        symbols = elf.get_section_by_name('.symtab')
        uses_rodata = False
        for relocation in (relocations.iter_relocations() if relocations else []):
            symbol = symbols.get_symbol(relocation['r_info_sym'])
            if isinstance(symbol['st_shndx'], int):
                section = elf.get_section(symbol['st_shndx']).name
                if section == '.rodata':
                    uses_rodata = True
                elif section != '.text':
                    return f'relocation into its own {section}'
            masks[relocation['r_offset'] // 4] = compare.MASK_BY_RELOCATION_TYPE.get(relocation['r_info_type'], 0xFFFFFFFF)
        if len(data) != end - start:
            return f'size {len(data):#x}, retail {end - start:#x}'
        target = retail_words(start, end - start)
        for index in range(len(data) // 4):
            word = int.from_bytes(data[index * 4:index * 4 + 4], 'little')
            mask = masks.get(index, 0xFFFFFFFF)
            if word & mask != target[index] & mask:
                return f'bytes differ at {start + index * 4:#X}'
        return rodata_cause(elf, data, start) if uses_rodata else None


def compiler(name, vu0=False):
    """A compile_source(text, language) -> (ok, message) for resolve(), compiling in the scratch directory under `name`; `vu0` adds the
    VU0 register flag, the flag set of a whole file whose start is listed in config/us/vu0_regs.txt (configure.py builds it so)."""
    import compile_unit
    os.makedirs(SCRATCH, exist_ok=True)

    def compile_source(text, language):
        source = os.path.join(SCRATCH, name + ('.c' if language == 'c' else '.cpp'))
        with open(source, 'w') as handle:
            handle.write(text)
        return compile_unit.compile_object(language, source, os.path.join(SCRATCH, name + '.o'), vu0=vu0)
    return compile_source


def tidy(text):
    """No run of more than one blank line (removed items leave their lines empty while the resolver works)."""
    return re.sub(r'\n{3,}', '\n\n', text).rstrip('\n') + '\n'


def make_and_prove(start, end, relative, functions, matched):
    """(file with extension, text, notes, cause or None): the whole file, resolved and compared with retail. A mixed file that does not
    compile as C++ is tried as C."""
    import compile_unit
    name = relative.replace('/', '__')
    compile_source = compiler(name, compile_unit.vu0_for(start))
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


# ---------------------------------------------------------------- one function of a whole object

COMPILER_MARKERS = ('gcc2_compiled.', '__gnu_compiled_c', '__gnu_compiled_cplusplus')


def function_symbols(object_path):
    """{offset in .text: symbol name} of the functions a whole object defines (its C functions and its INCLUDE_ASM labels: the named .text
    symbols other than the compiler's markers). A function's retail address is the whole file's start plus its offset."""
    from elftools.elf.elffile import ELFFile
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        text_index = elf.get_section_index('.text')
        found = {}
        for symbol in elf.get_section_by_name('.symtab').iter_symbols():
            if symbol['st_shndx'] == text_index and symbol.name and symbol['st_info']['type'] in ('STT_FUNC', 'STT_NOTYPE') and \
                    not symbol.name.startswith(COMPILER_MARKERS + ('.',)):
                found.setdefault(symbol['st_value'], symbol.name)
        return found


def write_object(output, code, symbols, local_count, relocations, flags=0, alignment=8, rodata=None):
    """Writes a little-endian MIPS relocatable object with one .text (`code`), its .rel.text and a symbol table. `symbols` are (name, value,
    size, info) after the null symbol, all defined in .text except the ones whose info has a binding (info >> 4) and no type, which are
    undefined; a fifth element, when present, is the symbol's section index (6 for .rodata). The first `local_count` entries (the null one
    included) are local. `relocations` are (offset, symbol index, type). `rodata`, when given, is (bytes, alignment, relocations): a .rodata
    section (index 6) and its .rel.rodata (index 7) after the five sections of an object without one."""
    import struct
    names = bytearray(b'\0')
    entries = [struct.pack('<IIIBBH', 0, 0, 0, 0, 0, 0)]
    for symbol in symbols:
        name, value, size, info = symbol[:4]
        position = len(names)
        names.extend(name.encode() + b'\0')
        undefined = info >> 4 and not info & 0xF
        section = symbol[4] if len(symbol) > 4 else 1
        entries.append(struct.pack('<IIIBBH', position if name else 0, value, size, info, 0, 0 if undefined else section))
    pack_relocations = lambda items: b''.join(struct.pack('<II', place, index << 8 | kind) for place, index, kind in items)
    relocation_bytes = pack_relocations(relocations)
    section_names = b'\0.text\0.rel.text\0.symtab\0.strtab\0.shstrtab\0' + (b'.rodata\0.rel.rodata\0' if rodata else b'')
    blobs = [bytes(code), relocation_bytes, b''.join(entries), bytes(names), section_names]
    if rodata:
        blobs += [bytes(rodata[0]), pack_relocations(rodata[2])]
    positions, cursor = [], 52
    for blob in blobs:
        cursor = (cursor + 15) & ~15
        positions.append(cursor)
        cursor += len(blob)
    section_count = 8 if rodata else 6
    section_table = (cursor + 3) & ~3
    out = bytearray(section_table + 40 * section_count)
    out[:52] = struct.pack('<4sBBBB8sHHIIIIIHHHHHH', b'\x7fELF', 1, 1, 1, 0, bytes(8), 1, 8, 1, 0, 0, section_table, flags, 52, 0, 0, 40, section_count, 5)
    for blob, position in zip(blobs, positions):
        out[position:position + len(blob)] = blob
    headers = [bytes(40),
               struct.pack('<10I', 1, 1, 6, 0, positions[0], len(code), 0, 0, alignment, 0),
               struct.pack('<10I', 7, 9, 0, 0, positions[1], len(relocation_bytes), 3, 1, 4, 8),
               struct.pack('<10I', 17, 2, 0, 0, positions[2], len(blobs[2]), 4, local_count, 4, 16),
               struct.pack('<10I', 25, 3, 0, 0, positions[3], len(names), 0, 0, 1, 0),
               struct.pack('<10I', 33, 3, 0, 0, positions[4], len(section_names), 0, 0, 1, 0)]
    if rodata:
        headers += [struct.pack('<10I', 43, 1, 2, 0, positions[5], len(blobs[5]), 0, 0, rodata[1], 0),
                    struct.pack('<10I', 51, 9, 0, 0, positions[6], len(blobs[6]), 3, 6, 4, 8)]
    out[section_table:] = b''.join(headers)
    os.makedirs(os.path.dirname(output) or '.', exist_ok=True)
    with open(output, 'wb') as handle:
        handle.write(out)


def cut_function(object_path, offset, output):
    """(output, outside): a relocatable object holding only the function of the whole object that starts at `offset` (up to the next
    function, function_symbols()), with its relocations. Every other function it refers to becomes an undefined global name, so a call to
    it reads as a call by name; `outside` maps those names to their offsets in the whole object (retail address = start + offset). When the
    function reads the object's own .rodata, the cut carries that whole section, as a per-function object carries its own: the code's
    offsets into it stay as they are, and a jump table entry that points into the function points into the cut (one pointing elsewhere is
    left as a plain word). Raises ValueError when no function starts at `offset` or a relocation points into the object other than at a
    named .text symbol or its .rodata."""
    import struct
    from elftools.elf.elffile import ELFFile
    functions = function_symbols(object_path)
    if offset not in functions:
        raise ValueError(f'no function at offset {offset:#x}')
    with open(object_path, 'rb') as handle:
        elf = ELFFile(handle)
        text = elf.get_section_by_name('.text')
        text_index = elf.get_section_index('.text')
        rodata_section = elf.get_section_by_name('.rodata')
        rodata_index = elf.get_section_index('.rodata') if rodata_section is not None else None
        end = next((value for value in sorted(functions) if value > offset), text['sh_size'])
        code = text.data()[offset:end]
        symbol_table = elf.get_section_by_name('.symtab')
        symbols = list(symbol_table.iter_symbols())
        relocation_section = elf.get_section_by_name('.rel.text')
        relocations = [(relocation['r_offset'], relocation['r_info_type'], relocation['r_info_sym'])
                       for relocation in (relocation_section.iter_relocations() if relocation_section else [])
                       if offset <= relocation['r_offset'] < end]
        rodata_relocation_section = elf.get_section_by_name('.rel.rodata')
        rodata_relocations = [(relocation['r_offset'], relocation['r_info_type'], relocation['r_info_sym'])
                              for relocation in (rodata_relocation_section.iter_relocations() if rodata_relocation_section else [])]
        rodata_bytes = bytearray(rodata_section.data()) if rodata_section is not None else None
        rodata_alignment = rodata_section['sh_addralign'] if rodata_section is not None else 0
        flags, alignment = elf['e_flags'], text['sh_addralign']
    uses_rodata = rodata_index is not None and any(symbols[number]['st_shndx'] == rodata_index for _, _, number in relocations)
    table, index_of, outside = [('', 0, 0, 3)], {}, {}  # after the null symbol: the .text section's
    if uses_rodata:
        table.append(('', 0, 0, 3, 6))  # the .rodata section's
    for number, symbol in enumerate(symbols):
        if symbol['st_shndx'] == text_index and symbol.name and offset <= symbol['st_value'] < end:
            index_of[number] = len(table) + 1
            kind = {'STT_FUNC': 2, 'STT_OBJECT': 1}.get(symbol['st_info']['type'], 0)
            table.append((symbol.name, symbol['st_value'] - offset, symbol['st_size'], kind))
        elif uses_rodata and symbol['st_shndx'] == rodata_index:
            if symbol['st_info']['type'] == 'STT_SECTION':
                index_of[number] = 2
            else:
                index_of[number] = len(table) + 1
                table.append((symbol.name, symbol['st_value'], symbol['st_size'], {'STT_OBJECT': 1}.get(symbol['st_info']['type'], 0), 6))
    local_count = len(table) + 1
    for place, kind, number in relocations:
        if number in index_of:
            continue
        symbol = symbols[number]
        if symbol['st_shndx'] == text_index and symbol.name and symbol['st_info']['type'] != 'STT_SECTION':
            outside[symbol.name] = symbol['st_value']
        elif (symbol['st_shndx'] != 'SHN_UNDEF' or not symbol.name) and not re.match(r'^[A-Z]{1,3}_[0-9A-Fa-f]{8}$', symbol.name):
            # an object the file defines under its retail address name (link_image.py link_whole_data) is cut as a name too
            raise ValueError(f'relocation at {place:#x} against {symbol.name or "a section"}: not a name')
        index_of[number] = len(table) + 1
        table.append((symbol.name, 0, 0, 0x10))  # an undefined global name
    rodata = None
    if uses_rodata:
        kept = []
        for place, kind, number in rodata_relocations:
            symbol = symbols[number]
            if kind != 2 or symbol['st_shndx'] != text_index:  # R_MIPS_32 into .text: a jump table entry
                continue
            word, = struct.unpack_from('<I', rodata_bytes, place)
            target = word + (0 if symbol['st_info']['type'] == 'STT_SECTION' else symbol['st_value'])
            if offset <= target < end:
                struct.pack_into('<I', rodata_bytes, place, target - offset)
                kept.append((place, 1, kind))
        rodata = (rodata_bytes, rodata_alignment, kept)
    write_object(output, code, table, local_count, [(place - offset, index_of[number], kind) for place, kind, number in relocations], flags,
                 alignment, rodata)
    return output, outside


# ---------------------------------------------------------------- landing one function in a whole file

def include_asm_marker(address):
    """The pattern of the INCLUDE_ASM line of `address` in a whole file (any spelling of the hexadecimal, a comment after it)."""
    return re.compile(r'^[ \t]*INCLUDE_ASM\(\s*0x0*%X\s*\)\s*;[^\n]*\n?' % address, re.M | re.I)


def whole_file_of(address, wholes=None):
    """(start, end, file) of the whole file (config/us/whole_files.tsv) whose range holds `address`, or None."""
    if wholes is None:
        from asm_units import whole_files
        wholes = whole_files()
    return next(((start, end, file) for start, end, file in wholes if start <= address < end), None)


def insert_function(whole_text, address, source_text, source_is_c, language, wrap_c=True, rename_declarations=False):
    """(text, notes): the whole file with the INCLUDE_ASM line of `address` replaced by the per-function source, merged the way
    build_whole_file merges one (Merge): an item the file writes before that line is dropped from the source, a struct-like or function
    definition the file has anywhere and the source defines differently takes the address suffix in the source, a new include goes after
    the file's includes, and `#include "include_asm.h"` goes when no INCLUDE_ASM is left. Raises ValueError without that line."""
    marker = include_asm_marker(address).search(whole_text)
    if marker is None:
        raise ValueError(f'no INCLUDE_ASM({address:#X}) line in the whole file')
    merge = Merge(language, wrap_c, rename_declarations)
    for _, _, offset, item in item_spans(whole_text):
        kind, name = classify(item)
        key = normalized(item)
        if kind == 'preprocessor':
            if key.startswith('#include') and key not in merge.includes:
                merge.includes.append(key)
            continue
        if kind == 'comment':
            continue
        if offset < marker.start():
            merge.seen_text.add(key)
        if name and ((kind == 'type' and is_struct_definition(item)) or kind == 'function'):
            merge.defined.setdefault(name, key)
        if name and kind == 'function' and rename_declarations:
            merge.declared.setdefault(name, (normalized(item.split('{', 1)[0]), None))
    known = list(merge.includes)
    chunk = merge.absorb(address, source_text, source_is_c)
    text = whole_text[:marker.start()] + chunk + whole_text[marker.end():]
    added = [include for include in merge.includes if include not in known]
    if added:
        last = None
        for last in re.finditer(r'^#include[^\n]*\n', text, re.M):
            pass
        at = last.end() if last else re.match(r'(?:(?://[^\n]*|/\*.*?\*/)?\n)*', text, re.S).end()
        text = text[:at] + ''.join(include + '\n' for include in added) + text[at:]
    if not re.search(r'^[ \t]*INCLUDE_ASM\(', text, re.M):
        text = re.sub(r'^#include "include_asm\.h"[^\n]*\n', '', text, flags=re.M)
    return text, merge.notes


def registry_source(address):
    """The source data/matching/functions.tsv records for `address` (the per-function source a worker matched), or None."""
    for row in read_table(os.path.join(ROOT, 'data', 'matching', 'functions.tsv')):
        if int(row['address'], 16) == address:
            return os.path.join(ROOT, row['source']) if row.get('source') else None
    return None


def already_landed(address, name, wholes=None, text=None):
    """True when `address`'s whole file has no INCLUDE_ASM line for it left and defines a function called `name`: it was landed there
    already (by hand, or by an earlier make_whole_files.py --land), so the whole file is its record and `make elf` its proof."""
    found = whole_file_of(address, wholes)
    if found is None:
        return False
    if text is None:
        path = os.path.join(ROOT, 'src', found[2])
        if not os.path.isfile(path):
            return False
        text = open(path).read()
    if include_asm_marker(address).search(text):
        return False
    return re.search(r'\b%s\s*\([^;{}]*\)\s*(?:const\s*)?\{' % re.escape(name), code_only(text)) is not None


def promote_to_cpp(file, wholes_path=None):
    """Renames the C whole file src/<file> to .cpp and its config/us/whole_files.tsv row with it: a whole file is built as one language, so a
    C file takes a C++ function by becoming C++ (land() does this only once the C++ text proves). Returns the new relative path."""
    new_file = file[:-2] + '.cpp'
    os.replace(os.path.join(ROOT, 'src', file), os.path.join(ROOT, 'src', new_file))
    wholes_path = wholes_path or os.path.join(ROOT, 'config', 'us', 'whole_files.tsv')
    text = open(wholes_path).read()
    text = re.sub(r'(\t)%s$' % re.escape(file), lambda match: match.group(1) + new_file, text, count=1, flags=re.M)
    with open(wholes_path, 'w') as handle:
        handle.write(text)
    return new_file


def land(address, source_path, wholes=None, compile_source=None, prove=None, write=True):
    """(ok, message, text) of landing a function that scores 0 on its own in its whole file: its INCLUDE_ASM line becomes its source
    (insert_function), the conflicts the merge leaves are resolved by compiling (resolve), and the whole range is compiled and compared with
    retail (compare_object) before anything is written. A failure leaves the file as it was and says why. With `write` false nothing is
    written (a dry run: text is what would be written). `compile_source(text, language)` and `prove()` stand in for the compiler and the
    comparison in tests."""
    found = whole_file_of(address, wholes)
    if found is None:
        return False, f'{address:#X} is in no whole file', None
    start, end, file = found
    flagged = listed_addresses('move_movables.txt') | listed_addresses('sony_gcc29.txt') | listed_addresses('sony_gcc29_01.txt')
    if address in flagged:
        return False, f'{address:#X} is in a per-function flag list; src/{file} has one flag set: not changed', None
    # the VU0 flag (a function using the VU0 helpers of include/vu0inline.h) becomes the whole file's flag when the whole file proves with
    # it: its start is then listed in config/us/vu0_regs.txt, the one flag set of that file
    vu0_list = listed_addresses('vu0_regs.txt')
    vu0 = address in vu0_list or start in vu0_list
    path = os.path.join(ROOT, 'src', file)
    whole_text = open(path).read()
    if not include_asm_marker(address).search(whole_text):
        return False, f'src/{file} has no INCLUDE_ASM({address:#X}) line: not changed', None
    if not source_path or not os.path.isfile(source_path):
        return False, f'no source for {address:#X} ({source_path}): src/{file} not changed', None
    language = 'c' if file.endswith('.c') else 'c++'
    source_text, source_is_c = open(source_path).read(), source_path.endswith('.c')
    promote = language == 'c' and not source_is_c  # a C++ function in a C file: the file can only take it as C++
    if promote:
        language = 'c++'
    name = f'land_{address:X}'
    compile_source = compile_source or compiler(name, vu0)
    prove = prove or (lambda: compare_object(os.path.join(SCRATCH, name + '.o'), start, end))
    attempts = [(True, False)] + ([(False, False)] if language == 'c++' and source_is_c else []) + [(True, True)]
    cause = None
    for wrap_c, rename_declarations in attempts:
        text, notes = insert_function(whole_text, address, source_text, source_is_c, language, wrap_c, rename_declarations)
        text, dropped, error = resolve(text, language, compile_source)
        text = tidy(text)
        if error:
            cause = cause or f'compile ({language}): {error}'
            continue
        ok, message = compile_source(text, language)
        if not ok:
            cause = cause or f'compile ({language}): {message.strip()[:200]}'
            continue
        difference = prove()
        if difference:
            cause = difference
            continue
        left = sorted({match.group(0) for match in CLEANUP_LEFT.finditer(text)})
        if left:
            return False, f'src/{file} not changed: cleanup left in the source: {", ".join(left[:3])}', text
        if write:
            if promote:
                file = promote_to_cpp(file)
                path = os.path.join(ROOT, 'src', file)
                notes = notes + [f'the whole file becomes C++ (src/{file}, config/us/whole_files.tsv), as the function is C++']
            with open(path, 'w') as handle:
                handle.write(text)
            if vu0 and start not in vu0_list:
                with open(os.path.join(ROOT, 'config', 'us', 'vu0_regs.txt'), 'a') as handle:
                    handle.write(f'0x{start:X}\n')
                notes = notes + [f'the whole file now takes the VU0 flag ({start:#X} listed in config/us/vu0_regs.txt)']
        notes = notes + dropped + ([] if write or not promote else [f'the whole file would become C++ ({file[:-2]}.cpp)'])
        return True, f'src/{file}: {address:#X} {"would land" if not write else "landed"}, {start:#X}-{end:#X} proved' + \
            (f' ({"; ".join(notes)})' if notes else ''), text
    return False, f'src/{file} not changed: {cause}', None


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
    parser.add_argument('--boundaries', help='work/boundaries/file_boundaries.tsv')
    parser.add_argument('--land', metavar='ADDRESS', help='land this function (it scores 0 on its own) in its whole file: see land()')
    parser.add_argument('--source', help='--land: the per-function source (default: the registry\'s, data/matching/functions.tsv)')
    parser.add_argument('--dry-run', action='store_true', help='--land: prove but write nothing; --output gets the text')
    parser.add_argument('--output', help='--land: also write the landed whole file here')
    parser.add_argument('--list', action='store_true', help='print the candidates and why the others are left out')
    parser.add_argument('--write', action='store_true', help='write the proved files to src/ and print their whole_files.tsv rows')
    parser.add_argument('--limit', type=int, help='only the first N candidates')
    parser.add_argument('--only', help='only the candidate starting at this address')
    parser.add_argument('--jobs', type=int, default=os.cpu_count())
    parser.add_argument('--report', help='write the stage report (start, end, file, status, cause) here')
    parser.add_argument('--dump', help='write every generated text to this directory, proved or not')
    arguments = parser.parse_args()
    if arguments.land:
        address = int(arguments.land, 16)
        ok, message, text = land(address, arguments.source or registry_source(address), write=not arguments.dry_run)
        if text is not None and arguments.output:
            with open(arguments.output, 'w') as handle:
                handle.write(text)
        print(('' if ok else 'not landed: ') + message)
        return 0 if ok else 1
    if not arguments.boundaries:
        parser.error('--boundaries is needed unless --land is given')
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
    sys.exit(main())
