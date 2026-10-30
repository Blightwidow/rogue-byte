typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_HandleSlyMessage {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);
void GoalAnimLeap_SetState(s32, M2C_UNK);
void HandleJtMessage();
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *);
s32 PosLoWorld(s8 *);
void SetJmpState(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void SetJtJtcs(s8 *, M2C_UNK);
void SetJtState(s8 *, M2C_UNK, M2C_UNK);
s32 SpawnSwHitFx(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *);
void func_00131B10(s32, s8 *, s32);
void func_00131B60(s32, s8 *, M2C_UNK, M2C_UNK *);
void func_001424E0(s8 *, s32, s32, M2C_UNK);
void func_0018D698(s8 *, s8 *, M2C_UNK);
s32 func_001F1E20(s32, M2C_UNK);
s32 func_00205458(s32, s32);
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BF2A0;
extern M2C_UNK D_002BF2B8;
void HandleSlyMessage(s8 *arg0, s32 arg1, s32 arg2) {
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
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_v0_2;
    s8 *temp_v0_6;
    s8 *temp_v1_3;
    s8 *var_s0;
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
            ;
        }
        return;
    case 9:                                         /* switch 1 */
        temp_v1_2 = M2C_FIELD(arg2, s32 *, 0);
        if ((temp_v1_2 == M2C_FIELD(arg0, s32 *, 0x1030)) || (temp_v1_2 == M2C_FIELD(arg0, s32 *, 0x18E0)) || ((temp_v0_2 = M2C_FIELD(arg0, s8 **, 0x1034), (temp_v0_2 != NULL)) && (temp_v1_2 == M2C_FIELD(temp_v0_2, s32 *, 0x30)))) {
            temp_a2 = M2C_FIELD(arg2, s8 **, 8) - 0x164;
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
                    s64 vu_1;
                    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(arg0)));
                    temp_v0_4 = func_001F1E20(M2C_FIELD(arg0, s32 *, 0x10DC), vu_1);
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
                temp_v0_6 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(s8 *, s128, s8 *), 0x11C)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 0x118), (s128) M2C_FIELD(arg0, s32 *, 0x190), temp_a2);
                temp_v0_7 = func_00205458(M2C_FIELD(arg0, s32 *, 0x10DC), 0xB1);
                if (temp_v0_7 != 0) {
                    GoalAnimLeap_SetState(temp_v0_7, 4);
                }
                break;
            case 16:                                /* switch 3 */
                temp_v0_8 = func_00205458(M2C_FIELD(arg0, s32 *, 0x10DC), 0xB1);
                if (temp_v0_8 != 0) {
                    GoalAnimLeap_SetState(temp_v0_8, 6);
                }
                break;
            case 9:                                 /* switch 3 */
                s64 vu_2;
                asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(PosLoWorld(arg0)));
                SpawnSwHitFx(&B_003DD490, 0, vu_2, arg0);
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
        if (M2C_FIELD(arg2, s32 *, 4) == (s32)arg0) {
            temp_a2_2 = M2C_FIELD(arg2, s8 **, 8);
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
}
