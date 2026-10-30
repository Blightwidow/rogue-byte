#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""prepare_report.py <output directory> [REPORT]: checks the committed objdiff report (default site/data/objdiff-report.json, written by
`make objdiff`; site/data/objdiff-report-eu.json for PAL, written by `make pal`) and copies it to <output directory>/report.json, the file
the `SCUS_973.16_report` (or `SCES_525.29_report`) artifact of progress.yml carries for bytematch.dev.
Measuring needs your own executable, so CI uploads what was committed instead of building it. Exit 1 when the report is not usable."""
import json
import os
import shutil
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
REPORT = os.path.join(ROOT, 'site', 'data', 'objdiff-report.json')
MEASURES = ('total_code', 'matched_code', 'total_functions', 'matched_functions')


def problems(report):
    """What is wrong with an objdiff report, empty when it can be uploaded."""
    measures = report.get('measures')
    if not isinstance(measures, dict):
        return ['no measures section']
    found = [f'measures.{key} is missing' for key in MEASURES if key not in measures]
    if found:
        return found
    total, matched = int(measures['total_code']), int(measures['matched_code'])
    found = []
    if not 0 < matched <= total:
        found.append(f'matched_code {matched} is not within total_code {total}')
    if not report.get('units'):
        found.append('no units')
    return found


def main():
    if len(sys.argv) not in (2, 3):
        sys.exit(__doc__)
    path = os.path.abspath(sys.argv[2]) if len(sys.argv) == 3 else REPORT
    report = json.load(open(path))
    found = problems(report)
    if found:
        sys.exit('\n'.join(f'{path}: {problem}' for problem in found))
    os.makedirs(sys.argv[1], exist_ok=True)
    shutil.copyfile(path, os.path.join(sys.argv[1], 'report.json'))
    measures = report['measures']
    print(f"report.json: {measures['matched_code']} of {measures['total_code']} bytes, {measures['matched_functions']} of {measures['total_functions']} functions")


if __name__ == '__main__':
    main()
