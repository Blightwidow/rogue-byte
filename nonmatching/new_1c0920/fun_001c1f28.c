#include "m2c_macros.h"

M2C_UNK GetPathPosFromS(s32, void *, M2C_UNK, f32); /* extern */
s128 PosLoWorld(s32);                               /* extern */
f32 SMaxCrv(s32);                                   /* extern */

s128 func_001C1F28(void *arg0) {
    char sp[0x400];
    s128 sp0;
    s128 var_v0;
    s32 temp_a0;
    s32 temp_a0_2;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_a0 == 0) {
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 4);
        if (temp_a0_2 == 0) {
            var_v0 = M2C_FIELD(arg0, s128 *, 0x10);
        } else {
            var_v0 = PosLoWorld(temp_a0_2);
        }
        sp0 = var_v0;
    } else {
        GetPathPosFromS(M2C_FIELD(arg0, s32 *, 0), sp, 0, SMaxCrv(temp_a0) * 0.5f);
    }
    return sp0;
}
