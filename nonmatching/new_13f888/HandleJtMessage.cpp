typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct It_140F90 { int pad0; s8 *sp4; s32 sp8; s8 *spC; };
extern "C" {
struct _m2c_stack_HandleJtMessage {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s8 **sp4;                          /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s8 *spC;                           /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0x60];
};                                                  /* size = 0x80 */
void ApplyAsegToHandle(s32, s8 *, M2C_UNK, s8 *, M2C_UNK, M2C_UNK);
void CarryThrow_Launch(s8 *, s8 *);
void CarryThrow_SetState(s8 *, M2C_UNK);
void Carry_Attach(s8 *, s32);
s32 FGadgetObjActive(s32);
s32 FIsBasicDerivedFrom(s32, M2C_UNK);
void GoalStack_HandleMessage(s8 *, s32, s8 *);
void HandlePoMessage(s8 *, s32, s8 *);
void HitFx_Remove(s8 *);
s32 PloLeaseCloneObject(s32, M2C_UNK);
s32 PosLoWorld(s8 *, s8 *);
void ReleaseGadgetObj(s32);
void RetractAsegaHandle(s8 *, s32);
f32 SetAsegaSpeed(s32, s8 *, M2C_UNK);
void SetSwGuardsFrozen(M2C_UNK *, M2C_UNK);
void SetSwGuardsMode(M2C_UNK *, M2C_UNK);
f32 SpendJtGadgetPower(s8 *, s32);
void UnsubscribeLoObject(s8 *, s8 *);
void ZapContinue(s8 *, s32);
void func_001A58D0(s32, M2C_UNK, M2C_UNK);
void func_001CCC88(s8 *, s32);
s32 func_00204E38(s8 *, s8 *, s32);
extern M2C_UNK B_003DD490;
extern M2C_UNK B_003E148C;
extern f32 g_2bcc94;
extern s8 *g_2dd2fc;
extern f32 g_2dded0;
extern s8 *g_2e1e40;
void HandleJtMessage(s8 *arg0, s32 arg1, s8 *arg2) {
    s128 sp10;
    M2C_UNK (*temp_a1_3)(s8 *, M2C_UNK, s8 *);
    M2C_UNK (*temp_a1_4)(s8 *, M2C_UNK, s8 *);
    M2C_UNK (*temp_a2)(s8 *, M2C_UNK, M2C_UNK);
    s32 temp_a0;
    s32 temp_a1_2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_s0;
    s32 var_s2;
    s8 *temp_a0_2;
    s8 *temp_a1;
    s8 *temp_a2_2;
    s8 *temp_a2_3;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1_3;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    s8 *var_a0;
    s8 *var_a3;
    switch (arg1) {                                 /* switch 1 */
    case 3:                                         /* switch 1 */
        if ((s32)arg2 != M2C_FIELD(arg0, s32 *, 0x1030)) {
            temp_v0 = M2C_FIELD(arg0, s8 **, 0x1034);
            var_a0 = arg0 + 0x26C;
            if (temp_v0 != NULL) {
                if ((s32)arg2 == M2C_FIELD(temp_v0, s32 *, 0x30)) {
                    goto block_5;
                }
            }
        } else {
block_5:
            M2C_FIELD(arg0, s32 *, 0x1038) = -1;
            if ((u32) (M2C_FIELD(arg0, s32 *, 0xDF4) - 8) < 5U) {
                ZapContinue(arg0 + 0xDF0, arg1);
                goto block_82;
            }
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x11B4);
            if (temp_v1 > 0) {
                if (temp_v1 >= 3) {
                    if (temp_v1 < 7) {
                        var_a0 = arg0 + 0x26C;
                        if (temp_v1 >= 5) {
                            CarryThrow_SetState(arg0 + 0x11B0, 4);
                            goto block_82;
                        }
                    } else {
                        goto block_82;
                    }
                } else {
                    CarryThrow_SetState(arg0 + 0x11B0, 0);
                    goto block_82;
                }
            } else {
            default:                                /* switch 1 */
block_82:
                var_a0 = arg0 + 0x26C;
            }
        }
        break;
    case 9:                                         /* switch 1 */
        temp_a1 = M2C_FIELD(arg2, s8 **, 0);
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(temp_a1, s32 *, 0x18) == (s32)arg0) {
            temp_v1_2 = M2C_FIELD(arg2, s32 *, 8);
            if (temp_v1_2 != 0x1C7) {
                if (temp_v1_2 < 0x1C8) {
                    switch (temp_v1_2) {            /* switch 2; irregular */
                    case 0x15E:                     /* switch 2 */
                        asm volatile("qmtc2.ni %0, vf4" : : "r"(func_00204E38(arg0, temp_a1, M2C_FIELD(arg2, s32 *, 4))));
                        temp_v1_3 = arg0 + 0x1B0;
                        asm volatile("lqc2 vf3, 0x1b0(%0)" : : "r"(arg0));
                        asm volatile("qmtc2.ni %0, vf5" : : "r"(0xBF800000));
                        asm volatile("vmulx.xyzw vf1, vf4, vf5x");
                        temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
                        asm volatile("sqc2 vf1, 0x190(%0)" : : "r"(arg0));
                        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_v1_3));
                        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v1_3));
                        temp_a2 = M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK), 0x11C);
                        asm volatile("vmulax.xyz ACC, vf3, vf4x");
                        asm volatile("vmadday.xyz ACC, vf1, vf4y");
                        asm volatile("vmaddz.xyz vf6, vf2, vf4z");
                        { s128 vec; asm volatile("sqc2 vf5, (%0)" : : "r"(&vec)); }
                        s32 vu_1;
                        asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_1));
                        temp_a2(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x118), vu_1, (M2C_UNK)(s32)temp_a2);
                        goto block_82;
                    default:                        /* switch 2 */
                        var_a0 = arg0 + 0x26C;
                        if (temp_v1_2 != 0x162) {
                        } else {
                            M2C_FIELD(arg0, s32 *, 0x1044) = 0;
                            sp10 = M2C_FIELD(arg0, s128 *, 0x1060);
                            asm volatile("lqc2 vf2, 0(%0)" : : "r"(&sp10));
                            asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(arg0, temp_a1)));
                            asm volatile("vsub.xyzw vf1, vf2, vf3");
                            asm volatile("sqc2 vf1, 0x1070(%0)" : : "r"(arg0));
                            M2C_FIELD(arg0, s32 *, 0x1078) = 0;
                            goto block_82;
                        }
                        break;
                    case 0x161:                     /* switch 2 */
                        M2C_FIELD(arg0, s32 *, 0x1044) = 1;
                        goto block_82;
                    }
                } else if (temp_v1_2 != 0x27B) {
                    if (temp_v1_2 < 0x27C) {
                        var_a0 = arg0 + 0x26C;
                        if (temp_v1_2 != 0x1C8) {
                        } else if (M2C_FIELD(arg0, s32 *, 0x4C8) == 0xC) {
                            func_001CCC88(arg0 + 0x900, M2C_FIELD(arg0, s32 *, 0x4D4));
                            goto block_82;
                        }
                    } else {
                        var_a0 = arg0 + 0x26C;
                        if (temp_v1_2 != 0x27C) {
                        } else if (M2C_FIELD(arg0, s32 *, 0x4C8) == 0xB) {
                            temp_a0 = M2C_FIELD(arg0, s32 *, 0x4D4);
                            if ((temp_a0 != 0) && (FIsBasicDerivedFrom(temp_a0, 0x64) != 0)) {
                                temp_s0 = M2C_FIELD(arg0, s32 *, 0x4D4);
                                if (FGadgetObjActive(temp_s0) != 0) {
                                    ReleaseGadgetObj(temp_s0);
                                }
                            }
                            temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x9BC);
                            if (M2C_FIELD(arg0, s32 *, 0x130C) != 0) {
                                if (M2C_FIELD(arg0, s32 *, 0x1314) == temp_a1_2) {
                                    RetractAsegaHandle(arg0 + 0x1310, temp_a1_2);
                                    M2C_FIELD(arg0, s32 *, 0x1314) = -1;
                                } else {
                                    SpendJtGadgetPower(arg0, temp_a1_2);
                                    ApplyAsegToHandle(M2C_FIELD(arg0, s32 *, 0x130C), arg0, 8, arg0 + 0x1310, 0, 0x3F800000);
                                    M2C_FIELD(arg0, s32 *, 0x1314) = (s32) M2C_FIELD(arg0, s32 *, 0x9BC);
                                }
                            } else if (temp_a1_2 != -1) {
                                SpendJtGadgetPower(arg0, temp_a1_2);
                                temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x9BC);
                                switch (temp_v1_4) { /* switch 3; irregular */
                                case 14:            /* switch 3 */
                                    SetSwGuardsFrozen(&B_003DD490, 1);
                                    break;
                                case 21:            /* switch 3 */
                                    SetSwGuardsMode(&B_003DD490, 0x15);
                                    break;
                                case 23:            /* switch 3 */
                                    temp_v0_3 = PloLeaseCloneObject(M2C_FIELD(g_2e1e40, s32 *, 0x2010), 0);
                                    if (temp_v0_3 != 0) {
                                        func_001A58D0(temp_v0_3, 0, 3);
                                    }
                                    var_a3 = M2C_FIELD(&B_003E148C, s8 **, 0);
                                    It_140F90 it;
                                    it.spC = g_2dd2fc;
                                    it.sp4 = M2C_FIELD(&B_003E148C, s8 **, 0) + M2C_FIELD(&B_003E148C, s32 *, 8);
                                    it.sp8 = M2C_FIELD(&B_003E148C, s32 *, 8);
                                    g_2dd2fc = (s8 *)&it;
                                    if (var_a3 != NULL) {
                                        do {
                                            if ((M2C_FIELD(var_a3, s32 *, 0x54) == 4) && (M2C_FIELD(var_a3, s32 *, 0x44) == (s32)arg0)) {
                                                HitFx_Remove(var_a3);
                                            }
                                            temp_a0_2 = *(s8 **)it.sp4;
                                            var_a3 = temp_a0_2;
                                            it.sp4 = temp_a0_2 + it.sp8;
                                        } while (var_a3 != NULL);
                                    }
                                    g_2dd2fc = it.spC;
                                    M2C_FIELD(&B_003DD490, f32 *, 0x4758) = (f32) (g_2dded0 + g_2bcc94);
                                    break;
                                }
                            }
                            M2C_FIELD(arg0, s32 *, 0x130C) = 0;
                            M2C_FIELD(arg0, s32 *, 0x9BC) = -1;
                            goto block_82;
                        }
                    }
                } else {
                    var_a0 = arg0 + 0x26C;
                    if (M2C_FIELD(arg0, s32 *, 0x11B4) != -1) {
                        CarryThrow_Launch(arg0 + 0x11B0, temp_a1);
                        goto block_82;
                    }
                }
            } else {
                var_a0 = arg0 + 0x26C;
                if (M2C_FIELD(arg0, s32 *, 0x4C8) == 0xC) {
                    SetAsegaSpeed(M2C_FIELD(arg0, s32 *, 0x1030), temp_a1, 0x3F800000);
                    Carry_Attach(arg0 + 0x900, M2C_FIELD(arg0, s32 *, 0x4D4));
                    goto block_82;
                }
            }
        }
        break;
    case 4:                                         /* switch 1 */
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(arg2, s32 *, 4) == (s32)arg0) {
            var_s2 = 0;
            M2C_FIELD(arg0, s8 **, 0x108C) = (s8 *) M2C_FIELD(arg2, s8 **, 0);
            if (M2C_FIELD(arg0, s32 *, 0x1094) > 0) {
                do {
                    temp_s0_2 = var_s2 * 8;
                    var_s2 += 1;
                    temp_a2_2 = *(s8 **)(temp_s0_2 + M2C_FIELD(arg0, s32 *, 0x1090));
                    temp_v1_5 = M2C_FIELD(temp_a2_2, s8 **, 0xC);
                    temp_a1_3 = M2C_FIELD(temp_v1_5, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x44);
                    temp_a1_3(temp_a2_2 + M2C_FIELD(temp_v1_5, s16 *, 0x40), (M2C_UNK)(s32)temp_a1_3, temp_a2_2);
                    M2C_FIELD((temp_s0_2 + M2C_FIELD(arg0, s32 *, 0x1090)), s32 *, 4) = 0;
                } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x1094));
                goto block_82;
            }
        }
        break;
    case 5:                                         /* switch 1 */
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(arg2, s32 *, 4) == (s32)arg0) {
            if (M2C_FIELD(arg2, s8 **, 0) == M2C_FIELD(arg0, s8 **, 0x108C)) {
                var_s0 = 0;
                M2C_FIELD(arg0, s8 **, 0x108C) = NULL;
                if (M2C_FIELD(arg0, s32 *, 0x1094) > 0) {
                    do {
                        temp_v0_4 = var_s0 * 8;
                        var_s0 += 1;
                        temp_a2_3 = *(s8 **)(temp_v0_4 + M2C_FIELD(arg0, s32 *, 0x1090));
                        temp_v1_6 = M2C_FIELD(temp_a2_3, s8 **, 0xC);
                        temp_a1_4 = M2C_FIELD(temp_v1_6, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x4C);
                        temp_a1_4(temp_a2_3 + M2C_FIELD(temp_v1_6, s16 *, 0x48), (M2C_UNK)(s32)temp_a1_4, temp_a2_3);
                    } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x1094));
                    goto block_82;
                }
            }
        }
        break;
    case 1:                                         /* switch 1 */
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(arg0, s32 *, 0x4C8) == 0xB) {
            if (M2C_FIELD(arg0, s32 *, 0x4D4) == (s32)arg2) {
                UnsubscribeLoObject(arg2, arg0);
                M2C_FIELD(arg0, s32 *, 0x4D4) = 0;
                goto block_82;
            }
        }
        break;
    case 11:                                        /* switch 1 */
        var_a0 = arg0 + 0x26C;
        if (M2C_FIELD(arg2, s32 *, 4) == (s32)arg0) {
            RetractAsegaHandle(arg0 + 0x1310, 0);
            M2C_FIELD(arg0, s32 *, 0x1314) = -1;
            goto block_82;
        }
        break;
    }
    GoalStack_HandleMessage(var_a0, arg1, arg2);
    HandlePoMessage(arg0, arg1, arg2);
}
}
