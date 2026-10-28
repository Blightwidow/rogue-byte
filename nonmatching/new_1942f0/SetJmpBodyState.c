#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(); /* extern */
M2C_UNK Carry_SetState();    /* extern */
s128 ConvertXfPos();                  /* extern */
M2C_UNK ConvertXfVec();           /* extern */
M2C_UNK DtSolveJumpLaunch(); /* extern */
s32 FIsBasicDerivedFrom();              /* extern */
M2C_UNK GetJmpLaunchVelocity();      /* extern */
M2C_UNK GetNormalVectors__FP6VECTORN30(); /* extern */
M2C_UNK PosLoWorld();                         /* extern */
M2C_UNK ReblendAsegbl();                      /* extern */
M2C_UNK RecalcSwOxfFilterForObject(); /* extern */
M2C_UNK RetractSmaRef();                      /* extern */
M2C_UNK SetHbskHbsks();              /* extern */
M2C_UNK SetJtJtcs();         /* extern */
M2C_UNK SetSmaGoal__FP3SMA3OID();       /* extern */
M2C_UNK SetSoNoXpsAll();             /* extern */
M2C_UNK SetStepGravityRatio__FP4STEPf(); /* extern */
M2C_UNK SetStepRadTarget();              /* extern */
M2C_UNK SetStepRadTargetDir();          /* extern */
M2C_UNK SetXfKind();         /* extern */
s32 func_0012DE58(); /* extern */
M2C_UNK func_0012E460();                      /* extern */
M2C_UNK func_00140C88();              /* extern */
M2C_UNK func_0019F3F8();         /* extern */
M2C_UNK func_00204F78();        /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_FLT_002BF780;
extern M2C_UNK D_FLT_002BF798;
extern f32 D_FLT_002BF7A0;
extern s128 g_2a2db0;
extern s128 g_2a2dc0;
extern s128 g_2a2dd0;
extern M2C_UNK g_2dded0;
extern s32 g_2e1e40;

void SetJmpBodyState(void *arg0, s32 arg1, void *arg2) {
    M2C_UNK sp70;
    M2C_UNK sp90;
    M2C_UNK spA0;
    M2C_UNK sp20;
    s128 sp50;
    s128 sp60;
    s128 sp80;
    M2C_UNK var_f20;
    M2C_UNK var_f21;
    M2C_UNK var_f23;
    M2C_UNK var_s3;
    f32 temp_f21;
    f32 var_f22;
    s32 temp_a0_11;
    s32 temp_a0_12;
    s32 temp_a0_4;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_10;
    s32 temp_v1_3;
    s32 temp_v1_7;
    void *temp_a0;
    void *temp_a0_10;
    void *temp_a0_13;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_5;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_a0_8;
    void *temp_a0_9;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_a1_5;
    void *temp_a2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_v0_10;
    void *temp_v0_11;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_2;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_8;
    void *temp_v1_9;
    void *var_s0;
    void *var_s1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1C);
    if (arg1 != temp_v0) {
        switch (temp_v0) {                          /* switch 1 */
        case 17:                                    /* switch 1 */
            func_00204F78(M2C_FIELD(arg0, void **, 0), M2C_FIELD(M2C_FIELD(arg0, void **, 0xC8), s32 *, 4), 0);
            M2C_FIELD(arg0, void **, 0xC8) = NULL;
            break;
        case 7:                                     /* switch 1 */
            temp_a1 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(arg0, void **, 0xC) = NULL;
            RecalcSwOxfFilterForObject(&B_003DD490, temp_a1);
            break;
        case 6:                                     /* switch 1 */
            temp_s0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(arg0, void **, 0xC) = NULL;
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x4C8) != 1) {
                RecalcSwOxfFilterForObject(&B_003DD490, temp_s0);
                if (M2C_FIELD(temp_s0, s32 *, 0x17C) == 1) {
                    SetHbskHbsks(temp_s0, 0);
                }
            }
            temp_a0 = M2C_FIELD(arg0, void **, 0);
            SetXfKind(temp_a0, M2C_FIELD(temp_a0, void **, 0x58), 2);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), s128 *, 0x190) = (s128) g_2a2dd0;
            break;
        case 8:                                     /* switch 1 */
        case 9:                                     /* switch 1 */
        case 10:                                    /* switch 1 */
        case 11:                                    /* switch 1 */
        case 12:                                    /* switch 1 */
        case 13:                                    /* switch 1 */
        case 14:                                    /* switch 1 */
        case 15:                                    /* switch 1 */
        case 16:                                    /* switch 1 */
        case 18:                                    /* switch 1 */
            temp_a0_2 = M2C_FIELD(arg0, void **, 0);
            SetXfKind(temp_a0_2, M2C_FIELD(temp_a0_2, void **, 0x58), 2);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), s128 *, 0x190) = (s128) g_2a2dd0;
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C);
            if ((temp_v1 < 0x10) && (temp_v1 >= 0xE)) {
                temp_a0_3 = M2C_FIELD(arg0, void **, 0);
                if (temp_a0_3 != g_2e1e40) {
                    Carry_SetState(temp_a0_3 + 0x900, -1);
                } else {
                    SetJtJtcs(temp_a0_3, -1);
                }
            }
            break;
        case 19:                                    /* switch 1 */
        case 20:                                    /* switch 1 */
            if ((arg1 >= 0x15) || (arg1 < 0x13)) {
                temp_a0_4 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1D28);
                if (temp_a0_4 != 0) {
                    SetSmaGoal__FP3SMA3OID(temp_a0_4, 0x5F8);
                }
                func_00140C88(M2C_FIELD(arg0, void **, 0), NULL);
            }
            break;
        case 21:                                    /* switch 1 */
            func_0012E460(arg0 + 0x1F0);
            temp_a0_5 = M2C_FIELD(arg0, void **, 0);
            SetXfKind(temp_a0_5, M2C_FIELD(temp_a0_5, void **, 0x58), 2);
            SetSoNoXpsAll(M2C_FIELD(arg0, void **, 0), 0);
            break;
        }
        var_s1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x1030);
        var_s0 = NULL;
        M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
        M2C_FIELD(arg0, void **, 0xC) = arg2;
        var_s3 = 1;
        var_f22 = 0.0f;
        var_f23 = 0x3F800000;
        M2C_FIELD(arg0, f32 *, 0x20) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0);
        switch (arg1) {                             /* switch 2 */
        case 17:                                    /* switch 2 */
            temp_a1_2 = M2C_FIELD(arg0, void **, 0);
            var_s3 = 9;
            temp_v0_2 = M2C_FIELD(temp_a1_2, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x2DC)(temp_a1_2 + M2C_FIELD(temp_v0_2, s16 *, 0x2D8), temp_a1_2);
            func_00204F78(M2C_FIELD(arg0, void **, 0), M2C_FIELD(M2C_FIELD(arg0, void **, 0xC8), s32 *, 4), 1);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($s2) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
            GetNormalVectors__FP6VECTORN30(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), g_2a2dc0, g_2a2db0, &sp20, ConvertXfPos(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC8), s32 *, 0), 0, M2C_FIELD(arg0, s128 *, 0xD0)));
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xf0($s2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf3z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xc0($sp) */);
            PosLoWorld(M2C_FIELD(arg0, void **, 0));
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc0($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1010($s0) */);
            temp_v1_2 = M2C_FIELD(arg0, void **, 0);
            temp_v0_3 = temp_v1_2 + 0x190;
            M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_3, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_2, s128 *, 0x190) = 0;
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
            var_s0 = M2C_FIELD(arg0, void **, 0x154);
            if (M2C_FIELD(arg0, s32 *, 0x174) != 0) {
                SetStepGravityRatio__FP4STEPf(M2C_FIELD(arg0, void **, 0), M2C_FIELD(arg0, f32 *, 0x168));
                func_00140C88(M2C_FIELD(arg0, void **, 0), NULL);
                M2C_FIELD(arg0, s32 *, 0x174) = 0;
            }
            break;
        case 0:                                     /* switch 2 */
        case 1:                                     /* switch 2 */
        case 4:                                     /* switch 2 */
        case 5:                                     /* switch 2 */
        case 7:                                     /* switch 2 */
            temp_v1_3 = M2C_FIELD(arg0, s32 *, 4);
            switch (temp_v1_3) {                    /* switch 3; irregular */
            case 13:                                /* switch 3 */
                var_s0 = M2C_FIELD(arg0, void **, 0x148);
                break;
            case 16:                                /* switch 3 */
                var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x1514);
                break;
            case 14:                                /* switch 3 */
                var_s0 = M2C_FIELD(arg0, void **, 0x158);
                break;
            case 15:                                /* switch 3 */
                var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x1518);
                break;
            }
            if (var_s0 == NULL) {
                var_s0 = M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 8) * 4)), void **, 0x120);
                if (var_s0 == NULL) {
                    var_s0 = M2C_FIELD(arg0, void **, 0x120);
                }
            }
            break;
        case 2:                                     /* switch 2 */
        case 3:                                     /* switch 2 */
            if (M2C_FIELD(arg0, s32 *, 4) == 0xE) {
                var_s0 = M2C_FIELD(arg0, void **, 0x15C);
            }
            if (var_s0 != NULL) {
                M2C_FIELD(arg0, s32 *, 0x28) = 0;
            } else {
                var_s0 = M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 8) * 4)), void **, 0x134);
                if (var_s0 != NULL) {
                    M2C_FIELD(arg0, s32 *, 0x28) = 0;
                } else {
                    var_s0 = M2C_FIELD(arg0, void **, 0x134);
                    if (var_s0 == NULL) {
                        var_s0 = M2C_FIELD(arg0, void **, 0x120);
                    }
                    M2C_FIELD(arg0, s32 *, 0x28) = 0;
                }
            }
            break;
        case 6:                                     /* switch 2 */
            temp_a0_6 = M2C_FIELD(arg0, void **, 0);
            SetXfKind(temp_a0_6, M2C_FIELD(temp_a0_6, void **, 0x58), 0x11);
            RecalcSwOxfFilterForObject(&B_003DD490, arg2);
            SetHbskHbsks(arg2, 1);
            temp_v1_4 = M2C_FIELD(arg0, void **, 0);
            temp_v0_4 = temp_v1_4 + 0x190;
            M2C_FIELD(temp_v0_4, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_4, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_4, s128 *, 0x190) = 0;
            var_s0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x1030), void **, 0x14);
            break;
        case 8:                                     /* switch 2 */
            temp_a0_7 = M2C_FIELD(arg0, void **, 0);
            SetXfKind(temp_a0_7, M2C_FIELD(temp_a0_7, void **, 0x58), 0x11);
            temp_v1_5 = M2C_FIELD(arg0, void **, 0);
            temp_v0_5 = temp_v1_5 + 0x190;
            M2C_FIELD(temp_v0_5, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_5, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_5, s128 *, 0x190) = 0;
            var_s0 = M2C_FIELD(var_s1, void **, 0x14);
            break;
        case 11:                                    /* switch 2 */
        case 12:                                    /* switch 2 */
        case 13:                                    /* switch 2 */
        case 14:                                    /* switch 2 */
        case 15:                                    /* switch 2 */
            temp_a0_8 = M2C_FIELD(arg0, void **, 0);
            SetXfKind(temp_a0_8, M2C_FIELD(temp_a0_8, void **, 0x58), 0x11);
            temp_v1_6 = M2C_FIELD(arg0, void **, 0);
            temp_v0_6 = temp_v1_6 + 0x190;
            M2C_FIELD(temp_v0_6, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_6, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_6, s128 *, 0x190) = 0;
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
            temp_v1_7 = M2C_FIELD(arg0, s32 *, 0x1C);
            M2C_FIELD(arg0, s32 *, 8) = 0;
            var_s0 = M2C_FIELD(arg0, void **, 0x120);
            if ((temp_v1_7 < 0x10) && (temp_v1_7 >= 0xE)) {
                temp_a2 = M2C_FIELD(arg0, void **, 0);
                temp_v0_7 = M2C_FIELD(arg0, void **, 0xC);
                if (temp_a2 == g_2e1e40) {
                    M2C_FIELD(temp_a2, void **, 0x1854) = temp_v0_7;
                    SetJtJtcs(temp_a2, 0, temp_a2);
                } else {
                    var_f23 = 0;
                    M2C_FIELD(temp_a2, void **, 0x984) = temp_v0_7;
                    Carry_SetState(M2C_FIELD(arg0, void **, 0) + 0x900, 0, temp_a2);
                    var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x930);
                    var_f22 = M2C_FIELD(var_s0, f32 *, 0x74) * 0.5f;
                }
            }
            break;
        case 9:                                     /* switch 2 */
        case 10:                                    /* switch 2 */
        case 16:                                    /* switch 2 */
        case 18:                                    /* switch 2 */
            temp_a0_9 = M2C_FIELD(arg0, void **, 0);
            SetXfKind(temp_a0_9, M2C_FIELD(temp_a0_9, void **, 0x58), 0x11);
            temp_v1_8 = M2C_FIELD(arg0, void **, 0);
            temp_v0_8 = temp_v1_8 + 0x190;
            M2C_FIELD(temp_v0_8, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_8, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_8, s128 *, 0x190) = 0;
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
            temp_s1 = M2C_FIELD(arg0, void **, 0);
            temp_s0_2 = M2C_FIELD(temp_s1, void **, 0xC);
            temp_s0_3 = temp_s0_2 + 0x118;
            temp_s1_2 = temp_s1 + M2C_FIELD(temp_s0_2, s16 *, 0x118);
            GetJmpLaunchVelocity(arg0, 4);
            M2C_FIELD(temp_s0_3, M2C_UNK (**)(void *, M2C_UNK), 4)(temp_s1_2, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
            M2C_FIELD(arg0, s32 *, 8) = 0;
            if (M2C_FIELD(arg0, s32 *, 0x1C) == 0x10) {
                var_s0 = M2C_FIELD(arg0, void **, 0x14C);
            } else {
                var_s0 = M2C_FIELD(arg0, void **, 0x148);
            }
            var_s1 = NULL;
            break;
        case -1:                                    /* switch 2 */
            if (M2C_FIELD(arg0, s32 *, 0x174) != 0) {
                SetStepGravityRatio__FP4STEPf(M2C_FIELD(arg0, void **, 0), M2C_FIELD(arg0, f32 *, 0x168));
                func_00140C88(M2C_FIELD(arg0, void **, 0), NULL);
                M2C_FIELD(arg0, s32 *, 0x174) = 0;
            }
            M2C_FIELD(arg0, s32 *, 0xBC) = 0;
            M2C_FIELD(arg0, s32 *, 4) = -1;
            break;
        case 19:                                    /* switch 2 */
            temp_a0_10 = M2C_FIELD(arg0, void **, 0);
            SetStepRadTarget(temp_a0_10, M2C_FIELD(temp_a0_10, f32 *, 0x1A8) - *((M2C_FIELD(arg0, s32 *, 8) * 4) + &D_FLT_002BF780));
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
            var_s0 = M2C_FIELD(arg0, void **, 0x178);
            func_00140C88(M2C_FIELD(arg0, void **, 0), M2C_FIELD(arg0, void **, 0x1BC));
            M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1BC), void **, 0x114), f32 *, 4) = (f32) ((M2C_FIELD(&D_FLT_002BF798, f32 *, 0) * 0.5f) + (M2C_FIELD(&D_FLT_002BF798, f32 *, 4) * 0.5f));
            temp_a0_11 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1D28);
            if (temp_a0_11 != 0) {
                SetSmaGoal__FP3SMA3OID(temp_a0_11, 0x5F7);
            }
            break;
        case 20:                                    /* switch 2 */
            var_s3 = 9;
            M2C_FIELD(arg0, s32 *, 0x188) = 0;
            M2C_FIELD(arg0, s32 *, 0x194) = 0;
            M2C_FIELD(arg0, s32 *, 0x1A0) = 0;
            M2C_FIELD(arg0, s32 *, 0x1AC) = 0;
            M2C_FIELD(arg0, f32 *, 0x17C) = 1.0f;
            ReblendAsegbl(M2C_FIELD(arg0, void **, 0x1B8));
            var_s0 = M2C_FIELD(arg0, void **, 0x1B8);
            break;
        case 21:                                    /* switch 2 */
            temp_a0_12 = M2C_FIELD(arg0, s32 *, 0x1D0);
            var_f21 = 0xC47A0000;
            var_f20 = 0xBF800000;
            sp50 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), s128 *, 0x70);
            if ((temp_a0_12 != 0) && ((FIsBasicDerivedFrom(temp_a0_12, 0x13) != 0) || (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x1D0), 0xB) != 0))) {
                var_f21 = 0;
                var_f20 = 0x43FA0000;
            }
            func_0019F3F8(M2C_FIELD(arg0, void **, 0), arg0 + 0x1D0, D_FLT_002BF7A0);
            sp60 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
            sp80 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xE8), s128 *, 0x80);
            DtSolveJumpLaunch(sp70, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), 0x447A0000, var_f21, 0x3F800000, var_f20);
            temp_a1_3 = M2C_FIELD(arg0, void **, 0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
            temp_v0_9 = M2C_FIELD(temp_a1_3, void **, 0xC);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf2, $q */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf4, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
            M2C_FIELD(temp_v0_9, M2C_UNK (**)(void *, s128), 0x11C)(temp_a1_3 + M2C_FIELD(temp_v0_9, s16 *, 0x118), sp90);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xa0($sp) */);
            temp_f21 = M2C_FIELD(&g_2dded0, f32 *, -0x2130) + M2C_ERROR(/* unknown instruction: max.s $f20, $f20, $f0 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            ConvertXfPos(0, M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), s32 *, 0xA0), sp60);
            M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
            ConvertXfVec(0, M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x58), s32 *, 0xA0), spA0);
            temp_a0_13 = M2C_FIELD(arg0, void **, 0);
            M2C_ERROR(/* unknown instruction: por $t0, $zero, $v0 */);
            M2C_FIELD(arg0, s32 *, 0x1F0) = func_0012DE58(temp_a0_13, M2C_FIELD(temp_a0_13, void **, 0x58), 5, M2C_ERROR(/* unknown instruction: por $a3, $zero, $s0 */), temp_f21);
            SetSoNoXpsAll(M2C_FIELD(arg0, void **, 0), 1);
            temp_v1_9 = M2C_FIELD(arg0, void **, 0);
            temp_v0_10 = temp_v1_9 + 0x190;
            M2C_FIELD(temp_v0_10, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_10, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_9, s128 *, 0x190) = 0;
            SetStepRadTargetDir(M2C_FIELD(arg0, void **, 0), sp70);
            var_s0 = M2C_FIELD(arg0, void **, 0x120);
            break;
        case 22:                                    /* switch 2 */
            var_s0 = M2C_FIELD(arg0, void **, 0x1C8);
            var_s3 = 9;
            break;
        }
        temp_v1_10 = M2C_FIELD(arg0, s32 *, 0x1C);
        switch (temp_v1_10) {                       /* switch 4; irregular */
        case 0:                                     /* switch 4 */
            M2C_FIELD(arg0, s32 *, 0x30) = 0;
            break;
        case 2:                                     /* switch 4 */
            M2C_FIELD(arg0, s32 *, 0x30) = 0;
            break;
        case 18:                                    /* switch 4 */
            RecalcSwOxfFilterForObject(&B_003DD490, M2C_FIELD(arg0, void **, 0));
            break;
        }
        if (M2C_FIELD(arg0, s32 *, 0x1C) != -1) {
            if ((var_s1 == NULL) || (M2C_FIELD(var_s1, s32 *, 0x14) != var_s0)) {
                RetractSmaRef(M2C_FIELD(arg0, void **, 0) + 0x1034);
                temp_a1_4 = M2C_FIELD(arg0, void **, 0);
                ApplyAsegToHandle(var_s0, temp_a1_4, var_s3, temp_a1_4 + 0x1030, var_f22, var_f23);
            }
            temp_a1_5 = M2C_FIELD(arg0, void **, 0);
            temp_v0_11 = M2C_FIELD(temp_a1_5, void **, 0xC);
            M2C_FIELD(temp_v0_11, M2C_UNK (**)(void *, void *), 0x2D4)(temp_a1_5 + M2C_FIELD(temp_v0_11, s16 *, 0x2D0), temp_a1_5);
        }
    }
}
