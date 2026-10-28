#include "m2c_macros.h"

M2C_UNK GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(M2C_UNK, void *); /* extern */
M2C_UNK GetPathPosFromS(s32, M2C_UNK *, M2C_UNK, f32); /* extern */
extern s32 g_2c0d04;

s32 *func_001C3A08(s32 arg0, s32 arg2, f32 fparg0) {
    char sp[0x400];
    M2C_UNK sp30;
    s32 *var_v0;

    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(1, sp);
    GetPathPosFromS(arg0, &sp30, 0, fparg0);
    var_v0 = &g_2c0d04;
    if (arg2 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf3x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
    }
    return var_v0;
}
