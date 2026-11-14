#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""compile_unit.py <c|c++> <source> <output.o> [--assembler sony29|sony29-01]: compiles one source the way the retail build did.

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
ee-gcc 2.9-ee-991111 and its driver (config/us/sony_gcc29.txt); `--assembler sony29-01` builds the libm functions that divide with Sony's
2.9-ee-991111-01 (config/us/sony_gcc29_01.txt), a Linux i386 build that Docker runs on a Mac and that `configure.py` leaves out (their functions
then come from assembly, the image the same) when nothing can run it. Symbols of the object are made local (objcopy -L) so that objects of
several functions can be linked together. A whole-file source (config/us/whole_files.tsv) includes its unmatched functions with
INCLUDE_ASM(address) at file scope: the marker it leaves in the compiler's assembly is replaced by that function's Splat assembly
(build/splat/asm) before ps2eeas runs, so the file assembles as one object in retail's order.

EE_AS_EXE and EE_AS_ARGS in the environment replace the assembler and its arguments for one run: scripts/matching/assembler_probe.py sets
them to measure a candidate, and a build never does (docs/build/assembler.md, "Before changing the assembler").
`compile_unit.py --make-assembler` makes the patched copy and exits (setup.sh runs it)."""
import argparse
import functools
import os
import platform
import re
import shutil
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
COMPILER = os.path.join(ROOT, 'tools', 'compilers', 'ee-gcc2.95.3-136')
LEGACY_COMPILER = os.path.join(ROOT, 'work', 'matching', 'compilers', 'ee-gcc2.95.3-136')
SONY_COMPILER = os.path.join(ROOT, 'tools', 'compilers', 'ee-gcc2.9-991111b')
LEGACY_SONY_COMPILER = os.path.join(ROOT, 'work', 'toolchains', 'ee-gcc2.9-991111b')
SONY_01_COMPILER = os.path.join(ROOT, 'tools', 'compilers', 'ee-gcc2.9-991111-01')  # Sony's later 2.9 build: a Linux i386 program (the others are Win32)
LEGACY_SONY_01_COMPILER = os.path.join(ROOT, 'work', 'toolchains', 'ee-gcc2.9-991111-01')
LINUX_IMAGE = 'i386/debian:bookworm-slim'  # runs the Linux build on a host that is not x86 Linux
DOCKER_APPLICATION = '/Applications/Docker.app/Contents/Resources/bin/docker'
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


@functools.lru_cache(maxsize=None)
def function_flags():
    """{address: [flags]} of config/us/function_flags.tsv (address, flags, note): extra compiler options of one function, which is its own source file
    (a whole file has one flag set: its functions take none from here). Measured, not a build setting: docs/build/inline-asm-helpers.md "Other compiler
    flags per function"."""
    path = os.path.join(ROOT, 'config', 'us', 'function_flags.tsv')
    found = {}
    if os.path.exists(path):
        with open(path) as listing:
            for line in list(listing)[1:]:
                fields = line.rstrip('\n').split('\t')
                if len(fields) >= 2 and fields[0].strip():
                    found[int(fields[0], 16)] = fields[1].split()
    return found


def flags_for(address):
    return function_flags().get(address, [])


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


def sony_01_functions():
    """Addresses of the functions built with Sony's gcc 2.9-ee-991111-01 (config/us/sony_gcc29_01.txt): the libm functions that divide.
    That build writes `nop; nop; div.s` itself (retail's libm has it before all 27 divides); 991111b, which the rest of the SDK range uses, does not."""
    return listed_functions('sony_gcc29_01.txt')


def assembler_for(address):
    """'sony29-01' for a function of config/us/sony_gcc29_01.txt, 'sony29' for one of config/us/sony_gcc29.txt (compiler and assembler both Sony's), else None: the one assembler, tools/ps2eeas."""
    if address in sony_01_functions():
        return 'sony29-01'
    return 'sony29' if address in sony_functions() else None


def sony_01_directory():
    """The directory of the 2.9-ee-991111-01 build (tools/compilers, else work/toolchains), or None when it is not installed."""
    for directory in (SONY_01_COMPILER, LEGACY_SONY_01_COMPILER):
        if os.path.isfile(os.path.join(directory, 'bin', 'ee-gcc')):
            return directory
    return None


@functools.lru_cache(maxsize=None)
def linux_runner():
    """The command words that run a Linux i386 program on this host, or None when nothing can: EE_LINUX_RUNNER (a command prefix, for one run), nothing on x86
    Linux, else `docker run` (Docker Desktop's CLI is not on PATH on macOS; its socket is ~/.docker/run/docker.sock) when the daemon answers."""
    if os.environ.get('EE_LINUX_RUNNER'):
        return os.environ['EE_LINUX_RUNNER'].split()
    if platform.system() == 'Linux' and platform.machine() in ('x86_64', 'i686', 'i386'):
        return []
    docker = shutil.which('docker') or (DOCKER_APPLICATION if os.path.isfile(DOCKER_APPLICATION) else None)
    if not docker:
        return None
    socket_path = os.path.expanduser('~/.docker/run/docker.sock')
    if not os.environ.get('DOCKER_HOST') and os.path.exists(socket_path):
        os.environ['DOCKER_HOST'] = f'unix://{socket_path}'
    try:
        if subprocess.run([docker, 'info'], capture_output=True, timeout=30).returncode:
            return None
    except (OSError, subprocess.TimeoutExpired):
        return None
    return [docker, 'run', '--rm', '--platform', 'linux/386']


def runner_is_docker(runner):
    """True for the `docker run` prefix of `linux_runner`: the build's directories are mounted into the container at the same paths; the program runs in `workdir` (default the repository), where a compiler writes its dump files without -g."""
    return len(runner) > 1 and os.path.basename(runner[0]) == 'docker' and runner[1] == 'run' and os.environ.get('EE_LINUX_RUNNER') is None


def sony_01_available():
    """True when the 991111-01 build is installed and something can run it (the functions of config/us/sony_gcc29_01.txt then come from C, else from assembly)."""
    return sony_01_directory() is not None and linux_runner() is not None


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
    return finish_sony(result, temporary, output, localize)


def compile_sony_01(language, source, output, include=None, localize=True):
    """The libm functions that divide: Sony's ee-gcc 2.9-ee-991111-01 and its own assembler, a Linux i386 build run by `linux_runner` (Docker on a Mac)."""
    directory = sony_01_directory()
    runner = linux_runner()
    if directory is None:
        return False, 'ee-gcc2.9-991111-01 is not installed (tools/compilers or work/toolchains)'
    if runner is None:
        return False, 'nothing runs the Linux ee-gcc2.9-991111-01: start Docker, or set EE_LINUX_RUNNER'
    include = os.path.abspath(include or os.path.join(ROOT, 'include'))
    source = os.path.abspath(source)
    temporary = os.path.abspath(output) + '.tmp'
    command = [os.path.join(directory, 'bin', 'ee-gcc'), '-x', language, f'-B{os.path.join(directory, "bin", "ee-")}', f'-I{include}', *SONY_FLAGS, '-c', source, '-o', temporary]
    result = subprocess.run(linux_command(runner, command, directory, include, source, temporary), capture_output=True, text=True)
    return finish_sony(result, temporary, output, localize)


def linux_command(runner, command, directory, include, source, output, workdir=None):
    """`command` (a Linux program) behind `runner`: as it is on a host that runs it, else in the container with the build's directories mounted at the same paths."""
    if not runner_is_docker(runner):
        return [*runner, *command]  # a host that runs the program, or a runner the caller gave
    mounts = []
    for path in (ROOT, directory, include, os.path.dirname(source), os.path.dirname(output)):
        if not any(path == mount or path.startswith(mount + os.sep) for mount in mounts):
            mounts = [mount for mount in mounts if not mount.startswith(path + os.sep)] + [path]
    return [*runner, *[word for mount in mounts for word in ('-v', f'{mount}:{mount}')], '-w', workdir or ROOT, LINUX_IMAGE, *command]


def compile_assembly(language, source, output, assembler=None, extra=(), vu0=False, movables=False, flags=()):
    """The compiler's assembly (`-S`) for `source` in `output` with the build's compiler and flags plus `extra` (the register allocator's dumps, `-dl -dg -dp`, land
    beside it): scripts/matching/regalloc.py reads them. Returns (ok, message). No INCLUDE_ASM expansion and no assembler run."""
    source = os.path.abspath(source)
    output = os.path.abspath(output)
    include = os.path.join(ROOT, 'include')
    if assembler == 'sony29-01':
        directory, runner = sony_01_directory(), linux_runner()
        if directory is None or runner is None:
            return False, 'ee-gcc2.9-991111-01 is not installed or nothing runs it (start Docker, or set EE_LINUX_RUNNER)'
        command = [os.path.join(directory, 'bin', 'ee-gcc'), '-x', language, f'-B{os.path.join(directory, "bin", "ee-")}', f'-I{include}', *SONY_FLAGS, *extra, '-S', source, '-o', output]
        result = subprocess.run(linux_command(runner, command, directory, include, source, output, os.path.dirname(output)), capture_output=True, text=True, cwd=os.path.dirname(output))
    else:
        if assembler == 'sony29':
            directory = SONY_COMPILER if os.path.isdir(os.path.join(SONY_COMPILER, 'bin')) else LEGACY_SONY_COMPILER
            options = SONY_FLAGS
        else:
            directory = compiler_directory()
            if not vu0:
                with open(source, encoding='utf-8', errors='replace') as handle:
                    vu0 = includes_vu0_helpers(handle.read())
            options = [*FLAGS, *([VU0_FLAG] if vu0 else []), *([MOVE_FLAG] if movables else []), *flags]
        version = os.listdir(os.path.join(directory, 'lib', 'gcc-lib', 'ee'))[0]
        result = subprocess.run([WIBO, os.path.join(directory, 'bin', 'ee-gcc.exe'), '-x', language, f'-B{os.path.join(directory, "lib", "gcc-lib", "ee", version)}/',
                                 f'-I{include}', *options, *extra, '-S', source, '-o', output], capture_output=True, text=True, cwd=os.path.dirname(output))
    if result.returncode or not os.path.exists(output):
        return False, result.stderr or result.stdout
    return True, ''


def finish_sony(result, temporary, output, localize):
    """The object a Sony build wrote (its symbols local unless `localize` is false), or the compiler's message."""
    if result.returncode or not os.path.exists(temporary):
        return False, result.stderr or result.stdout
    if localize:
        subprocess.run([OBJCOPY, '-w', '-L', '*', temporary, output], check=True)
        os.remove(temporary)
    else:
        os.replace(temporary, output)
    return True, ''


def compile_object(language, source, output, assembler=None, include=None, localize=True, vu0=False, movables=False, flags=()):
    """Compiles `source` to `output` (a relocatable object, its symbols local unless `localize` is false). Returns (ok, message)."""
    if assembler == 'sony29-01':
        return compile_sony_01(language, source, output, include, localize)
    if assembler == 'sony29':
        return compile_sony(language, source, output, include, localize)
    if not vu0:
        with open(source, encoding='utf-8', errors='replace') as handle:
            vu0 = includes_vu0_helpers(handle.read())
    directory = compiler_directory()
    version = os.listdir(os.path.join(directory, 'lib', 'gcc-lib', 'ee'))[0]
    common = [WIBO, os.path.join(directory, 'bin', 'ee-gcc.exe'), '-x', language, f'-B{os.path.join(directory, "lib", "gcc-lib", "ee", version)}/',
              f'-I{include or os.path.join(ROOT, "include")}', *FLAGS, *([VU0_FLAG] if vu0 else []), *([MOVE_FLAG] if movables else []), *flags]
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
    parser.add_argument('--flags', default='', help='more compiler options, space separated (config/us/function_flags.tsv)')
    parser.add_argument('--assembler', choices=['sony29', 'sony29-01'])
    arguments = parser.parse_args()
    ok, message = compile_object(arguments.language, arguments.source, arguments.output, arguments.assembler, vu0=arguments.vu0, movables=arguments.movables, flags=arguments.flags.split())
    if not ok:
        sys.stderr.write(message)
        sys.exit(1)


if __name__ == '__main__':
    main()
