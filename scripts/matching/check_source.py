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
TYPE_HEAD = re.compile(r'\b(?:struct|union|class|enum)\b')


def strip_comments(text):
    """The text with comments blanked, keeping every newline so line numbers stay right."""
    text = re.sub(r'/\*.*?\*/', lambda match: re.sub(r'[^\n]', ' ', match.group(0)), text, flags=re.DOTALL)
    return re.sub(r'//[^\n]*', '', text)


DECLARATION = re.compile(r'\s*(?:(?:unsigned|signed|const|static|struct)\s+)*\w[\w:<>*&\s]*?\s+\**(\w+)\s*(?:\[|;|=)')


def padding_locals(text):
    """[(line number, line)] of locals named scratch/junk/dummy/unused/spill inside a function body that nothing uses (not in a struct, union
    or class): a declaration whose name appears nowhere else, or only in a `(void)name;` cast, is a frame filler."""
    clean = strip_comments(text)
    found, stack, head = [], [], ''
    for number, line in enumerate(clean.split('\n'), 1):
        match = DECLARATION.match(line)
        if 'block' in stack and match and PADDING_NAME.search(line):
            name = match.group(1)
            uses = len(re.findall(r'\b%s\b' % re.escape(name), clean)) - len(re.findall(r'\(void\)\s*%s\b' % re.escape(name), clean))
            if uses <= 1:
                found.append((number, line.strip()[:100]))
        for character in line:
            if character == '{':
                stack.append('type' if TYPE_HEAD.search(head) and '(' not in head else 'block')
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


def main():
    paths = [argument for argument in sys.argv[1:] if not argument.startswith('-')]
    if not paths:
        sys.exit('usage: check_source.py FILE...')
    failed = False
    for path in paths:
        with open(path, encoding='utf-8') as handle:
            found = problems(handle.read())
        if found:
            failed = True
            for number, kind, message in found:
                print(f'{path}:{number}: {kind}: {message}')
        else:
            print(f'ok: {path}')
    return 1 if failed else 0


if __name__ == '__main__':
    sys.exit(main())
