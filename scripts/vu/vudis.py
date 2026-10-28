#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""vudis.py <executable> [--out FILE] [--section NAME] - disassembles the VU1 microcode (.vutext and the .DVP.overlay* sections).

  .venv/bin/python scripts/vu/vudis.py work/elf/SCUS_973.16 --out work/vu/vutext.s      (from the repository root)

A micro instruction is 64 bits: the low word is the lower instruction, the high word the upper one (bits 31-27 of the upper
word are the I, E, M, D and T flags). When I is set the lower word is not an instruction but a 32-bit float constant.
Opcode tables follow the VU user's manual; the tables were cross-checked against the ISC-licensed disassembler of OpenGOAL
(decompiler/VuDisasm), which only covers what Jak needs. Programs are split after the instruction in the delay slot of an
E-bit instruction. Branch targets print as the instruction index (byte address / 8) and get labels.

The output is game code: keep it in work/, never commit it."""
import argparse
import struct
import sys

FIELDS = 'xyzw'

UPPER_FUNCT = {
    0x1C: ('mulq', 'q'), 0x1D: ('maxi', 'i'), 0x1E: ('muli', 'i'), 0x1F: ('minii', 'i'),
    0x20: ('addq', 'q'), 0x21: ('maddq', 'q'), 0x22: ('addi', 'i'), 0x23: ('maddi', 'i'),
    0x24: ('subq', 'q'), 0x25: ('msubq', 'q'), 0x26: ('subi', 'i'), 0x27: ('msubi', 'i'),
    0x28: ('add', 'v'), 0x29: ('madd', 'v'), 0x2A: ('mul', 'v'), 0x2B: ('max', 'v'),
    0x2C: ('sub', 'v'), 0x2D: ('msub', 'v'), 0x2E: ('opmsub', 'v'), 0x2F: ('mini', 'v'),
}
UPPER_BROADCAST = ['add', 'sub', 'madd', 'msub', 'max', 'mini', 'mul']  # funct 0x00-0x1B, four per name

# 11-bit special opcodes of the upper word: (bits 10-6 << 2) | (bits 1-0), bits 5-2 are 1111
UPPER_SPECIAL = {}
for index, name in enumerate(['adda', 'suba', 'madda', 'msuba']):
    for broadcast in range(4):
        UPPER_SPECIAL[(index << 2) | broadcast] = (name + 'xyzw'[broadcast], 'a')
for broadcast, convert in enumerate(['itof0', 'itof4', 'itof12', 'itof15']):
    UPPER_SPECIAL[(4 << 2) | broadcast] = (convert, 'ft')
for broadcast, convert in enumerate(['ftoi0', 'ftoi4', 'ftoi12', 'ftoi15']):
    UPPER_SPECIAL[(5 << 2) | broadcast] = (convert, 'ft')
for broadcast in range(4):
    UPPER_SPECIAL[(6 << 2) | broadcast] = ('mula' + 'xyzw'[broadcast], 'a')
UPPER_SPECIAL.update({
    (7 << 2) | 0: ('mulaq', 'a'), (7 << 2) | 1: ('abs', 'ft'), (7 << 2) | 2: ('mulai', 'a'), (7 << 2) | 3: ('clip', 'clip'),
    (8 << 2) | 0: ('addaq', 'a'), (8 << 2) | 1: ('maddaq', 'a'), (8 << 2) | 2: ('addai', 'a'), (8 << 2) | 3: ('maddai', 'a'),
    (9 << 2) | 0: ('subaq', 'a'), (9 << 2) | 1: ('msubaq', 'a'), (9 << 2) | 2: ('subai', 'a'), (9 << 2) | 3: ('msubai', 'a'),
    (10 << 2) | 0: ('adda', 'a'), (10 << 2) | 1: ('madda', 'a'), (10 << 2) | 2: ('mula', 'a'),
    (11 << 2) | 0: ('suba', 'a'), (11 << 2) | 1: ('msuba', 'a'), (11 << 2) | 2: ('opmula', 'a'), (11 << 2) | 3: ('nop', 'nop'),
})

LOWER_SPECIAL_FUNCT = {0x30: 'iadd', 0x31: 'isub', 0x32: 'iaddi', 0x34: 'iand', 0x35: 'ior'}
# (bits 10-6 << 2) | (bits 1-0) when bits 5-2 are 1111
LOWER_SPECIAL = {
    (0x0C << 2) | 0: 'move', (0x0C << 2) | 1: 'mr32', (0x0D << 2) | 0: 'lqi', (0x0D << 2) | 1: 'sqi',
    (0x0D << 2) | 2: 'lqd', (0x0D << 2) | 3: 'sqd', (0x0E << 2) | 0: 'div', (0x0E << 2) | 1: 'sqrt',
    (0x0E << 2) | 2: 'rsqrt', (0x0E << 2) | 3: 'waitq', (0x0F << 2) | 0: 'mtir', (0x0F << 2) | 1: 'mfir',
    (0x0F << 2) | 2: 'ilwr', (0x0F << 2) | 3: 'iswr', (0x19 << 2) | 0: 'mfp', (0x1A << 2) | 0: 'xtop',
    (0x1A << 2) | 1: 'xitop', (0x1B << 2) | 0: 'xgkick', (0x1C << 2) | 0: 'esadd', (0x1C << 2) | 1: 'ersadd',
    (0x1C << 2) | 2: 'eleng', (0x1C << 2) | 3: 'erleng', (0x1D << 2) | 0: 'eatanxy', (0x1D << 2) | 1: 'eatanxz',
    (0x1D << 2) | 2: 'esum', (0x1E << 2) | 0: 'esqrt', (0x1E << 2) | 1: 'ersqrt', (0x1E << 2) | 2: 'ercpr',
    (0x1E << 2) | 3: 'waitp', (0x1F << 2) | 0: 'esin', (0x1F << 2) | 1: 'eatan', (0x1F << 2) | 2: 'eexp',
}
LOWER_OP7 = {
    0x00: 'lq', 0x01: 'sq', 0x04: 'ilw', 0x05: 'isw', 0x08: 'iaddiu', 0x09: 'isubiu', 0x10: 'fceq', 0x11: 'fcset',
    0x12: 'fcand', 0x13: 'fcor', 0x14: 'fseq', 0x15: 'fsset', 0x16: 'fsand', 0x17: 'fsor', 0x18: 'fmeq',
    0x1A: 'fmand', 0x1B: 'fmor', 0x1C: 'fcget', 0x20: 'b', 0x21: 'bal', 0x24: 'jr', 0x25: 'jalr', 0x28: 'ibeq',
    0x29: 'ibne', 0x2C: 'ibltz', 0x2D: 'ibgtz', 0x2E: 'iblez', 0x2F: 'ibgez',
}


def signed(value, bits):
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def dest_mask(word):
    return ''.join(FIELDS[index] for index in range(4) if word & (1 << (24 - index)))


def decode_upper(word):
    dest = dest_mask(word)
    ft, fs, fd = (word >> 16) & 31, (word >> 11) & 31, (word >> 6) & 31
    funct = word & 63
    suffix = '.' + dest if dest else ''
    if funct < 0x1C:
        name = UPPER_BROADCAST[funct >> 2] + 'xyzw'[funct & 3]
        return f'{name}{suffix} vf{fd}, vf{fs}, vf{ft}{"xyzw"[funct & 3]}'
    if funct in UPPER_FUNCT:
        name, kind = UPPER_FUNCT[funct]
        operand = {'q': 'Q', 'i': 'I', 'v': f'vf{ft}'}[kind]
        return f'{name}{suffix} vf{fd}, vf{fs}, {operand}'
    if funct >= 0x3C:
        op11 = ((word >> 6) & 31) << 2 | (word & 3)
        if op11 not in UPPER_SPECIAL:
            return f'.upper_unknown {word:#010x}'
        name, kind = UPPER_SPECIAL[op11]
        if kind == 'nop':
            return 'nop'
        if kind == 'ft':
            return f'{name}{suffix} vf{ft}, vf{fs}'
        if kind == 'clip':
            return f'clipw{suffix} vf{fs}, vf{ft}'
        if name[-1] in 'xyzw' and name.startswith(('adda', 'suba', 'madda', 'msuba', 'mula')) and name[-1] != 'a':
            return f'{name}{suffix} ACC, vf{fs}, vf{ft}{name[-1]}'
        operand = {'q': 'Q', 'i': 'I'}.get(name[-1], f'vf{ft}') if name.endswith(('q', 'i')) else f'vf{ft}'
        return f'{name}{suffix} ACC, vf{fs}, {operand}'
    return f'.upper_unknown {word:#010x}'


def decode_lower(word, index):
    """Returns the text of a lower instruction; index is the instruction's own index (for branch targets)."""
    op7 = word >> 25
    dest = dest_mask(word)
    suffix = '.' + dest if dest else ''
    it, is_, id_ = (word >> 16) & 31, (word >> 11) & 31, (word >> 6) & 31
    imm11 = signed(word & 0x7FF, 11)
    if word == 0x8000033C:
        return 'nop'
    if op7 == 0x40:
        funct = word & 63
        if funct in LOWER_SPECIAL_FUNCT:
            name = LOWER_SPECIAL_FUNCT[funct]
            if name == 'iaddi':
                return f'iaddi vi{it}, vi{is_}, {signed(id_, 5)}'
            return f'{name} vi{id_}, vi{is_}, vi{it}'
        if funct >= 0x3C:
            op11 = ((word >> 6) & 31) << 2 | (word & 3)
            name = LOWER_SPECIAL.get(op11)
            ftf, fsf = (word >> 23) & 3, (word >> 21) & 3
            if name is None:
                return f'.lower_unknown {word:#010x}'
            if name in ('move', 'mr32'):
                return f'{name}{suffix} vf{it}, vf{is_}'
            if name == 'lqi':
                return f'lqi{suffix} vf{it}, (vi{is_}++)'
            if name == 'lqd':
                return f'lqd{suffix} vf{it}, (--vi{is_})'
            if name == 'sqi':
                return f'sqi{suffix} vf{is_}, (vi{it}++)'
            if name == 'sqd':
                return f'sqd{suffix} vf{is_}, (--vi{it})'
            if name in ('div', 'rsqrt'):
                return f'{name} Q, vf{is_}{FIELDS[fsf]}, vf{it}{FIELDS[ftf]}'
            if name == 'sqrt':
                return f'sqrt Q, vf{it}{FIELDS[ftf]}'
            if name in ('waitq', 'waitp'):
                return name
            if name == 'mtir':
                return f'mtir vi{it}, vf{is_}{FIELDS[fsf]}'
            if name == 'mfir':
                return f'mfir{suffix} vf{it}, vi{is_}'
            if name in ('ilwr', 'iswr'):
                return f'{name}{suffix} vi{it}, (vi{is_})'
            if name == 'mfp':
                return f'mfp{suffix} vf{it}, P'
            if name in ('xtop', 'xitop'):
                return f'{name} vi{it}'
            if name == 'xgkick':
                return f'xgkick vi{is_}'
            if name in ('esadd', 'ersadd', 'eleng', 'erleng', 'eatanxy', 'eatanxz', 'esum'):
                return f'{name} P, vf{is_}'
            return f'{name} P, vf{is_}{FIELDS[fsf]}'
        return f'.lower_unknown {word:#010x}'
    name = LOWER_OP7.get(op7)
    if name is None:
        return f'.lower_unknown {word:#010x}'
    imm15 = ((word >> 21) & 15) << 11 | (word & 0x7FF)
    if name == 'lq':
        return f'lq{suffix} vf{it}, {imm11}(vi{is_})'
    if name == 'sq':
        return f'sq{suffix} vf{is_}, {imm11}(vi{it})'
    if name in ('ilw', 'isw'):
        return f'{name}{suffix} vi{it}, {imm11}(vi{is_})'
    if name in ('iaddiu', 'isubiu'):
        return f'{name} vi{it}, vi{is_}, {imm15}'
    if name in ('fcset', 'fcand', 'fceq', 'fcor'):
        return f'{name} {word & 0xFFFFFF:#x}'
    if name in ('fsand', 'fseq', 'fsor', 'fsset'):
        return f'{name} vi{it}, {(imm15 & 0xFFF):#x}'
    if name in ('fmand', 'fmeq', 'fmor'):
        return f'{name} vi{it}, vi{is_}'
    if name == 'fcget':
        return f'fcget vi{it}'
    target = index + 1 + imm11
    if name == 'b':
        return f'b L{target}'
    if name == 'bal':
        return f'bal vi{it}, L{target}'
    if name == 'jr':
        return f'jr vi{is_}'
    if name == 'jalr':
        return f'jalr vi{it}, vi{is_}'
    if name in ('ibeq', 'ibne'):
        return f'{name} vi{it}, vi{is_}, L{target}'
    return f'{name} vi{is_}, L{target}'


def disassemble(data, base_label):
    """Yields (index, text, targets) per instruction pair."""
    count = len(data) // 8
    rows = []
    targets = set()
    for index in range(count):
        lower, upper = struct.unpack_from('<II', data, index * 8)
        flags = ''.join(letter for letter, bit in zip('iemdt', (31, 30, 29, 28, 27)) if upper & (1 << bit))
        upper_text = decode_upper(upper)
        if upper & (1 << 31):
            lower_text = f'loi {struct.unpack("<f", struct.pack("<I", lower))[0]!r}'
        else:
            lower_text = decode_lower(lower, index)
            if ' L' in lower_text:
                targets.add(int(lower_text.rsplit('L', 1)[1]))
        rows.append((index, flags, upper_text, lower_text, upper & (1 << 30) != 0))
    return rows, targets


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('executable')
    parser.add_argument('--out')
    parser.add_argument('--section', help='one section only (default: .vutext and every .DVP.overlay* section)')
    arguments = parser.parse_args()
    from elftools.elf.elffile import ELFFile
    elf = ELFFile(open(arguments.executable, 'rb'))
    output = open(arguments.out, 'w') if arguments.out else sys.stdout
    for section in elf.iter_sections():
        wanted = section.name == '.vutext' or section.name.startswith('.DVP.overlay.')
        if arguments.section:
            wanted = section.name == arguments.section
        if not wanted:
            continue
        data = section.data()
        rows, targets = disassemble(data, section.name)
        print(f'# {section.name}: {len(data)} bytes, {len(rows)} instructions', file=output)
        program_start = 0
        pending_end = None
        for index, flags, upper_text, lower_text, end_bit in rows:
            if index in targets:
                print(f'L{index}:', file=output)
            if pending_end is not None and index == pending_end:
                print(f'# end of program (started at {program_start})', file=output)
                program_start = index
                pending_end = None
            print(f'  {index:5d}  {index * 8:#07x}  {upper_text:<44s} | {lower_text:<40s} {("[" + flags + "]") if flags else ""}', file=output)
            if end_bit:
                pending_end = index + 2
        print(file=output)


if __name__ == '__main__':
    main()
