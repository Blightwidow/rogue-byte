# SPDX-License-Identifier: GPL-3.0-or-later
"""Compare one function of a compiled object with the same function in a PS2 ELF.

Relocated fields are masked on both sides (R_MIPS_26: target bits, HI16/LO16/GPREL16: immediate).
Score = instructions not in matching blocks (0 = byte match after masking).
--symbols <symbol_addrs.txt>: also checks what the masked fields point at, as if the function were linked at its
real address: every call (R_MIPS_26) and every %hi/%lo pair must resolve, through the symbol table, to the address
the binary has there (the addend is the object's own immediates). A wrong or unknown symbol counts in the score.
"""
import argparse
import difflib
import json
import sys

import rabbitizer
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

MASK_BY_RELOCATION_TYPE = {
    4: 0xFC000000,   # R_MIPS_26
    5: 0xFFFF0000,   # R_MIPS_HI16
    6: 0xFFFF0000,   # R_MIPS_LO16
    7: 0xFFFF0000,   # R_MIPS_GPREL16
}
RELOCATION_NAMES = {4: "%26", 5: "%hi", 6: "%lo", 7: "%gp_rel"}


def read_target_words(elf_path, address, size):
    with open(elf_path, "rb") as elf_file:
        elf = ELFFile(elf_file)
        for segment in elf.iter_segments():
            start = segment["p_vaddr"]
            if segment["p_type"] == "PT_LOAD" and start <= address < start + segment["p_filesz"]:
                data = segment.data()[address - start:address - start + size]
                return [int.from_bytes(data[index:index + 4], "little") for index in range(0, len(data), 4)]
    sys.exit(f"address {address:#x} not in a loadable segment")


def target_size_from_export(export_path, address):
    with open(export_path) as export_file:
        for line in export_file:
            record = json.loads(line)
            if record["entry"] == address:
                return record["size"], record["name"]
    return None, None


def read_object_function(object_path, symbol_query):
    with open(object_path, "rb") as object_file:
        elf = ELFFile(object_file)
        symbol_table = elf.get_section_by_name(".symtab")
        functions = [symbol for symbol in symbol_table.iter_symbols()
                     if symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_size"] > 0]
        if symbol_query:
            chosen = [symbol for symbol in functions if symbol.name == symbol_query] or \
                     [symbol for symbol in functions if symbol.name.startswith(symbol_query + "__")] or \
                     [symbol for symbol in functions if symbol_query in symbol.name]
        else:
            chosen = functions
        if len(chosen) != 1:
            names = ", ".join(symbol.name for symbol in (chosen or functions))
            sys.exit(f"need exactly one function matching '{symbol_query}'; candidates: {names}")
        symbol = chosen[0]
        section_index = symbol["st_shndx"]
        section = elf.get_section(section_index)
        start, size = symbol["st_value"], symbol["st_size"]
        data = section.data()[start:start + size]
        words = [int.from_bytes(data[index:index + 4], "little") for index in range(0, len(data), 4)]
        relocations = {}
        for relocation_section in elf.iter_sections():
            if not isinstance(relocation_section, RelocationSection):
                continue
            if relocation_section["sh_info"] != section_index:
                continue
            relocation_symbols = elf.get_section(relocation_section["sh_link"])
            for relocation in relocation_section.iter_relocations():
                offset = relocation["r_offset"]
                if start <= offset < start + size:
                    target_symbol = relocation_symbols.get_symbol(relocation["r_info_sym"])
                    target_name = target_symbol.name or elf.get_section(target_symbol["st_shndx"]).name
                    relocations[(offset - start) // 4] = (relocation["r_info_type"], target_name)
        return symbol.name, words, relocations, start


def rodata_matches(object_path, object_start, addend, actual, address, size, elf_path):
    """An unnamed `.rodata+addend` target (a jump table or a constant the compiler made for this function): in a real link the object's
    .rodata lands at the binary's address, so the link is right when what the object holds there equals what the binary holds.
    A jump table: every word the binary has there that points inside the function (address..address+size) is a relocated .text
    word of the object at the same offset from the function start; a constant: the first word is the same."""
    with open(object_path, "rb") as object_file:
        elf = ELFFile(object_file)
        rodata = elf.get_section_by_name(".rodata")
        if rodata is None or addend + 4 > rodata["sh_size"]:
            return False
        data = rodata.data()
        index = elf.get_section_index(".rodata") if hasattr(elf, "get_section_index") else None
        relocated = {}
        for section in elf.iter_sections():
            if isinstance(section, RelocationSection) and section.name in (".rel.rodata", ".rela.rodata"):
                for relocation in section.iter_relocations():
                    relocated[relocation["r_offset"]] = relocation["r_info_type"]
    word = lambda blob, offset: int.from_bytes(blob[offset:offset + 4], "little")
    first = read_target_words(elf_path, actual, 4)[0]
    if not address <= first < address + size:
        return addend + 4 <= len(data) and word(data, addend) == first and (addend not in relocated)
    count = 0
    while count < 512:
        try:
            binary_word = read_target_words(elf_path, actual + 4 * count, 4)[0]
        except SystemExit:
            break
        if not address <= binary_word < address + size:
            break
        offset = addend + 4 * count
        if offset + 4 > len(data) or relocated.get(offset) != 2 or word(data, offset) - object_start != binary_word - address:
            return False
        count += 1
    return count > 0


def read_symbol_addresses(path):
    """name -> address from a splat-style symbol_addrs file; C++ names also under their unmangled prefix."""
    import re
    addresses = {}
    for line in open(path, encoding="utf-8"):
        match = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+);", line)
        if match:
            addresses.setdefault(match.group(1), int(match.group(2), 16))
            addresses.setdefault(match.group(1).split("__")[0], int(match.group(2), 16))
    return addresses


def resolve(addresses, name):
    import re
    generated = re.fullmatch(r"(?:D|func|jtbl|L|B|RO)_([0-9A-Fa-f]{8})", name)  # spimdisasm's names carry the address
    if generated:
        return int(generated.group(1), 16) & 0x1FFFFFFF
    if name in addresses:
        return addresses[name]
    base = name.split("__")[0]  # a mangled C++ name: the plain name before the signature
    return addresses.get(base)


def sign16(value):
    return value - 0x10000 if value & 0x8000 else value


def strip_trailing_nops(words):
    while words and words[-1] == 0:
        words = words[:-1]
    return words


def disassemble(word, relocation=None):
    instruction = rabbitizer.Instruction(word, category=rabbitizer.InstrCategory.R5900)
    text = instruction.disassemble(immOverride=None)
    text = " ".join(text.split())
    if relocation:
        relocation_type, target_name = relocation
        text += f"  [{RELOCATION_NAMES.get(relocation_type, relocation_type)} {target_name}]"
    return text


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("object")
    parser.add_argument("address", type=lambda text: int(text, 0))
    parser.add_argument("--elf", required=True)
    parser.add_argument("--symbol", help="function symbol (or mangled prefix) in the object")
    parser.add_argument("--size", type=lambda text: int(text, 0), help="target size in bytes")
    parser.add_argument("--export", help="jsonl with entry/size/name (sizes for the target)")
    parser.add_argument("--quiet", action="store_true")
    parser.add_argument("--symbols", help="symbol_addrs file: check calls and %%hi/%%lo targets as if linked")
    arguments = parser.parse_args()

    export_name = None
    size = arguments.size
    if size is None and arguments.export:
        size, export_name = target_size_from_export(arguments.export, arguments.address)
    symbol_query = arguments.symbol
    symbol_name, object_words, relocations, object_start = read_object_function(arguments.object, symbol_query)
    if size is None:
        size = len(object_words) * 4
    target_words = strip_trailing_nops(read_target_words(arguments.elf, arguments.address, size))
    object_words = strip_trailing_nops(object_words)

    def masked(index, word):
        relocation = relocations.get(index)
        return word & MASK_BY_RELOCATION_TYPE.get(relocation[0], 0xFFFFFFFF) if relocation else word

    object_keys = [masked(index, word) for index, word in enumerate(object_words)]
    # align on mnemonics first, then mask each target word with the relocation of its aligned object word
    target_mnemonics = [disassemble(word).split()[0] for word in target_words]
    object_mnemonics = [disassemble(word).split()[0] for word in object_words]
    target_keys = list(target_words)
    aligned = {}  # object index -> target index
    aligner = difflib.SequenceMatcher(None, target_mnemonics, object_mnemonics, autojunk=False)
    for operation, target_start, target_end, object_start, object_end in aligner.get_opcodes():
        if operation in ("equal", "replace"):
            for target_index, object_index in zip(range(target_start, target_end), range(object_start, object_end)):
                aligned[object_index] = target_index
                relocation = relocations.get(object_index)
                if relocation:
                    target_keys[target_index] &= MASK_BY_RELOCATION_TYPE.get(relocation[0], 0xFFFFFFFF)
    # the link check: what each relocated field points at
    link_errors = {}  # target index -> message
    if arguments.symbols:
        addresses = read_symbol_addresses(arguments.symbols)
        pending_hi = {}  # symbol -> object index of its last %hi
        for object_index in sorted(relocations):
            kind, name = relocations[object_index]
            target_index = aligned.get(object_index)
            if target_index is None:
                continue
            wanted = resolve(addresses, name)
            if kind == 4:
                pc = arguments.address + target_index * 4
                actual = ((pc + 4) & 0xF0000000) | ((target_words[target_index] & 0x3FFFFFF) << 2)
                expected = None if wanted is None else wanted + ((object_words[object_index] & 0x3FFFFFF) << 2)
                if wanted is None and name == ".text":
                    # a call within the object (self-recursion): the assembler resolved it locally, no symbol
                    offset = ((object_words[object_index] & 0x3FFFFFF) << 2) - object_start
                    if arguments.address + offset == actual:
                        continue
                if expected != actual:
                    link_errors[target_index] = f"calls {name} ({'unknown' if wanted is None else hex(expected)}), binary {actual:#x}"
            elif kind == 5:
                pending_hi[name] = object_index
            elif kind == 6 and name in pending_hi and aligned.get(pending_hi[name]) is not None:
                hi_object, hi_target = pending_hi[name], aligned[pending_hi[name]]
                actual = ((target_words[hi_target] & 0xFFFF) << 16) + sign16(target_words[target_index] & 0xFFFF)
                addend = ((object_words[hi_object] & 0xFFFF) << 16) + sign16(object_words[object_index] & 0xFFFF)
                expected = None if wanted is None else wanted + addend
                if wanted is None and name == ".rodata" and rodata_matches(arguments.object, object_start, addend, actual & 0xFFFFFFFF, arguments.address, size, arguments.elf):
                    continue
                if expected != actual & 0xFFFFFFFF:
                    link_errors[target_index] = f"{name}+{addend:#x} = {'unknown' if wanted is None else hex(expected)}, binary {actual & 0xFFFFFFFF:#x}"
    matcher = difflib.SequenceMatcher(None, target_keys, object_keys, autojunk=False)
    score = len(link_errors)
    register_only = 0
    first_bad = min(link_errors) if link_errors else len(target_words)  # target index of the first difference
    lines = []
    for operation, target_start, target_end, object_start, object_end in matcher.get_opcodes():
        if operation != "equal":
            first_bad = min(first_bad, target_start)
            score += max(target_end - target_start, object_end - object_start)
            for target_index, object_index in zip(range(target_start, target_end), range(object_start, object_end)):
                if (target_words[target_index] >> 26) == (object_words[object_index] >> 26) and \
                        disassemble(target_words[target_index]).split()[0] == disassemble(object_words[object_index]).split()[0]:
                    register_only += 1
        width = max(target_end - target_start, object_end - object_start)
        for step in range(width):
            target_index, object_index = target_start + step, object_start + step
            left = disassemble(target_words[target_index]) if target_index < target_end else ""
            right = disassemble(object_words[object_index], relocations.get(object_index)) if object_index < object_end else ""
            marker = " " if operation == "equal" else ("|" if left and right else ("<" if left else ">"))
            if operation == "equal" and target_index in link_errors:
                marker, right = "!", right + "  LINK: " + link_errors[target_index]
            target_column = f"{arguments.address + target_index * 4:08x}" if target_index < target_end else "        "
            lines.append(f"{target_column} {left:<38} {marker} {right}")
    header = (f"score {score}  ({register_only} same-mnemonic{f', {len(link_errors)} link' if link_errors else ''})  target {len(target_words)} instr"
              f"{' ' + export_name if export_name else ''}  ours {len(object_words)} instr {symbol_name}"
              f"{f'  prefix {first_bad}/{len(target_words)} first-mismatch +{first_bad * 4:#x}' if score else ''}")
    print(header)
    if not arguments.quiet and score:
        print("\n".join(lines))
    elif not arguments.quiet:
        print("MATCH")
    return 0


if __name__ == "__main__":
    sys.exit(main())
