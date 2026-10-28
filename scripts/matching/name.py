#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""name.py <address> <name> - registers a symbol name for the matching link check (config/matching/symbol_addrs.txt).

  python3 scripts/matching/name.py 0x116D70 Reserve__FP4CAryi      (from the lab root)

The link check (scripts/matching/try.py) resolves every call and %hi/%lo pair of a compiled function through that file;
a source that calls a function under a name the file doesn't know scores a link error. A name may be added for an
address the split knows (an alias when the address has one already: the binary's own names are unknown, ours are
guesses); it is refused when the name already stands for another address.
"""
import re
import sys

SYMBOLS = 'config/matching/symbol_addrs.txt'


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    address, name = int(sys.argv[1], 16), sys.argv[2]
    if not re.match(r'^[A-Za-z_]\w*$', name):
        sys.exit(f'not a symbol name: {name}')
    generated = re.fullmatch(r'(?:D|B|func|jtbl|L|RO)_([0-9A-Fa-f]{8})', name)
    if generated:  # spimdisasm's names stand for the address they carry; they need no entry and can't mean another
        if int(generated.group(1), 16) != address:
            sys.exit(f'{name} is the split\'s name for 0x{int(generated.group(1), 16):08X}, not 0x{address:08X}: use the name the '
                     f'table has for 0x{address:08X} or give it a real one')
        print(f'{name} needs no entry: it resolves to its own address')
        return 0
    known = {}
    for line in open(SYMBOLS, encoding='utf-8'):
        match = re.match(r'(\w+) = 0x([0-9A-Fa-f]+);', line)
        if match:
            known.setdefault(match.group(1), int(match.group(2), 16))
    if name in known:
        if known[name] == address:
            print(f'{name} already = 0x{address:08X}')
            return 0
        sys.exit(f'{name} already stands for 0x{known[name]:08X}')
    others = [other for other, at in known.items() if at == address]
    with open(SYMBOLS, 'a', encoding='utf-8') as out:
        out.write(f'{name} = 0x{address:08X}; // source:matching{" alias-of:" + others[0] if others else ""}\n')
    print(f'{name} = 0x{address:08X}' + (f' (alias of {", ".join(others)})' if others else ''))
    return 0


if __name__ == '__main__':
    sys.exit(main())
