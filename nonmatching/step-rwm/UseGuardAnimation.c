#include "m2c_macros.h"

s32 GrfsgsFromRef(s32);                             /* extern */
void *PguardanimEnsure(s32, s32);                   /* extern */

void UseGuardAnimation(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = PguardanimEnsure(arg0, GrfsgsFromRef(arg1));
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg3;
    M2C_FIELD(temp_v0, s32 *, 4) = arg2;
}
