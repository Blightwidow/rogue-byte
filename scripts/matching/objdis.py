#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""objdis.py <file.o> [symbol]: EE-aware disassembly of an object's .text (llvm-objdump + EE fixups), one line per insn:
   offset word text   (relocations appended as ' ; R:<sym>')"""
import os, sys, subprocess, re
LAB = os.environ.get('ROGUE_BYTE_DIR') or os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from eedecode import fix
PORT = os.environ.get('GAME_DIR') or os.path.join(LAB, 'work', 'game')
path = sys.argv[1]; sym = sys.argv[2] if len(sys.argv) > 2 else None
out = subprocess.run(['/opt/homebrew/opt/llvm/bin/llvm-objdump', '-d', '-r', '--triple=mips64el', path], capture_output=True, text=True).stdout
cur = None; lines = []
for line in out.split('\n'):
    m = re.match(r'^[0-9a-f]+ <(.*)>:', line)
    if m: cur = m.group(1); lines.append(('LABEL', cur)); continue
    m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{2}) ([0-9a-f]{2}) ([0-9a-f]{2}) ([0-9a-f]{2})\s*(.*)', line)
    if m:
        word = int(m.group(5) + m.group(4) + m.group(3) + m.group(2), 16)
        lines.append(('INS', int(m.group(1), 16), word, fix(word, m.group(6).strip())))
        continue
    m = re.match(r'\s*[0-9a-f]+:\s+(R_\S+)\s+(\S+)', line)
    if m and lines and lines[-1][0] == 'INS':
        lines[-1] = lines[-1][:3] + (lines[-1][3] + ' ; R:' + m.group(1)[7:] + ':' + m.group(2),)
for entry in lines:
    if entry[0] == 'LABEL': print(entry[1] + ':')
    else: print('%5x: %08x  %s' % entry[1:])
