typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PauseMenu_SetState {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
M2C_UNK SeekBlotLabel(s8 *, M2C_UNK, f32);        /* extern */
M2C_UNK func_00213B00(s8 *, s32);                 /* extern */
extern M2C_UNK B_002DEB80;
extern f32 B_FLT_002F6468;
extern f32 B_FLT_002F646C;
extern f32 B_FLT_003DD18C;
extern f32 B_FLT_003DD190;
void PauseMenu_SetState(s8 *arg0, u32 arg1) {
    f32 var_f0;
    f32 var_f12;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_v0;
    s64 temp_v0_4;
    u32 temp_v1;
    s8 *temp_a0_2;
    s8 *temp_a0_3;
    s8 *temp_a0_4;
    s8 *temp_a0_5;
    s8 *temp_a1;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a2_3;
    s8 *temp_a3;
    s8 *temp_a3_2;
    s8 *temp_a3_3;
    s8 *temp_v0_3;
    s8 *temp_v0_5;
    s8 *var_s0;
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x1E8);
    if (temp_v1 != arg1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x24);
        var_s0 = NULL;
        if (temp_a0 > 0) {
            var_s0 = arg0 + ((temp_a0 * 0x1C) + 0xC);
        }
        switch (temp_v1) {                          /* switch 1 */
        case 5:                                     /* switch 1 */
            var_v0 = arg1 < 0xCU;
            if (var_s0 != NULL) {
                temp_v0 = M2C_FIELD(var_s0, s32 *, 0x14) + 1;
                M2C_FIELD(var_s0, s32 *, 0x14) = temp_v0;
                if (temp_v0 >= M2C_FIELD(var_s0, s32 *, 0)) {
                    M2C_FIELD(var_s0, s32 *, 0x14) = 0;
                }
            default:                                /* switch 1 */
            case 1:                                 /* switch 1 */
            case 2:                                 /* switch 1 */
            case 3:                                 /* switch 1 */
            case 4:                                 /* switch 1 */
            case 7:                                 /* switch 1 */
            case 8:                                 /* switch 1 */
            case 9:                                 /* switch 1 */
            case 10:                                /* switch 1 */
            case 11:                                /* switch 1 */
block_12:
                var_v0 = arg1 < 0xCU;
            }
            break;
        case 6:                                     /* switch 1 */
            var_v0 = arg1 < 0xCU;
            if (var_s0 != NULL) {
                temp_v0_2 = M2C_FIELD(var_s0, s32 *, 0x14) - 1;
                M2C_FIELD(var_s0, s32 *, 0x14) = temp_v0_2;
                if (temp_v0_2 < 0) {
                    M2C_FIELD(var_s0, s32 *, 0x14) = (s32) (M2C_FIELD(var_s0, s32 *, 0) - 1);
                }
                goto block_12;
            }
            break;
        case 0:                                     /* switch 1 */
            temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *), 0x54)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x50));
            goto block_12;
        }
        M2C_FIELD(arg0, u32 *, 0x1E8) = arg1;
        if (var_v0 != 0) {
            switch (arg1) {                         /* switch 2 */
            case 1:                                 /* switch 2 */
                if (var_s0 != NULL) {
                    temp_a3 = M2C_FIELD(var_s0, s8 **, 8);
                    if (temp_a3 != NULL) {
                        temp_a2 = M2C_FIELD(temp_a3, s8 **, 0xC);
                        M2C_FIELD(temp_a2, M2C_UNK (**)(s8 *, s32, s8 *, s8 *), 0x18C)(temp_a3 + M2C_FIELD(temp_a2, s16 *, 0x188), M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0x18), s32 *, 0), temp_a2, temp_a3);
block_24:
                        func_00213B00(M2C_FIELD(var_s0, s8 **, 8), M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0x18), s32 *, 0xC));
                    }
                }
                break;
            case 3:                                 /* switch 2 */
                if ((var_s0 != NULL) && (M2C_FIELD(var_s0, s8 **, 8) != NULL)) {
block_28:
                    func_00213B00(M2C_FIELD(var_s0, s8 **, 8), M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0x18), s32 *, 0x14));
                }
                break;
            case 4:                                 /* switch 2 */
                if ((var_s0 != NULL) && (M2C_FIELD(var_s0, s8 **, 8) != NULL)) {
                    goto block_24;
                }
                break;
            case 2:                                 /* switch 2 */
            case 8:                                 /* switch 2 */
                if (var_s0 != NULL) {
                    temp_a3_2 = M2C_FIELD(var_s0, s8 **, 8);
                    if (temp_a3_2 != NULL) {
                        temp_a2_2 = M2C_FIELD(temp_a3_2, s8 **, 0xC);
                        M2C_FIELD(temp_a2_2, M2C_UNK (**)(s8 *, s32, s8 *, s8 *), 0x18C)(temp_a3_2 + M2C_FIELD(temp_a2_2, s16 *, 0x188), M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0x18), s32 *, 8), temp_a2_2, temp_a3_2);
                        goto block_28;
                    }
                }
                break;
            case 5:                                 /* switch 2 */
                if (var_s0 != NULL) {
                    temp_a0_2 = M2C_FIELD(var_s0, s8 **, 8);
                    if (temp_a0_2 != NULL) {
                        func_00213B00(temp_a0_2, M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0x18), s32 *, 0x18));
                    }
                }
                break;
            case 6:                                 /* switch 2 */
                if (var_s0 != NULL) {
                    temp_a0_3 = M2C_FIELD(var_s0, s8 **, 8);
                    if (temp_a0_3 != NULL) {
                        func_00213B00(temp_a0_3, M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0x18), s32 *, 0x1C));
                    }
                }
                break;
            case 11:                                /* switch 2 */
                if (var_s0 != NULL) {
                    temp_a0_4 = M2C_FIELD(var_s0, s8 **, 8);
                    if (temp_a0_4 != NULL) {
                        func_00213B00(temp_a0_4, 0x331);
                    }
                }
                break;
            case 9:                                 /* switch 2 */
                if (var_s0 != NULL) {
                    temp_a0_5 = M2C_FIELD(var_s0, s8 **, 8);
                    if (temp_a0_5 != NULL) {
                        func_00213B00(temp_a0_5, 0x332);
                    }
                }
                break;
            case 10:                                /* switch 2 */
                if ((var_s0 != NULL) && (temp_a1 = M2C_FIELD(var_s0, s8 **, 8), (temp_a1 != NULL))) {
                    temp_v1_2 = *(s32 *)(M2C_FIELD(var_s0, s32 *, 4) + (M2C_FIELD(var_s0, s32 *, 0x14) << 5));
                    switch (temp_v1_2) {            /* switch 3; irregular */
                    case 0x67:                      /* switch 3 */
                        func_00213B00(temp_a1, 0x333);
                        func_00213B00(M2C_FIELD(var_s0, s8 **, 8), 0x315);
                        var_f12 = B_FLT_003DD190;
block_51:
                        SeekBlotLabel(M2C_FIELD(var_s0, s8 **, 8), 0x315, var_f12);
                        break;
                    case 0x68:                      /* switch 3 */
                        func_00213B00(temp_a1, 0x334);
                        func_00213B00(M2C_FIELD(var_s0, s8 **, 8), 0x315);
                        var_f12 = B_FLT_003DD18C;
                        goto block_51;
                    case 0x3F:                      /* switch 3 */
                        func_00213B00(temp_a1, 0x335);
                        temp_v1_3 = M2C_FIELD(&B_002DEB80, s32 *, 0x18) & 0xFFF;
                        if (temp_v1_3 >= 0) {
                            var_f0 = (f32) temp_v1_3;
                        } else {
                            var_f0 = 2.0f * (f32) ((M2C_FIELD(&B_002DEB80, s32 *, 0x18) & 1) | ((u32) temp_v1_3 >> 1));
                        }
                        temp_v0_4 = (s64) ((s64) M2C_FIELD(&B_002DEB80, s32 *, 0x18) << 0x14) >> 0x20;
                        temp_v1_4 = temp_v0_4 & 0x7FF;
                        B_FLT_002F6468 = var_f0;
                        if (temp_v1_4 >= 0) {
                            B_FLT_002F646C = (f32) temp_v1_4;
                        } else {
                            B_FLT_002F646C = 2.0f * (f32) ((temp_v0_4 & 1) | ((u32) temp_v1_4 >> 1));
                        }
                        break;
                    }
                }
                break;
            case 7:                                 /* switch 2 */
                if (var_s0 != NULL) {
                    temp_a3_3 = M2C_FIELD(var_s0, s8 **, 8);
                    if (temp_a3_3 != NULL) {
                        temp_a2_3 = M2C_FIELD(temp_a3_3, s8 **, 0xC);
                        M2C_FIELD(temp_a2_3, M2C_UNK (**)(s8 *, s32, s8 *, s8 *), 0x18C)(temp_a3_3 + M2C_FIELD(temp_a2_3, s16 *, 0x188), M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0x18), s32 *, 4), temp_a2_3, temp_a3_3);
                        func_00213B00(M2C_FIELD(var_s0, s8 **, 8), M2C_FIELD(M2C_FIELD(var_s0, s8 **, 0x18), s32 *, 0x10));
                    }
                }
                break;
            case 0:                                 /* switch 2 */
                temp_v0_5 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *), 0x5C)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x58));
                break;
            }
        }
    }
}
}
