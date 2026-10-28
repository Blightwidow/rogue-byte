#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""pack_elf.py: build/image/SCUS_973.16, the whole executable file, from the rebuilt image and the raw pieces Splat cut out:
the ELF header and program headers (0x80 bytes), the padding after the first loaded segment, the IOP modules, and the
section data and section header table after them (build/splat/assets/elf_*.databin.bin).

The two loaded segments are the rebuilt code, rodata and data (image.bin, vram 0x100000 on); the container pieces are
carried over from your executable."""
import os
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
ASSETS = os.path.join(ROOT, 'build', 'splat', 'assets')
IMAGE = os.path.join(ROOT, 'build', 'image', 'image.bin')
LOADED_SIZE = 0x1DD230  # filesz of the first PT_LOAD segment

def piece(name):
    return open(os.path.join(ASSETS, name + '.databin.bin'), 'rb').read()

image = open(IMAGE, 'rb').read()
executable = piece('elf_header') + image[:LOADED_SIZE] + piece('irx_gap') + piece('irx') + piece('elf_tail')
destination = os.path.join(ROOT, 'build', 'image', 'SCUS_973.16')
open(destination, 'wb').write(executable)
print(f'{destination}: {len(executable)} bytes')
