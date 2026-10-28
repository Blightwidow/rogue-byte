#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/bevy_names.py - Sly 2 names from the address comments of sly2-bevy-of-thieves (MIT), a function-by-function Rust port.

  python3 scripts/names/bevy_names.py <bevy_of_thieves/src> work/export/sly2.jsonl config/recovered/

Its ported functions carry the original Sly 2 address in a comment just above them (`/// 0x00131290 (52B, r=1 w=0)`, then
more doc lines or attributes, then `fn name`), and a table names globals (`(0x00275c68, "g_...")`). An address counts only
when it is a function entry of our Sly 2 export (functions) or is not one (globals), so a stray constant is dropped.

Outputs config/recovered/bevy_functions.tsv and config/recovered/bevy_globals.tsv (address, name, file). The names are the port's own Rust names.
"""
import os
import re
import sys
import json

ADDRESS_COMMENT = re.compile(r'//.*?\b0x00?([12][0-9a-fA-F]{5})\b')
FUNCTION = re.compile(r'^\s*(?:pub(?:\([^)]*\))?\s+)?(?:const\s+)?(?:unsafe\s+)?(?:extern\s+"[^"]*"\s+)?fn\s+([A-Za-z_][A-Za-z0-9_]*)')
GLOBAL = re.compile(r'\(\s*0x00?([12][0-9a-fA-F]{5})\s*,\s*"([A-Za-z_][A-Za-z0-9_]*)"\s*\)')
SKIPPABLE = re.compile(r'^\s*(?://|#\[|$)')


def scan(source_root, entries):
    functions, globals_found = {}, {}
    for directory, _dirs, files in os.walk(source_root):
        for name in files:
            if not name.endswith('.rs'):
                continue
            path = os.path.join(directory, name)
            relative = os.path.relpath(path, source_root)
            lines = open(path, encoding='utf-8', errors='replace').read().splitlines()
            for index, line in enumerate(lines):
                for match in GLOBAL.finditer(line):
                    address = int(match.group(1), 16)
                    if address not in entries:
                        globals_found.setdefault(address, (match.group(2), relative))
                match = ADDRESS_COMMENT.search(line)
                if not match:
                    continue
                address = int(match.group(1), 16)
                if address not in entries:
                    continue
                same_line = FUNCTION.match(line)
                if same_line:
                    functions.setdefault(address, (same_line.group(1), relative))
                    continue
                for following in lines[index + 1:index + 16]:
                    definition = FUNCTION.match(following)
                    if definition:
                        functions.setdefault(address, (definition.group(1), relative))
                        break
                    if not SKIPPABLE.match(following):
                        break  # code before any fn: the comment is about something else
    return functions, globals_found


def main():
    if len(sys.argv) != 4:
        sys.exit(__doc__)
    source_root, export, out = sys.argv[1:]
    entries = {json.loads(line)['entry'] for line in open(export, encoding='utf-8')}
    functions, globals_found = scan(source_root, entries)
    os.makedirs(out, exist_ok=True)
    for file_name, table in (('bevy_functions.tsv', functions), ('bevy_globals.tsv', globals_found)):
        with open(os.path.join(out, file_name), 'w', encoding='utf-8') as f:
            f.write('address\tname\tfile\n')
            for address, (name, relative) in sorted(table.items()):
                f.write(f'0x{address:X}\t{name}\t{relative}\n')
    print(f'{len(functions)} functions, {len(globals_found)} globals')


if __name__ == '__main__':
    main()
