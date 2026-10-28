#!/bin/bash
# SPDX-License-Identifier: GPL-3.0-or-later
# usage: cc.sh <compiler-id> <src> <out.o> [flags...]
# Runs a candidate EE compiler: SN/Win32 via wibo-macos, Linux i386 via docker (colima), mwcc via wibo.
LAB=${ROGUE_BYTE_DIR:-$(cd "$(dirname "${BASH_SOURCE[0]:-$0}")/../.." && pwd)}
PORT=${GAME_DIR:-$LAB/work/game}
export LAB PORT
set -e
LAB=$LAB
TC=$LAB/work/toolchains
id=$1; src=$2; out=$3; shift 3
d=$TC/$id
case $id in
  ee-gcc2.95.*)
    ver=$(ls "$d"/lib/gcc-lib/ee/)
    exec "$TC"/wibo/wibo-macos "$d"/bin/ee-gcc.exe -c -B"$d"/lib/gcc-lib/ee/"$ver"/ "$@" -o "$out" "$src" ;;
  mwcps2-*)
    exec "$TC"/wibo/wibo-macos "$d"/mwccps2.exe -c "$@" -o "$out" "$src" ;;
  *)
    exec docker run --rm --platform linux/386 -v $LAB:$LAB -w "$PWD" i386/debian:bookworm-slim \
      "$d"/bin/ee-gcc -c -B"$d"/bin/ee- "$@" -o "$out" "$src" ;;
esac
