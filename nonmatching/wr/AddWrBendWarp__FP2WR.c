#include "m2c_macros.h"

extern s128 g_2a2db0;
extern s128 g_2a2dc0;

void AddWrBendWarp__FP2WR(void *arg0) {
    s32 temp_v0;
    void *temp_a1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x54);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) (temp_v0 + 1);
    M2C_FIELD(arg0, s32 *, 0x6E0) = (s32) (M2C_FIELD(arg0, s32 *, 0x6E0) + 1);
    temp_a1 = arg0 + ((temp_v0 * 0xD0) + 0x60);
    M2C_FIELD(temp_a1, s32 *, 0) = 1;
    M2C_FIELD(temp_a1, s128 *, 0x10) = (s128) g_2a2db0;
    M2C_FIELD(temp_a1, f32 *, 0x88) = 0.5f;
    M2C_FIELD(temp_a1, s128 *, 0x20) = (s128) g_2a2dc0;
    M2C_FIELD(temp_a1, f32 *, 0x38) = 0.5f;
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + 1);
}
