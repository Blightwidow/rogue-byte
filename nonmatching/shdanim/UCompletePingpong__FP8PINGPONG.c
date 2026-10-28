#include "m2c_macros.h"

f32 UCompletePingpong__FP8PINGPONG(void *arg0) {
    f32 var_f0;
    f32 var_f3;

    var_f3 = M2C_FIELD(arg0, f32 *, 0x60);
    if (!(var_f3 < 0.0f)) {
        var_f0 = M2C_FIELD(arg0, f32 *, 0x64);
    } else {
        var_f3 = -var_f3;
        var_f0 = (f32) (M2C_FIELD(arg0, s32 *, 0x1C) * 2) - M2C_FIELD(arg0, f32 *, 0x64);
    }
    return (var_f0 / var_f3) / (((f32) (M2C_FIELD(arg0, s32 *, 0x1C) * 2) / var_f3) + M2C_FIELD(arg0, f32 *, 0x68));
}
