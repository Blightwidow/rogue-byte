#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""vuasm.py - assembler for the VU micro-instruction text of vudis.py, and the proof that the text rebuilds the microcode byte for byte.

  .venv/bin/python scripts/vu/vuasm.py verify work/elf/SCUS_973.16               every instruction of .vutext round-trips
  .venv/bin/python scripts/vu/vuasm.py source work/elf/SCUS_973.16 OUT.vu        write the verified source (generated: keep it in work/)
  .venv/bin/python scripts/vu/vuasm.py assemble IN.vu OUT.bin                     assemble a source file

A source line is `upper | lower [flags]` (flags: letters of i e m d t) or `.vu 0xLOWER 0xUPPER` for an instruction whose text does not
reassemble to the same bits (the disassembler leaves some fields out: they are zero in compiler-made code but arbitrary in a hand-written
program), `Ln:` for a branch target (n is the instruction index; branch operands name it), and `#` starts a comment. The leading
`index address` columns of vudis.py's listing are ignored, so its output can be assembled too.

`source` writes only lines that were checked: each instruction is assembled back and compared with the bytes it came from, and falls back
to `.vu` when it differs. The assembler is the inverse of the tables in vudis.py, so a change there changes both."""
import argparse
import re
import struct
import sys

import vudis

FIELDS = 'xyzw'
FLAG_BITS = {'i': 31, 'e': 30, 'm': 29, 'd': 28, 't': 27}


class AssemblyError(ValueError):
    pass


def dest_bits(text):
    """Bits 24..21 for a destination mask string like `xyz`; None for no mask."""
    if not text:
        return 0
    if any(letter not in FIELDS for letter in text) or list(text) != sorted(text, key=FIELDS.index):
        raise AssemblyError(f'bad destination {text!r}')
    return sum(1 << (24 - FIELDS.index(letter)) for letter in text)


def register(text, prefix):
    match = re.fullmatch(rf'{prefix}(\d+)', text.strip())
    if not match or int(match.group(1)) > 31:
        raise AssemblyError(f'expected {prefix}N, got {text!r}')
    return int(match.group(1))


def split_operands(text):
    return [part.strip() for part in text.split(',')] if text.strip() else []


def mnemonic_of(text):
    """(name, destination letters, operand text)."""
    match = re.fullmatch(r'(\S+?)(?:\.([xyzw]+))?(?:\s+(.*))?', text.strip())
    if not match:
        raise AssemblyError(f'cannot read {text!r}')
    return match.group(1), match.group(2) or '', match.group(3) or ''


UPPER_FUNCT_BY_NAME = {name: (funct, kind) for funct, (name, kind) in vudis.UPPER_FUNCT.items()}
UPPER_BROADCAST_BY_NAME = {name + letter: (index * 4 + position) for index, name in enumerate(vudis.UPPER_BROADCAST) for position, letter in enumerate(FIELDS)}
UPPER_SPECIAL_BY_NAME = {}
for _op11, (_name, _kind) in vudis.UPPER_SPECIAL.items():
    UPPER_SPECIAL_BY_NAME.setdefault(_name, (_op11, _kind))
LOWER_SPECIAL_FUNCT_BY_NAME = {name: funct for funct, name in vudis.LOWER_SPECIAL_FUNCT.items()}
LOWER_SPECIAL_BY_NAME = {name: op11 for op11, name in vudis.LOWER_SPECIAL.items()}
LOWER_OP7_BY_NAME = {name: op7 for op7, name in vudis.LOWER_OP7.items()}


def special_upper(op11):
    return ((op11 >> 2) << 6) | (op11 & 3) | 0x3C


def assemble_upper(text):
    """The 32-bit upper word (flags not included) for the text of vudis.decode_upper."""
    text = text.strip()
    if text.startswith('.upper_unknown'):
        return int(text.split()[1], 0)
    if text == 'nop':
        return special_upper(UPPER_SPECIAL_BY_NAME['nop'][0])
    name, dest, operands = mnemonic_of(text)
    mask = dest_bits(dest)
    parts = split_operands(operands)
    if name in UPPER_BROADCAST_BY_NAME and len(parts) == 3:
        fd, fs = register(parts[0], 'vf'), register(parts[1], 'vf')
        match = re.fullmatch(r'vf(\d+)([xyzw])', parts[2])
        if not match or match.group(2) != name[-1]:
            raise AssemblyError(f'bad broadcast operand in {text!r}')
        return mask | int(match.group(1)) << 16 | fs << 11 | fd << 6 | UPPER_BROADCAST_BY_NAME[name]
    if name in UPPER_FUNCT_BY_NAME and parts and parts[0].startswith('vf'):
        funct, kind = UPPER_FUNCT_BY_NAME[name]
        fd, fs = register(parts[0], 'vf'), register(parts[1], 'vf')
        if kind == 'v':
            ft = register(parts[2], 'vf')
        elif parts[2] == {'q': 'Q', 'i': 'I'}[kind]:
            ft = 0
        else:
            raise AssemblyError(f'bad operand in {text!r}')
        return mask | ft << 16 | fs << 11 | fd << 6 | funct
    if name == 'clipw':
        return mask | register(parts[1], 'vf') << 16 | register(parts[0], 'vf') << 11 | special_upper(UPPER_SPECIAL_BY_NAME['clip'][0])
    if name in UPPER_SPECIAL_BY_NAME:
        op11, kind = UPPER_SPECIAL_BY_NAME[name]
        if kind == 'ft':
            return mask | register(parts[0], 'vf') << 16 | register(parts[1], 'vf') << 11 | special_upper(op11)
        if kind == 'a' and parts and parts[0] == 'ACC':
            fs = register(parts[1], 'vf')
            operand = parts[2]
            if operand in ('Q', 'I'):
                ft = 0
            else:
                match = re.fullmatch(r'vf(\d+)([xyzw]?)', operand)
                if not match:
                    raise AssemblyError(f'bad operand in {text!r}')
                ft = int(match.group(1))
            return mask | ft << 16 | fs << 11 | special_upper(op11)
    raise AssemblyError(f'unknown upper instruction {text!r}')


def signed_field(value, bits):
    low, high = -(1 << (bits - 1)), (1 << (bits - 1)) - 1
    if not low <= value <= high:
        raise AssemblyError(f'{value} does not fit {bits} signed bits')
    return value & ((1 << bits) - 1)


def parse_target(text, index):
    match = re.fullmatch(r'L(\d+)', text.strip())
    if not match:
        raise AssemblyError(f'bad branch target {text!r}')
    return signed_field(int(match.group(1)) - (index + 1), 11)


def special_lower(op11, extra=0):
    return 0x40 << 25 | ((op11 >> 2) << 6) | (op11 & 3) | 0x3C | extra


def field_letter(text):
    match = re.fullmatch(r'vf(\d+)([xyzw])', text.strip())
    if not match:
        raise AssemblyError(f'bad field operand {text!r}')
    return int(match.group(1)), FIELDS.index(match.group(2))


def assemble_lower(text, index):
    """The 32-bit lower word for the text of vudis.decode_lower at instruction `index`."""
    text = text.strip()
    if text.startswith('.lower_unknown'):
        return int(text.split()[1], 0)
    if text == 'nop':
        return 0x8000033C
    name, dest, operands = mnemonic_of(text)
    mask = dest_bits(dest)
    parts = split_operands(operands)
    if name in LOWER_SPECIAL_FUNCT_BY_NAME:
        funct = LOWER_SPECIAL_FUNCT_BY_NAME[name]
        if name == 'iaddi':
            return 0x40 << 25 | register(parts[0], 'vi') << 16 | register(parts[1], 'vi') << 11 | signed_field(int(parts[2], 0), 5) << 6 | funct
        return 0x40 << 25 | register(parts[2], 'vi') << 16 | register(parts[1], 'vi') << 11 | register(parts[0], 'vi') << 6 | funct
    if name in LOWER_SPECIAL_BY_NAME:
        op11 = LOWER_SPECIAL_BY_NAME[name]
        if name in ('move', 'mr32'):
            return special_lower(op11, mask | register(parts[0], 'vf') << 16 | register(parts[1], 'vf') << 11)
        if name == 'lqi':
            return special_lower(op11, mask | register(parts[0], 'vf') << 16 | register(re.fullmatch(r'\((vi\d+)\+\+\)', parts[1]).group(1), 'vi') << 11)
        if name == 'lqd':
            return special_lower(op11, mask | register(parts[0], 'vf') << 16 | register(re.fullmatch(r'\(--(vi\d+)\)', parts[1]).group(1), 'vi') << 11)
        if name == 'sqi':
            return special_lower(op11, mask | register(re.fullmatch(r'\((vi\d+)\+\+\)', parts[1]).group(1), 'vi') << 16 | register(parts[0], 'vf') << 11)
        if name == 'sqd':
            return special_lower(op11, mask | register(re.fullmatch(r'\(--(vi\d+)\)', parts[1]).group(1), 'vi') << 16 | register(parts[0], 'vf') << 11)
        if name in ('div', 'rsqrt'):
            fs, fsf = field_letter(parts[1])
            ft, ftf = field_letter(parts[2])
            return special_lower(op11, ftf << 23 | fsf << 21 | ft << 16 | fs << 11)
        if name == 'sqrt':
            ft, ftf = field_letter(parts[1])
            return special_lower(op11, ftf << 23 | ft << 16)
        if name in ('waitq', 'waitp'):
            return special_lower(op11)
        if name == 'mtir':
            fs, fsf = field_letter(parts[1])
            return special_lower(op11, fsf << 21 | register(parts[0], 'vi') << 16 | fs << 11)
        if name == 'mfir':
            return special_lower(op11, mask | register(parts[0], 'vf') << 16 | register(parts[1], 'vi') << 11)
        if name in ('ilwr', 'iswr'):
            return special_lower(op11, mask | register(parts[0], 'vi') << 16 | register(re.fullmatch(r'\((vi\d+)\)', parts[1]).group(1), 'vi') << 11)
        if name == 'mfp':
            return special_lower(op11, mask | register(parts[0], 'vf') << 16)
        if name in ('xtop', 'xitop'):
            return special_lower(op11, register(parts[0], 'vi') << 16)
        if name == 'xgkick':
            return special_lower(op11, register(parts[0], 'vi') << 11)
        if name in ('esadd', 'ersadd', 'eleng', 'erleng', 'eatanxy', 'eatanxz', 'esum'):
            return special_lower(op11, register(parts[1], 'vf') << 11)
        fs, fsf = field_letter(parts[1])  # the e-instructions that name a field
        return special_lower(op11, fsf << 21 | fs << 11)
    if name in LOWER_OP7_BY_NAME:
        op7 = LOWER_OP7_BY_NAME[name] << 25
        if name == 'lq':
            offset = re.fullmatch(r'(-?\d+)\((vi\d+)\)', parts[1])
            return op7 | mask | register(parts[0], 'vf') << 16 | register(offset.group(2), 'vi') << 11 | signed_field(int(offset.group(1)), 11)
        if name == 'sq':
            offset = re.fullmatch(r'(-?\d+)\((vi\d+)\)', parts[1])
            return op7 | mask | register(offset.group(2), 'vi') << 16 | register(parts[0], 'vf') << 11 | signed_field(int(offset.group(1)), 11)
        if name in ('ilw', 'isw'):
            offset = re.fullmatch(r'(-?\d+)\((vi\d+)\)', parts[1])
            return op7 | mask | register(parts[0], 'vi') << 16 | register(offset.group(2), 'vi') << 11 | signed_field(int(offset.group(1)), 11)
        if name in ('iaddiu', 'isubiu'):
            imm = int(parts[2], 0)
            if not 0 <= imm < 1 << 15:
                raise AssemblyError('immediate out of range')
            return op7 | register(parts[0], 'vi') << 16 | register(parts[1], 'vi') << 11 | ((imm >> 11) & 15) << 21 | (imm & 0x7FF)
        if name in ('fcset', 'fcand', 'fceq', 'fcor'):
            return op7 | int(parts[0], 0)
        if name in ('fsand', 'fseq', 'fsor', 'fsset'):
            imm = int(parts[1], 0)
            return op7 | register(parts[0], 'vi') << 16 | ((imm >> 11) & 1) << 21 | (imm & 0x7FF)
        if name in ('fmand', 'fmeq', 'fmor'):
            return op7 | register(parts[0], 'vi') << 16 | register(parts[1], 'vi') << 11
        if name == 'fcget':
            return op7 | register(parts[0], 'vi') << 16
        if name == 'b':
            return op7 | parse_target(parts[0], index)
        if name == 'bal':
            return op7 | register(parts[0], 'vi') << 16 | parse_target(parts[1], index)
        if name == 'jr':
            return op7 | register(parts[0], 'vi') << 11
        if name == 'jalr':
            return op7 | register(parts[0], 'vi') << 16 | register(parts[1], 'vi') << 11
        if name in ('ibeq', 'ibne'):
            return op7 | register(parts[0], 'vi') << 16 | register(parts[1], 'vi') << 11 | parse_target(parts[2], index)
        return op7 | register(parts[0], 'vi') << 11 | parse_target(parts[1], index)
    raise AssemblyError(f'unknown lower instruction {text!r}')


def assemble_loi(text):
    match = re.fullmatch(r'loi\s+(\S+)', text.strip())
    if not match:
        raise AssemblyError(f'bad loi {text!r}')
    return struct.unpack('<I', struct.pack('<f', float(match.group(1))))[0]


def assemble_pair(upper_text, lower_text, flags, index):
    """(lower word, upper word) of one instruction pair."""
    upper = assemble_upper(upper_text)
    for letter in flags:
        upper |= 1 << FLAG_BITS[letter]
    lower = assemble_loi(lower_text) if 'i' in flags else assemble_lower(lower_text, index)
    return lower, upper


def source_lines(data):
    """Source lines for a block of microcode: text where it reassembles to the same bits, `.vu` where it does not. Returns (lines, raw count)."""
    rows, targets = vudis.disassemble(data, '')
    lines = []
    raw = 0
    for index, flags, upper_text, lower_text, _end in rows:
        if index in targets:
            lines.append(f'L{index}:')
        lower, upper = struct.unpack_from('<II', data, index * 8)
        try:
            same = assemble_pair(upper_text, lower_text, flags, index) == (lower, upper)
        except (AssemblyError, AttributeError, ValueError, IndexError, struct.error):
            same = False
        if same:
            lines.append(f'  {upper_text:<44s} | {lower_text:<40s}{(" [" + flags + "]") if flags else ""}'.rstrip())
        else:
            raw += 1
            lines.append(f'  .vu {lower:#010x} {upper:#010x}')
    return lines, raw


LINE = re.compile(r'^\s*(?:\d+\s+0x[0-9a-fA-F]+\s+)?(?P<upper>[^|]+?)\s*\|\s*(?P<lower>[^\[]+?)\s*(?:\[(?P<flags>[iemdt]*)\])?\s*$')


def assemble(text):
    """The microcode bytes of a source text."""
    out = bytearray()
    for number, line in enumerate(text.split('\n'), 1):
        line = line.split('#')[0].rstrip()
        if not line.strip() or re.fullmatch(r'L\d+:', line.strip()):
            continue
        index = len(out) // 8
        try:
            raw = re.fullmatch(r'\s*\.vu\s+(\S+)\s+(\S+)', line)
            if raw:
                lower, upper = int(raw.group(1), 0), int(raw.group(2), 0)
            else:
                match = LINE.match(line)
                if not match:
                    raise AssemblyError('not an instruction line')
                lower, upper = assemble_pair(match.group('upper'), match.group('lower'), match.group('flags') or '', index)
        except (AssemblyError, AttributeError, ValueError, KeyError) as error:
            raise AssemblyError(f'line {number}: {error}') from error
        out += struct.pack('<II', lower, upper)
    return bytes(out)


def sections(executable):
    from elftools.elf.elffile import ELFFile
    with open(executable, 'rb') as handle:
        elf = ELFFile(handle)
        return [(section.name, section.data()) for section in elf.iter_sections() if section.name == '.vutext' or section.name.startswith('.DVP.overlay.')]


def verify(arguments):
    failed = False
    for name, data in sections(arguments.executable):
        lines, raw = source_lines(data)
        rebuilt = assemble('\n'.join(lines))
        same = rebuilt == data
        failed |= not same
        print(f'{name}: {len(data) // 8} instructions, {raw} kept as .vu, rebuilt {"identical" if same else "DIFFERENT"}')
    return 1 if failed else 0


def write_source(arguments):
    with open(arguments.output, 'w', encoding='utf-8') as out:
        for name, data in sections(arguments.executable):
            lines, raw = source_lines(data)
            out.write(f'# {name}: {len(data) // 8} instructions, {raw} as .vu\n' + '\n'.join(lines) + '\n\n')
    return 0


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest='command', required=True)
    checker = sub.add_parser('verify')
    checker.add_argument('executable')
    writer = sub.add_parser('source')
    writer.add_argument('executable')
    writer.add_argument('output')
    assembler = sub.add_parser('assemble')
    assembler.add_argument('input')
    assembler.add_argument('output')
    arguments = parser.parse_args()
    if arguments.command == 'verify':
        return verify(arguments)
    if arguments.command == 'source':
        return write_source(arguments)
    with open(arguments.input, encoding='utf-8') as handle:
        data = assemble(handle.read())
    with open(arguments.output, 'wb') as handle:
        handle.write(data)
    return 0


if __name__ == '__main__':
    sys.exit(main())
