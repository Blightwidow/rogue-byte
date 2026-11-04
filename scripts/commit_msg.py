#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""commit_msg.py <message file> | --range <base>..<head> | --title <text>: checks commit messages against
docs/contributing/commit-messages.md: Conventional Commits `<type>(<scope>): <summary>`, lowercase type from the list, optional
lowercase scope, no trailing period, at most 120 characters, body lines wrapped at 72 columns (a URL line is exempt), no AI
attribution trailers. As a commit-msg hook it gets the message file; in CI it gets the commits of a pull request.
Exit 1 when one is wrong."""
import argparse
import re
import subprocess
import sys

TYPES = ('feat', 'fix', 'docs', 'refactor', 'perf', 'test', 'build', 'ci', 'chore', 'style', 'revert')
MAXIMUM_LENGTH = 120
BODY_WIDTH = 72
ATTRIBUTION = re.compile(r'^(co-authored-by|generated-by|assisted-by):', re.IGNORECASE)

def check(message, check_body=True):
    """The problems of one commit message (its first line is the subject), empty when it is fine."""
    lines = message.strip().split('\n')
    subject = lines[0].strip()
    if not subject or subject.startswith(('Merge ', 'Revert "', 'fixup! ', 'squash! ')):
        return []
    match = re.match(r'^([a-z]+)(?:\(([a-z0-9/_.-]+)\))?!?: (\S.*)$', subject)
    if match is None:
        return [f'"{subject}" is not `<type>(<scope>): <summary>` with a lowercase type and scope']
    problems = []
    if match.group(1) not in TYPES:
        problems.append(f'type "{match.group(1)}" is not one of {", ".join(TYPES)}')
    if subject.endswith('.'):
        problems.append('the subject ends with a period')
    if len(subject) > MAXIMUM_LENGTH:
        problems.append(f'the subject is {len(subject)} characters, the limit is {MAXIMUM_LENGTH}')
    if check_body:
        for line in lines[1:]:
            if ATTRIBUTION.match(line.strip()):
                problems.append(f'attribution trailer "{line.strip()}": no attribution lines for AI tools')
            elif len(line) > BODY_WIDTH and ' ' in line.strip() and 'http' not in line:
                problems.append(f'body line of {len(line)} characters, wrap at {BODY_WIDTH}: "{line[:40]}..."')
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
        messages = [('commit', open(arguments.message_file, encoding='utf-8').read())]
    else:
        parser.error('give a message file, --range or --title')
    failed = False
    for label, message in messages:
        for problem in check(message, check_body=label != 'title'):
            print(f'{label}: {problem}')
            failed = True
    sys.exit(1 if failed else 0)

if __name__ == '__main__':
    main()
