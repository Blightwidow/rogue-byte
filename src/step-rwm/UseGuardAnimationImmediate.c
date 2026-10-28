#include "m2c_macros.h"

M2C_UNK BindAnimref(s32, s32);                      /* extern */
s32 GrfsgsFromRef(s32);                             /* extern */
s32 PguardanimEnsure(s32, s32);                     /* extern */
M2C_UNK UseGuardAnimation(s32, s32, s32, s32);      /* extern */

void UseGuardAnimationImmediate(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s1;

    temp_s1 = PguardanimEnsure(arg0, GrfsgsFromRef(arg1));
    UseGuardAnimation(arg0, arg1, arg2, arg3);
    BindAnimref(temp_s1, arg0);
}
