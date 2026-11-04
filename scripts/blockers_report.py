#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""blockers_report.py REPORT [--check]: counts the permanent blockers (config/us/blockers.tsv) as finished in an objdiff report, as
sly1-decomp counts original assembly: every function of the table that is not at 100% is set to 100, and the measures of the units, the
categories and the whole report are recomputed (`make objdiff` runs it on progress/us/report.json). It also writes
progress/<version>/blockers.json (how many functions and bytes were counted) so the README can show them apart from the exact C.

The measures are recomputed with scripts/pal_report.py `measures`; `--check` recomputes without any blockers and fails when that does not
give the report's own numbers (a test of the aggregation, run by tests/test_tools.py on a sample). Names, addresses and sizes only."""
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import classify_blockers  # noqa: E402
import pal_report  # noqa: E402


def blocker_names():
    """The function names of config/us/blockers.tsv."""
    return classify_blockers.names()


def summarise(unit):
    """The input of pal_report.measures for one unit of an objdiff report."""
    metadata = unit.get('metadata', {})
    functions = [(int(function['size']), function.get('fuzzy_match_percent', 0.0)) for function in unit.get('functions', [])]
    sections = unit.get('sections', [])
    sized = [section for section in sections if section['name'] != '.text' and int(section.get('size', 0))]  # an empty section has no `size`
    data = sum(int(section['size']) for section in sized) if unit['name'].startswith('data/') else 0
    matched_data = sum(int(section['size']) for section in sized if section.get('fuzzy_match_percent') == 100) if data else 0
    complete = bool(metadata.get('complete')) if data else bool(functions) and all(fuzzy == 100 for _, fuzzy in functions)
    return {'functions': functions, 'data': data, 'matched_data': matched_data, 'complete': complete, 'categories': metadata.get('progress_categories', [])}


def recompute(report):
    """The report with the measures of every unit, category and the whole recomputed from its functions."""
    summaries = []
    for unit in report['units']:
        summary = summarise(unit)
        summaries.append(summary)
        if not unit['name'].startswith('data/'):
            unit['measures'] = pal_report.measures([summary])
            unit.setdefault('metadata', {})['complete'] = summary['complete']
    for category in report.get('categories', []):
        category['measures'] = pal_report.measures([summary for summary in summaries if category['id'] in summary['categories']])
    report['measures'] = pal_report.measures(summaries)
    return report


def apply(report, names):
    """Marks the functions of `names` at 100 and recomputes. Returns (functions counted, bytes counted): the ones that were below 100."""
    count = size = 0
    for unit in report['units']:
        for function in unit.get('functions', []):
            if function['name'] in names and function.get('fuzzy_match_percent', 0.0) < 100:
                function['fuzzy_match_percent'] = 100.0
                count += 1
                size += int(function['size'])
    recompute(report)
    return count, size


def main():
    path = sys.argv[1]
    with open(path, encoding='utf-8') as handle:
        report = json.load(handle)
    if '--check' in sys.argv:
        before = {key: value for key, value in report['measures'].items() if key in ('total_code', 'matched_code', 'total_functions', 'matched_functions')}
        recompute(report)
        after = {key: value for key, value in report['measures'].items() if key in before}
        print('ok' if before == after else f'differs: {before} against {after}')
        return 0 if before == after else 1
    count, size = apply(report, blocker_names())
    with open(path, 'w', encoding='utf-8') as handle:
        json.dump(report, handle)
    summary = os.path.join(os.path.dirname(path), 'blockers.json')
    with open(summary, 'w', encoding='utf-8') as handle:
        json.dump({'functions': count, 'bytes': size}, handle)
        handle.write('\n')
    print(f'{count} blocker functions ({size} bytes) counted as finished in {path}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
