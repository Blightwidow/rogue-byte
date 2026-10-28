#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""progress_comment.py <base summary.json> <head summary.json> [--number N] [--output DIR]: the pull request comment that compares the
progress data (site/data/summary.json, written locally by `make progress`) a change commits with the one on the base branch. Prints the
Markdown; with --output it also writes DIR/comment.md and DIR/number for progress-comment.yml. Exit 1 when the head file is not valid."""
import argparse
import json
import os
import sys

MARKER = '<!-- rogue-byte-progress -->'

def percent(part, whole):
    return f'{100 * part / whole:.2f}%' if whole else '0.00%'

def delta(before, after, suffix=''):
    difference = after - before
    return f'{after:,}{suffix} ({difference:+,}{suffix})' if difference else f'{after:,}{suffix}'

def validate(summary):
    """The problems that make a summary unusable for the site and the comparison."""
    game = summary.get('game_code')
    if not isinstance(game, dict):
        return ['no game_code section']
    return [f'game_code.{key} is missing or not a number' for key in ('functions', 'bytes', 'named', 'c_functions', 'c_bytes') if not isinstance(game.get(key), int)]

def render(base, head):
    before, after = base['game_code'], head['game_code']
    rows = [
        ('Compiled from C (bytes)', percent(before['c_bytes'], before['bytes']), percent(after['c_bytes'], after['bytes'])),
        ('Functions from C', f"{before['c_functions']:,}", delta(before['c_functions'], after['c_functions'])),
        ('Functions named', f"{before['named']:,}", delta(before['named'], after['named'])),
    ]
    lines = [MARKER, '### Progress', '', '| | main | this change |', '| :-- | --: | --: |'] + [f'| {name} | {old} | {new} |' for name, old, new in rows]
    lines += ['', 'From the committed `site/data/summary.json`; `make progress` regenerates it after `make elf`.']
    return '\n'.join(lines) + '\n'

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('base')
    parser.add_argument('head')
    parser.add_argument('--number', default='')
    parser.add_argument('--output')
    arguments = parser.parse_args()
    head = json.load(open(arguments.head))
    problems = validate(head)
    if problems:
        print('\n'.join(f'{arguments.head}: {problem}' for problem in problems))
        sys.exit(1)
    try:
        base = json.load(open(arguments.base))
        problems = validate(base)
    except (OSError, ValueError):
        problems = ['unreadable']
    comment = render(head if problems else base, head)
    print(comment)
    if arguments.output:
        os.makedirs(arguments.output, exist_ok=True)
        open(os.path.join(arguments.output, 'comment.md'), 'w').write(comment)
        open(os.path.join(arguments.output, 'number'), 'w').write(str(arguments.number))

if __name__ == '__main__':
    main()
