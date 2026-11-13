#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""configure.py [--split]: write build.ninja for the pieces of the Sly 2 image: the raw segments wrapped as objects and the
matched functions of src/ compiled (targets `pieces` and `units`).

--split runs Splat first (config/us/sly2.us.yaml on work/elf/SCUS_973.16, output in build/splat). `make elf` then builds
`pieces` and `units` and runs scripts/build/link_image.py (assembly runs + compiled functions, linked at their retail
addresses) and scripts/verify_image.py (every loaded byte against the retail executable)."""
import hashlib
import importlib.metadata
import os
import subprocess
import sys

import ninja_syntax

ROOT = os.path.dirname(os.path.abspath(__file__))
BINUTILS = os.path.join('tools', 'binutils-mips-ps2-decompals', 'mips-ps2-decompals')
SPLAT_OUTPUT = os.path.join('build', 'splat')
BUILD = os.path.join('build', 'image')
# (object name, vram of the first byte) of the raw pieces: the symbol Splat's code refers to is defined at their start
BINARY_PIECES = [('vutext', 0x259DF0), ('irx_gap', 0x2DD250), ('irx', 0x472200)]  # rodata and data pieces: link_image.py

def snapshot_tree(directory):
    """{path: (mtime in ns, size, sha1 of the bytes)} of every file under `directory`."""
    found = {}
    for folder, _, names in os.walk(directory):
        for name in names:
            path = os.path.join(folder, name)
            status = os.stat(path)
            with open(path, 'rb') as handle:
                found[path] = (status.st_mtime_ns, status.st_size, hashlib.sha1(handle.read()).digest())
    return found


def restore_unchanged_mtimes(before):
    """Puts back the modification time of every file of `before` that now holds the same bytes. Splat rewrites all its output on each run; with
    the new times ninja saw every object that includes assembly (about 200 whole files) as stale after each `make elf`."""
    restored = 0
    for path, (mtime, size, digest) in before.items():
        if os.path.exists(path) and os.stat(path).st_size == size:
            with open(path, 'rb') as handle:
                if hashlib.sha1(handle.read()).digest() == digest:
                    os.utime(path, ns=(mtime, mtime))
                    restored += 1
    return restored


if '--split' in sys.argv:
    subprocess.check_call(['python3', 'scripts/names/combine.py', 'config/recovered/'], cwd=ROOT)
    subprocess.check_call(['python3', 'scripts/names/export_splat_symbols.py'], cwd=ROOT)
    # Splat takes 14 s and its output is a function of a few files: skip it when none changed since the run that wrote build/splat
    stamp_path = os.path.join(ROOT, SPLAT_OUTPUT, '.split_stamp')
    digest = hashlib.sha1()
    for path in ('config/us/sly2.us.yaml', 'config/us/symbol_addrs.txt', 'work/elf/SCUS_973.16', 'scripts/build/numeric_constants.py'):
        with open(os.path.join(ROOT, path), 'rb') as handle:
            digest.update(handle.read())
    digest.update(f"{importlib.metadata.version('splat64')} {importlib.metadata.version('spimdisasm')}".encode())
    if os.path.isfile(stamp_path) and open(stamp_path).read() == digest.hexdigest() and os.path.isdir(os.path.join(ROOT, SPLAT_OUTPUT, 'asm')):
        print('split: its inputs are unchanged since the last run, build/splat kept')
    else:
        splat_before = snapshot_tree(os.path.join(ROOT, SPLAT_OUTPUT)) if os.path.isdir(os.path.join(ROOT, SPLAT_OUTPUT)) else {}
        subprocess.check_call([os.path.join(ROOT, '.venv', 'bin', 'splat'), 'split', 'sly2.us.yaml'],
                              cwd=os.path.join(ROOT, 'config', 'us'))
        subprocess.check_call(['python3', 'scripts/build/numeric_constants.py'], cwd=ROOT)
        restore_unchanged_mtimes(splat_before)
        with open(stamp_path, 'w') as handle:
            handle.write(digest.hexdigest())

with open(os.path.join(ROOT, 'build.ninja'), 'w') as handle:
    ninja = ninja_syntax.Writer(handle, width=120)
    ninja.variable('binutils', BINUTILS)
    ninja.rule('wrap_binary', command='printf \'.section .data, "aw"\\n.global %s\\n%s:\\n.incbin "%s"\\n\' $symbol $symbol $piece'
                                      ' | ${binutils}-as -EL -march=r5900 -o $out -', description='BIN $piece')
    ninja.variable('builddir', BUILD)

    pieces = []
    for name, address in BINARY_PIECES:
        piece = os.path.join(SPLAT_OUTPUT, 'assets', f'{name}.databin.bin')
        object_path = os.path.join(BUILD, f'{name}.o')
        ninja.build(object_path, 'wrap_binary', piece, variables={'piece': piece, 'symbol': f'D_{address:08X}'})
        pieces.append(object_path)
    ninja.build('pieces', 'phony', pieces)

    # the matched functions of src/ outside whole files (python3 scripts/matching/export_src.py), compiled the way the retail build did (scripts/build/compile_unit.py:
    # SN's compiler, then SN's ps2eeas, the one assembler)
    sys.path.insert(0, os.path.join(ROOT, 'scripts', 'build'))
    import asm_units
    import compile_unit
    assembler_for = compile_unit.assembler_for

    def options(address):
        """The compile_unit.py options of a function: its compiler for the SDK range (config/us/sony_gcc29.txt) --vu0 (config/us/vu0_regs.txt) and --movables (config/us/move_movables.txt)."""
        return ' '.join(part for part in (f'--assembler {assembler_for(address)}' if assembler_for(address) else '', '--vu0' if compile_unit.vu0_for(address) else '', '--movables' if compile_unit.movables_for(address) else '', f"--flags='{' '.join(compile_unit.flags_for(address))}'" if compile_unit.flags_for(address) else '') if part)
    for language, rule in (('c++', 'compile_cpp'), ('c', 'compile_c')):
        ninja.rule(rule, command=f'python3 scripts/build/compile_unit.py {language} $in $out $assembler', description='CC $in')
    units = []
    manifest = os.path.join(ROOT, 'src', 'MANIFEST.tsv')
    if os.path.exists(manifest):
        for line in list(open(manifest))[1:]:
            columns = line.rstrip('\n').split('\t')
            if len(columns) > 4 and columns[4]:  # inside a whole file: that file's object holds it (below)
                continue
            source = os.path.join('src', columns[3])
            unit = os.path.join('build', 'units', source[len('src/'):] + '.o')
            address = int(columns[0], 16)
            ninja.build(unit, 'compile_c' if source.endswith('.c') else 'compile_cpp', source, implicit=['include/sly2.h', 'include/m2c_macros.h'],
                        variables={'assembler': options(address)})
            units.append(unit)
        # whole files (config/us/whole_files.tsv): one source per retail file, its unmatched functions included from Splat's assembly
        # (INCLUDE_ASM), so the object depends on the split; link_image.py links it at the file's start in place of its functions
        for start, _, source in asm_units.whole_files():
            unit = os.path.join('build', 'units', source + '.o')
            ninja.build(unit, 'compile_c' if source.endswith('.c') else 'compile_cpp', os.path.join('src', source),
                        implicit=['include/sly2.h', 'include/m2c_macros.h', 'include/include_asm.h', os.path.join(SPLAT_OUTPUT, 'undefined_syms_auto.txt')],
                        variables={'assembler': options(start)})
            units.append(unit)
        # data files (config/us/data_files.tsv): a source that defines game data (docs/contributing/exceptions.md); link_image.py links its .data or .rodata
        data_list = os.path.join(ROOT, 'config', 'us', 'data_files.tsv')
        for line in (list(open(data_list))[1:] if os.path.isfile(data_list) else []):
            start_text, _, source = line.rstrip('\n').split('\t')
            ninja.build(os.path.join('build', 'units', source + '.o'), 'compile_c' if source.endswith('.c') else 'compile_cpp', os.path.join('src', source),
                        variables={'assembler': options(int(start_text, 16))})
            units.append(os.path.join('build', 'units', source + '.o'))
        ninja.build('units', 'phony', units)

    # the sources that compile but do not match (python3 scripts/matching/export_nonmatching.py): only objdiff looks at them
    drafts = []
    manifest = os.path.join(ROOT, 'nonmatching', 'MANIFEST.tsv')
    if os.path.exists(manifest):
        for line in list(open(manifest))[1:]:
            source = os.path.join('nonmatching', line.rstrip('\n').split('\t')[3])
            unit = os.path.join('build', 'nonmatching', source[len('nonmatching/'):] + '.o')
            address = int(line.split('\t')[0], 16)
            ninja.build(unit, 'compile_c' if source.endswith('.c') else 'compile_cpp', source, implicit=['include/sly2.h', 'include/m2c_macros.h'],
                        variables={'assembler': options(address)})
            drafts.append(unit)
        ninja.build('nonmatching', 'phony', drafts)
print('wrote build.ninja')
