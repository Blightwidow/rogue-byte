#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""check_source.py FILE... : everything AGENTS.md and docs/contributing/code-cleanup.md ask of a matched source, checked on a file before it is
a match: the constructs AGENTS.md bans (inline asm, register pins, `volatile` on ordinary data: record.py `scan`), the cleanup rules
(raw `M2C_UNK`/`M2C_FIELD` offsets, `/* Error` comments, m2c temporary names, tabs, trailing whitespace: check_cleanup.py `LINE_RULES`)
and a padding local (a variable named scratch, junk, dummy, unused or spill declared in a function, not in a struct, that nothing uses).

Prints `file:line: kind: what` for every hit and `ok: FILE` for a clean one; exit 1 when any file has a hit. A worker runs it before
it says EXACT, and record.py runs the same checks before it registers a match, so no rule is first met after a landing.
`kind` is `banned` (the source can never match as written: it goes to data/matching/asm-archive) or `cleanup` (it can match once the
code is rewritten: it goes to data/matching/cleanup-pending). It is a heuristic for the padding local: read the hit."""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, '..'))
import check_cleanup  # noqa: E402
import record  # noqa: E402

PADDING_NAME = re.compile(r'\b(?:scratch|junk|dummy|unused|spill)\w*\s*(?:\[|;|=)')
SCALAR_TYPES = re.compile(r'\s*(?:(?:unsigned|signed|const|volatile)\s+)*(?:int|char|short|long|float|double|bool|[su](?:8|16|32|64)|f(?:32|64))\b')
TYPE_HEAD = re.compile(r'\b(?:struct|union|class|enum)\b')
LINKAGE = re.compile(r'extern\s*"C(?:\+\+)?"\s*$')


def strip_comments(text):
    """The text with comments blanked, keeping every newline so line numbers stay right."""
    text = re.sub(r'/\*.*?\*/', lambda match: re.sub(r'[^\n]', ' ', match.group(0)), text, flags=re.DOTALL)
    return re.sub(r'//[^\n]*', '', text)


DECLARATION = re.compile(r'\s*(?:(?:unsigned|signed|const|static|struct)\s+)*\w[\w:<>*&\s]*?\s+\**(\w+)\s*(?:\[|;|=)')


def padding_locals(text):
    """[(line number, line)] of locals inside a function body that nothing uses (not in a struct, union or class): a declaration whose name
    appears nowhere else, or only in a `(void)name;` cast, is a frame filler when its name says so (scratch, junk, dummy, unused, spill) or
    when it is an array or a scalar, whatever its name (`int dead[2];`, `int reserved[2]; (void)reserved;`). A local of a named struct type that
    nothing uses is allowed: AGENTS.md accepts an unused local only as a type the original plausibly declared, which retail's frame shows."""
    clean = strip_comments(text)
    found, stack, head = [], [], ''
    for number, line in enumerate(clean.split('\n'), 1):
        if line.lstrip().startswith('#'):  # a preprocessor line is not part of the next declaration's head
            continue
        match = DECLARATION.match(line)
        if stack and stack[-1] == 'block' and match and '(' not in line.split('=', 1)[-1] and (PADDING_NAME.search(line) or '[' in line or SCALAR_TYPES.match(line)):
            name = match.group(1)
            uses = len(re.findall(r'\b%s\b' % re.escape(name), clean)) - len(re.findall(r'\(void\)\s*%s\b' % re.escape(name), clean))
            if uses <= 1:
                found.append((number, line.strip()[:100]))
        for character in line:
            if character == '{':
                stack.append('linkage' if LINKAGE.search(head) else 'type' if TYPE_HEAD.search(head) and '(' not in head else 'block')
                head = ''
            elif character == '}':
                if stack:
                    stack.pop()
                head = ''
            elif character == ';':
                head = ''
            else:
                head += character
        head += ' '
    return found


def problems(text):
    """[(line number, kind, message)] of everything wrong with a source; kind is `banned` or `cleanup`."""
    found = [(number, 'banned', what) for number, what, _ in record.scan(text)]
    for number, line in enumerate(text.split('\n'), 1):
        for pattern, message in check_cleanup.LINE_RULES:
            if pattern.search(line):
                found.append((number, 'cleanup', message.split(':')[0]))
    found += [(number, 'cleanup', f'padding local: {line}') for number, line in padding_locals(text)]
    return sorted(found)


def destination(found):
    """The folder under data/matching a source with these problems is parked in: asm-archive when anything is banned, else cleanup-pending."""
    return 'asm-archive' if any(kind == 'banned' for _, kind, _ in found) else 'cleanup-pending'


LITERAL_LOCAL = re.compile(r'^\s+(?:(?:unsigned|signed|const)\s+)*(?:int|char|short|long|float|double|[su](?:8|16|32|64)|f(?:32|64))\s+(\w+)\s*=\s*'
                           r'(-?(?:0[xX][0-9a-fA-F]+|\d+(?:\.\d*)?f?))\s*;')
CONSTANT_CONDITION = re.compile(r'\|\|\s*(?:1|true)\s*[)|&]|&&\s*(?:0|false)\s*[)|&]')


def literal_locals(text):
    """[(line number, line)] of locals set from a number once and never changed (no assignment, increment or address taken) that are used at least twice:
    a literal given its own name so that each use takes a register of its own. AGENTS.md allows a typed local bound to a value the code reads and then
    uses, not one that only holds a literal for a store or a compare to use (ClineWrap's `int newline = 10;`). A heuristic: a loop bound or a real
    named constant looks the same, so this is a warning, never a ban."""
    clean = strip_comments(text)
    found, stack, head = [], [], ''
    for number, line in enumerate(clean.split('\n'), 1):
        match = LITERAL_LOCAL.match(line)
        if stack and stack[-1] == 'block' and match:
            name = match.group(1)
            uses = len(re.findall(r'\b%s\b' % re.escape(name), clean)) - 1
            changed = re.search(r'\b%s\s*(?:[-+*/|&^]=|=(?!=)|\+\+|--)|(?:\+\+|--)\s*%s\b|&\s*%s\b' % ((re.escape(name),) * 3), clean.replace(line, '', 1))
            if uses >= 2 and not changed:
                found.append((number, line.strip()[:100]))
        for character in line:
            if character == '{':
                stack.append('linkage' if LINKAGE.search(head) else 'type' if TYPE_HEAD.search(head) and '(' not in head else 'block')
                head = ''
            elif character == '}':
                if stack:
                    stack.pop()
                head = ''
            elif character == ';':
                head = ''
            else:
                head += character
        head += ' '
    return found


def review(text):
    """[(line number, 'review', message)]: what the rules do not ban but a person should read before a rewrite is adopted (a literal-holding local, a
    constant-true condition). Kept apart from `problems`: record.py parks a source that has a problem, and these are warnings. A lint for a callee
    declared with an argument it does not have was tried (callee_sigs `params` against the declaration) and dropped: it fired on 19% of the matched
    sources, because a callee may ignore an argument its callers still pass. That check needs retail's call sites, not the callee's code."""
    found = [(number, 'review', f'literal local: {line}') for number, line in literal_locals(text)]
    for number, line in enumerate(strip_comments(text).split('\n'), 1):
        if CONSTANT_CONDITION.search(line):
            found.append((number, 'review', f'constant condition: {line.strip()[:100]}'))
    return sorted(found)


def main():
    paths = [argument for argument in sys.argv[1:] if not argument.startswith('-')]
    if not paths:
        sys.exit('usage: check_source.py [--review] FILE...   (--review also prints the warnings of `review`; they never fail the check)')
    failed = False
    for path in paths:
        with open(path, encoding='utf-8') as handle:
            text = handle.read()
        found = problems(text)
        if '--review' in sys.argv:
            for number, kind, message in review(text):
                print(f'{path}:{number}: {kind}: {message}')
        if found:
            failed = True
            for number, kind, message in found:
                print(f'{path}:{number}: {kind}: {message}')
        else:
            print(f'ok: {path}')
    return 1 if failed else 0


if __name__ == '__main__':
    sys.exit(main())
