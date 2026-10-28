#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""gen_progress_report.py: site/data/report.json, the progress of the decompilation in bytes of code.

Needs `make elf` first (build/splat, config/us/swapped.tsv, build/image/fallbacks.tsv). Per function: address, name, size,
module and status. The file lists names, addresses, sizes and statuses only, never game bytes.

  c        compiled from src/ in the verified image (byte for byte)
  matched  matched by the judge, but the image still uses assembly for it (build/image/fallbacks.tsv says why)
  asm      not matched yet
Functions of the Sony SDK range (module `sdk`) are not the game's own code: they are reported but left out of the
game-code totals."""
import csv
import datetime
import json
import os
import re
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
os.chdir(ROOT)
TEXT_END = 0x259DF0

sys.path.insert(0, os.path.join(ROOT, 'scripts', 'build'))
from asm_units import read_units  # noqa: E402
_, units = read_units('build/splat')
addresses = [(function['address'], function['name']) for function in units]
unit_of = {function['address']: function['unit'] for function in units}

modules = {}
for row in csv.DictReader(open('config/recovered/modules.tsv'), delimiter='\t'):
    modules[int(row['sly2_entry'], 16)] = row['module']
swapped = {int(line.split('\t')[0], 16) for line in open('config/us/swapped.tsv')}
matched = {int(line.split('\t')[0], 16) for line in list(open('src/MANIFEST.tsv'))[1:]}

functions = []
for index, (address, name) in enumerate(addresses):
    end = addresses[index + 1][0] if index + 1 < len(addresses) else TEXT_END
    status = 'c' if address in swapped else 'matched' if address in matched else 'asm'
    functions.append({'address': f'{address:#X}', 'name': name, 'size': end - address,
                      'module': unit_of[address], 'status': status,
                      'named': not re.match(r'(func|fun)_[0-9A-Fa-f]{8}$', name)})

def totals(rows):
    result = {'functions': len(rows), 'bytes': sum(row['size'] for row in rows),
              'named': sum(1 for row in rows if row['named'])}
    for status in ('c', 'matched', 'asm'):
        selected = [row for row in rows if row['status'] == status]
        result[status + '_functions'] = len(selected)
        result[status + '_bytes'] = sum(row['size'] for row in selected)
    return result

game = [row for row in functions if row['module'] != 'sdk']
by_module = {}
for row in functions:
    by_module.setdefault(row['module'], []).append(row)
report = {
    'generated': datetime.datetime.now(datetime.timezone.utc).strftime('%Y-%m-%d'),
    'commit': subprocess.run(['git', 'rev-parse', '--short', 'HEAD'], capture_output=True, text=True).stdout.strip(),
    'game': 'Sly 2: Band of Thieves (SCUS-97316)',
    'totals': totals(functions),
    'game_code': totals(game),
    'modules': [{'name': name, **totals(rows)} for name, rows in sorted(by_module.items(), key=lambda item: -sum(r['size'] for r in item[1]))],
    'functions': functions,
}
os.makedirs('site/data', exist_ok=True)
with open('site/data/report.json', 'w') as handle:
    json.dump(report, handle, separators=(',', ':'))
summary = {key: value for key, value in report.items() if key != 'functions'}
if os.path.exists('site/data/objdiff-report.json'):  # make objdiff: objdiff's own measures of the same build
    measures = json.load(open('site/data/objdiff-report.json'))['measures']
    summary['objdiff'] = {key: float(measures[key]) for key in ('fuzzy_match_percent', 'matched_code_percent', 'total_code', 'matched_code', 'total_functions', 'matched_functions') if key in measures}
with open('site/data/summary.json', 'w') as handle:
    json.dump(summary, handle, separators=(',', ':'))
# one point per commit, for the curve on the site
history_path = 'site/data/history.json'
history = json.load(open(history_path)) if os.path.exists(history_path) else []
point = {'date': report['generated'], 'commit': report['commit'], 'c_bytes': report['game_code']['c_bytes'],
         'matched_bytes': report['game_code']['matched_bytes'], 'bytes': report['game_code']['bytes'],
         'named': report['game_code']['named'], 'functions': report['game_code']['functions']}
if not history or history[-1]['commit'] != point['commit']:
    history.append(point)
else:
    history[-1] = point
with open(history_path, 'w') as handle:
    json.dump(history, handle, indent=1)
total = report['game_code']
print(f"game code: {total['functions']} functions, {total['bytes']} bytes; C in image {total['c_bytes'] / total['bytes']:.1%}, "
      f"matched (not yet in image) {total['matched_bytes'] / total['bytes']:.1%}; named {total['named'] / total['functions']:.1%}")
