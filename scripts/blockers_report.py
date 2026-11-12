#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""blockers_report.py REPORT [--check]: takes the final permanent blockers (config/us/blockers.tsv kinds `system`, `remnant`, `vu` and
`handwritten`, classify_blockers.FINAL_KINDS) out of an objdiff report: they stay original assembly for good, so they are neither matched nor
unmatched, and the functions, bytes, units and categories are recomputed without them (`make objdiff` runs it on progress/us/report.json).
The `mmi` kind is not final yet (shared helpers may turn some into C), so those functions stay in the count as the objdiff report has them.
It also writes progress/<version>/blockers.json (how many functions and bytes were left out, and by kind) so the README can show them apart.
A unit whose functions are all left out is complete (its `complete` metadata, the one field objdiff's report schema allows for it).

The measures are recomputed with scripts/pal_report.py `measures`; `--check` recomputes without any blockers and fails when that does not
give the report's own numbers (a test of the aggregation, run by tests/test_tools.py on a sample). Names, addresses and sizes only."""
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import classify_blockers  # noqa: E402
import pal_report  # noqa: E402


def summarise(unit):
    """The input of pal_report.measures for one unit of an objdiff report."""
    metadata = unit.get('metadata', {})
    functions = [(int(function['size']), function.get('fuzzy_match_percent', 0.0)) for function in unit.get('functions', [])]
    sections = unit.get('sections', [])
    sized = [section for section in sections if section['name'] != '.text' and int(section.get('size', 0))]  # an empty section has no `size`
    data = sum(int(section['size']) for section in sized) if unit['name'].startswith('data/') else 0
    matched_data = sum(int(section['size']) for section in sized if section.get('fuzzy_match_percent') == 100) if data else 0
    complete = bool(metadata.get('complete')) if data else (bool(metadata.get('complete')) if not functions else all(fuzzy == 100 for _, fuzzy in functions))
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


def apply(report, excluded):
    """Takes the functions named in `excluded` ({name: kind}) out of the report and recomputes. Returns {'functions', 'bytes', 'kinds'} of what was left out."""
    count = size = 0
    kinds = {}
    for unit in report['units']:
        kept = []
        left = 0
        for function in unit.get('functions', []):
            if function['name'] in excluded:
                left += 1
                count += 1
                size += int(function['size'])
                kinds[excluded[function['name']]] = kinds.get(excluded[function['name']], 0) + 1
            else:
                kept.append(function)
        if left:
            unit['functions'] = kept
            if not kept:
                unit.setdefault('metadata', {})['complete'] = True  # objdiff rejects unknown metadata fields: `complete` carries it
    recompute(report)
    return {'functions': count, 'bytes': size, 'kinds': kinds}


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
    summary_counts = apply(report, classify_blockers.final_names())
    with open(path, 'w', encoding='utf-8') as handle:
        json.dump(report, handle)
    summary = os.path.join(os.path.dirname(path), 'blockers.json')
    with open(summary, 'w', encoding='utf-8') as handle:
        json.dump(summary_counts, handle)
        handle.write('\n')
    print(f"{summary_counts['functions']} final blocker functions ({summary_counts['bytes']} bytes) left out of {path}")
    return 0


if __name__ == '__main__':
    sys.exit(main())
