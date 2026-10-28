#include "m2c_macros.h"

s32 FAsegaGone(s32);                                /* extern */
s32 GetSmaCur(s32);                                 /* extern */
s32 GetSmaGoal(s32);                                /* extern */

s32 func_0017F550(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x194);
    if (temp_a0 == 0) {
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x198);
        var_v0 = 1;
        if (temp_a0_2 != 0) {
            temp_s0 = GetSmaCur(temp_a0_2);
            var_v0 = temp_s0 == GetSmaGoal(M2C_FIELD(arg0, s32 *, 0x198));
        }
        return var_v0;
    }
    return FAsegaGone(temp_a0);
}
