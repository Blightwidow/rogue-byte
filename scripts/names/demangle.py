#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/demangle.py - GCC 2.95 ("gnu v2") demangling of the Sly 1 decomp names, and a C header of their prototypes.

  python3 scripts/names/demangle.py config/recovered/sly2_combined_symbol_addrs.txt config/recovered/      writes config/recovered/sly2.h and config/recovered/sly2_signatures.json
  (when config/recovered/sly2_signature_flags.tsv exists, from FlagSignatures.java, a prototype the Sly 2 code contradicts gets a
  SUSPECT comment in the header; when config/recovered/sly2_signature_flags.tsv.repairs.tsv exists, a repaired prototype is shown
  above the Sly 1 one)
  python3 scripts/names/demangle.py --all config/sly1/sly1_symbol_addrs.txt config/recovered/sly1/   every mangled name, not only source:sly1 (Sly 1 itself)
  python3 scripts/names/demangle.py --test                                      runs the self-tests

The v2 scheme encodes parameters, not the return type:
  Name__F<params>             free function            InitLo__FP2LO -> InitLo(LO *)
  Name__<n><Class><params>    method (gets this)        Startup__3CGc -> CGc::Startup(CGc *this)
  __<n><Class><params>        constructor               __3CGc
  _$_<n><Class>               destructor
  __<op>__<...>               operator (eq, ml, as...)  __eq__4CRefRC4CRef
Parameter codes: v void, i int, c char, s short, l long, x long long, f float, d double, b bool, w wchar_t, e "...",
U unsigned, S signed, C const, V volatile, P pointer, R reference, A<n>_ array, F<params>_<ret> function,
<n><Name> class, G<n><Name> class by value, Q<k><n><A><n><B> qualified, T<i> same as parameter i, N<count><i> parameter i
repeated count times.

Return types come from Sucker Punch's Hungarian prefixes where the name has one (F = flag, G = float, Rad = radians,
C = count, S = parameter value, P... = pointer when the next letter is upper case); otherwise they stay unknown.
"""
import json
import os
import re
import sys

BUILTIN = {'v': 'void', 'i': 'int', 'c': 'char', 's': 'short', 'l': 'long', 'x': 'long long', 'f': 'float',
           'd': 'double', 'b': 'bool', 'w': 'wchar_t', 'r': 'long double'}
# C++ operator -> (C++ spelling, C identifier for the header)
OPERATORS = {'eq': ('operator==', 'op_equal'), 'ne': ('operator!=', 'op_not_equal'), 'as': ('operator=', 'op_assign'),
             'ml': ('operator*', 'op_multiply'), 'pl': ('operator+', 'op_add'), 'mi': ('operator-', 'op_subtract'),
             'dv': ('operator/', 'op_divide'), 'apl': ('operator+=', 'op_add_assign'), 'ami': ('operator-=', 'op_subtract_assign'),
             'aml': ('operator*=', 'op_multiply_assign'), 'adv': ('operator/=', 'op_divide_assign'), 'vc': ('operator[]', 'op_index'),
             'nw': ('operator new', 'op_new'), 'dl': ('operator delete', 'op_delete'), 'vn': ('operator new[]', 'op_new_array'),
             'vd': ('operator delete[]', 'op_delete_array'), 'lt': ('operator<', 'op_less'), 'gt': ('operator>', 'op_greater'),
             'nt': ('operator!', 'op_not'), 'ad': ('operator&', 'op_and'), 'cl': ('operator()', 'op_call')}


class Unsupported(Exception):
    pass


class TypeReader:
    """Reads one mangled parameter list; each parameter is a C type string (pointer stars written C-style)."""

    def __init__(self, text, this=None):
        self.text, self.position = text, 0
        # T and N count parameters from 0, and for a method the implicit this is parameter 0
        self.parameters = [this] if this else []

    def peek(self):
        return self.text[self.position] if self.position < len(self.text) else ''

    def take(self, count=1):
        chunk = self.text[self.position:self.position + count]
        self.position += count
        return chunk

    def number(self):
        start = self.position
        while self.peek().isdigit():
            self.position += 1
        if start == self.position:
            raise Unsupported(f'number expected at {self.position} in {self.text}')
        return int(self.text[start:self.position])

    def class_name(self):
        length = self.number()
        name = self.take(length)
        if len(name) != length:
            raise Unsupported(f'short class name in {self.text}')
        return name

    def qualified(self):
        count = int(self.take())
        return '::'.join(self.class_name() for _ in range(count))

    def one(self):
        """One type: (c_type, struct_names_used)."""
        qualifiers = []
        while self.peek() in ('C', 'V', 'U', 'S'):
            qualifiers.append({'C': 'const', 'V': 'volatile', 'U': 'unsigned', 'S': 'signed'}[self.take()])
        code = self.peek()
        if code == 'P' or code == 'R':
            self.take()
            inner, structs = self.one()
            if '(*)' in inner:  # P before F: the function type is already written as a pointer
                return inner, structs
            pointer = f'{inner} *' if code == 'P' else f'{inner} &'
            return (' '.join(qualifiers + [pointer]) if qualifiers else pointer), structs
        if code == 'A':
            self.take()
            size = self.number()
            if self.take() != '_':
                raise Unsupported(f'array in {self.text}')
            inner, structs = self.one()
            return f'{inner} [{size}]', structs
        if code == 'F':
            self.take()
            parameters = []
            while self.peek() not in ('_', ''):
                parameters.append(self.one())
            self.take()
            result, structs = self.one()
            for _, used in parameters:
                structs |= used
            listed = ', '.join(t for t, _ in parameters) or 'void'
            return f'{result} (*)({listed})', structs
        if code == 'G':
            self.take()
            return self.one()
        if code.isdigit():
            name = self.class_name()
            return ' '.join(qualifiers + [name]), {name}
        if code == 'Q':
            self.take()
            name = self.qualified()
            return ' '.join(qualifiers + [name.replace('::', '_')]), {name.replace('::', '_')}
        if code in BUILTIN:
            self.take()
            return ' '.join(qualifiers + [BUILTIN[code]]), set()
        if code == 'e':
            self.take()
            return '...', set()
        raise Unsupported(f'type code {code!r} in {self.text}')

    def all(self):
        structs = set()
        while self.position < len(self.text):
            code = self.peek()
            if code == 'T':
                self.take()
                index = self.number() if self.peek().isdigit() else 0
                if index >= len(self.parameters):
                    raise Unsupported(f'T{index} in {self.text}')
                self.parameters.append(self.parameters[index])
                continue
            if code == 'N':
                self.take()
                count = int(self.take())
                index = int(self.take())
                if index >= len(self.parameters):
                    raise Unsupported(f'N in {self.text}')
                self.parameters.extend([self.parameters[index]] * count)
                continue
            if code == '_':  # trailing underscore of an old-style name
                self.take()
                continue
            parameter, used = self.one()
            structs |= used
            self.parameters.append(parameter)
        if self.parameters[-1:] == ['void']:
            self.parameters.pop()
        return self.parameters, structs


def guess_return(name):
    base = name.split('::')[-1]
    if re.match(r'^F[A-Z]', base):
        return 'int'
    if re.match(r'^(G|Rad|Deg|S)[A-Z]', base):
        return 'float'
    if re.match(r'^C[A-Z][a-z]', base):
        return 'int'
    if re.match(r'^(P[a-z]{1,6}[A-Z]|Pv[A-Z])', base):
        return 'void *'
    return None


def demangle(mangled):
    """{'name', 'class', 'parameters', 'return', 'structs'} or None for a plain C name; raises Unsupported."""
    klass = None
    c_identifier = None
    if mangled.startswith('_$_'):
        reader = TypeReader(mangled[3:])
        klass = reader.qualified() if reader.peek() == 'Q' else reader.class_name()
        name, rest = '~' + klass.split('::')[-1], ''
        c_identifier = 'destructor'
    elif mangled.startswith('__') and re.match(r'^__([a-z]{2,3})__', mangled) and re.match(r'^__([a-z]{2,3})__', mangled).group(1) in OPERATORS:
        operator, rest = re.match(r'^__([a-z]{2,3})__(.*)$', mangled).groups()
        name, c_identifier = OPERATORS[operator]
        if rest.startswith('F'):
            rest = rest[1:]
        else:
            reader = TypeReader(rest)
            klass = reader.qualified() if reader.take() == 'Q' else (setattr(reader, 'position', 0) or reader.class_name())
            rest = rest[reader.position:]
    elif mangled.startswith('__') and mangled[2:3].isdigit() or mangled.startswith('__Q'):
        reader = TypeReader(mangled[2:])
        klass = reader.qualified() if reader.take() == 'Q' else (setattr(reader, 'position', 0) or reader.class_name())
        name, rest = klass.split('::')[-1], mangled[2 + reader.position:]
        c_identifier = 'constructor'
    else:
        split = mangled.find('__', 1)
        if split <= 0:
            return None
        name, rest = mangled[:split], mangled[split + 2:]
        if rest.startswith('F'):
            rest = rest[1:]
        elif rest[:1].isdigit() or rest.startswith('Q'):
            reader = TypeReader(rest)
            klass = reader.qualified() if reader.take() == 'Q' else (setattr(reader, 'position', 0) or reader.class_name())
            rest = rest[reader.position:]
        else:
            return None
    c_class = klass.replace('::', '_') if klass else None
    parameters, structs = TypeReader(rest, f'{c_class} *this' if c_class else None).all()
    if c_class:
        structs = structs | {c_class}
    return {'name': name, 'class': klass, 'c_identifier': c_identifier or name, 'parameters': parameters,
            'return': 'void' if c_identifier in ('constructor', 'destructor') else guess_return(name), 'structs': sorted(structs)}


def c_name(entry):
    """A C identifier for the header: Class_method for methods, the plain name otherwise."""
    return f"{entry['class'].replace('::', '_')}_{entry['c_identifier']}" if entry['class'] else entry['c_identifier']


def declare(entry, address):
    def parameter(index, c_type):
        if c_type == '...':
            return '...'
        if '(*)' in c_type:
            return c_type.replace('(*)', f'(*arg{index})')
        if c_type.endswith(' *this'):
            return c_type
        if '[' in c_type:
            base, array = c_type.split(' [')
            return f'{base} arg{index}[{array}'
        return f'{c_type} arg{index}'
    listed = ', '.join(parameter(i, t) for i, t in enumerate(entry['parameters'])) or 'void'
    result = entry['return'] or 'undefined4'
    return f"{result} {entry['c_name']}({listed}); /* 0x{address:X} {entry['mangled']} */"


SYMBOL = re.compile(r'^\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;\s*//\s*type:func(.*)$')


def main():
    if len(sys.argv) == 2 and sys.argv[1] == '--test':
        return test()
    take_all = len(sys.argv) == 4 and sys.argv[1] == '--all'
    if take_all:
        sys.argv.pop(1)
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    symbols, out = sys.argv[1], sys.argv[2]
    entries, failed, structs = [], [], set()
    for line in open(symbols, encoding='utf-8'):
        match = SYMBOL.match(line)
        if not match or not (take_all or 'source:sly1' in match.group(3)):
            continue
        mangled, address = match.group(1), int(match.group(2), 16)
        mangled = re.sub(r'_\d+$', '', mangled) if re.search(r'__.*_\d+$', mangled) and not re.search(r'__.*_$', mangled) else mangled
        try:
            entry = demangle(mangled)
        except Unsupported as error:
            failed.append((mangled, str(error)))
            continue
        if entry is None:
            continue
        entry.update(address=address, mangled=mangled)
        entries.append(entry)
        structs.update(entry['structs'])
    os.makedirs(out, exist_ok=True)
    entries.sort(key=lambda e: e['address'])
    seen = {}
    for entry in entries:  # overloads share a C name: number the later ones, as the symbol file does
        base = c_name(entry)
        seen[base] = seen.get(base, 0) + 1
        entry['c_name'] = base if seen[base] == 1 else f'{base}_{seen[base]}'
    suspects = {}
    flags_path = os.path.join(out, 'sly2_signature_flags.tsv')
    if os.path.isfile(flags_path):
        with open(flags_path, encoding='utf-8') as flags_file:
            next(flags_file)
            for line in flags_file:
                address, _name, severity, findings = line.rstrip('\n').split('\t')
                if severity == 'high':
                    suspects[int(address, 16)] = findings.replace('*/', '* /')
    repairs = {}
    repairs_path = flags_path + '.repairs.tsv'
    if os.path.isfile(repairs_path):
        with open(repairs_path, encoding='utf-8') as repairs_file:
            next(repairs_file)
            for line in repairs_file:  # the last repair of a function is its final prototype
                address, _name, _before, after, _reason = line.rstrip('\n').split('\t')
                repairs[int(address, 16)] = after.replace('*/', '* /')
    with open(os.path.join(out, 'sly2.h'), 'w', encoding='utf-8') as f:
        f.write('/* Sly 2: Band of Thieves (SCUS-97316): prototypes of the functions named from the Sly 1 decomp, demangled\n')
        f.write(' * from their GCC 2.95 names by scripts/names/demangle.py. Parameters come from the mangling; return types are guessed from\n')
        f.write(' * the Hungarian prefix (F flag, G float, ...) or left undefined4. Names come from code matching: unverified.\n')
        f.write(' * Structs are opaque: Sly 2 layouts differ from Sly 1. The parameter lists are Sly 1\'s: a function can keep its\n')
        f.write(' * role and name in Sly 2 but change its parameters (CalcCmAdjust looks like it takes an output VECTOR first). */\n\n')
        f.write('typedef unsigned int undefined4;\n')
        f.write('typedef int bool;\ntypedef int wchar_t;\n\n')
        for struct in sorted(structs):
            f.write(f'typedef struct {struct} {struct};\n')
        f.write('\n')
        for entry in sorted(entries, key=lambda e: e['address']):
            if entry['address'] in repairs:
                f.write(f"/* REPAIRED for Sly 2: {repairs[entry['address']]} */\n")
            if entry['address'] in suspects:
                f.write(f"/* SUSPECT in Sly 2: {suspects[entry['address']]} */\n")
            f.write(declare(entry, entry['address']).replace(' &', ' *') + '\n')
    with open(os.path.join(out, 'sly2_signatures.json'), 'w', encoding='utf-8') as f:
        json.dump([{'address': e['address'], 'name': e['c_name'], 'return': e['return'], 'parameters': [p.replace(' &', ' *') for p in e['parameters']]}
                   for e in sorted(entries, key=lambda e: e['address'])], f, indent=0)
    print(f'{len(entries)} prototypes, {len(structs)} opaque structs, {len(failed)} names not demangled, {len(repairs)} repaired, {len(suspects)} still suspect')
    for mangled, error in failed[:10]:
        print(f'  not demangled: {mangled} ({error})')


def test():
    cases = {
        'InitLo__FP2LO': ('InitLo', None, ['LO *']),
        'CloneAsegbl__FP6ASEGBLP2LO': ('CloneAsegbl', None, ['ASEGBL *', 'LO *']),
        'Startup__3CGc': ('Startup', 'CGc', ['CGc *this']),
        'AddRootFrame__3CGcP6CFrame': ('AddRootFrame', 'CGc', ['CGc *this', 'CFrame *']),
        'PrefFindBinding__6CFrameUii': ('PrefFindBinding', 'CFrame', ['CFrame *this', 'unsigned int', 'int']),
        'FFloatsNear__Ffff': ('FFloatsNear', None, ['float', 'float', 'float']),
        'RadBetweenVectors__FP6VECTORN20': ('RadBetweenVectors', None, ['VECTOR *', 'VECTOR *', 'VECTOR *']),
        'FInvertMatrix__FiPfT1': ('FInvertMatrix', None, ['int', 'float *', 'float *']),
        '__eq__4CRefRC4CRef': ('op_equal', 'CRef', ['CRef *this', 'const CRef &']),
        'Draw__9CRichTextP8CTextBoxT1P4GIFS': ('Draw', 'CRichText', ['CRichText *this', 'CTextBox *', 'CTextBox *', 'GIFS *']),
        '__5CProgP4RGBAN31': ('constructor', 'CProg', ['CProg *this', 'RGBA *', 'RGBA *', 'RGBA *', 'RGBA *']),
        '__3CGc': ('constructor', 'CGc', ['CGc *this']),
        '__ml__FG8VU_FLOATG9VU_VECTOR': ('op_multiply', None, ['VU_FLOAT', 'VU_VECTOR']),
        'MinimizeRange__FPFPvf_fPvffffPfT6': ('MinimizeRange', None, ['float (*)(void *, float)', 'void *', 'float', 'float', 'float', 'float', 'float *', 'float *']),
        'RefCmp__FP4CRef4CMPK': ('RefCmp', None, ['CRef *', 'CMPK']),
        'Reset__10CMpegAudio': ('Reset', 'CMpegAudio', ['CMpegAudio *this']),
        'RemoveLo__FP2LO': ('RemoveLo', None, ['LO *']),
        'GetSomething__Fv': ('GetSomething', None, []),
    }
    failures = 0
    for mangled, (name, klass, parameters) in cases.items():
        got = demangle(mangled)
        if (got['c_identifier'], got['class'], got['parameters']) != (name, klass, parameters):
            failures += 1
            print(f'FAIL {mangled}: {got}')
    returns = {'FFloatsNear': 'int', 'GLimitAbs': 'float', 'RadNormalize': 'float', 'CSolveQuadratic': 'int',
               'SFromCrvlU': 'float', 'SetJtPuppet': None, 'CloneLo': None, 'InitLo': None}
    for name, expected in returns.items():
        if guess_return(name) != expected:
            failures += 1
            print(f'FAIL return {name}: {guess_return(name)} != {expected}')
    print(f'{len(cases) + len(returns) - failures} of {len(cases) + len(returns)} tests pass')
    sys.exit(1 if failures else 0)


if __name__ == '__main__':
    main()
