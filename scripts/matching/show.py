# SPDX-License-Identifier: GPL-3.0-or-later
"""Print the R5900 disassembly of a function in the target ELF (size from the export jsonl)."""
import sys
import compare
elf_path, export_path = sys.argv[1], sys.argv[2]
for argument in sys.argv[3:]:
    address = int(argument, 0)
    size, name = compare.target_size_from_export(export_path, address)
    print(f"== {address:#x} {name} ({size} bytes)")
    for index, word in enumerate(compare.read_target_words(elf_path, address, size)):
        print(f"{address + index * 4:08x}  {compare.disassemble(word)}")
