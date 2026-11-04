#include "m2c_macros.h"

extern f32 g_2dded0;

void ForceRipFade__FP3RIPf(void *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f3;

    temp_f3 = M2C_FIELD(arg0, f32 *, 0x18);
    temp_f0 = temp_f3 - (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x14));
    if (fparg0 < temp_f0) {
        temp_f0_2 = temp_f0 / temp_f3;
        temp_f2 = fparg0 / temp_f0_2;
        M2C_FIELD(arg0, f32 *, 0x18) = temp_f2;
        M2C_FIELD(arg0, f32 *, 0x14) = (f32) (g_2dded0 - ((1.0f - temp_f0_2) * temp_f2));
    }
}
