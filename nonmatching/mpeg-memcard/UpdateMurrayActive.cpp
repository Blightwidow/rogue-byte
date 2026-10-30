typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateMurrayActive {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK CarryThrow_Update(s8 *);                  /* extern */
M2C_UNK ClearVjoyPresses(s8 *, M2C_UNK);          /* extern */
s32 FAsegaGone(s32);                                /* extern */
s32 FAttachGroundTarget(s8 *, M2C_UNK, M2C_UNK);  /* extern */
s32 FButtonPressedWithin(s8 *, M2C_UNK, f32);     /* extern */
s32 FJtInFocusRange(s8 *, M2C_UNK);               /* extern */
s32 FJtLandsWithin(s8 *, f32);                    /* extern */
s32 FMurrayAttackCanChain(s8 *);                  /* extern */
s32 FMurrayTryGrabGuard(s8 *);                    /* extern */
s32 FSmaRetracted(s32);                             /* extern */
s32 GrfbtnJtGadget(s8 *, M2C_UNK);                /* extern */
s32 GrfbtnVjoyPressedWithin(s8 *, M2C_UNK, f32);  /* extern */
M2C_UNK SetJmpState(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetMurrayState(s8 *, M2C_UNK);            /* extern */
M2C_UNK StartBinoc(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK StartMurrayAttackA(s8 *);                 /* extern */
M2C_UNK StartMurrayAttackB(s8 *);                 /* extern */
M2C_UNK UpdateAttachInput(s8 *);                  /* extern */
M2C_UNK UpdateJmpBodyState(s8 *);                 /* extern */
M2C_UNK UpdateJtActivePipe(s8 *);                 /* extern */
M2C_UNK UpdateMurrayAttack(s8 *);                 /* extern */
M2C_UNK UpdateMurrayCarry(s8 *);                  /* extern */
M2C_UNK UpdateMurrayLift(s8 *);                   /* extern */
M2C_UNK UpdateMurrayMash(s8 *);                   /* extern */
M2C_UNK UpdateZap(s8 *);                          /* extern */
M2C_UNK func_001B5990(s8 *);                      /* extern */
M2C_UNK func_001B6BA8(s8 *);                      /* extern */
M2C_UNK func_001B8EC0(s8 *);                      /* extern */
extern f32 D_FLT_002C08DC;
extern f32 D_FLT_002C08E0;
extern f32 g_2dded0;
void UpdateMurrayActive(s8 *arg0) {
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s1;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_5;
    s32 temp_v1_7;
    s32 var_v0;
    s8 *temp_v0;
    s8 *temp_v1_4;
    s8 *temp_v1_6;
    s8 *var_a0;
    s8 *var_a0_2;
    do {
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x13D0);
        switch (temp_s1) {                          /* switch 1 */
        case 2:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
        case 4:                                     /* switch 1 */
        case 6:                                     /* switch 1 */
        case 7:                                     /* switch 1 */
        case 8:                                     /* switch 1 */
        case 14:                                    /* switch 1 */
        case 15:                                    /* switch 1 */
        case 16:                                    /* switch 1 */
        case 17:                                    /* switch 1 */
        case 18:                                    /* switch 1 */
        case 20:                                    /* switch 1 */
            break;
        default:                                    /* switch 1 */
        case 5:                                     /* switch 1 */
        case 9:                                     /* switch 1 */
        case 10:                                    /* switch 1 */
        case 11:                                    /* switch 1 */
        case 12:                                    /* switch 1 */
        case 13:                                    /* switch 1 */
        case 19:                                    /* switch 1 */
            if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x20C)) > 0.1f) {
                temp_v1 = M2C_FIELD(arg0, s32 *, 0x13D0);
                if (temp_v1 != 0xC) {
                    if (temp_v1 < 0xD) {
                        var_a0 = arg0 + 0x2C0;
                        if (temp_v1 != 5) {
                            goto block_19;
                        }
                        var_a1 = 0x10;
                        goto block_18;
                    }
                    if (temp_v1 == 0xD) {
                        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x4C8);
                        if (temp_v1_2 != 1) {
                            var_a0 = arg0 + 0x2C0;
                            if (temp_v1_2 != 0xC) {
                                var_a1 = 0;
                                goto block_18;
                            }
                        }
                    } else {
                        var_a0 = arg0 + 0x2C0;
block_19:
                        SetJmpState(var_a0, 0, 0, 0);
                    }
                } else if (M2C_FIELD(arg0, s32 *, 0x1840) == 3) {
                    var_a0 = arg0 + 0x2C0;
                    var_a1 = 0xB;
block_18:
                    SetJmpState(var_a0, var_a1, 0, 0);
                }
            }
            break;
        }
        temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x13D0);
        switch (temp_v1_3) {                        /* switch 2 */
        case 0:                                     /* switch 2 */
        case 1:                                     /* switch 2 */
        case 10:                                    /* switch 2 */
            if (!(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s32 *, 0x30) & 8) && (FJtInFocusRange(arg0, 0) != 0)) {
                SetMurrayState(arg0, 9);
            } else {
                var_a0_2 = arg0 + 0x2C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x40, 0.1f) != 0) {
                    var_a1_2 = 1;
block_82:
                    SetJmpState(var_a0_2, var_a1_2, 0, 0);
                } else if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x400, 0.15f) != 0) && (temp_v1_4 = M2C_FIELD(arg0, s8 **, 0xC), (M2C_FIELD(temp_v1_4, s32 (**)(s8 *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x318), 3) != 0))) {
                    ClearVjoyPresses(M2C_FIELD(arg0, s8 **, 0x150), 0x400);
                    StartBinoc(arg0 + 0xF00, 0, 0, 0);
                } else if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x10, D_FLT_002C08DC) != 0)) {
                    StartMurrayAttackB(arg0);
                } else if (FMurrayTryGrabGuard(arg0) == 0) {
                    if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x20, 0.2f) != 0) {
                        if ((FAttachGroundTarget(arg0 + 0x4C0, 0xF8FA, 0) == 0) && (M2C_FIELD(arg0, s32 *, 0x13EC) != 0)) {
                            M2C_FIELD(arg0, s32 *, 0x144C) = 0;
                            SetMurrayState(arg0, 4);
                        }
                    } else if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x80, D_FLT_002C08DC) != 0)) {
                        StartMurrayAttackA(arg0);
                    } else {
                        temp_v0 = M2C_FIELD(arg0, s8 **, 0x150);
                        temp_f1 = M2C_FIELD(temp_v0, f32 *, 0x1C);
                        if (M2C_FIELD(arg0, s32 *, 0x13D0) == 0) {
                            if (!(temp_f1 > 0.1f)) {
                                goto block_79;
                            }
                            goto block_45;
                        }
                        if (temp_f1 > 0.0f) {
block_45:
                            if (M2C_FIELD(temp_v0, s32 *, 0x30) & 8) {
                                SetMurrayState(arg0, 1);
                            } else {
                                SetMurrayState(arg0, 0xA);
                            }
                        } else {
block_78:
block_79:
                            SetMurrayState(arg0, 0);
                        }
                    }
                }
            }
            break;
        case 2:                                     /* switch 2 */
            UpdateJmpBodyState(arg0 + 0x2C0);
            temp_v1_5 = M2C_FIELD(arg0, s32 *, 0x2C4);
            if (temp_v1_5 != 0xB) {
                if (temp_v1_5 >= 0xC) {
                    if (temp_v1_5 < 0x11) {
                        if (temp_v1_5 >= 0xF) {
                        } else {
                            goto block_55;
                        }
                    } else {
                        goto block_54;
                    }
                } else if (temp_v1_5 != 0) {
block_54:
block_55:
                    if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x90, D_FLT_002C08DC) != 0) {
                        temp_v1_6 = M2C_FIELD(arg0, s8 **, 0xC);
                        if (M2C_FIELD(temp_v1_6, s32 (**)(s8 *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1_6, s16 *, 0x318), 2) != 0) {
                            temp_v1_7 = M2C_FIELD(arg0, s32 *, 0x2DC);
                            if ((temp_v1_7 < 6) && (temp_v1_7 > 0) && (FJtLandsWithin(arg0, D_FLT_002C08E0) == 0)) {
                                ClearVjoyPresses(M2C_FIELD(arg0, s8 **, 0x150), 0x90);
                                M2C_FIELD(arg0, s32 *, 0x13E8) = 0;
                                SetMurrayState(arg0, 3);
                            }
                        }
                    }
                }
            }
            break;
        case 13:                                    /* switch 2 */
            UpdateAttachInput(arg0 + 0x4C0);
            break;
        case 14:                                    /* switch 2 */
            UpdateZap(arg0 + 0xDF0);
            break;
        case 3:                                     /* switch 2 */
            func_001B6BA8(arg0);
            break;
        case 5:                                     /* switch 2 */
            UpdateMurrayCarry(arg0);
            break;
        case 6:                                     /* switch 2 */
            UpdateMurrayMash(arg0);
            break;
        case 4:                                     /* switch 2 */
            UpdateMurrayLift(arg0);
            break;
        case 7:                                     /* switch 2 */
        case 8:                                     /* switch 2 */
            var_v0 = FAsegaGone(M2C_FIELD(arg0, s32 *, 0x1030));
block_77:
            if (var_v0 != 0) {
                goto block_78;
            }
            break;
        case 11:                                    /* switch 2 */
            UpdateMurrayAttack(arg0);
            break;
        case 9:                                     /* switch 2 */
            func_001B5990(arg0);
            break;
        case 12:                                    /* switch 2 */
            func_001B8EC0(arg0);
            break;
        case 15:                                    /* switch 2 */
            CarryThrow_Update(arg0 + 0x1910);
            break;
        case 20:                                    /* switch 2 */
            UpdateJtActivePipe(arg0 + 0xF50);
            break;
        case 17:                                    /* switch 2 */
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x1030);
            if ((temp_a0 == 0) || (FAsegaGone(temp_a0) == 0)) {
                temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x1034);
                if (temp_a0_2 != 0) {
                    var_v0 = FSmaRetracted(temp_a0_2);
                    goto block_77;
                }
            } else {
                goto block_79;
            }
            break;
        case 21:                                    /* switch 2 */
            var_a0_2 = arg0 + 0x2C0;
            if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x40, 0.0f) != 0) {
                var_a1_2 = 0xD;
                goto block_82;
            }
            if (!(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s32 *, 0x30) & GrfbtnJtGadget(arg0, 0x10))) {
                SetMurrayState(arg0, 0);
            }
            break;
        }
    } while (M2C_FIELD(arg0, s32 *, 0x13D0) != temp_s1);
}
}
