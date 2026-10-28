#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""place_programs.py <trace dir> <trace log> <executable> - places the VU1 programs a run uploaded inside .vutext and lists their entry points.

  .venv/bin/python scripts/vu/place_programs.py work/ps2-web-recomp/games/sly2/vif-trace work/ps2-web-recomp/games/sly2/vif-trace/log3 work/elf/SCUS_973.16

Input is a run of the recompiler with scripts/swapin/patches/vif-trace.patch applied and VIF_TRACE=1: its log has one line per distinct VU
upload (MPG) and start (MSCAL, MSCNT) with the active program, and <trace dir>/chunks/ holds the uploaded bytes. Each uploaded chunk is found in
.vutext by comparing words; chunks that follow each other (VU1 address 0x0, 0x800, ...) form a program; a start address becomes an instruction
index in .vutext. Prints addresses and counts only."""
import collections
import glob
import os
import re
import struct
import sys
from elftools.elf.elffile import ELFFile
trace = sys.argv[1].rstrip('/') + '/'
elf = ELFFile(open(sys.argv[3], 'rb'))
vutext = elf.get_section_by_name('.vutext').data()
words = struct.unpack(f'<{len(vutext) // 8}Q', vutext)
def locate(chunk):
    count = len(chunk)
    for start in range(len(words) - count + 1):
        if tuple(words[start:start + count]) == chunk: return start
chunks = []  # (unit, dest, count, start, hash, times)
log = open(sys.argv[2], errors='replace').read()
times = {m[1]: int(m[2]) for m in re.finditer(r'upload unit=\d dest=[0-9A-F]+ instrs=\d+ hash=([0-9A-F]+) count=(\d+)', log) for m in [(0, m[1], m[2])]}
for path in glob.glob(trace + 'chunks/u1_*.bin'):
    m = re.match(r'u(\d)_([0-9A-F]+)_(\d+)_([0-9A-F]+)\.bin', os.path.basename(path))
    unit, dest, count, h = int(m[1]), int(m[2], 16), int(m[3]), m[4]
    chunks.append((unit, dest, count, locate(struct.unpack(f'<{count}Q', open(path, 'rb').read())), h, times.get(h, 0)))
# group: a program is the dest-0 chunk plus following chunks (dest > 0) whose vutext index follows within 2 instrs
chunks.sort(key=lambda c: c[3])
programs = []
for c in chunks:
    if c[1] == 0 or not programs or c[3] - (programs[-1][-1][3] + programs[-1][-1][2]) > 2 or c[1] != programs[-1][-1][1] + 0x800:
        programs.append([c])
    else:
        programs[-1].append(c)
starts = collections.defaultdict(list)
for m in re.finditer(r'start unit=1 op=(\w+) addr=([0-9A-F]+) program=([0-9A-F]+) count=(\d+)', log):
    starts[m[3][:8]].append((int(m[2], 16), int(m[1], 16), int(m[4])))
for program in programs:
    first = program[0]
    last = program[-1]
    span = (last[3] + last[2]) - first[3]
    print(f'program: vutext {first[3]}..{last[3] + last[2] - 1} ({span} instrs, {len(program)} chunk(s), VU1 {first[1]:#x}..{last[1] + last[2] * 8 - 1:#x}), uploaded {first[5]}x')
    for unit, dest, count, start, h, n in program: print(f'    chunk dest {dest:#06x} +{count:3d} = vutext {start}')
    for addr, op, n in sorted(set(starts.get(first[4][:8], []))):
        for unit, dest, count, start, h, k in program:
            if dest <= addr < dest + count * 8:
                print(f'    {"MSCAL" if op == 0x14 else "MSCNT"} {addr:#06x} -> vutext {start + (addr - dest) // 8:5d}  x{n}')
                break
        else:
            print(f'    {"MSCAL" if op == 0x14 else "MSCNT"} {addr:#06x} -> not in an uploaded chunk  x{n}')
