#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""make_assets.py: the logo, icon and favicon in assets/ and site/.

The cap is the project's cap artwork (assets/source/cap-full.png), the colours are the logo's blues. The title is set in
Racing Sans One (SIL OFL 1.1, downloaded to build/brand) and converted to paths, so the SVGs need no font. PNG
renders use macOS Quick Look (qlmanage) when it is there; otherwise only the SVGs are written."""
import base64
import io
import os
import subprocess
import sys
import urllib.request

from fontTools.pens.svgPathPen import SVGPathPen
from fontTools.pens.transformPen import TransformPen
from fontTools.ttLib import TTFont
from PIL import Image

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
FONT_URL = 'https://github.com/google/fonts/raw/main/ofl/racingsansone/RacingSansOne-Regular.ttf'
FONT_PATH = os.path.join(ROOT, 'build', 'brand', 'RacingSansOne-Regular.ttf')
COLORS = {'navy': '#05060f', 'ink': '#05081a', 'blue_dark': '#02307f', 'blue': '#2f7af4', 'blue_tile': '#2f63e0',
          'sky_light': '#5a5fa8', 'sky_mid': '#2a2d6e', 'sky_dark': '#0b0c26', 'moon': '#d9def5', 'gold': '#f3c25a'}

os.makedirs(os.path.join(ROOT, 'build', 'brand'), exist_ok=True)
if not os.path.exists(FONT_PATH):
    urllib.request.urlretrieve(FONT_URL, FONT_PATH)

cap = Image.open(os.path.join(ROOT, 'assets', 'source', 'cap-full.png')).convert('RGBA')
cap.thumbnail((520, 520), Image.LANCZOS)
cap.save(os.path.join(ROOT, 'assets', 'cap.png'), optimize=True)
buffer = io.BytesIO()
cap.save(buffer, 'PNG', optimize=True)
CAP_URI = 'data:image/png;base64,' + base64.b64encode(buffer.getvalue()).decode()

def title_path(text, size):
    """(svg path data, width) of the text set at `size` px, baseline at y=0."""
    font = TTFont(FONT_PATH)
    glyph_set = font.getGlyphSet()
    cmap = font.getBestCmap()
    scale = size / font['head'].unitsPerEm
    pen = SVGPathPen(glyph_set)
    cursor = 0
    for character in text:
        name = cmap[ord(character)]
        glyph_set[name].draw(TransformPen(pen, (scale, 0, 0, -scale, cursor, 0)))
        cursor += glyph_set[name].width * scale
    return pen.getCommands(), cursor

def logo_svg():
    path, width = title_path('Rogue Byte', 210)
    cap_width, cap_height = 330, round(330 * cap.height / cap.width)
    total_width = cap_width + 30 + round(width) + 40
    return f"""<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewBox="0 0 {total_width} 300" width="{total_width}" height="300">
  <defs>
    <linearGradient id="fill" x1="0" y1="0" x2="0" y2="1">
      <stop offset="0" stop-color="{COLORS['blue_dark']}"/><stop offset="0.5" stop-color="{COLORS['blue']}"/><stop offset="1" stop-color="{COLORS['blue_dark']}"/>
    </linearGradient>
    <filter id="drop" x="-5%" y="-10%" width="110%" height="130%"><feDropShadow dx="0" dy="6" stdDeviation="5" flood-color="#000" flood-opacity="0.5"/></filter>
  </defs>
  <image xlink:href="{CAP_URI}" x="0" y="{round((300 - cap_height) / 2)}" width="{cap_width}" height="{cap_height}"/>
  <g transform="translate({cap_width + 30} 222)" filter="url(#drop)">
    <path d="{path}" fill="none" stroke="{COLORS['ink']}" stroke-width="22" stroke-linejoin="round"/>
    <path d="{path}" fill="url(#fill)" stroke="#eef4ff" stroke-width="2.5" stroke-linejoin="round"/>
  </g>
</svg>
"""

def icon_svg():
    return f"""<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewBox="0 0 1024 1024" width="1024" height="1024">
  <defs>
    <radialGradient id="sky" cx="0.3" cy="0.25" r="0.95">
      <stop offset="0" stop-color="{COLORS['sky_light']}"/><stop offset="0.35" stop-color="{COLORS['sky_mid']}"/><stop offset="1" stop-color="{COLORS['sky_dark']}"/>
    </radialGradient>
    <radialGradient id="glow" cx="0.5" cy="0.5" r="0.5">
      <stop offset="0" stop-color="#dfe6ff" stop-opacity="0.7"/><stop offset="1" stop-color="#dfe6ff" stop-opacity="0"/>
    </radialGradient>
    <clipPath id="tileClip"><rect x="44" y="44" width="936" height="936"/></clipPath>
  </defs>
  <rect width="1024" height="1024" fill="{COLORS['navy']}"/>
  <rect x="22" y="22" width="980" height="980" fill="{COLORS['blue_tile']}"/>
  <rect x="34" y="34" width="956" height="956" fill="{COLORS['navy']}"/>
  <rect x="44" y="44" width="936" height="936" fill="url(#sky)"/>
  <circle cx="300" cy="250" r="330" fill="url(#glow)" clip-path="url(#tileClip)"/>
  <circle cx="300" cy="250" r="150" fill="{COLORS['moon']}"/>
  <path clip-path="url(#tileClip)" fill="#0c0e2c" d="M44 980 L44 860 L90 860 L120 830 L240 830 L270 860 L300 860 L300 800 L322 800 L322 840 L380 840 L410 810 L520 810 L520 770 L546 770 L546 810 L560 810 L590 850 L660 850 L690 820 L780 820 L780 790 L804 790 L804 820 L840 820 L870 850 L930 850 L930 810 L950 810 L950 850 L980 850 L980 980 Z"/>
  <g fill="{COLORS['gold']}" opacity="0.85"><rect x="150" y="880" width="18" height="28"/><rect x="200" y="880" width="18" height="28"/><rect x="450" y="860" width="18" height="28"/><rect x="720" y="880" width="18" height="28"/><rect x="900" y="900" width="18" height="28"/></g>
  <g fill="#ffffff" opacity="0.8"><circle cx="760" cy="150" r="5"/><circle cx="880" cy="260" r="4"/><circle cx="640" cy="110" r="3"/><circle cx="900" cy="120" r="3"/><circle cx="120" cy="560" r="3"/><circle cx="830" cy="830" r="4"/></g>
  <image xlink:href="{CAP_URI}" x="110" y="200" width="804" height="{round(804 * cap.height / cap.width)}"/>
</svg>
"""

def render_png(svg_path, size):
    """A PNG next to the SVG, through Quick Look; returns False when it is not available."""
    if not os.path.exists('/usr/bin/qlmanage'):
        return False
    output = os.path.dirname(svg_path)
    subprocess.run(['/usr/bin/qlmanage', '-t', '-s', str(size), '-o', output, svg_path], capture_output=True)
    produced = svg_path + '.png'
    if os.path.exists(produced):
        os.replace(produced, svg_path[:-4] + '.png')
        return True
    return False

def render_wide_png(svg_path, width):
    """Quick Look renders a square on white, so the SVG is set in a square viewBox, rendered on white and on black (the
    difference gives the alpha) and cropped to its content."""
    import re
    import numpy
    content = open(svg_path).read()
    view_width, view_height = map(int, re.search(r'viewBox="0 0 (\d+) (\d+)"', content).groups())
    square = content.replace(f'viewBox="0 0 {view_width} {view_height}" width="{view_width}" height="{view_height}"',
                             f'viewBox="0 {-(view_width - view_height) // 2} {view_width} {view_width}" width="{view_width}" height="{view_width}"')
    renders = {}
    for name, backdrop in (('white', None), ('black', f'<rect x="-10" y="{-view_width}" width="{view_width + 20}" height="{3 * view_width}" fill="#000"/>')):
        document = square if backdrop is None else re.sub(r'(<svg[^>]*>)', lambda match: match.group(1) + backdrop, square, count=1)
        temporary = svg_path[:-4] + f'-{name}.svg'
        open(temporary, 'w').write(document)
        done = render_png(temporary, 2400)
        os.remove(temporary)
        if not done:
            return False
        renders[name] = numpy.asarray(Image.open(temporary[:-4] + '.png').convert('RGB'), dtype=numpy.float64)
        os.remove(temporary[:-4] + '.png')
    alpha = 1.0 - (renders['white'] - renders['black']).mean(axis=2) / 255.0
    alpha = numpy.clip(alpha, 0.0, 1.0)
    safe = numpy.maximum(alpha, 1e-6)[..., None]
    color = numpy.clip(renders['black'] / safe, 0, 255)
    rgba = numpy.dstack([color, alpha * 255]).astype(numpy.uint8)
    image = Image.fromarray(rgba, 'RGBA')
    image = image.crop(image.getchannel('A').point(lambda value: 255 if value > 8 else 0).getbbox())
    image = image.resize((width, round(width * image.height / image.width)), Image.LANCZOS)
    image.save(svg_path[:-4] + '.png', optimize=True)
    return True

if __name__ == '__main__':
    path = os.path.join(ROOT, 'assets', 'logo.svg')
    open(path, 'w').write(logo_svg())
    print(path, 'png' if render_wide_png(path, 1152) else 'svg only')
    path = os.path.join(ROOT, 'assets', 'icon.svg')
    open(path, 'w').write(icon_svg())
    print(path, 'png' if render_png(path, 1024) else 'svg only')
