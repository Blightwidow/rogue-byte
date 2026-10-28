#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(s32, void *, M2C_UNK, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK CarryThrow_SetState(void *, M2C_UNK);       /* extern */
M2C_UNK ClearVjoyPresses(void *, M2C_UNK);          /* extern */
s128 ConvertXfPos(s32, s32, s128);                  /* extern */
s32 FAsegaGone(s32);                                /* extern */
s32 FButtonPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
s32 FCheckJtEdgeGrab__FP2JTP2SOP6VECTOR3XPKPvT2(void *, s32 *, M2C_UNK, s32); /* extern */
s32 FGadgetAcquired(M2C_UNK);                       /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FJtLandsWithin(void *, M2C_UNK);                /* extern */
s32 FJtStuck(void *, void *, f32);                  /* extern */
M2C_UNK GetJmpLaunchVelocity(void *, M2C_UNK);      /* extern */
s32 GetJtPower(void *);                             /* extern */
s32 GrfbtnJtGadget(void *, M2C_UNK);                /* extern */
s32 GrfbtnVjoyPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK JtbsChooseJtLanding(void *, void *);        /* extern */
s32 PmqFirstOxaContact(s32);                        /* extern */
s128 PosLoWorld(void *);                            /* extern */
s128 PosSmooth(s128, s128, M2C_UNK *, M2C_UNK, f32); /* extern */
void *PxpFindJtBestEdge__FP2JTPiP6VECTOR(void *, s32 *, s128 *); /* extern */
M2C_UNK SetActvalGoal(void *, M2C_UNK, s128);       /* extern */
M2C_UNK SetJmpBodyState(void *, M2C_UNK, void *);   /* extern */
M2C_UNK SetJmpState(void *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK SetStepRadTargetDir(void *, M2C_UNK);       /* extern */
M2C_UNK SpendJtGadgetPower(void *, M2C_UNK);        /* extern */
M2C_UNK StartAttach(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK StartBinoc(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK StartJmpDirectionAseg(void *);              /* extern */
f32 TFindAsegLabel__FP4ASEG3OID(s32, M2C_UNK);      /* extern */
M2C_UNK WarpJtToSafePoint(void *, M2C_UNK);         /* extern */
M2C_UNK bevy_player_19c828(void *);                 /* extern */
M2C_UNK bevy_player_p14_jts8_enter(void *);         /* extern */
M2C_UNK func_0019F3F8(void *, void *, M2C_UNK);     /* extern */
extern M2C_UNK D_002BF820;
extern f32 D_FLT_002BF818;
extern f32 D_FLT_002BF81C;
extern f32 D_FLT_002BF82C;
extern f32 D_FLT_002BF830;
extern s128 g_2a2dd0;
extern M2C_UNK g_2dded0;
extern void *g_2e1e40;
extern void *g_2f7900;

void UpdateJmpBodyState(void *arg0) {
    M2C_UNK saved_reg_s6;
    M2C_UNK sp18;
    M2C_UNK unksp24;
    s128 sp20;                                      /* compiler-managed */
    s32 sp40;
    M2C_UNK var_a1;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f0;
    s32 *temp_v1_5;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_s5;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_condition_bit;
    s32 var_s4;
    s32 var_s6;
    s32 var_v1;
    void *temp_a0;
    void *temp_a0_3;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_s3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_6;
    void *temp_v1_7;
    void *var_s0;

    var_s6 = saved_reg_s6;
    var_s4 = 0;
    temp_a1 = M2C_FIELD(arg0, void **, 0);
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, void *, s128), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1, PosLoWorld(M2C_FIELD(arg0, void **, 0)));
    temp_v0 = M2C_FIELD(arg0, void **, 0);
    temp_v1_2 = M2C_FIELD(temp_v0, void **, 0x208);
    temp_s3 = M2C_FIELD(temp_v0, void **, 0x150);
    if ((temp_v1_2 != NULL) && (M2C_FIELD(temp_v1_2, f32 *, 0x88) > 0.7f)) {
        var_s4 = 1;
    }
loop_3:
    temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
    temp_s5 = M2C_FIELD(arg0, s32 *, 0x1C);
    if ((temp_v0_2 != NULL) && !(((u64) M2C_FIELD(temp_v0_2, u64 *, 0x28) >> 0x3C) & 1)) {
        bevy_player_19c828(arg0);
    }
    temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x1C);
    if ((temp_v1_3 >= 0x17) || (temp_v1_3 < 9)) {
        if ((M2C_FIELD(arg0, s32 *, 0x28) != 0) && (GrfbtnVjoyPressedWithin(temp_s3, 0x40, 0) != 0) && (FJtLandsWithin(M2C_FIELD(arg0, void **, 0), 0x3D99999A) == 0)) {
            ClearVjoyPresses(temp_s3, 0x40);
            SetJmpState(arg0, 6, M2C_FIELD(arg0, s32 *, 8), 0);
        }
        if (GrfbtnVjoyPressedWithin(temp_s3, 0x20, 0) != 0) {
            temp_s0 = M2C_FIELD(arg0, s32 *, 0x1C);
            JtbsChooseJtLanding(arg0, NULL);
            if (M2C_FIELD(arg0, s32 *, 0x1C) != temp_s0) {
                ClearVjoyPresses(temp_s3, 0x20);
            }
        }
        if ((GrfbtnVjoyPressedWithin(temp_s3, 8, 0) != 0) && (M2C_FIELD(arg0, void **, 0) == g_2e1e40) && (FGadgetAcquired(0x1B) != 0) && (FJtLandsWithin(M2C_FIELD(arg0, void **, 0), 0x3E99999A) == 0)) {
            SpendJtGadgetPower(M2C_FIELD(arg0, void **, 0), 0x1B);
            ClearVjoyPresses(temp_s3, 8);
            temp_v0_3 = M2C_FIELD(g_2e1e40, void **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, void *), 0x324)(g_2e1e40 + M2C_FIELD(temp_v0_3, s16 *, 0x320), 0x1B, g_2e1e40);
        }
    }
    temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x1C);
    switch (temp_v1_4) {
    case 0:
        if (D_FLT_002BF818 < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x20))) {
            if (!(M2C_FIELD(temp_s3, s32 *, 0x30) & 0x40) && (M2C_FIELD(arg0, s32 *, 0x40) != 3)) {
                M2C_FIELD(arg0, s32 *, 0x24) = 1;
            }
            SetJmpBodyState(arg0, 1, M2C_FIELD(arg0, void **, 0xC));
        } else {
block_29:
            if ((M2C_FIELD(arg0, s32 *, 0x30) == 0) && (M2C_FIELD(temp_s3, f32 *, 0x1C) > 0.5f)) {
                StartJmpDirectionAseg(arg0);
            }
        }
    default:
        break;
    case 2:
        if (D_FLT_002BF81C < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x20))) {
            SetJmpBodyState(arg0, 3, M2C_FIELD(arg0, void **, 0xC));
        } else {
            goto block_29;
        }
        break;
    case 1:
    case 7:
        var_condition_bit = sp18 < 0.0f;
block_43:
        if (var_condition_bit) {
            SetJmpBodyState(arg0, 4, M2C_FIELD(arg0, void **, 0xC));
        }
        break;
    case 6:
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 0x17C) != 3) {
            var_f0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), f32 *, 0xA8);
block_40:
            if (var_f0 < M2C_FIELD(&g_2dded0, f32 *, 0)) {
                bevy_player_p14_jts8_enter(arg0);
            }
        } else {
block_103:
block_104:
            var_a1 = 4;
block_105:
            SetJmpBodyState(arg0, var_a1, NULL);
        }
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        var_f0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), f32 *, 0xA8);
        goto block_40;
    case 18:
        if (((M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), f32 *, 0xA8) - TFindAsegLabel__FP4ASEG3OID(M2C_FIELD(g_2f7900, s32 *, 0x1974), 0x1C7)) <= M2C_FIELD(&g_2dded0, f32 *, 0)) && (M2C_FIELD(g_2f7900, s32 *, 0x1914) != 3)) {
            CarryThrow_SetState(g_2f7900 + 0x1910, 3);
        } else {
            var_f0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), f32 *, 0xA8);
            goto block_40;
        }
        break;
    case 8:
        var_condition_bit = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), f32 *, 0xA8) < M2C_FIELD(&g_2dded0, f32 *, 0);
        goto block_43;
    case 5:
        if ((M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x20)) > 0.25f) {
            if (var_s4 == 0) {
                goto block_56;
            }
block_99:
            temp_a2 = M2C_FIELD(arg0, void **, 0);
            temp_v0_4 = M2C_FIELD(temp_a2, void **, 0xC);
            M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2 + M2C_FIELD(temp_v0_4, s16 *, 0x2C0), 0, temp_a2);
        } else {
block_56:
            temp_a0 = M2C_FIELD(arg0, void **, 0);
            if (FJtStuck(temp_a0, temp_a0 + 0x131C, M2C_FIELD(arg0, f32 *, 0x20)) != 0) {
                WarpJtToSafePoint(M2C_FIELD(arg0, void **, 0), 0);
            }
        }
        break;
    case 3:
    case 4:
        if (var_s4 != 0) {
            if (M2C_FIELD(arg0, s32 *, 4) == 0xE) {
                StartAttach(M2C_FIELD(arg0, void **, 0) + 0x4C0, 0xA, 0, 0);
            } else {
                goto block_99;
            }
        } else {
            temp_v0_5 = PxpFindJtBestEdge__FP2JTPiP6VECTOR(arg0, &sp40, &sp20);
            if (temp_v0_5 != NULL) {
                temp_v0_6 = temp_v0_5 + ((1 - sp40) << 6);
                temp_v1_5 = M2C_FIELD(temp_v0_6, s32 **, 0);
                M2C_FIELD(arg0, s32 **, 0xC8) = temp_v1_5;
                M2C_FIELD(arg0, s128 *, 0xD0) = ConvertXfPos(0, *temp_v1_5, M2C_FIELD(temp_v0_6, s128 *, 0x10));
                M2C_FIELD(arg0, s32 *, 0x100) = (s32) M2C_FIELD(temp_v0_5, s32 *, 0x9C);
                if (sp40 == 0) {
                    var_v1 = M2C_FIELD(temp_v0_5, s32 *, 0xA4);
                } else {
                    var_v1 = M2C_FIELD(temp_v0_5, s32 *, 0xA0);
                }
                M2C_FIELD(arg0, s32 *, 0x104) = var_v1;
                var_a1 = 0x11;
                M2C_FIELD(arg0, s128 *, 0xE0) = sp20;
                goto block_105;
            }
            goto block_56;
        }
        break;
    case 17:
        if (((M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x20)) > 0.25f) && (FButtonPressedWithin(temp_s3, 0x40, 0x3E800000) != 0)) {
            SetJmpState(arg0, 3, 0, 0);
        } else if (M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC8), void **, 4), s32 *, 0xEC) != 0) {
            temp_s0_2 = M2C_FIELD(arg0, void **, 0);
            M2C_FIELD(temp_s0_2, s128 *, 0x1010) = PosSmooth(M2C_FIELD(temp_s0_2, s128 *, 0x1010), g_2a2dd0, &D_002BF820, 0, M2C_FIELD(&g_2dded0, f32 *, 4));
            sp20 = ConvertXfPos(M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC8), s32 *, 0), 0, M2C_FIELD(arg0, s128 *, 0xD0));
            if (!((M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x20)) > 0.03f) || (FCheckJtEdgeGrab__FP2JTP2SOP6VECTOR3XPKPvT2(arg0, M2C_FIELD(arg0, s32 **, 0xC8), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), M2C_FIELD(arg0, s32 *, 0x100)) != 0)) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($s2) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
                SetStepRadTargetDir(M2C_FIELD(arg0, void **, 0), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
                if (GrfbtnVjoyPressedWithin(temp_s3, 0x400, 0x3E19999A) != 0) {
                    temp_a2_2 = M2C_FIELD(arg0, void **, 0);
                    temp_v1_6 = M2C_FIELD(temp_a2_2, void **, 0xC);
                    if (M2C_FIELD(temp_v1_6, s32 (**)(void *, M2C_UNK, void *), 0x31C)(temp_a2_2 + M2C_FIELD(temp_v1_6, s16 *, 0x318), 3, temp_a2_2) != 0) {
                        ClearVjoyPresses(temp_s3, 0x400);
                        StartBinoc(M2C_FIELD(arg0, void **, 0) + 0xF00, 0, 0, 0);
                    }
                }
            } else {
                goto block_104;
            }
        } else {
            goto block_103;
        }
        break;
    case 19:
    case 20:
        if (PmqFirstOxaContact(M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0xEC)) == 0) {
            if (M2C_FIELD(temp_s3, s32 *, 0x30) & (GrfbtnJtGadget(M2C_FIELD(arg0, void **, 0), 0x1B) | 8)) {
                if (M2C_FIELD(arg0, s32 *, 0x1C) == 0x13) {
                    temp_a0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1030);
                    if ((temp_a0_2 == 0) || (FAsegaGone(temp_a0_2) != 0)) {
                        var_a1 = 0x14;
                        goto block_105;
                    }
                }
            } else {
                goto block_103;
            }
        } else {
            goto block_104;
        }
        break;
    case 21:
        temp_f1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x1F0), f32 *, 0x1C);
        if (temp_f1 < M2C_FIELD(&g_2dded0, f32 *, 0)) {
            var_s0 = NULL;
            temp_a1_2 = M2C_FIELD(arg0, void **, 0);
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0), 0x35) != 0) {
                var_s0 = M2C_FIELD(arg0, void **, 0);
                var_s6 = M2C_FIELD(var_s0, s32 *, 0x18F0);
            }
            temp_v1_7 = M2C_FIELD(temp_a1_2, void **, 0xC);
            sp20 = M2C_FIELD(temp_v1_7, s128 (**)(void *, void *), 0x10C)(temp_a1_2 + M2C_FIELD(temp_v1_7, s16 *, 0x108), temp_a1_2);
            sp20 = 0.0f;
            unksp24 = 0.0f;
            temp_a2_3 = M2C_FIELD(arg0, void **, 0);
            temp_v0_7 = M2C_FIELD(temp_a2_3, void **, 0xC);
            M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *, s128, void *), 0x11C)(temp_a2_3 + M2C_FIELD(temp_v0_7, s16 *, 0x118), (s128) sp20, temp_a2_3);
            SetJmpState(arg0, 0xB, 0, 0);
            if (var_s0 != NULL) {
                M2C_FIELD(var_s0, s32 *, 0x18F0) = var_s6;
            }
        } else if ((M2C_FIELD(arg0, s32 *, 0x1D4) != 0) && (temp_f1 < (M2C_FIELD(&g_2dded0, f32 *, 0) + 0.25f)) && ((FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1D0), 0x13) != 0) || (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1D0), 0xB) != 0) || (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1D0), 0xD) != 0) || (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1D0), 0x27) != 0) || (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1D0), 0xC) != 0) || (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1D0), 0x22) != 0) || (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1D0), 0x26) != 0))) {
            SetJmpState(arg0, 0xB, 0, 0);
            JtbsChooseJtLanding(arg0, M2C_FIELD(arg0, void **, 0x1D0));
        } else if ((M2C_FIELD(arg0, s32 *, 0x28) != 0) && (temp_a1_3 = M2C_FIELD(arg0, void **, 0), (M2C_FIELD(M2C_FIELD(temp_a1_3, void **, 0x58), f32 *, 0xB8) < 0.0f))) {
            ApplyAsegToHandle(M2C_FIELD(arg0, s32 *, 0x134), temp_a1_3, 1, temp_a1_3 + 0x1030, 0, 0x3F800000);
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
            temp_s1 = M2C_FIELD(arg0, void **, 0);
            temp_s0_3 = M2C_FIELD(temp_s1, void **, 0xC);
            temp_s0_4 = temp_s0_3 + 0x118;
            temp_s1_2 = temp_s1 + M2C_FIELD(temp_s0_3, s16 *, 0x118);
            GetJmpLaunchVelocity(arg0, 6);
            M2C_FIELD(temp_s0_4, M2C_UNK (**)(void *, M2C_UNK), 4)(temp_s1_2, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
        } else if ((M2C_FIELD(arg0, s32 *, 0x1D4) != 0) || (M2C_FIELD(arg0, s32 *, 0x1D8) != 0)) {
            func_0019F3F8(M2C_FIELD(arg0, void **, 0), arg0 + 0x1D0, M2C_ERROR(/* unknown instruction: min.s $f12, $f12, $f0 */));
            ConvertXfPos(0, M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), s32 *, 0xA0), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
            temp_a0_3 = M2C_FIELD(arg0, void **, 0x1F0);
            SetActvalGoal(temp_a0_3, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), M2C_FIELD(temp_a0_3, s128 *, 0x30));
        }
        break;
    case 22:
        if (GetJtPower(M2C_FIELD(arg0, void **, 0)) > 0) {
            temp_f2 = M2C_FIELD(arg0, f32 *, 0x20);
            if (D_FLT_002BF82C < (M2C_FIELD(&g_2dded0, f32 *, 0) - temp_f2)) {
                if (var_s4 != 0) {
                    goto block_99;
                }
                goto block_101;
            }
block_101:
            temp_f0 = M2C_FIELD(&g_2dded0, f32 *, 0);
            if ((D_FLT_002BF82C < (M2C_FIELD(&g_2dded0, f32 *, 0) - temp_f2)) && !(M2C_FIELD(temp_s3, s32 *, 0x30) & GrfbtnJtGadget(M2C_FIELD(arg0, void **, 0), 0xC))) {
                goto block_103;
            }
            if (D_FLT_002BF830 < (temp_f0 - M2C_FIELD(arg0, f32 *, 0x20))) {
                SetJmpBodyState(arg0, 4, NULL);
            }
        } else {
            goto block_103;
        }
        break;
    }
    if ((M2C_FIELD(arg0, s32 *, 0x1C) != temp_s5) && (M2C_FIELD(arg0, s32 *, 0x1C) != -1)) {
        goto loop_3;
    }
}
