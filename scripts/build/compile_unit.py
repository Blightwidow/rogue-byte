#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""compile_unit.py <c|c++> <source> <output.o> [--assembler ps2eeas|ps2eeas-loop5|gnu]: compiles one source the way the retail build did.

SN's compiler (EE-GCC 2.95.3 build 1.36) writes assembly, and retail's assembler was SN's own `ps2eeas`, which differs from the GNU `as`
the compiler driver calls: it adds the hazard nops of the R5900 (between `mtc1` and the instruction that reads the register, between a
float compare and `bc1`), pads short loops, and picks other sequences for 64-bit constants. So by default the compiler runs with `-S` and
tools/ps2eeas/Ps2EeAs.exe (`setup.sh --ps2eeas` downloads it, pinned) assembles the result under wibo. `--assembler gnu`, and the
fallback when Ps2EeAs.exe is missing, use the driver's GNU `as`. `ps2eeas` assembles in one pass and only reaches a global through `$gp`
when it has already seen the symbol's size, so the compiler's `.extern SYM,SIZE` lines, written at the end of the file, go to the top.
`--assembler ps2eeas-loop5` is the same assembler with its short-loop padding one nop shorter (retail's shortest loop is five
instructions before the delay slot, `ps2eeas` 3.01 pads to six; see docs/build/assembler.md). Symbols of the object are made local (objcopy -L) so that objects of several functions can be linked together."""
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
PS2EEAS = os.path.join(ROOT, 'tools', 'ps2eeas', 'Ps2EeAs.exe')
PS2EEAS_LOOP5 = os.path.join(ROOT, 'tools', 'ps2eeas', 'Ps2EeAs-loop5.exe')
LOOP_LENGTH_OFFSET = 0x4DEB  # in Ps2EeAs.exe 1.9.25.758: the 6 of "pad a backward-branch loop up to six instructions"
OBJCOPY = os.path.join(ROOT, 'tools', 'binutils-mips-ps2-decompals', 'mips-ps2-decompals-objcopy')
FLAGS = os.environ['COMPILE_FLAGS'].split() if os.environ.get('COMPILE_FLAGS') else ['-O2', '-G0', '-ffast-math', '-fno-exceptions']  # the variable is for flag sweeps


def hoist_externs(assembly):
    """The assembly with its `.extern` lines moved in front of everything else (ps2eeas needs a symbol's size before its first use)."""
    lines = assembly.split('\n')
    externs = [line for line in lines if re.match(r'\s*\.extern\s', line)]
    return '\n'.join(externs + [line for line in lines if not re.match(r'\s*\.extern\s', line)])


BRANCH = re.compile(r'\s*(b|j|jal|jr|jalr|beq|bne|beqz|bnez|bgez|bgtz|blez|bltz|bc1[tf]l?|beql|bnel|bgezal|bltzal)\s')
COPROCESSOR_2 = re.compile(r'(qmtc2|qmfc2|lqc2|sqc2|ctc2|cfc2|v[a-z0-9]+)(\.\w+)?\s')


def fills_delay_slot_from_asm(assembly):
    """True when an inline-asm block ends with a VU0 instruction (qmfc2, qmtc2, sqc2, lqc2, v*) and a branch or jump follows it right away.
    GCC leaves such a branch's delay slot for the assembler to fill, and retail's assembler moved the VU0 instruction into it; `ps2eeas`
    does not. Of the 3,500 matched sources none that has this shape assembles with `ps2eeas`; an inline-asm block ending in `mtc1` or `nop` does."""
    lines = assembly.split('\n')
    for index, line in enumerate(lines):
        if line.strip() == '#NO_APP' and index + 1 < len(lines) and BRANCH.match(lines[index + 1]):
            back = index - 1
            while back >= 0 and (not lines[back].strip() or lines[back].lstrip().startswith(('#', '.'))):
                back -= 1
            if back >= 0 and COPROCESSOR_2.match(lines[back].strip() + ' '):
                return True
    return False


@functools.lru_cache(maxsize=None)
def listed_functions(name):
    """Addresses listed in config/us/<name> (one per line, `#` comments)."""
    path = os.path.join(ROOT, 'config', 'us', name)
    if not os.path.exists(path):
        return set()
    with open(path) as listing:
        return {int(line.split()[0], 16) for line in listing if line.strip() and not line.startswith('#')}


def gnu_functions():
    """Addresses of the functions assembled with GNU as (config/us/gnu_as.txt)."""
    return listed_functions('gnu_as.txt')


def loop5_functions():
    """Addresses of the functions assembled with ps2eeas-loop5 (config/us/ps2eeas_loop5.txt)."""
    return listed_functions('ps2eeas_loop5.txt')


def sony_functions():
    """Addresses of the functions built with Sony's gcc 2.9 (config/us/sony_gcc29.txt): the libgcc and libc units of the SDK range."""
    return listed_functions('sony_gcc29.txt')


def assembler_for(address):
    """'sony29' for a function listed in config/us/sony_gcc29.txt (compiler and assembler both Sony's), 'ps2eeas-loop5' for a function listed in config/us/ps2eeas_loop5.txt, 'gnu' for one of config/us/gnu_as.txt, else None (ps2eeas when available)."""
    if address in sony_functions():
        return 'sony29'
    if address in loop5_functions():
        return 'ps2eeas-loop5'
    return 'gnu' if address in gnu_functions() else None


def loop5_executable():
    """tools/ps2eeas/Ps2EeAs-loop5.exe: Ps2EeAs.exe with one byte changed (made on first use, next to the original, never published)."""
    if not os.path.isfile(PS2EEAS):
        return None
    if not os.path.isfile(PS2EEAS_LOOP5) or os.path.getmtime(PS2EEAS_LOOP5) < os.path.getmtime(PS2EEAS):
        data = bytearray(open(PS2EEAS, 'rb').read())
        if data[LOOP_LENGTH_OFFSET] != 6:
            raise SystemExit(f'{PS2EEAS}: not the pinned 1.9.25.758 build (byte {LOOP_LENGTH_OFFSET:#x} is {data[LOOP_LENGTH_OFFSET]}, not 6)')
        data[LOOP_LENGTH_OFFSET] = 5
        temporary = f'{PS2EEAS_LOOP5}.{os.getpid()}'
        open(temporary, 'wb').write(data)
        os.replace(temporary, PS2EEAS_LOOP5)
    return PS2EEAS_LOOP5


def compiler_directory():
    return COMPILER if os.path.isdir(os.path.join(COMPILER, 'bin')) else LEGACY_COMPILER


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


def compile_object(language, source, output, assembler=None, include=None, localize=True):
    """Compiles `source` to `output` (a relocatable object, its symbols local unless `localize` is false). Returns (ok, message)."""
    if assembler == 'sony29':
        return compile_sony(language, source, output, include, localize)
    directory = compiler_directory()
    version = os.listdir(os.path.join(directory, 'lib', 'gcc-lib', 'ee'))[0]
    common = [WIBO, os.path.join(directory, 'bin', 'ee-gcc.exe'), '-x', language, f'-B{os.path.join(directory, "lib", "gcc-lib", "ee", version)}/',
              f'-I{include or os.path.join(ROOT, "include")}', *FLAGS]
    executable = loop5_executable() if assembler == 'ps2eeas-loop5' else PS2EEAS
    use_ps2eeas = assembler != 'gnu' and executable is not None and os.path.isfile(executable)
    temporary = output + '.tmp'
    if use_ps2eeas:
        assembly = output + '.s'
        result = subprocess.run([*common, '-S', os.path.abspath(source), '-o', assembly], capture_output=True, text=True)
        if result.returncode:
            return False, result.stderr or result.stdout
        text = open(assembly).read()
        if assembler is None and fills_delay_slot_from_asm(text):
            use_ps2eeas = False
            os.remove(assembly)
        else:
            open(assembly, 'w').write(hoist_externs(text))
            for attempt in range(3):  # under a parallel build ps2eeas (under wibo) now and then never returns; a rerun takes a fraction of a second
                try:
                    result = subprocess.run([WIBO, executable, '-G0', '-o', temporary, assembly], capture_output=True, text=True, timeout=20)
                    break
                except subprocess.TimeoutExpired:
                    if attempt == 2:
                        os.remove(assembly)
                        return False, 'ps2eeas timed out'
            os.remove(assembly)
    if not use_ps2eeas:
        result = subprocess.run([*common, '-c', os.path.abspath(source), '-o', temporary], capture_output=True, text=True)
    if result.returncode or not os.path.exists(temporary):
        return False, result.stderr or result.stdout
    if localize:
        subprocess.run([OBJCOPY, '-w', '-L', '*', temporary, output], check=True)
        os.remove(temporary)
    else:
        os.replace(temporary, output)
    return True, ''


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('language', choices=['c', 'c++'])
    parser.add_argument('source')
    parser.add_argument('output')
    parser.add_argument('--assembler', choices=['ps2eeas', 'ps2eeas-loop5', 'gnu', 'sony29'])
    arguments = parser.parse_args()
    ok, message = compile_object(arguments.language, arguments.source, arguments.output, arguments.assembler)
    if not ok:
        sys.stderr.write(message)
        sys.exit(1)


if __name__ == '__main__':
    main()
