#include "m2c_macros.h"

s128 PosLoWorld(void *);                            /* extern */
M2C_UNK PredictXfTransform(s32, M2C_UNK, M2C_UNK *, M2C_UNK, f32); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */

void MeasureJtJumpToTargetAtTime(void **arg0, void *arg1, s128 arg2, f32 *arg3, f32 fparg0) {
    M2C_UNK sp120;
    M2C_UNK spE0;
    f32 sp8;
    M2C_UNK sp10;
    M2C_UNK sp50;
    M2C_UNK spA0;
    s128 spF0;
    s128 sp100;
    s128 sp110;
    s128 sp130;
    f32 temp_f1;
    f32 temp_f2;
    s128 *temp_s4;
    s128 *temp_s5;
    s32 temp_a0;
    void *temp_a1;
    void *temp_a2;
    void *temp_v1;

    temp_s4 = M2C_ERROR(/* Read from unset register $t0 */);
    temp_s5 = M2C_ERROR(/* Read from unset register $t1 */);
    sp130 = arg2;
    spF0 = PosLoWorld(*arg0);
    temp_a1 = *arg0;
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    sp100 = M2C_FIELD(temp_v1, s128 (**)(void *, void *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
    temp_a2 = M2C_FIELD(arg1, void **, 0xC);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($v1) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xe0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xe0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xf0($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x120($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
    temp_a0 = M2C_FIELD(temp_a2, s32 (**)(void *, M2C_UNK *, void *), 0x104)(arg1 + M2C_FIELD(temp_a2, s16 *, 0x100), &sp50, temp_a2);
    sp110 = sp120;
    PredictXfTransform(temp_a0, 0, &sp10, 0, fparg0);
    __ml__FRC7MATRIX4T0(&spA0, &sp10, &sp50);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xd0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x130($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf6z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf4, $vf0w */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf5, $vf5, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf5, $vf5 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
    temp_f1 = M2C_FIELD(*arg0, f32 *, 0x1020);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < (temp_f1 * temp_f1)) {
        if (arg3 != NULL) {
            M2C_ERROR(/* unknown instruction: c1 0x20004 */);
            *arg3 = sp8 - temp_f1;
        }
        if (temp_s4 != NULL) {
            *temp_s4 = sp120;
        }
    } else {
        temp_f2 = fabsf(sp8);
        if (!(temp_f1 < temp_f2)) {
            if (fparg0 != 0.0f) {
                sp8 = 0.0f;
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */) < 0.0001f) {

                } else {
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                }
                M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
                M2C_ERROR(/* unknown instruction: c1 0x44 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x100($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf2, $vf1x */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($v1) */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
                M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf2, $vf3x */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf3x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xe0($sp) */);
                if (arg3 != NULL) {
                    *arg3 = M2C_ERROR(/* unknown instruction: min.s $f0, $f0, $f1 */);
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xf0($sp) */);
                if (temp_s4 != NULL) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x100($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf4, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf2, $vf1x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s4) */);
                }
            } else {
                goto block_9;
            }
        } else {
block_9:
            if (arg3 != NULL) {
                *arg3 = temp_f2 + 1010000.0f;
            }
            if (temp_s4 != NULL) {
                *temp_s4 = spF0;
            }
        }
    }
    if (temp_s5 != NULL) {
        *temp_s5 = spE0;
    }
}
