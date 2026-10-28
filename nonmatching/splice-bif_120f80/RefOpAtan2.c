#include "m2c_macros.h"

f32 atan2f(s32, M2C_UNK, void *, f32, f32);         /* extern */

void *RefOpAtan2(void *arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp4;
    s32 *var_v1;
    s32 var_a0;
    s32 var_f0;
    void *var_a2;

    var_a2 = arg2;
    var_v1 = sp;
    var_a0 = 1;
    do {
        if (M2C_FIELD(var_a2, s32 *, 0) == 0x16) {
            var_f0 = M2C_FIELD(var_a2, s32 *, 4);
        } else {
            var_f0 = M2C_BITWISE(s32, (f32) M2C_FIELD(var_a2, s32 *, 4));
        }
        *var_v1 = var_f0;
        var_v1 += 4;
        var_a0 -= 1;
        var_a2 += 8;
    } while (var_a0 >= 0);
    M2C_FIELD(arg0, f32 *, 4) = atan2f(var_a0, 0x16, var_a2, sp0, sp4);
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    return arg0;
}
