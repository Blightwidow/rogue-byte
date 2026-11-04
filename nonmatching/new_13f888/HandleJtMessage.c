#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(); /* extern */
M2C_UNK CarryThrow_Launch();          /* extern */
M2C_UNK CarryThrow_SetState();       /* extern */
M2C_UNK Carry_Attach();                  /* extern */
s32 FGadgetObjActive();                          /* extern */
s32 FIsBasicDerivedFrom();              /* extern */
M2C_UNK GoalStack_HandleMessage(); /* extern */
M2C_UNK HandlePoMessage();       /* extern */
M2C_UNK HitFx_Remove();                       /* extern */
s32 PloLeaseCloneObject();              /* extern */
M2C_UNK PosLoWorld();                 /* extern */
M2C_UNK ReleaseGadgetObj();                      /* extern */
M2C_UNK RetractAsegaHandle();            /* extern */
M2C_UNK SetAsegaSpeed();        /* extern */
M2C_UNK SetSwGuardsFrozen();      /* extern */
M2C_UNK SetSwGuardsMode();        /* extern */
M2C_UNK SpendJtGadgetPower();            /* extern */
M2C_UNK UnsubscribeLoObject();        /* extern */
M2C_UNK ZapContinue();                   /* extern */
M2C_UNK func_001A58D0();       /* extern */
M2C_UNK func_001CCC88();                 /* extern */
M2C_UNK func_00204E38();         /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK B_003E148C;
extern f32 g_2bcc94;
extern void *g_2dd2fc;
extern f32 g_2dded0;
extern void *g_2e1e40;

void HandleJtMessage(void *arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    void **sp4;
    s32 sp8;
    void *spC;
    s128 sp10;
    M2C_UNK (*temp_a1_3)(void *, M2C_UNK, void *);
    M2C_UNK (*temp_a1_4)(void *, M2C_UNK, void *);
    M2C_UNK (*temp_a2)(void *, M2C_UNK, M2C_UNK);
    s32 temp_a0;
    s32 temp_a1_2;
    s32 temp_s0;
    u8 *temp_s0_2;
    s32 temp_v0_3;
    u8 *temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_s0;
    s32 var_s2;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1_4;
    void *temp_v1_5;
    void *var_a0;
    void *var_a3;

    switch (arg1) {                                 /* switch 1 */
    case 3:                                         /* switch 1 */
        if (arg2 != M2C_FIELD(arg0, s32 *, 0x1030)) {
            temp_v0 = M2C_FIELD(arg0, void **, 0x1034);
            var_a0 = arg0 + 0x26C;
            if (temp_v0 != NULL) {
                if (arg2 == M2C_FIELD(temp_v0, s32 *, 0x30)) {
                    goto block_5;
                }
            }
        } else {
block_5:
            M2C_FIELD(arg0, s32 *, 0x1038) = -1;
            if ((u32) (M2C_FIELD(arg0, s32 *, 0xDF4) - 8) < 5U) {
                ZapContinue(arg0 + 0xDF0, arg1);
                goto block_82;
            }
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x11B4);
            if (temp_v1 > 0) {
                if (temp_v1 >= 3) {
                    if (temp_v1 < 7) {
                        var_a0 = arg0 + 0x26C;
                        if (temp_v1 >= 5) {
                            CarryThrow_SetState(arg0 + 0x11B0, 4);
                            goto block_82;
                        }
                    } else {
                        goto block_82;
                    }
                } else {
                    CarryThrow_SetState(arg0 + 0x11B0, 0);
                    goto block_82;
                }
            } else {
            default:                                /* switch 1 */
block_82:
                var_a0 = arg0 + 0x26C;
            }
        }
        break;
    case 9:                                         /* switch 1 */
        temp_a1 = M2C_FIELD(arg2, void **, 0);
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(temp_a1, s32 *, 0x18) == arg0) {
            temp_v1_2 = M2C_FIELD(arg2, s32 *, 8);
            if (temp_v1_2 != 0x1C7) {
                if (temp_v1_2 < 0x1C8) {
                    switch (temp_v1_2) {            /* switch 2; irregular */
                    case 0x15E:                     /* switch 2 */
                        func_00204E38(arg0, temp_a1, M2C_FIELD(arg2, s32 *, 4));
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x1b0($s1) */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
                        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf4, $vf5x */);
                        temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s1) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v1) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v1) */);
                        temp_a2 = M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK), 0x11C);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf4y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf2, $vf4z */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
                        temp_a2(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf6 */), temp_a2);
                        goto block_82;
                    default:                        /* switch 2 */
                        var_a0 = arg0 + 0x26C;
                        if (temp_v1_2 != 0x162) {

                        } else {
                            M2C_FIELD(arg0, s32 *, 0x1044) = 0;
                            sp10 = M2C_FIELD(arg0, s128 *, 0x1060);
                            PosLoWorld(arg0, temp_a1);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x1070($s1) */);
                            M2C_FIELD(arg0, s32 *, 0x1078) = 0;
                            goto block_82;
                        }
                        break;
                    case 0x161:                     /* switch 2 */
                        M2C_FIELD(arg0, s32 *, 0x1044) = 1;
                        goto block_82;
                    }
                } else if (temp_v1_2 != 0x27B) {
                    if (temp_v1_2 < 0x27C) {
                        var_a0 = arg0 + 0x26C;
                        if (temp_v1_2 != 0x1C8) {

                        } else if (M2C_FIELD(arg0, s32 *, 0x4C8) == 0xC) {
                            func_001CCC88(arg0 + 0x900, M2C_FIELD(arg0, s32 *, 0x4D4));
                            goto block_82;
                        }
                    } else {
                        var_a0 = arg0 + 0x26C;
                        if (temp_v1_2 != 0x27C) {

                        } else if (M2C_FIELD(arg0, s32 *, 0x4C8) == 0xB) {
                            temp_a0 = M2C_FIELD(arg0, s32 *, 0x4D4);
                            if ((temp_a0 != 0) && (FIsBasicDerivedFrom(temp_a0, 0x64) != 0)) {
                                temp_s0 = M2C_FIELD(arg0, s32 *, 0x4D4);
                                if (FGadgetObjActive(temp_s0) != 0) {
                                    ReleaseGadgetObj(temp_s0);
                                }
                            }
                            temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x9BC);
                            if (M2C_FIELD(arg0, s32 *, 0x130C) != 0) {
                                if (M2C_FIELD(arg0, s32 *, 0x1314) == temp_a1_2) {
                                    RetractAsegaHandle(arg0 + 0x1310, temp_a1_2);
                                    M2C_FIELD(arg0, s32 *, 0x1314) = -1;
                                } else {
                                    SpendJtGadgetPower(arg0, temp_a1_2);
                                    ApplyAsegToHandle(M2C_FIELD(arg0, s32 *, 0x130C), arg0, 8, arg0 + 0x1310, 0, 0x3F800000);
                                    M2C_FIELD(arg0, s32 *, 0x1314) = (s32) M2C_FIELD(arg0, s32 *, 0x9BC);
                                }
                            } else if (temp_a1_2 != -1) {
                                SpendJtGadgetPower(arg0, temp_a1_2);
                                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x9BC);
                                switch (temp_v1_3) { /* switch 3; irregular */
                                case 14:            /* switch 3 */
                                    SetSwGuardsFrozen(&B_003DD490, 1);
                                    break;
                                case 21:            /* switch 3 */
                                    SetSwGuardsMode(&B_003DD490, 0x15);
                                    break;
                                case 23:            /* switch 3 */
                                    temp_v0_3 = PloLeaseCloneObject(M2C_FIELD(g_2e1e40, s32 *, 0x2010), 0);
                                    if (temp_v0_3 != 0) {
                                        func_001A58D0(temp_v0_3, 0, 3);
                                    }
                                    var_a3 = M2C_FIELD(&B_003E148C, void **, 0);
                                    spC = g_2dd2fc;
                                    sp4 = M2C_FIELD(&B_003E148C, void **, 0) + M2C_FIELD(&B_003E148C, s32 *, 8);
                                    sp8 = M2C_FIELD(&B_003E148C, s32 *, 8);
                                    g_2dd2fc = sp;
                                    if (var_a3 != NULL) {
                                        do {
                                            if ((M2C_FIELD(var_a3, s32 *, 0x54) == 4) && (M2C_FIELD(var_a3, s32 *, 0x44) == arg0)) {
                                                HitFx_Remove(var_a3);
                                            }
                                            temp_a0_2 = *sp4;
                                            var_a3 = temp_a0_2;
                                            sp4 = temp_a0_2 + sp8;
                                        } while (var_a3 != NULL);
                                    }
                                    g_2dd2fc = spC;
                                    M2C_FIELD(&B_003DD490, f32 *, 0x4758) = (f32) (g_2dded0 + g_2bcc94);
                                    break;
                                }
                            }
                            M2C_FIELD(arg0, s32 *, 0x130C) = 0;
                            M2C_FIELD(arg0, s32 *, 0x9BC) = -1;
                            goto block_82;
                        }
                    }
                } else {
                    var_a0 = arg0 + 0x26C;
                    if (M2C_FIELD(arg0, s32 *, 0x11B4) != -1) {
                        CarryThrow_Launch(arg0 + 0x11B0, temp_a1);
                        goto block_82;
                    }
                }
            } else {
                var_a0 = arg0 + 0x26C;
                if (M2C_FIELD(arg0, s32 *, 0x4C8) == 0xC) {
                    SetAsegaSpeed(M2C_FIELD(arg0, s32 *, 0x1030), temp_a1, 0x3F800000);
                    Carry_Attach(arg0 + 0x900, M2C_FIELD(arg0, s32 *, 0x4D4));
                    goto block_82;
                }
            }
        }
        break;
    case 4:                                         /* switch 1 */
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(arg2, s32 *, 4) == arg0) {
            var_s2 = 0;
            M2C_FIELD(arg0, void **, 0x108C) = (void *) M2C_FIELD(arg2, void **, 0);
            if (M2C_FIELD(arg0, s32 *, 0x1094) > 0) {
                do {
                    temp_s0_2 = var_s2 * 8;
                    var_s2 += 1;
                    temp_a2_2 = *(temp_s0_2 + M2C_FIELD(arg0, s32 *, 0x1090));
                    temp_v1_4 = M2C_FIELD(temp_a2_2, void **, 0xC);
                    temp_a1_3 = M2C_FIELD(temp_v1_4, M2C_UNK (**)(void *, M2C_UNK, void *), 0x44);
                    temp_a1_3(temp_a2_2 + M2C_FIELD(temp_v1_4, s16 *, 0x40), temp_a1_3, temp_a2_2);
                    M2C_FIELD((temp_s0_2 + M2C_FIELD(arg0, s32 *, 0x1090)), s32 *, 4) = 0;
                } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x1094));
                goto block_82;
            }
        }
        break;
    case 5:                                         /* switch 1 */
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(arg2, s32 *, 4) == arg0) {
            if (M2C_FIELD(arg2, void **, 0) == M2C_FIELD(arg0, void **, 0x108C)) {
                var_s0 = 0;
                M2C_FIELD(arg0, void **, 0x108C) = NULL;
                if (M2C_FIELD(arg0, s32 *, 0x1094) > 0) {
                    do {
                        temp_v0_4 = var_s0 * 8;
                        var_s0 += 1;
                        temp_a2_3 = *(temp_v0_4 + M2C_FIELD(arg0, s32 *, 0x1090));
                        temp_v1_5 = M2C_FIELD(temp_a2_3, void **, 0xC);
                        temp_a1_4 = M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *, M2C_UNK, void *), 0x4C);
                        temp_a1_4(temp_a2_3 + M2C_FIELD(temp_v1_5, s16 *, 0x48), temp_a1_4, temp_a2_3);
                    } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x1094));
                    goto block_82;
                }
            }
        }
        break;
    case 1:                                         /* switch 1 */
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(arg0, s32 *, 0x4C8) == 0xB) {
            if (M2C_FIELD(arg0, s32 *, 0x4D4) == arg2) {
                UnsubscribeLoObject(arg2, arg0);
                M2C_FIELD(arg0, s32 *, 0x4D4) = 0;
                goto block_82;
            }
        }
        break;
    case 11:                                        /* switch 1 */
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(arg2, s32 *, 4) == arg0) {
            RetractAsegaHandle(arg0 + 0x1310);
            M2C_FIELD(arg0, s32 *, 0x1314) = -1;
            goto block_82;
        }
        break;
    }
    GoalStack_HandleMessage(var_a0, arg1, arg2);
    HandlePoMessage(arg0, arg1, arg2);
}
