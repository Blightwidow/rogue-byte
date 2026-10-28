#include "m2c_macros.h"

M2C_UNK AddGuardPriorityClass();     /* extern */
s32 FCanSetGuardMode();                             /* extern */
M2C_UNK GoalBrain_ChooseNextCommand(); /* extern */
s32 PpoSwFocusBase();                      /* extern */
M2C_UNK RemoveGuardPriorityClass();  /* extern */
M2C_UNK SetAsegaMasterSpeed();           /* extern */
M2C_UNK func_0012D108();                   /* extern */
void *func_00205458();               /* extern */
M2C_UNK func_00206DB0();                      /* extern */
M2C_UNK func_00206E50();                      /* extern */
void *func_00209518();                           /* extern */
extern M2C_UNK B_003DD490;
extern s128 D_002C3D30;
extern s128 RO_002A2DE0;
extern f32 g_2dded0;

void SetGuardMode(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_9;
    s32 var_v0;
    u32 var_v1;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;

    if (arg1 != M2C_FIELD(arg0, s32 *, 0xFBC)) {
        if (FCanSetGuardMode() != 0) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0xFBC);
            M2C_FIELD(arg0, s32 *, 0xFBC) = arg1;
            M2C_FIELD(arg0, f32 *, 0xFC0) = (f32) g_2dded0;
            switch (temp_v0) {                      /* switch 1 */
            case 8:                                 /* switch 1 */
            case 13:                                /* switch 1 */
                temp_a0 = M2C_FIELD(arg0, s32 *, 0xFC4);
                if (temp_a0 != 0) {
                    func_0012D108(temp_a0, RO_002A2DE0);
                }
            default:                                /* switch 1 */
block_15:
                var_v1 = arg1 - 8;
block_16:
                var_v0 = var_v1 < 0x1EU;
                break;
            case 34:                                /* switch 1 */
            case 37:                                /* switch 1 */
                RemoveGuardPriorityClass(arg0, 0x38);
                func_00206E50(arg0);
                goto block_15;
            case 14:                                /* switch 1 */
                temp_v0_2 = func_00205458(arg0, 0x9D);
                var_v1 = arg1 - 8;
                if (temp_v0_2 != NULL) {
                    temp_v0_3 = func_00209518(M2C_FIELD(temp_v0_2, s32 *, 0x40));
                    var_v1 = arg1 - 8;
                    if (temp_v0_3 != NULL) {
                        SetAsegaMasterSpeed(temp_v0_3, M2C_FIELD(M2C_FIELD(temp_v0_3, void **, 0x14), f32 *, 0x78));
                        goto block_15;
                    }
                }
                goto block_16;
            case 21:                                /* switch 1 */
                temp_v0_4 = func_00205458(arg0, 0x9C);
                if (temp_v0_4 != NULL) {
                    var_v1 = arg1 - 8;
                    if ((M2C_FIELD(temp_v0_4, s32 *, 0x30) == 0x12) && (var_v1 = arg1 - 8, (M2C_FIELD(temp_v0_4, s32 *, 0x40) == PpoSwFocusBase(&B_003DD490)))) {
                        var_v0 = var_v1 < 0x1EU;
                        if (M2C_FIELD(temp_v0_4, f32 *, 0x44) == 3.4028235e38f) {
                            GoalBrain_ChooseNextCommand(temp_v0_4);
                            goto block_15;
                        }
                    } else {
                        goto block_16;
                    }
                } else {
                    goto block_15;
                }
                break;
            }
            if (var_v0 != 0) {
                switch (var_v1) {                   /* switch 2 */
                case 0:                             /* switch 2 */
                case 5:                             /* switch 2 */
                    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0xFC4);
                    if (temp_a0_2 != 0) {
                        func_0012D108(temp_a0_2, D_002C3D30);
                    }
                    break;
                case 26:                            /* switch 2 */
                case 29:                            /* switch 2 */
                    AddGuardPriorityClass(arg0, 0x38);
                    func_00206DB0(arg0);
                    break;
                case 6:                             /* switch 2 */
                    temp_v0_5 = func_00205458(arg0, 0x9D);
                    if (temp_v0_5 != NULL) {
                        temp_v0_6 = func_00209518(M2C_FIELD(temp_v0_5, s32 *, 0x40));
                        if (temp_v0_6 != NULL) {
                            SetAsegaMasterSpeed(temp_v0_6, 0.0f);
                        }
                    }
                    temp_v0_7 = arg0 + 0x190;
                    M2C_FIELD(temp_v0_7, s32 *, 4) = 0;
                    M2C_FIELD(temp_v0_7, s32 *, 8) = 0;
                    M2C_FIELD(arg0, s32 *, 0x190) = 0;
                    break;
                case 13:                            /* switch 2 */
                    temp_v0_8 = func_00205458(arg0, 0x9C);
                    if (temp_v0_8 != NULL) {
                        temp_v0_9 = M2C_FIELD(temp_v0_8, s32 *, 0x30);
                        switch (temp_v0_9) {        /* switch 3 */
                        case 1:                     /* switch 3 */
                        case 2:                     /* switch 3 */
                        case 3:                     /* switch 3 */
                        case 4:                     /* switch 3 */
                        case 12:                    /* switch 3 */
                        case 16:                    /* switch 3 */
                        case 17:                    /* switch 3 */
                        case 18:                    /* switch 3 */
                            GoalBrain_ChooseNextCommand(temp_v0_8, temp_v0_8);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
