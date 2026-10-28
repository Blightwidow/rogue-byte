#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */

void func_001C20E8(void *arg0, s32 arg1) {
    u32 temp_v1;
    void *temp_s1;

    temp_v1 = M2C_FIELD(arg0, u32 *, 0x50);
    if (temp_v1 < 6U) {
        M2C_FIELD(arg0, u32 *, 0x50) = (u32) (temp_v1 + 1);
        temp_s1 = arg0 + ((temp_v1 << 5) + 0x60);
        if (FIsBasicDerivedFrom(arg1, 0xA) == 0) {
            M2C_FIELD(temp_s1, s32 *, 4) = arg1;
            return;
        }
        M2C_FIELD(temp_s1, s32 *, 0) = arg1;
    }
}
