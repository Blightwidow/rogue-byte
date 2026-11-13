# SPDX-License-Identifier: GPL-3.0-or-later
"""elfmini.py: a reader for the little-endian ELF32 relocatable objects the compiler writes: sections, symbols and REL relocations, with struct.

link_image.py asks about thousands of small objects on every run (does the code use its own data, which names does it leave undefined, where is
the function in its .text). pyelftools answered each of those questions with a few hundred construct parses and took most of the Python time
of a link; this reads the same tables directly. It handles only what a compiled object holds (no program headers, no 64-bit, no RELA)."""
import struct

SHT_SYMTAB = 2
SHT_REL = 9
SHN_UNDEF = 0
SHN_LORESERVE = 0xFF00


class Elf:
    def __init__(self, data):
        if data[:4] != b'\x7fELF' or data[4] != 1 or data[5] != 1:
            raise ValueError('not a little-endian ELF32 file')
        self.data = data
        section_offset = struct.unpack_from('<I', data, 0x20)[0]
        entry_size, count, names_index = struct.unpack_from('<HHH', data, 0x2E)
        raw = [struct.unpack_from('<10I', data, section_offset + index * entry_size) for index in range(count)]
        names = data[raw[names_index][4]:raw[names_index][4] + raw[names_index][5]]
        self.sections = [{'name': names[name:names.index(b'\0', name)].decode(), 'type': kind, 'flags': flags, 'address': address, 'offset': offset,
                          'size': size, 'link': link, 'info': info, 'entry_size': entsize}
                         for name, kind, flags, address, offset, size, link, info, _, entsize in raw]
        self._symbols = None

    @classmethod
    def read(cls, path):
        with open(path, 'rb') as handle:
            return cls(handle.read())

    def section(self, name):
        """The first section called `name`, or None."""
        return next((section for section in self.sections if section['name'] == name), None)

    def section_index(self, name):
        return next((index for index, section in enumerate(self.sections) if section['name'] == name), None)

    def symbols(self):
        """[(name, value, size, info, section index)] of .symtab, in table order (empty when the object has none)."""
        if self._symbols is None:
            table = next((section for section in self.sections if section['type'] == SHT_SYMTAB), None)
            self._symbols = []
            if table is not None:
                strings = self.sections[table['link']]
                blob = self.data[strings['offset']:strings['offset'] + strings['size']]
                for at in range(table['offset'], table['offset'] + table['size'], 16):
                    name, value, size, info, _, index = struct.unpack_from('<IIIBBH', self.data, at)
                    self._symbols.append((blob[name:blob.index(b'\0', name)].decode(), value, size, info, index))
        return self._symbols

    def relocations(self, name):
        """[(offset, type, symbol index)] of the REL section called `name` (for example '.rel.text'); empty when there is none."""
        section = self.section(name)
        if section is None or section['type'] != SHT_REL:
            return []
        found = []
        for at in range(section['offset'], section['offset'] + section['size'], 8):
            offset, info = struct.unpack_from('<II', self.data, at)
            found.append((offset, info & 0xFF, info >> 8))
        return found
