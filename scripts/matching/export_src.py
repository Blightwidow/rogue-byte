#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""export_src.py: publishes the matched functions as src/<module>/<function name>.<ext>.

The working copies stay in data/matching/src (one file per function, named by address; the matching tools use them).
Reads data/matching/functions.tsv (status "matched") and config/recovered/modules.tsv (the module of each function:
Sly 1's source file names carried over by the code matcher). Unnamed functions (func_<address>) become fun_<address>.
Writes src/MANIFEST.tsv (address, name, size, file) and copies the shared headers to include/."""
import csv
import os
import re
import shutil

LAB = os.environ.get('ROGUE_BYTE_DIR') or os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.chdir(LAB)

modules = {}
for row in csv.DictReader(open('config/recovered/modules.tsv'), delimiter='\t'):
    modules[int(row['sly2_entry'], 16)] = row['module']

def directory_name(module):
    return re.sub(r'[^A-Za-z0-9_-]+', '-', module).strip('-') or 'unsorted'

readme = open('src/README.md').read() if os.path.exists('src/README.md') else None  # documentation, not generated
shutil.rmtree('src', ignore_errors=True)
manifest = []
for row in csv.DictReader(open('data/matching/functions.tsv'), delimiter='\t'):
    if row['status'] != 'matched':
        continue
    address = int(row['address'], 16)
    name = row['name']
    if name.startswith('func_'):
        name = 'fun_' + name[len('func_'):].lower()
    name = re.sub(r'[^A-Za-z0-9_]', '_', name)
    extension = os.path.splitext(row['source'])[1]
    folder = os.path.join('src', directory_name(modules.get(address, 'unsorted')))
    os.makedirs(folder, exist_ok=True)
    destination = os.path.join(folder, name + extension)
    if os.path.exists(destination):
        destination = os.path.join(folder, f'{name}_{address:X}{extension}')
    shutil.copyfile(row['source'], destination)
    manifest.append((f'{address:#X}', row['name'], row['size'], destination[len('src/'):]))

with open('src/MANIFEST.tsv', 'w') as handle:
    handle.write('address\tname\tsize\tfile\n')
    for entry in sorted(manifest):
        handle.write('\t'.join(entry) + '\n')
for header in os.listdir('data/matching/include'):
    shutil.copyfile(os.path.join('data/matching/include', header), os.path.join('include', header))
print(f'{len(manifest)} functions -> src/')
if readme is not None:
    with open('src/README.md', 'w') as handle:
        handle.write(readme)
