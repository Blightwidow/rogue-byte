#include "m2c_macros.h"

M2C_UNK SetJoyJoys__FP3JOY4JOYS4JOYK(M2C_UNK, M2C_UNK); /* extern */
M2C_UNK scePadPortOpen(s32, s32, void *);           /* extern */

void InitJoy(void *arg0, s32 arg1, s32 arg2) {
    SetJoyJoys__FP3JOY4JOYS4JOYK(1, 0);
    M2C_FIELD(arg0, s32 *, 0x1000) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1004) = arg2;
    scePadPortOpen(arg1, arg2, arg0);
    M2C_FIELD(arg0, s32 *, 0x10E8) = 1;
    M2C_FIELD(arg0, f32 *, 0x10EC) = 1.0f;
}
