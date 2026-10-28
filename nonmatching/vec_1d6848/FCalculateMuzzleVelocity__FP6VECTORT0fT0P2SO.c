#include "m2c_macros.h"

f32 atan2f(f32, f32);                               /* extern */
f32 cosf(f32);                                      /* extern */
f32 sinf();                                         /* extern */
f32 tanf(f32);                                      /* extern */
extern s128 g_2a2dd0;

s128 FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(s128 arg0, s128 arg1, s128 arg2) {
    M2C_UNK sp0;
    M2C_UNK unksp18;
    f32 sp8;
    s128 sp10;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f24;
    f32 temp_v0;
    f32 var_f12;

    sp40 = arg0;
    sp30 = arg1;
    sp50 = arg2;
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    temp_f21 = sinf();
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    temp_f24 = sp8;
    sp8 = 0.0f;
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    var_f12 = atan2f(temp_f24, temp_v0);
    if (var_f12 < 0.0f) {
        var_f12 = 0.0f;
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    temp_f21_2 = var_f12 + ((1.5707964f - var_f12) * temp_f21);
    temp_f0 = 2.0f * (temp_f24 - (temp_v0 * tanf(temp_f21_2)));
    if (!((M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) / temp_f0) <= 0.0f)) {
        M2C_ERROR(/* unknown instruction: c1 0x140004 */);
        temp_f20 = (temp_v0 * temp_f0) / cosf(temp_f21_2);
        sp10 = sp0;
        unksp18 = temp_v0 * tanf(temp_f21_2);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf3x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
        return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
    }
    return g_2a2dd0;
}
