#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""record.py [--jobs N] [--dry-run] [--no-scan] [--only ADDRESS...] - judges every source in data/matching/src/fn and records it in the registry.

  python3 scripts/matching/record.py       (from the repository root; `make land` runs it first)

Each data/matching/src/fn/<ADDRESS>.cpp (or .c, judged as C) is judged by scripts/matching/try.py, which picks the assembler by
address (config/us). The registry row (data/matching/functions.tsv) gets status `matched` with the source at score 0, else `tried` with
the best score so far and one more try (a near miss that holds a banned construct, see below, does not lower the best score; a match is scanned
afterwards). A function of the SDK range (status `library`) is registered the same way. A new match inside a whole file
(config/us/whole_files.tsv) is landed there (scripts/build/make_whole_files.py land(): its INCLUDE_ASM line becomes its source and the
whole range is proved against retail); only then is it registered as matched, else it stays `tried` with best 0 and the file is unchanged.

A new match is scanned for what AGENTS.md bans: `volatile` on ordinary data (a pointer to a hardware register, an address from
0x10000000 up, is allowed; so is a line marked `// volatile-ok: <reason>` for a register-block pointer or interrupt-shared data), `register` pins, and inline asm in a function (only the shared `sqrt.s` helper is allowed).
A source that scores 0 but breaks a rule (scripts/matching/check_source.py: the scan above, the cleanup rules, a padding local) is not
registered: it is parked (scripts/matching/park.py) in data/matching/asm-archive or cleanup-pending and the run lists it (`--no-scan` skips
the check). Prints the totals and the
functions that matched this time. `--only` judges just those addresses (hex, as `claim.py land` prints them) and leaves the rest of the
registry and the try counter alone: a wave lands in seconds, a toolchain change still needs the full run."""
import argparse
import concurrent.futures
import csv
import glob
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'build'))
from progress import Progress  # noqa: E402
import make_whole_files  # noqa: E402
import check_source  # noqa: E402
import park  # noqa: E402

REGISTRY = 'data/matching/functions.tsv'
STAMP = 'work/matching/last_record'  # sources older than the last record were counted already
SOURCES = 'data/matching/src/fn'

HARDWARE_ADDRESS = re.compile(r'0x1[0-9A-Fa-f]{7}\b')
# `// volatile-ok: <reason>` on the line of a `volatile`: sly1-decomp's other allowed cases, a pointer to a register block (a DMA channel's) and
# data shared with an interrupt handler or another thread where retail reads and writes it as volatile. The reason names the register block or
# the handler (and its address), so every use can be audited; a bare marker with no reason does not count.
VOLATILE_OK = re.compile(r'volatile-ok:\s*\S')
BANNED = [
    ('volatile', re.compile(r'(?<!asm )(?<!asm\t)\bvolatile\b')),  # not the `asm volatile` of a statement: the inline asm check covers those
    ('register pin', re.compile(r'\bregister\b[^;]*\basm\b|\basm\s*\(\s*"\$')),
]
# An inline asm statement: `asm` where a statement starts. An asm label on a declaration (`CRef(const CRef &) asm("Name");`) is a rename, not code.
BARE_DO_WHILE_ZERO = re.compile(r'\bwhile\s*\(\s*0\s*\)')  # AGENTS.md: `do { } while (0)` only as the body of a C macro
ASM_STATEMENT = re.compile(r'(?:^|[;{}])\s*(?:__)?asm(?:__)?\b(?:\s+volatile\b)?\s*\(', re.MULTILINE)


def scan(text):
    """[(line number, what, line)] of the constructs AGENTS.md bans in a source: `volatile` on ordinary data, register pins, inline asm
    (the one shared `sqrt.s` helper is the only asm allowed), and `do { } while (0)` outside the body of a C macro."""
    found = []
    lines = text.split('\n')
    for number, line in enumerate(lines, 1):
        code, _, comment = line.partition('//')
        for what, pattern in BANNED:
            if what == 'volatile' and (HARDWARE_ADDRESS.search(code) or VOLATILE_OK.search(comment)):
                continue
            if pattern.search(code):
                found.append((number, what, line.strip()[:100]))
    for number, line in enumerate(lines, 1):
        code_line = line.split('//')[0].rstrip()
        in_macro = code_line.lstrip().startswith('#') or code_line.endswith('\\') or (number > 1 and lines[number - 2].split('//')[0].rstrip().endswith('\\'))
        if BARE_DO_WHILE_ZERO.search(code_line) and not in_macro:
            found.append((number, 'do-while(0) outside a macro', line.strip()[:100]))
    code = '\n'.join(line.split('//')[0] for line in lines)
    for match in ASM_STATEMENT.finditer(code):
        if 'sqrt.s' not in code[match.start():match.start() + 200]:
            number = code.count('\n', 0, match.end()) + 1
            found.append((number, 'inline asm', lines[number - 1].strip()[:100]))
    return found


TRACKER = []  # the Progress of main(), for the worker threads


def judge(path):
    address = os.path.splitext(os.path.basename(path))[0]
    tracker = TRACKER[0] if TRACKER else None
    if tracker:
        tracker.begin(address)
    result = subprocess.run([sys.executable, 'scripts/matching/try.py', address, path, '--quiet'], capture_output=True, text=True)
    first = (result.stdout.strip().splitlines() or [''])[-1]
    score = int(first.split()[1]) if first.startswith('score ') else None
    if tracker:
        tracker.tick(f'{address}: {score}', address)
    return int(address, 16), score, path


def only_sources(sources, addresses):
    """The sources whose file name (a hex address) is one of `addresses` (hex strings, any case, with or without 0x)."""
    wanted = {int(address, 16) for address in addresses}
    return [path for path in sources if int(os.path.splitext(os.path.basename(path))[0], 16) in wanted]


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--jobs', type=int, default=8)
    parser.add_argument('--only', nargs='+', metavar='ADDRESS', help='judge only these addresses')
    parser.add_argument('--dry-run', action='store_true', help='judge and report, change nothing')
    parser.add_argument('--no-scan', action='store_true', help='do not scan the new matches for banned constructs')
    arguments = parser.parse_args()
    rows = list(csv.DictReader(open(REGISTRY, encoding='utf-8'), delimiter='\t'))
    by_address = {int(row['address'], 16): row for row in rows}
    sources = sorted(glob.glob(f'{SOURCES}/*.cpp') + glob.glob(f'{SOURCES}/*.c'))
    if arguments.only:
        sources = only_sources(sources, arguments.only)
    progress = Progress(len(sources), 'record')
    TRACKER.append(progress)
    with concurrent.futures.ThreadPoolExecutor(arguments.jobs) as pool:
        results = list(pool.map(judge, sources))
    progress.done()
    new_matches, tried, parked, unlanded = [], 0, [], []
    since = os.path.getmtime(STAMP) if os.path.exists(STAMP) else 0
    for address, score, path in results:
        row = by_address.get(address)
        if not row or row['status'] in ('matched', 'fragment'):  # a fragment (words between two functions, set by hand) stays one
            continue
        if os.path.getmtime(path) > since:
            row['tries'] = str(int(row['tries'] or 0) + 1)
        if score is not None and (row['best'] == '' or score < int(row['best'])) and (score == 0 or not scan(open(path, encoding='utf-8').read())):
            row['best'] = str(score)  # a near miss that leans on a banned construct does not lower `best` (export_nonmatching.py sets it from the honest source)
        if score == 0:
            found = [] if arguments.no_scan else check_source.problems(open(path, encoding='utf-8').read())
            if found:  # a source that scores 0 but breaks a rule is not a match: park it (check_source.py says why), so no later step meets it
                row['source'] = path
                reason = 'asm' if check_source.destination(found) == 'asm-archive' else 'cleanup'
                parked.append((row['address'], row['name'], reason, found[0], path))
                if not arguments.dry_run:
                    park.park(row, reason)
                else:
                    row['source'] = ''
                row['status'] = 'tried'
                tried += 1
                continue
            if make_whole_files.whole_file_of(address) is not None:  # its whole file is its record: it lands there or stays unmatched
                if make_whole_files.already_landed(address, row['name']):  # landed by hand (make_whole_files.py --land): make elf proves it
                    landed, message = True, f'{row["name"]} is in its whole file already (no INCLUDE_ASM left): registered'
                else:
                    landed, message, _ = make_whole_files.land(address, path, write=not arguments.dry_run)
                print(message if landed else f'not landed: {message}')
                if not landed:
                    row['source'], row['status'] = path, 'tried'
                    unlanded.append(row['address'])
                    tried += 1
                    continue
            row['status'], row['source'] = 'matched', path
            new_matches.append(row)
        else:
            row['status'] = 'tried'
            tried += 1
    for note in ([] if arguments.only else glob.glob('data/matching/notes/*.md')):
        row = by_address.get(int(os.path.splitext(os.path.basename(note))[0], 16))
        if row and row['status'] == 'todo':
            row['status'], row['tries'] = 'tried', str(int(row['tries'] or 0) + 1)
            tried += 1
    if not arguments.dry_run:
        if not arguments.only:  # the stamp says which sources the last full run saw: a partial run must not mark the others as seen
            os.makedirs(os.path.dirname(STAMP), exist_ok=True)
            open(STAMP, 'w').close()
        with open(REGISTRY, 'w', encoding='utf-8', newline='') as out:
            writer = csv.DictWriter(out, list(rows[0].keys()), delimiter='\t', lineterminator='\n')
            writer.writeheader()
            writer.writerows(rows)
    matched = [row for row in rows if row['status'] == 'matched']
    print(f'{len(sources)} sources judged{" (dry run)" if arguments.dry_run else ""}: {len(new_matches)} new matches '
          f'({sum(int(row["size"]) for row in new_matches)} bytes), {tried} tried; registry: {len(matched)} of {len(rows)} matched')
    for address, name, reason, (number, kind, what), path in parked:
        print(f'parked: {address} {name}: {reason} ({path}:{number}: {what})')
    if parked:
        print(f'{len(parked)} source(s) score 0 but break a rule (check_source.py): parked in data/matching/asm-archive or cleanup-pending, not matched')
    if unlanded:
        print(f'{len(unlanded)} source(s) score 0 but did not land in their whole file (the file is unchanged), not matched: {" ".join(unlanded)}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
