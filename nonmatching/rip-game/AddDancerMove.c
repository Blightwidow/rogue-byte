#include "m2c_macros.h"

void AddDancerMove(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 temp_t2;
    void *temp_v0;

    temp_t2 = M2C_FIELD(arg0, u32 *, 0x2C4);
    if (temp_t2 < 8U) {
        M2C_FIELD(arg0, u32 *, 0x2C4) = (u32) (temp_t2 + 1);
        temp_v0 = arg0 + ((temp_t2 * 0x28) + 0x2C8);
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, s32 *, 4) = arg2;
        M2C_FIELD(temp_v0, s32 *, 0xC) = arg3;
        M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
        M2C_FIELD(temp_v0, s32 *, 0x1C) = (s32) M2C_ERROR(/* Read from unset register $t1 */);
        M2C_FIELD(temp_v0, s32 *, 0x24) = 0;
        M2C_FIELD(temp_v0, s32 *, 0x18) = 0;
    }
}
