#include "m2c_macros.h"

void SelectLootDef(void *arg0, s32 arg1) {
    s32 *var_v1;
    s32 temp_v0;
    s32 var_a2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x150);
    var_a2 = 0;
    if (temp_v0 > 0) {
        var_v1 = M2C_FIELD(arg0, s32 **, 0x154);
loop_2:
        var_a2 += 1;
        if (arg1 == *var_v1) {
            M2C_FIELD(arg0, s32 **, 0x158) = var_v1;
            return;
        }
        var_v1 += 0x2C;
        if (var_a2 >= temp_v0) {
            /* Duplicate return node #5. Try simplifying control flow for better match */
            M2C_FIELD(arg0, s32 **, 0x158) = (s32 *) M2C_FIELD(arg0, s32 **, 0x154);
            return;
        }
        goto loop_2;
    }
    M2C_FIELD(arg0, s32 **, 0x158) = (s32 *) M2C_FIELD(arg0, s32 **, 0x154);
}
