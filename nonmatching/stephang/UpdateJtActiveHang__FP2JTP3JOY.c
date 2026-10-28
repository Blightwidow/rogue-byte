#include "m2c_macros.h"

M2C_UNK CalculateJtHangAccel__FP2JT();        /* extern */
M2C_UNK ClearVjoyPresses();          /* extern */
f32 GLimitAbs__Fff();         /* extern */
f32 GSmooth__FfffP3SMPPf(); /* extern */
M2C_UNK GetJtHangHeading__FP2JTPf();           /* extern */
s32 GrfbtnVjoyPressedWithin(); /* extern */
M2C_UNK LoadRotateMatrixRad();  /* extern */
s128 PosLoWorld();                      /* extern */
f32 RadNormalize__Ff();                          /* extern */
M2C_UNK ReblendAsegbl();                      /* extern */
M2C_UNK SetJtState();           /* extern */
M2C_UNK SetStepRadTarget();              /* extern */
M2C_UNK StartBinoc(); /* extern */
f32 atan2f();                               /* extern */
M2C_UNK func_001F5078();                         /* extern */
extern M2C_UNK D_002BF570;
extern M2C_UNK D_002BF580;
extern f32 D_FLT_002BF554;
extern f32 D_FLT_002BF558;
extern f32 D_FLT_002BF55C;
extern f32 D_FLT_002BF560;
extern f32 D_FLT_002BF564;
extern f32 D_FLT_002BF568;
extern f32 D_FLT_002BF56C;
extern f32 D_FLT_002BF58C;
extern f32 D_FLT_002BF590;
extern s128 g_2a2dc0;
extern f32 g_2dded0;

void UpdateJtActiveHang__FP2JTP3JOY(void *arg0) {
    f32 saved_reg_f20;
    f32 saved_reg_f22;
    M2C_UNK sp20;
    M2C_UNK sp28;
    M2C_UNK sp60;
    f32 sp90;
    s128 spA0;
    M2C_UNK var_f20;
    M2C_UNK var_f22;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f21;
    f32 temp_f2;
    f32 var_f1;
    s128 temp_v0;
    s32 temp_v1_4;
    s32 var_a2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    void *temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    var_f20 = saved_reg_f20;
    var_f22 = saved_reg_f22;
    var_s1 = 0;
    var_s3 = 0;
    GetJtHangHeading__FP2JTPf(&sp90);
    if (M2C_FIELD(arg0, s32 *, 0x18FC) != 0) {
        sp90 = RadNormalize__Ff(sp90 + 3.1415927f);
    }
    SetStepRadTarget(arg0, sp90);
    temp_f2 = RadNormalize__Ff(M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18) - M2C_FIELD(arg0, f32 *, 0x1A8));
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C) > 0.3f) {
        temp_f1 = fabsf(temp_f2);
        if (temp_f1 < 1.0471976f) {
            var_s1 = 1;
            goto block_7;
        }
        if (temp_f1 > 2.0943952f) {
            var_s3 = 1;
block_7:
            M2C_FIELD(arg0, f32 *, 0x18F4) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0);
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x18F8) = -1;
    }
    temp_v0 = PosLoWorld(M2C_FIELD(arg0, void **, 0x18C4));
    spA0 = temp_v0;
    PosLoWorld(arg0, temp_v0);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    LoadRotateMatrixRad(&sp60, g_2a2dc0, M2C_FIELD(arg0, f32 *, 0x1A8));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf7, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf8, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf6, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf5, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf7, $vf7y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf8, $vf7z */);
    M2C_ERROR(/* unknown instruction: vaddax.y $acc, $vf6, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmaddz.y $vf1, $vf8, $vf6z */);
    M2C_ERROR(/* unknown instruction: vaddax.z $acc, $vf5, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmaddy.z $vf1, $vf8, $vf5y */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x50($sp) */);
    var_s0 = M2C_FIELD(arg0, s32 *, 0x18D0);
    temp_f21 = RadNormalize__Ff(atan2f(sp28, sp20) - 1.5707964f);
    if (var_s0 != 1) {
        if (var_s0 < 2) {
            var_a2 = var_s0;
            if (var_s0 != 0) {

            } else {
                if (var_s3 != 0) {
                    var_s0 = 2;
                    goto block_52;
                }
                if (var_s1 != 0) {
                    var_a2 = var_s0;
                    if (D_FLT_002BF554 < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x18D4))) {
                        M2C_FIELD(arg0, s32 *, 0x18F8) = 0;
                        var_s0 = 1;
                        goto block_52;
                    }
                } else {
                    goto block_29;
                }
            }
        } else if (var_s0 != 2) {
            var_a2 = var_s0;
            if (var_s0 != 3) {

            } else {
                if ((var_s1 != 0) && (M2C_FIELD(arg0, s32 *, 0x18F8) != 0)) {
                    goto block_43;
                }
                if ((var_s3 != 0) && (M2C_FIELD(arg0, s32 *, 0x18F8) != 2)) {
                    goto block_46;
                }
                var_a2 = var_s0;
                if (D_FLT_002BF564 < fabsf(temp_f21)) {
                    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
                    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    var_v1 = 1;
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    if (!(D_FLT_002BF56C < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */))) {
                        var_v1 = 0;
                    }
                    var_v0 = 1;
                    goto block_51;
                }
            }
        } else {
            if (var_s1 != 0) {
                var_s0 = 0;
                goto block_52;
            }
            if (var_s3 != 0) {
                var_a2 = var_s0;
                if (D_FLT_002BF558 < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x18D4))) {
                    M2C_FIELD(arg0, s32 *, 0x18F8) = var_s0;
                    var_s0 = 1;
                    goto block_52;
                }
            } else {
block_29:
                if (D_FLT_002BF55C < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x18F4))) {
                    var_s0 = 1;
                }
                goto block_52;
            }
        }
    } else if ((var_s1 == 0) || (M2C_FIELD(arg0, s32 *, 0x18F8) == 0)) {
        if ((var_s3 == 0) || (M2C_FIELD(arg0, s32 *, 0x18F8) == 2)) {
            var_a2 = var_s0;
            if (fabsf(temp_f21) < D_FLT_002BF560) {
                temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x108));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                var_v1 = 1;
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < D_FLT_002BF568)) {
                    var_v1 = 0;
                }
                var_v0 = 3;
block_51:
                var_s0 = (var_v1 != 0) ? var_v0 : var_s0;
                goto block_52;
            }
        } else {
block_46:
            var_s0 = 2;
            M2C_FIELD(arg0, s32 *, 0x18F8) = -1;
            goto block_52;
        }
    } else {
block_43:
        var_s0 = 0;
        M2C_FIELD(arg0, s32 *, 0x18F8) = -1;
block_52:
        var_a2 = var_s0;
    }
    SetJtState(arg0, 3, var_a2);
    CalculateJtHangAccel__FP2JT(arg0);
    temp_v0_2 = M2C_FIELD(arg0, void **, 0x1900);
    if (temp_v0_2 != NULL) {
        func_001F5078(M2C_FIELD(temp_v0_2, s32 *, 4));
    }
    if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x400, 0x3E19999A) != 0) {
        temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
        if (M2C_FIELD(temp_v1_3, s32 (**)(void *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x318), 3) != 0) {
            ClearVjoyPresses(M2C_FIELD(arg0, void **, 0x150), 0x400);
            StartBinoc(arg0 + 0xF00, 0, 0, 0);
        }
    }
    temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x18D0);
    switch (temp_v1_4) {                            /* irregular */
    case 3:
        break;
    case 0:
        var_f22 = 0x3F800000;
        var_f20 = 0x3F800000;
block_69:
    default:
block_70:
        M2C_FIELD(arg0, f32 *, 0x199C) = GSmooth__FfffP3SMPPf(&D_002BF570, 0, M2C_FIELD(arg0, f32 *, 0x199C), var_f20, M2C_FIELD(&g_2dded0, f32 *, 4));
        temp_f0 = GSmooth__FfffP3SMPPf(&D_002BF580, 0, M2C_FIELD(arg0, f32 *, 0x1998), var_f22, M2C_FIELD(&g_2dded0, f32 *, 4));
        temp_f1_2 = M2C_FIELD(arg0, f32 *, 0x199C);
        M2C_FIELD(arg0, f32 *, 0x1998) = temp_f0;
        M2C_FIELD(arg0, f32 *, 0x1970) = (f32) (temp_f1_2 * temp_f0);
        M2C_FIELD(arg0, f32 *, 0x1988) = (f32) (1.0f - temp_f1_2);
        M2C_FIELD(arg0, f32 *, 0x197C) = (f32) (temp_f1_2 * (1.0f - temp_f0));
        ReblendAsegbl(M2C_FIELD(arg0, void **, 0x1994));
        var_f1 = -1.0f;
        temp_f0_2 = temp_f21 / D_FLT_002BF58C;
        if (!(temp_f0_2 < -1.0f)) {
            var_f1 = temp_f0_2;
            if (temp_f0_2 > 1.0f) {
                var_f1 = 1.0f;
            }
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), f32 *, 0x40) = GLimitAbs__Fff(&g_2dded0, &D_FLT_002BF590, ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x1994), f32 *, 0x74) * (var_f1 + 1.0f) * 0.5f) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), f32 *, 0x1C)) / M2C_FIELD(&g_2dded0, f32 *, 4), D_FLT_002BF590);
        break;
    case 2:
        var_f20 = 0x3F800000;
        var_f22 = 0;
        goto block_70;
    case 1:
        var_f20 = 0;
        var_f22 = 0;
        if (M2C_FIELD(arg0, f32 *, 0x1998) > 0.5f) {
            var_f22 = 0x3F800000;
        }
        goto block_69;
    }
}
