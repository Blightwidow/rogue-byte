#include "m2c_macros.h"
extern "C" {

s32 CSolveQuadratic__FfffPf(void *, f32, f32, f32); /* extern */

f32 GSmooth__FfffP3SMPPf(void *arg0, f32 *arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    char sp[0x10];
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f14;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f14;
    f32 var_f20;
    f32 var_f2;
    s32 var_s2;

    var_s2 = 0;
    temp_f3 = M2C_FIELD(arg0, f32 *, 0);
    var_f20 = fparg2;
    if (temp_f3 == 0.0f) {
        if (arg1 != NULL) {
            *arg1 = 0.0f;
            return fparg0;
        }
        return fparg0;
    }
    var_f14 = fparg0 - fparg1;
    if (var_f14 < 0.0f) {
        var_f14 = -var_f14;
        var_s2 = 1;
    }
    temp_f1 = M2C_FIELD(arg0, f32 *, 8);
    temp_f1_2 = (M2C_FIELD(arg0, f32 *, 4) + temp_f3) * temp_f1 * 0.5f;
    if (temp_f1_2 <= var_f14) {
        temp_f0 = (var_f14 - temp_f1_2) / temp_f3;
        if (!(var_f20 <= temp_f0)) {
            var_f20 -= temp_f0;
            var_f14 = temp_f1_2;
            goto block_13;
        }
        var_f2 = -temp_f3;
        var_f12_2 = var_f14 - (temp_f3 * var_f20);
    } else {
block_13:
        temp_f0_2 = M2C_FIELD(arg0, f32 *, 4);
        temp_f14 = *(sp + ((CSolveQuadratic__FfffPf(sp, (M2C_FIELD(arg0, f32 *, 0) - temp_f0_2) / (2.0f * temp_f1), temp_f0_2, -var_f14) - 1) * 4)) - var_f20;
        var_f12_2 = 0.0f;
        if (!(temp_f14 > 0.0f)) {
            var_f2 = -M2C_FIELD(arg0, f32 *, 4);
        } else {
            temp_f2 = M2C_FIELD(arg0, f32 *, 4);
            temp_f1_3 = M2C_FIELD(arg0, f32 *, 8);
            temp_f0_3 = (M2C_FIELD(arg0, f32 *, 0) - temp_f2) * temp_f14;
            var_f2 = -(temp_f2 + (temp_f0_3 / temp_f1_3));
            var_f12_2 = ((temp_f0_3 * temp_f14) / (2.0f * temp_f1_3)) + (temp_f2 * temp_f14);
        }
    }
    if (var_s2 != 0) {
        var_f12 = fparg1 - var_f12_2;
        if (arg1 != NULL) {
            *arg1 = -var_f2;
        }
    } else {
        var_f12 = var_f12_2 + fparg1;
        if (arg1 != NULL) {
            *arg1 = var_f2;
        }
    }
    return var_f12;
}
}
