#include "m2c_macros.h"

M2C_UNK GetScriptPose(s32, M2C_UNK, s32, s32);      /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */

void func_00171AF8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10));
    GetScriptPose(M2C_FIELD(arg0, s32 *, 0x30), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), arg1, arg2);
}
