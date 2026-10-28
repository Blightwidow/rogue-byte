#include "m2c_macros.h"

extern s32 D_002C3258;

s32 GrfbtnJtGadget(s32 arg0, s32 arg1) {
    s32 *var_a0;
    s32 *var_a2;
    s32 var_a3;
    s32 var_v1;

    var_a0 = arg0 + 0x1180;
    var_a2 = &D_002C3258;
    var_a3 = 0;
    var_v1 = 2;
    do {
        if (arg1 == *var_a0) {
            var_a3 |= *var_a2;
        }
        var_a2 += 4;
        var_v1 -= 1;
        var_a0 += 0xC;
    } while (var_v1 >= 0);
    return var_a3;
}
