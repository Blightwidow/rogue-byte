#include "m2c_macros.h"

M2C_UNK RecalcCmFrustrum__FP2CM();                  /* extern */

void SetCmFov(void *arg0, f32 fparg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(fabsf(fparg0 - M2C_FIELD(arg0, f32 *, 0x20)) > 0.0001f)) {
        var_v0 = 0;
    }
    M2C_FIELD(arg0, f32 *, 0x24) = fparg0;
    M2C_FIELD(arg0, f32 *, 0x20) = fparg0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    if (var_v0 != 0) {
        RecalcCmFrustrum__FP2CM();
    }
}
