#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""prepare_report.py <output directory>: checks the committed objdiff report (site/data/objdiff-report.json, written by `make objdiff`)
and copies it to <output directory>/report.json, the file the `SCUS_973.16_report` artifact of progress.yml carries for bytematch.dev.
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
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    report = json.load(open(REPORT))
    found = problems(report)
    if found:
        sys.exit('\n'.join(f'{REPORT}: {problem}' for problem in found))
    os.makedirs(sys.argv[1], exist_ok=True)
    shutil.copyfile(REPORT, os.path.join(sys.argv[1], 'report.json'))
    measures = report['measures']
    print(f"report.json: {measures['matched_code']} of {measures['total_code']} bytes, {measures['matched_functions']} of {measures['total_functions']} functions")


if __name__ == '__main__':
    main()
