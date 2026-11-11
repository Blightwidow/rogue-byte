# SPDX-License-Identifier: GPL-3.0-or-later
"""The pre-commit check: no game data or proprietary material, licence headers present.

    python3 tests/check_repository.py

CI runs it on every pull request. It looks at what git would commit (tracked files and untracked ones that are not ignored), and
needs no disc and no compiler.

1. scripts/proprietary.py: no binaries, disc images, game data, generated assembly, toolchains, Sony SDK headers or banners.
2. Every source file starts with the GPL-3.0-or-later SPDX line.
3. LICENSE is the GNU General Public License.
"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'scripts'))
sys.path.insert(0, str(ROOT / 'scripts' / 'matching'))
import proprietary  # noqa: E402
import check_source  # noqa: E402

SPDX = 'SPDX-License-Identifier: GPL-3.0-or-later'
NEEDS_SPDX = {'.py', '.sh', '.c', '.cpp', '.h', '.hpp', '.s', '.inc', '.ld'}
# Reconstructed game code (src/, nonmatching/) and the data-like generated headers carry no tool header.
EXEMPT = ('src/', 'nonmatching/', 'include/', 'data/', 'config/')


def main():
    errors = proprietary.scan(ROOT)
    for relative in proprietary.tracked(ROOT):
        path = ROOT / relative
        if relative.startswith(EXEMPT) or path.suffix not in NEEDS_SPDX:
            continue
        if SPDX not in path.read_text(encoding='utf-8', errors='replace')[:400]:
            errors.append(f"{relative}: no '{SPDX}' line at the top")
    # game data defined in source (config/us/data_files.tsv): the marker on every definition, no dump in bytes or plain words
    # (docs/contributing/exceptions.md "Game data defined in source")
    data_list = ROOT / 'config' / 'us' / 'data_files.tsv'
    for line in (data_list.read_text(encoding='utf-8').splitlines()[1:] if data_list.exists() else []):
        source = 'src/' + line.split('\t')[2]
        for number, kind, message in check_source.data_definitions((ROOT / source).read_text(encoding='utf-8')):
            if kind == 'banned':
                errors.append(f'{source}:{number}: {message}')
    if 'GNU GENERAL PUBLIC LICENSE' not in (ROOT / 'LICENSE').read_text(encoding='utf-8')[:200].upper():
        errors.append('LICENSE: not the GNU General Public License')
    for error in errors:
        print('error: ' + error)
    print('%s: %d problem(s)' % ('FAIL' if errors else 'ok', len(errors)))
    return 1 if errors else 0


if __name__ == '__main__':
    sys.exit(main())
