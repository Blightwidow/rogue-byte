#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""fdiff.py <obj.o> <symbol> <sly2 hex addr> [elf]: side-by-side diff of a compiled function vs the binary."""
import tempfile
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from match import load_target, object_functions
from eedecode import fix
import subprocess
LAB = os.environ.get('ROGUE_BYTE_DIR') or os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
PORT = os.environ.get('GAME_DIR') or os.path.join(LAB, 'work', 'game')
path, symbol, address = sys.argv[1], sys.argv[2], int(sys.argv[3], 16)
if os.path.isdir(path):  # a build directory: find the object defining the symbol
    import glob
    path = next(candidate for candidate in sorted(glob.glob(path + '/*.o')) if any(entry[0] == symbol for entry in object_functions(candidate)))
elf = sys.argv[4] if len(sys.argv) > 4 else LAB + '/work/elf/SCUS_973.16'
word_at = load_target(elf)
def text_of(word):
    blob = open(os.path.join(tempfile.gettempdir(), 'fd_word.bin'), 'wb'); blob.write(word.to_bytes(4, 'little')); blob.close()
    output = subprocess.run(['/opt/homebrew/opt/llvm/bin/llvm-mc', '--disassemble', '-triple=mips64el', '-mcpu=mips3'], input='0x%02x 0x%02x 0x%02x 0x%02x' % tuple(word.to_bytes(4, 'little')), capture_output=True, text=True).stdout
    lines = [line.strip() for line in output.split('\n') if line.strip() and not line.strip().startswith('.')]
    return fix(word, lines[0] if lines else '?')
for name, words, masks in object_functions(path):
    if name != symbol: continue
    for position, word in enumerate(words):
        target = word_at(address + 4 * position)
        same = (word & masks[position]) == (target & masks[position])
        print('%s %3x  %-34s | %s' % ('  ' if same else '!!', position * 4, text_of(word)[:34], text_of(target)))
