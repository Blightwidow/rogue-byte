#include "m2c_macros.h"

M2C_UNK SetSmaGoalIfReachable(s32, s32, s32);       /* extern */
extern M2C_UNK D_002C2248;
extern f32 g_2dded0;

void SetAmmopickupState(void *arg0, s32 arg1) {
    s32 temp_a2;

    if (arg1 != M2C_FIELD(arg0, s32 *, 0x150)) {
        M2C_FIELD(arg0, s32 *, 0x150) = arg1;
        temp_a2 = M2C_FIELD(arg0, s32 *, 0x164);
        M2C_FIELD(arg0, f32 *, 0x154) = (f32) g_2dded0;
        if ((temp_a2 != 0) && (arg1 != -1)) {
            SetSmaGoalIfReachable(temp_a2, *((arg1 * 4) + &D_002C2248), temp_a2);
        }
    }
}
