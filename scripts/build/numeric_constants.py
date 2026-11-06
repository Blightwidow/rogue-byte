#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""numeric_constants.py : after Splat, writes the constants it mistook for addresses back as numbers.

spimdisasm turns a `lui`/`addiu` pair into a symbol whenever the value looks like an address, and its address filter skips pairs that end
in `addiu`. Splat then declares an undefined symbol for it (build/splat/undefined_syms_auto.txt: `D_FFFF = 0xFFFF;`), so a loop counter
such as `delay = 0x10000; delay != -1` reads `%lo(D_FFFF)` and the expected object carries a relocation that no C source can reproduce:
objdiff scored a byte-identical scePadInit 99.75%. A value outside the game's address range (0x100000 to 0x600000: the irx piece at 0x472200 is
the highest) is not a symbol. This rewrites `%hi(D_xxxx)` and `%lo(D_xxxx)` of such a symbol as `%hi(0xVALUE)` and `%lo(0xVALUE)` in every
assembly file under build/splat/asm; the bytes are the same, the relocation is gone. Symbols from config (user-declared) are not touched: only
the names Splat made up are listed in undefined_syms_auto.txt.

  python3 scripts/build/numeric_constants.py          (from the repository root; `configure.py --split` runs it after Splat)"""
import glob
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
SPLAT = os.path.join(ROOT, 'build', 'splat')
GAME_LOW = 0x100000
GAME_HIGH = 0x600000


def spurious_symbols():
    """{name: value} of the auto-declared symbols whose value lies outside the game's addresses."""
    found = {}
    with open(os.path.join(SPLAT, 'undefined_syms_auto.txt'), encoding='utf-8') as handle:
        for line in handle:
            match = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+);', line)
            if match:
                value = int(match.group(2), 16)
                if value < GAME_LOW or value >= GAME_HIGH:
                    found[match.group(1)] = value
    return found


def main():
    symbols = spurious_symbols()
    if not symbols:
        return 0
    pattern = re.compile(r'%(hi|lo)\((' + '|'.join(re.escape(name) for name in symbols) + r')\)')
    changed = replaced = 0
    for path in glob.glob(os.path.join(SPLAT, 'asm', '**', '*.s'), recursive=True):
        with open(path, encoding='utf-8') as handle:
            text = handle.read()
        new, count = pattern.subn(lambda match: f'%{match.group(1)}(0x{symbols[match.group(2)]:X})', text)
        if count:
            with open(path, 'w', encoding='utf-8') as handle:
                handle.write(new)
            changed += 1
            replaced += count
    print(f'numeric_constants: {replaced} references to {len(symbols)} non-address symbols rewritten in {changed} files', file=sys.stderr)
    return 0


if __name__ == '__main__':
    sys.exit(main())
