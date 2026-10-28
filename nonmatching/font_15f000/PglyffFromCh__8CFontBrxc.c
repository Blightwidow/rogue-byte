#include "m2c_macros.h"

extern M2C_UNK D_002BE338;

u16 *PglyffFromCh__8CFontBrxc(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0;
    u16 *temp_v1;

    var_a3 = 0;
    var_a2 = M2C_FIELD(arg0, s32 *, 0x138) - 1;
    if (var_a2 >= 0) {
        var_v0 = var_a2;
loop_2:
        temp_a1 = var_v0 / 2;
        temp_v1 = (temp_a1 * 8) + M2C_FIELD(arg0, s32 *, 0x13C);
        temp_v0 = *(((arg1 & 0xFF) * 2) + &D_002BE338) - *temp_v1;
        if (temp_v0 == 0) {
            return temp_v1;
        }
        if (temp_v0 <= 0) {
            var_a2 = temp_a1 - 1;
        } else {
            var_a3 = temp_a1 + 1;
        }
        var_v0 = var_a2 + var_a3;
        if (var_a2 < var_a3) {
            /* Duplicate return node #9. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_2;
    }
    return NULL;
}
