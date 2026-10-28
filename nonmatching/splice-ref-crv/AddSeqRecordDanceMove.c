#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK, M2C_UNK);              /* extern */

void func_001E1740(s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x4A, 0);
    M2C_FIELD(temp_v0, s32 *, 0x1C) = arg3;
    M2C_FIELD(temp_v0, f32 *, 0x10) = fparg0;
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg2;
}
