#include "m2c_macros.h"

s32 func_001792E8(void *arg0) {
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x4C);
    var_a1 = 0;
    if ((temp_v1 < 2) && (temp_v1 >= 0)) {
        var_a1 = 1;
        if (!(M2C_FIELD(arg0, f32 *, 0xE0) < 0.0f)) {
            var_a1 = 0;
        }
    }
    return var_a1;
}
