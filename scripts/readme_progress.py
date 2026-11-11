#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""readme_progress.py [--check]: rewrites the progress table of README.md (between the `progress:begin` and `progress:end` markers) from
progress/us/report.json and progress/eu/report.json, the objdiff reports `make objdiff` and `make pal` write. With --check it exits 1
when the README is not current. Names, addresses and sizes only."""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / 'README.md'
PATTERN = re.compile(r'(<!-- progress:begin[^>]*-->\n).*?(<!-- progress:end -->)', re.DOTALL)


def inline_to_match():
    """{'functions', 'bytes'} of config/us/inline_functions.tsv not matched yet (not in src/MANIFEST.tsv)."""
    listing = ROOT / 'config' / 'us' / 'inline_functions.tsv'
    manifest = ROOT / 'src' / 'MANIFEST.tsv'
    matched = {int(line.split('\t')[0], 16) for line in manifest.read_text(encoding='utf-8').splitlines()[1:] if line} if manifest.exists() else set()
    found = {'functions': 0, 'bytes': 0}
    for line in (listing.read_text(encoding='utf-8').splitlines()[1:] if listing.exists() else []):
        address, _, size, _ = line.split('\t')
        if int(address, 16) not in matched:
            found['functions'] += 1
            found['bytes'] += int(size)
    return found


def table():
    blocked = {'functions': 0, 'bytes': 0}
    blockers = ROOT / 'progress' / 'us' / 'blockers.json'
    if blockers.exists():
        blocked = json.loads(blockers.read_text(encoding='utf-8'))
    inline = inline_to_match()
    rows = ['| Version | Code | of which exact C | Functions | Blocked for C | C with inline assembly to match |',
            '| :--- | ---: | ---: | ---: | ---: | ---: |']
    for label, path in (('NTSC-U `SCUS_973.16`', 'progress/us/report.json'), ('PAL `SCES_525.29`', 'progress/eu/report.json')):
        report = ROOT / path
        if not report.exists():
            continue
        measures = json.loads(report.read_text(encoding='utf-8'))['measures']
        total = int(measures['total_code'])
        matched = int(measures['matched_code'])
        rows.append('| %s | %.2f%% (%s of %s bytes) | %.2f%% | %s of %s | %s functions, %.2f%% | %s functions, %.2f%% |' % (
            label, float(measures['matched_code_percent']), matched, total, 100 * (matched - blocked['bytes']) / total,
            measures['matched_functions'], measures['total_functions'], blocked['functions'], 100 * blocked['bytes'] / total,
            inline['functions'], 100 * inline['bytes'] / total))
    note = ('A function counts when `make elf` links its C and the image still equals retail byte for byte; for PAL, when the same C also reproduces '
            "PAL's code. Permanent blockers (a VU0, MMI or COP0 instruction, hand-written assembly, or a remnant that is not a function: "
            '`config/us/blockers.tsv`, [docs/build/vu0-mmi.md](docs/build/vu0-mmi.md)) stay original assembly and count as finished too, '
            'shown apart from the exact C. Compiled C that needs a shared inline-assembly helper for an instruction GCC cannot emit '
            '(`config/us/inline_functions.tsv`, [docs/build/inline-asm-helpers.md](docs/build/inline-asm-helpers.md)) is work to do; the last '
            'column counts those not matched yet.')
    return '\n'.join(rows) + '\n\n' + note + '\n'


def main():
    text = README.read_text(encoding='utf-8')
    if not PATTERN.search(text):
        sys.exit('README.md has no progress:begin / progress:end markers')
    updated = PATTERN.sub(lambda match: match.group(1) + table() + match.group(2), text)
    if '--check' in sys.argv:
        return 0 if updated == text else 1
    README.write_text(updated, encoding='utf-8')
    return 0


if __name__ == '__main__':
    sys.exit(main())
