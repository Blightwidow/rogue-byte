#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""commit_msg.py <message file> | --range <base>..<head> | --title <text>: checks commit messages against
docs/contributing/commit-messages.md: `<type>: <summary>`, lowercase type from the list, no trailing period, at most 120 characters.
As a commit-msg hook it gets the message file; in CI it gets the commits of a pull request. Exit 1 when one is wrong."""
import argparse
import re
import subprocess
import sys

TYPES = ('names', 'decomp', 'build', 'ci', 'docs', 'chore', 'fix')
MAXIMUM_LENGTH = 120

def check(message):
    """The problems of one commit message (its first line is the subject), empty when it is fine."""
    subject = message.strip().split('\n', 1)[0].strip()
    if not subject or subject.startswith(('Merge ', 'Revert "', 'fixup! ', 'squash! ')):
        return []
    match = re.match(r'^([A-Za-z]+): (\S.*)$', subject)
    if match is None:
        return [f'"{subject}" is not `<type>: <summary>`']
    problems = []
    if match.group(1) not in TYPES:
        problems.append(f'type "{match.group(1)}" is not one of {", ".join(TYPES)}')
    if subject.endswith('.'):
        problems.append('the subject ends with a period')
    if len(subject) > MAXIMUM_LENGTH:
        problems.append(f'the subject is {len(subject)} characters, the limit is {MAXIMUM_LENGTH}')
    return problems

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('message_file', nargs='?')
    parser.add_argument('--range')
    parser.add_argument('--title')
    arguments = parser.parse_args()
    if arguments.range:
        log = subprocess.check_output(['git', 'log', '--no-merges', '--format=%H%x00%B%x01', arguments.range], text=True)
        messages = [(entry.split('\0', 1)[0].strip()[:10], entry.split('\0', 1)[1]) for entry in log.split('\x01') if entry.strip()]
    elif arguments.title:
        messages = [('title', arguments.title)]
    elif arguments.message_file:
        messages = [('commit', open(arguments.message_file).read())]
    else:
        parser.error('give a message file, --range or --title')
    failed = False
    for label, message in messages:
        for problem in check(message):
            print(f'{label}: {problem}')
            failed = True
    sys.exit(1 if failed else 0)

if __name__ == '__main__':
    main()
