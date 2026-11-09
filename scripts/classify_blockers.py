#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""classify_blockers.py [--check]: flags the functions that are permanent blockers for C, as sly1-decomp does for its `vu`, `mmi` and
`handwritten` tags, and writes them to config/us/blockers.tsv (address, name, size, kind).

A function is a blocker when its code holds an instruction C has no form for and AGENTS.md does not let us write as inline asm:

  vu           a VU0 macro instruction (`lqc2`, `sqc2`, `qmtc2`, `qmfc2`, `cfc2`, `ctc2`, `vadd`, `vmul`, `vmadd`...)
  mmi          a multimedia instruction (`pextuw`, `pcpyld`, `prot3w`, `ppacw`...)
  system       a COP0 or system instruction (`mfc0`, `mtc0`, `ei`, `di`, `sync`, `eret`, `cache`, `syscall`; not `break`, which the compiler emits for a division by zero)
  handwritten  listed in config/us/handwritten_asm.txt (spimdisasm marks hand-written assembly)
  remnant      not a function: nothing in retail reaches it (no `jal`, `j` or branch target, no data word, no `lui`+`addiu`/`ori` pair,
               not the entry point) and it has no control-transfer instruction (no return, jump, branch or call), so no compiled
               function can be it: an epilogue left behind (`addiu $sp,$sp,N; nop`) or one or two leftover instructions. Every
               matched function either is reached or returns (measured 2026-11-09, docs/PRESERVATION_AND_PORT.md)

Such a function stays assembly: it is built from the original assembly, never counted as matched, and left out of the work queues
(list_functions.py, claim.py). Read from the split (`make elf` first); names, addresses and sizes only. With --check it exits 1 when
the committed table is stale. See docs/build/vu0-mmi.md."""
import os
import re
import struct
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
TABLE = os.path.join(ROOT, 'config', 'us', 'blockers.tsv')
HANDWRITTEN = os.path.join(ROOT, 'config', 'us', 'handwritten_asm.txt')
ELF = os.path.join(ROOT, 'work', 'elf', 'SCUS_973.16')
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


CONTROL_TRANSFER = re.compile(r'^(jr|jalr|j|jal|b\w*|bc[012]\w*|eret|syscall|break)$')
BRANCH_OPCODES = {1, 4, 5, 6, 7, 20, 21, 22, 23}  # REGIMM, beq, bne, blez, bgtz and their likely forms
PAIR_WINDOW = 8  # instructions between a `lui` and the `addiu`/`ori` that completes the address


def transfers_control(mnemonics):
    """True when one of the mnemonics returns, jumps, branches or calls."""
    return any(CONTROL_TRANSFER.match(mnemonic) for mnemonic in mnemonics)


def references_in_words(words, base):
    """Every address the words could aim at: each word itself (a pointer in data), `j`/`jal` targets, branch targets (COP1 and COP2
    branches included) and `lui` + `addiu`/`ori` pairs on the same register within PAIR_WINDOW instructions."""
    found = set()
    pending = {}
    for index, word in enumerate(words):
        pc = base + index * 4
        opcode = word >> 26
        found.add(word)
        if opcode in (2, 3):
            found.add((pc & 0xF0000000) | ((word & 0x3FFFFFF) << 2))
        if opcode in BRANCH_OPCODES or (opcode in (17, 18) and (word >> 21) & 31 == 8):
            offset = word & 0xFFFF
            found.add(pc + 4 + ((offset - 0x10000 if offset & 0x8000 else offset) << 2))
        if opcode == 15:
            pending[(word >> 16) & 31] = ((word & 0xFFFF) << 16, index)
        if opcode in (9, 13):
            source = (word >> 21) & 31
            if source in pending and index - pending[source][1] < PAIR_WINDOW:
                offset = word & 0xFFFF
                if opcode == 9 and offset & 0x8000:
                    offset -= 0x10000
                found.add((pending[source][0] + offset) & 0xFFFFFFFF)
    return found


def referenced_addresses(path=ELF):
    """references_in_words over every loaded segment of the executable, plus its entry point."""
    data = open(path, 'rb').read()
    entry, header_offset = struct.unpack_from('<II', data, 0x18)
    count = struct.unpack_from('<H', data, 0x2C)[0]
    found = {entry}
    for index in range(count):
        kind, offset, address, _, size = struct.unpack_from('<5I', data, header_offset + index * 32)
        if kind == 1 and size:
            found |= references_in_words(struct.unpack_from(f'<{size // 4}I', data, offset), address)
    return found


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
    references = referenced_addresses()
    rows = []
    for unit in units:
        mnemonics = mnemonics_of(unit['lines'])
        kind = (kind_of(mnemonics) or ('handwritten' if unit['address'] in hand else None)
                or ('remnant' if unit['address'] not in references and not transfers_control(mnemonics) else None))
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
