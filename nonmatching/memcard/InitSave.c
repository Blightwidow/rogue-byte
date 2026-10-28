#include "m2c_macros.h"

M2C_UNK InitMemcard__FP7MEMCARD(s32);               /* extern */
M2C_UNK sceMcInit();                                /* extern */

void InitSave(void *arg0, s32 arg1, s32 arg2) {
    sceMcInit();
    InitMemcard__FP7MEMCARD(arg0 + 0xFD5C);
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = -1;
    M2C_FIELD(arg0, f32 *, 0x10) = 0.0f;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, f32 *, 0x14) = 0.0f;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}
