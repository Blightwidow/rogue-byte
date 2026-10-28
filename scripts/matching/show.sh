#!/bin/bash
# SPDX-License-Identifier: GPL-3.0-or-later
# show.sh <hex addr>: Ghidra C + disassembly of one Sly 2 function
LAB=${ROGUE_BYTE_DIR:-$(cd "$(dirname "${BASH_SOURCE[0]:-$0}")/../.." && pwd)}
PORT=${GAME_DIR:-$LAB/work/game}
export LAB PORT
cd $LAB || exit 1
python3 - "$1" <<'PY'
import json,sys,subprocess
a=int(sys.argv[1],16)
for l in open('work/export/sly2_decompiled.jsonl'):
    d=json.loads(l)
    if d['entry']==a: print(d['name'], d['signature']); print(d['c'][:2500])
for l in open('work/export/sly2.jsonl'):
    d=json.loads(l)
    if d['entry']==a: size=d['size']
subprocess.run(['python3','work/compiler-test/eedis.py','%x'%a,'%x'%(a+size)])
PY
