#!/bin/bash
# SPDX-License-Identifier: GPL-3.0-or-later
# Compile one source with a PS2 compiler and compare one function with the game ELF.
# Usage: judge.sh <compiler> "<flags>" <source.cpp> <function address> [symbol]
#   compiler: a directory name under compilers/ (ee-gcc2.95.3-136, ee-gcc2.95.2-SN-v2.73a, ...)
#   flags:    e.g. "-O2 -G0"; the language (-x c++) and -B are added here
#   symbol:   function in the object (exact, mangled prefix "Name" for Name__..., or substring);
#             optional when the object holds one function
# Environment: TARGET_ELF (default Sly 2 SCUS_973.16), TARGET_EXPORT (jsonl with sizes; default sly2.jsonl,
#   "none" to use the object's function size), QUIET=1 for the score line only.
# Prints "score N" (0 = match after masking relocated fields) and an instruction diff (target | ours).
set -euo pipefail

if [ $# -lt 4 ]; then
    sed -n '3,12p' "$0"
    exit 2
fi

# the scripts live in scripts/matching, the compilers, wibo, the venv and build output in work/matching (git-ignored:
# set up by the 2026-10-25 probe, see docs/build/decompilation.md)
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
LAB_DIR="$(cd "$SCRIPT_DIR/../.." && pwd)"
MATCHING_DIR="$LAB_DIR/work/matching"
compiler_name="$1"
flags="$2"
source_path="$3"
address="$4"
symbol="${5:-}"

compiler_dir="$MATCHING_DIR/compilers/$compiler_name"
[ -d "$compiler_dir/cc" ] && compiler_dir="$compiler_dir/cc"
target_elf="${TARGET_ELF:-$LAB_DIR/work/elf/SCUS_973.16}"
target_export="${TARGET_EXPORT:-$LAB_DIR/work/export/sly2.jsonl}"
build_dir="$MATCHING_DIR/build/$compiler_name"
mkdir -p "$build_dir"
object_path="$build_dir/$(basename "${source_path%.*}").o"

case "$compiler_name" in
    ee-gcc2.*)
        version="$(ls "$compiler_dir/lib/gcc-lib/ee/")"
        # shellcheck disable=SC2086
        "$MATCHING_DIR/tools/wibo-macos" "$compiler_dir/bin/ee-gcc.exe" -c -x c++ \
            -B"$compiler_dir/lib/gcc-lib/ee/$version/" $flags "$source_path" -o "$object_path"
        ;;
    mwcps2-*)
        # shellcheck disable=SC2086
        "$MATCHING_DIR/tools/wibo-macos" "$compiler_dir"/mwcc*.exe -c -lang c++ $flags "$source_path" -o "$object_path"
        ;;
    *)
        echo "unknown compiler family: $compiler_name" >&2
        exit 2
        ;;
esac

compare_arguments=("$object_path" "$address" --elf "$target_elf")
[ "$target_export" != "none" ] && compare_arguments+=(--export "$target_export")
[ -n "$symbol" ] && compare_arguments+=(--symbol "$symbol")
[ "${QUIET:-0}" = "1" ] && compare_arguments+=(--quiet)
"$MATCHING_DIR/venv/bin/python" "$SCRIPT_DIR/compare.py" "${compare_arguments[@]}"
