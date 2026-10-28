#include "m2c_macros.h"

s32 CploFindSwObjectsByClass(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetGuardMode(s32, s32);                     /* extern */

void SetSwGuardsMode(s32 arg0, s32 arg1) {
    char sp[0x400];
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_s1;

    temp_v0 = CploFindSwObjectsByClass(0x105, 0x38, 0);
    var_s1 = temp_v0;
    if (temp_v0 > 0) {
        var_s0 = sp;
        do {
            temp_a0 = *var_s0;
            var_s0 += 4;
            var_s1 -= 1;
            SetGuardMode(temp_a0, arg1);
        } while (var_s1 != 0);
    }
}
