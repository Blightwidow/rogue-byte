#include "m2c_macros.h"

M2C_UNK CopyAb__FPvT0Ui(s32, void *, s32);          /* extern */
extern s32 B_003E123C;

void CloneAct(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg1, s32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(arg1, s32 *, 0x14);
    M2C_FIELD(arg0, s32 *, 8) = arg3;
    CopyAb__FPvT0Ui(arg0 + 0x1C, arg1 + 0x1C, B_003E123C - 0x1C);
}
