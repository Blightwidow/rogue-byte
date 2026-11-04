#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(s32, void *, M2C_UNK, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK CarryThrow_SetState(void *, M2C_UNK);       /* extern */
M2C_UNK ChooseMurrayThrowTarget(void *);            /* extern */
M2C_UNK ExplodeExpl(void *);                        /* extern */
s32 FGadgetAcquired(M2C_UNK);                       /* extern */
s32 IsmsFindSmOptional__FP2SM3OID(s32, M2C_UNK);    /* extern */
f32 *PeaFindAsegLabel(s32, M2C_UNK);                /* extern */
M2C_UNK PosLoWorld(void *, s128);                   /* extern */
M2C_UNK ResetRunBlendFootsteps(void *);             /* extern */
M2C_UNK RetractAsegaHandle(void *);                 /* extern */
M2C_UNK RetractSmaRef(void *);                      /* extern */
M2C_UNK ScheduleJtGlance(void *);                   /* extern */
M2C_UNK SetAttachSubstate(void *, M2C_UNK);         /* extern */
M2C_UNK SetBinocState(void *, M2C_UNK);             /* extern */
M2C_UNK SetJmpBodyState(void *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK SetJtPipeState(void *, M2C_UNK);            /* extern */
M2C_UNK SetJtZapState(void *, M2C_UNK);             /* extern */
M2C_UNK SetMurrayAttackState(void *, M2C_UNK);      /* extern */
M2C_UNK SetMurrayCarryState(void *, M2C_UNK);       /* extern */
M2C_UNK SetMurrayLiftState(void *, M2C_UNK);        /* extern */
M2C_UNK SetSoCnstrForce(void *, M2C_UNK);           /* extern */
M2C_UNK SetStepRadTargetDir(void *, M2C_UNK);       /* extern */
M2C_UNK SetXfKind(void *, s32, M2C_UNK);            /* extern */
M2C_UNK func_00131A90(void *, f32);                 /* extern */
M2C_UNK func_00142868(void *, M2C_UNK);             /* extern */
M2C_UNK func_001430C8(void *);                      /* extern */
M2C_UNK func_001B5D30(void *, M2C_UNK);             /* extern */
M2C_UNK func_001B6DA8(void *, M2C_UNK);             /* extern */
M2C_UNK func_001B8D30(void *, M2C_UNK);             /* extern */
M2C_UNK func_001F14F8(s32, void *, M2C_UNK, M2C_UNK); /* extern */
extern s128 g_2a2dd0;
extern s32 g_2dd5bc;
extern f32 g_2dded0;

void SetMurrayState(void *arg0, u32 arg1) {
    M2C_UNK (*temp_a2)(void *, s128, M2C_UNK);
    M2C_UNK var_s4;
    M2C_UNK var_s4_2;
    M2C_UNK var_s6;
    f32 *temp_v0_5;
    f32 var_f21;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_s3;
    s32 var_s5;
    u32 temp_s0;
    u32 temp_v1;
    void *temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_4;
    void *var_a0;
    void *var_a0_2;
    void *var_s0;

    temp_v1 = M2C_FIELD(arg0, u32 *, 0x13D0);
    if (arg1 != temp_v1) {
        switch (temp_v1) {                          /* switch 1 */
        case 0:                                     /* switch 1 */
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 2);
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 2);
            ScheduleJtGlance(arg0);
            break;
        case 16:                                    /* switch 1 */
        case 17:                                    /* switch 1 */
        case 18:                                    /* switch 1 */
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 2);
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 2);
            break;
        case 3:                                     /* switch 1 */
            func_001B6DA8(arg0, -1);
            break;
        case 2:                                     /* switch 1 */
            var_a0 = arg0 + 0x2C0;
            if (M2C_FIELD(arg0, s32 *, 0x108C) == 0) {
                var_s0 = NULL;
                switch (arg1) {                     /* switch 2 */
                case 13:                            /* switch 2 */
                    temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x4C8);
                    if (temp_v1_2 != 1) {
                        if ((temp_v1_2 > 0) && (temp_v1_2 < 5) && (temp_v1_2 >= 3)) {
                            var_s0 = M2C_FIELD(arg0, void **, 0x1A54);
                        } else {
                        case 0:                     /* switch 2 */
                        case 1:                     /* switch 2 */
                        case 4:                     /* switch 2 */
                        case 5:                     /* switch 2 */
                        case 9:                     /* switch 2 */
                        case 11:                    /* switch 2 */
                        case 12:                    /* switch 2 */
                            var_s0 = M2C_FIELD(arg0, void **, 0x1A50);
                        }
                    }
                    break;
                }
                var_a0 = arg0 + 0x2C0;
                if (var_s0 != NULL) {
                    temp_v0 = M2C_FIELD(var_s0, void **, 0xC);
                    M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x44)(var_s0 + M2C_FIELD(temp_v0, s16 *, 0x40));
                    ExplodeExpl(var_s0);
                    temp_v0_2 = M2C_FIELD(var_s0, void **, 0xC);
                    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x4C)(var_s0 + M2C_FIELD(temp_v0_2, s16 *, 0x48));
                    var_a0 = arg0 + 0x2C0;
                }
            }
            SetJmpBodyState(var_a0, -1, 0);
            break;
        case 13:                                    /* switch 1 */
            SetAttachSubstate(arg0 + 0x4C0, -1);
            break;
        case 14:                                    /* switch 1 */
            SetJtZapState(arg0 + 0xDF0, -1);
            break;
        case 11:                                    /* switch 1 */
            SetMurrayAttackState(arg0, -1);
            break;
        case 12:                                    /* switch 1 */
            func_001B8D30(arg0, -1);
            break;
        case 4:                                     /* switch 1 */
            SetMurrayLiftState(arg0, -1);
            break;
        case 5:                                     /* switch 1 */
            SetMurrayCarryState(arg0, -1);
            break;
        case 9:                                     /* switch 1 */
            func_001B5D30(arg0, -1);
            break;
        case 15:                                    /* switch 1 */
            temp_a1 = M2C_FIELD(arg0, void **, 0x191C);
            temp_v0_3 = M2C_FIELD(temp_a1, void **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0_3, s16 *, 0x48), temp_a1);
            CarryThrow_SetState(arg0 + 0x1910, -1);
            SetSoCnstrForce(arg0, 0);
            break;
        case 1:                                     /* switch 1 */
        case 10:                                    /* switch 1 */
            temp_v0_4 = M2C_FIELD(arg0, void **, 0x1030);
            M2C_FIELD(arg0, f32 *, 0x1A0) = (f32) (M2C_FIELD(temp_v0_4, f32 *, 0x1C) / M2C_FIELD(M2C_FIELD(temp_v0_4, void **, 0x14), f32 *, 0x74));
            break;
        case 6:                                     /* switch 1 */
            M2C_FIELD(arg0, s32 *, 0x1530) = 0;
            break;
        case 20:                                    /* switch 1 */
            SetJtPipeState(arg0 + 0xF50, -1);
            break;
        }
        temp_s0 = M2C_FIELD(arg0, u32 *, 0x13D0);
        M2C_FIELD(arg0, u32 *, 0x13D0) = arg1;
        var_s3 = 0;
        var_s5 = 0;
        var_s6 = 1;
        var_s4 = -1;
        var_f21 = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x13D4) = (f32) g_2dded0;
        switch (arg1) {                             /* switch 3 */
        case 0:                                     /* switch 3 */
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 1);
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 1);
            var_s5 = M2C_FIELD(arg0, s32 *, 0x1028);
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
            if (temp_s0 != 2) {
                var_s4_2 = ((temp_s0 ^ 0xA) != 0) ? 0x175 : 0x176;
            } else {
                var_s4_2 = 0x178;
            }
            var_s4 = (IsmsFindSmOptional__FP2SM3OID(var_s5, var_s4_2) <= -1) ? -1 : var_s4_2;
            func_001430C8(arg0);
            func_00142868(arg0, 1);
        default:                                    /* switch 3 */
block_74:
            temp_s0_2 = arg0 + 0x1030;
            RetractAsegaHandle(temp_s0_2);
            RetractSmaRef(arg0 + 0x1034);
            ApplyAsegToHandle(var_s3, arg0, var_s6, temp_s0_2, 0, 0x3F800000);
            func_001F14F8(var_s5, arg0, var_s4, var_s6);
            if (var_s3 == 0) {
                if (var_s5 != 0) {
                    goto block_80;
                }
            } else {
                if (0.0f == 0.0f) {
                    temp_v0_5 = PeaFindAsegLabel(var_s3, 0x1AC);
                    if (temp_v0_5 != NULL) {
                        var_f21 = *temp_v0_5;
                    }
                }
block_80:
                if (var_f21 != 0.0f) {
                    temp_a0 = M2C_FIELD(arg0, void **, 0x1030);
                    func_00131A90(temp_a0, g_2dded0 + (var_f21 / M2C_FIELD(temp_a0, f32 *, 0x40)));
                }
            }
            temp_v0_6 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *), 0x2D4)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 0x2D0));
            break;
        case 1:                                     /* switch 3 */
            var_s3 = M2C_FIELD(arg0, s32 *, 0x1324);
            var_a0_2 = arg0 + 0x1320;
block_67:
            var_s6 = 9;
            ResetRunBlendFootsteps(var_a0_2);
            goto block_74;
        case 14:                                    /* switch 3 */
            SetBinocState(arg0 + 0xF00, -1);
            goto block_74;
        case 3:                                     /* switch 3 */
            func_001B6DA8(arg0, 0);
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x1AE8);
            if (temp_a0_2 == 0) {
                var_s3 = M2C_FIELD(arg0, s32 *, 0x13E0);
            } else {
                var_s3 = temp_a0_2;
                if (M2C_FIELD(arg0, s32 *, 0x13E8) == 0) {
                    var_s3 = M2C_FIELD(arg0, s32 *, 0x13E0);
                }
            }
            goto block_74;
        case 5:                                     /* switch 3 */
            SetMurrayCarryState(arg0, 0);
block_65:
            temp_v0_7 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *), 0x2D4)(arg0 + M2C_FIELD(temp_v0_7, s16 *, 0x2D0));
            return;
        case 6:                                     /* switch 3 */
            var_s5 = M2C_FIELD(arg0, s32 *, 0x1520);
            goto block_74;
        case 4:                                     /* switch 3 */
            temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x144C);
            switch (temp_v1_3) {                    /* switch 4; irregular */
            case 0:                                 /* switch 4 */
                var_s3 = M2C_FIELD(arg0, s32 *, 0x1440);
                break;
            case 1:                                 /* switch 4 */
                var_s3 = M2C_FIELD(arg0, s32 *, 0x1444);
                break;
            }
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
            SetMurrayLiftState(arg0, 0);
            goto block_74;
        case 7:                                     /* switch 3 */
            if (M2C_FIELD(arg0, s32 *, 0x1AE0) == 0) {
                var_s3 = M2C_FIELD(arg0, s32 *, 0x140C);
            } else if (FGadgetAcquired(0x11) == 0) {
                var_s3 = M2C_FIELD(arg0, s32 *, 0x140C);
            } else {
                var_s3 = M2C_FIELD(arg0, s32 *, 0x1AE0);
            }
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
            ChooseMurrayThrowTarget(arg0);
            PosLoWorld(arg0, M2C_FIELD(arg0, s128 *, 0x1420));
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            SetStepRadTargetDir(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
            goto block_74;
        case 8:                                     /* switch 3 */
            temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x1AE4);
            if (temp_a0_3 == 0) {
                var_s3 = M2C_FIELD(arg0, s32 *, 0x1438);
            } else {
                var_s3 = temp_a0_3;
                if (M2C_FIELD(arg0, s32 *, 0x143C) == 0) {
                    var_s3 = M2C_FIELD(arg0, s32 *, 0x1438);
                }
            }
block_71:
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
            goto block_74;
        case 9:                                     /* switch 3 */
            func_001B5D30(arg0, 0);
            goto block_65;
        case 10:                                    /* switch 3 */
            var_s3 = M2C_FIELD(arg0, s32 *, 0x1544);
            var_a0_2 = arg0 + 0x1540;
            goto block_67;
        case 15:                                    /* switch 3 */
            temp_a1_2 = M2C_FIELD(arg0, void **, 0x191C);
            temp_v0_8 = M2C_FIELD(temp_a1_2, void **, 0xC);
            M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, void *), 0x44)(temp_a1_2 + M2C_FIELD(temp_v0_8, s16 *, 0x40), temp_a1_2);
            M2C_FIELD(arg0, s32 *, 0x1920) = (s32) g_2dd5bc;
            CarryThrow_SetState(arg0 + 0x1910, 0);
            SetSoCnstrForce(arg0, 1);
            temp_v1_4 = M2C_FIELD(arg0, void **, 0xC);
            temp_a2 = M2C_FIELD(temp_v1_4, M2C_UNK (**)(void *, s128, M2C_UNK), 0x11C);
            temp_a2(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x118), g_2a2dd0, temp_a2);
            return;
        case 16:                                    /* switch 3 */
            var_s5 = M2C_FIELD(arg0, s32 *, 0x102C);
            /* fallthrough */
        case 17:                                    /* switch 3 */
        case 18:                                    /* switch 3 */
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 1);
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 1);
            goto block_71;
        case 20:                                    /* switch 3 */
            SetJtPipeState(arg0 + 0xF50, 0);
            return;
        case 21:                                    /* switch 3 */
            var_s3 = M2C_FIELD(arg0, s32 *, 0x1AEC);
            temp_v0_9 = arg0 + 0x190;
            M2C_FIELD(temp_v0_9, s32 *, 4) = 0;
            var_s6 = 9;
            M2C_FIELD(temp_v0_9, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0x190) = 0;
            goto block_74;
        }
    }
}
