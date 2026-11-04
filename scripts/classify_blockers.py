#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""classify_blockers.py [--check]: flags the functions that are permanent blockers for C, as sly1-decomp does for its `vu`, `mmi` and
`handwritten` tags, and writes them to config/us/blockers.tsv (address, name, size, kind).

A function is a blocker when its code holds an instruction C has no form for and AGENTS.md does not let us write as inline asm:

  vu           a VU0 macro instruction (`lqc2`, `sqc2`, `qmtc2`, `qmfc2`, `cfc2`, `ctc2`, `vadd`, `vmul`, `vmadd`...)
  mmi          a multimedia instruction (`pextuw`, `pcpyld`, `prot3w`, `ppacw`...)
  system       a COP0 or system instruction (`mfc0`, `mtc0`, `ei`, `di`, `sync`, `eret`, `cache`, `syscall`; not `break`, which the compiler emits for a division by zero)
  handwritten  listed in config/us/handwritten_asm.txt (spimdisasm marks hand-written assembly)

Such a function stays assembly: it is built from the original assembly, never counted as matched, and left out of the work queues
(list_functions.py, claim.py). Read from the split (`make elf` first); names, addresses and sizes only. With --check it exits 1 when
the committed table is stale. See docs/build/vu0-mmi.md."""
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
TABLE = os.path.join(ROOT, 'config', 'us', 'blockers.tsv')
HANDWRITTEN = os.path.join(ROOT, 'config', 'us', 'handwritten_asm.txt')
INSTRUCTION = re.compile(r'^\s*/\*[^*]*\*/\s+(\w[\w.]*)')

VU = re.compile(r'^(lqc2|sqc2|qmtc2|qmfc2|cfc2|ctc2|v(?:add|sub|mul|madd|msub|max|mini|opmsub|opmula|div|sqrt|rsqrt|abs|ftoi|itof|clip|mr32|move|nop|ior|iaddi|lqi|sqi|callms|lq|sq)\w*)(?:\.\w+)?$')
MMI = re.compile(r'^p(?:extuw|extlw|cpyld|cpyud|extub|extlb|extuh|extlh|ackw|rot3w|sllw|srlw|raw|addw|subw|maxw|minw|and|xor|nor|mfhl|mthl)$')
SYSTEM = re.compile(r'^(mfc0|mtc0|ei|di|sync|eret|cache|syscall|tlbr|tlbwi|tlbwr|tlbp)$')  # not `break`: the compiler emits it for a division by zero


def kind_of(mnemonics):
    """'vu', 'mmi', 'system' or None for the mnemonics of one function (the first kind found, in that order)."""
    for kind, pattern in (('vu', VU), ('mmi', MMI), ('system', SYSTEM)):
        if any(pattern.match(mnemonic) for mnemonic in mnemonics):
            return kind
    return None


def mnemonics_of(lines):
    found = []
    for line in lines:
        match = INSTRUCTION.match(line)
        if match:
            found.append(match.group(1))
    return found


def handwritten():
    if not os.path.exists(HANDWRITTEN):
        return set()
    with open(HANDWRITTEN, encoding='utf-8') as listing:
        return {int(line.split()[0], 16) for line in listing if line.strip() and not line.startswith('#')}


def build():
    sys.path.insert(0, os.path.join(ROOT, 'scripts', 'build'))
    from asm_units import read_units
    os.chdir(ROOT)
    _, units = read_units('build/splat')
    hand = handwritten()
    rows = []
    for unit in units:
        kind = kind_of(mnemonics_of(unit['lines'])) or ('handwritten' if unit['address'] in hand else None)
        if kind:
            rows.append((unit['address'], unit['name'], unit['end'] - unit['address'], kind))
    return sorted(rows)


def render(rows):
    lines = ['address\tname\tsize\tkind']
    lines += [f'{address:#X}\t{name}\t{size}\t{kind}' for address, name, size, kind in rows]
    return '\n'.join(lines) + '\n'


def read_table():
    """{address: kind} of the committed table, empty when it does not exist."""
    if not os.path.exists(TABLE):
        return {}
    with open(TABLE, encoding='utf-8') as handle:
        return {int(line.split('\t')[0], 16): line.rstrip('\n').split('\t')[3] for line in list(handle)[1:] if line.strip()}


def names():
    """The function names of the committed table (empty when it does not exist)."""
    found = set()
    if os.path.exists(TABLE):
        with open(TABLE, encoding='utf-8') as handle:
            for line in list(handle)[1:]:
                if line.strip():
                    found.add(line.split('\t')[1])
    return found


def main():
    text = render(build())
    if '--check' in sys.argv:
        current = open(TABLE, encoding='utf-8').read() if os.path.exists(TABLE) else ''
        print('ok: config/us/blockers.tsv is current' if current == text else 'stale: run python3 scripts/classify_blockers.py')
        return 0 if current == text else 1
    with open(TABLE, 'w', encoding='utf-8') as handle:
        handle.write(text)
    counts = {}
    for line in text.split('\n')[1:]:
        if line:
            kind = line.split('\t')[3]
            counts[kind] = counts.get(kind, 0) + 1
    print(f'{sum(counts.values())} blockers: ' + ', '.join(f'{kind} {count}' for kind, count in sorted(counts.items())))
    return 0


if __name__ == '__main__':
    sys.exit(main())
