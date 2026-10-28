#include "m2c_macros.h"

M2C_UNK RemoveGuardIgnoredClass(s32, s32);          /* extern */
extern s32 D_002C3D10;

void func_00206E50(s32 arg0) {
    s32 *var_s1;
    s32 temp_a1;
    u32 var_s0;

    var_s0 = 0;
    var_s1 = &D_002C3D10;
    do {
        temp_a1 = *var_s1;
        var_s0 += 1;
        var_s1 += 4;
        RemoveGuardIgnoredClass(arg0, temp_a1);
    } while (var_s0 < 5U);
}
