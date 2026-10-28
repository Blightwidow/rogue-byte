#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""build_site.py: site/assets (logo, icon, favicon) and the social card site/assets/og.png from site/data/summary.json.

Run scripts/gen_progress_report.py and scripts/generate_treemap.py first (`make progress` does all three). The PNG
renders need macOS Quick Look; elsewhere the committed PNGs are kept."""
import json
import os
import shutil
import subprocess
import sys

from PIL import Image

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
sys.path.insert(0, os.path.join(ROOT, 'assets', 'source'))
import make_assets  # noqa: E402  (writes the logo and icon too)

summary = json.load(open(os.path.join(ROOT, 'site', 'data', 'summary.json')))
game = summary['game_code']
assets = os.path.join(ROOT, 'site', 'assets')
os.makedirs(assets, exist_ok=True)
for name in ('logo.svg', 'logo.png', 'icon.png'):
    shutil.copyfile(os.path.join(ROOT, 'assets', name), os.path.join(assets, name))
Image.open(os.path.join(ROOT, 'assets', 'icon.png')).convert('RGBA').resize((128, 128), Image.LANCZOS).save(os.path.join(assets, 'favicon.png'), optimize=True)

c_share = game['c_bytes'] / game['bytes']
matched_share = (game['c_bytes'] + game['matched_bytes']) / game['bytes']
bar_width = 1040
logo_png = Image.open(os.path.join(ROOT, 'assets', 'logo.png'))
logo_height = round(760 * logo_png.height / logo_png.width)
card = f"""<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewBox="0 0 1200 1200" width="1200" height="1200">
  <defs><radialGradient id="sky" cx="0.2" cy="0" r="1.1"><stop offset="0" stop-color="#2a2d6e"/><stop offset="0.5" stop-color="#0b0c26"/><stop offset="1" stop-color="#05060f"/></radialGradient></defs>
  <rect width="1200" height="1200" fill="#05060f"/>
  <rect y="285" width="1200" height="630" fill="url(#sky)"/>
  <rect y="285" width="1200" height="8" fill="#2f63e0"/><rect y="907" width="1200" height="8" fill="#2f63e0"/>
  <image xlink:href="{os.path.relpath(os.path.join(assets, 'logo.png'), assets)}" x="60" y="{285 + 70}" width="760" height="{logo_height}"/>
  <text x="60" y="610" font-family="Helvetica Neue, Arial, sans-serif" font-size="120" font-weight="700" fill="#e8ecff">{c_share:.1%}</text>
  <text x="60" y="665" font-family="Helvetica Neue, Arial, sans-serif" font-size="34" fill="#9aa3d6">of the code compiles from matched C, verified byte for byte</text>
  <text x="60" y="745" font-family="Helvetica Neue, Arial, sans-serif" font-size="28" fill="#9aa3d6">Sly 2: Band of Thieves (PS2) decompilation</text>
  <rect x="60" y="830" width="{bar_width}" height="38" rx="8" fill="#2a2d6e"/>
  <rect x="60" y="830" width="{bar_width * c_share:.1f}" height="38" rx="8" fill="#2f7af4"/>
  <rect x="{60 + bar_width * c_share:.1f}" y="830" width="{bar_width * (matched_share - c_share):.1f}" height="38" fill="#f3c25a"/>
</svg>
"""
card_path = os.path.join(assets, 'og-square.svg')
open(card_path, 'w').write(card)
if make_assets.render_png(card_path, 2400):
    image = Image.open(os.path.join(assets, 'og-square.png')).convert('RGB')
    # the card is the 1200x630 band at y=285 of the 1200x1200 square
    scale = image.width / 1200
    image.crop((0, round(285 * scale), image.width, round(915 * scale))).resize((1200, 630), Image.LANCZOS).save(os.path.join(assets, 'og.png'), optimize=True)
    os.remove(os.path.join(assets, 'og-square.png'))
    print('site/assets/og.png')
os.remove(card_path)
