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
several functions can be linked together. A whole-file source (config/us/whole_files.tsv) includes its unmatched functions with
INCLUDE_ASM(address) at file scope: the marker it leaves in the compiler's assembly is replaced by that function's Splat assembly
(build/splat/asm) before ps2eeas runs, so the file assembles as one object in retail's order.

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
SONY_FLAGS = os.environ['SONY_COMPILE_FLAGS'].split() if os.environ.get('SONY_COMPILE_FLAGS') else ['-O2', '-G0']  # the variable is for SDK-range probes
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


INCLUDE_ASM_MARKER = re.compile(r'^[ \t]*\.include_asm[ \t]+(0[xX][0-9A-Fa-f]+)[ \t]*$', re.M)  # what include/include_asm.h's INCLUDE_ASM(address) writes
SPLAT_COMMENT = re.compile(r'/\*.*?\*/')
SPLAT_ENCODING = re.compile(r'\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/')  # Splat's comment: file offset, address, the word's bytes
# instructions that ps2eeas does not read as spimdisasm writes them, emitted as the word Splat's comment gives (none takes a relocation):
# `c1 0x...` (a COP1 operation spimdisasm names only by its function, the R5900's sqrt.s forms; ps2eeas has no `c1`) and `vadda`
# (spimdisasm prints ft before fs, ps2eeas reads fs first). Measured over every game function (docs/ROADMAP.md item 2, stage 4).
SPELLED_AS_WORD = {'c1', 'vadda'}


@functools.lru_cache(maxsize=None)
def splat_functions():
    """{address: assembly lines} of every function in build/splat/asm (make elf's split), as scripts/build/asm_units.py cuts them."""
    if os.path.dirname(os.path.abspath(__file__)) not in sys.path:
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from asm_units import read_units
    return {function['address']: function['lines'] for function in read_units(os.path.join(ROOT, 'build', 'splat'))[1]}


def splat_for_ps2eeas(lines):
    """One function of Splat's assembly as ps2eeas reads it: spimdisasm's comments and the `.size` lines dropped, `glabel`/`jlabel`/`dlabel` as
    plain labels, the instructions of SPELLED_AS_WORD as their word, between `.set noreorder` and `.set reorder` (Splat writes every delay slot itself). Macro mode stays on: ps2eeas refuses a
    backward branch in a short loop under `.set nomacro`, although retail's loop is already padded and nothing is added (the build compares)."""
    body = []
    for line in lines:
        text = SPLAT_COMMENT.sub('', line).strip()
        if not text or text.startswith('.size '):
            continue
        encoding = SPLAT_ENCODING.match(line)
        if text.split()[0] in ('glabel', 'jlabel', 'dlabel'):
            body.append(text.split()[1] + ':')
        elif encoding and text.split()[0].split('.')[0] in SPELLED_AS_WORD:
            body.append(f"\t.word\t{int.from_bytes(bytes.fromhex(encoding.group(1)), 'little'):#010x}")
        else:
            body.append(text if text.endswith(':') else '\t' + text)
    return '\n'.join(['\t.set\tnoreorder', '\t.set\tnoat', *body, '\t.set\tat', '\t.set\treorder'])


def expand_include_asm(assembly, functions=None):
    """The compiler's assembly with every `.include_asm <address>` line (a whole-file source's INCLUDE_ASM) replaced by that function's Splat
    assembly. `functions` ({address: lines}) defaults to build/splat; a missing address raises KeyError."""
    if not INCLUDE_ASM_MARKER.search(assembly):
        return assembly
    functions = functions if functions is not None else splat_functions()
    return INCLUDE_ASM_MARKER.sub(lambda match: splat_for_ps2eeas(functions[int(match.group(1), 16)]), assembly)


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


def includes_vu0_helpers(text):
    """True when a source includes include/vu0inline.h. Its helpers take `"j"` operands, which GCC rejects ("Invalid `asm' statement") without
    VU0_FLAG, so such a source is always compiled with the flag: claim.py verify, adopt.py and record.py judge it right without TRY_VU0=1."""
    return 'vu0inline.h' in text


MOVE_FLAG = '-fmove-all-movables'  # loop.c treats every loop-invariant movable as worth hoisting, not only the ones it judges profitable


def movables_functions():
    """Addresses of the functions compiled with MOVE_FLAG (config/us/move_movables.txt): retail's loop-invariant hoisting there is what this option gives
    and the default does not (docs/contributing/exceptions.md). Every function of src/ is its own source file, so this is that file's flag set."""
    return listed_functions('move_movables.txt')


def movables_for(address):
    return os.environ.get('TRY_MOVABLES') == '1' or address in movables_functions()


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


def compile_object(language, source, output, assembler=None, include=None, localize=True, vu0=False, movables=False):
    """Compiles `source` to `output` (a relocatable object, its symbols local unless `localize` is false). Returns (ok, message)."""
    if assembler == 'sony29':
        return compile_sony(language, source, output, include, localize)
    if not vu0:
        with open(source, encoding='utf-8', errors='replace') as handle:
            vu0 = includes_vu0_helpers(handle.read())
    directory = compiler_directory()
    version = os.listdir(os.path.join(directory, 'lib', 'gcc-lib', 'ee'))[0]
    common = [WIBO, os.path.join(directory, 'bin', 'ee-gcc.exe'), '-x', language, f'-B{os.path.join(directory, "lib", "gcc-lib", "ee", version)}/',
              f'-I{include or os.path.join(ROOT, "include")}', *FLAGS, *([VU0_FLAG] if vu0 else []), *([MOVE_FLAG] if movables else [])]
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
    try:
        text = expand_include_asm(text)
    except KeyError as error:
        os.remove(assembly)
        return False, f'INCLUDE_ASM({int(error.args[0]):#X}): no function starts there in build/splat/asm (run make elf first)'
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
    parser.add_argument('--movables', action='store_true', help='compile with ' + MOVE_FLAG)
    parser.add_argument('--assembler', choices=['sony29'])
    arguments = parser.parse_args()
    ok, message = compile_object(arguments.language, arguments.source, arguments.output, arguments.assembler, vu0=arguments.vu0, movables=arguments.movables)
    if not ok:
        sys.stderr.write(message)
        sys.exit(1)


if __name__ == '__main__':
    main()
