#include "m2c_macros.h"

M2C_UNK memmove(s32 *, void *, s32, s32);           /* extern */

void func_001E0070(void *arg0, s32 arg1) {
    s32 *var_a0;
    s32 var_a2;
    void *var_a1;

    var_a2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x84) > 0) {
        var_a1 = arg0 + 0x8C;
        var_a0 = arg0 + 0x88;
loop_2:
        if (*var_a0 != arg1) {
            var_a2 += 1;
            var_a1 += 4;
            var_a0 += 4;
            if (var_a2 >= M2C_FIELD(arg0, s32 *, 0x84)) {

            } else {
                goto loop_2;
            }
        } else {
            memmove(var_a0, var_a1, ((M2C_FIELD(arg0, s32 *, 0x84) - var_a2) * 4) - 4, arg1);
            M2C_FIELD(arg0, s32 *, 0x84) = (s32) (M2C_FIELD(arg0, s32 *, 0x84) - 1);
        }
    }
}
