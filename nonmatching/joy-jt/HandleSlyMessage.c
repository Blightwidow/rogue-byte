#include "m2c_macros.h"

s32 FIsBasicDerivedFrom();              /* extern */
M2C_UNK GoalAnimLeap_SetState();        /* extern */
M2C_UNK HandleJtMessage();                          /* extern */
s32 PloFindSwObject_thunk(); /* extern */
M2C_UNK PosLoWorld();                         /* extern */
M2C_UNK SetJmpState(); /* extern */
M2C_UNK SetJtJtcs();                 /* extern */
M2C_UNK SetJtState();       /* extern */
M2C_UNK SpawnSwHitFx(); /* extern */
M2C_UNK func_00131B10();            /* extern */
M2C_UNK func_00131B60(); /* extern */
M2C_UNK func_001424E0();   /* extern */
M2C_UNK func_0018D698();     /* extern */
s32 func_001F1E20();                    /* extern */
s32 func_00205458();            /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BF2A0;
extern M2C_UNK D_002BF2B8;

void HandleSlyMessage(void *arg0, s32 arg1, void *arg2) {
    M2C_UNK *var_a3;
    s32 temp_a2_3;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_s2;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_v0_2;
    void *temp_v0_6;
    void *temp_v1_3;
    void *var_s0;

    HandleJtMessage();
    switch (arg1) {                                 /* switch 1; irregular */
    case 3:                                         /* switch 1 */
        if (arg2 != M2C_FIELD(arg0, s32 *, 0x18E0)) {
            if (arg2 == M2C_FIELD(arg0, s32 *, 0x1030)) {
                temp_v0 = M2C_FIELD(arg0, s32 *, 0x18C8);
                switch (temp_v0) {                  /* switch 2 */
                case 9:                             /* switch 2 */
                case 11:                            /* switch 2 */
                    SetJtState(arg0, 0, -1);
                    break;
                case 7:                             /* switch 2 */
                case 21:                            /* switch 2 */
                    M2C_FIELD(arg0, s32 *, 0x1038) = -1;
                    break;
                case 5:                             /* switch 2 */
                    temp_v1 = M2C_FIELD(arg0, s32 *, 0x18D0);
                    if (temp_v1 < 0xA) {
                        if (temp_v1 >= 8) {
                            SetJtState(arg0, 5, 4);
                        }
                    }
                    break;
                }
            }
        } else {
            if (M2C_FIELD(arg0, s32 *, 0x18D8) == 0xA) {
                SetJtJtcs(arg0, 2);
            } else {
                SetJtJtcs(arg0, -1);
            }
        default:                                    /* switch 3 */
        }
        return;
    case 9:                                         /* switch 1 */
        temp_v1_2 = M2C_FIELD(arg2, s32 *, 0);
        if ((temp_v1_2 == M2C_FIELD(arg0, s32 *, 0x1030)) || (temp_v1_2 == M2C_FIELD(arg0, s32 *, 0x18E0)) || ((temp_v0_2 = M2C_FIELD(arg0, void **, 0x1034), (temp_v0_2 != NULL)) && (temp_v1_2 == M2C_FIELD(temp_v0_2, s32 *, 0x30)))) {
            temp_a2 = M2C_FIELD(arg2, void **, 8) - 0x164;
            switch ((s32) temp_a2) {                /* switch 3 */
            case 10:                                /* switch 3 */
                func_00131B10(M2C_FIELD(arg0, s32 *, 0x18E0), arg0, M2C_FIELD(arg0, s32 *, 0x10B8));
                break;
            case 11:                                /* switch 3 */
                var_a3 = &D_002BF2A0;
block_30:
                func_00131B60(M2C_FIELD(arg0, s32 *, 0x18E0), arg0, 3, var_a3);
                break;
            case 12:                                /* switch 3 */
                var_a3 = &D_002BF2B8;
                goto block_30;
            case 0:                                 /* switch 3 */
                M2C_FIELD(arg0, s32 *, 0x18E4) = 1;
                break;
            case 2:                                 /* switch 3 */
                M2C_FIELD(arg0, s32 *, 0x18E8) = 1;
                break;
            case 1:                                 /* switch 3 */
                if (M2C_FIELD(arg0, s32 *, 0x18EC) != 0) {
                    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x18D8);
                    switch (temp_v0_3) {            /* switch 4 */
                    case 12:                        /* switch 4 */
                    case 14:                        /* switch 4 */
                    case 16:                        /* switch 4 */
                    case 18:                        /* switch 4 */
                    case 20:                        /* switch 4 */
                        SetJtState(arg0, 5, 6);
                        break;
                    case 13:                        /* switch 4 */
                    case 15:                        /* switch 4 */
                    case 17:                        /* switch 4 */
                    case 19:                        /* switch 4 */
                    case 21:                        /* switch 4 */
                        SetJtState(arg0, 5, 7);
                        break;
                    }
                }
                break;
            case 3:                                 /* switch 3 */
                if ((M2C_FIELD(arg0, s32 *, 0x10DC) != 0) && (M2C_FIELD(arg0, s32 *, 0x1BD4) != 0)) {
                    PosLoWorld(arg0);
                    temp_v0_4 = func_001F1E20(M2C_FIELD(arg0, s32 *, 0x10DC), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
                    if ((temp_v0_4 != 0) && (FIsBasicDerivedFrom(temp_v0_4, 0x5B) == 0) && (FIsBasicDerivedFrom(temp_v0_4, 0x5D) == 0)) {
                        temp_v0_5 = PloFindSwObject_thunk(&B_003DD490, 1, 0x282, arg0);
                        M2C_FIELD(arg0, s32 *, 0x1BCC) = temp_v0_4;
                        func_001424E0(arg0, temp_v0_5, temp_v0_4, -1);
                    }
                }
                break;
            case 15:                                /* switch 3 */
                temp_v1_3 = arg0 + 0x190;
                M2C_FIELD(arg0, s32 *, 0x1D2C) = 1;
                M2C_FIELD(temp_v1_3, s32 *, 4) = 0;
                M2C_FIELD(temp_v1_3, s32 *, 8) = 0;
                M2C_FIELD(arg0, s32 *, 0x190) = 0;
                temp_v0_6 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, s128, void *), 0x11C)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 0x118), (s128) M2C_FIELD(arg0, s32 *, 0x190), temp_a2);
                temp_v0_7 = func_00205458(M2C_FIELD(arg0, s32 *, 0x10DC), 0xB1);
                if (temp_v0_7 != 0) {
                    GoalAnimLeap_SetState(temp_v0_7, 4);
                }
                break;
            case 16:                                /* switch 3 */
                temp_v0_8 = func_00205458(M2C_FIELD(arg0, s32 *, 0x10DC), 0xB1, temp_a2);
                if (temp_v0_8 != 0) {
                    GoalAnimLeap_SetState(temp_v0_8, 6);
                }
                break;
            case 9:                                 /* switch 3 */
                PosLoWorld(arg0);
                SpawnSwHitFx(&B_003DD490, 0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), arg0);
                break;
            }
        }
        break;
    case 1:                                         /* switch 1 */
        temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x18C8);
        if (temp_v1_4 != 7) {
            if (temp_v1_4 < 8) {
                var_s0 = arg0 + 0x1FB0;
                if (temp_v1_4 != 3) {

                } else {
                    goto block_54;
                }
            } else {
                var_s0 = arg0 + 0x1FB0;
                if (temp_v1_4 == 0x16) {
block_54:
                    var_s0 = arg0 + 0x1FB0;
                    if (M2C_FIELD(arg0, s32 *, 0x18C4) == arg2) {
                        SetJmpState(arg0 + 0x2C0, 0, 0, 0);
                        goto block_60;
                    }
                }
            }
            goto block_61;
        }
        temp_v1_5 = M2C_FIELD(arg0, s32 *, 0x4C8);
        if (temp_v1_5 < 5) {
            var_s0 = arg0 + 0x1FB0;
            if (temp_v1_5 >= 3) {
                var_s2 = 3;
                if (M2C_FIELD(arg0, s32 *, 0x4D4) == arg2) {
                    SetJmpState(arg0 + 0x2C0, 0, 0, 0);
                    goto block_60;
                }
            } else {
                goto block_61;
            }
        } else {
block_60:
            var_s0 = arg0 + 0x1FB0;
block_61:
            var_s2 = 3;
        }
        do {
            if (M2C_FIELD(var_s0, s32 *, 8) == arg2) {
                func_0018D698(arg0, var_s0, 0);
            }
            var_s2 -= 1;
            var_s0 += 0xC;
        } while (var_s2 >= 0);
        break;
    case 11:                                        /* switch 1 */
        if (M2C_FIELD(arg2, s32 *, 4) == arg0) {
            temp_a2_2 = M2C_FIELD(arg2, void **, 8);
            if (M2C_FIELD(temp_a2_2, s32 *, 0x44) & 2) {
                temp_a2_3 = M2C_FIELD(temp_a2_2, s32 *, 0xC);
                if (temp_a2_3 & 2) {
                    temp_v0_9 = M2C_FIELD(arg0, s32 *, 0x18D8);
                    switch (temp_v0_9) {            /* switch 5 */
                    case 4:                         /* switch 5 */
                    case 6:                         /* switch 5 */
                    case 12:                        /* switch 5 */
                    case 14:                        /* switch 5 */
                    case 16:                        /* switch 5 */
                    case 18:                        /* switch 5 */
                    case 20:                        /* switch 5 */
                        SetJtState(arg0, 0, -1);
                        SetJtJtcs(arg0, 8);
                        break;
                    case 5:                         /* switch 5 */
                    case 7:                         /* switch 5 */
                    case 13:                        /* switch 5 */
                    case 15:                        /* switch 5 */
                    case 17:                        /* switch 5 */
                    case 19:                        /* switch 5 */
                    case 21:                        /* switch 5 */
                        SetJtState(arg0, 0, -1);
                        SetJtJtcs(arg0, 9);
                        break;
                    }
                } else if (temp_a2_3 & 4) {
                    SetJtState(arg0, 0, -1);
                    SetJtJtcs(arg0, 8);
                }
            }
        }
        break;
    }
}
