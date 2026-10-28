#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK, M2C_UNK);              /* extern */

void func_001E0CB8(s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x27, 0);
    M2C_FIELD(temp_v0, s32 *, 0x24) = (s32) M2C_ERROR(/* Read from unset register $t1 */);
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg3;
    M2C_FIELD(temp_v0, f32 *, 0x1C) = fparg0;
    M2C_FIELD(temp_v0, s32 *, 0x20) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
}
