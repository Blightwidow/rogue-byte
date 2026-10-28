#include "m2c_macros.h"

f32 __floatdisf(s64);                               /* extern */

f32 MarkClockTickRealOnly__FP5CLOCK(void *arg0) {
    f32 var_f1;
    s32 temp_v0;
    s64 temp_a0;
    void *var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x204);
    if (temp_v0 > 0) {
        var_v0 = M2C_FIELD(((temp_v0 * 4) + arg0), void **, 0x204);
    } else {
        var_v0 = NULL;
    }
    if (var_v0 != NULL) {
        temp_a0 = M2C_FIELD(var_v0, s64 *, 0x68);
        if (temp_a0 >= 0) {
            var_f1 = __floatdisf(temp_a0);
        } else {
            var_f1 = 2.0f * __floatdisf((temp_a0 & 1) | ((u64) temp_a0 >> 1));
        }
        return var_f1 * 3.390842e-9f;
    }
    return 0.0f;
}
