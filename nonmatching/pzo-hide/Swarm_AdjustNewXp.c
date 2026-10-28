#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK func_0017F1A0();                            /* extern */
M2C_UNK func_0017F5B0(void *, s32);                 /* extern */

void Swarm_AdjustNewXp(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;

    func_0017F1A0();
    if (M2C_FIELD(arg0, s32 *, 0x188) != 0) {
        temp_s0 = M2C_FIELD((arg1 + ((1 - arg2) << 6)), s32 *, 0xC);
        if (FIsBasicDerivedFrom(temp_s0, 0x47) != 0) {
            func_0017F5B0(arg0, temp_s0);
        }
    }
}
