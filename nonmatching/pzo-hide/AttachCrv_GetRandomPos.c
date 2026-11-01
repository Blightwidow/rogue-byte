#include "m2c_macros.h"

M2C_UNK GRandInRange(M2C_UNK, f32);                 /* extern */
M2C_UNK GetPathPosFromS(s32, void *, M2C_UNK *, f32); /* extern */
f32 SRandNearCrv(f32);                              /* extern */
extern s128 g_2a2da0;
extern s128 g_2a2dc0;
extern f32 g_2be8b8;
extern f32 g_2be8bc;

void AttachCrv_GetRandomPos(s32 arg0, s32 arg1, s128 *arg2) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    s128 sp30;
    s128 sp40;

    GetPathPosFromS(arg0, sp, &sp10, SRandNearCrv(g_2be8b8));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
        sp30 = g_2a2da0;
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
    }
    sp40 = sp0;
    GRandInRange(0, g_2be8bc);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
    *arg2 = g_2a2dc0;
}
