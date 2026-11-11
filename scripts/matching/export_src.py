#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""export_src.py: publishes the matched functions into src/: a function inside a whole file (config/us/whole_files.tsv) is published by
that file alone, every other one as src/<module>/<function name>.<ext>.

The working copies stay in data/matching/src (one file per function, named by address; the matching tools use them, and a function inside
a whole file keeps its copy there only). Reads data/matching/functions.tsv (status "matched") and config/recovered/modules.tsv (the module
of each function: Sly 1's source file names carried over by the code matcher). Unnamed functions (func_<address>) become fun_<address>.
Whole files are written by hand or by scripts/build/make_whole_files.py (`--land` puts a new match in), never generated here: they are
kept as they are. A matched function inside a whole file that still includes it from assembly (`INCLUDE_ASM`) is not published (landing
failed or was not run) and is listed. Writes src/MANIFEST.tsv (address, name, size, file, whole_file, symbol: `file` is the source in src/
that holds the function, `whole_file` the same path when that is a whole file and empty for a per-function source, `symbol` the
function's name in the whole file, empty for a per-function source: it defines that one function) and copies the shared headers to include/."""
import csv
import os
import re
import shutil
import sys

LAB = os.environ.get('SLY2_DECOMP_DIR') or os.environ.get('ROGUE_BYTE_DIR') or os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'build'))
import make_whole_files  # noqa: E402

COLUMNS = ('address', 'name', 'size', 'file', 'whole_file', 'symbol')


def directory_name(module):
    return re.sub(r'[^A-Za-z0-9_-]+', '-', module).strip('-') or 'unsorted'


def read_whole_files(path):
    """[(start, end, file)] of config/us/whole_files.tsv (file relative to src/)."""
    if not os.path.exists(path):
        return []
    rows = [line.rstrip('\n').split('\t') for line in list(open(path))[1:] if line.strip()]
    return [(int(start, 16), int(end, 16), file) for start, end, file in rows]


def whole_file_of(address, wholes):
    """The whole file (src/-relative) whose range holds `address`, or None."""
    return next((file for start, end, file in wholes if start <= address < end), None)


def included_from_assembly(text, address):
    """True when the whole file's text still has the INCLUDE_ASM line of `address`."""
    return make_whole_files.include_asm_marker(address).search(text) is not None


def source_symbol(text, name):
    """The name of the function `text` defines for the registry name `name`: the definition of that name (or of a qualified name ending
    with it), else the last function the source defines, else `name`."""
    defined = [found for kind, found in (make_whole_files.classify(item) for item in make_whole_files.split_items(text)) if kind == 'function' and found]
    plain = name.split('__')[0] if '__' in name[1:] else name
    for candidate in defined:
        if candidate in (name, plain) or candidate.endswith('::' + plain) or candidate.replace('::', '_') == plain:
            return candidate
    if defined and all('::' in candidate for candidate in defined):  # only inline members: the code is the file's static initializer
        return '__static_initialization_and_destruction_0'
    return defined[-1] if defined else name


def manifest_rows(registry_rows, modules, wholes, whole_texts, read_source=None):
    """(rows, copies, unlanded): src/MANIFEST.tsv rows as dicts (COLUMNS), the per-function copies to make as (source, destination
    relative to src/), and the matched rows inside a whole file that still includes them from assembly. read_source(path) gives a
    per-function source's text (None when it is missing); nothing else is read or written."""
    read_source = read_source or (lambda path: open(path, encoding='utf-8').read() if os.path.exists(path) else None)
    rows, copies, unlanded, taken = [], [], [], set()
    for row in registry_rows:
        if row['status'] != 'matched':
            continue
        address = int(row['address'], 16)
        whole = whole_file_of(address, wholes)
        if whole is not None:
            if whole not in whole_texts or included_from_assembly(whole_texts[whole], address):
                unlanded.append(row)
                continue
            text = read_source(row['source'])
            symbol = source_symbol(text, row['name']) if text is not None else row['name']
            rows.append({'address': f'{address:#X}', 'name': row['name'], 'size': row['size'], 'file': whole, 'whole_file': whole, 'symbol': symbol})
            continue
        name = row['name']
        if name.startswith('func_'):
            name = 'fun_' + name[len('func_'):].lower()
        name = re.sub(r'[^A-Za-z0-9_]', '_', name)
        extension = os.path.splitext(row['source'])[1]
        folder = directory_name(modules.get(address, 'unsorted'))
        destination = os.path.join(folder, name + extension)
        if destination.lower() in taken:  # as the file system sees it: macOS's is case-insensitive
            destination = os.path.join(folder, f'{name}_{address:X}{extension}')
        taken.add(destination.lower())
        copies.append((row['source'], destination))
        rows.append({'address': f'{address:#X}', 'name': row['name'], 'size': row['size'], 'file': destination, 'whole_file': '', 'symbol': ''})
    return sorted(rows, key=lambda entry: entry['address']), copies, unlanded


def main():
    os.chdir(LAB)
    modules = {}
    for row in csv.DictReader(open('config/recovered/modules.tsv'), delimiter='\t'):
        modules[int(row['sly2_entry'], 16)] = row['module']
    readme = open('src/README.md').read() if os.path.exists('src/README.md') else None  # documentation, not generated
    wholes = read_whole_files('config/us/whole_files.tsv')
    whole_texts = {file: open(os.path.join('src', file)).read() for _, _, file in wholes if os.path.exists(os.path.join('src', file))}
    # data files (config/us/data_files.tsv) are written by hand like whole files and kept as they are
    data_list = 'config/us/data_files.tsv'
    data_files = [line.rstrip('\n').split('\t')[2] for line in list(open(data_list))[1:]] if os.path.exists(data_list) else []
    data_texts = {file: open(os.path.join('src', file)).read() for file in data_files if os.path.exists(os.path.join('src', file))}
    registry = list(csv.DictReader(open('data/matching/functions.tsv'), delimiter='\t'))
    rows, copies, unlanded = manifest_rows(registry, modules, wholes, whole_texts)
    shutil.rmtree('src', ignore_errors=True)
    for source, destination in copies:
        os.makedirs(os.path.join('src', os.path.dirname(destination)), exist_ok=True)
        shutil.copyfile(source, os.path.join('src', destination))
    with open('src/MANIFEST.tsv', 'w') as handle:
        handle.write('\t'.join(COLUMNS) + '\n')
        for entry in rows:
            handle.write('\t'.join(entry[column] for column in COLUMNS) + '\n')
    for header in os.listdir('data/matching/include'):
        shutil.copyfile(os.path.join('data/matching/include', header), os.path.join('include', header))
    for file, text in list(whole_texts.items()) + list(data_texts.items()):
        path = os.path.join('src', file)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, 'w') as handle:
            handle.write(text)
    if readme is not None:
        with open('src/README.md', 'w') as handle:
            handle.write(readme)
    in_whole = sum(1 for entry in rows if entry['whole_file'])
    print(f'{len(rows)} functions -> src/ ({len(copies)} per-function sources, {in_whole} in {len(whole_texts)} whole files)')
    for row in unlanded:
        print(f'not published: {row["address"]} {row["name"]} is matched but its whole file still includes it from assembly: '
              f'run `.venv/bin/python scripts/build/make_whole_files.py --land {row["address"]}`')


if __name__ == '__main__':
    main()
