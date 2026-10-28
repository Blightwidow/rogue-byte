#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""configure.py [--split]: write build.ninja for the pieces of the Sly 2 image: the raw segments wrapped as objects and the
matched functions of src/ compiled (targets `pieces` and `units`).

--split runs Splat first (config/us/sly2.us.yaml on work/elf/SCUS_973.16, output in build/splat). `make elf` then builds
`pieces` and `units` and runs scripts/build/link_image.py (assembly runs + compiled functions, linked at their retail
addresses) and scripts/verify_image.py (every loaded byte against the retail executable)."""
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

if '--split' in sys.argv:
    subprocess.check_call(['python3', 'scripts/names/combine.py', 'config/recovered/'], cwd=ROOT)
    subprocess.check_call(['python3', 'scripts/names/export_splat_symbols.py'], cwd=ROOT)
    subprocess.check_call([os.path.join(ROOT, '.venv', 'bin', 'splat'), 'split', 'sly2.us.yaml'],
                          cwd=os.path.join(ROOT, 'config', 'us'))

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

    # the matched functions of src/ (python3 scripts/matching/export_src.py), compiled the way the retail build did (scripts/build/compile_unit.py:
    # SN's compiler, then SN's assembler ps2eeas when tools/ps2eeas has it, GNU as for the functions of config/us/gnu_as.txt, ps2eeas-loop5 for config/us/ps2eeas_loop5.txt)
    sys.path.insert(0, os.path.join(ROOT, 'scripts', 'build'))
    import compile_unit
    assembler_for = compile_unit.assembler_for
    for language, rule in (('c++', 'compile_cpp'), ('c', 'compile_c')):
        ninja.rule(rule, command=f'python3 scripts/build/compile_unit.py {language} $in $out $assembler', description='CC $in')
    units = []
    manifest = os.path.join(ROOT, 'src', 'MANIFEST.tsv')
    if os.path.exists(manifest):
        for line in list(open(manifest))[1:]:
            source = os.path.join('src', line.rstrip('\n').split('\t')[3])
            unit = os.path.join('build', 'units', source[len('src/'):] + '.o')
            address = int(line.split('\t')[0], 16)
            ninja.build(unit, 'compile_c' if source.endswith('.c') else 'compile_cpp', source, implicit=['include/sly2.h', 'include/m2c_macros.h'],
                        variables={'assembler': f'--assembler {assembler_for(address)}' if assembler_for(address) else ''})
            units.append(unit)
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
                        variables={'assembler': f'--assembler {assembler_for(address)}' if assembler_for(address) else ''})
            drafts.append(unit)
        ninja.build('nonmatching', 'phony', drafts)
print('wrote build.ninja')
