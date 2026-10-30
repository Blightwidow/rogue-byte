#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""pal_report.py [--out site/data/objdiff-report-eu.json] [--check] - the objdiff report of the PAL build, from the US report and config/eu/c_status.tsv.

  python3 scripts/pal_report.py        (after `make objdiff` and scripts/version_check.py; `make pal` runs the chain)

The US report (site/data/objdiff-report.json) gives the units, their functions with sizes, and the categories. A function counts as matched
for PAL (fuzzy 100) when scripts/version_check.py found that the same C reproduces the PAL code (score 0) and every address its relocation
sites point at resolves to the paired PAL address (`addresses` ok); every other function is 0: a partial US match says nothing about PAL
until it is checked. Sizes are the US sizes (the two `.text` sections differ by 0.2%); the data sections have the PAL sizes and none of
it counts as matched (the rodata that compiled C owns is not checked for PAL). Only names, addresses and sizes are written: no retail
bytes. The report is what the `SCES_525.29_report` artifact of progress.yml carries for bytematch.dev.

--check needs no executable (it runs in `make check` and in CI): it fails when a matched function (src/MANIFEST.tsv) has no row in
config/eu/c_status.tsv or a row belongs to a function that is no longer matched, and when the committed PAL report is not what the committed
US report and c_status.tsv give: C was added, removed or re-measured without `make pal`."""
import argparse
import csv
import json
import os
import sys

LAB = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
DEFAULT_OUT = os.path.join(LAB, 'site', 'data', 'objdiff-report-eu.json')


def percent(part, whole):
    return round(100 * part / whole, 6) if whole else 100.0


def measures(units):
    """objdiff's `measures` of a list of units (each: functions as (size, fuzzy), data size, matched data size, complete flag)."""
    code = sum(size for unit in units for size, _ in unit['functions'])
    matched = sum(size for unit in units for size, fuzzy in unit['functions'] if fuzzy == 100)
    weighted = sum(size * fuzzy for unit in units for size, fuzzy in unit['functions'])
    functions = sum(len(unit['functions']) for unit in units)
    matched_functions = sum(1 for unit in units for _, fuzzy in unit['functions'] if fuzzy == 100)
    data = sum(unit['data'] for unit in units)
    matched_data = sum(unit['matched_data'] for unit in units)
    complete = [unit for unit in units if unit['complete']]
    complete_code = sum(size for unit in complete for size, _ in unit['functions'])
    result = {'fuzzy_match_percent': round(weighted / code, 6) if code else 100.0, 'total_code': str(code), 'matched_code': str(matched),
              'matched_code_percent': percent(matched, code)}
    if data:
        result['total_data'] = str(data)
        if matched_data:
            result['matched_data'] = str(matched_data)
            result['matched_data_percent'] = percent(matched_data, data)
    else:
        result['matched_data_percent'] = 100.0
    result.update({'total_functions': functions, 'matched_functions': matched_functions, 'matched_functions_percent': percent(matched_functions, functions),
                   'complete_code': str(complete_code), 'complete_code_percent': percent(complete_code, code)})
    if not data:
        result['complete_data_percent'] = 100.0
    result.update({'total_units': len(units), 'complete_units': len(complete)})
    return result


def build(us_report, status, other_sections):
    """The PAL report: `status` maps a function name to True when the same C reproduces the PAL code and its addresses."""
    units, summaries = [], []
    for unit in us_report['units']:
        name = unit['name']
        if name.startswith('data/'):
            section = {'data/rodata': '.rodata', 'data/rodata-c': None, 'data/data': '.data', 'data/vutext': '.vutext', 'data/irx': '.irx'}.get(name)
            if section is None:
                continue  # the rodata that compiled C owns: not checked for PAL
            size = other_sections[section]
            if name == 'data/rodata':
                size = other_sections['.rodata']
            copy = {'name': name, 'sections': [{'name': section, 'size': str(size), 'fuzzy_match_percent': 0.0, 'metadata': {}}], 'functions': [],
                    'metadata': dict(unit.get('metadata', {}), complete=False)}
            summary = {'functions': [], 'data': size, 'matched_data': 0, 'complete': False, 'categories': copy['metadata'].get('progress_categories', [])}
        else:
            functions = []
            for function in unit.get('functions', []):
                fuzzy = 100.0 if status.get(function['name']) else 0.0
                functions.append(dict(function, fuzzy_match_percent=fuzzy))
            text_size = sum(int(function['size']) for function in functions)
            copy = {'name': name, 'sections': [{'name': '.text', 'size': str(text_size), 'fuzzy_match_percent': percent(
                sum(int(f['size']) for f in functions if f['fuzzy_match_percent'] == 100), text_size) if text_size else 100.0, 'metadata': {}}],
                'functions': functions, 'metadata': dict(unit.get('metadata', {}))}
            complete = bool(functions) and all(f['fuzzy_match_percent'] == 100 for f in functions)
            copy['metadata']['complete'] = complete
            summary = {'functions': [(int(f['size']), f['fuzzy_match_percent']) for f in functions], 'data': 0, 'matched_data': 0, 'complete': complete,
                       'categories': copy['metadata'].get('progress_categories', [])}
        copy['measures'] = measures([summary])
        units.append(copy)
        summaries.append(summary)
    categories = []
    for category in us_report.get('categories', []):
        members = [summary for summary in summaries if category['id'] in summary['categories']]
        categories.append({'id': category['id'], 'name': category['name'], 'measures': measures(members)})
    return {'measures': measures(summaries), 'units': units, 'version': us_report.get('version', 2), 'categories': categories}


def read_status(path):
    """{function name: True when the same C reproduces the PAL code and its addresses}, and the addresses of the rows."""
    status, addresses = {}, set()
    for row in csv.DictReader(open(path, encoding='utf-8'), delimiter='\t'):
        status[row['name']] = row['score'] == '0' and row['addresses'] == 'ok'
        addresses.add(int(row['us_address'], 16))
    return status, addresses


def check(arguments):
    """The problems of the committed PAL data, empty when it is current."""
    problems = []
    manifest = {int(row['address'], 16): row['name'] for row in csv.DictReader(open(os.path.join(LAB, 'src', 'MANIFEST.tsv'), encoding='utf-8'), delimiter='\t')}
    status, rows = read_status(arguments.status)
    for address in sorted(set(manifest) - rows):
        problems.append(f'{manifest[address]} ({address:#X}) is matched but has no row in {os.path.relpath(arguments.status, LAB)}: run `make pal`')
    for address in sorted(rows - set(manifest)):
        problems.append(f'{os.path.relpath(arguments.status, LAB)} has a row for {address:#X}, which is no longer a matched function: run `make pal`')
    if not os.path.exists(arguments.out):
        return problems + [f'{os.path.relpath(arguments.out, LAB)} is missing: run `make pal`']
    committed = json.load(open(arguments.out))
    sizes = {}
    for unit in committed['units']:
        if unit['name'].startswith('data/'):
            section = unit['sections'][0]
            sizes[section['name']] = int(section['size'])
    expected = build(json.load(open(arguments.us_report)), status, {name: sizes.get(name, 0) for name in ('.rodata', '.data', '.vutext', '.irx')})
    if json.loads(json.dumps(expected)) != committed:
        problems.append(f'{os.path.relpath(arguments.out, LAB)} is not what {os.path.relpath(arguments.us_report, LAB)} and '
                        f'{os.path.relpath(arguments.status, LAB)} give: run `make pal`')
    return problems


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--us-report', default=os.path.join(LAB, 'site', 'data', 'objdiff-report.json'))
    parser.add_argument('--status', default=os.path.join(LAB, 'config', 'eu', 'c_status.tsv'))
    parser.add_argument('--other', default=os.path.join(LAB, 'work', 'elf', 'SCES_525.29'))
    parser.add_argument('--out', default=DEFAULT_OUT)
    parser.add_argument('--check', action='store_true', help='check that the committed PAL data is current (no executable needed)')
    arguments = parser.parse_args()
    if arguments.check:
        problems = check(arguments)
        for problem in problems:
            print(f'error: {problem}')
        print(f'{"FAIL" if problems else "ok"}: {len(problems)} problem(s) in the PAL data')
        return 1 if problems else 0
    from elftools.elf.elffile import ELFFile
    with open(arguments.other, 'rb') as handle:
        image = ELFFile(handle)
        sections = {name: image.get_section_by_name(name)['sh_size'] for name in ('.rodata', '.data', '.vutext', '.irx')}
    status, _ = read_status(arguments.status)
    report = build(json.load(open(arguments.us_report)), status, sections)
    os.makedirs(os.path.dirname(arguments.out), exist_ok=True)
    with open(arguments.out, 'w') as handle:
        json.dump(report, handle, indent=1)
    shown = report['measures']
    print(f'{shown["matched_functions"]} of {shown["total_functions"]} functions, {shown["matched_code_percent"]:.2f}% of the code '
          f'({int(shown["matched_code"])} of {int(shown["total_code"])} bytes), {shown["fuzzy_match_percent"]:.2f}% fuzzy; {arguments.out}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
