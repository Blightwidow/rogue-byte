#include "m2c_macros.h"

extern s128 g_2a2da0;

void AddWrCircleWarp__FP2WR(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    void *temp_a0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x54);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) (temp_v0 + 1);
    M2C_FIELD(arg0, s32 *, 0x6E0) = (s32) (M2C_FIELD(arg0, s32 *, 0x6E0) + 1);
    temp_a0 = arg0 + ((temp_v0 * 0xD0) + 0x60);
    M2C_FIELD(temp_a0, s32 *, 0) = 0;
    M2C_FIELD(temp_a0, s128 *, 0x10) = (s128) g_2a2da0;
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x5C);
    if (temp_v0_2 < 0) {
        temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x58);
        M2C_FIELD(temp_a0, s32 *, 4) = temp_v0_3;
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_v0_3 + 1);
        M2C_FIELD(arg0, s32 *, 0x5C) = (s32) M2C_FIELD(temp_a0, s32 *, 4);
        M2C_FIELD(temp_a0, s32 *, 0x60) = 0;
        return;
    }
    M2C_FIELD(temp_a0, s32 *, 4) = temp_v0_2;
    M2C_FIELD(arg0, s32 *, 0x5C) = -1;
    M2C_FIELD(temp_a0, s32 *, 0x60) = 2;
}
