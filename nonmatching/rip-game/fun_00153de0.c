#include "m2c_macros.h"

s32 NNextSensorState(void *, s32, s32);             /* extern */
M2C_UNK SetSensorEntryState(void *, s32 *, s32);    /* extern */

void func_00153DE0(void *arg0) {
    s32 *temp_a1;
    s32 *var_s0;
    s32 temp_a2;
    s32 var_a1;
    s32 var_s2;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xFC) > 0) {
        var_s0 = arg0 + 0x100;
        var_a1 = M2C_FIELD(arg0, s32 *, 0x100);
loop_2:
        var_s2 += 1;
        temp_a2 = NNextSensorState(arg0, var_a1, M2C_FIELD(var_s0, s32 *, 4));
        temp_a1 = var_s0;
        var_s0 += 0x10;
        SetSensorEntryState(arg0, temp_a1, temp_a2);
        if (var_s2 < M2C_FIELD(arg0, s32 *, 0xFC)) {
            var_a1 = *var_s0;
            goto loop_2;
        }
    }
}
