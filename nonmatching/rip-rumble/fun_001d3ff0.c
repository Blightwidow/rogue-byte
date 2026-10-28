#include "m2c_macros.h"

M2C_UNK SetAmmopickupState(void *, M2C_UNK, void *, s32); /* extern */

s32 func_001D3FF0(s32 arg0, void *arg1) {
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    void *temp_a2;

    if (M2C_FIELD(arg1, s32 *, 0x150) != 2) {
        temp_a2 = arg0 + ((M2C_FIELD(arg1, s32 *, 0x158) * 0xC) + 0x574);
        temp_v1 = M2C_FIELD(temp_a2, s32 *, 4);
        temp_v0 = M2C_FIELD(temp_a2, s32 *, 0) + M2C_FIELD(arg1, s32 *, 0x15C);
        temp_a3 = temp_v1 < temp_v0;
        M2C_FIELD(temp_a2, s32 *, 0) = (s32) ((temp_a3 == 0) ? temp_v0 : temp_v1);
        SetAmmopickupState(arg1, 2, temp_a2, temp_a3);
    }
}
