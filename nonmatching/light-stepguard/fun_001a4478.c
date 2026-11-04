#include "m2c_macros.h"

M2C_UNK FindSwLights(s128, M2C_UNK, f32 *);         /* extern */
M2C_UNK GetNormalVectors__FP6VECTORN30(M2C_UNK, s128, s128, s128 *); /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, s128);  /* extern */
s32 func_001A4258(s128, M2C_UNK, s128 *, M2C_UNK *, f32); /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_002BFC60;
extern s128 g_2a2da0;
extern s128 g_2a2db0;
extern f32 g_2bfc94;
extern M2C_UNK g_2dea28;

void func_001A4478(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp120;
    M2C_UNK sp40;
    M2C_UNK sp50;
    M2C_UNK unksp6C;
    void *sp4;
    s128 sp30;
    s128 sp60;
    s32 sp7C;
    s32 sp8C;
    M2C_UNK sp90;
    s32 spA0;
    f32 spA4;
    s128 spB0;
    f32 spC0;
    f32 spE0;
    s32 sp100;
    s128 sp110;
    M2C_UNK *var_a3_2;
    f32 *var_s0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    f32 var_f20;
    f32 var_f21;
    s128 *var_s0_2;
    s32 *temp_v0;
    s32 *temp_v0_3;
    s32 *temp_v1;
    s32 *temp_v1_3;
    s32 *temp_v1_6;
    s32 *var_a0;
    s32 *var_a0_2;
    s32 *var_a2;
    s32 *var_a2_2;
    s32 *var_a2_3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 temp_v1_7;
    s32 var_a3_3;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t0_3;
    s32 var_v0;
    s32 var_v0_2;
    u32 temp_t1;
    u32 var_s2;
    u32 var_t5;
    void *temp_v1_5;
    void *var_a1;
    void *var_a1_2;
    void *var_a3;

    sp110 = *M2C_FIELD(arg2, s128 **, 4);
    if (arg1 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($a1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($a1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($a1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($a1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf5z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf4, $vf0w */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x110($sp) */);
    }
    FindSwLights(sp110, 4, sp);
    if (M2C_FIELD(arg2, f32 *, 0x10) == 0.0f) {
        M2C_FIELD(arg2, s32 *, 0x14) = 0;
        M2C_FIELD(arg2, s32 **, 0x18) = NULL;
    } else {
        var_a1 = sp4;
        var_t0 = 0;
        var_t5 = 0;
        M2C_FIELD(arg2, s32 **, 0x18) = (s32 *) M2C_FIELD(&g_2dea28, s32 **, 0xC);
        if (var_a1 != NULL) {
            var_v0 = 0 * 2;
loop_6:
            var_a3 = var_a1 + 0x120;
            *M2C_FIELD(&g_2dea28, s32 **, 0xC) = (var_v0 + var_t0 + 0x15) | 0x6C03C000;
            temp_v1 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
            var_a2 = temp_v1;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1;
            temp_t1 = var_t5 + 1;
            var_t0_2 = 8;
            do {
                var_t0_2 -= 4;
                temp_v1_2 = M2C_FIELD(var_a3, s32 *, 4);
                temp_a0 = M2C_FIELD(var_a3, s32 *, 8);
                temp_a1 = M2C_FIELD(var_a3, s32 *, 0xC);
                M2C_FIELD(var_a2, s32 *, 0) = M2C_FIELD(var_a3, s32 *, 0);
                var_a3 += 0x10;
                M2C_FIELD(var_a2, s32 *, 4) = temp_v1_2;
                M2C_FIELD(var_a2, s32 *, 8) = temp_a0;
                M2C_FIELD(var_a2, s32 *, 0xC) = temp_a1;
                var_a2 += 0x10;
            } while (var_t0_2 >= 0);
            var_t0 += 1;
            var_t5 = temp_t1;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x30);
            if (temp_t1 < 4U) {
                var_a1 = *(&sp4 + (temp_t1 * 8));
                var_v0 = var_t0 * 2;
                if (var_a1 != NULL) {
                    goto loop_6;
                }
            }
        }
        if (var_t0 < 4) {
            do {
                var_a3_2 = &D_002BFC60;
                *M2C_FIELD(&g_2dea28, s32 **, 0xC) = ((var_t0 * 3) + 0x15) | 0x6C03C000;
                temp_v1_3 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                var_a2_2 = temp_v1_3;
                M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1_3;
                var_t0_3 = 8;
loop_13:
                var_t0_3 -= 4;
                temp_v1_4 = M2C_FIELD(var_a3_2, s32 *, 4);
                temp_a0_2 = M2C_FIELD(var_a3_2, s32 *, 8);
                temp_a1_2 = M2C_FIELD(var_a3_2, s32 *, 0xC);
                M2C_FIELD(var_a2_2, s32 *, 0) = M2C_FIELD(var_a3_2, s32 *, 0);
                var_a3_2 += 0x10;
                M2C_FIELD(var_a2_2, s32 *, 4) = temp_v1_4;
                M2C_FIELD(var_a2_2, s32 *, 8) = temp_a0_2;
                M2C_FIELD(var_a2_2, s32 *, 0xC) = temp_a1_2;
                var_a2_2 += 0x10;
                if (var_t0_3 >= 0) {
                    goto loop_13;
                }
                var_t0 += 1;
                M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x30);
            } while (var_t0 < 4);
        }
        var_a0 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
        if ((s32) var_a0 & 0xF) {
            do {
                *var_a0 = 0;
                temp_v0 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                var_a0 = temp_v0;
                M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0;
            } while ((s32) var_a0 & 0xF);
        }
        M2C_FIELD(arg2, s32 *, 0x14) = (s32) ((s32) (M2C_FIELD(&g_2dea28, s32 **, 0xC) - M2C_FIELD(arg2, s32 **, 0x18)) >> 4);
    }
    if (M2C_FIELD(arg2, f32 *, 0x1C) != 0.0f) {
        var_a1_2 = sp4;
        var_f20 = 0.0f;
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf0, $vf0 */);
        var_s2 = 0;
        if (var_a1_2 != NULL) {
            var_s0 = sp;
            var_v0_2 = M2C_FIELD(var_a1_2, s32 *, 0x158);
loop_23:
            if (var_v0_2 != 0) {
                temp_v0_2 = M2C_FIELD(var_a1_2, s32 *, 0xE0);
                if (temp_v0_2 != 0) {
                    if (temp_v0_2 == 1) {
                        temp_v1_5 = M2C_FIELD(var_a1_2, void **, 0xC);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        var_f20 += *var_s0;
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x130($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x140($sp) */);
                        M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *, void *), 0xFC)(var_a1_2 + M2C_FIELD(temp_v1_5, s16 *, 0xF8), var_a1_2);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x130($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x140($sp) */);
                        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
                        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf2x */);
                    }
                } else {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x110($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    var_f20 += *var_s0;
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($a1) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf5 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf2, $vf3x */);
                }
            }
            var_s2 += 1;
            var_s0 += 8;
            if (var_s2 < 4U) {
                var_a1_2 = M2C_FIELD(var_s0, void **, 4);
                if (var_a1_2 != NULL) {
                    var_v0_2 = M2C_FIELD(var_a1_2, s32 *, 0x158);
                    goto loop_23;
                }
            }
        }
        if (var_f20 == 0.0f) {
            goto block_33;
        }
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x110($sp) */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf4, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x120($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf4 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        var_f21 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        temp_f1 = g_2bfc94 * M2C_FIELD(arg2, f32 *, 0x1C);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
        if (var_f21 < temp_f1) {
            if (var_f21 < 1.0f) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
            } else {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf4, $vf4, $q */);
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x110($sp) */);
            var_f21 = temp_f1;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x120($sp) */);
        } else {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf4, $vf4, $q */);
        }
        temp_f20 = var_f21 + M2C_FIELD(arg2, f32 *, 0x20);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x140($sp) */);
        GetNormalVectors__FP6VECTORN30(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf4 */), g_2a2db0, g_2a2da0, &sp30);
        var_s0_2 = &sp60;
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x140($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf4, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
        __as__6VECTORG9VU_VECTOR(&sp90, sp120);
        sp60 = sp30;
        temp_f2 = M2C_FIELD(arg2, f32 *, 0x1C);
        M2C_FIELD(var_s0_2, s128 *, 0x10) = sp40;
        M2C_FIELD(var_s0_2, s128 *, 0x20) = sp50;
        sp8C = 0;
        sp7C = 0;
        unksp6C = 0;
        M2C_FIELD(var_s0_2, f32 *, 0x3C) = 1.0f;
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x120($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf3x */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf4, $vf1 */);
        spA4 = var_f21 / temp_f20;
        spB0 = sp110;
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xd0($sp) */);
        spE0 = (temp_f2 * temp_f20) / var_f21;
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xf0($sp) */);
        spC0 = temp_f2;
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        sp100 = 0;
        spA0 = func_001A4258(M2C_FIELD(&B_002DDF40, s128 *, 0x90), 3, &spB0, &B_002DDF40, M2C_FIELD(&B_002DDF40, f32 *, 0x48));
        M2C_FIELD(arg2, s32 **, 0x2C) = (s32 *) M2C_FIELD(&g_2dea28, s32 **, 0xC);
        M2C_FIELD(arg2, void **, 0x24) = (void *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x10);
        var_a0_2 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
        if (((s32) var_a0_2 & 0xF) != 0xC) {
            do {
                *var_a0_2 = 0;
                temp_v0_3 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                var_a0_2 = temp_v0_3;
                M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0_3;
            } while (((s32) var_a0_2 & 0xF) != 0xC);
        }
        *M2C_FIELD(&g_2dea28, s32 **, 0xC) = 0x6C05C00E;
        temp_v1_6 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
        var_a2_3 = temp_v1_6;
        M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1_6;
        var_a3_3 = 0x10;
        do {
            var_a3_3 -= 4;
            temp_v1_7 = M2C_FIELD(var_s0_2, s32 *, 4);
            temp_a0_3 = M2C_FIELD(var_s0_2, s32 *, 8);
            temp_a1_3 = M2C_FIELD(var_s0_2, s32 *, 0xC);
            M2C_FIELD(var_a2_3, s32 *, 0) = M2C_FIELD(var_s0_2, s32 *, 0);
            var_s0_2 += 0x10;
            M2C_FIELD(var_a2_3, s32 *, 4) = temp_v1_7;
            M2C_FIELD(var_a2_3, s32 *, 8) = temp_a0_3;
            M2C_FIELD(var_a2_3, s32 *, 0xC) = temp_a1_3;
            var_a2_3 += 0x10;
        } while (var_a3_3 >= 0);
        M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x50);
        M2C_FIELD(arg2, s32 *, 0x28) = (s32) ((s32) (M2C_FIELD(&g_2dea28, s32 **, 0xC) - M2C_FIELD(arg2, s32 **, 0x2C)) >> 4);
        return;
    }
block_33:
    M2C_FIELD(arg2, void **, 0x24) = NULL;
    M2C_FIELD(arg2, s32 *, 0x28) = 0;
    M2C_FIELD(arg2, s32 **, 0x2C) = NULL;
}
