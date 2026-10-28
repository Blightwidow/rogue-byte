#include "m2c_macros.h"

s32 GrfsgsFromSgs(s32);                             /* extern */

s32 AsgsFromGrfsgs(s32 arg0, s32 *arg1) {
    s32 *var_s1;
    s32 var_s0;
    s32 var_s2;

    var_s0 = 0x2E;
    var_s1 = arg1;
    var_s2 = 0;
    do {
        if (arg0 & GrfsgsFromSgs(var_s0)) {
            *var_s1 = var_s0;
            var_s2 += 1;
            var_s1 += 4;
        }
        var_s0 -= 1;
    } while (var_s0 >= 0);
    return var_s2;
}
