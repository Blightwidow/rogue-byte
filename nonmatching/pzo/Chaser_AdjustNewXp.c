#include "m2c_macros.h"

M2C_UNK func_0017F1A0();                            /* extern */
M2C_UNK func_0017F5B0(void *, s32);                 /* extern */
extern s32 g_2dfb80;

void Chaser_AdjustNewXp(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;

    func_0017F1A0();
    if (M2C_FIELD(arg0, s32 *, 0x188) != 0) {
        temp_a1 = M2C_FIELD((arg1 + ((1 - arg2) << 6)), s32 *, 8);
        if (temp_a1 == g_2dfb80) {
            func_0017F5B0(arg0, temp_a1);
        }
    }
}
