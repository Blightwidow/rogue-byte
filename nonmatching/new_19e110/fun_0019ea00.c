#include "m2c_macros.h"

M2C_UNK GetPathPosFromS(s32, M2C_UNK, void *, f32); /* extern */

void func_0019EA00(void *arg0, void *arg1) {
    char sp[0x400];
    GetPathPosFromS(M2C_FIELD(arg0, s32 *, 0xC), 0, sp, M2C_FIELD(arg0, f32 *, 0x10));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
    M2C_FIELD(arg1, s32 *, 0x34) = 0;
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
}
