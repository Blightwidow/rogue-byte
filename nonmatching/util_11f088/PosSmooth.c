#include "m2c_macros.h"

f32 GSmooth__FfffP3SMPPf(s32, f32 *, M2C_UNK, f32, f32); /* extern */
extern s128 g_2a2dd0;

s32 PosSmooth(s32 arg2, s128 *arg3, f32 fparg0) {
    f32 sp10;
    s128 sp20;
    f32 temp_f1;
    f32 temp_v0;

    sp20 = M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf1 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf4 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    if (temp_v0 > 0.0001f) {
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
        temp_f1 = GSmooth__FfffP3SMPPf(arg2, &sp10, 0, temp_v0, fparg0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
        if (arg3 != NULL) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s0) */);
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    }
    if (arg3 != NULL) {
        *arg3 = g_2a2dd0;
    }
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
}
