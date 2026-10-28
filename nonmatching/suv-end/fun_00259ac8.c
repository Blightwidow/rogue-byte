#include "m2c_macros.h"

s32 func_00259AC8(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_ERROR(/* Read from unset register $v1 */);
    M2C_FIELD(arg0, s32 *, 0x40) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x40) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x40) = temp_v0;
    return ((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1;
}
