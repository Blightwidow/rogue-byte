#include "m2c_macros.h"

f32 GRandInRange(f32, f32);                         /* extern */
extern f32 D_FLT_002BE5A0;
extern f32 g_2dded0;

void func_00172560(void *arg0) {
    f32 temp_f20;
    f32 var_f0;
    void *temp_v0;

    temp_f20 = g_2dded0;
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) (temp_f20 + GRandInRange(M2C_FIELD(temp_v0, f32 *, 0xE6C), M2C_FIELD(temp_v0, f32 *, 0xE70)));
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xE78) == 1) {
        var_f0 = g_2dded0 + D_FLT_002BE5A0;
    } else {
        var_f0 = 3.4028235e38f;
    }
    M2C_FIELD(arg0, f32 *, 0x3C) = var_f0;
}
