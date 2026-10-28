# SPDX-License-Identifier: GPL-3.0-or-later
"""vu_dis.py - disassembles VU micro-mode code (VU0 or VU1) from a raw code-memory dump.

  python3 scripts/decompile/vu_dis.py work/vu0_code.bin <start byte> <end byte>     (from the lab root, byte addresses in hex)

Each 64-bit instruction: lower word at +0, upper word at +4, little endian. Upper word flags: I (the lower word is a
float loaded into I), E (end: the next instruction still executes), M, D, T. Addresses and branch targets in bytes
(vcallms <imm>*8 lands on the same byte address).
"""
import struct
import sys

BROADCAST = 'xyzw'


def dest_mask(word):
    dest = (word >> 21) & 0xF
    return ''.join(lane for index, lane in enumerate('xyzw') if dest & (8 >> index))


def signed(value, bits):
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


UPPER_PRIMARY = {0x1c: 'mulq', 0x1d: 'maxi', 0x1e: 'muli', 0x1f: 'minii', 0x20: 'addq', 0x21: 'maddq', 0x22: 'addi',
                 0x23: 'maddi', 0x24: 'subq', 0x25: 'msubq', 0x26: 'subi', 0x27: 'msubi', 0x28: 'add', 0x29: 'madd',
                 0x2a: 'mul', 0x2b: 'max', 0x2c: 'sub', 0x2d: 'msub', 0x2e: 'opmsub', 0x2f: 'mini'}
UPPER_SPECIAL = {0x1c: 'mulaq', 0x1d: 'abs', 0x1e: 'mulai', 0x1f: 'clipw', 0x20: 'addaq', 0x21: 'maddaq', 0x22: 'addai',
                 0x23: 'maddai', 0x24: 'subaq', 0x25: 'msubaq', 0x26: 'subai', 0x27: 'msubai', 0x28: 'adda',
                 0x29: 'madda', 0x2a: 'mula', 0x2c: 'suba', 0x2d: 'msuba', 0x2e: 'opmula', 0x2f: 'nop'}


def upper(word):
    mask = dest_mask(word)
    ft = (word >> 16) & 31
    fs = (word >> 11) & 31
    fd = (word >> 6) & 31
    function = word & 0x3F
    if function < 0x1c:
        name = ['add', 'sub', 'madd', 'msub', 'max', 'mini', 'mul'][function >> 2] + BROADCAST[function & 3]
        return '%s.%s vf%02d, vf%02d, vf%02d%s' % (name, mask, fd, fs, ft, BROADCAST[function & 3])
    if function < 0x3c:
        name = UPPER_PRIMARY.get(function)
        if name is None:
            return 'upper?%#04x' % function
        if name in ('mulq', 'addq', 'subq', 'maddq', 'msubq'):
            return '%s.%s vf%02d, vf%02d, Q' % (name, mask, fd, fs)
        if name in ('maxi', 'muli', 'minii', 'addi', 'maddi', 'subi', 'msubi'):
            return '%s.%s vf%02d, vf%02d, I' % (name, mask, fd, fs)
        return '%s.%s vf%02d, vf%02d, vf%02d' % (name, mask, fd, fs, ft)
    index = (fd << 2) | (function & 3)
    if index < 0x10:
        name = ['adda', 'suba', 'madda', 'msuba'][index >> 2] + BROADCAST[index & 3]
        return '%s.%s ACC, vf%02d, vf%02d%s' % (name, mask, fs, ft, BROADCAST[index & 3])
    if index < 0x14:
        return 'itof%d.%s vf%02d, vf%02d' % ([0, 4, 12, 15][index & 3], mask, ft, fs)
    if index < 0x18:
        return 'ftoi%d.%s vf%02d, vf%02d' % ([0, 4, 12, 15][index & 3], mask, ft, fs)
    if index < 0x1c:
        return 'mula%s.%s ACC, vf%02d, vf%02d%s' % (BROADCAST[index & 3], mask, fs, ft, BROADCAST[index & 3])
    name = UPPER_SPECIAL.get(index)
    if name is None:
        return 'upper?special%#04x' % index
    if name == 'nop':
        return 'nop'
    if name == 'abs':
        return 'abs.%s vf%02d, vf%02d' % (mask, ft, fs)
    if name == 'clipw':
        return 'clipw.xyz vf%02d, vf%02dw' % (fs, ft)
    if name.endswith('q'):
        return '%s.%s ACC, vf%02d, Q' % (name, mask, fs)
    if name.endswith('i'):
        return '%s.%s ACC, vf%02d, I' % (name, mask, fs)
    return '%s.%s ACC, vf%02d, vf%02d' % (name, mask, fs, ft)


LOWER_SPECIAL = {0x30: 'move', 0x31: 'mr32', 0x34: 'lqi', 0x35: 'sqi', 0x36: 'lqd', 0x37: 'sqd', 0x38: 'div',
                 0x39: 'sqrt', 0x3a: 'rsqrt', 0x3b: 'waitq', 0x3c: 'mtir', 0x3d: 'mfir', 0x3e: 'ilwr', 0x3f: 'iswr',
                 0x40: 'rnext', 0x41: 'rget', 0x42: 'rinit', 0x43: 'rxor', 0x64: 'mfp', 0x68: 'xtop', 0x69: 'xitop',
                 0x6c: 'xgkick', 0x70: 'esadd', 0x71: 'ersadd', 0x72: 'eleng', 0x73: 'erleng', 0x74: 'eatanxy',
                 0x75: 'eatanxz', 0x76: 'esum', 0x78: 'esqrt', 0x79: 'ersqrt', 0x7a: 'ercpr', 0x7b: 'waitp',
                 0x7c: 'esin', 0x7d: 'eatan', 0x7e: 'eexp'}
BRANCHES = {0x20: 'b', 0x21: 'bal', 0x28: 'ibeq', 0x29: 'ibne', 0x2c: 'ibltz', 0x2d: 'ibgtz', 0x2e: 'iblez',
            0x2f: 'ibgez'}


def lower_special(word):
    mask = dest_mask(word)
    ft = (word >> 16) & 31
    fs = (word >> 11) & 31
    fsf = BROADCAST[(word >> 21) & 3]
    ftf = BROADCAST[(word >> 23) & 3]
    index = (((word >> 6) & 31) << 2) | (word & 3)
    name = LOWER_SPECIAL.get(index)
    if name is None:
        return 'lower?special%#04x' % index
    if name == 'move' and mask == '' and ft == 0 and fs == 0:
        return 'nop'
    if name in ('move', 'mr32'):
        return '%s.%s vf%02d, vf%02d' % (name, mask, ft, fs)
    if name == 'lqi':
        return 'lqi.%s vf%02d, (vi%02d++)' % (mask, ft, fs)
    if name == 'sqi':
        return 'sqi.%s vf%02d, (vi%02d++)' % (mask, fs, ft)
    if name == 'lqd':
        return 'lqd.%s vf%02d, (--vi%02d)' % (mask, ft, fs)
    if name == 'sqd':
        return 'sqd.%s vf%02d, (--vi%02d)' % (mask, fs, ft)
    if name == 'div':
        return 'div Q, vf%02d%s, vf%02d%s' % (fs, fsf, ft, ftf)
    if name == 'sqrt':
        return 'sqrt Q, vf%02d%s' % (ft, ftf)
    if name == 'rsqrt':
        return 'rsqrt Q, vf%02d%s, vf%02d%s' % (fs, fsf, ft, ftf)
    if name in ('waitq', 'waitp'):
        return name
    if name == 'mtir':
        return 'mtir vi%02d, vf%02d%s' % (ft, fs, fsf)
    if name == 'mfir':
        return 'mfir.%s vf%02d, vi%02d' % (mask, ft, fs)
    if name in ('ilwr', 'iswr'):
        return '%s.%s vi%02d, (vi%02d)' % (name, mask, ft, fs)
    if name in ('rnext', 'rget'):
        return '%s.%s vf%02d, R' % (name, mask, ft)
    if name in ('rinit', 'rxor'):
        return '%s R, vf%02d%s' % (name, fs, fsf)
    if name == 'mfp':
        return 'mfp.%s vf%02d, P' % (mask, ft)
    if name in ('xtop', 'xitop'):
        return '%s vi%02d' % (name, ft)
    if name == 'xgkick':
        return 'xgkick vi%02d' % fs
    if name in ('esadd', 'ersadd', 'eleng', 'erleng', 'eatanxy', 'eatanxz', 'esum'):
        return '%s P, vf%02d' % (name, fs)
    return '%s P, vf%02d%s' % (name, fs, fsf)


def lower(word, address):
    opcode = word >> 25
    mask = dest_mask(word)
    it = (word >> 16) & 31
    is_ = (word >> 11) & 31
    imm11 = signed(word & 0x7FF, 11)
    if opcode == 0x40:
        function = word & 0x3F
        if function >= 0x3c:
            return lower_special(word)
        id_ = (word >> 6) & 31
        if function == 0x30:
            return 'iadd vi%02d, vi%02d, vi%02d' % (id_, is_, it)
        if function == 0x31:
            return 'isub vi%02d, vi%02d, vi%02d' % (id_, is_, it)
        if function == 0x32:
            return 'iaddi vi%02d, vi%02d, %d' % (it, is_, signed(id_, 5))
        if function == 0x34:
            return 'iand vi%02d, vi%02d, vi%02d' % (id_, is_, it)
        if function == 0x35:
            return 'ior vi%02d, vi%02d, vi%02d' % (id_, is_, it)
        return 'lower?op%#04x' % function
    if opcode == 0x00:
        return 'lq.%s vf%02d, %d(vi%02d)' % (mask, it, imm11, is_)
    if opcode == 0x01:
        return 'sq.%s vf%02d, %d(vi%02d)' % (mask, is_, imm11, it)
    if opcode == 0x04:
        return 'ilw.%s vi%02d, %d(vi%02d)' % (mask, it, imm11, is_)
    if opcode == 0x05:
        return 'isw.%s vi%02d, %d(vi%02d)' % (mask, it, imm11, is_)
    if opcode in (0x08, 0x09):
        imm15 = ((word >> 10) & 0x7800) | (word & 0x7FF)
        return '%s vi%02d, vi%02d, %#x' % ('iaddiu' if opcode == 0x08 else 'isubiu', it, is_, imm15)
    if opcode in (0x10, 0x11, 0x12, 0x13):
        return '%s vi01, %#08x' % (['fceq', 'fcset', 'fcand', 'fcor'][opcode & 3], word & 0xFFFFFF)
    if opcode in (0x14, 0x15, 0x16, 0x17):
        imm12 = ((word >> 10) & 0x800) | (word & 0x7FF)
        name = ['fseq', 'fsset', 'fsand', 'fsor'][opcode & 3]
        return 'fsset %#05x' % imm12 if name == 'fsset' else '%s vi%02d, %#05x' % (name, it, imm12)
    if opcode in (0x18, 0x1a, 0x1b):
        return '%s vi%02d, vi%02d' % ({0x18: 'fmeq', 0x1a: 'fmand', 0x1b: 'fmor'}[opcode], it, is_)
    if opcode == 0x1c:
        return 'fcget vi%02d' % it
    if opcode in BRANCHES:
        name = BRANCHES[opcode]
        target = address + 8 + imm11 * 8
        if name == 'b':
            return 'b %#x' % target
        if name == 'bal':
            return 'bal vi%02d, %#x' % (it, target)
        if name in ('ibeq', 'ibne'):
            return '%s vi%02d, vi%02d, %#x' % (name, it, is_, target)
        return '%s vi%02d, %#x' % (name, is_, target)
    if opcode == 0x24:
        return 'jr vi%02d' % is_
    if opcode == 0x25:
        return 'jalr vi%02d, vi%02d' % (it, is_)
    return 'lower?%#04x' % opcode


def disassemble(code, start, end):
    lines = []
    for address in range(start & ~7, end, 8):
        lower_word, upper_word = struct.unpack_from('<II', code, address)
        flags = ''.join(flag for bit, flag in ((31, 'I'), (30, 'E'), (29, 'M'), (28, 'D'), (27, 'T'))
                        if upper_word & (1 << bit))
        upper_text = upper(upper_word)
        if upper_word & (1 << 31):
            lower_text = 'loi %r' % struct.unpack('<f', struct.pack('<I', lower_word))[0]
        else:
            lower_text = lower(lower_word, address)
        lines.append('%04x: %08x %08x %-5s %-40s %s' % (address, upper_word, lower_word,
                                                         '[%s]' % flags if flags else '', upper_text, lower_text))
    return lines


def main():
    if len(sys.argv) != 4:
        sys.exit(__doc__)
    code = open(sys.argv[1], 'rb').read()
    start, end = (int(argument, 16) for argument in sys.argv[2:4])
    print('\n'.join(disassemble(code, start, end)))


if __name__ == '__main__':
    main()
