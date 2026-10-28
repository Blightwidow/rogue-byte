# SlyMods wiki cross-check (2026-10-26)

Source: https://slymods.info/wiki/Sly_2:SEQ (modders' wiki, CC BY-SA 4.0; facts recorded here with attribution, no page text copied).
Checked against our decompiled code and its matched functions, not yet against a fresh Ghidra read.

The wiki's `CSeq` is the class our code calls `JSG` (the Sly 1 decomp's name: InitJsg, NextJsgJsge, AddJsgContext...) and, in some
files, `SEQ` (the Rust port's reading). Its `SEQI` is our `JSGE`, its `CSeqThread` our `SEQNODE`.

Which names are Sucker Punch's own is open. Nothing here shows the Sly 1 decomp's names are the original source's, and the modders say
the opcode spreadsheets they link give instruction names from two internal builds: if so, those are the better candidate for the real
names, and `CSeq`/`SEQI`/`CSeqThread` may be real too. Do not rename anything yet: read the spreadsheets, see whether they say CSeq or JSG,
then decide. Our code mixes `JSG` (PjsgeAllocJsg at 0x1E01F8) and `SEQ` (StartNextSeqnodeRecord at 0x1E1E30) today.

| Wiki offset / claim | Our code | Verdict |
|---|---|---|
| 0x50 instruction count | `PjsgeAllocJsg` 0x1E01F8: `cjsge` at +0x50 | agrees |
| 0x54 instruction array | same: `pjsge` array at +0x54, `PseqnodeNew` 0x1E5AE0 steps it by 0x50 | agrees, instruction = 0x50 bytes |
| 0x58 max count, MAX_COMMAND_COUNT option | same: `cjsgeMax` at +0x58, 0x200 when negative; a full script returns a dummy event | agrees (default 0x200 is new) |
| 0x5C list of threads | `PseqnodeNew`: `InsertDlEntry(owner+0x5C, node)` | agrees |
| 0x68 thread that ran CALL_SPLICE | `StartNextSeqnodeRecord` case 9: +0x68 = node around the script-message call, cleared after | agrees; CALL_SPLICE is record kind 9 |
| 0x6C pParentCaller (CSeq*) | same function: +0x6C is the last fallback for a record's subject object | **conflict**: ours is an object, not a sequence |
| 0x74 fFinished / 0x78 fRunning | `FSeqnodeRecordDone` kind 0xB: waiting on another sequence ends when its +0x74 is 0 | **suspect**: reads as "running" at 0x74; wiki may have 0x74/0x78 swapped |
| size 0xB0, 0x70 flRuntime, 0x7C, 0x80, 0x84/0x88 semaphores | not checked | open (needs the constructor / allocation size) |
| opcodes (external spreadsheets) | record kinds seen: 0 open block, 1 close, 2 stop node, 3 wait nodes, 4 wait signal, 5 set signal, 7 switch control, 8 subject override, 9 splice call, 0xA pose/anim... | to compare once the spreadsheets are read |

Next: the JSG constructor (allocation size), kinds against the opcode sheets, the 0x6C and 0x74 conflicts. JSG/JSGE stay `sly1-*`, SEQNODE is ours.

## The two spreadsheets (2026-10-26)

1. Instruction sheet (78 opcodes, `config/recovered/slymods_jsg_opcodes.tsv`: names and our verdicts; the sheet itself is in
   work/slymods/, git-ignored). Its header says the names come from two internal builds and that "official names as of release are unknown". The record kind numbers are the same enum as ours
   (every kind we had code for lines up in structure), so the sheet names the kinds our we had guessed at.
   - Agree (19 kinds): 0 THREAD, 1 END_THREAD, 2 DESTROY_THREAD, 4 WAIT, 5 SIGNAL_SEQUENCE, 6 UNTRIGGER_SEQUENCE, 7 SET_PLAYER,
     8 SET_ACTOR, 9 CALL_SPLICE, 0xA CALL_ANIMATION, 0xB CALL_SEQUENCE, 0xD SET_SM_GOAL, 0x4C APPLY_MUSIC, 0x4D RETRACT_MUSIC,
     0x52 WAIT_FOR_VOICE, 0x53 SHOW_BRIEF, 0x54 HIDE_BRIEF, 0x55 PLAY_GUARD_SCRIPT, 0x56 RETRACT_GUARD_SCRIPT.
   - **Our labels wrong**: 0x49 (ours "dialog choice") is SET_DANCE_STATE, 0x4A ("choice option / speaker") DANCE_MOVE (its +0x10
     float is a time), 0x4B ("speaker target") DANCE_INTERLUDE; 0x50/0x51 ("drive the subject's input") are TAKE_OUT_BOMB / DROP_BOMB
     by the sheet (to check: the sheet calls them barely usable). Rename AddSeqRecord49/4a/4b accordingly once the binary agrees.
   - The sheet has `???` for 3 SYNC; our code knows it: wait until no node runs any of the listed blocks.
   - Our code has Add functions for kinds 0x57-0x5A that the sheet lacks (a later build, or unfinished sheet).
   - The record's +4 word, "unknown flag" there, is `fAsync` in ours (0: the node waits for the record to finish; THREAD and
     END_THREAD carry 1), so not "same with every instruction".
2. Script dump sheet (tab gid 2004645276, map 0 Cairo): 51 scripts, 870 instructions, each with its RAM base (the first at
   0x488590) and the 0x50-byte records as hex. Usable as test inputs for our JSG interpreter (record kind, args, expected
   effects); it names the OIDs' targets only as None/Unknown/Sly/Murray/Bentley.
