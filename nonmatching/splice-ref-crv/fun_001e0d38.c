#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK, M2C_UNK);              /* extern */

void func_001E0D38(s32 arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x28, 0);
    M2C_FIELD(temp_v0, s32 *, 0x24) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    M2C_FIELD(temp_v0, f32 *, 0x14) = fparg0;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg2;
    M2C_FIELD(temp_v0, f32 *, 0x1C) = fparg1;
    M2C_FIELD(temp_v0, s32 *, 0x20) = arg3;
}
