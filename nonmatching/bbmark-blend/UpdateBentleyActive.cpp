typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateBentleyActive {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
void CarryThrow_Update(s8 *);
void ClearVjoyPresses(s8 *, M2C_UNK);
s32 FAsegaGone(s32);
s32 FAttachGroundTarget(s8 *, M2C_UNK, M2C_UNK);
s32 FButtonPressedWithin(s8 *, M2C_UNK, M2C_UNK);
s32 FJtInFocusRange(s8 *, M2C_UNK);
s32 FSmaRetracted(s32);
s32 GrfbtnVjoyPressedWithin(s8 *, M2C_UNK, M2C_UNK);
s32 PslotBentleyGadget(s8 *, s32);
void SetBentleyState(s8 *, M2C_UNK);
void SetJmpState(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void StartBinoc(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void UpdateAttachInput(s8 *);
void UpdateBentleyAim(s8 *);
void UpdateBentleyGadget(s8 *);
void UpdateJmpBodyState(s8 *);
void UpdateJtActivePipe(s8 *);
void UpdateZap(s8 *);
void func_001367D8(s8 *);
extern f32 D_FLT_002BC930;
extern f32 g_2dded0;
void UpdateBentleyActive(s8 *arg0) {
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v1;
    u32 temp_s1;
    u32 temp_v1_2;
    s8 *temp_v0;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    s8 *var_a0;
    s8 *var_a0_2;
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
            if (!(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s32 *, 0x30) & 8) && (FJtInFocusRange(arg0, 0) != 0)) {
                SetBentleyState(arg0, 5);
            } else {
                var_a0 = arg0 + 0x2C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x40, 0x3DCCCCCD) == 0) {
                    if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x400, 0x3E19999A) == 0) || (temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC), (M2C_FIELD(temp_v1_3, s32 (**)(s8 *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x318), 3) == 0))) {
                        if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x10, 0x3E19999A) == 0) || (temp_v1_4 = M2C_FIELD(arg0, s8 **, 0xC), (M2C_FIELD(temp_v1_4, s32 (**)(s8 *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x318), M2C_FIELD(arg0, s32 *, 0x1870)) == 0))) {
                            var_a0_2 = arg0 + 0x4C0;
                            if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x20, 0x3E4CCCCD) == 0) {
                                temp_v0 = M2C_FIELD(arg0, s8 **, 0x150);
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
                            ClearVjoyPresses(M2C_FIELD(arg0, s8 **, 0x150), 0x10);
                            M2C_FIELD(arg0, s32 *, 0x16B4) = PslotBentleyGadget(arg0, M2C_FIELD(arg0, s32 *, 0x1870));
                            SetBentleyState(arg0, 6);
                        }
                    } else {
block_36:
                        ClearVjoyPresses(M2C_FIELD(arg0, s8 **, 0x150), 0x400);
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
            if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x10, 0x3E19999A) != 0) {
                temp_v1_5 = M2C_FIELD(arg0, s8 **, 0xC);
                if (M2C_FIELD(temp_v1_5, s32 (**)(s8 *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_5, s16 *, 0x318), M2C_FIELD(arg0, s32 *, 0x1870)) != 0) {
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
            if (!(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s32 *, 0x30) & 8) && (FJtInFocusRange(arg0, 1) != 0)) {
                var_a0 = arg0 + 0x2C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x40, 0x3DCCCCCD) != 0) {
                    goto block_33;
                }
                if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x400, 0x3E19999A) != 0) {
                    temp_v1_6 = M2C_FIELD(arg0, s8 **, 0xC);
                    if (M2C_FIELD(temp_v1_6, s32 (**)(s8 *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_6, s16 *, 0x318), 3) != 0) {
                        goto block_36;
                    }
                    goto block_38;
                }
block_38:
                var_a0_2 = arg0 + 0x4C0;
                if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x20, 0x3E4CCCCD) != 0) {
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
}
