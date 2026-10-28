#include "m2c_macros.h"

s32 FGoalAnimDone();              /* extern */
s32 FGoalNoticeDone();                        /* extern */
s32 FGuardScriptDone();           /* extern */
s32 FIsBasicDerivedFrom();           /* extern */
M2C_UNK GoalBrain_AbsorbDamage(); /* extern */
M2C_UNK GoalBrain_ChooseNextCommand();        /* extern */
s32 GoalBrain_FCmdEqual();            /* extern */
s32 GoalBrain_FGotoTargetInWorld();           /* extern */
M2C_UNK GoalBrain_SetCommand();        /* extern */
M2C_UNK HitFx_Remove();                          /* extern */
s32 PhitfxChooseForGuard();              /* extern */
M2C_UNK PosLoWorld();                         /* extern */
M2C_UNK SetSearchGoal();                 /* extern */
s32 SpawnSwHitFx(); /* extern */
s32 func_00172550();                          /* extern */
s32 func_00174898();                             /* extern */
s32 func_00177D20();              /* extern */
s32 func_0017A9C0();              /* extern */
s32 func_0017DE40();              /* extern */
s32 func_0017EAE8();              /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8();                          /* extern */
s32 func_00208B38();                     /* extern */
f32 func_00208BB0();                          /* extern */
M2C_UNK memset();            /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;

void GoalBrain_Update(void *arg0) {
    char sp[0x400];
    u32 sp70;
    s32 sp80;
    f32 sp84;
    s128 *temp_s3;
    s128 *var_a0;
    s128 *var_v0;
    s128 temp_a1;
    s128 temp_a2;
    s32 temp_s0;
    s32 temp_s0_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1_7;
    s32 var_v0_4;
    u32 temp_v1;
    u32 temp_v1_3;
    u32 var_v0_2;
    u32 var_v0_3;
    u32 var_v0_5;
    u32 var_v1;
    void *temp_a0;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_s0_2;
    void *temp_s0_4;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_v1_2;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;

    func_001EEF98();
loop_79:
    if (func_001EF0A8(arg0) == 0) {
        var_v0 = arg0 + 0x30;
        var_a0 = sp;
        temp_s3 = var_v0;
        do {
            temp_a2 = M2C_FIELD(var_v0, s128 *, 0x10);
            M2C_FIELD(var_a0, s128 *, 0) = M2C_FIELD(var_v0, s128 *, 0);
            M2C_FIELD(var_a0, s128 *, 0x10) = temp_a2;
            var_v0 += 0x20;
            var_a0 += 0x20;
        } while (var_v0 != (arg0 + 0x90));
        temp_v1 = M2C_FIELD(arg0, u32 *, 0x30);
        temp_a1 = *var_v0;
        *var_a0 = temp_a1;
        switch (temp_v1) {
        case 1:
        case 16:
        case 17:
            memset(&sp70, 0, 0x70);
            var_v0_2 = 0xC;
            if (func_00177D20(arg0) == 0) {
                temp_a1_2 = M2C_FIELD(arg0, void **, 0x10);
                temp_v1_2 = M2C_FIELD(temp_a1_2, void **, 0xC);
                temp_v0 = M2C_FIELD(temp_v1_2, s32 (**)(void *, void *), 0x2C4)(temp_a1_2 + M2C_FIELD(temp_v1_2, s16 *, 0x2C0), temp_a1_2);
                temp_a0 = M2C_FIELD(arg0, void **, 0x10);
                if (temp_v0 != 0) {
                    if (func_00208B38(temp_a0, temp_v0) != 0) {
                        sp70 = 0x12;
                        sp80 = temp_v0;
                        sp84 = func_00208BB0(M2C_FIELD(arg0, void **, 0x10));
                    } else {
                        var_v0_2 = 3;
                        sp80 = temp_v0;
                        goto block_17;
                    }
                } else {
                    temp_v0_2 = PhitfxChooseForGuard(temp_a0, 0);
                    var_v0_2 = 2;
                    if (temp_v0_2 != 0) {
                        sp80 = temp_v0_2;
                        goto block_17;
                    }
                    temp_v1_3 = M2C_FIELD(arg0, u32 *, 0x30);
                    if ((temp_v1_3 == 0x11) && (g_2dded0 < M2C_FIELD(arg0, f32 *, 0xA4))) {
                        sp70 = temp_v1_3;
                    } else {
                        var_v0_2 = 0x10;
                        if (GoalBrain_FGotoTargetInWorld(arg0) == 0) {
                            var_v0_2 = 1;
                        }
                        goto block_17;
                    }
                }
            } else {
block_17:
                sp70 = var_v0_2;
            }
block_60:
            GoalBrain_SetCommand(arg0, &sp70);
        default:
            break;
        case 2:
            if (func_00177D20(arg0, temp_a1, temp_a2) != 0) {
                memset(&sp70, 0, 0x70);
                var_v1 = 0xC;
                goto block_59;
            }
            temp_a1_3 = M2C_FIELD(arg0, void **, 0x10);
            temp_v1_4 = M2C_FIELD(temp_a1_3, void **, 0xC);
            temp_v0_3 = M2C_FIELD(temp_v1_4, s32 (**)(void *, void *), 0x2C4)(temp_a1_3 + M2C_FIELD(temp_v1_4, s16 *, 0x2C0), temp_a1_3);
            if (temp_v0_3 != 0) {
                memset(&sp70, 0, 0x70);
                if (func_00208B38(M2C_FIELD(arg0, void **, 0x10), temp_v0_3) != 0) {
                    sp70 = 0x12;
                    sp80 = temp_v0_3;
                    sp84 = func_00208BB0(M2C_FIELD(arg0, void **, 0x10));
                } else {
                    sp80 = temp_v0_3;
                    sp70 = 3;
                }
                goto block_60;
            }
            temp_s1 = M2C_FIELD(arg0, void **, 0x18);
            temp_s0 = M2C_FIELD(temp_s1, s32 *, 0x44);
            temp_v0_4 = PhitfxChooseForGuard(M2C_FIELD(arg0, void **, 0x10), temp_s0);
            if (temp_v0_4 != temp_s0) {
                SetSearchGoal(temp_s1, temp_v0_4);
            } else if (func_00172550(temp_s1) != 0) {
block_58:
                memset(&sp70, 0, 0x70);
                var_v1 = 1;
block_59:
                sp70 = var_v1;
                goto block_60;
            }
            break;
        case 3:
            if (func_00177D20(arg0, temp_a1, temp_a2) != 0) {
                memset(&sp70, 0, 0x70);
                var_v1 = 0xC;
                goto block_59;
            }
            if (FGoalAnimDone(M2C_FIELD(arg0, void **, 0x18)) != 0) {
                memset(&sp70, 0, 0x70);
                var_v0_3 = 0xD;
                if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x10), 0x3B) != 0) {

                } else {
                    var_v0_3 = 4;
                }
                sp70 = var_v0_3;
                sp80 = M2C_FIELD(arg0, s32 *, 0x40);
                goto block_60;
            }
            break;
        case 5:
            var_v0_4 = FGuardScriptDone(M2C_FIELD(arg0, void **, 0x18), temp_a1, temp_a2);
block_73:
            if (var_v0_4 != 0) {
block_74:
                GoalBrain_ChooseNextCommand(arg0);
            }
            break;
        case 4:
            temp_s1_2 = M2C_FIELD(arg0, void **, 0x18);
            if (func_00177D20(arg0, temp_a1, temp_a2) != 0) {
                memset(&sp70, 0, 0x70);
                var_v1 = 0xC;
                goto block_59;
            }
            if (FGoalNoticeDone(temp_s1_2) == 0) {
                temp_a1_4 = M2C_FIELD(arg0, void **, 0x10);
                temp_v1_5 = M2C_FIELD(temp_a1_4, void **, 0xC);
                temp_v0_5 = M2C_FIELD(temp_v1_5, s32 (**)(void *, void *), 0x2C4)(temp_a1_4 + M2C_FIELD(temp_v1_5, s16 *, 0x2C0), temp_a1_4);
                if (temp_v0_5 != M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x38C)) {
                    memset(&sp70, 0, 0x70);
                    if (temp_v0_5 != 0) {
                        if (func_00208B38(M2C_FIELD(arg0, void **, 0x10), temp_v0_5) != 0) {
                            sp70 = 0x12;
                            sp80 = temp_v0_5;
                            sp84 = func_00208BB0(M2C_FIELD(arg0, void **, 0x10));
                        } else {
                            var_v0_5 = 3;
                            sp80 = temp_v0_5;
                            goto block_54;
                        }
                    } else {
                        sp70 = 1;
                        temp_s0_2 = M2C_FIELD(temp_s1_2, void **, 0x30);
                        if (temp_s0_2 != NULL) {
                            if (FIsBasicDerivedFrom(temp_s0_2, 0x34) == 0) {

                            } else {
                                temp_v1_6 = M2C_FIELD(temp_s0_2, void **, 0xC);
                                if (M2C_FIELD(temp_v1_6, s32 (**)(void *), 0x26C)(temp_s0_2 + M2C_FIELD(temp_v1_6, s16 *, 0x268)) == 2) {
                                    temp_v0_6 = func_00174898(M2C_FIELD(temp_s0_2, s32 *, 0xE20));
                                    if (temp_v0_6 != 0) {
                                        var_v0_5 = 0x11;
                                        if (temp_v0_6 != M2C_FIELD(arg0, void **, 0x10)) {
                                            sp80 = temp_v0_6;
block_54:
                                            sp70 = var_v0_5;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    goto block_60;
                }
            } else {
            case 0:
block_57:
                goto block_58;
            }
            break;
        case 12:
            if (func_00177D20(arg0, temp_a1, temp_a2) == 0) {
                goto block_57;
            }
            break;
        case 8:
            if (FGoalAnimDone(M2C_FIELD(arg0, void **, 0x18), temp_a1, temp_a2) != 0) {
                PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
                temp_s0_3 = SpawnSwHitFx(&B_003DD490, 0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), M2C_FIELD(arg0, void **, 0x10));
                memset(&sp70, 0, 0x70);
                sp70 = 2;
                sp80 = temp_s0_3;
                GoalBrain_SetCommand(arg0, &sp70);
                HitFx_Remove(temp_s0_3);
            }
            break;
        case 7:
            temp_s0_4 = M2C_FIELD(arg0, void **, 0x18);
            if (FGoalAnimDone(temp_s0_4, temp_a1, temp_a2) != 0) {
                temp_v1_7 = M2C_FIELD(temp_s0_4, s32 *, 0x50);
                if (temp_v1_7 != -1) {
                    if (temp_v1_7 == 3) {
                        goto block_74;
                    }
                } else {
                    GoalBrain_AbsorbDamage(arg0, -0x32, M2C_FIELD(temp_s0_4, s32 *, 0x5C));
                    if (M2C_FIELD(arg0, u32 *, 0x30) == 7) {
                        goto block_74;
                    }
                }
            }
            break;
        case 6:
            var_v0_4 = func_0017A9C0(M2C_FIELD(arg0, void **, 0x18), temp_a1, temp_a2);
            goto block_73;
        case 9:
            var_v0_4 = FGoalAnimDone(M2C_FIELD(arg0, void **, 0x18), temp_a1, temp_a2);
            goto block_73;
        case 10:
            var_v0_4 = FGoalAnimDone(M2C_FIELD(arg0, void **, 0x18), temp_a1, temp_a2);
            goto block_73;
        case 19:
            var_v0_4 = func_0017EAE8(M2C_FIELD(arg0, void **, 0x18), temp_a1, temp_a2);
            goto block_73;
        case 18:
            if (func_0017DE40(M2C_FIELD(arg0, void **, 0x18), temp_a1, temp_a2) != 0) {
                GoalBrain_ChooseNextCommand(arg0);
            }
            break;
        }
        if (GoalBrain_FCmdEqual(temp_s3, sp) == 0) {
            goto loop_79;
        }
    }
}
