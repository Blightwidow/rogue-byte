#include "m2c_macros.h"

M2C_UNK CarryThrow_Update(void *);                  /* extern */
M2C_UNK ClearVjoyPresses(void *, M2C_UNK);          /* extern */
s128 ConvertAloPos(M2C_UNK, void *, M2C_UNK);       /* extern */
s32 FAsegaGone(void *);                             /* extern */
M2C_UNK FAttachGroundTarget(void *, M2C_UNK, M2C_UNK); /* extern */
s32 FButtonPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(M2C_UNK, M2C_UNK, s128, M2C_UNK); /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FJtInFocusRange(void *, M2C_UNK);               /* extern */
s32 FSmaRetracted(s32);                             /* extern */
s32 GetJtPower(void *);                             /* extern */
M2C_UNK GetPathPosFromS(void *, void *, M2C_UNK, f32); /* extern */
s32 GrfbtnJtGadget(void *, M2C_UNK);                /* extern */
s32 GrfbtnVjoyPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK LoadRotateMatrixRad(s128 *, s128, f32, s128); /* extern */
M2C_UNK PmatLoWorld(void *);                        /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
f32 SMaxCrv(void *);                                /* extern */
M2C_UNK SeekAsega(void *, M2C_UNK, f32, f32);       /* extern */
M2C_UNK SetJmpState(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetJtState(void *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK StartBinoc(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
f32 TFindAsegLabel__FP4ASEG3OID(s32, M2C_UNK);      /* extern */
M2C_UNK UpdateAttachInput(void *);                  /* extern */
M2C_UNK UpdateJmpBodyState(void *);                 /* extern */
M2C_UNK UpdateJtActivePipe(void *);                 /* extern */
M2C_UNK UpdateZap(void *);                          /* extern */
M2C_UNK bevy_player_p25_1371c8(void *);             /* extern */
extern s128 D_002BF370;
extern f32 D_FLT_002BF354;
extern f32 D_FLT_002BF360;
extern f32 D_FLT_002BF364;
extern s128 g_2a2da0;
extern f32 g_2dded0;

void UpdateJtStateTransitions(void *arg0) {
    char sp[0x400];
    M2C_UNK sp60;
    M2C_UNK sp70;
    s128 sp50;
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f1;
    s128 var_v0_2;
    s32 temp_a0_4;
    s32 temp_s3;
    s32 temp_v1;
    s32 var_v0;
    u32 temp_v1_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_5;
    void *temp_a0_6;
    void *temp_a1;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_7;
    void *temp_v1_8;
    void *var_a0;
    void *var_a0_2;

loop_1:
    temp_s3 = M2C_FIELD(arg0, s32 *, 0x18D0);
    switch (M2C_FIELD(arg0, u32 *, 0x18C8)) {       /* switch 1 */
    case 7:                                         /* switch 1 */
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x4C8);
        switch (temp_v1) {                          /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            break;
        case 12:                                    /* switch 2 */
            break;
        }
block_13:
        temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x18C8);
        switch (temp_v1_2) {                        /* switch 3 */
        case 2:                                     /* switch 3 */
            UpdateJmpBodyState(arg0 + 0x2C0);
            var_a1 = 0x11;
            if (M2C_FIELD(arg0, s32 *, 0x1D30) != 0) {
                goto block_102;
            }
            temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
            if (M2C_FIELD(temp_v1_3, s32 (**)(void *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x318), 2) != 0) {
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x80, 0) != 0) {
                    var_a1 = 0xD;
                    goto block_102;
                }
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x10, 0) != 0) {
                    var_a1 = 0xE;
block_102:
                    SetJtState(arg0, var_a1, -1);
                }
            }
            break;
        case 7:                                     /* switch 3 */
            UpdateAttachInput(arg0 + 0x4C0);
            break;
        case 4:                                     /* switch 3 */
            UpdateZap(arg0 + 0xDF0);
            break;
        case 23:                                    /* switch 3 */
            CarryThrow_Update(arg0 + 0x11B0);
            break;
        case 6:                                     /* switch 3 */
            bevy_player_p25_1371c8(arg0 + 0x1FF0);
            break;
        case 8:                                     /* switch 3 */
            UpdateJtActivePipe(arg0 + 0xF50);
            break;
        case 0:                                     /* switch 3 */
        case 1:                                     /* switch 3 */
        case 10:                                    /* switch 3 */
        case 12:                                    /* switch 3 */
            if (M2C_FIELD(arg0, s32 *, 0x1D30) != 0) {
                var_a1 = 0x11;
                goto block_102;
            }
            if (((u32) (M2C_FIELD(arg0, s32 *, 0x18D8) - 8) >= 2U) || (M2C_FIELD(arg0, s32 *, 0x18E4) != 0)) {
                var_a0 = arg0 + 0x2C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3DCCCCCD) != 0) {
                    var_a1_2 = 1;
block_105:
                    SetJmpState(var_a0, var_a1_2, 0, 0);
                } else if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x30) & 8) || (FJtInFocusRange(arg0, 0) == 0)) {
                    if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x400, 0x3E19999A) == 0) || (temp_v1_4 = M2C_FIELD(arg0, void **, 0xC), (M2C_FIELD(temp_v1_4, s32 (**)(void *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x318), 3) == 0))) {
                        if (M2C_FIELD(arg0, s32 *, 0x10E4) == 3) {
                            if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x20, 0x3E19999A) != 0) {
                                var_a1 = 0xB;
                                goto block_102;
                            }
                            goto block_41;
                        }
block_41:
                        var_a0_2 = arg0 + 0x4C0;
                        if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x20, 0x3E4CCCCD) == 0) {
                            temp_v0 = M2C_FIELD(arg0, void **, 0x150);
                            temp_f1 = M2C_FIELD(temp_v0, f32 *, 0x1C);
                            if (M2C_FIELD(arg0, u32 *, 0x18C8) == 0) {
                                if (!(temp_f1 > 0.1f)) {
                                    goto block_100;
                                }
                                goto block_46;
                            }
                            if (temp_f1 > 0.0f) {
block_46:
                                if (M2C_FIELD(temp_v0, s32 *, 0x30) & 8) {
                                    var_a1 = 1;
                                } else {
                                    var_a1 = 0xC;
                                    if (M2C_FIELD(arg0, s32 *, 0x10E4) == 3) {
                                        var_a1 = 0xA;
                                    }
                                }
                            } else {
block_100:
block_101:
                                var_a1 = 0;
                            }
                            goto block_102;
                        }
block_71:
                        FAttachGroundTarget(var_a0_2, 0xFFFF, 0);
                    } else {
block_68:
                        ClearVjoyPresses(M2C_FIELD(arg0, void **, 0x150), 0x400);
                        StartBinoc(arg0 + 0xF00, 0, 0, 0);
                    }
                } else {
block_74:
                    SetJtState(arg0, 5, 4);
                }
            }
            break;
        case 24:                                    /* switch 3 */
            if (M2C_FIELD(arg0, s32 *, 0x1D30) != 0) {
                var_a1 = 0x11;
                goto block_102;
            }
            if (!((f32) GetJtPower(arg0) <= 0.0f)) {
                var_a0 = arg0 + 0x2C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3DCCCCCD) != 0) {
                    var_a1_2 = 1;
                    goto block_105;
                }
                if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x30) & GrfbtnJtGadget(arg0, 0x19)) {
                    if (M2C_FIELD(arg0, s32 *, 0x18D0) == 0xD) {
                        temp_v1_5 = M2C_FIELD(arg0, void **, 0xC);
                        M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_5, s16 *, 0x108));
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x80($sp) */);
                        PmatLoWorld(arg0);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($sp) */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                        var_v0 = 1;
                        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) < D_FLT_002BF354)) {
                            var_v0 = 0;
                        }
block_91:
                        if (var_v0 != 0) {
                            goto block_101;
                        }
                    }
                } else {
                    goto block_100;
                }
            } else {
                goto block_101;
            }
            break;
        case 5:                                     /* switch 3 */
            if (M2C_FIELD(arg0, s32 *, 0x1D30) != 0) {
                var_a1 = 0x11;
                goto block_102;
            }
            if ((u32) (M2C_FIELD(arg0, s32 *, 0x18D0) - 6) >= 4U) {
                if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x30) & 8) && (FJtInFocusRange(arg0, 1) != 0)) {
                    var_a0 = arg0 + 0x2C0;
                    if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3DCCCCCD) != 0) {
                        var_a1_2 = 1;
                        goto block_105;
                    }
                    if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x400, 0x3E19999A) != 0) {
                        temp_v1_6 = M2C_FIELD(arg0, void **, 0xC);
                        if (M2C_FIELD(temp_v1_6, s32 (**)(void *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1_6, s16 *, 0x318), 3) != 0) {
                            goto block_68;
                        }
                        goto block_70;
                    }
block_70:
                    var_a0_2 = arg0 + 0x4C0;
                    if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x20, 0x3E4CCCCD) != 0) {
                        goto block_71;
                    }
                    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C) > 0.0f) {
                        SetJtState(arg0, 5, 5);
                    } else {
                        goto block_74;
                    }
                } else {
                    goto block_101;
                }
            }
            break;
        case 3:                                     /* switch 3 */
            if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x18CC)) > 0.25f) {
                var_a0 = arg0 + 0x2C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3E800000) != 0) {
                    var_a1_2 = 2;
                    goto block_105;
                }
            }
            break;
        case 13:                                    /* switch 3 */
            var_a0 = arg0 + 0x2C0;
            if (FAsegaGone(M2C_FIELD(arg0, void **, 0x1030)) != 0) {
                var_a1_2 = 0xB;
                goto block_105;
            }
            temp_v0_2 = M2C_FIELD(arg0, void **, 0x208);
            if ((temp_v0_2 != NULL) && (M2C_FIELD(temp_v0_2, f32 *, 0x88) > 0.7f)) {
                var_f1 = 0.4f;
block_99:
                if (var_f1 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x18CC))) {
                    goto block_100;
                }
            }
            break;
        case 14:                                    /* switch 3 */
            if (FAsegaGone(M2C_FIELD(arg0, void **, 0x1030)) == 0) {
                temp_v0_3 = M2C_FIELD(arg0, void **, 0x208);
                if ((temp_v0_3 != NULL) && (M2C_FIELD(temp_v0_3, f32 *, 0x88) > 0.7f) && ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x18CC)) > 0.4f)) {
                    temp_f0 = TFindAsegLabel__FP4ASEG3OID(M2C_FIELD(arg0, s32 *, 0x1A84), 0x16D);
                    temp_a0 = M2C_FIELD(arg0, void **, 0x1030);
                    if (M2C_FIELD(temp_a0, f32 *, 0x1C) < temp_f0) {
                        SeekAsega(temp_a0, 0, temp_f0, M2C_FIELD(temp_a0, f32 *, 0x40));
                    }
                }
            } else {
                goto block_100;
            }
            break;
        case 16:                                    /* switch 3 */
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x1030);
            if (temp_a0_2 != NULL) {
                var_v0 = FAsegaGone(temp_a0_2);
                goto block_91;
            }
            goto block_100;
        case 19:                                    /* switch 3 */
            temp_a0_3 = M2C_FIELD(arg0, void **, 0x1030);
            if ((temp_a0_3 == NULL) || (FAsegaGone(temp_a0_3) == 0)) {
                temp_a0_4 = M2C_FIELD(arg0, s32 *, 0x1034);
                if (temp_a0_4 != 0) {
                    var_v0 = FSmaRetracted(temp_a0_4);
                    goto block_91;
                }
            } else {
                goto block_101;
            }
            break;
        case 17:                                    /* switch 3 */
            if (M2C_FIELD(arg0, s32 *, 0x1D30) != 0) {
                var_f1 = D_FLT_002BF360;
                goto block_99;
            }
            goto block_100;
        case 21:                                    /* switch 3 */
            var_a0 = arg0 + 0x2C0;
            if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3E800000) != 0) {
                var_a1_2 = 0x12;
                goto block_105;
            }
            break;
        case 22:                                    /* switch 3 */
            if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3E800000) != 0) {
                temp_a0_5 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C4), void **, 0x138);
                if (temp_a0_5 != NULL) {
                    temp_v0_4 = M2C_FIELD(arg0, void **, 0x18C4);
                    if (FIsBasicDerivedFrom(temp_a0_5, 0xA) != 0) {
                        temp_s0 = M2C_FIELD(temp_v0_4, void **, 0x138);
                        GetPathPosFromS(temp_s0, sp, 0, SMaxCrv(temp_s0) * (0.5f - (M2C_FIELD(arg0, f32 *, 0x1F94) * 0.5f)));
                    } else {
                        temp_a0_6 = M2C_FIELD(temp_v0_4, void **, 0x138);
                        if (temp_a0_6 != NULL) {
                            PosLoWorld(temp_a0_6);
                            var_v0_2 = ConvertAloPos(0, M2C_FIELD(arg0, void **, 0x18C4), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
                        } else {
                            goto block_112;
                        }
                        goto block_113;
                    }
                } else {
block_112:
                    var_v0_2 = D_002BF370;
block_113:
                    LoadRotateMatrixRad(&sp50, g_2a2da0, M2C_FIELD(arg0, f32 *, 0x1F94) * D_FLT_002BF364, var_v0_2);
                    temp_a1 = M2C_FIELD(arg0, void **, 0x18C4);
                    temp_v1_7 = M2C_FIELD(temp_a1, void **, 0xC);
                    M2C_FIELD(temp_v1_7, M2C_UNK (**)(void *, void *, s128, s128, s128), 0xFC)(temp_a1 + M2C_FIELD(temp_v1_7, s16 *, 0xF8), temp_a1, sp50, sp60, sp70);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf4z */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
                    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf4z */);
                    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf5, $vf0w */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                }
                PosLoWorld(arg0);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x240($s1) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
                FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */), M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), s128 *, 0x80), 0x3F000000);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                temp_v1_8 = M2C_FIELD(arg0, void **, 0xC);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf4, $vf1x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x90($sp) */);
                M2C_FIELD(temp_v1_8, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_8, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */));
                SetJmpState(arg0 + 0x2C0, 0xC, 0, 0);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf4, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf4, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x360($s1) */);
            }
            break;
        }
        break;
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
    case 5:                                         /* switch 1 */
    case 10:                                        /* switch 1 */
    case 11:                                        /* switch 1 */
    case 12:                                        /* switch 1 */
    case 23:                                        /* switch 1 */
    case 24:                                        /* switch 1 */
        if (((u32) (M2C_FIELD(arg0, s32 *, 0x18D8) - 8) >= 2U) || (M2C_FIELD(arg0, s32 *, 0x18E4) != 0)) {
            if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x20C)) > 0.1f) {
                SetJmpState(arg0 + 0x2C0, 0, 0, 0);
            }
        }
        goto block_13;
    }
    if (M2C_FIELD(arg0, u32 *, 0x18C8) != M2C_FIELD(arg0, u32 *, 0x18C8)) {
        goto loop_1;
    }
    if (M2C_FIELD(arg0, s32 *, 0x18D0) != temp_s3) {
        goto loop_1;
    }
}
