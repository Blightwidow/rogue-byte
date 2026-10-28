#include "m2c_macros.h"

void RemoveLightFromSw(void *arg0, void *arg1) {
    s32 *temp_a3;
    s32 temp_a2;
    s32 temp_v0;

    temp_a2 = M2C_FIELD(arg1, s32 *, 0x118);
    temp_v0 = (s32) ((temp_a2 > -1) ? temp_a2 : (temp_a2 + 0x1F)) >> 5;
    temp_a3 = arg0 + 0x4590 + (temp_v0 * 4);
    *temp_a3 |= 1 << (temp_a2 - (temp_v0 << 5));
    M2C_FIELD((arg0 + (M2C_FIELD(arg1, s32 *, 0x118) * 4)), s32 *, 0x4154) = 0;
    M2C_FIELD(arg1, s32 *, 0x118) = -1;
    M2C_FIELD(arg0, s32 *, 0x4554) = 1;
}
