#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""claim.py init|take|status|land - queue waves for matching workers (OpenRAC/rac1-decomp's `wave.py`, our scale).

  python3 scripts/matching/claim.py init W1 --addresses file.txt [--budget 12]   a queue of function addresses (hex, one per line)
  python3 scripts/matching/claim.py init W1 --near 4 [--min-size B --max-size B]  every open function whose best draft scores MIN..4 (--min-score, default 1), from the registry
  python3 scripts/matching/claim.py take W1 k01 2 [--of 12]   claim the next 2 free functions for worker k01: prints one packet each (--of: the worker's N, shows how many are left)
  python3 scripts/matching/claim.py done W1 k01 12     DONE when worker k01 has claimed 12 functions or the queue is empty, else NOT DONE (exit 1): a worker's last check before its final message
  python3 scripts/matching/claim.py status W1         per function: claimed by, runs, best score (from work/matching/runs.log)
  python3 scripts/matching/claim.py verify W1          re-run the best logged source of every function with try.py's scorer and check_source.py: LAND, PARK (why), NEAR or MISMATCH
  python3 scripts/matching/claim.py land W1 [--reject ADDR ...] [--allow-ignored]   stage the best logged source of every function of the wave and adopt it

`take` is locked, so any number of workers can claim at once; it says QUEUE EMPTY when nothing is left. A packet gives the asm, the
current best draft and its last diff, the nearest matched functions and the worker's scratch folder, and the TRY_ARM/TRY_BUDGET
values to put in front of every try.py run. The tool, not the worker's message, decides: `status` and `land` read runs.log only.
`land` copies the lowest-scoring logged source of each function (the copy try.py kept) to work/matching/waves/<wave>/stage/ and runs
adopt.py on it (strictly lower than the source the function has now, re-judged); then `make land PROGRESS=0` registers and gates.
"""
import argparse
import csv
import fcntl
import json
import os
import re
import subprocess
import sys

LAB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
WAVES = os.path.join(LAB, 'work', 'matching', 'waves')
RUNS_LOG = os.path.join(LAB, 'work', 'matching', 'runs.log')
HELD = {0x22C8C0, 0x14DA08, 0x20C7E0, 0x196928, 0x15C690, 0x187768, 0x1C8090, 0x14F478, 0x15B0C8, 0x114AE0}  # rulings pending


SPLIT = os.path.join(LAB, 'work', 'matching', 'split', 'asm', 'functions', 'SCUS_973')
INSTRUCTION = re.compile(r'^\s*/\*[^*]*\*/\s+(\w[\w.]*)\s*(.*?)\s*(?:#.*)?$')


def fragment_reason(name):
    """Why the split's chunk of this name is not a whole function (nothing to match, a split fix at most), else None. The same
    traps OpenRAC's `plan` skips: a chunk that frees a frame it never made (leading `addiu $sp,$sp,+N`: the end of the previous
    function), one with no `jr $ra` and no `j` (it never returns), one that branches to a label outside its own bytes."""
    path = os.path.join(SPLIT, f'{name}.s')
    if not os.path.exists(path):
        return None
    text = open(path, encoding='utf-8').read()
    instructions = [match.groups() for match in map(INSTRUCTION.match, text.splitlines()) if match]
    if not instructions:
        return None
    mnemonic, operands = instructions[0]
    if mnemonic == 'addiu' and re.fullmatch(r'\$sp,\s*\$sp,\s*0x[0-9A-Fa-f]+', operands):
        return 'leading frame release (the end of the previous function)'
    if not any(m == 'j' or (m == 'jr' and ops in ('$ra', '$31')) for m, ops in instructions):
        return 'no return'
    labels = set(re.findall(r'^\s*(\.L\w+):', text, re.M))
    for mnemonic, operands in instructions:
        if mnemonic.startswith(('b', 'beq', 'bne')) and mnemonic not in ('break',) and operands:
            target = operands.split(',')[-1].strip()
            if target.startswith('.L') and target not in labels:
                return 'branches outside its own bytes'
    return None


def state_path(wave):
    return os.path.join(WAVES, wave, 'wave.json')


class Locked:
    def __enter__(self):
        return self

    def __init__(self, wave):
        self.path = state_path(wave)
        self.lock = open(self.path + '.lock', 'w')
        fcntl.flock(self.lock, fcntl.LOCK_EX)
        self.state = json.load(open(self.path))

    def save(self):
        json.dump(self.state, open(self.path, 'w'), indent=1)

    def __exit__(self, *exc):
        fcntl.flock(self.lock, fcntl.LOCK_UN)
        self.lock.close()


def manifest():
    rows = {}
    for row in csv.DictReader(open(os.path.join(LAB, 'nonmatching', 'MANIFEST.tsv'), encoding='utf-8'), delimiter='\t'):
        rows[int(row['address'], 16)] = row
    return rows


def fingerprint():
    """The scorer's fingerprint of the current toolchain (compiler flags, assembler, include/): try.py writes it on every runs.log line."""
    import scorer
    return scorer.fingerprint()


IGNORED = {}  # wave -> number of its logged runs the last runs() call skipped because they were made under another toolchain


def runs(wave):
    """address -> list of (arm, score or None, kept path) of this wave's arms, from runs made with the current toolchain: a run logged
    under another assembler or flag set (another fingerprint, or none) says nothing about what the sources score now."""
    found = {}
    IGNORED[wave] = 0
    if os.path.exists(RUNS_LOG):
        current = fingerprint()
        for line in open(RUNS_LOG, encoding='utf-8'):
            fields = line.rstrip('\n').split('\t')
            if len(fields) >= 2 and fields[1].startswith(wave + '-'):
                if len(fields) == 7 and fields[6] == current:
                    score = int(fields[3]) if fields[3].lstrip('-').isdigit() else None
                    found.setdefault(int(fields[2], 16), []).append((fields[1], score, fields[5]))
                else:
                    IGNORED[wave] += 1
    return found


def warn_ignored(wave):
    """Says on stderr how many logged runs of the wave do not count: the assembler, the flags, config/us/sony_gcc29.txt, the symbol file or include/
    changed since they were made (run the sources again with try.py, or put the change back)."""
    if IGNORED.get(wave):
        print(f'warning: {IGNORED[wave]} logged run(s) of wave {wave} were made under another toolchain and are ignored '
              '(the assembler, the flags, config/us/sony_gcc29.txt, the symbol file or include/ changed since)', file=sys.stderr)


def draft_source(address):
    """The source in data/matching/src/fn for a registry address (`0x1234`), or None."""
    stem = os.path.join(LAB, 'data', 'matching', 'src', 'fn', f'{int(address, 16):06X}')
    for extension in ('.cpp', '.c'):
        if os.path.exists(stem + extension):
            return stem + extension
    return None


def init(arguments):
    rows = list(csv.DictReader(open(os.path.join(LAB, 'data/matching/functions.tsv'), encoding='utf-8'), delimiter='\t'))
    size = {int(row['address'], 16): int(row['size']) for row in rows}
    open_now = {int(row['address'], 16) for row in rows if row['status'] != 'matched'}
    if arguments.addresses:
        queue = [int(line.split()[0], 16) for line in open(arguments.addresses, encoding='utf-8') if line.strip()]
    else:
        # the registry, not nonmatching/MANIFEST.tsv: the manifest lists only drafts published for objdiff, and misses the functions a toolchain
        # change demoted (they keep a source in data/matching/src/fn and a best score, but no published draft)
        best = {int(row['address'], 16): int(row['best']) for row in rows if row['status'] in ('tried', 'todo') and row['best'].isdigit()
                and arguments.min_score <= int(row['best']) <= arguments.near and draft_source(row['address'])}
        queue = sorted(best, key=lambda address: (best[address], -size.get(address, 0)))
    queue = [a for a in queue if a in open_now and a not in HELD and max(arguments.min_size, 16) <= size.get(a, 0) <= arguments.max_size]
    names = {int(row['address'], 16): row['name'] for row in rows}
    sys.path.insert(0, os.path.join(LAB, 'scripts'))
    import classify_blockers
    blocker_names = classify_blockers.names()
    fragments = {a: fragment_reason(names[a]) for a in queue}
    for address, reason in sorted(fragments.items()):
        if reason:
            print(f'skipped 0x{address:06X} {names[address]}: {reason}')
    queue = [a for a in queue if not fragments[a]]
    blocked = {a for a in queue if names[a] in blocker_names}
    for address in sorted(blocked):
        print(f'skipped 0x{address:06X} {names[address]}: permanent blocker (VU0, MMI, COP0 or hand-written: config/us/blockers.tsv)')
    queue = [a for a in queue if a not in blocked]
    os.makedirs(os.path.join(WAVES, arguments.wave), exist_ok=True)
    json.dump({'queue': queue, 'claims': {}, 'budget': arguments.budget}, open(state_path(arguments.wave), 'w'), indent=1)
    print(f'{arguments.wave}: {len(queue)} functions queued, budget {arguments.budget} runs each')


def packet(wave, worker, address, budget):
    import similar
    rows = {int(r['address'], 16): r for r in csv.DictReader(open(os.path.join(LAB, 'data/matching/functions.tsv'), encoding='utf-8'), delimiter='\t')}
    row = rows[address]
    scratch = os.path.join(WAVES, wave, worker, f'{address:06X}')
    os.makedirs(scratch, exist_ok=True)
    lines = [f'## 0x{address:06X} {row["name"]} ({row["size"]} bytes)',
             f'- asm: `work/matching/split/asm/functions/SCUS_973/{row["name"]}.s`',
             f'- scratch folder (write every attempt here, never in src/ or nonmatching/): `{os.path.relpath(scratch, LAB)}`',
             f'- run: `TRY_ARM={wave}-{worker} TRY_BUDGET={budget} python3 scripts/matching/try.py 0x{address:X} <file>`']
    entry = manifest().get(address)
    draft = draft_source(f'{address:X}') or (os.path.join(LAB, 'nonmatching', entry['file']) if entry else None)
    if draft:
        score = row['best'] if row['best'].isdigit() else (entry['score'] if entry else '?')
        lines.append(f'- best draft so far: `{os.path.relpath(draft, LAB)}` (best score {score}); its diff with the current toolchain is below')
        environment = {key: value for key, value in os.environ.items() if key not in ('TRY_ARM', 'TRY_BUDGET')}  # the packet's own run is no worker's try
        shown = subprocess.run([sys.executable, os.path.join(LAB, 'scripts', 'matching', 'try.py'), f'0x{address:X}', draft],
                               capture_output=True, text=True, env=environment).stdout.splitlines()[:40]
        if shown:
            lines.append('```\n' + '\n'.join(shown) + '\n```')
    for folder, why in (('cleanup-pending', 'scored 0 but breaks the cleanup rules (raw M2C offsets, a padding local): rewrite it clean and keep score 0'),
                        ('asm-archive', 'scored 0 only with a construct AGENTS.md bans (inline asm, a register pin): find the plain C')):
        parked = [name for name in os.listdir(os.path.join(LAB, 'data', 'matching', folder)) if name.upper().startswith(f'{address:06X}.')] \
            if os.path.isdir(os.path.join(LAB, 'data', 'matching', folder)) else []
        if parked:
            lines.append(f'- parked source `data/matching/{folder}/{parked[0]}` ({why})')
    index_rows, gold = similar.index()
    examples = [f'`data/matching/src/fn/{other:06X}.cpp` ({example["name"]}, {score:.2f})'
                for score, other, example, _ in similar.similar(address, 3, index_rows, gold) if score >= 0.25]
    if examples:
        lines.append('- similar matched sources: ' + '; '.join(examples))
    import check_calls
    flagged = check_calls.read_flags().get(address)
    if flagged:
        lines.append(f'- declarations that disagree with matched code (check_calls.py: confirm each in the diff, by the argument registers '
                     f'retail sets before the call; fix the real ones first): {flagged}')
    note = os.path.join(LAB, 'data', 'matching', 'notes', f'{address:06X}.md')
    if os.path.exists(note):
        lines.append(f'- earlier notes: `data/matching/notes/{address:06X}.md`')
    return '\n'.join(lines) + '\n'


def take(arguments):
    with Locked(arguments.wave) as lock:
        state = lock.state
        free = [a for a in state['queue'] if f'{a:06X}' not in state['claims']][:arguments.count]
        if not free:
            print('QUEUE EMPTY')
            return
        for address in free:
            state['claims'][f'{address:06X}'] = arguments.worker
        lock.save()
        budget = state['budget']
    for address in free:
        print(packet(arguments.wave, arguments.worker, address, budget))
    claimed = claimed_by(arguments.wave, arguments.worker)
    if arguments.of:
        print(f'Claimed {len(free)}; you have {claimed} of {arguments.of}. Handle them (EXACT, NEAR or SKIP per function), then `take` again until '
              f'`claim.py done {arguments.wave} {arguments.worker} {arguments.of}` prints DONE.')
    else:
        print(f'Claimed {len(free)}. Hand in per function one line: EXACT, NEAR (what still differs) or SKIP (why). Then `take` again until QUEUE EMPTY.')


def claimed_by(wave, worker):
    """How many functions of the wave the worker has claimed."""
    state = json.load(open(state_path(wave)))
    return sum(1 for owner in state['claims'].values() if owner == worker)


def done(arguments):
    """DONE (exit 0) when the worker has claimed N functions or no free one is left, else NOT DONE (exit 1)."""
    state = json.load(open(state_path(arguments.wave)))
    claimed = claimed_by(arguments.wave, arguments.worker)
    free = sum(1 for a in state['queue'] if f'{a:06X}' not in state['claims'])
    if claimed >= arguments.count or free == 0:
        print(f'DONE: {arguments.worker} has claimed {claimed} of {arguments.count}' + ('' if claimed >= arguments.count else '; the queue is empty'))
        return 0
    print(f'NOT DONE: {arguments.worker} has claimed {claimed} of {arguments.count} and {free} functions are free: `take` again')
    return 1


def best_runs(wave):
    """address -> the run to land: the lowest score; among equal scores a source that passes check_source.py (a worker's first run is often the
    untouched draft, which ties at 0 and breaks a rule), then the latest run, as workers end on their cleanest file."""
    import check_source
    best = {}
    for address, entries in runs(wave).items():
        scored = [(index, entry) for index, entry in enumerate(entries) if entry[1] is not None]
        if not scored:
            continue

        def clean(entry):
            try:
                with open(os.path.join(LAB, entry[2]), encoding='utf-8') as handle:
                    return not check_source.problems(handle.read())
            except OSError:
                return False
        best[address] = min(scored, key=lambda item: (item[1][1], not clean(item[1]), -item[0]))[1]
    return best


def status(arguments):
    state = json.load(open(state_path(arguments.wave)))
    found, best = runs(arguments.wave), best_runs(arguments.wave)
    warn_ignored(arguments.wave)
    exact = 0
    for address in state['queue']:
        key = f'{address:06X}'
        score = best[address][1] if address in best else '-'
        exact += score == 0
        print(f'{key}\t{state["claims"].get(key, "free")}\t{len(found.get(address, []))} runs\tbest {score}')
    print(f'{len(state["queue"])} queued, {len(state["claims"])} claimed, {exact} at score 0')


def verify(arguments):
    """One row per function with a logged run: the logged score, the score of a fresh compile of that source, and what landing would do with it.
    The log can be wrong (a worker's report often is); this is the lead's check, from the log and not from report text."""
    import scorer
    best = best_runs(arguments.wave)
    warn_ignored(arguments.wave)
    scorer.registry()
    names = {int(row['address'], 16): row['name'] for row in csv.DictReader(open(os.path.join(LAB, 'data/matching/functions.tsv'), encoding='utf-8'), delimiter='\t')}
    counts = {'LAND': 0, 'PARK': 0, 'NEAR': 0, 'MISMATCH': 0}
    for address in sorted(best):
        _, logged, kept = best[address]
        with open(os.path.join(LAB, kept), encoding='utf-8') as handle:
            text = handle.read()
        fresh = scorer.score_of(scorer.report(address, text, 'c' if kept.endswith('.c') else 'c++'))
        found = check_source_problems(text)
        if fresh != logged:
            verdict = f'MISMATCH logged {logged}, fresh {fresh}'
            counts['MISMATCH'] += 1
        elif fresh == 0 and found:
            verdict = f'PARK {found}'
            counts['PARK'] += 1
        elif fresh == 0:
            verdict = 'LAND'
            counts['LAND'] += 1
        else:
            verdict = f'NEAR {fresh}'
            counts['NEAR'] += 1
        print(f'0x{address:06X}\t{names.get(address, "?")}\t{kept}\t{verdict}')
    print(' '.join(f'{count} {name}' for name, count in counts.items()), file=sys.stderr)
    return 1 if counts['MISMATCH'] else 0


def check_source_problems(text):
    """The first thing check_source.py finds in a source ("line N: what"), or '' for a clean one."""
    import check_source
    found = check_source.problems(text)
    return f'line {found[0][0]}: {found[0][2]}' if found else ''


def land(arguments):
    best = best_runs(arguments.wave)
    warn_ignored(arguments.wave)
    if IGNORED.get(arguments.wave) and not arguments.allow_ignored:
        print(f'refusing to land: {IGNORED[arguments.wave]} logged run(s) of wave {arguments.wave} do not count under this toolchain, so the staged set would be '
              'incomplete (run the sources again with try.py, put the change back, or pass --allow-ignored)', file=sys.stderr)
        return 2
    rejected = {int(a, 16) for a in arguments.reject}
    stage = os.path.join(WAVES, arguments.wave, 'stage')
    os.makedirs(stage, exist_ok=True)
    for name in os.listdir(stage):
        os.remove(os.path.join(stage, name))
    count = 0
    staged = []
    for address, (_, score, kept) in best.items():
        if address in rejected:
            continue
        extension = os.path.splitext(kept)[1]
        data = open(os.path.join(LAB, kept), 'rb').read()
        open(os.path.join(stage, f'{address:06X}{extension}'), 'wb').write(data)
        count += 1
        staged.append(address)
        if score == 0 and check_source_problems(data.decode('utf-8', 'replace')):
            print(f'will be parked: 0x{address:06X} scores 0 but {check_source_problems(data.decode("utf-8", "replace"))}')
    print(f'{count} sources staged in {os.path.relpath(stage, LAB)}')
    subprocess.run([os.path.join(LAB, '.venv', 'bin', 'python'), os.path.join(LAB, 'scripts/matching/adopt.py'), stage], cwd=LAB)
    print('Next, the whole registry: make land PROGRESS=0')
    print('Next, only this wave (seconds in place of minutes): make land PROGRESS=0 ONLY="' + ' '.join(f'0x{address:06X}' for address in staged) + '"')
    return 0


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    commands = parser.add_subparsers(dest='command', required=True)
    sub = commands.add_parser('init')
    sub.add_argument('wave')
    sub.add_argument('--addresses')
    sub.add_argument('--near', type=int, default=4, help='highest draft score queued')
    sub.add_argument('--min-score', type=int, default=1, help='lowest draft score queued')
    sub.add_argument('--min-size', type=int, default=0)
    sub.add_argument('--max-size', type=int, default=1 << 30)
    sub.add_argument('--budget', type=int, default=12)
    sub = commands.add_parser('take')
    sub.add_argument('wave')
    sub.add_argument('worker')
    sub.add_argument('count', type=int, nargs='?', default=1)
    sub.add_argument('--of', type=int, help="the worker's N: the footer says how many are left")
    sub = commands.add_parser('done')
    sub.add_argument('wave')
    sub.add_argument('worker')
    sub.add_argument('count', type=int, help="the worker's N")
    for name in ('status', 'verify', 'land'):
        sub = commands.add_parser(name)
        sub.add_argument('wave')
        if name == 'land':
            sub.add_argument('--allow-ignored', action='store_true', help='stage the runs that count even though others were made under another toolchain')
            sub.add_argument('--reject', nargs='*', default=[], help='addresses (hex) not to stage: a score that rests on a banned construct or a wrong prototype')
    arguments = parser.parse_args()
    sys.exit({'init': init, 'take': take, 'status': status, 'verify': verify, 'land': land, 'done': done}[arguments.command](arguments) or 0)


if __name__ == '__main__':
    main()
