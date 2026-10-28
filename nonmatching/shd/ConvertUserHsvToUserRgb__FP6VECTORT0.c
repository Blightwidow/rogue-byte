#include "m2c_macros.h"

M2C_UNK ConvertHsvToRgb__FP6VECTORT0(void *, s128); /* extern */

void ConvertUserHsvToUserRgb__FP6VECTORT0(s128 *arg0, void *arg1) {
    char sp[0x400];
    f32 sp4;
    f32 sp8;

    sp4 *= 0.003921569f;
    sp8 *= 0.003921569f;
    ConvertHsvToRgb__FP6VECTORT0(sp, *arg0);
    M2C_FIELD(arg1, f32 *, 0) = (f32) (M2C_FIELD(arg1, f32 *, 0) * 255.0f);
    M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) * 255.0f);
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) * 255.0f);
}
