#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, M2C_UNK, s128); /* extern */
s32 CSolveQuadratic__FfffPf(f32 *, f32, M2C_UNK, f32); /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s128 ConvertAloPos(s32, M2C_UNK, s128);             /* extern */
s128 FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(s128, s128, s128, f32); /* extern */
s32 FGadgetAcquired(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, M2C_UNK, s32); /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
f32 RadYawSo(s32);                                  /* extern */
M2C_UNK ReblendAsegbl(s32);                         /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s128 *, s128);     /* extern */
f32 atan2f(f32, f32);                               /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_0021C5F8(void *, s128);                /* extern */
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002C40E4;
extern M2C_UNK D_FLT_002C40F0;
extern f32 D_FLT_002C4100;
extern f32 D_FLT_002C4104;
extern M2C_UNK func_0021FB18;
extern s128 g_2a2dc0;
extern M2C_UNK g_2dded0;

void CarryThrow_UpdateArc(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp208;
    M2C_UNK sp210;
    M2C_UNK sp220;
    M2C_UNK sp250;
    M2C_UNK sp260;
    M2C_UNK sp4;
    M2C_UNK unksp20C;
    M2C_UNK sp10;
    M2C_UNK sp20;
    s128 sp200;
    s32 sp21C;
    s32 sp22C;
    s128 sp230;
    s128 sp240;
    s32 sp270;
    s32 sp274;
    s128 sp280;
    s128 sp290;
    s128 sp2A0;
    s128 sp2C0;
    s128 sp2D0;
    f32 *var_v1;
    f32 temp_a0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f1;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f25;
    f32 var_f2;
    f32 var_f3;
    f32 var_f3_2;
    f32 var_f5;
    s128 var_a1;
    s32 temp_a0_2;
    s32 temp_s5;
    s32 temp_v0;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;
    u32 var_s0;
    u32 var_s0_2;
    void *temp_v1;
    void *var_s0_3;

    sp280 = ConvertAloPos(M2C_FIELD(arg0, s32 *, 0), 0, M2C_FIELD(arg0, s128 *, 0xD0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($s2) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x2e0($sp) */);
    sp290 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xE8), s128 *, 0x80);
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    temp_f2 = M2C_FIELD(arg0, f32 *, 0x1C);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x2e0($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_f0 = (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) - temp_f2) / (M2C_FIELD(arg0, f32 *, 0x20) - temp_f2);
    var_f25 = 0.0f;
    if (!(temp_f0 < 0.0f)) {
        var_f25 = temp_f0;
        if (temp_f0 > 1.0f) {
            var_f25 = 1.0f;
        }
    }
    sp2A0 = FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(sp280, M2C_FIELD(arg0, s128 *, 0xE0), sp290, M2C_FIELD(&D_FLT_002C40F0, f32 *, 0) + (var_f25 * (M2C_FIELD(&D_FLT_002C40F0, f32 *, 4) + (var_f25 * M2C_FIELD(&D_FLT_002C40F0, f32 *, 8)))));
    M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */);
    M2C_ERROR(/* unknown instruction: pextuw $a1, $zero, $a1 */);
    M2C_ERROR(/* unknown instruction: pextuw $a0, $zero, $a0 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x280($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x2a0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x290($sp) */);
    M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f2 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf4, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf5, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x2b0($sp) */);
    if (FGadgetAcquired(0x24, M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */)) != 0) {
        var_f20 = D_FLT_002C40E4 * M2C_FIELD(arg0, f32 *, 0x24);
    } else {
        var_f20 = M2C_FIELD(arg0, f32 *, 0x24);
    }
    var_s0 = 1;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x280($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x2a0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x290($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf5, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x2e0($sp) */);
    CStackFrame_Construct(&sp10, M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */));
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x2e0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x2b0($sp) */);
    M2C_ERROR(/* unknown instruction: vmax.xyz $vf2, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmini.xyz $vf1, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x280($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x280($sp) */);
    M2C_ERROR(/* unknown instruction: vmini.xyz $vf4, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmax.xyz $vf5, $vf5, $vf2 */);
    bevy_camera_follow_push_out(&B_003DD490, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf5 */), &func_0021FB18);
    M2C_FIELD(arg0, s128 *, 0xF0) = sp2A0;
    temp_f21 = var_f20 * 0.03448276f;
    var_a1 = sp280;
loop_7:
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x280($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x2a0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x290($sp) */);
    var_f20_2 = (f32) var_s0 * temp_f21;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf4, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf5, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x2f0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x2f0($sp) */);
    if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(1, var_a1, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */), sp270) != 0) {
        temp_v0 = CSolveQuadratic__FfffPf(sp, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */) * 0.5f, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */) - sp208);
        var_f1 = 0.0f;
        var_f3 = 3.4028235e38f;
        if (temp_v0 > 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x200($sp) */);
            var_v0 = temp_v0;
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x260($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x280($sp) */);
            var_v1 = sp;
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x2a0($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x290($sp) */);
            do {
                temp_f2_2 = *var_v1;
                if (temp_f2_2 < 0.0f) {
                    var_v0 -= 1;
                } else {
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf6 */);
                    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf5, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf4, $vf3x */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf7 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    temp_a0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
                    var_v0 -= 1;
                    if (temp_a0 < var_f3) {
                        var_f3 = temp_a0;
                        var_f1 = temp_f2_2;
                    }
                }
                var_v1 += 4;
            } while (var_v0 != 0);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x260($sp) */);
        }
        var_f20_2 = var_f1;
    } else {
        var_s0 += 1;
        var_a1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */);
        if (var_s0 < 0x1DU) {
            goto loop_7;
        }
    }
    temp_f2_3 = M2C_FIELD(arg0, f32 *, 0x130);
    temp_f0_2 = D_FLT_002C4100 * M2C_FIELD(&g_2dded0, f32 *, 4);
    temp_f1 = temp_f2_3 + temp_f0_2;
    var_f2 = temp_f2_3 - temp_f0_2;
    if (!(var_f20_2 < var_f2)) {
        var_f2 = var_f20_2;
        if (temp_f1 < var_f20_2) {
            var_f2 = temp_f1;
        }
    }
    M2C_FIELD(arg0, f32 *, 0x130) = var_f2;
    var_s0_2 = 0;
    if (!(var_f2 < 0.1f)) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x2a0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x290($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x280($sp) */);
loop_24:
        var_s0_2 += 1;
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf5, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf4, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
        if (var_s0_2 < 0x1DU) {
            if (!((M2C_FIELD(arg0, f32 *, 0x130) - ((f32) var_s0_2 * temp_f21)) < 0.1f)) {
                goto loop_24;
            }
        }
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    }
    temp_v1 = M2C_FIELD(arg0, void **, 0x12C);
    temp_s5 = var_s0_2 + 1;
    M2C_FIELD(((var_s0_2 * 0x10) + sp), s128 *, 0x20) = sp280;
    if (temp_v1 != NULL) {
        temp_a0_2 = M2C_FIELD(temp_v1, s32 *, 0x158);
        var_s1 = 0;
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf4 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
        var_s0_3 = M2C_FIELD(temp_v1, s32 *, 0x15C) + (temp_a0_2 * 0x50);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf3x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
        if (temp_a0_2 > 0) {
            var_v0_2 = temp_s5 > 0;
            do {
                var_s0_3 -= 0x50;
                if (var_v0_2 != 0) {
                    sp2C0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
                    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp240, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), g_2a2dc0);
                    __as__6VECTORG9VU_VECTOR(&sp230, sp2C0);
                    sp200 = sp240;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x2c0($sp) */);
                    M2C_FIELD(&sp200, s128 *, 0x10) = sp250;
                    M2C_FIELD(&sp200, s128 *, 0x20) = sp260;
                    sp22C = 0;
                    sp21C = 0;
                    unksp20C = 0;
                    M2C_FIELD(&sp200, f32 *, 0x3C) = 1.0f;
                    M2C_FIELD(var_s0_3, M2C_UNK32 *, 4) = 0x3F800000;
                } else {
                    M2C_FIELD(var_s0_3, M2C_UNK32 *, 4) = 0;
                }
                var_s1 += 1;
                M2C_FIELD(var_s0_3, s32 *, 8) = 0;
                M2C_FIELD(var_s0_3, f32 *, 0) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0);
                M2C_FIELD(var_s0_3, s128 *, 0x10) = sp200;
                M2C_FIELD(var_s0_3, s128 *, 0x20) = sp210;
                M2C_FIELD(var_s0_3, s128 *, 0x30) = sp220;
                M2C_FIELD(var_s0_3, s128 *, 0x40) = sp230;
                var_v0_2 = var_s1 < temp_s5;
            } while (var_s1 < M2C_FIELD(M2C_FIELD(arg0, void **, 0x12C), s32 *, 0x158));
        }
        func_0021C5F8(M2C_FIELD(arg0, void **, 0x12C), sp280);
    }
    sp2D0 = M2C_FIELD(arg0, s128 *, 0xE0);
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x2d0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    temp_f20 = atan2f(sp4, sp0);
    var_f0 = RadNormalize__Ff(temp_f20 - RadYawSo(M2C_FIELD(arg0, s32 *, 0))) / M2C_FIELD(arg0, f32 *, 0x18);
    if (var_f0 < -1.0f) {
        var_f0 = -1.0f;
    } else if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
    }
    var_f3_2 = (var_f0 * 0.5f) + 0.5f;
    if (arg1 != 0) {
        temp_f2_4 = M2C_FIELD(arg0, f32 *, 0xB0);
        if (temp_f2_4 > 0.5f) {
            var_f5 = M2C_FIELD(arg0, f32 *, 0x8C) / temp_f2_4;
        } else {
            var_f5 = M2C_FIELD(arg0, f32 *, 0x74) / (1.0f - temp_f2_4);
        }
        temp_f0_3 = D_FLT_002C4104 * M2C_FIELD(&g_2dded0, f32 *, 4);
        temp_f1_2 = temp_f2_4 - temp_f0_3;
        temp_f4 = temp_f2_4 + temp_f0_3;
        if (var_f25 < temp_f1_2) {
            var_f25 = temp_f1_2;
        } else if (temp_f4 < var_f25) {
            var_f25 = temp_f4;
        }
        temp_f2_5 = var_f5 - temp_f0_3;
        temp_f0_4 = var_f5 + temp_f0_3;
        if (var_f3_2 < temp_f2_5) {
            var_f3_2 = temp_f2_5;
        } else if (temp_f0_4 < var_f3_2) {
            var_f3_2 = temp_f0_4;
        }
    }
    temp_f20_2 = 1.0f - var_f25;
    temp_f0_5 = 1.0f - var_f3_2;
    M2C_FIELD(arg0, f32 *, 0x8C) = (f32) (var_f3_2 * var_f25);
    M2C_FIELD(arg0, f32 *, 0x74) = (f32) (var_f3_2 * temp_f20_2);
    M2C_FIELD(arg0, f32 *, 0x80) = (f32) (temp_f0_5 * var_f25);
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) (temp_f0_5 * temp_f20_2);
    ReblendAsegbl(M2C_FIELD(arg0, s32 *, 0x98));
    M2C_FIELD(arg0, f32 *, 0xA4) = temp_f20_2;
    M2C_FIELD(arg0, f32 *, 0xB0) = var_f25;
    ReblendAsegbl(M2C_FIELD(arg0, s32 *, 0xBC));
    CStackFrame_Destructor(&sp10, 2);
}
