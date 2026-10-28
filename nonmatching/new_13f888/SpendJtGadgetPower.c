#include "m2c_macros.h"

s32 GetJtPower();                                   /* extern */
M2C_UNK SetJtPower(void *, s32);                    /* extern */
extern M2C_UNK D_002BCD00;
extern f32 g_2dded0;

void SpendJtGadgetPower(void *arg0, s32 arg1) {
    if (arg1 != -1) {
        SetJtPower(arg0, GetJtPower() - M2C_FIELD((&D_002BCD00 + (arg1 << 5)), s32 *, 0xC));
    }
    M2C_FIELD(arg0, f32 *, 0x1304) = (f32) g_2dded0;
}
