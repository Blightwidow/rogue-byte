#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""proprietary.py: finds game data and proprietary material in the files git would commit (tracked files, and untracked ones
that are not ignored). Run from anywhere: `python3 scripts/proprietary.py`; tests/check_repository.py runs it in CI.

It rejects:
- binaries, disc images and their sidecar files, archives, objects, libraries, executables (by suffix, and by an ELF or PE header);
- files in a folder that holds game data, build output or a toolchain (`work/`, `build/`, `baserom/`, `asm/`, `assets/game/`, ...);
- includes of Sony SDK headers and Sony SDK copyright or confidentiality banners;
- splat disassembly (its `/* address word */` comments), wherever it is pasted;
- runs of hex byte literals long enough to be a dump of retail data;
- files over 512 KiB, except the generated progress reports (up to 2.5 MB)."""
import re
import subprocess
import sys
from pathlib import Path

MAX_BYTES = 512 * 1024
LARGE_OK = re.compile(r'^progress/[a-z0-9_]+/report\.json$')
LARGE_MAX = 2_500_000
BINARY_SUFFIXES = {
    '.iso', '.img', '.bin', '.cue', '.ccd', '.sub', '.mdf', '.mds', '.nrg', '.chd', '.cso',
    '.elf', '.irx', '.erx', '.o', '.obj', '.a', '.lib', '.so', '.dylib', '.dll', '.exe',
    '.wal', '.wac', '.7z', '.zip', '.gz', '.tgz', '.xz', '.bz2', '.rar', '.tar', '.zst',
}
FORBIDDEN_FOLDERS = ('work/', 'build/', 'baserom/', 'asm/', 'assets/game/', 'discs/', 'tools/ext/', 'toolchain/', 'data/matching/')
SDK_INCLUDE = re.compile(r'#\s*include\s*[<"](?:eekernel|eeregs|libgraph|libdma|libpkt|libvu0|libipu|libmpeg|sifdev|sifrpc|sifcmd|libcdvd|libpad|libmc|sceerrno|devvu0|devvif0|devgif|devvif1|eestruct|libvifpk|libgifpk)\.h[>"]')
SDK_BANNER = re.compile(r'Sony Computer Entertainment Inc\.?\s+(?:All Rights Reserved|Confidential)|SCEI\s+Confidential', re.IGNORECASE)
DISASSEMBLY = re.compile(r'/\*\s*[0-9A-F]{4,8}\s+[0-9A-F]{8}\s+[0-9A-F]{8}\s*\*/')
HEX_RUN = re.compile(r'(?:0x[0-9A-Fa-f]{2}\s*,\s*){64,}')
TEXT_SUFFIXES_SKIPPED = {'.png', '.jpg', '.svg', '.ico', '.pdf'}


def tracked(root):
    """Paths relative to root of what git would commit: tracked files, and untracked ones that are not ignored."""
    output = subprocess.check_output(['git', 'ls-files', '--cached', '--others', '--exclude-standard', '-z'], cwd=root)
    return sorted(path for path in output.decode('utf-8').split('\0') if path and (Path(root) / path).is_file())


def scan(root):
    """The problems of what git would commit, as strings; empty when it is clean."""
    root = Path(root)
    errors = []
    for relative in tracked(root):
        path = root / relative
        suffix = path.suffix.lower()
        if suffix in BINARY_SUFFIXES:
            errors.append(f'{relative}: a binary, archive or disc file')
            continue
        if relative.startswith(FORBIDDEN_FOLDERS):
            errors.append(f'{relative}: in a folder for game data, build output or a toolchain')
            continue
        size = path.stat().st_size
        if suffix not in TEXT_SUFFIXES_SKIPPED and size > (LARGE_MAX if LARGE_OK.match(relative) else MAX_BYTES):
            errors.append(f'{relative}: {size} bytes, over the limit')
            continue
        with open(path, 'rb') as handle:
            head = handle.read(4)
        if head[:4] == b'\x7fELF' or head[:2] == b'MZ':
            errors.append(f'{relative}: an ELF or PE executable')
            continue
        if suffix in TEXT_SUFFIXES_SKIPPED or b'\0' in head:
            continue
        try:
            text = path.read_text(encoding='utf-8')
        except UnicodeDecodeError:
            continue
        for what, pattern in (('a Sony SDK include', SDK_INCLUDE), ('a Sony SDK banner', SDK_BANNER),
                              ('splat disassembly', DISASSEMBLY), ('a dump of hex bytes', HEX_RUN)):
            if relative in ('scripts/proprietary.py',):
                continue
            if pattern.search(text):
                errors.append(f'{relative}: {what}')
    return errors


def main():
    root = Path(__file__).resolve().parent.parent
    errors = scan(root)
    for error in errors:
        print(f'error: {error}')
    print(f'{"FAIL" if errors else "ok"}: {len(errors)} problem(s)')
    return 1 if errors else 0


if __name__ == '__main__':
    sys.exit(main())
