#include "m2c_macros.h"

M2C_UNK SeekBlotLabel(s32, M2C_UNK, f32);           /* extern */

void UpdateVehicleHpBlot(void *arg0) {
    f32 var_f12;
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x568);
    if (temp_v1 != 0) {
        var_f12 = (f32) M2C_FIELD(arg0, s32 *, 0x560) / (f32) M2C_FIELD(arg0, s32 *, 0x55C);
        if (M2C_FIELD(arg0, s32 *, 0x564) != 0) {
            var_f12 = 1.0f - var_f12;
        }
        SeekBlotLabel(temp_v1, 0x34F, var_f12);
    }
}
