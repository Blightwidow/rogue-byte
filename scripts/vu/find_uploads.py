#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""find_uploads.py - where the executable's code points into the VU1 microcode (.vutext) and where it starts programs.

  python3 -I scripts/vu/find_uploads.py        (from the repository root, needs work/elf/SCUS_973.16)

Prints (1) every address inside .vutext that code (a `lui` + `addiu`/`ori` pair) or data (a pointer word) refers to, with the
function that does it: the references come in start/end pairs, one pair per uploaded program range; (2) VIF MSCAL, MSCALF and
MSCNT codes written as constants; (3) entry points built as `(VU byte address) >> 3 | command << 24`. Function names come from
data/matching/functions.tsv. Output is addresses and names only."""
import bisect, collections, struct, sys
VU_START, VU_SIZE = 0x259df0, 0x8540
VU_END = VU_START + VU_SIZE
data = open('work/elf/SCUS_973.16', 'rb').read()
TEXT_ADDR, TEXT_OFF, TEXT_SIZE = 0x100000, 0x80, 0x159df0
functions = []
for line in list(open('data/matching/functions.tsv'))[1:]:
    parts = line.split('\t'); functions.append((int(parts[0], 16), parts[1]))
functions.sort()
starts = [address for address, _ in functions]
def owner(address):
    index = bisect.bisect_right(starts, address) - 1
    return functions[index][1] if index >= 0 else '?'
words = struct.unpack_from(f'<{TEXT_SIZE // 4}I', data, TEXT_OFF)
def signed16(value): return value - 0x10000 if value & 0x8000 else value
hits = collections.defaultdict(list)
for index, word in enumerate(words):
    if word >> 26 != 0x0F: continue
    register, high = (word >> 16) & 31, word & 0xFFFF
    for ahead in range(1, 9):
        if index + ahead >= len(words): break
        follow = words[index + ahead]
        opcode, rs, rt, immediate = follow >> 26, (follow >> 21) & 31, (follow >> 16) & 31, follow & 0xFFFF
        if rs == register and opcode in (0x09, 0x0D):
            value = (high << 16) + (signed16(immediate) if opcode == 0x09 else immediate)
            value &= 0xFFFFFFFF
            if VU_START <= value < VU_END:
                hits[value].append((TEXT_ADDR + index * 4, owner(TEXT_ADDR + index * 4)))
        if rt == register and opcode not in (0x09, 0x0D): break
# data words (pointers in .rodata/.data)
for name, address, offset, size in (('rodata', 0x262380, 0x162400, 0x4a4e4), ('data', 0x2ac880, 0x1ac900, 0x309b0)):
    for position in range(0, size - 3, 4):
        value = struct.unpack_from('<I', data, offset + position)[0]
        if VU_START <= value < VU_END:
            hits[value].append((address + position, f'<{name}>'))
print('distinct vutext addresses referenced:', len(hits))
for value in sorted(hits):
    offset = value - VU_START
    print(f'{value:#x} +{offset:#06x} (instr {offset // 8}{"" if offset % 8 == 0 else " MISALIGNED"}):', '; '.join(f'{where:#x} {who}' for where, who in hits[value][:4]))

print('--- MSCAL (0x14) / MSCALF (0x15) / MSCNT (0x17) VIF codes')
found = collections.defaultdict(list)
# code: lui rt, 0x14xx|0x15xx|0x17xx then ori/addiu
for index, word in enumerate(words):
    if word >> 26 != 0x0F: continue
    register, high = (word >> 16) & 31, word & 0xFFFF
    if (high >> 8) not in (0x14, 0x15, 0x17): continue
    for ahead in range(1, 7):
        if index + ahead >= len(words): break
        follow = words[index + ahead]
        if (follow >> 26) in (0x09, 0x0D) and ((follow >> 21) & 31) == register:
            value = ((high << 16) | (follow & 0xFFFF)) & 0xFFFFFFFF
            found[value].append((TEXT_ADDR + index * 4, owner(TEXT_ADDR + index * 4), 'code')); break
    else:
        found[high << 16].append((TEXT_ADDR + index * 4, owner(TEXT_ADDR + index * 4), 'code-hi-only'))
# the commonly written form: ori rt, zero, imm after lui is common; also bare `addiu` with cmd in a register built otherwise
for name, address, offset, size in (('rodata', 0x262380, 0x162400, 0x4a4e4), ('data', 0x2ac880, 0x1ac900, 0x309b0)):
    for position in range(0, size - 3, 4):
        value = struct.unpack_from('<I', data, offset + position)[0]
        if (value >> 24) in (0x14, 0x15, 0x17) and (value & 0x00FF0000) == 0 and (value & 0xFFFF) < 0x400:
            found[value].append((address + position, f'<{name}>', 'data'))
for value in sorted(found):
    command = {0x14: 'MSCAL', 0x15: 'MSCALF', 0x17: 'MSCNT'}[value >> 24]
    address = (value & 0xFFFF) * 8
    print(f'{command} imm={value & 0xFFFF:#06x} (byte {address:#06x}, instr {address // 8}):', '; '.join(f'{w:#x} {who} {kind}' for w, who, kind in found[value][:3]))

print('--- entry points: (lui/addiu constant) >> 3 | 0x14/15/17 << 24')
def constant_before(index, register, limit=14):
    """Walks back from index for the value loaded into register by lui/addiu/ori (unrelocated hi may be 0)."""
    low = None
    for back in range(1, limit):
        j = index - back
        word = words[j]
        opcode, rs, rt, immediate = word >> 26, (word >> 21) & 31, (word >> 16) & 31, word & 0xFFFF
        if rt != register: continue
        if opcode == 0x0F:
            return ((immediate << 16) + (low or 0)) & 0xFFFFFFFF
        if opcode in (0x09, 0x0D) and rs == register and low is None:
            low = signed16(immediate) if opcode == 0x09 else immediate
            continue
        if opcode in (0x09, 0x0D) and rs == 0:
            return signed16(immediate) if opcode == 0x09 else immediate
        return None
    return None
entries = collections.defaultdict(list)
for index, word in enumerate(words):
    # srl rd, rt, 3 : special, funct 0, shamt 3
    if word >> 26 == 0 and (word & 0x3F) == 2 and ((word >> 6) & 31) == 3:
        rd, rt = (word >> 11) & 31, (word >> 16) & 31
        for ahead in range(1, 5):
            follow = words[index + ahead]
            if follow >> 26 == 0 and (follow & 0x3F) == 0x25:  # or
                a, b = (follow >> 21) & 31, (follow >> 16) & 31
                other = b if a == rd else a if b == rd else None
                if other is None: continue
                command = constant_before(index + ahead, other)
                if command is not None and (command >> 24) in (0x14, 0x15, 0x17) and (command & 0xFFFFFF) == 0:
                    value = constant_before(index, rt)
                    entries[owner(TEXT_ADDR + index * 4)].append((command >> 24, value, TEXT_ADDR + index * 4))
                break
for function in sorted(entries, key=lambda name: min(a for _, _, a in entries[name])):
    shown = ', '.join(f'{ {0x14: "MSCAL", 0x15: "MSCALF", 0x17: "MSCNT"}[cmd] }@{(value or 0) >> 3}' if value is not None else f'{ {0x14: "MSCAL", 0x15: "MSCALF", 0x17: "MSCNT"}[cmd] }@?' for cmd, value, _ in entries[function])
    print(f'{function} ({min(a for _, _, a in entries[function]):#x}): {shown}')
print('functions with entries:', len(entries))
