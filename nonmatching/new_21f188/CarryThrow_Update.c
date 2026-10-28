#include "m2c_macros.h"

M2C_UNK CarryThrow_SetState();       /* extern */
M2C_UNK CarryThrow_UpdateArc();      /* extern */
M2C_UNK DecomposeCylind(); /* extern */
u64 FAsegaGone();                        /* extern */
s32 FButtonPressedWithin(); /* extern */
s32 FGadgetAcquired();              /* extern */
s32 FIsBasicDerivedFrom();           /* extern */
f32 GLimitLm__FP2LMf();                  /* extern */
void *PchnFindAseg();  /* extern */
s128 PosLoWorld();                       /* extern */
f32 RadNormalize__Ff();                          /* extern */
f32 RadYawSo();                               /* extern */
M2C_UNK ReblendAsegbl();                         /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(); /* extern */
f32 atan2f();                               /* extern */
M2C_UNK func_00136530();             /* extern */
extern f32 D_FLT_002C40E0;
extern s128 g_2a2dd0;
extern void *g_2dd5bc;
extern f32 g_2dded0;
extern f32 g_2dded4;

void CarryThrow_Update(void *arg0) {
    char sp[0x400];
    M2C_UNK sp8;
    f32 sp0;
    f32 sp4;
    M2C_UNK32 sp18;
    f32 sp20;
    f32 sp24;
    s128 sp30;
    s128 sp40;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_v1;
    s32 temp_v1_2;
    u64 temp_ret;
    void **temp_a3;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_a2_4;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *var_v0;

    temp_a0 = M2C_FIELD(arg0, void **, 0);
    temp_s3 = M2C_FIELD(temp_a0, void **, 0x150);
    sp30 = PosLoWorld(temp_a0);
    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_v1 < 7) {
        if (temp_v1 < 4) {

        } else {
            if (M2C_FIELD(arg0, s32 *, 0x128) != 0) {
                if (!((M2C_FIELD(arg0, f32 *, 0x120) + M2C_FIELD(arg0, f32 *, 0x124)) <= g_2dded0)) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x100($s1) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x110($s1) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf3x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xe0($s1) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
                } else {
                    M2C_FIELD(arg0, s32 *, 0x128) = 0;
                    M2C_FIELD(arg0, s128 *, 0xE0) = (s128) M2C_FIELD(arg0, s128 *, 0x110);
                }
            } else {
                M2C_ERROR(/* unknown instruction: ldl $a1, 0x23($s1) */);
                M2C_ERROR(/* unknown instruction: ldr $a1, 0x1c($s1) */);
                M2C_ERROR(/* unknown instruction: sdl $a1, 0x7($sp) */);
                if (FGadgetAcquired(0x24, M2C_ERROR(/* unknown instruction: sdr $a1, ($sp) */)) != 0) {
                    sp4 *= D_FLT_002C40E0;
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($s1) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                sp18 = 0;
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
                SetVectorCylind__FP6VECTORfff(M2C_FIELD(temp_s3, f32 *, 0x18), M2C_FIELD(temp_s3, f32 *, 0x1C) * g_2dded4 * M2C_FIELD(arg0, f32 *, 0x28), sp18);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf3 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                DecomposeCylind(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), &sp20, &sp24, 0);
                temp_f0 = GLimitLm__FP2LMf(sp, sp24);
                sp24 = temp_f0;
                SetVectorCylind__FP6VECTORfff(sp20, temp_f0, sp18);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf4, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xe0($s1) */);
            }
            CarryThrow_UpdateArc(arg0, 1);
        }
    }
loop_15:
    temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x1030);
    switch ((u32) M2C_FIELD(arg0, s32 *, 4)) {
    case 0:
        PosLoWorld(M2C_FIELD(arg0, void **, 0x10), (u32) M2C_FIELD(arg0, s32 *, 4));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        temp_f20 = atan2f(sp4, sp0);
        temp_f0_2 = RadNormalize__Ff(temp_f20 - RadYawSo(M2C_FIELD(arg0, void **, 0)));
        temp_f1 = M2C_FIELD(arg0, f32 *, 0x14);
        if (temp_f1 < temp_f0_2) {
            CarryThrow_SetState(arg0, 2);
        } else if (!(temp_f0_2 < -temp_f1)) {
            temp_f0_3 = ((temp_f0_2 / temp_f1) * 0.5f) + 0.5f;
            M2C_FIELD(arg0, f32 *, 0x4C) = temp_f0_3;
            M2C_FIELD(arg0, f32 *, 0x40) = (f32) (1.0f - temp_f0_3);
            ReblendAsegbl(M2C_FIELD(arg0, s32 *, 0x58));
        } else {
            CarryThrow_SetState(arg0, 1);
        }
    default:
block_68:
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 4);
        if ((temp_v1_2 == (u32) M2C_FIELD(arg0, s32 *, 4)) || (temp_v1_2 == -1)) {
            temp_a1 = M2C_FIELD(arg0, void **, 0);
            if (M2C_FIELD(temp_a1, s32 *, 0x1A4) == 1) {
                temp_s0_2 = M2C_FIELD(temp_a1, void **, 0x1030);
                if (temp_s0_2 != NULL) {
                    var_v0 = PchnFindAseg(M2C_FIELD(temp_s0_2, s32 *, 0x14), temp_a1, 6, 1);
                } else {
                    var_v0 = NULL;
                }
                if (var_v0 != NULL) {
                    temp_a3 = M2C_FIELD(var_v0, void ***, 4);
                    temp_v0 = *temp_a3;
                    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *, void **, f32, f32), 0x1C)(temp_a3 + M2C_FIELD(temp_v0, s16 *, 0x18), 0, sp, temp_a3, M2C_FIELD(temp_s0_2, f32 *, 0x1C), M2C_FIELD(temp_s0_2, f32 *, 0x40));
                    temp_v0_2 = M2C_FIELD(arg0, void **, 0);
                    M2C_FIELD(temp_v0_2, s32 *, 0x1E0) = 0;
                    temp_v0_3 = temp_v0_2 + 0x1E0;
                    M2C_FIELD(temp_v0_3, f32 *, 8) = sp8;
                    M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
                } else {
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1E0) = (s128) g_2a2dd0;
                }
            }
        } else {
            goto loop_15;
        }
        break;
    case 1:
    case 2:
        if (temp_s0 != NULL) {
            if (FAsegaGone(temp_s0, (u32) M2C_FIELD(arg0, s32 *, 4)) != 0) {
block_65:
                goto block_66;
            }
        } else {
block_66:
            CarryThrow_SetState(arg0, 0);
        }
        goto block_68;
    case 3:
        if (temp_s0 != NULL) {
            if (FAsegaGone(temp_s0, (u32) M2C_FIELD(arg0, s32 *, 4)) != 0) {
                goto block_30;
            }
        } else {
block_30:
            if (M2C_FIELD(g_2dd5bc, s32 *, 0x13D0) != 8) {
                goto block_66;
            }
block_53:
block_54:
            CarryThrow_SetState(arg0, 4);
        }
        goto block_68;
    case 4:
    case 5:
    case 6:
        if ((FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x10), 0x64) != 0) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x158) != -1)) {
            temp_a2 = M2C_FIELD(arg0, void **, 0);
            temp_v0_4 = M2C_FIELD(temp_a2, void **, 0xC);
            M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2 + M2C_FIELD(temp_v0_4, s16 *, 0x2C0), 0, temp_a2);
            goto block_68;
        }
        if (FButtonPressedWithin(temp_s3, 0xC0, 0x3DCCCCCD) != 0) {
            CarryThrow_SetState(arg0, 7);
            goto block_68;
        }
        if (FButtonPressedWithin(temp_s3, 0x30, 0x3DCCCCCD) != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x58) == 0) {
                temp_a2_2 = M2C_FIELD(arg0, void **, 0);
                temp_v0_5 = M2C_FIELD(temp_a2_2, void **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2_2 + M2C_FIELD(temp_v0_5, s16 *, 0x2C0), 0, temp_a2_2);
            } else {
                CarryThrow_SetState(arg0, 0);
            }
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
            if ((temp_a0_2 == g_2dd5bc) && (M2C_FIELD(temp_a0_2, s32 *, 0x13D0) == 8)) {
                sp40 = 0x43C80000;
                sp0 = 0x43C80000;
                PosLoWorld(temp_a0_2);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x60($sp) */);
                PosLoWorld(M2C_FIELD(arg0, void **, 0));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x60($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf4, $vf1 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf4, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf4, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                } else {
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf3, $q */);
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf4x */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                func_00136530(g_2dd5bc, 1);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
                temp_v0_6 = M2C_FIELD(g_2dd5bc, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, M2C_UNK, void *), 0x11C)(g_2dd5bc + M2C_FIELD(temp_v0_6, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), g_2dd5bc);
            }
            temp_a2_3 = M2C_FIELD(arg0, void **, 0x12C);
            if (temp_a2_3 != NULL) {
                temp_v0_7 = M2C_FIELD(temp_a2_3, void **, 0xC);
                M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *), 0x4C)(temp_a2_3 + M2C_FIELD(temp_v0_7, s16 *, 0x48));
            }
        } else {
            if (temp_s0 != NULL) {
                temp_ret = FAsegaGone(temp_s0);
                if (temp_ret != 0) {
                    goto block_53;
                }
                if ((u32) temp_ret == 4) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($s1) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                    temp_f20_2 = atan2f(sp4, sp0);
                    temp_f0_4 = RadNormalize__Ff(temp_f20_2 - RadYawSo(M2C_FIELD(arg0, void **, 0)));
                    temp_f0_5 = M2C_FIELD(arg0, f32 *, 0x18);
                    if (temp_f0_5 < temp_f0_4) {
                        CarryThrow_SetState(arg0, 6);
                    } else if (temp_f0_4 < -temp_f0_5) {
                        CarryThrow_SetState(arg0, 5);
                    }
                }
            } else {
                goto block_54;
            }
            goto block_68;
        }
        break;
    case 7:
        if ((temp_s0 == NULL) || (FAsegaGone(temp_s0, (u32) M2C_FIELD(arg0, s32 *, 4)) != 0)) {
            if (M2C_FIELD(arg0, s32 *, 0x58) == 0) {
                temp_a2_4 = M2C_FIELD(arg0, void **, 0);
                temp_v0_8 = M2C_FIELD(temp_a2_4, void **, 0xC);
                M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2_4 + M2C_FIELD(temp_v0_8, s16 *, 0x2C0), 0, temp_a2_4);
            } else {
                goto block_65;
            }
        }
        goto block_68;
    }
}
