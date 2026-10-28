#include "m2c_macros.h"

void SetBlotLabelList(void *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 *var_a2;
    s32 *var_a3;
    s32 var_a0;
    s32 var_v1;
    void *temp_v0;

    var_a2 = arg2;
    var_a3 = arg3;
    var_a0 = 0;
    if (arg1 > 0) {
        var_a3 = arg0 + 0xCC;
        var_v1 = *var_a2;
loop_2:
        var_a0 += 1;
        var_a2 += 4;
        *var_a3 = var_v1;
        var_a3 += 4;
        if (var_a0 < arg1) {
            if ((u32) var_a0 < 0xAU) {
                var_v1 = *var_a2;
                goto loop_2;
            }
        }
    }
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, s32 *, s32 *), 0x18C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x188), -1, var_a2, var_a3);
}
