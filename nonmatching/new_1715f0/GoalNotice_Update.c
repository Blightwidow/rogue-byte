#include "m2c_macros.h"

s32 FGoalAnimDone(s32);                             /* extern */
s32 FGoalReactDone(s32);                            /* extern */
M2C_UNK GoalNotice_SetState(void *, M2C_UNK);       /* extern */
s128 PosLoWorld(void *);                            /* extern */
s32 PpathzoneFindPos(s128, M2C_UNK);                /* extern */
M2C_UNK SetGoalTarget(s32, void *, s128);           /* extern */
s32 func_00175D00(void *);                          /* extern */
s32 func_00175FF0(void *);                          /* extern */
s32 func_00176060(void *);                          /* extern */
s32 func_0017B7F8(s32);                             /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(void *);                          /* extern */
s32 func_00209098(void *);                          /* extern */
M2C_UNK func_0020B140(void *, void *);              /* extern */
M2C_UNK func_002562A8(void *, s32);                 /* extern */
extern f32 B_FLT_003E1BE8;
extern f32 D_FLT_002BE614;
extern f32 g_2dded0;

void GoalNotice_Update(void *arg0) {
    char sp[0x400];
    s128 sp20;
    f32 var_f20;
    s32 temp_a1;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    u32 temp_s1;
    u32 temp_v1_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *var_v1;
    void *var_v1_2;

    func_001EEF98();
    do {
        temp_s1 = M2C_FIELD(arg0, u32 *, 0x34);
        switch (temp_s1) {                          /* switch 1 */
        case 0:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
            if (func_001EF0A8(arg0) == 0) {
                if (func_00209098(M2C_FIELD(arg0, void **, 0x10)) == 0) {
                    if (func_00176060(arg0) != 0) {
                        GoalNotice_SetState(arg0, 4);
                    } else if (func_00175FF0(arg0) != 0) {
                        GoalNotice_SetState(arg0, 1);
                    } else if (func_00175D00(arg0) != 0) {
                        GoalNotice_SetState(arg0, 2);
                    } else {
                        sp20 = PosLoWorld(M2C_FIELD(arg0, void **, 0x30));
                        PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                        temp_a0 = M2C_FIELD(arg0, void **, 0x10);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                        temp_v1 = M2C_FIELD(temp_a0, s32 *, 0xFBC);
                        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        var_f20 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */);
                        switch (temp_v1) {          /* switch 2; irregular */
                        case 13:                    /* switch 2 */
                            /* fallthrough */
                        case 8:                     /* switch 2 */
                            temp_v0 = M2C_FIELD(temp_a0, void **, 0xFC4);
                            if (temp_v0 != NULL) {
                                var_f20 /= M2C_FIELD(temp_v0, f32 *, 0x20);
                            }
                            break;
                        }
                        temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x34);
                        temp_a1 = PpathzoneFindPos(sp20, 1);
                        if (temp_v1_2 != 0) {
                            if (temp_v1_2 == 3) {
                                temp_v0_2 = M2C_FIELD(arg0, void **, 0x10);
                                if (var_f20 < M2C_FIELD(temp_v0_2, f32 *, 0x314)) {
                                    temp_v0_3 = M2C_FIELD(temp_v0_2, void **, 0xE8);
                                    var_v1 = NULL;
                                    if (temp_v0_3 != NULL) {
                                        var_v1 = M2C_FIELD(temp_v0_3, void **, 0xDC);
                                    }
                                    var_v0 = 0;
                                    if (var_v1 != NULL) {
                                        var_v0 = M2C_FIELD(var_v1, s32 *, 0x10);
                                    }
                                    if (temp_a1 != var_v0) {
                                        goto block_25;
                                    }
block_45:
                                    GoalNotice_SetState(arg0, 0);
                                } else {
block_25:
                                    if (M2C_FIELD(arg0, s32 *, 0x44) == temp_a1) {
                                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($s0) */);
                                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
                                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                                        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                                        var_v0_2 = 1;
                                        M2C_ERROR(/* unknown instruction: vwaitq */);
                                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                                        if (!(D_FLT_002BE614 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                                            var_v0_2 = 0;
                                        }
                                        if (var_v0_2 != 0) {
                                            goto block_29;
                                        }
                                    } else {
block_29:
                                        M2C_FIELD(arg0, s32 *, 0x44) = temp_a1;
                                        M2C_FIELD(arg0, s128 *, 0x50) = sp20;
                                        func_002562A8(sp, temp_a1);
                                        SetGoalTarget(M2C_FIELD(arg0, s32 *, 0x18), sp, sp20);
                                    }
                                }
                            }
                        } else {
                            temp_v0_4 = M2C_FIELD(arg0, void **, 0x10);
                            if (!(M2C_FIELD(temp_v0_4, f32 *, 0x318) < var_f20)) {
                                temp_v0_5 = M2C_FIELD(temp_v0_4, void **, 0xE8);
                                var_v1_2 = NULL;
                                if (temp_v0_5 != NULL) {
                                    var_v1_2 = M2C_FIELD(temp_v0_5, void **, 0xDC);
                                }
                                var_v0_3 = 0;
                                if (var_v1_2 != NULL) {
                                    var_v0_3 = M2C_FIELD(var_v1_2, s32 *, 0x10);
                                }
                                if (temp_a1 != var_v0_3) {
                                    goto block_36;
                                }
                            } else {
block_36:
                                GoalNotice_SetState(arg0, 3);
                            }
                        }
                    }
                } else {
block_41:
                    GoalNotice_SetState(arg0, 5);
                }
            }
            break;
        case 1:                                     /* switch 1 */
            if (func_00209098(M2C_FIELD(arg0, void **, 0x10)) == 0) {
                if (func_001EF0A8(arg0) == 0) {
                    var_v0_4 = FGoalReactDone(M2C_FIELD(arg0, s32 *, 0x18));
block_44:
                    if (var_v0_4 != 0) {
                        goto block_45;
                    }
                }
            } else {
                goto block_41;
            }
            break;
        case 2:                                     /* switch 1 */
            if (func_00209098(M2C_FIELD(arg0, void **, 0x10)) != 0) {
                goto block_41;
            }
            if (func_001EF0A8(arg0) == 0) {
                var_v0_4 = func_0017B7F8(M2C_FIELD(arg0, s32 *, 0x18));
                goto block_44;
            }
            break;
        case 4:                                     /* switch 1 */
            if ((func_001EF0A8(arg0) == 0) && (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0)) {
                GoalNotice_SetState(arg0, -1);
            }
            break;
        case 5:                                     /* switch 1 */
            if ((func_001EF0A8(arg0) == 0) && (func_00209098(M2C_FIELD(arg0, void **, 0x10)) == 0)) {
                GoalNotice_SetState(arg0, 3);
            }
            break;
        }
    } while (temp_s1 != M2C_FIELD(arg0, u32 *, 0x34));
    temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
    if ((M2C_FIELD(temp_a0_2, s32 *, 0xF40) != 0) && ((s32) temp_s1 < 4) && ((s32) temp_s1 >= 0) && (M2C_FIELD(temp_a0_2, f32 *, 0xF44) <= g_2dded0) && (B_FLT_003E1BE8 <= g_2dded0)) {
        func_0020B140(temp_a0_2, M2C_FIELD(arg0, void **, 0x30));
    }
}
