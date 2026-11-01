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
  inline_local   a local that holds a value read once, written out at each use (retail re-reads the field where m2c named the load)
  hoist_field    a read that appears twice (`M2C_FIELD(x, T *, off)`, or `*p` of a parameter) named once as a local before its first use
  result_local   `return a || b;` as `int r = 0; if (a || b) r = 1; return r;`, and `v = c ? 1 : 0;` as `v = 0; if (c) v = 1;`
  condition_split `if (a && b) { ... }` as nested ifs, `if (a || b) { return x; }` as two ifs
  for_to_while   `for (init; cond; step) { body }` as `init; while (cond) { body step; }`
  early_return_split `if (c) { A; r = x; } else { B; r = y; } return r;` as two early returns (either arm first, the condition negated for the second form):
                 a result local shared by both arms keeps one pseudo for both, where retail gives each arm's value its own register
  scalar_buffer  `T buf[16 / sizeof(T)] __attribute__((aligned(16)));` read as `buf[0]` and passed as `buf` as `T buf;` read as `buf` and passed as `&buf`
  chained_store  two stores of the same constant a few statements apart as one chain `a = b = k;` (either order): the scheduler emits the outer store
                 early and the inner late, and the constant stays in one register
  vcall_raw      m2c's untouched `M2C_FIELD(vt, R (**)(A, B, O), 0x18C)(obj + delta, x, obj)` without its trailing `obj`
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


# ---- inline_local ----

CALL_IN_EXPRESSION = re.compile(r'\b(?!M2C_FIELD\b|M2C_BITWISE\b|sizeof\b)(\w+)\s*\(')
LOCAL_WITH_VALUE = re.compile(r'^(?P<indent>[ \t]+)(?P<type>[A-Za-z_][\w \t\*]*?[ \t\*])(?P<name>[A-Za-z_]\w*) = (?P<value>[^;{}\n]+);[ \t]*\n', re.M)
LOCAL_DECLARED = re.compile(r'^[ \t]+(?P<type>[A-Za-z_][\w \t\*]*?[ \t\*])(?P<name>[A-Za-z_]\w*);[ \t]*\n', re.M)
LOCAL_ASSIGNED = re.compile(r'^[ \t]+(?P<name>[A-Za-z_]\w*) = (?P<value>[^;{}\n]+);[ \t]*\n', re.M)
TYPE_WORDS = {'return', 'goto', 'else', 'case', 'typedef', 'extern', 'struct', 'static'}


def plain_value(value):
    """Safe to evaluate again at each use: loads and arithmetic only, no call."""
    return not CALL_IN_EXPRESSION.search(value)


def uses_of(name):
    return re.compile(rf'(?<![\w.])(?<!->)\b{re.escape(name)}\b(?!\s*\()')


def inline_local(text):
    """A local that holds a value read once (`T x = p->f;`, or m2c's `T x;` ... `x = p->f;`) written out at each use: retail often re-reads
    the field where m2c named the load, and the load then schedules and allocates differently. One local per rewrite, never one that is
    assigned again or has its address taken, never a value with a call in it."""
    candidates = []
    for match in LOCAL_WITH_VALUE.finditer(text):
        first_word = match.group('type').split()[0] if match.group('type').split() else ''
        if first_word in TYPE_WORDS or match.group('name') in TYPE_WORDS:
            continue
        candidates.append((match.group('name'), match.group('value').strip(), match.start(), match.end(), None))
    for declared in LOCAL_DECLARED.finditer(text):
        name = declared.group('name')
        assigned = [found for found in LOCAL_ASSIGNED.finditer(text) if found.group('name') == name and found.start() > declared.end()]
        if len(assigned) == 1:
            candidates.append((name, assigned[0].group('value').strip(), assigned[0].start(), assigned[0].end(), (declared.start(), declared.end())))
    produced = 0
    for name, value, start, end, declaration in candidates:
        if not plain_value(value) or re.search(rf'&\s*{re.escape(name)}\b|(?<![\w.])(?<!->){re.escape(name)}\s*(\+\+|--|[-+*/|&^]?=(?!=))', text[end:]):
            continue
        rest = text[end:]
        if not uses_of(name).search(rest):
            continue
        replacement = value if re.fullmatch(r'[\w>.\[\]\- *()]+', value) and '*' not in value.replace('->', '') and not re.search(r'[+\-]\s', value) else f'({value})'
        replaced = uses_of(name).sub(lambda _: replacement, rest)
        head = text[:start]
        if declaration:
            head = text[:declaration[0]] + text[declaration[1]:start]
        yield f'inline_local {name}', head + replaced
        produced += 1
        if produced >= 12:
            return


# ---- vcall_raw ----

RAW_VCALL = re.compile(r'M2C_FIELD\(\s*(?P<object>[^,()]+(?:\([^()]*\))?[^,()]*),\s*(?P<type>[^,]*?\(\*\*\)\s*\((?P<types>[^()]*)\)),\s*(?P<offset>0x[0-9A-Fa-f]+|\d+)\s*\)\s*\(')


def vcall_raw(text):
    """m2c's untouched virtual call `M2C_FIELD(vt, R (**)(A, B, O), 0x18C)(obj + delta, x, obj)` (the form of a draft nobody has rewritten, which
    vcall_object's `(*fn)(...)` pattern does not see): drop the trailing `obj` and its type when a0 is built from it."""
    for call in RAW_VCALL.finditer(text):
        types = split_parameters(call.group('types'))
        end = balanced_end(text, call.end(), '(', ')')
        if len(types) < 2 or end is None:
            continue
        args = split_parameters(text[call.end():end - 1])
        if len(args) != len(types) or re.sub(r'^\(\s*[\w\s\*]+\)\s*', '', args[-1]) not in args[0]:
            continue
        new_type = call.group('type').replace(call.group('types'), ', '.join(types[:-1]), 1)
        yield (f'vcall_raw {call.group("offset")}',
               text[:call.start('type')] + new_type + text[call.end('type'):call.end()] + ', '.join(args[:-1]) + text[end - 1:])


# ---- condition shapes ----

def top_level_split(expression, operator):
    """The parts of an expression at parenthesis depth 0 around `operator` (` && `), or the whole expression as one part."""
    parts, depth, start, index = [], 0, 0, 0
    while index < len(expression):
        character = expression[index]
        if character in '([':
            depth += 1
        elif character in ')]':
            depth -= 1
        elif depth == 0 and expression.startswith(operator, index):
            parts.append(expression[start:index].strip())
            index += len(operator)
            start = index
            continue
        index += 1
    parts.append(expression[start:].strip())
    return parts


RETURN_CONDITION = re.compile(r'^(?P<indent>[ \t]*)return (?P<expression>[^;{}?\n]+);[ \t]*\n', re.M)
TERNARY_FLAG = re.compile(r'^(?P<indent>[ \t]*)(?P<target>[\w>.\[\]\-]+) = (?P<condition>[^;{}?\n]+) \? 1 : 0;[ \t]*\n', re.M)
COMPARISON = re.compile(r'\|\||&&|[=!<>]=|(?<![<>-])[<>](?![<>=])')


def result_local(text):
    """`return a || b;` (or `return x < y;`) as `int result = 0; if (a || b) result = 1; return result;`, and `v = cond ? 1 : 0;` as `v = 0; if (cond) v = 1;`:
    retail's compare then folds to its own xor/sltiu/movn shape where the one-expression form does not."""
    for match in RETURN_CONDITION.finditer(text):
        expression = match.group('expression').strip()
        if not COMPARISON.search(expression) or re.search(r'\bresult_local\b', text):
            continue
        indent = match.group('indent')
        yield ('result_local return',
               text[:match.start()] + f'{indent}int result_local = 0;\n{indent}if ({expression}) result_local = 1;\n{indent}return result_local;\n' + text[match.end():])
    for match in TERNARY_FLAG.finditer(text):
        indent, target = match.group('indent'), match.group('target')
        yield (f'result_local {target}',
               text[:match.start()] + f'{indent}{target} = 0;\n{indent}if ({match.group("condition").strip()}) {target} = 1;\n' + text[match.end():])


IF_HEAD = re.compile(r'^(?P<indent>[ \t]*)if \(', re.M)


def condition_split(text):
    """`if (a && b) { body }` as `if (a) { if (b) { body } }` and `if (a || b) { return x; }` as two ifs: gcc folds the one-test form into a range
    test or a merged branch (`sltiu`, a shared `beq`) where retail has a compare and a branch each. No `else` on the statement."""
    for head in IF_HEAD.finditer(text):
        condition_end = balanced_end(text, head.end(), '(', ')')
        if condition_end is None:
            continue
        condition = text[head.end():condition_end - 1]
        rest = text[condition_end:]
        opening = re.match(r'\s*\{', rest)
        if not opening:
            continue
        body_end = balanced_end(text, condition_end + opening.end(), '{', '}')
        if body_end is None or re.match(r'\s*else\b', text[body_end:]):
            continue
        body = text[condition_end + opening.end():body_end - 1]
        indent = head.group('indent')
        parts = top_level_split(condition, ' && ')
        if len(parts) >= 2:
            inner = ' && '.join(parts[1:])
            yield ('condition_split and',
                   text[:head.start()] + f'{indent}if ({parts[0]}) {{\n{indent}    if ({inner}) {{{body}}}\n{indent}}}' + text[body_end:])
        parts = top_level_split(condition, ' || ')
        statements = [line.strip() for line in body.strip().split(';') if line.strip()]
        if len(parts) >= 2 and len(statements) == 1 and re.match(r'(return\b|goto\b)', statements[0]):
            yield ('condition_split or',
                   text[:head.start()] + '\n'.join(f'{indent}if ({part}) {{{body}}}' for part in parts) + text[body_end:])


# ---- loop forms ----

FOR_HEAD = re.compile(r'^(?P<indent>[ \t]*)for \(', re.M)


def for_to_while(text):
    """`for (init; cond; step) { body }` as `init; while (cond) { body step; }` (no `continue` in the body): the loop's test and step then sit where
    the source put them instead of where the compiler's for-loop lowering puts them."""
    for head in FOR_HEAD.finditer(text):
        header_end = balanced_end(text, head.end(), '(', ')')
        if header_end is None:
            continue
        pieces = [piece.strip() for piece in text[head.end():header_end - 1].split(';')]
        opening = re.match(r'\s*\{', text[header_end:])
        if len(pieces) != 3 or not pieces[1] or not opening:
            continue
        body_end = balanced_end(text, header_end + opening.end(), '{', '}')
        if body_end is None:
            continue
        body = text[header_end + opening.end():body_end - 1]
        if re.search(r'\bcontinue\b', body):
            continue
        indent = head.group('indent')
        initial = f'{indent}{pieces[0]};\n' if pieces[0] else ''
        step = f'{indent}    {pieces[2]};\n' if pieces[2] else ''
        yield ('for_to_while',
               text[:head.start()] + initial + f'{indent}while ({pieces[1]}) {{{body.rstrip()}\n{step}{indent}}}' + text[body_end:])


# ---- hoist_field ----

M2C_READ = re.compile(r'M2C_FIELD\(')
SIGNATURE = re.compile(r'^[^\n(]*\b(?P<name>\w+)\((?P<parameters>[^()\n]*)\)\s*\{', re.M)


def value_type(pointer_type):
    """The type an `M2C_FIELD(x, T *, off)` read yields: T without its last `*`; None for a function pointer or a non-pointer."""
    pointer_type = pointer_type.strip()
    if '(' in pointer_type or not pointer_type.endswith('*'):
        return None
    return pointer_type[:-1].strip()


def statement_start(text, index):
    return text.rfind('\n', 0, index) + 1


def hoist_field(text):
    """The opposite of inline_local: a read that appears twice or more (m2c's `M2C_FIELD(x, T *, off)`, or `*p` of a parameter `T *p`) named once as
    a local before its first use. Retail keeps the object, the vtable or the child in a callee-saved register or a spill where m2c re-reads it."""
    counts = {}
    for match in M2C_READ.finditer(text):
        end = balanced_end(text, match.end(), '(', ')')
        if end is None:
            continue
        expression = text[match.start():end]
        arguments = split_parameters(text[match.end():end - 1])
        if len(arguments) == 3 and value_type(arguments[1]) and plain_value(arguments[0].replace('M2C_FIELD(', '(')):
            counts.setdefault(expression, [value_type(arguments[1]), []])[1].append(match.start())
    produced = 0
    for expression, (kind, places) in counts.items():
        if len(places) < 2:
            continue
        first = statement_start(text, places[0])
        indent = re.match(r'[ \t]*', text[first:]).group(0)
        name = f'hoisted_{produced}'
        declaration = f'{indent}{kind} {name} = {expression};\n'
        yield (f'hoist_field read{produced}', text[:first] + declaration + text[first:].replace(expression, name))
        produced += 1
        if produced >= 6:
            return
    signature = SIGNATURE.search(text)
    if signature:
        for parameter in split_parameters(signature.group('parameters')):
            found = re.match(r'(?P<kind>[\w \t]+?[ \t]*\*+)\s*(?P<name>\w+)$', parameter)
            if not found or not found.group('kind').strip().endswith('*'):
                continue
            name, pointer_kind = found.group('name'), found.group('kind').strip()
            reads = [m for m in re.finditer(rf'(?<![\w*])\*\s*{re.escape(name)}\b(?!\s*=(?!=))', text[signature.end():])]
            if len(reads) < 2 or re.search(rf'\*\s*{re.escape(name)}\s*=(?!=)', text[signature.end():]):
                continue
            first = statement_start(text, signature.end() + reads[0].start())
            indent = re.match(r'[ \t]*', text[first:]).group(0)
            local = f'{name}_value'
            kind = pointer_kind[:-1].strip()
            replaced = re.sub(rf'(?<![\w*])\*\s*{re.escape(name)}\b(?!\s*=(?!=))', local, text[first:])
            yield (f'hoist_field *{name}', text[:first] + f'{indent}{kind} {local} = *{name};\n' + replaced)


# ---- early_return_split ----

FLIPPED_COMPARISON = {'<': '>=', '>': '<=', '<=': '>', '>=': '<', '==': '!=', '!=': '=='}
SIMPLE_COMPARISON = re.compile(r'^(?P<left>[\w.>\[\]\-]+) (?P<operator><=|>=|==|!=|<|>) (?P<right>[\w.>\[\]\-]+)$')
LAST_ASSIGNMENT = re.compile(r'(?:^|[;{}])\s*(?P<name>\w+) = (?P<value>[^;{}]+);\s*$')


def negated(condition):
    """`a < b` as `a >= b`; anything else as `!(...)`."""
    simple = SIMPLE_COMPARISON.match(condition.strip())
    if simple:
        return f"{simple.group('left')} {FLIPPED_COMPARISON[simple.group('operator')]} {simple.group('right')}"
    return f'!({condition})'


def arm_with_return(body, name, kind, indent):
    """An arm's statements with its assignment `name = value;` turned into the arm's own return: at the end `return value;`; earlier, a block-local
    `kind name = value;` kept in place and `return name;` added at the end. None when the arm has no such assignment or has nested blocks."""
    if '{' in body or '}' in body:
        return None
    assignment = re.search(rf'^[ \t]*{name} = (?P<value>[^;]+);[ \t]*$', body, re.M)
    if not assignment:
        return None
    before, after = body[:assignment.start()].rstrip(), body[assignment.end():].rstrip()
    value = assignment.group('value').strip()
    if not after.strip():
        return f'{before}\n{indent}    return {value};'
    if not kind:
        return None
    return f'{before}\n{indent}    {kind} {name} = {value};{after}\n{indent}    return {name};'


def early_return_split(text):
    """`if (c) { A; r = x; B; } else { C; r = y; D; } return r;` as `if (c) { A; T r = x; B; return r; } C; T r = y; D; return r;` and as the second arm
    first under the negated condition: each arm's value then has its own block-local register instead of one pseudo shared by both arms, which is
    how the stream reads (U16/S16/U32/S32) match. The assignment may be anywhere in an arm."""
    for head in IF_HEAD.finditer(text):
        condition_end = balanced_end(text, head.end(), '(', ')')
        if condition_end is None:
            continue
        condition = text[head.end():condition_end - 1]
        opening = re.match(r'\s*\{', text[condition_end:])
        if not opening:
            continue
        then_start = condition_end + opening.end()
        then_end = balanced_end(text, then_start, '{', '}')
        if then_end is None:
            continue
        otherwise = re.match(r'\s*else\s*\{', text[then_end:])
        if not otherwise:
            continue
        else_start = then_end + otherwise.end()
        else_end = balanced_end(text, else_start, '{', '}')
        if else_end is None:
            continue
        returned = re.match(r'\s*return (\w+);', text[else_end:])
        if not returned:
            continue
        name = returned.group(1)
        declaration = None
        for declaration in re.finditer(rf'^[ \t]*(?P<kind>[A-Za-z_][\w ]*?[\w*])\s+{name};[ \t]*$', text[:head.start()], re.M):
            pass
        kind = declaration.group('kind').strip() if declaration else ''
        indent = head.group('indent')
        then_arm = arm_with_return(text[then_start:then_end - 1], name, kind, indent)
        else_arm = arm_with_return(text[else_start:else_end - 1], name, kind, indent)
        if then_arm is None or else_arm is None:
            continue
        tail = text[else_end + returned.end():]
        front = text[:head.start()]
        if declaration:  # the shared local is gone: each arm declares its own
            front = front[:declaration.start()] + front[declaration.end() + 1:]
        yield ('early_return_split then-first',
               front + f'{indent}if ({condition}) {{{then_arm}\n{indent}}}{else_arm.replace(chr(10) + indent + "    ", chr(10) + indent)}' + tail)
        yield ('early_return_split else-first',
               front + f'{indent}if ({negated(condition)}) {{{else_arm}\n{indent}}}{then_arm.replace(chr(10) + indent + "    ", chr(10) + indent)}' + tail)


# ---- scalar_buffer ----

BUFFER_DECLARATION = re.compile(r'^(?P<indent>[ \t]*)(?P<kind>[A-Za-z_][\w ]*?)\s+(?P<name>\w+)\[(?P<size>[^\]\n]*)\](?:\s*__attribute__\(\(aligned\(\d+\)\)\))?;[ \t]*\n', re.M)


def scalar_buffer(text):
    """A one-element buffer (`T buf[16 / sizeof(T)] __attribute__((aligned(16)));`, `T buf[1];`) as a plain `T buf;`: `buf[0]` becomes `buf`
    and a bare `buf` (an argument) becomes `&buf`. Retail's frame slot is the scalar's; the aligned array changes where the slot goes."""
    for match in BUFFER_DECLARATION.finditer(text):
        size = match.group('size').strip()
        if size != '1' and 'sizeof' not in size:
            continue
        name, kind = match.group('name'), match.group('kind').strip()
        rest = text[match.end():]
        marker = '\x01'  # stands for `name[0]` while the bare names are rewritten
        rest = re.sub(rf'\b{name}\[0\]', marker, rest)
        rest = re.sub(rf'(?<![\w&.>]){name}\b(?!\s*\[)', f'&{name}', rest)
        rest = rest.replace(marker, name)
        yield (f'scalar_buffer {name}', text[:match.start()] + f"{match.group('indent')}{kind} {name};\n" + rest)


# ---- chained_store ----

PLAIN_STORE = re.compile(r'^(?P<indent>[ \t]*)(?P<target>[^=;(){}\n]+?[^=;(){}\s]) = (?P<value>-?[\w.]+f?);[ \t]*$')


def chained_store(text):
    """Two stores of one constant or name, up to three statements apart, as `a = b = k;` at the first one's place (either order) or the second's."""
    lines = text.split('\n')
    stores = [(index, PLAIN_STORE.match(line)) for index, line in enumerate(lines)]
    stores = [(index, found) for index, found in stores if found and '==' not in lines[index]]
    for position, (first, first_match) in enumerate(stores):
        for second, second_match in stores[position + 1:]:
            if second - first > 3:
                break
            if second_match.group('value') != first_match.group('value') or second_match.group('target') == first_match.group('target'):
                continue
            indent = first_match.group('indent')
            targets = (first_match.group('target'), second_match.group('target'))
            for order, (outer, inner) in (('a', targets), ('b', targets[::-1])):
                chained = f"{indent}{outer} = {inner} = {first_match.group('value')};"
                for place in (first, second):
                    changed = list(lines)
                    changed[place] = chained
                    del changed[second if place == first else first]
                    yield (f'chained_store {order}{"1" if place == first else "2"}', '\n'.join(changed))


RULES = (index_loop, index_first, constify, return_result, missing_parameter, vcall_object, global_array, call_arguments, float_position, long_long, by_value,
         inline_local, vcall_raw, hoist_field, result_local, condition_split, for_to_while, early_return_split, scalar_buffer, chained_store)


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
