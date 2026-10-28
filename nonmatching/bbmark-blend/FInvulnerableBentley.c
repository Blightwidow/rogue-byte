#include "m2c_macros.h"

s32 FInvulnerableJt(void *, s32);                   /* extern */
s32 func_00194640(void *, s32);                     /* extern */

s32 FInvulnerableBentley(void *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x13D0);
    if (temp_v1 != 3) {
        if ((temp_v1 == 0xD) && (arg1 == 0x4000)) {
            return 1;
        }
        goto block_6;
    }
    var_v0 = 1;
    if (func_00194640(arg0 + 0x4C0, arg1) == 0) {
block_6:
        var_v0 = FInvulnerableJt(arg0, arg1);
    }
    return var_v0;
}
