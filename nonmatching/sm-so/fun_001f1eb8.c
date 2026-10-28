#include "m2c_macros.h"

M2C_UNK func_00200F58(s32, s32, M2C_UNK, s32 *);    /* extern */

s32 func_001F1EB8(s32 arg0, void *arg1) {
    char sp[0x400];
    s32 *var_a0;
    s32 *var_a1;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_v1;

    var_a2 = 0;
    temp_a3 = M2C_FIELD(arg1, s32 *, 0x484);
    temp_v1 = M2C_FIELD(arg1, s32 *, 0x488);
    if (temp_v1 < temp_a3) {
        var_a0 = sp;
        var_v1 = temp_a3 - temp_v1;
        var_a1 = (temp_v1 * 0x10) + 0x404 + arg1;
        do {
            temp_v0 = *var_a1;
            var_a2 += 1;
            var_a1 += 0x10;
            var_v1 -= 1;
            *var_a0 = temp_v0;
            var_a0 += 4;
        } while (var_v1 != 0);
    }
    func_00200F58(arg0, var_a2, 6, sp);
    return arg0;
}
