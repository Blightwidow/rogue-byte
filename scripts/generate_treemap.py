#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""generate_treemap.py: site/progress-map.svg, a treemap of the code: one block per module, one cell per function, area =
bytes, colour = status (blue: compiled from src/ in the verified image, gold: matched but still assembly in the image,
violet: compiles but does not match yet (nonmatching/), navy: not matched, grey: Sony SDK, left out of the totals). Reads site/data/report.json (scripts/gen_progress_report.py)."""
import html
import json
import os

import squarify

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
WIDTH, HEIGHT = 1600, 900
COLORS = {'c': '#2f7af4', 'matched': '#f3c25a', 'draft': '#4a45a8', 'asm': '#2a2d6e', 'sdk': '#4b4f6e'}
BACKGROUND = '#05060f'

report = json.load(open(os.path.join(ROOT, 'site', 'data', 'report.json')))
by_module = {}
for function in report['functions']:
    by_module.setdefault(function['module'], []).append(function)
modules = sorted(by_module.items(), key=lambda item: -sum(f['size'] for f in item[1]))
sizes = squarify.normalize_sizes([sum(f['size'] for f in rows) for _, rows in modules], WIDTH, HEIGHT)
module_boxes = squarify.squarify(sizes, 0, 0, WIDTH, HEIGHT)

parts = [f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {WIDTH} {HEIGHT}" width="{WIDTH}" height="{HEIGHT}" font-family="system-ui, sans-serif">',
         f'<rect width="{WIDTH}" height="{HEIGHT}" fill="{BACKGROUND}"/>']
for (name, rows), box in zip(modules, module_boxes):
    x, y, dx, dy = box['x'], box['y'], box['dx'], box['dy']
    rows = sorted(rows, key=lambda f: -f['size'])
    inner = squarify.normalize_sizes([f['size'] for f in rows], max(dx - 2, 1), max(dy - 2, 1))
    cells = squarify.squarify(inner, x + 1, y + 1, max(dx - 2, 1), max(dy - 2, 1))
    parts.append(f'<g><title>{html.escape(name)}: {sum(f["size"] for f in rows)} bytes</title>')
    for function, cell in zip(rows, cells):
        color = COLORS['sdk'] if function['module'] == 'sdk' and function['status'] == 'asm' else COLORS[function['status']]
        parts.append(f'<rect x="{cell["x"]:.1f}" y="{cell["y"]:.1f}" width="{max(cell["dx"] - 0.4, 0.2):.1f}" height="{max(cell["dy"] - 0.4, 0.2):.1f}" '
                     f'fill="{color}"><title>{html.escape(function["name"])} {function["address"]} {function["size"]} bytes ({function["status"]})</title></rect>')
    parts.append(f'<rect x="{x:.1f}" y="{y:.1f}" width="{dx:.1f}" height="{dy:.1f}" fill="none" stroke="{BACKGROUND}" stroke-width="2"/>')
    if dx > 110 and dy > 28:
        label = html.escape(name)
        parts.append(f'<text x="{x + 6:.1f}" y="{y + 17:.1f}" font-size="13" font-weight="600" fill="#ffffff" stroke="{BACKGROUND}" '
                     f'stroke-width="3" paint-order="stroke">{label}</text>')
    parts.append('</g>')
parts.append('</svg>')
open(os.path.join(ROOT, 'site', 'progress-map.svg'), 'w').write('\n'.join(parts))
print('site/progress-map.svg', len(modules), 'modules')
