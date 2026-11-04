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


def table():
    rows = ['| Version | Matched code | Functions | Data |', '| :--- | ---: | ---: | ---: |']
    for label, path in (('NTSC-U `SCUS_973.16`', 'progress/us/report.json'), ('PAL `SCES_525.29`', 'progress/eu/report.json')):
        report = ROOT / path
        if not report.exists():
            continue
        measures = json.loads(report.read_text(encoding='utf-8'))['measures']
        rows.append('| %s | %.2f%% (%s of %s bytes) | %s of %s | %.2f%% |' % (
            label, float(measures['matched_code_percent']), measures['matched_code'], measures['total_code'],
            measures['matched_functions'], measures['total_functions'], float(measures.get('matched_data_percent', 0))))
    return '\n'.join(rows) + '\n\n'


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
