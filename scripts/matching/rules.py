#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""rules.py - the source shapes the deep dives found, as rewrites the search can try (docs/contributing/matching.md, "One function per kind").

Each rule turns an m2c-shaped source into the shape the original code most likely had; none is a trick (no volatile, pins or empty asm).
`edits(text)` returns {changed source: (label, 0)}, the format of neighborhood.py's single edits, so `neighborhood.py` judges them with
the rewrites of mutate.py, chains them (depth) and keeps a beam: a rule that first scores worse (a corrected argument that exposes a
store order) can still lead to 0 one step later.

  python3 scripts/matching/rules.py SOURCE        prints every rewrite's label and the changed lines

Rules:
  index_loop     m2c's pointer walk `do { ...; i += 1; p += S; } while (i < n)` back to `for (i = 0; ...) { p = START + i * S; ... }`
  index_first    one `&BASE[INDEX]` as `(T *)((INDEX) * sizeof(*BASE) + (unsigned)BASE)`: the scaled index first, as retail's addu has it
  constify       `extern ... RO_<address>` made `const`: a read-only load is free to move across the stores
  return_result  a `void` function whose local from a call is the result: `T *f() { ...; return local; }`
  missing_parameter m2c names the parameters by register (`arg0, arg1, arg3`): a skipped register is an unused parameter of the real signature, a dummy
                 is inserted so that later parameters arrive in their own registers (a first parameter `arg1` gets `unused_arg0`)
  vcall_object   a virtual call `fn(obj + delta, ..., obj)` as `fn(obj + delta, ...)`: the register that holds `obj` is often just the object's own
  global_array   `extern T g;` as `extern T g[];` read as `g[0]`: the compiler then schedules and aliases the load differently
  call_arguments a callee's trailing argument appended (the caller's own parameter), dropped or replaced; a member re-read after a call
  float_position a float parameter moved to another position of a callee's prototype (the order the argument instructions are emitted in)
  long_long      `long long` (128-bit under SN) as `long`
  by_value       `T *F(T *pret, ...)` returning `pret` as a by-value return (retail's delay-slot filler then emits a plain branch)
"""
import re
import sys

FLOAT_TYPE = re.compile(r'float|f32|f64|double|QW|s128|TI\b')
KEYWORDS = ('if', 'while', 'for', 'return', 'sizeof', 'switch')


def balanced_end(text, start, opener='{', closer='}'):
    """Index just after the closer that matches an opener at text[start - 1], or None."""
    depth = 1
    for index in range(start, len(text)):
        if text[index] == opener:
            depth += 1
        elif text[index] == closer:
            depth -= 1
            if depth == 0:
                return index + 1
    return None


def split_parameters(text):
    parts, current, depth, previous = [], '', 0, ''
    for character in text:
        if character in '(<[':
            depth += 1
        elif character in ')>]' and not (character == '>' and previous == '-'):  # the `>` of `->` closes nothing
            depth -= 1
        previous = character
        if character == ',' and depth == 0:
            parts.append(current.strip())
            current = ''
        else:
            current += character
    if current.strip():
        parts.append(current.strip())
    return [] if parts in ([], ['void']) else parts


# ---- index_loop ----

INDEX_LOOP = re.compile(
    r'(?P<indent>[ \t]*)(?P<counter>\w+) = 0;\n(?P<between>(?:(?!\1if)[^\n]*\n)*?)'
    r'(?P=indent)if \((?P<limit>[^\n]+?) > 0\) \{\n'
    r'(?P<inits>(?:[ \t]+\w+ = [^\n]+;\n)*)'
    r'[ \t]+do \{\n(?P<body>(?:[^\n]*\n)*?)[ \t]+\} while \((?P=counter) < (?P=limit)\);\n'
    r'(?P=indent)\}\n')


def index_loop(text):
    match = INDEX_LOOP.search(text)
    if not match:
        return
    counter, limit, body, indent = match['counter'], match['limit'], match['body'], match['indent']
    steps = dict(re.findall(r'^[ \t]+(\w+) \+= (0x[0-9A-Fa-f]+|\d+);\n', body, re.M))
    if steps.get(counter) != '1':
        return
    inits = dict(re.findall(r'^[ \t]+(\w+) = ([^\n]+);\n', match['inits'], re.M))
    walkers = [name for name in steps if name != counter and name in inits]
    if len(walkers) != 1:
        return
    walker = walkers[0]
    stride = steps[walker]
    kept, advanced = [], False
    for line in body.splitlines(keepends=True):
        if re.fullmatch(rf'[ \t]+{counter} \+= 1;\n', line):
            continue
        if re.fullmatch(rf'[ \t]+{walker} \+= {stride};\n', line):
            advanced = True
            continue
        if advanced and re.search(rf'\b{walker}\b', line):
            return  # a use after the advance needs an offset fix: leave it to a person
        kept.append(line)
    inner = indent + '    '
    emitted = (f'{indent}for ({counter} = 0; {counter} < {limit}; {counter}++) {{\n{inner}{walker} = {inits[walker]} + {counter} * {stride};\n'
               + ''.join(kept) + f'{indent}}}\n')
    yield 'index_loop', text[:match.start()] + match['between'] + emitted + text[match.end():]


# ---- index_first ----

ADDRESS_OF_INDEX = re.compile(r'&\s*([A-Za-z_][\w\->.]*)\[([^\[\]]+)\]')


def index_first(text):
    for which, match in enumerate(list(ADDRESS_OF_INDEX.finditer(text))[:6]):
        base, index = match.group(1), match.group(2)
        replacement = f'(__typeof__(&({base})[0]))(({index}) * sizeof(({base})[0]) + (unsigned)({base}))'
        yield f'index_first #{which}', text[:match.start()] + replacement + text[match.end():]


# ---- constify ----

RO_DECLARATION = re.compile(r'^(\s*extern\s+(?:"C"\s+)?)(?!const\b)(?!")([^;()=]*?\bRO_[0-9A-Fa-f]{6,8}\b[^;()=]*;)', re.M)


def constify(text):
    changed = RO_DECLARATION.sub(lambda match: f'{match.group(1)}const {match.group(2)}', text)
    if changed != text:
        yield 'constify', changed


# ---- return_result ----

def return_result(text):
    definition = None
    for match in re.finditer(r'^(\s*(?:extern\s+"C"\s+)?)void(\s+\w+\s*\([^;{}()]*\)\s*\{)', text, re.M):
        definition = match
    if not definition:
        return
    end = balanced_end(text, definition.end())
    if end is None:
        return
    body = text[definition.end():end - 1]
    for assignment in re.finditer(r'^\s*(\w+)\s*=\s*\(?[\w\s\*]*\)?\s*\w+\s*\([^;]*\)\s*;', body, re.M):
        name = assignment.group(1)
        declaration = re.search(rf'^\s*([\w\s]+?\**)\s*\b{re.escape(name)}\s*[;=]', body, re.M)
        if not declaration or declaration.group(1).strip() in ('return', 'else'):
            continue
        yield f'return_result {name}', (text[:definition.start()] + definition.group(1) + declaration.group(1).strip() + definition.group(2)
                                         + body.rstrip() + f'\n    return {name};\n}}' + text[end:])


# ---- missing_parameter ----

def missing_parameter(text):
    """A function whose parameters are m2c's `argN` (N = the argument register) with N skipped: the real signature has an unused parameter there."""
    matches = [match for match in re.finditer(r'\b(\w+)\s*\(([^;{}()]*)\)\s*\{', text) if match.group(1) not in KEYWORDS]
    if not matches:
        return
    match = matches[-1]
    parameters = split_parameters(match.group(2))
    numbered = []
    for parameter in parameters:
        found = re.fullmatch(r'(.*?)\barg(\d+)', parameter)
        if not found or FLOAT_TYPE.search(found.group(1)):
            return
        numbered.append((int(found.group(2)), parameter))
    if not numbered or [number for number, _ in numbered] != sorted(set(number for number, _ in numbered)):
        return
    present = {number for number, _ in numbered}
    gaps = [number for number in range(max(present) + 1) if number not in present]
    if not gaps or max(present) > 7:
        return
    kind = re.fullmatch(r'(.*?)\barg\d+', numbered[0][1]).group(1).strip() or 's32'
    filled = []
    for number in range(max(present) + 1):
        filled.append(next((parameter for index, parameter in numbered if index == number), f'{kind} unused_arg{number}'))
    for count in range(1, len(gaps) + 1):  # every gap, then only the first ones
        chosen = set(gaps[:count])
        edited = [parameter for number, parameter in zip(range(max(present) + 1), filled) if number in present or number in chosen]
        yield (f'missing_parameter {",".join(str(g) for g in gaps[:count])}',
               text[:match.start(2)] + ', '.join(edited) + text[match.end(2):])


# ---- vcall_object ----

FUNCTION_POINTER = re.compile(r'\(\s*\*\s*(\w+)\s*\)\s*\(([^()]*)\)')


def vcall_object(text):
    """For a function pointer `(*fn)(types)` called as `x->fn(a0, ..., an)` where the last argument is the object that a0 is built from (`(char *)x + delta`),
    drop that last argument and its type at every call."""
    for declaration in FUNCTION_POINTER.finditer(text):
        name, types = declaration.group(1), split_parameters(declaration.group(2))
        if len(types) < 2:
            continue
        calls = []
        for call in re.finditer(rf'(?<![\w])(?:[\w\->.\[\]]*(?:->|\.))?{re.escape(name)}\s*\(', text):
            if call.start() < declaration.end():
                continue
            end = balanced_end(text, call.end(), '(', ')')
            if end is None:
                continue
            args = split_parameters(text[call.end():end - 1])
            if len(args) == len(types):
                calls.append((call.end(), end - 1, args))
        if not calls:
            continue
        if not all(re.sub(r'^\(\s*[\w\s\*]+\)\s*', '', args[-1]) in args[0] for _, _, args in calls):
            continue
        edits = [(declaration.start(2), declaration.end(2), ', '.join(types[:-1]))]
        edits += [(start, end, ', '.join(args[:-1])) for start, end, args in calls]
        pieces, last = [], 0
        for start, end, replacement in sorted(edits):
            pieces += [text[last:start], replacement]
            last = end
        yield f'vcall_object {name}', ''.join(pieces) + text[last:]


# ---- global_array ----

GLOBAL_DECLARATION = re.compile(r'^(\s*extern\s+(?:const\s+)?[\w ]+?\s*)\b((?:g|B|D)_[0-9A-Fa-f]{5,8})\s*;', re.M)


def global_array(text):
    for which, declaration in enumerate(list(GLOBAL_DECLARATION.finditer(text))[:4]):
        name = declaration.group(2)
        head = text[:declaration.start()] + declaration.group(1) + f'{name}[];' + text[declaration.end():]
        body_start = declaration.start() + len(declaration.group(1)) + len(f'{name}[];')
        changed = head[:body_start] + re.sub(rf'(?<![\w.>]){re.escape(name)}\b(?!\s*\[)', f'{name}[0]', head[body_start:])
        if changed != head:
            yield f'global_array {name}', changed


# ---- call_arguments ----

def caller_of(text):
    """(parameters as (type, name), index just after the opening brace) of the last function definition, or None."""
    matches = list(re.finditer(r'\b(\w+)\s*\(([^;{}()]*)\)\s*\{', text))
    matches = [match for match in matches if match.group(1) not in KEYWORDS]
    if not matches:
        return None
    match = matches[-1]
    parameters = []
    for parameter in split_parameters(match.group(2)):
        name = re.search(r'(\w+)\s*$', parameter)
        if not name:
            return None
        parameters.append((parameter[:name.start()].strip(), name.group(1)))
    return parameters, match.end()


def declarations_before(text, body_start):
    found = {}
    for match in re.finditer(r'^([ \t]*(?:extern\s+"C"\s+)?(?:extern\s+)?[\w\s\*]+?[\s\*])(\w+)\s*\(([^;{}()]*)\)\s*;', text[:body_start], re.M):
        if match.group(2) not in KEYWORDS:
            found[match.group(2)] = match
    return found


def calls_of(text, name, body_start):
    calls = []
    for match in re.finditer(rf'(?<![\w.>]){re.escape(name)}\s*\(', text):
        if match.start() < body_start:
            continue
        end = balanced_end(text, match.end(), '(', ')')
        if end is not None:
            calls.append((match.end(), end - 1))
    return calls


def rewrite_calls(text, declaration, new_parameters, calls, transform):
    edits = [(declaration.start(3), declaration.end(3), ', '.join(new_parameters) or 'void')]
    edits += [(start, end, ', '.join(transform(split_parameters(text[start:end])))) for start, end in calls]
    pieces, last = [], 0
    for start, end, replacement in sorted(edits):
        pieces += [text[last:start], replacement]
        last = end
    return ''.join(pieces) + text[last:]


def callee_signatures(text):
    """[(name, declaration match, declared parameters, calls)] of the callees declared in the source and called with their declared count."""
    caller = caller_of(text)
    if not caller:
        return []
    _, body_start = caller
    found = []
    for name, declaration in declarations_before(text, body_start).items():
        declared = split_parameters(declaration.group(3))
        calls = calls_of(text, name, body_start)
        if not calls or '...' in declared:
            continue
        if {len(split_parameters(text[start:end])) for start, end in calls} != {len(declared)}:
            continue
        found.append((name, declaration, declared, calls))
    return found


def call_arguments(text):
    caller = caller_of(text)
    if not caller:
        return
    parameters, body_start = caller
    for name, declaration, declared, calls in callee_signatures(text):
        count = len(declared)
        for total in range(count + 1, min(4, len(parameters)) + 1):  # the caller's own incoming parameters, passed through
            added = parameters[count:total]
            if any(FLOAT_TYPE.search(kind) for kind, _ in added):
                break
            yield (f'call_arguments {name}+{",".join(n for _, n in added)}',
                   rewrite_calls(text, declaration, declared + [kind for kind, _ in added], calls, lambda args, added=added: args + [n for _, n in added]))
        for kept in range(count - 1, -1, -1):  # trailing arguments m2c took for a callee's: a register set that the callee never reads
            yield f'call_arguments {name}-{count - kept}', rewrite_calls(text, declaration, declared[:kept], calls, lambda args, kept=kept: args[:kept])
        for index in range(min(count, len(parameters))):  # one argument that is really the caller's parameter of the same position
            kind, parameter = parameters[index]
            if FLOAT_TYPE.search(kind):
                continue
            yield (f'call_arguments {name}[{index}]={parameter}',
                   rewrite_calls(text, declaration, declared[:index] + [kind] + declared[index + 1:], calls,
                                 lambda args, index=index, parameter=parameter: args[:index] + [parameter] + args[index + 1:]))
    body = text[body_start:]
    for kind, name in parameters:  # `obj->field = param; call(...); use(param)`: the original re-read the member after the call
        for store in re.finditer(rf'^(\s*)([\w\->\.\[\]\*\(\) ]+?)\s*=\s*{re.escape(name)}\s*;', body, re.M):
            target, after = store.group(2).strip(), body[store.end():]
            call = re.search(r'\w+\s*\(', after)
            uses = [use for use in re.finditer(rf'(?<![\w.>]){re.escape(name)}\b', after) if call and use.start() > call.start()]
            for count in range(1, len(uses) + 1):
                changed = after
                for use in reversed(uses[:count]):
                    changed = changed[:use.start()] + target + changed[use.end():]
                yield f'call_arguments reload {name} x{count}', text[:body_start] + body[:store.end()] + changed


# ---- float_position ----

def float_position(text):
    for name, declaration, declared, calls in callee_signatures(text):
        floats = [index for index, kind in enumerate(declared) if FLOAT_TYPE.search(kind)]
        if not floats or len(floats) == len(declared) or len(declared) > 6:
            continue
        for source in floats[:2]:
            for target in range(len(declared)):
                if target == source:
                    continue

                def move(items, source=source, target=target):
                    items = list(items)
                    items.insert(target, items.pop(source))
                    return items
                yield f'float_position {name} {source}->{target}', rewrite_calls(text, declaration, move(declared), calls, move)


# ---- long_long ----

def long_long(text):
    changed = re.sub(r'\blong long\b', 'long', text)
    if changed != text:
        yield 'long_long', changed


# ---- by_value ----

BY_VALUE = re.compile(r'((?:extern\s+"C"\s+)?)(?:struct\s+)?(\w+)\s*\*\s*(\w+)\s*\(\s*(?:struct\s+)?(\w+)\s*\*\s*(\w+)\s*(,\s*[^)]*)?\)\s*\{')


def by_value(text):
    for match in BY_VALUE.finditer(text):
        linkage, return_type, function, parameter_type, parameter = match.groups()[:5]
        if return_type != parameter_type or re.search(r'inline[^\n;{}]*$', text[:match.end(1) + 1]):
            continue
        end = balanced_end(text, match.end())
        if end is None:
            continue
        body = text[match.end():end - 1]
        plain = re.compile(r'return\s+' + re.escape(parameter) + r'\s*;')
        through = re.compile(r'return\s+(\w+\s*\(\s*' + re.escape(parameter) + r'\b[^;]*\))\s*;')
        if not plain.search(body) and not through.search(body):
            continue
        body = through.sub(lambda found: found.group(1) + '; return;', body)
        body = plain.sub('return;', body)
        body = re.sub(r'\b' + re.escape(parameter) + r'\s*->', '__ret.', body)
        body = re.sub(r'(?<![\w.>])' + re.escape(parameter) + r'\b', '(&__ret)', body)
        rest = (match.group(6) or '').lstrip(',').strip() or 'void'
        changed = text[:match.start()] + f'{linkage}{return_type} {function}({rest}) return __ret\n{{' + body + '}' + text[end:]
        definition = re.search(r'struct\s+' + re.escape(return_type) + r'\s*\{', changed)
        if definition:  # the named return value needs a default constructor, and a declared destructor puts the class in memory
            members_end = balanced_end(changed, definition.end())
            members = changed[definition.end():members_end - 1] if members_end else ''
            added = ''
            if members_end and not re.search(r'(?<![~\w])' + re.escape(return_type) + r'\s*\(\s*(void)?\s*\)', members):
                added += f' {return_type}() {{}}'
            if members_end and '~' + return_type not in members:
                added += f' ~{return_type}();'
            if members_end:
                changed = changed[:members_end - 1] + added + ' ' + changed[members_end - 1:]
        yield f'by_value {function}', changed
        return


RULES = (index_loop, index_first, constify, return_result, missing_parameter, vcall_object, global_array, call_arguments, float_position, long_long, by_value)


def edits(text):
    """{changed source: (label, 0)} of every rewrite of every rule (a rule that does not apply, or breaks on this source, adds nothing)."""
    found = {}
    for rule in RULES:
        try:
            for label, changed in rule(text):
                if changed != text and changed not in found:
                    found[changed] = (label, 0)
        except (re.error, IndexError, ValueError, RecursionError):
            continue
    return found


if __name__ == '__main__':
    source = open(sys.argv[1], encoding='utf-8').read()
    for changed, (label, _) in edits(source).items():
        print(label)
