#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""verify_image.py <image.bin>: the rebuilt image against work/elf/SCUS_973.16, segment by segment.

image.bin starts at vram 0x100000 (objcopy -O binary). The gate: every loaded byte of the retail executable is
reproduced. Writes build/image/verified on success."""
import hashlib
import os
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
# (name, file offset in the retail ELF, vram, size): the PT_LOAD contents (the .text, .vutext, .rodata and .data
# sections are contiguous in the file) and the embedded IOP modules
REGIONS = [('code, VU1 microcode, rodata, data', 0x80, 0x100000, 0x1DD230), ('IOP modules (.irx)', 0x1DD380, 0x472200, 0x73C40)]

original = open(os.path.join(ROOT, 'work', 'elf', 'SCUS_973.16'), 'rb').read()
expected_sha1 = open(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'config', 'us', 'checksum.sha1')).read().split()[0]
if hashlib.sha1(original).hexdigest() != expected_sha1:
    sys.exit(f'work/elf/SCUS_973.16 is not the USA release (sha1 {expected_sha1} in config/us/checksum.sha1)')
image = open(sys.argv[1], 'rb').read()
failed = False
for name, file_offset, vram, size in REGIONS:
    expected = original[file_offset:file_offset + size]
    actual = image[vram - 0x100000:vram - 0x100000 + size]
    if expected == actual:
        print(f'ok   {name}: {size} bytes')
        continue
    failed = True
    differing = [index for index in range(min(len(expected), len(actual))) if expected[index] != actual[index]]
    print(f'FAIL {name}: {len(differing)} of {size} bytes differ, first at {vram + differing[0]:#x}' if differing
          else f'FAIL {name}: image is {len(actual)} bytes, expected {size}')
packed = os.path.join(os.path.dirname(os.path.abspath(sys.argv[1])), 'SCUS_973.16')
if os.path.exists(packed):
    whole = open(packed, 'rb').read()
    if whole == original:
        print(f'ok   whole file: {len(whole)} bytes, sha1 {hashlib.sha1(whole).hexdigest()}')
    else:
        failed = True
        print(f'FAIL whole file: {len(whole)} bytes, expected {len(original)}')
if failed:
    sys.exit(1)
print('PASS: reconstructed image matches retail')
open(os.path.join(os.path.dirname(os.path.abspath(sys.argv[1])), 'verified'), 'w').write('PASS\n')
