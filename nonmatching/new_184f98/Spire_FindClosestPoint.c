#include "m2c_macros.h"

M2C_UNK ClosestPointOnSegment(s128, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */

void Spire_FindClosestPoint(void *arg0, s128 arg1, void *arg3) {
    M2C_UNK saved_reg_s2;
    M2C_UNK spB0;
    f32 sp48;
    f32 sp58;
    M2C_UNK sp60;
    f32 sp80;
    s128 sp90;
    s128 spA0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_v0;
    f32 var_f22;
    s128 *temp_s4;
    s128 var_s2;
    s32 var_s0;
    void *temp_v1;

    var_s2 = saved_reg_s2;
    var_s0 = 0;
    temp_s4 = M2C_ERROR(/* Read from unset register $t0 */);
    spA0 = arg1;
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    var_f22 = 3.4028235e38f;
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf6, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf4, $vf1z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf12, $vf3, $vf0w */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf6, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf4, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf11, $vf3, $vf0w */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf6, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf4, $vf1z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf10, $vf3, $vf0w */);
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf9, $vf12 */);
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf7, $vf10 */);
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf8, $vf11 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf9, $vf7 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf8, $vf7 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf1, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf4, $vf7 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf4, $vf1 */);
            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf1, $vf4 */);
            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf4, $vf3, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf5, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf5, $vf3z */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf6, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf6, $vf2z */);
            temp_f0 = 1.0f / M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf4, $vf2, $vf4 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf4, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf4, $vf1, $vf4z */);
            temp_f2 = temp_f0 * M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
            temp_f1 = temp_f0 * M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
            if (temp_f2 < 0.0f) {
                ClosestPointOnSegment(spA0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf8 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf7 */), &sp60);
                sp48 = 1.0f - sp80;
            } else if (temp_f1 < 0.0f) {
                ClosestPointOnSegment(spA0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf9 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf7 */), &sp60);
                sp48 = 0.0f;
            } else if ((temp_f2 + temp_f1) > 1.0f) {
                ClosestPointOnSegment(spA0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf9 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf8 */), &sp60);
                sp48 = sp80;
            } else {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
                sp48 = temp_f1;
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf12, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf11, $vf3x */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf10, $vf1x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x60($sp) */);
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            if (temp_v0 < var_f22) {
                var_f22 = temp_v0;
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x47($sp) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x57($sp) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, 0x50($sp) */);
                sp58 = sp48;
                var_s2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $s2, $vf3 */);
                sp90 = spB0;
            }
            var_s0 += 1;
        } while (var_s0 < M2C_FIELD(arg0, s32 *, 0xE8));
    }
    if (arg3 != NULL) {
        M2C_ERROR(/* unknown instruction: ldl $a0, 0x57($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $a0, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $a0, 0x7($s3) */);
        M2C_ERROR(/* unknown instruction: sdr $a0, ($s3) */);
        M2C_FIELD(arg3, f32 *, 8) = sp58;
    }
    if (temp_s4 != NULL) {
        *temp_s4 = var_s2;
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
    if (M2C_ERROR(/* Read from unset register $t1 */) != 0) {
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s5) */);
    }
}
