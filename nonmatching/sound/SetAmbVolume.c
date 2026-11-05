#include "m2c_macros.h"

f32 GLimitLm__FP2LMf(M2C_UNK *);                    /* extern */
f32 SetAmbGrf(void *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK g_2bbb60;

f32 SetAmbVolume(void *arg0) {
    f32 temp_f3;
    f32 var_f0;

    temp_f3 = GLimitLm__FP2LMf(&g_2bbb60);
    var_f0 = M2C_FIELD(arg0, f32 *, 0x10) * 1024.0f;
    if (0x44800000 != 0x44800000) {
        M2C_FIELD(arg0, f32 *, 0x10) = temp_f3;
        var_f0 = SetAmbGrf(arg0, 0x10, 0x10);
    }
    return var_f0;
}
