#include "m2c_macros.h"

M2C_UNK CarryThrow_Update(void *);                  /* extern */
M2C_UNK ClearVjoyPresses(void *, M2C_UNK);          /* extern */
s32 FAsegaGone(s32);                                /* extern */
M2C_UNK FAttachGroundTarget(void *, M2C_UNK, M2C_UNK); /* extern */
s32 FButtonPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
s32 FJtInFocusRange(void *, M2C_UNK);               /* extern */
s32 FSmaRetracted(s32);                             /* extern */
s32 GrfbtnVjoyPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
s32 PslotBentleyGadget(void *, s32);                /* extern */
M2C_UNK SetBentleyState(void *, M2C_UNK);           /* extern */
M2C_UNK SetJmpState(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK StartBinoc(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK UpdateAttachInput(void *);                  /* extern */
M2C_UNK UpdateBentleyAim(void *);                   /* extern */
M2C_UNK UpdateBentleyGadget(void *);                /* extern */
M2C_UNK UpdateJmpBodyState(void *);                 /* extern */
M2C_UNK UpdateJtActivePipe(void *);                 /* extern */
M2C_UNK UpdateZap(void *);                          /* extern */
M2C_UNK func_001367D8(void *);                      /* extern */
extern f32 D_FLT_002BC930;
extern f32 g_2dded0;

void UpdateBentleyActive(void *arg0) {
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v1;
    u32 temp_s1;
    u32 temp_v1_2;
    void *temp_v0;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;
    void *var_a0;
    void *var_a0_2;

    do {
        temp_s1 = M2C_FIELD(arg0, u32 *, 0x13D0);
        switch (temp_s1) {                          /* switch 1 */
        case 2:                                     /* switch 1 */
        case 4:                                     /* switch 1 */
        case 6:                                     /* switch 1 */
        case 8:                                     /* switch 1 */
        case 9:                                     /* switch 1 */
        case 10:                                    /* switch 1 */
        case 11:                                    /* switch 1 */
        case 13:                                    /* switch 1 */
        case 14:                                    /* switch 1 */
            break;
        case 3:                                     /* switch 1 */
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x4C8);
            if ((temp_v1 != 1) && (temp_v1 != 0xC) && ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x20C)) > 0.1f)) {
                SetJmpState(arg0 + 0x2C0, 0, 0, 0);
            }
            break;
        default:                                    /* switch 1 */
        case 5:                                     /* switch 1 */
        case 7:                                     /* switch 1 */
        case 12:                                    /* switch 1 */
            if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x20C)) > 0.1f) {
                SetJmpState(arg0 + 0x2C0, 0, 0, 0);
            }
            break;
        }
        temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x13D0);
        switch (temp_v1_2) {                        /* switch 2 */
        case 0:                                     /* switch 2 */
        case 1:                                     /* switch 2 */
        case 7:                                     /* switch 2 */
            if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x30) & 8) && (FJtInFocusRange(arg0, 0) != 0)) {
                SetBentleyState(arg0, 5);
            } else {
                var_a0 = arg0 + 0x2C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3DCCCCCD) == 0) {
                    if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x400, 0x3E19999A) == 0) || (temp_v1_3 = M2C_FIELD(arg0, void **, 0xC), (M2C_FIELD(temp_v1_3, s32 (**)(void *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x318), 3) == 0))) {
                        if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x10, 0x3E19999A) == 0) || (temp_v1_4 = M2C_FIELD(arg0, void **, 0xC), (M2C_FIELD(temp_v1_4, s32 (**)(void *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x318), M2C_FIELD(arg0, s32 *, 0x1870)) == 0))) {
                            var_a0_2 = arg0 + 0x4C0;
                            if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x20, 0x3E4CCCCD) == 0) {
                                temp_v0 = M2C_FIELD(arg0, void **, 0x150);
                                temp_f1 = M2C_FIELD(temp_v0, f32 *, 0x1C);
                                if (M2C_FIELD(arg0, u32 *, 0x13D0) == 0) {
                                    if (!(temp_f1 > 0.1f)) {
                                        goto block_53;
                                    }
                                    goto block_24;
                                }
                                if (temp_f1 > 0.0f) {
block_24:
                                    if (M2C_FIELD(temp_v0, s32 *, 0x30) & 8) {
                                        SetBentleyState(arg0, 1);
                                    } else {
                                        SetBentleyState(arg0, 7);
                                    }
                                } else {
block_52:
block_53:
                                    SetBentleyState(arg0, 0);
                                }
                            } else {
block_39:
                                FAttachGroundTarget(var_a0_2, 0xF8FE, 0);
                            }
                        } else {
block_43:
                            ClearVjoyPresses(M2C_FIELD(arg0, void **, 0x150), 0x10);
                            M2C_FIELD(arg0, s32 *, 0x16B4) = PslotBentleyGadget(arg0, M2C_FIELD(arg0, s32 *, 0x1870));
                            SetBentleyState(arg0, 6);
                        }
                    } else {
block_36:
                        ClearVjoyPresses(M2C_FIELD(arg0, void **, 0x150), 0x400);
                        StartBinoc(arg0 + 0xF00, 0, 0, 0);
                    }
                } else {
block_33:
                    SetJmpState(var_a0, 1, 0, 0);
                }
            }
            break;
        case 2:                                     /* switch 2 */
            UpdateJmpBodyState(arg0 + 0x2C0);
block_40:
            if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x10, 0x3E19999A) != 0) {
                temp_v1_5 = M2C_FIELD(arg0, void **, 0xC);
                if (M2C_FIELD(temp_v1_5, s32 (**)(void *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_5, s16 *, 0x318), M2C_FIELD(arg0, s32 *, 0x1870)) != 0) {
                    goto block_43;
                }
            }
            break;
        case 3:                                     /* switch 2 */
            UpdateAttachInput(arg0 + 0x4C0);
            break;
        case 4:                                     /* switch 2 */
            UpdateZap(arg0 + 0xDF0);
            break;
        case 5:                                     /* switch 2 */
            if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x30) & 8) && (FJtInFocusRange(arg0, 1) != 0)) {
                var_a0 = arg0 + 0x2C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3DCCCCCD) != 0) {
                    goto block_33;
                }
                if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x400, 0x3E19999A) != 0) {
                    temp_v1_6 = M2C_FIELD(arg0, void **, 0xC);
                    if (M2C_FIELD(temp_v1_6, s32 (**)(void *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_6, s16 *, 0x318), 3) != 0) {
                        goto block_36;
                    }
                    goto block_38;
                }
block_38:
                var_a0_2 = arg0 + 0x4C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x20, 0x3E4CCCCD) != 0) {
                    goto block_39;
                }
                goto block_40;
            }
            goto block_53;
        case 13:                                    /* switch 2 */
            UpdateJtActivePipe(arg0 + 0xF50);
            break;
        case 6:                                     /* switch 2 */
            UpdateBentleyGadget(arg0);
            break;
        case 8:                                     /* switch 2 */
            func_001367D8(arg0);
            break;
        case 12:                                    /* switch 2 */
            CarryThrow_Update(arg0 + 0x11B0);
            break;
        case 10:                                    /* switch 2 */
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x1030);
            if ((temp_a0 == 0) || (FAsegaGone(temp_a0) == 0)) {
                temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x1034);
                if ((temp_a0_2 != 0) && (FSmaRetracted(temp_a0_2) != 0)) {
                    goto block_52;
                }
            } else {
                goto block_53;
            }
            break;
        case 14:                                    /* switch 2 */
            if (D_FLT_002BC930 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x13D4))) {
                SetBentleyState(arg0, 0);
            }
            break;
        }
        UpdateBentleyAim(arg0);
    } while (M2C_FIELD(arg0, u32 *, 0x13D0) != temp_s1);
}
