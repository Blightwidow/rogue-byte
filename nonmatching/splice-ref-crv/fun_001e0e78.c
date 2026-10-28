#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK);                       /* extern */

void func_001E0E78(s32 arg1, s32 arg3, f32 fparg0, f32 fparg1) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x2B);
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    M2C_FIELD(temp_v0, f32 *, 0x14) = fparg0;
    M2C_FIELD(temp_v0, f32 *, 0x18) = fparg1;
    M2C_FIELD(temp_v0, s32 *, 0x1C) = arg3;
}
