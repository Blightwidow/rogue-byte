#!/bin/bash
# SPDX-License-Identifier: GPL-3.0-or-later
LAB=${ROGUE_BYTE_DIR:-$(cd "$(dirname "${BASH_SOURCE[0]:-$0}")/../.." && pwd)}
PORT=${GAME_DIR:-$LAB/work/game}
export LAB PORT
name=$(basename "$1" .c)
# shellcheck disable=SC2086  # CT_FLAGS is a list of flags: split on purpose
$LAB/work/compiler-test/cc.sh "$CT_COMPILER" "$1" "$CT_OUT/$name.o" $CT_FLAGS > "$CT_OUT/$name.log" 2>&1
