#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""claim.py init|take|status|land - queue waves for matching workers (OpenRAC/rac1-decomp's `wave.py`, our scale).

  python3 scripts/matching/claim.py init W1 --addresses file.txt [--budget 12]   a queue of function addresses (hex, one per line)
  python3 scripts/matching/claim.py init W1 --near 4 [--min-size B --max-size B]  every nonmatching/ draft scoring MIN..4 (--min-score, default 1)
  python3 scripts/matching/claim.py take W1 k01 2     claim the next 2 free functions for worker k01: prints one packet each
  python3 scripts/matching/claim.py status W1         per function: claimed by, runs, best score (from work/matching/runs.log)
  python3 scripts/matching/claim.py land W1 [--reject ADDR ...]   stage the best logged source of every function of the wave and adopt it

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


def runs(wave):
    """address -> list of (arm, score or None, kept path) of this wave's arms."""
    found = {}
    if os.path.exists(RUNS_LOG):
        for line in open(RUNS_LOG, encoding='utf-8'):
            fields = line.rstrip('\n').split('\t')
            if len(fields) == 6 and fields[1].startswith(wave + '-'):
                score = int(fields[3]) if fields[3].lstrip('-').isdigit() else None
                found.setdefault(int(fields[2], 16), []).append((fields[1], score, fields[5]))
    return found


def init(arguments):
    rows = list(csv.DictReader(open(os.path.join(LAB, 'data/matching/functions.tsv'), encoding='utf-8'), delimiter='\t'))
    size = {int(row['address'], 16): int(row['size']) for row in rows}
    open_now = {int(row['address'], 16) for row in rows if row['status'] != 'matched'}
    if arguments.addresses:
        queue = [int(line.split()[0], 16) for line in open(arguments.addresses, encoding='utf-8') if line.strip()]
    else:
        queue = [address for address, row in manifest().items() if row['score'].isdigit() and arguments.min_score <= int(row['score']) <= arguments.near]
        queue.sort(key=lambda address: (int(manifest()[address]['score']), -size.get(address, 0)))
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
    if entry:
        lines.append(f'- best draft so far: `nonmatching/{entry["file"]}` (score {entry["score"]}); its last diff: `work/matching/diffs/{address:06X}.txt`')
    index_rows, gold = similar.index()
    examples = [f'`data/matching/src/fn/{other:06X}.cpp` ({example["name"]}, {score:.2f})'
                for score, other, example, _ in similar.similar(address, 3, index_rows, gold) if score >= 0.25]
    if examples:
        lines.append('- similar matched sources: ' + '; '.join(examples))
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
    print(f'Claimed {len(free)}. Hand in per function one line: EXACT, NEAR (what still differs) or SKIP (why). Then `take` again until QUEUE EMPTY.')


def best_runs(wave):
    best = {}
    for address, entries in runs(wave).items():
        scored = [e for e in entries if e[1] is not None]
        if scored:
            best[address] = min(scored, key=lambda e: e[1])
    return best


def status(arguments):
    state = json.load(open(state_path(arguments.wave)))
    found, best = runs(arguments.wave), best_runs(arguments.wave)
    exact = 0
    for address in state['queue']:
        key = f'{address:06X}'
        score = best[address][1] if address in best else '-'
        exact += score == 0
        print(f'{key}\t{state["claims"].get(key, "free")}\t{len(found.get(address, []))} runs\tbest {score}')
    print(f'{len(state["queue"])} queued, {len(state["claims"])} claimed, {exact} at score 0')


def land(arguments):
    rejected = {int(a, 16) for a in arguments.reject}
    stage = os.path.join(WAVES, arguments.wave, 'stage')
    os.makedirs(stage, exist_ok=True)
    for name in os.listdir(stage):
        os.remove(os.path.join(stage, name))
    count = 0
    for address, (_, _, kept) in best_runs(arguments.wave).items():
        if address in rejected:
            continue
        extension = os.path.splitext(kept)[1]
        data = open(os.path.join(LAB, kept), 'rb').read()
        open(os.path.join(stage, f'{address:06X}{extension}'), 'wb').write(data)
        count += 1
    print(f'{count} sources staged in {os.path.relpath(stage, LAB)}')
    subprocess.run([os.path.join(LAB, '.venv', 'bin', 'python'), os.path.join(LAB, 'scripts/matching/adopt.py'), stage], cwd=LAB)
    print('Next: make land PROGRESS=0')


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
    for name in ('status', 'land'):
        sub = commands.add_parser(name)
        sub.add_argument('wave')
        if name == 'land':
            sub.add_argument('--reject', nargs='*', default=[], help='addresses (hex) not to stage: a score that rests on a banned construct or a wrong prototype')
    arguments = parser.parse_args()
    {'init': init, 'take': take, 'status': status, 'land': land}[arguments.command](arguments)


if __name__ == '__main__':
    main()
