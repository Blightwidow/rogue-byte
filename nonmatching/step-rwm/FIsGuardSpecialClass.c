#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, s32);                  /* extern */
extern s32 D_002C3D10;

s32 FIsGuardSpecialClass(s32 arg0) {
    s32 *var_s1;
    s32 var_v0;
    u32 var_s0;

    var_s0 = 0;
    var_s1 = &D_002C3D10;
loop_1:
    var_v0 = 1;
    if (FIsBasicDerivedFrom(arg0, *var_s1) == 0) {
        var_s0 += 1;
        var_s1 += 4;
        if (var_s0 >= 5U) {
            var_v0 = 0;
        } else {
            goto loop_1;
        }
    }
    return var_v0;
}
