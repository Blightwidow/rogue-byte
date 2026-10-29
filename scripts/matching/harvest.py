#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""harvest.py - which unsourced functions a plain decompiler draft already matches.

  .venv/bin/python scripts/matching/harvest.py [--max-size N] [--limit N] [--write] [--m2c PATH]

Runs m2c (https://github.com/matt-kempster/m2c, GPL-3.0; clone it, `--m2c` or work/matching/tools/m2c/m2c.py) on the split assembly of
every function that has no source yet, makes the draft compile (m2c's own macro header, unknown types taken as int, the callee
declarations in an `extern "C"` block), judges it with scripts/matching/scorer.py, and tries a second variant whose callee return types
come from callee_sigs.py (`void` where the code says no result). A draft that scores 0 needs no editing: `--write` saves it as
data/matching/src/fn/<ADDRESS>.cpp, and scripts/matching/record_round.py then registers it. The others are kept in
work/matching/harvest/ with their scores, so `--near` lists the closest first (the drafts to edit by hand).

m2c cannot handle every R5900 instruction (unaligned loads, VU0 and multimedia instructions): such drafts are skipped and counted."""
import argparse
import concurrent.futures
import csv
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scorer  # noqa: E402

LAB = scorer.LAB
SPLIT = os.path.join(LAB, 'work', 'matching', 'split', 'asm', 'functions', 'SCUS_973')
M2C = os.path.join(LAB, 'work', 'matching', 'tools', 'm2c', 'm2c.py')
OUT = os.path.join(LAB, 'work', 'matching', 'harvest')
SOURCES = os.path.join(LAB, 'data', 'matching', 'src', 'fn')
SIGNATURES = os.path.join(LAB, 'work', 'matching', 'callee_sigs.tsv')
PRELUDE = '''typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
'''
VU_CALL = re.compile(r'M2C_VU_([SOQM])([0-9a-f]+)\(')
REJECT = re.compile(r'M2C_ERROR|M2C_LWL|M2C_FIRST3BYTES|M2C_UNALIGNED|Decompilation failure|unknown instruction')
DECLARATION = re.compile(r'^(M2C_UNK|s32|void|f32|\w+)(\s+\**)(\w+)\((.*)\);\s*(/\*.*\*/)?\s*$')


def candidates(arguments):
    with open(scorer.REGISTRY, encoding='utf-8') as handle:
        rows = [row for row in csv.DictReader(handle, delimiter='\t') if row['status'] == 'todo' and arguments.min_size <= int(row['size']) <= arguments.max_size]
    rows.sort(key=lambda row: int(row['size']))
    return rows[:arguments.limit] if arguments.limit else rows


SCALARS = {'void', 'char', 'short', 'int', 'long', 'float', 'double', 'unsigned', 's8', 's16', 's32', 's64', 'u8', 'u16', 'u32', 'u64', 'f32', 'f64'}
SIGNATURE_KIND = {'void': 'void', 'unknown': 'void', 'int': 's32', 'int?': 's32', 'float': 'f32', 'float?': 'f32'}


def c_type(text):
    """A C type m2c's parser accepts for a type written in a source: scalars stay, every pointer is `void *`, the rest an int."""
    words = text.replace('const', ' ').replace('struct', ' ').split()
    if not words:
        return 's32'
    if '*' in text:
        return 'void *'
    if all(word in SCALARS for word in words):
        return ' '.join(words)
    return 's128' if 'QW' in words else 's32'


def source_signature(name, text):
    """(return type, [parameter types]) of the definition of `name` in a matched source, in C types, or None."""
    match = re.search(rf'^(?:extern "C"\s+)?([A-Za-z_][\w \*]*?)\s*\b{re.escape(name)}\s*\(([^)]*)\)\s*(?:\{{|$)', text, re.M)
    if not match:
        return None
    parameters = [] if match.group(2).strip() in ('', 'void') else [c_type(re.sub(r'\b\w+\s*(\[\d*\])?\s*$', '', part) if re.search(r'[\w\*]\s+\**\w+\s*(\[\d*\])?\s*$', part) else part) for part in match.group(2).split(',')]
    return c_type(match.group(1)), parameters


def build_context(path):
    """Writes a C file of prototypes for every function: the real signature from its matched source, else the one the code implies
    (callee_sigs.py: return kind and the number of integer parameters). m2c reads it with --context. Returns the number of prototypes."""
    with open(scorer.REGISTRY, encoding='utf-8') as handle:
        registry = list(csv.DictReader(handle, delimiter='\t'))
    inferred = {}
    if os.path.exists(SIGNATURES):
        with open(SIGNATURES, encoding='utf-8') as handle:
            inferred = {row['name']: row for row in csv.DictReader(handle, delimiter='\t')}
    lines = ['typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;', 'typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;', 'typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));']
    count = 0
    for row in registry:
        name = row['name']
        if not re.fullmatch(r'[A-Za-z_]\w*', name):
            continue
        signature = None
        if row['status'] == 'matched' and row['source']:
            source = os.path.join(LAB, row['source'])
            if os.path.exists(source):
                with open(source, encoding='utf-8') as handle:
                    signature = source_signature(name, handle.read())
        if signature is None and name in inferred:
            kind = SIGNATURE_KIND[inferred[name]['inferred']]
            signature = (kind, None)  # the parameter count read from the code is only a lower bound: leave the list open
        if signature:
            lines.append(f'{signature[0]} {name}({"" if signature[1] is None else ", ".join(signature[1]) or "void"});')
            count += 1
    with open(path, 'w', encoding='utf-8') as handle:
        handle.write('\n'.join(lines) + '\n')
    return count


TEXT_ASSEMBLY = os.path.join(LAB, 'work', 'matching', 'split', 'asm', 'SCUS_973.text.s')
INSTRUCTION_LINE = re.compile(r'^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/')
_text_index = {}


def instruction_at(address):
    """The assembly line of the whole-text split at a virtual address (the file is read once), or None."""
    if not _text_index and os.path.exists(TEXT_ASSEMBLY):
        with open(TEXT_ASSEMBLY, encoding='utf-8') as handle:
            for line in handle:
                found = INSTRUCTION_LINE.match(line)
                if found:
                    _text_index[int(found.group(1), 16)] = line.rstrip('\n')
    return _text_index.get(address)


def patch_assembly(path):
    """The function's assembly with what the split left out, or None when nothing needed fixing: the delay slot after a final `jr $ra`
    (it belongs to the function but sits past its recorded size) and the labels of branch targets inside the function that the split
    did not write."""
    with open(path, encoding='utf-8') as handle:
        lines = handle.read().split('\n')
    changed = False
    instructions = [(index, int(found.group(1), 16)) for index, line in enumerate(lines) if (found := INSTRUCTION_LINE.match(line))]
    if not instructions:
        return None
    last_index, last_address = instructions[-1]
    if re.match(r'^\s*/\*[^*]*\*/\s+jr\s+\$ra\s*$', lines[last_index]):
        slot = instruction_at(last_address + 4)
        if slot:
            lines.insert(last_index + 1, slot)
            changed = True
    text = '\n'.join(lines)
    defined = set(re.findall(r'^\s*(\.L\w+):', text, re.M))
    insertions = []
    for target in sorted(set(re.findall(r'(?<![\w.])(\.L[0-9A-F]{8})\b', text)) - defined):
        address = int(target[2:], 16)
        for index, instruction_address in instructions:
            if instruction_address == address:
                insertions.append((index, f'  {target}:'))
                break
    for index, label in sorted(insertions, reverse=True):
        lines.insert(index, label)
        changed = True
    if not changed:
        return None
    return '\n'.join(lines)


def run_m2c(arguments, row):
    """The draft text for a function, from the cache or a fresh m2c run; None when m2c fails."""
    folder = 'm2c-context' if arguments.context else 'm2c-vu'
    os.makedirs(os.path.join(OUT, folder), exist_ok=True)
    cached = os.path.join(OUT, folder, f'{int(row["address"], 16):06X}.c')
    if os.path.exists(cached):
        with open(cached, encoding='utf-8') as handle:
            return handle.read()
    path = os.path.join(SPLIT, row['name'] + '.s')
    if not os.path.exists(path):
        return None
    command = [sys.executable, arguments.m2c, '-t', 'mipsee-gcc-c', '--valid-syntax', '--stack-structs'] + (['--context', arguments.context] if arguments.context else [])
    result = subprocess.run(command + [path], capture_output=True, text=True, timeout=120)
    if result.returncode or not result.stdout.strip():
        patched = patch_assembly(path)  # the split can leave out a final delay slot or a branch label
        if patched is None:
            return None
        os.makedirs(os.path.join(OUT, 'patched'), exist_ok=True)
        patched_path = os.path.join(OUT, 'patched', row['name'] + '.s')
        with open(patched_path, 'w', encoding='utf-8') as handle:
            handle.write(patched)
        result = subprocess.run(command + [patched_path], capture_output=True, text=True, timeout=120)
        if result.returncode or not result.stdout.strip():
            return None
    with open(cached, 'w', encoding='utf-8') as handle:
        handle.write(result.stdout)
    return result.stdout


def split_arguments_top(text):
    """The top-level comma-separated pieces of an argument list (commas inside brackets stay)."""
    pieces, depth, current = [], 0, ''
    for character in text:
        if character in '([{':
            depth += 1
        elif character in ')]}':
            depth -= 1
        if character == ',' and depth == 0:
            pieces.append(current.strip())
            current = ''
        else:
            current += character
    if current.strip():
        pieces.append(current.strip())
    return pieces


def lift_vu(body):
    """Turns the opaque VU0 calls of the patched m2c (scripts/matching/m2c_vu.patch) into `asm volatile` statements: a call that
    gives a value (qmfc2, cfc2) becomes a temporary written by the asm, and the temporary replaces the call in its statement."""
    out, counter = [], 0
    for line in body.split('\n'):
        while True:
            match = None
            for match in VU_CALL.finditer(line):  # the last one is the innermost of a nested call
                pass
            if match is None:
                break
            depth, end = 1, match.end()
            while end < len(line) and depth:
                depth += {'(': 1, ')': -1}.get(line[end], 0)
                end += 1
            arguments = split_arguments_top(line[match.end():end - 1])
            text = bytes.fromhex(match.group(2)).decode()
            text = re.sub(r'\b(acc|q|p|i|r)\b', lambda found: found.group(1).upper(), text).replace('"', '\\"')  # the VU special registers are upper case for the assembler
            text = re.sub(r'%(?!\d)', '%%', text)  # a relocation operator (%lo) is not an operand marker
            inputs = ', '.join(f'"r"({argument})' for argument in arguments)
            indent = re.match(r'\s*', line).group(0)
            if match.group(1) in 'OQM':
                counter += 1
                temporary = f'vu_{counter}'
                out.append(f'{indent}{"s128" if match.group(1) == "Q" else "s32"} {temporary};')
                if match.group(1) == 'M':  # the second argument is the value the instruction merges into
                    inputs = f'"r"({arguments[0]}), "0"({arguments[1]})'
                out.append(f'{indent}asm volatile("{text}" : "=r"({temporary}){" : " + inputs if inputs else ""});')
                line = line[:match.start()] + temporary + line[end:]
            else:
                out.append(f'{indent}asm volatile("{text}"{" : : " + inputs if inputs else ""});')
                line = line[:match.start()] + line[end:]
                if not line.strip(' ;'):
                    line = ''
        if line.strip():
            out.append(line)
    return '\n'.join(out)


STACK_FIELD = re.compile(r'/\*\s*(0x[0-9A-Fa-f]+)\s*\*/\s*([\w ]+?)\s*(\**)\s*(\w+)(\[[^\]]*\])?;')


def stack_field_macros(body):
    """`#define`s that make the fields of m2c's `struct _m2c_stack_<name>` (sp0, sp10, ...) views into the local `sp` buffer."""
    match = re.search(r'struct _m2c_stack_\w+ \{(.*?)\};', body, re.S)
    if not match:
        return ''
    lines = []
    after = body[match.end():]
    declared = set(re.findall(r'^[ \t]+(?![ \t]|return\b)[\w ]+?\s*\**\s*(\w+)(?:\[[^\]]*\])?;', after, re.M))  # m2c made these locals of the function
    for field in STACK_FIELD.finditer(match.group(1)):
        offset, kind, stars, name, array = field.groups()
        if name.startswith('pad') or name in declared:
            continue
        kind = (kind.strip() + ' ' + stars).strip()
        lines.append(f'#define {name} ((' + kind + ' *)(sp + ' + offset + '))' if array else f'#define {name} (*({kind} *)(sp + {offset}))')
    return '\n'.join(lines) + '\n' if lines else ''


def build(draft, signatures=None):
    """C++ source for a draft: prelude, then everything in an extern "C" block. `signatures` (name -> 'void'|'int'|'float') retypes callees."""
    if REJECT.search(draft):
        return None
    lines = []
    for line in draft.split('\n'):
        if line.startswith('#include') or line.startswith('/* Warning'):
            continue
        match = DECLARATION.match(line)
        if signatures is not None and match and match.group(3) in signatures and line.rstrip().endswith(('*/', ');')) and not line.startswith(' '):
            line = f'{signatures[match.group(3)]}{match.group(2)}{match.group(3)}({match.group(4)});'
        lines.append(line)
    body = '\n'.join(lines)
    body = re.sub(r'(M2C_FIELD\((?:[^()]|\([^()]*\))*?,\s*)[\w ]+\*+\s*\([^()*][^()]*\)(\s*,)', r'\1s8 **\2', body)  # a function type where a pointer type belongs
    body = lift_vu(body)
    body = re.sub(r'\bvoid\s*\*', 's8 *', body)  # C++ forbids arithmetic on void *
    stack = re.search(r'struct _m2c_stack_(\w+) \{.*?\};\s*/\* size = (0x[0-9A-Fa-f]+) \*/', body, re.S)
    if stack and re.search(r'(?<![\w.>])sp(?!\w)', body):  # `sp` is the address of the function's stack area: a local buffer of that size
        body = re.sub(rf'(\b{re.escape(stack.group(1))}\([^)]*\)\s*\{{\n)', rf'\1    s8 sp[{stack.group(2)}] __attribute__((aligned(16)));\n', body, count=1)
    saved = sorted(set(re.findall(r'\bsaved_reg_\w+', body)))
    if saved:  # callee-saved registers m2c reads before any write (the function saves and restores them): locals
        opening = re.search(r'^[^\s#/][^;{}]*\)\s*\{\n', body, re.M)
        if opening:
            body = body[:opening.end()] + ''.join(f'    {"f32" if "_f" in name else "s32"} {name};\n' for name in saved) + body[opening.end():]
    extra = []
    if re.search(r'(?<![\w.>])sp(?!\w)', body) and not re.search(r's8 sp\[', body):  # the address of a stack area m2c did not size
        extra.append('    s8 sp[0x100] __attribute__((aligned(16)));\n')
    for name in sorted(set(re.findall(r'\bunksp\w+', body))):  # stack slots m2c used without declaring
        if not re.search(rf'^\s+\w[\w ]*\*?\s*{name}\b', body, re.M):
            extra.append(f'    s32 {name};\n')
    if extra:
        opening = re.search(r'^[^\s#/][^;{}]*\)\s*\{\n', body, re.M)
        if opening:
            body = body[:opening.end()] + ''.join(extra) + body[opening.end():]
    macros = stack_field_macros(body)
    if macros:  # after the struct: the names are also its members
        body = re.sub(r'(struct _m2c_stack_\w+ \{.*?\};[^\n]*\n)', lambda found: found.group(1) + macros, body, count=1, flags=re.S)
    return PRELUDE + 'extern "C" {\n' + body + '\n}\n'


def read_signatures():
    if not os.path.exists(SIGNATURES):
        return {}
    kinds = {'void': 'void', 'unknown': 'void', 'int': 's32', 'int?': 's32', 'float': 'f32', 'float?': 'f32'}
    with open(SIGNATURES, encoding='utf-8') as handle:
        return {row['name']: kinds[row['inferred']] for row in csv.DictReader(handle, delimiter='\t')}


CAST_RULES = (
    (re.compile(r"assignment to `([^']+)' from `[^']+'"), 'assign'),
    (re.compile(r"passing `[^']+' (?:to|as) argument (\d+) of `([^']+)'"), 'argument'),
    (re.compile(r"argument passing to `[^']+' from `[^']+'"), None),
)


def split_arguments(text):
    """The top-level comma-separated pieces of an argument list."""
    pieces, depth, current = [], 0, ''
    for character in text:
        if character in '([':
            depth += 1
        elif character in ')]':
            depth -= 1
        if character == ',' and depth == 0:
            pieces.append(current)
            current = ''
        else:
            current += character
    return pieces + [current]


def parameter_types(signature):
    """The parameter types in a compiler message's `name(type, type)` text."""
    inner = signature[signature.index('(') + 1:signature.rindex(')')]
    return [part.strip() for part in split_arguments(inner)] if inner.strip() else []


POINTER_NAME = re.compile(r'(?:^|[(,])[ \t]*(?:const\s+)?[A-Za-z_]\w*(?:[ \t]+[A-Za-z_]\w*)*[ \t]*\*+[ \t]*(\w+)[ \t]*[;,)=\[]', re.M)


def cast_integer_dereferences(text, number):
    """The line `number` (0-based) with every dereference of an integer expression made `*(s32 *)expr` (`f32` on a line that uses floats):
    m2c leaves a pointer it could not type as an `s32`, and C++ cannot dereference one. An operand that mentions a pointer is left alone."""
    lines = text.split('\n')
    line = lines[number]
    pointers = set(POINTER_NAME.findall(text))
    kind = 'f32' if re.search(r'\b(var|temp)_f\w*|\d\.\d*f\b|\bf32\b', line) else 's32'
    result, index, changed = '', 0, False
    while index < len(line):
        character = line[index]
        before = result.rstrip()
        unary = character == '*' and (not before or before[-1] in '(=,;{[+-*/<>!&|?:' or before.endswith('return'))
        if not unary:
            result += character
            index += 1
            continue
        end = index + 1
        while end < len(line) and line[end] == ' ':
            end += 1
        start = end
        if end < len(line) and line[end] == '(':
            depth = 0
            while end < len(line):
                depth += (line[end] == '(') - (line[end] == ')')
                end += 1
                if depth == 0:
                    break
        else:
            while end < len(line) and (line[end].isalnum() or line[end] == '_'):
                end += 1
            if end < len(line) and line[end] == '(':
                depth = 0
                while end < len(line):
                    depth += (line[end] == '(') - (line[end] == ')')
                    end += 1
                    if depth == 0:
                        break
        operand = line[start:end]
        integer_free = re.sub(r'M2C_FIELD\((?:[^()]|\([^()]*\))*?,\s*[\w ]+\*\s*,\s*[^,()]+\)', ' ', operand)  # a field read as a scalar is an integer term
        names = set(re.findall(r'[A-Za-z_]\w*', integer_free))
        already_cast = re.match(r'^\(\s*[\w ]+\*+\s*\)$', operand)
        field_pointer = re.search(r'M2C_FIELD\([^;]*?,\s*[\w ]+\*\s*\*', operand)
        if already_cast or '&' in operand or names & pointers or field_pointer or operand.startswith('sp'):
            result += character
            index += 1
            continue
        result += f'*({kind} *){operand}'
        changed = True
        index = end
    if not changed:
        return None
    lines[number] = result
    return '\n'.join(lines)


def cast_compared_pointers(text, number):
    """The line `number` (0-based) with each pointer variable that is an operand of a comparison cast to `(s32)`: m2c compares a pointer with
    a scalar it could not type."""
    lines = text.split('\n')
    pointers = set(POINTER_NAME.findall(text))
    line = lines[number]
    comparator = r'(?:==|!=|<=|>=|<|>)'
    changed = line
    for name in pointers:
        changed = re.sub(rf'(?<![\w.>*&])({re.escape(name)})(?=\s*{comparator}\s*(?!0\b|NULL))', r'(s32)\1', changed)
        changed = re.sub(rf'({comparator}\s+)({re.escape(name)})\b(?!\s*[\[(.-])', r'\1(s32)\2', changed)
    if changed == line:
        return None
    lines[number] = changed
    return '\n'.join(lines)


def repair_once(text, message):
    """One edit that answers the first pointer or integer conversion error of a compile message, or None: the right side of an assignment or
    the argument the compiler names gets a cast to the type it expects."""
    error = re.search(r'^[^:]+:(\d+): (?!warning)(.*)$', message, re.M)
    if not error:
        return None
    number, reason = int(error.group(1)) - 1, error.group(2)
    lines = text.split('\n')
    if number >= len(lines):
        return None
    line = lines[number]
    if "invalid type argument of `unary *'" in reason:
        return cast_integer_dereferences(text, number)
    if 'comparison between pointer and integer' in reason:
        return cast_compared_pointers(text, number)
    assign = re.search(r"assignment to `([^']+)' from", reason)
    if assign and '=' in line:
        match = re.match(r'^(\s*[^=]*[^=!<>+\-*/&|^]=)\s*([^=].*?);\s*$', line)
        if match:
            lines[number] = f'{match.group(1)} ({assign.group(1)})({match.group(2)});'
            return '\n'.join(lines)
    argument = re.search(r"argument (\d+) of `([^']+)'", reason)
    if argument:
        index = int(argument.group(1)) - 1
        types = parameter_types(argument.group(2))
        name = argument.group(2).split('(')[0].split()[-1]
        call = re.search(rf'\b{re.escape(name)}\s*\(', line)
        if call and index < len(types):
            start, depth, end = call.end(), 1, call.end()
            while end < len(line) and depth:
                depth += (line[end] == '(') - (line[end] == ')')
                end += 1
            pieces = split_arguments(line[start:end - 1])
            if index < len(pieces):
                pieces[index] = f' ({types[index]})({pieces[index].strip()})' if index else f'({types[index]})({pieces[index].strip()})'
                lines[number] = line[:start] + ','.join(pieces) + line[end - 1:]
                return '\n'.join(lines)
    few = re.search(r"too few arguments to function `[^`']*?(\w+)\([^']*'", reason)
    if few:  # a callee declared from one call and called with fewer arguments elsewhere: any argument list
        name = few.group(1)
        for index, candidate in enumerate(lines):
            declaration = re.match(rf'^([^\s(][^(]*\b{re.escape(name)})\([^)]*\);(.*)$', candidate)
            if declaration and '...' not in candidate:
                lines[index] = f'{declaration.group(1)}(...);{declaration.group(2)}'
                return '\n'.join(lines)
    return None


def judge_with_repair(address, text, attempts=8):
    """(score, text): the draft judged, after up to `attempts` cast repairs when it does not compile."""
    import compile_unit
    for _ in range(attempts):
        score = scorer.judge(address, text)
        if score is not None:
            return score, text
        os.makedirs(scorer.BUILD, exist_ok=True)
        stem = os.path.join(scorer.BUILD, f'repair-{address:06X}-{os.getpid()}-{next(scorer._counter)}')
        with open(stem + '.cpp', 'w') as handle:
            handle.write(text)
        ok, message = compile_unit.compile_object('c++', stem + '.cpp', stem + '.o', assembler=compile_unit.assembler_for(address), include=scorer.INCLUDE, localize=False)
        for leftover in (stem + '.cpp', stem + '.o', stem + '.o.tmp', stem + '.o.s'):
            if os.path.exists(leftover):
                os.remove(leftover)
        if ok:
            return None, text
        edited = repair_once(text, message)
        if edited is None or edited == text:
            return None, text
        text = edited
    return scorer.judge(address, text), text


def wrap_bit_tests(text):
    """`(X >> 0x3C) & 1` with a 64-bit X gets a dsll32/dsra32 pair retail lacks: the shifted value is cast to `(int)`."""
    out, index = '', 0
    marker = re.compile(r'>> (?:0x[0-9A-Fa-f]+|\d+)\) & 1\b')
    while True:
        found = marker.search(text, index)
        if not found:
            return out + text[index:]
        depth, start = 0, found.end() - len(found.group(0)) + len(found.group(0).split(')')[0])  # position of the closing parenthesis
        position = start
        while position >= 0:
            depth += (text[position] == ')') - (text[position] == '(')
            if depth == 0:
                break
            position -= 1
        if position < 0 or text[max(0, position - 5):position] == '(int)':
            out += text[index:found.end()]
        else:
            out += text[index:position] + '(int)' + text[position:found.end()]
        index = found.end()


def sign_extend_masks(text):
    """A 32-bit constant with its top bit set, used as a 64-bit mask (`& 0xFBFFFFFF`), is a sign-extended constant in retail."""
    return re.sub(r'(&\s*)(0x[89A-Fa-f][0-9A-Fa-f]{7})\b(?!\s*[uUlL])', lambda found: f'{found.group(1)}(s64)(s32){found.group(2)}', text)


def long_shifts(text):
    """`0x8000 << 0x23` is an int shift: a 64-bit constant needs `0x8000L`."""
    return re.sub(r'\b(0x[0-9A-Fa-f]+)(\s*<<\s*(?:0x[2-9A-Fa-f][0-9A-Fa-f]|[3-6]\d)\b)', lambda found: f'{found.group(1)}L{found.group(2)}', text)


def pass_through_arguments(text):
    """Variants that give every call of a `(...)` callee its pass-through leading arguments (`arg0`, then `arg0, arg1`): m2c drops an
    untouched `$a0`/`$a1`, and the repair loop's variadic prototype hides it."""
    variants = []
    names = re.findall(r'^[^\s(][^(]*?\b(\w+)\(\.\.\.\);', text, re.M)
    for name in names:
        for prefix in ('arg0', 'arg0, arg1'):
            if prefix.split(',')[-1].strip() not in text:
                continue
            changed = re.sub(rf'(?<![\w.>])({re.escape(name)})\((?!\.\.\.|\))', rf'\1({prefix}, ', text)
            changed = re.sub(rf'(?<![\w.>])({re.escape(name)})\(\)', rf'\1({prefix})', changed)
            if changed != text:
                variants.append((f'{name}+{prefix}', changed))
    return variants


def shape(address, text, score):
    """The draft after the shape fixes that recur in hand-shaped matches (bit-test cast, sign-extended masks, long shifts, pass-through
    arguments): each variant is judged and kept when it scores lower. Returns (score, text)."""
    for _round in range(3):
        before = score
        candidates = [(label, function(text)) for label, function in (('bit', wrap_bit_tests), ('mask', sign_extend_masks), ('shift', long_shifts))]
        candidates += pass_through_arguments(text)
        for _label, variant in candidates:
            if variant == text:
                continue
            result = scorer.judge(address, variant)
            if result is not None and result < score:
                score, text = result, variant
                if score == 0:
                    return score, text
        if score == before:
            break
    return score, text


def harvest_one(arguments, signatures, row):
    address = int(row['address'], 16)
    draft = run_m2c(arguments, row)
    if draft is None:
        return address, 'no draft', None, None
    results = []
    for text in (build(draft), build(draft, signatures)):
        if text is None:
            return address, 'unsupported', None, None
        results.append(judge_with_repair(address, text) if arguments.repair else (scorer.judge(address, text), text))
    scored = [(score, text) for score, text in results if score is not None]
    if not scored:
        return address, 'does not compile', None, None
    score, text = min(scored, key=lambda item: item[0])
    if arguments.shape and score > 0:
        score, text = shape(address, text, score)
    return address, 'ok', score, text


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--m2c', default=M2C)
    parser.add_argument('--min-size', type=int, default=8)
    parser.add_argument('--max-size', type=int, default=4096)
    parser.add_argument('--limit', type=int, default=0)
    parser.add_argument('--jobs', type=int, default=12)
    parser.add_argument('--write', action='store_true', help='save drafts that score 0 as data/matching/src/fn/<ADDRESS>.cpp')
    parser.add_argument('--context', action='store_true', help='give m2c prototypes of every function (real signatures from matched sources, the rest inferred from the code)')
    parser.add_argument('--repair', action='store_true', help='when a draft does not compile, add the casts the compiler asks for (up to 8 edits)')
    parser.add_argument('--keep', type=int, default=-1, metavar='SCORE', help='also save drafts scoring at most SCORE as sources (for mutate.py, neighborhood.py)')
    parser.add_argument('--shape', action='store_true', help='try the recurring shape fixes (bit-test cast, sign-extended masks, long shifts, pass-through arguments) on every draft that compiles')
    parser.add_argument('--refresh', action='store_true', help='with --write: replace a saved source when the new draft scores strictly lower')
    parser.add_argument('--near', type=int, default=0, metavar='N', help='list the N closest drafts')
    arguments = parser.parse_args()
    if not scorer.compare:
        sys.exit('needs rabbitizer and pyelftools: run with .venv/bin/python')
    scorer.registry()
    signatures = read_signatures()
    if arguments.context:
        context = os.path.join(OUT, 'context.h')
        os.makedirs(OUT, exist_ok=True)
        print(f'{build_context(context)} prototypes in {context}')
        arguments.context = context
    rows = candidates(arguments)
    print(f'{len(rows)} functions without source, {arguments.min_size}-{arguments.max_size} bytes')
    outcomes = {}
    scores = []
    table = []
    sizes = {int(row['address'], 16): int(row['size']) for row in rows}
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        for address, outcome, score, text in pool.map(lambda row: harvest_one(arguments, signatures, row), rows):
            outcomes[outcome] = outcomes.get(outcome, 0) + 1
            table.append((address, sizes[address], outcome, score))
            if score is None:
                continue
            scores.append((score, address, text))
            if score == 0 or (arguments.write and score <= arguments.keep):
                if score == 0:
                    print(f'{address:#x}: matches', flush=True)
                if arguments.write:
                    path = os.path.join(SOURCES, f'{address:06X}.cpp')
                    if not os.path.exists(path):
                        with open(path, 'w', encoding='utf-8') as handle:
                            handle.write(text)
                    elif arguments.refresh:  # a saved source is replaced only by a draft that scores strictly lower
                        with open(path, encoding='utf-8') as handle:
                            current = scorer.judge(address, handle.read())
                        if current is None or score < current:
                            with open(path, 'w', encoding='utf-8') as handle:
                                handle.write(text)
                            print(f'{address:#x}: refreshed {current} -> {score}', flush=True)
    scores.sort()
    os.makedirs(OUT, exist_ok=True)
    with open(os.path.join(OUT, 'scores.tsv'), 'w', encoding='utf-8') as handle:
        handle.write('address\tscore\n')
        for score, address, _text in scores:
            handle.write(f'{address:#x}\t{score}\n')
    with open(os.path.join(OUT, 'blockers.tsv'), 'w', encoding='utf-8') as handle:
        handle.write('address\tsize\toutcome\tscore\n')
        for address, size, outcome, score in sorted(table):
            handle.write(f'{address:#x}\t{size}\t{outcome}\t{"" if score is None else score}\n')
    print(', '.join(f'{count} {name}' for name, count in sorted(outcomes.items())))
    print('by size (bytes): functions / draft compiles / within 5 words / match')
    for low, high in ((8, 64), (65, 128), (129, 256), (257, 512), (513, 1024), (1025, 4096)):
        group = [entry for entry in table if low <= entry[1] <= high]
        compiled = [entry for entry in group if entry[3] is not None]
        print(f'  {low:5d}-{high:<5d} {len(group):5d} {len(compiled):5d} {sum(1 for e in compiled if e[3] <= 5):5d} {sum(1 for e in compiled if e[3] == 0):4d}')
    print(f'{sum(1 for score, _, _ in scores if score == 0)} match, {sum(1 for score, _, _ in scores if 0 < score <= 5)} within 5, {sum(1 for score, _, _ in scores if 5 < score <= 20)} within 20')
    for score, address, _text in scores[:arguments.near]:
        print(f'  {address:#x} score {score}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
