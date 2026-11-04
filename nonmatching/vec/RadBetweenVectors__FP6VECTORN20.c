#include "m2c_macros.h"

M2C_UNK GetPerpendicularVector(M2C_UNK, M2C_UNK);   /* extern */
f32 acosf(f32);                                     /* extern */
extern s128 g_2a2da0;

f32 RadBetweenVectors__FP6VECTORN20(s128 *arg2) {
    f32 temp_v0;
    f32 temp_v0_2;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf4 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf5, $vf5 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    if ((temp_v0 < 0.0001f) || (temp_v0_2 < 0.0001f)) {
        if (arg2 != NULL) {
            *arg2 = g_2a2da0;
        }
        return 0.0f;
    }
    if (arg2 != NULL) {
        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf4, $vf5 */);
        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf5, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) > 1e-8f) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf3, $q */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        } else {
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x20($sp) */);
            GetPerpendicularVector(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf4 */), M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf5 */));
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        }
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($s0) */);
    }
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf5 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    return acosf(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) / (temp_v0 * temp_v0_2));
}
