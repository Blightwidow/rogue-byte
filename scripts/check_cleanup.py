#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""check_cleanup.py --base <ref>: the rules of docs/contributing/code-cleanup.md on what a change adds (the lines it adds to src/ and
include/, and the files it adds anywhere), so older problems on main do not fail a new pull request. Exit 1 when a rule is broken."""
import argparse
import re
import subprocess
import sys

CODE = re.compile(r'^(src|include)/.+\.(c|cpp|h)$')
FORBIDDEN_FILES = re.compile(r'(^|/)(SCUS_\d+\.\d+|.*\.(elf|iso|bin|irx|o|s|ee|vu|gpr))$|^(work|build)/|^tools/(?!README\.md$)')
LINE_RULES = (
    (re.compile(r'M2C_(UNK|FIELD)\b'), 'M2C_UNK / M2C_FIELD: write the struct field (include/sly2.h) instead of the raw offset'),
    (re.compile(r'/\* Error'), 'a `/* Error` comment from m2c: resolve it'),
    (re.compile(r'\b(unk_[0-9A-Fa-f]+|phi_[a-z0-9_]+|saved_reg_\w+)\b'), 'an m2c temporary name (unk_, phi_, saved_reg_): name it'),
    (re.compile(r'[ \t]+$'), 'trailing whitespace'),
    (re.compile(r'\t'), 'a tab: use four spaces'),
)

def parse_diff(text):
    """{path: [(line number, added line)]} of a `git diff -U0`."""
    added, path, number = {}, None, 0
    for line in text.split('\n'):
        if line.startswith('+++ '):
            path = line[6:] if line.startswith('+++ b/') else None
        elif line.startswith('@@'):
            number = int(re.search(r'\+(\d+)', line).group(1)) - 1
        elif path and line.startswith('+'):
            number += 1
            added.setdefault(path, []).append((number, line[1:]))
    return added

def check_lines(added):
    """Problems (path:line: rule) in the added lines of code files."""
    return [f'{path}:{number}: {message}' for path, lines in sorted(added.items()) if CODE.match(path)
            for number, text in lines for pattern, message in LINE_RULES if pattern.search(text)]

def check_files(paths):
    """Problems for added files that could be game data or build output."""
    return [f'{path}: game data or build output must not be committed (see .gitignore)' for path in paths if FORBIDDEN_FILES.search(path)]

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--base', required=True)
    arguments = parser.parse_args()
    diff = subprocess.check_output(['git', 'diff', '-U0', '--diff-filter=AM', arguments.base, 'HEAD'], text=True)
    new_files = subprocess.check_output(['git', 'diff', '--name-only', '--diff-filter=A', arguments.base, 'HEAD'], text=True).split()
    problems = check_lines(parse_diff(diff)) + check_files(new_files)
    print('\n'.join(problems) if problems else 'cleanup rules: ok')
    sys.exit(1 if problems else 0)

if __name__ == '__main__':
    main()
