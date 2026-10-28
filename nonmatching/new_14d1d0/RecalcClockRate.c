#include "m2c_macros.h"

void RecalcClockRate(void *arg0) {
    f32 *var_v1;
    f32 temp_f0;
    u32 var_a1;

    var_a1 = 0;
    var_v1 = arg0 + 0x18;
    M2C_FIELD(arg0, f32 *, 8) = 1.0f;
    do {
        temp_f0 = *var_v1;
        var_a1 += 1;
        var_v1 += 4;
        M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) * temp_f0);
    } while (var_a1 < 9U);
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0x38);
}
