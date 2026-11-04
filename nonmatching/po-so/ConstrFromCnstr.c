#include "m2c_macros.h"

extern M2C_UNK D_002C3C20;
extern s128 g_2a2dd0;

s128 ConstrFromCnstr(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    M2C_FIELD(arg3, s32 *, 0x10) = (s32) *((arg2 * 4) + &D_002C3C20);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($a2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($a1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf3, $vf4z */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a3) */);
        return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    }
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a3) */);
    return g_2a2dd0;
}
