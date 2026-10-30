#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""disc_extract.py ISO [--out DIR] [--list] [FILE ...] - reads a PS2 disc image (ISO 9660, 2048-byte sectors) without mounting it.

  python3 scripts/disc_extract.py discs/sly2.iso                 the boot executable named by SYSTEM.CNF, written to work/elf/
  python3 scripts/disc_extract.py discs/sly2.iso --list          the files of the root directory
  python3 scripts/disc_extract.py discs/sly2.iso SYSTEM.CNF      a file of the root directory, written to the output folder

Prints the name, size and SHA-1 of every file it writes. The disc images are yours: nothing here is committed (work/ and discs/ are
ignored)."""
import argparse
import hashlib
import os
import re
import struct
import sys

SECTOR = 2048


def read_sectors(handle, lba, size):
    handle.seek(lba * SECTOR)
    return handle.read(size)


def directory(handle, lba, size):
    """[(name, lba, size, is_directory)] of an ISO 9660 directory (the `;1` version suffix is dropped)."""
    data = read_sectors(handle, lba, size)
    entries, position = [], 0
    while position < len(data):
        length = data[position]
        if length == 0:  # records do not cross a sector: skip the padding
            position = (position // SECTOR + 1) * SECTOR
            continue
        record = data[position:position + length]
        extent, = struct.unpack_from('<I', record, 2)
        extent_size, = struct.unpack_from('<I', record, 10)
        flags = record[25]
        name_length = record[32]
        name = record[33:33 + name_length]
        position += length
        if name in (b'\x00', b'\x01'):
            continue
        entries.append((name.decode('ascii', 'replace').split(';')[0], extent, extent_size, bool(flags & 2)))
    return entries


def root(handle):
    descriptor = read_sectors(handle, 16, SECTOR)
    if descriptor[1:6] != b'CD001':
        sys.exit('not an ISO 9660 image with 2048-byte sectors')
    lba, size = struct.unpack_from('<I', descriptor, 156 + 2)[0], struct.unpack_from('<I', descriptor, 156 + 10)[0]
    return directory(handle, lba, size)


def find(entries, name):
    return next((entry for entry in entries if entry[0].upper() == name.upper() and not entry[3]), None)


def write(handle, entry, out):
    name, lba, size, _ = entry
    data = read_sectors(handle, lba, size)
    os.makedirs(out, exist_ok=True)
    path = os.path.join(out, name)
    with open(path, 'wb') as target:
        target.write(data)
    print(f'{path}: {size} bytes, sha1 {hashlib.sha1(data).hexdigest()}')
    return path


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('iso')
    parser.add_argument('files', nargs='*')
    parser.add_argument('--out', default=os.path.join('work', 'elf'))
    parser.add_argument('--list', action='store_true')
    arguments = parser.parse_args()
    with open(arguments.iso, 'rb') as handle:
        entries = root(handle)
        if arguments.list:
            for name, lba, size, is_directory in entries:
                print(f'{name}{"/" if is_directory else ""}\t{size}\tlba {lba}')
            return 0
        wanted = arguments.files
        if not wanted:
            config = find(entries, 'SYSTEM.CNF')
            if not config:
                sys.exit('no SYSTEM.CNF in the root directory')
            text = read_sectors(handle, config[1], config[2]).decode('ascii', 'replace')
            boot = re.search(r'BOOT2\s*=\s*cdrom0:\\?([^;\s]+)', text)
            if not boot:
                sys.exit('SYSTEM.CNF has no BOOT2 line:\n' + text)
            wanted = [boot.group(1)]
        for name in wanted:
            entry = find(entries, name)
            if not entry:
                sys.exit(f'{name}: not in the root directory (--list shows it)')
            write(handle, entry, arguments.out)
    return 0


if __name__ == '__main__':
    sys.exit(main())
