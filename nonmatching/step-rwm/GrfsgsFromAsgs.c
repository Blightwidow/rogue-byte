#include "m2c_macros.h"

s32 GrfsgsFromSgs(s32);                             /* extern */

s32 GrfsgsFromAsgs(s32 arg0, s32 *arg1) {
    s32 *var_s1;
    s32 temp_a0;
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    if (arg0 > 0) {
        var_s1 = arg1;
        var_s0 = arg0;
        do {
            temp_a0 = *var_s1;
            var_s0 -= 1;
            var_s1 += 4;
            var_s2 |= GrfsgsFromSgs(temp_a0);
        } while (var_s0 != 0);
    }
    return var_s2;
}
