#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, s128, s128); /* extern */
M2C_UNK ConvertXfMat(s128 *, M2C_UNK, void *, s128 *); /* extern */
M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, f32, f32, f32); /* extern */
M2C_UNK RefreshXfActSegment(s32, void *, void *);   /* extern */
extern s128 D_002BC380;
extern s128 g_2a2dc0;

void GetActbankRotationGoal(void *arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp50;
    M2C_UNK sp60;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp70;
    f32 temp_f0;
    f32 temp_f12;
    s128 var_a1;
    s128 var_a2_2;
    s16 temp_v1;
    s16 temp_v1_2;
    void *temp_a0;
    void *temp_a3;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_a0;
    void *var_a2;

    var_a2 = arg2;
    if (M2C_FIELD(arg0, void **, 0x24) == NULL) {
        temp_v0 = M2C_FIELD(arg0, void **, 8);
        var_a0 = M2C_FIELD(temp_v0, void **, 0xA0);
        var_a2 = temp_v0;
        if (var_a0 != NULL) {
            if (M2C_FIELD(var_a0, s32 *, 0x94) != 1) {
                var_a0 = M2C_FIELD(var_a0, void **, 0xA0);
loop_4:
                if (var_a0 != NULL) {
                    if (M2C_FIELD(var_a0, s32 *, 0x94) != 1) {
                        var_a0 = M2C_FIELD(var_a0, void **, 0xA0);
                        goto loop_4;
                    }
                    goto block_8;
                }
                goto block_11;
            }
block_8:
            if (var_a0 != NULL) {
                M2C_FIELD(arg0, void **, 0x24) = var_a0;
                goto block_12;
            }
            goto block_11;
        }
block_11:
        temp_a0 = var_a2 + 0xC0;
        M2C_FIELD(var_a2, s128 *, 0xC0) = (s128) M2C_FIELD(var_a2, s128 *, 0);
        M2C_FIELD(temp_a0, s128 *, 0x10) = (s128) M2C_FIELD(var_a2, s128 *, 0x10);
        M2C_FIELD(temp_a0, s128 *, 0x20) = (s128) M2C_FIELD(var_a2, s128 *, 0x20);
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 0x9A) = 5;
        return;
    }
block_12:
    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    temp_v0_2 = M2C_FIELD(temp_s0, void **, 0x90);
    if (temp_v0_2 != NULL) {
        RefreshXfActSegment(M2C_FIELD(temp_v0_2, s32 *, 4), temp_s0, var_a2);
    }
    temp_v1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), u16 *, 0x98) - 1;
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
    case 6:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
    case 8:                                         /* switch 1 */
    case 10:                                        /* switch 1 */
    case 16:                                        /* switch 1 */
    case 17:                                        /* switch 1 */
    case 19:                                        /* switch 1 */
    case 20:                                        /* switch 1 */
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xb0($s0) */);
        break;
    case 4:                                         /* switch 1 */
    case 5:                                         /* switch 1 */
        temp_v1_2 = M2C_FIELD(temp_s0, s16 *, 0x9A);
        switch (temp_v1_2) {                        /* switch 2 */
        case 3:                                     /* switch 2 */
        case 4:                                     /* switch 2 */
            break;
        case 1:                                     /* switch 2 */
            temp_f0 = M2C_FIELD(temp_s0, f32 *, 0x80);
            EvaluateBezierPos__FfffP6VECTORN63(M2C_FIELD(temp_s0, s128 *, 0xC0), M2C_FIELD(temp_s0, s128 *, 0xD0), M2C_FIELD(temp_s0, s128 *, 0xE0), M2C_FIELD(temp_s0, s128 *, 0xF0), M2C_FIELD(temp_s0, f32 *, 0x84) - temp_f0, *M2C_FIELD(temp_s0, f32 **, 0x88) - temp_f0, *M2C_FIELD(temp_s0, f32 **, 0x8C));
            break;
        default:                                    /* switch 2 */
        case 0:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
        case 5:                                     /* switch 2 */
            break;
        }
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf5 */);
        break;
    default:                                        /* switch 1 */
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf5, $vf0, $vf0 */);
        break;
    }
    if (M2C_FIELD(temp_s0, s32 *, 0xA0) != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf2, $vf5z */);
    }
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf5, $vf5 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 100.0f) {
        var_a2_2 = g_2a2dc0;
        var_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0x40);
    } else {
        temp_f12 = M2C_FIELD(arg0, f32 *, 0x20);
        sp70 = D_002BC380;
        if ((temp_f12 > 0.0f) && (M2C_FIELD(arg0, f32 *, 0x1C) > 0.0f)) {
            temp_a3 = M2C_FIELD(temp_s0, void **, 0x90);
            if (temp_a3 != NULL) {
                temp_v0_3 = M2C_FIELD(temp_a3, void **, 0x18);
                M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x80($sp) */);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, void *, void *, f32), 0x2C)(temp_a3 + M2C_FIELD(temp_v0_3, s16 *, 0x28), 0, sp, temp_a3, temp_f12);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x80($sp) */);
                if (M2C_FIELD(temp_s0, s32 *, 0xA0) != 0) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($a1) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf3, $vf1z */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf5 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
            }
        }
        var_a2_2 = sp70;
        var_a1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf5 */);
    }
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp40, var_a1, var_a2_2);
    sp20 = sp50;
    sp30 = sp60;
    sp10 = sp40;
    temp_s0_2 = M2C_FIELD(arg0, void **, 8);
    temp_s1 = temp_s0_2 + 0xC0;
    ConvertXfMat(&sp40, 0, M2C_FIELD(temp_s0_2, void **, 0xA0), &sp10);
    M2C_FIELD(temp_s0_2, s128 *, 0xC0) = sp40;
    M2C_FIELD(temp_s1, s128 *, 0x10) = sp50;
    M2C_FIELD(temp_s1, s128 *, 0x20) = sp60;
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 0x9A) = 5;
}
