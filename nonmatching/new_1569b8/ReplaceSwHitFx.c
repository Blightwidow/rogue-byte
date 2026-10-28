#include "m2c_macros.h"

M2C_UNK ReplaceHitFx(s32, M2C_UNK, s32, M2C_UNK);   /* extern */

void ReplaceSwHitFx(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_a0;

    switch (arg1) {                                 /* irregular */
    case 1:
        var_a0 = M2C_FIELD(arg0, s32 *, 0x4024);
        break;
    default:
        var_a0 = 0;
        break;
    case 0:
        var_a0 = M2C_FIELD(arg0, s32 *, 0x4020);
        break;
    }
    ReplaceHitFx(var_a0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $a2 */), arg3, M2C_ERROR(/* Read from unset register $t0 */));
}
