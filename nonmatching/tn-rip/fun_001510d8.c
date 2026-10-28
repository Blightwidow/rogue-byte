#include "m2c_macros.h"

s32 FFloatsNear__Ffff(f32, f32, M2C_UNK);           /* extern */

s32 func_001510D8(void *arg0) {
    f32 temp_f13;
    s32 var_v0;

    temp_f13 = M2C_FIELD(arg0, f32 *, 0x18);
    if ((temp_f13 < 0.0f) || (var_v0 = 0, (FFloatsNear__Ffff(M2C_FIELD(arg0, f32 *, 0xAC), temp_f13, 0x3C23D70A) != 0))) {
        var_v0 = 1;
    }
    return var_v0;
}
