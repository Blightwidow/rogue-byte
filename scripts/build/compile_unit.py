#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""compile_unit.py <c|c++> <source> <output.o> [--assembler sony29]: compiles one source the way the retail build did.

SN's compiler (EE-GCC 2.95.3 build 1.36) writes assembly with `-S`, and SN Systems' own assembler `ps2eeas` 1.9.25.758 (the one SN's ProDG
driver runs; `setup.sh --assembler` downloads it, pinned) assembles the result under wibo, with `-G` from the compile flags. It
expands `move` to `daddu`, puts the hazard `nop` between `mtc1` and the instruction that reads the register only when the next instruction
reads it, and pads short loops (the R5900 short-loop erratum). The one assembler serves every game function: there is no per-function choice
of assembler. Its short-loop padding is the one change: the build's copy, `tools/ps2eeas/Ps2EeAs-loop5.exe`, is the pinned binary with one
byte changed (offset 0x4DEB, the 6 of "pad a backward-branch loop up to six instructions", becomes 5), because retail pads to five
instructions (target through branch) in all 240 short loops of its game code and none below; no unpatched assembler release we could
run pads that way (docs/build/assembler.md, "Short loops"). The copy is made from the pinned download on first use, never committed.
It assembles in one pass and only reaches a global through `$gp` when it has already seen the symbol's size, so the compiler's
`.extern SYM,SIZE` lines, written at the end of the file, go to the top. `--assembler sony29` builds the SDK range with Sony's own
ee-gcc 2.9-ee-991111 and its driver (config/us/sony_gcc29.txt). Symbols of the object are made local (objcopy -L) so that objects of
several functions can be linked together.

EE_AS_EXE and EE_AS_ARGS in the environment replace the assembler and its arguments for one run: scripts/matching/assembler_probe.py sets
them to measure a candidate, and a build never does (docs/build/assembler.md, "Before changing the assembler").
`compile_unit.py --make-assembler` makes the patched copy and exits (setup.sh runs it)."""
import argparse
import functools
import os
import re
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
COMPILER = os.path.join(ROOT, 'tools', 'compilers', 'ee-gcc2.95.3-136')
LEGACY_COMPILER = os.path.join(ROOT, 'work', 'matching', 'compilers', 'ee-gcc2.95.3-136')
SONY_COMPILER = os.path.join(ROOT, 'tools', 'compilers', 'ee-gcc2.9-991111b')
LEGACY_SONY_COMPILER = os.path.join(ROOT, 'work', 'toolchains', 'ee-gcc2.9-991111b')
SONY_FLAGS = ['-O2', '-G0']
WIBO = os.path.join(ROOT, 'tools', 'wibo')
EE_AS_PINNED = os.path.join(ROOT, 'tools', 'ps2eeas', 'Ps2EeAs.exe')  # SN's binary exactly as downloaded (setup.sh checks its sha256)
EE_AS_BUILD = os.path.join(ROOT, 'tools', 'ps2eeas', 'Ps2EeAs-loop5.exe')  # the same binary with its short-loop padding one nop shorter
SHORT_LOOP_OFFSET = 0x4DEB  # in Ps2EeAs.exe 1.9.25.758: the 6 of "pad a backward-branch loop up to six instructions"
EE_AS = os.environ.get('EE_AS_EXE') or EE_AS_BUILD  # EE_AS_EXE: only for scripts/matching/assembler_probe.py
OBJCOPY = os.path.join(ROOT, 'tools', 'binutils-mips-ps2-decompals', 'mips-ps2-decompals-objcopy')
FLAGS = os.environ['COMPILE_FLAGS'].split() if os.environ.get('COMPILE_FLAGS') else ['-O2', '-G0', '-ffast-math', '-fno-exceptions']  # the variable is for flag sweeps


def hoist_externs(assembly):
    """The assembly with its `.extern` lines moved in front of everything else (ps2eeas needs a symbol's size before its first use)."""
    lines = assembly.split('\n')
    externs = [line for line in lines if re.match(r'\s*\.extern\s', line)]
    return '\n'.join(externs + [line for line in lines if not re.match(r'\s*\.extern\s', line)])


BRANCH = re.compile(r'\s*(b|j|jal|jr|jalr|beq|bne|beqz|bnez|bgez|bgtz|blez|bltz|bc1[tf]l?|beql|bnel|bgezal|bltzal)\s')
COPROCESSOR_2 = re.compile(r'(qmtc2|qmfc2|lqc2|sqc2|ctc2|cfc2|v[a-z0-9]+)(\.\w+)?\s')


GPR_WRITER = re.compile(r'(qmfc2|cfc2)(\.\w+)?\s+(\$\w+)')


@functools.lru_cache(maxsize=None)
def listed_functions(name):
    """Addresses listed in config/us/<name> (one per line, `#` comments)."""
    path = os.path.join(ROOT, 'config', 'us', name)
    if not os.path.exists(path):
        return set()
    with open(path) as listing:
        return {int(line.split()[0], 16) for line in listing if line.strip() and not line.startswith('#')}


VU0_FLAG = '-mvu0-use-vf0-15'  # lets the register allocator use vf0..vf15 for the `"j"` (VU0 register) operands of inline asm: the moves to and from them become ordinary insns


def vu0_functions():
    """Addresses of the functions compiled with VU0_FLAG (config/us/vu0_regs.txt): retail's VU0 moves around an asm block are compiler insns that
    GCC schedules and puts in delay slots itself, which only `"j"` operands under this option reproduce (docs/contributing/matching.md)."""
    return listed_functions('vu0_regs.txt')


def vu0_for(address):
    return os.environ.get('TRY_VU0') == '1' or address in vu0_functions()


def sony_functions():
    """Addresses of the functions built with Sony's gcc 2.9 (config/us/sony_gcc29.txt): the libgcc and libc units of the SDK range."""
    return listed_functions('sony_gcc29.txt')


def assembler_for(address):
    """'sony29' for a function listed in config/us/sony_gcc29.txt (compiler and assembler both Sony's), else None: the one assembler, tools/ee-as/as.exe."""
    return 'sony29' if address in sony_functions() else None


def compiler_directory():
    """The SN compiler: EE_GCC_DIR (one run of a probe, scripts/matching/compiler_probe.py) replaces the pinned build 1.36; a build never sets it."""
    if os.environ.get('EE_GCC_DIR'):
        return os.environ['EE_GCC_DIR']
    return COMPILER if os.path.isdir(os.path.join(COMPILER, 'bin')) else LEGACY_COMPILER


def make_assembler():
    """tools/ps2eeas/Ps2EeAs-loop5.exe: the pinned Ps2EeAs.exe with one byte changed (made when missing or older than the pinned binary)."""
    if not os.path.isfile(EE_AS_PINNED):
        return False
    if not os.path.isfile(EE_AS_BUILD) or os.path.getmtime(EE_AS_BUILD) < os.path.getmtime(EE_AS_PINNED):
        data = bytearray(open(EE_AS_PINNED, 'rb').read())
        if data[SHORT_LOOP_OFFSET] != 6:
            raise SystemExit(f'{EE_AS_PINNED}: not the pinned 1.9.25.758 build (byte {SHORT_LOOP_OFFSET:#x} is {data[SHORT_LOOP_OFFSET]}, not 6)')
        data[SHORT_LOOP_OFFSET] = 5
        temporary = f'{EE_AS_BUILD}.{os.getpid()}'
        open(temporary, 'wb').write(data)
        os.replace(temporary, EE_AS_BUILD)
    return True


def compile_sony(language, source, output, include=None, localize=True):
    """The SDK range: Sony's ee-gcc 2.9-ee-991111 and the `ee/bin/as.exe` its driver runs (SN's compiler and ps2eeas give other saves and slots there)."""
    directory = SONY_COMPILER if os.path.isdir(os.path.join(SONY_COMPILER, 'bin')) else LEGACY_SONY_COMPILER
    version = os.listdir(os.path.join(directory, 'lib', 'gcc-lib', 'ee'))[0]
    temporary = output + '.tmp'
    result = subprocess.run([WIBO, os.path.join(directory, 'bin', 'ee-gcc.exe'), '-x', language, f'-B{os.path.join(directory, "lib", "gcc-lib", "ee", version)}/',
                             f'-I{include or os.path.join(ROOT, "include")}', *SONY_FLAGS, '-c', os.path.abspath(source), '-o', temporary], capture_output=True, text=True)
    if result.returncode or not os.path.exists(temporary):
        return False, result.stderr or result.stdout
    if localize:
        subprocess.run([OBJCOPY, '-w', '-L', '*', temporary, output], check=True)
        os.remove(temporary)
    else:
        os.replace(temporary, output)
    return True, ''


def compile_object(language, source, output, assembler=None, include=None, localize=True, vu0=False):
    """Compiles `source` to `output` (a relocatable object, its symbols local unless `localize` is false). Returns (ok, message)."""
    if assembler == 'sony29':
        return compile_sony(language, source, output, include, localize)
    directory = compiler_directory()
    version = os.listdir(os.path.join(directory, 'lib', 'gcc-lib', 'ee'))[0]
    common = [WIBO, os.path.join(directory, 'bin', 'ee-gcc.exe'), '-x', language, f'-B{os.path.join(directory, "lib", "gcc-lib", "ee", version)}/',
              f'-I{include or os.path.join(ROOT, "include")}', *FLAGS, *([VU0_FLAG] if vu0 else [])]
    if EE_AS == EE_AS_BUILD:
        make_assembler()
    if not os.path.isfile(EE_AS):
        return False, f'{EE_AS} is missing: run ./setup.sh --assembler'
    temporary = output + '.tmp'
    assembly = output + '.s'
    result = subprocess.run([*common, '-S', os.path.abspath(source), '-o', assembly], capture_output=True, text=True)
    if result.returncode:
        return False, result.stderr or result.stdout
    text = open(assembly).read()
    open(assembly, 'w').write(hoist_externs(text))
    assembler_flags = os.environ['EE_AS_ARGS'].split() if os.environ.get('EE_AS_ARGS') else [flag for flag in FLAGS if flag.startswith('-G')]
    for attempt in range(3):  # under a parallel build the assembler (under wibo) now and then never returns; a rerun takes a fraction of a second
        try:
            result = subprocess.run([WIBO, EE_AS, *assembler_flags, '-o', temporary, assembly], capture_output=True, text=True, timeout=20)
            break
        except subprocess.TimeoutExpired:
            if attempt == 2:
                os.remove(assembly)
                return False, 'the assembler timed out'
    os.remove(assembly)
    if result.returncode or not os.path.exists(temporary):
        return False, result.stderr or result.stdout
    if localize:
        subprocess.run([OBJCOPY, '-w', '-L', '*', temporary, output], check=True)
        os.remove(temporary)
    else:
        os.replace(temporary, output)
    return True, ''


def main():
    if sys.argv[1:] == ['--make-assembler']:
        if not make_assembler():
            sys.exit(f'{EE_AS_PINNED} is missing: run ./setup.sh --assembler')
        return
    parser = argparse.ArgumentParser()
    parser.add_argument('language', choices=['c', 'c++'])
    parser.add_argument('source')
    parser.add_argument('output')
    parser.add_argument('--vu0', action='store_true', help='compile with ' + VU0_FLAG)
    parser.add_argument('--assembler', choices=['sony29'])
    arguments = parser.parse_args()
    ok, message = compile_object(arguments.language, arguments.source, arguments.output, arguments.assembler, vu0=arguments.vu0)
    if not ok:
        sys.stderr.write(message)
        sys.exit(1)


if __name__ == '__main__':
    main()
