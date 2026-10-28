#include "m2c_macros.h"

s32 PvAllocStackImpl__Fi(void *, s32, s32);         /* extern */

void AllocStack__4DMASi(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg1 * 0x10;
    temp_v0 = PvAllocStackImpl__Fi(sp, temp_s0, 0x10);
    M2C_FIELD(arg0, s32 *, 4) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0) = (s32) (temp_v0 + temp_s0);
    M2C_FIELD(arg0, s32 *, 0xC) = temp_v0;
}
