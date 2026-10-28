#include "m2c_macros.h"

extern s32 D_002BE8AC;

void Swarm_AddGroup(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    u32 temp_a0;
    void *temp_v0;

    temp_a0 = M2C_FIELD(arg0, u32 *, 0x1C8);
    if (temp_a0 < 4U) {
        M2C_FIELD(arg0, u32 *, 0x1C8) = (u32) (temp_a0 + 1);
        temp_v0 = arg0 + ((temp_a0 * 0x30) + 0x1CC);
        M2C_FIELD(temp_v0, s32 *, 0x1C) = (s32) D_002BE8AC;
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, s32 *, 4) = arg2;
        M2C_FIELD(temp_v0, s32 *, 8) = arg3;
        M2C_FIELD(temp_v0, f32 *, 0x20) = fparg0;
        M2C_FIELD(temp_v0, f32 *, 0x2C) = -1.0f;
    }
}
