#include "m2c_macros.h"

void PushScaling__5CFontff(void *arg0, f32 fparg0, f32 fparg1) {
    s32 temp_v1;
    void *temp_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x18);
    temp_v0 = arg0 + ((temp_v1 * 8) + 0x1C);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (temp_v1 + 1);
    M2C_FIELD(temp_v0, f32 *, 0) = (f32) M2C_FIELD(arg0, f32 *, 0x10);
    M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 0x10);
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) (M2C_FIELD(arg0, f32 *, 0x1C) * fparg0);
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) (M2C_FIELD(arg0, f32 *, 0x20) * fparg1);
}
