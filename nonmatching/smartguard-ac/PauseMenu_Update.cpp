typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PauseMenu_Update {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x58];
};                                                  /* size = 0x60 */
#define sp4 (*(f32 *)(sp + 0x04))
void CRef_Destruct(s8 *);
s32 FBlotLabelPlaying(s8 *, s32);
s32 FJoyButtonPressed(s32, M2C_UNK);
void MemcardMenu_SetState(M2C_UNK *, M2C_UNK);
void PauseMenu_AdjustOption(s8 *, s8 *, s32);
void PauseMenu_ApplyOption(s8 *, s32);
void PauseMenu_CancelOption(s8 *, s32);
void PauseMenu_Close(s8 *);
void PauseMenu_Pop(s8 *);
void PauseMenu_SetState(s8 *, M2C_UNK);
s32 RefGetGameSaveValue(s8 *, s32, s8 *);
s32 UpdateJoyNavY(s32);
s32 func_001AF490(s8 *);
s32 func_001B0078(s8 *);
void func_001D9870();
extern M2C_UNK B_002E6550;
extern M2C_UNK B_002E6604;
extern s32 B_003E0FAC;
void PauseMenu_Update(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    M2C_UNK (*temp_v0)(s8 *);
    M2C_UNK (*temp_v0_5)(s8 *);
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_s0_3;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    u32 temp_v1_2;
    s8 *temp_a0;
    s8 *temp_a1;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s2;
    s8 *temp_v0_3;
    func_001D9870();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x24);
    if (temp_v1 > 0) {
        temp_s2 = arg0 + ((temp_v1 * 0x1C) + 0xC);
        var_s0 = 0;
        if (M2C_FIELD(temp_s2, s32 *, 0) > 0) {
            do {
                temp_a0 = (s8 *)(M2C_FIELD(temp_s2, s32 *, 4) + (var_s0 << 5));
                temp_v0 = M2C_FIELD(temp_a0, M2C_UNK (**)(s8 *), 0x10);
                if (temp_v0 != NULL) {
                    temp_v0(temp_a0);
                }
                var_s0 += 1;
            } while (var_s0 < M2C_FIELD(temp_s2, s32 *, 0));
        }
        temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x1E8);
        switch (temp_v1_2) {
        case 0:
            break;
        case 1:
            if (FBlotLabelPlaying(M2C_FIELD(temp_s2, s8 **, 8), 0x314) == 0) {
                temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1EC);
                if (temp_v0_2 != -1) {
                    M2C_FIELD(arg0, s32 *, 0x24) = temp_v0_2;
                    M2C_FIELD(arg0, s32 *, 0x1EC) = -1;
                }
block_65:
                PauseMenu_SetState(arg0, 7);
            }
            break;
        case 2:
            if (FBlotLabelPlaying(M2C_FIELD(temp_s2, s8 **, 8), 0x314) == 0) {
                if (M2C_FIELD(arg0, s32 *, 0x1EC) == -1) {
                    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) - 1);
                } else {
                    M2C_FIELD(arg0, s32 *, 0x1EC) = -1;
                }
                if (M2C_FIELD(arg0, s32 *, 0x24) != 0) {
                    goto block_65;
                }
block_22:
                temp_a1 = M2C_FIELD(temp_s2, s8 **, 8);
                temp_v0_3 = M2C_FIELD(temp_a1, s8 **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *), 0x194)(temp_a1 + M2C_FIELD(temp_v0_3, s16 *, 0x190), temp_a1);
                PauseMenu_SetState(arg0, 0);
            }
            break;
        case 3:
            if (FBlotLabelPlaying(M2C_FIELD(temp_s2, s8 **, 8), M2C_FIELD(M2C_FIELD(temp_s2, s8 **, 0x18), s32 *, 0x14)) == 0) {
                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x1EC);
                M2C_FIELD(arg0, s32 *, 0x1EC) = -1;
                M2C_FIELD(arg0, s32 *, 0x24) = temp_v1_3;
                PauseMenu_SetState(arg0, 4);
            }
            break;
        case 4:
            var_a1 = M2C_FIELD(M2C_FIELD(temp_s2, s8 **, 0x18), s32 *, 0xC);
block_63:
            if (FBlotLabelPlaying(M2C_FIELD(temp_s2, s8 **, 8), var_a1) == 0) {
                goto block_65;
            }
            break;
        case 8:
            if (FBlotLabelPlaying(M2C_FIELD(temp_s2, s8 **, 8), 0x314) == 0) {
                goto block_22;
            }
            break;
        case 5:
            var_a1_2 = M2C_FIELD(M2C_FIELD(temp_s2, s8 **, 0x18), s32 *, 0x18);
block_24:
            if (FBlotLabelPlaying(M2C_FIELD(temp_s2, s8 **, 8), var_a1_2) == 0) {
                PauseMenu_SetState(arg0, 7);
                temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x10);
                if (temp_a0_2 != 0) {
                    var_v0 = UpdateJoyNavY(temp_a0_2);
                    if (var_v0 >= 0) {
block_58:
                        if (var_v0 > 0) {
                            PauseMenu_SetState(arg0, 5);
                        }
                    } else {
block_57:
                        PauseMenu_SetState(arg0, 6);
                    }
                }
            }
            break;
        case 6:
            var_a1_2 = M2C_FIELD(M2C_FIELD(temp_s2, s8 **, 0x18), s32 *, 0x1C);
            goto block_24;
        case 7:
            temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x10);
            if (temp_a0_3 != 0) {
                temp_v0_4 = FJoyButtonPressed(temp_a0_3, 0x870);
                if (!(temp_v0_4 & 0x800)) {
                    if (!(temp_v0_4 & 0x10)) {
                        if (M2C_FIELD(temp_s2, s32 *, 0) != 0) {
                            goto block_40;
                        }
                        if (temp_v0_4 == 0) {
block_40:
                            if (M2C_FIELD(arg0, s32 *, 0x24) > 0) {
                                var_v0_2 = temp_v0_4 & 0x20;
                                if (temp_v0_4 & 0x40) {
                                    temp_s0 = (s8 *)(M2C_FIELD(temp_s2, s32 *, 4) + (M2C_FIELD(temp_s2, s32 *, 0x14) << 5));
                                    temp_v0_5 = M2C_FIELD(temp_s0, M2C_UNK (**)(s8 *), 4);
                                    if (temp_v0_5 != NULL) {
                                        temp_v0_5(temp_s0);
                                    }
                                    temp_v1_4 = M2C_FIELD(temp_s0, s32 *, 0x1C);
                                    if (!(temp_v1_4 & 2)) {
                                        if (temp_v1_4 & 1) {
                                            if (M2C_FIELD(temp_s2, s32 *, 0xC) != 0) {
                                                goto block_47;
                                            }
                                            goto block_48;
                                        }
                                        goto block_69;
                                    }
                                } else {
                                    goto block_50;
                                }
                            } else {
                                var_v0_2 = temp_v0_4 & 0x20;
block_50:
                                if (var_v0_2 != 0) {
                                    temp_v0_6 = func_001B0078(arg0);
                                    if ((temp_v0_6 == 0x19) || (temp_v0_6 == 0x1E)) {
                                        temp_s0_2 = (s8 *)&B_002E6604 + (M2C_FIELD(temp_s2, s32 *, 0x14) * 0x5464);
                                        RefGetGameSaveValue(sp, B_003E0FAC, temp_s0_2);
                                        f32 flagValue = sp4;
                                        CRef_Destruct(sp);
                                        if (flagValue != 0.0f) {
                                            M2C_FIELD((s8 *)&B_002E6604, s8 **, 0xFD34) = temp_s0_2;
                                            MemcardMenu_SetState(&B_002E6550, 0x20);
                                        }
                                    }
                                } else if (temp_s2 != NULL) {
                                    var_v0 = UpdateJoyNavY(M2C_FIELD(arg0, s32 *, 0x10));
                                    if (var_v0 < 0) {
                                        goto block_57;
                                    }
                                    goto block_58;
                                }
                            }
                        } else {
                            goto block_38;
                        }
                    } else {
block_38:
                        if (M2C_FIELD(temp_s2, s32 *, 0xC) == 0) {
block_48:
                            PauseMenu_Pop(arg0);
                        } else {
block_47:
                            func_001AF490(arg0);
                        }
                    }
                } else {
block_69:
                    PauseMenu_Close(arg0);
                }
            }
            break;
        case 11:
            if (FBlotLabelPlaying(M2C_FIELD(temp_s2, s8 **, 8), 0x331) == 0) {
                PauseMenu_SetState(arg0, 0xA);
            }
            break;
        case 9:
            var_a1 = 0x332;
            goto block_63;
        case 10:
            temp_a0_4 = M2C_FIELD(arg0, s32 *, 0x10);
            if (temp_a0_4 != 0) {
                temp_s0_3 = M2C_FIELD(temp_s2, s32 *, 4) + (M2C_FIELD(temp_s2, s32 *, 0x14) << 5);
                temp_v0_7 = FJoyButtonPressed(temp_a0_4, 0x850);
                if (temp_v0_7 & 0x800) {
                    PauseMenu_CancelOption(arg0, temp_s0_3);
                    goto block_69;
                }
                if (temp_v0_7 & 0x10) {
                    PauseMenu_CancelOption(arg0, temp_s0_3);
                } else if (temp_v0_7 & 0x40) {
                    PauseMenu_ApplyOption(arg0, temp_s0_3);
                } else {
                    PauseMenu_AdjustOption(arg0, temp_s2, temp_s0_3);
                }
            }
            break;
        }
    }
}
}
