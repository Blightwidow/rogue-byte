#include "m2c_macros.h"

s32 FIsSlEmpty(s32);                                /* extern */

void SetSaiIframe(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 var_a1;
    u16 temp_a1_2;

    if (FIsSlEmpty(arg0 + 0x34) == 0) {
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
        if (arg1 < 0) {
            var_a1 = 0;
        } else {
            var_a1 = (temp_a1 >= arg1) ? arg1 : temp_a1;
        }
        temp_a1_2 = var_a1 & 0xFFFF;
        if (M2C_FIELD(arg0, u16 *, 0x28) != temp_a1_2) {
            M2C_FIELD(arg0, u16 *, 0x28) = temp_a1_2;
            M2C_FIELD(arg0, s32 *, 0x2C) = 1;
        }
    }
}
