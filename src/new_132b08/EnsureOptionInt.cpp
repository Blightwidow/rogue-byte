// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef short s16; typedef int s32;
typedef unsigned char u8; typedef unsigned int u32;

struct EnsureOptionIntArgs_132C20 {
    s32 mode;
    s32 value;
    char pad[8];
};

extern "C" {
void CRef_Destruct(void *ref);
void RefEnsureOption__FP5BASICiP4CRef(void *ref, void *basic, s32 a2, EnsureOptionIntArgs_132C20 *args);

void EnsureOptionInt(void *arg0, s32 arg1, s32 arg2) {
    EnsureOptionIntArgs_132C20 args;
    char ref[0x10];

    args.mode = 0x15;
    args.value = arg2;
    RefEnsureOption__FP5BASICiP4CRef(ref, arg0, arg1, &args);
    CRef_Destruct(ref);
    CRef_Destruct(&args);
}
}
