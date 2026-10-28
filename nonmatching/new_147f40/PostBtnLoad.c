#include "m2c_macros.h"

M2C_UNK PostAshLoad(s32, s32);                      /* extern */

void PostBtnLoad(s32 *arg0) {
    s32 temp_a0;
    s32 var_s0;
    u32 var_s2;

    var_s0 = arg0 + 4;
    var_s2 = 0;
loop_1:
    temp_a0 = var_s0;
    var_s2 += 1;
    var_s0 += 0x44;
    PostAshLoad(temp_a0, *arg0);
    if (var_s2 < 2U) {
        goto loop_1;
    }
}
