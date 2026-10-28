#include "m2c_macros.h"

s32 GetJtPower(f32);                                /* extern */
M2C_UNK SetJtPower(void *, s32);                    /* extern */
extern f32 g_2dded4;

void DrainJtPower(void *arg0, f32 fparg0) {
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_s0;
    s32 temp_v0;

    temp_f12 = fparg0 * g_2dded4;
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x1308) + temp_f12;
    temp_s0 = g_2dded4;
    M2C_FIELD(arg0, f32 *, 0x1308) = temp_f1;
    if (M2C_BITWISE(s32, temp_s0) != 0) {
        M2C_FIELD(arg0, f32 *, 0x1308) = (f32) (temp_f1 - (f32) temp_s0);
        temp_v0 = GetJtPower(temp_f12) - M2C_BITWISE(s32, temp_s0);
        SetJtPower(arg0, (temp_v0 > -1) ? temp_v0 : 0);
    }
}
