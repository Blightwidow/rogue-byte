#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""search_guard.py - what the search tools share: the functions they leave alone, and the findings a rewrite must not add.

  from search_guard import skipped, new_findings, accept

  skipped(address)          why a function is left out of a search (a wall, a boundary suspect), or None
  new_findings(old, new)    [(kind, message)] that a rewritten source has and the source it came from does not
  accept(old, new)          True when a rewrite adds nothing: no new banned construct, cleanup problem or review warning

Why: a search scores sources, and a lower score reached with a padding local, an inline asm statement or a literal given its own name is not a result
(AGENTS.md "Matching rules"). `adopt.py` checked that; `neighborhood.py`, `mutate.py` and `callee_sigs.py` wrote straight into data/matching/src/fn
without it. A rewrite is compared with the source it came from, so a finding the current source already has (a draft that has a warning today) does
not block an improvement; only a finding the rewrite adds does.

The skip list has two sources:
  * config/matching/walls.tsv: functions whose remaining difference was traced to the toolchain and no plain-C form reached it (a store in a delay
    slot whose address is in a register, a $gp save) or that hold a scheduling tie found in the RTL dumps after a long manual search. Searching them
    only spends the budget. SEARCH_INCLUDE_WALLS=1 searches them anyway.
  * work/matching/boundary_suspects.tsv (boundary_suspects.py): functions whose score is probably a split artifact, not a code difference."""
import csv
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
LAB = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
import check_source  # noqa: E402

WALLS = os.path.join(LAB, 'config', 'matching', 'walls.tsv')
SUSPECTS = os.path.join(LAB, 'work', 'matching', 'boundary_suspects.tsv')


def table(path, reason_column):
    """{address: reason} of a tab-separated skip list (the `address` column and the named reason column); an absent file is an empty list."""
    if not os.path.exists(path):
        return {}
    with open(path, encoding='utf-8') as handle:
        return {int(row['address'], 16): row[reason_column] for row in csv.DictReader(handle, delimiter='\t') if row.get('address')}


def skipped(address):
    """The reason a function is left out of a search, or None. `address` is an int or a hex string."""
    address = int(address, 16) if isinstance(address, str) else address
    if not os.environ.get('SEARCH_INCLUDE_WALLS'):
        reason = table(WALLS, 'reason').get(address)
        if reason:
            return f'wall: {reason}'
    reason = table(SUSPECTS, 'reason').get(address)
    return f'boundary suspect: {reason}' if reason else None


def findings(text):
    """{(kind, message)} of a source: its banned constructs, cleanup problems and review warnings (line numbers left out: a move must not look new)."""
    return {(kind, message) for _, kind, message in check_source.problems(text) + check_source.review(text)}


def new_findings(old, new):
    """[(kind, message)] that `new` has and `old` does not."""
    return sorted(findings(new) - findings(old or ''))


def accept(old, new):
    """True when a rewrite of `old` into `new` adds no finding."""
    return not new_findings(old, new)


def guarded_write(path, text):
    """Write `text` over the source at `path` unless it adds a finding; prints why it did not. Returns whether it wrote."""
    current = ''
    if os.path.exists(path):
        with open(path, encoding='utf-8') as handle:
            current = handle.read()
    added = new_findings(current, text)
    if added:
        print(f'not written: {os.path.basename(path)}: ' + '; '.join(f'{kind}: {message}' for kind, message in added[:3]), file=sys.stderr, flush=True)
        return False
    with open(path, 'w', encoding='utf-8') as handle:
        handle.write(text)
    return True
