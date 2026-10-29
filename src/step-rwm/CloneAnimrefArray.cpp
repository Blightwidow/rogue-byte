#include "m2c_macros.h"
extern "C" {

M2C_UNK CloneAnimref(s32);                          /* extern */

void CloneAnimrefArray(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = arg1;
    var_s1 = 0x19;
    do {
        var_s1 -= 1;
        CloneAnimref(var_s0);
        var_s0 += 0x10;
    } while (var_s1 >= 0);
}
}
