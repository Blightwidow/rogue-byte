#include "m2c_macros.h"

M2C_UNK InitPlaneFromNormalPos(s32, M2C_UNK, M2C_UNK); /* extern */

s32 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(s128 arg0, s128 arg2, s32 arg3, f32 fparg0) {
    char sp[0x400];
    f32 sp0;
    f32 sp4;
    s128 sp20;
    s128 sp30;
    f32 *var_s0;
    f32 *var_s1;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f5;
    f32 temp_v0;
    s32 temp_a0;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;
    void *temp_s5;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf5 */);
    temp_s5 = M2C_ERROR(/* Read from unset register $t0 */);
    sp30 = arg0;
    sp20 = arg2;
    if (arg3 > 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf5, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf4, $vf3z */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf4, $vf5 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf2 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
        temp_f5 = 2.0f * M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
        temp_f0 = temp_v0 * ((M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */) - (fparg0 * fparg0)) * 4.0f);
        if (((temp_f5 * temp_f5) - temp_f0) < 0.0001f) {
            return 0;
        }
        M2C_ERROR(/* unknown instruction: c1 0xc0004 */);
        temp_f2 = 2.0f * temp_v0;
        temp_f0_2 = -temp_f5;
        temp_f1 = (temp_f0_2 - temp_f0) / temp_f2;
        temp_f0_3 = (temp_f0_2 + temp_f0) / temp_f2;
        sp0 = temp_f1;
        sp4 = temp_f0_3;
        if (!(temp_f1 < 0.0f) || (var_v0 = 0, !(temp_f0_3 < 0.0f))) {
            if ((temp_f1 > 1.0f) && (temp_f0_3 > 1.0f)) {
                goto block_8;
            }
            var_s3 = temp_s5 + 0x20;
            sp4 = M2C_ERROR(/* unknown instruction: min.s $f0, $f0, $f2 */);
            sp0 = M2C_ERROR(/* unknown instruction: max.s $f1, $f1, $f3 */);
            var_s1 = temp_s5 + 0x40;
            var_s0 = sp;
            var_s4 = 1;
            do {
                *var_s1 = *var_s0;
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf5, $vf1x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf4, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($s2) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */);
                } else {
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                }
                temp_a0 = var_s3;
                M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
                var_s3 += 0x10;
                InitPlaneFromNormalPos(temp_a0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf4 */));
                var_s1 += 4;
                var_s0 += 4;
                var_s4 -= 1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($sp) */);
            } while (var_s4 >= 0);
            var_v0 = 1;
            M2C_FIELD(temp_s5, s32 *, 0x48) = 1;
            /* Duplicate return node #15. Try simplifying control flow for better match */
            return var_v0;
        }
        return var_v0;
    }
block_8:
    return 0;
}
