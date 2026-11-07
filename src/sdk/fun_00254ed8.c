// SPDX-License-Identifier: GPL-3.0-or-later
// Behaviour: registers the global object D_002C8934 with the slot-heap pool at 0x452080 (RegisterGlobalObject), as a tail call.
// Exact only as C with Sony's ee-gcc 2.9 (sibling call `j`, `addiu` for the %lo of B_00452080):
//   cp this file to a .c; TRY_ASSEMBLER=sony29 python3 scripts/matching/try.py 254ED8 <file>.c  -> score 0
// SN 2.95.3 (the default for this address) emits jal + frame: score 6.
#ifdef __cplusplus
extern "C" {
#endif
extern char D_002C8934[];
extern char B_00452080[];
void RegisterGlobalObject(void *, void *);
void func_00254ED8(void)
{
    RegisterGlobalObject(D_002C8934, B_00452080);
}
#ifdef __cplusplus
}
#endif
