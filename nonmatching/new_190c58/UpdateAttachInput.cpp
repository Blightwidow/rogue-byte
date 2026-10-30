typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateAttachInput {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x300];
    /* 0x310 */ s32 sp310;                          /* inferred */
    /* 0x314 */ char pad314[0xC];                   /* maybe part of sp310[4]? */
    /* 0x320 */ s32 sp320;                          /* inferred */
    /* 0x324 */ s8 **sp324;                       /* inferred */
    /* 0x328 */ s32 sp328;                          /* inferred */
    /* 0x32C */ s32 sp32C;                          /* inferred */
    /* 0x330 */ s32 sp330;                          /* inferred */
    /* 0x334 */ s32 sp334;                          /* inferred */
    /* 0x338 */ char pad338[8];                     /* maybe part of sp334[3]? */
    /* 0x340 */ s128 sp340;                         /* inferred */
    /* 0x350 */ s128 sp350;                         /* inferred */
    /* 0x360 */ s128 sp360;                         /* inferred */
    /* 0x370 */ s128 sp370;                         /* inferred */
    /* 0x380 */ char pad380[0xD0];
};                                                  /* size = 0x450 */
#define sp340 (*(s128 *)(sp + 0x340))
#define sp370 (*(s128 *)(sp + 0x370))
s32 CStackFrame_Construct(s8 *, s32);
void CStackFrame_Destructor(s8 *, M2C_UNK);
void Carry_Attach(s8 *, s8 *);
void ClearVjoyPresses(s8 *, M2C_UNK);
s32 ClsgClipEdgeToObject(s8 *, M2C_UNK, s128, M2C_UNK);
s32 FAsegaGone(s32, s32);
s32 FButtonPressedWithin(s8 *, M2C_UNK, M2C_UNK);
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);
void FreeSwMqList__FP2SWP2MQ(M2C_UNK *, s32);
s32 GetJtPower(s8 *, s32);
s32 GrfbtnJtGadget(s8 *, M2C_UNK, s8 *);
s32 GrfbtnVjoyPressedWithin(s8 *, M2C_UNK, M2C_UNK);
void MarkSoContactsBspBsp(M2C_UNK *, s8 *, s8 *, s32);
void MarkSoContactsSphereBsp(M2C_UNK *, s8 *, s8 *, M2C_UNK);
s128 PosLoWorld(s8 *);
s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(s32, M2C_UNK, s128, s32 *, M2C_UNK);
s32 PvAllocStackImpl__Fi(s32 *, M2C_UNK, s32 *);
void SetAttachSubstate(s8 *, M2C_UNK);
void SetJmpState(s32, M2C_UNK, M2C_UNK, s8 *);
void StartBinoc(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 VecMaxOfVerts(s32, s32);
s32 VecMinOfVerts(s32, s32);
void bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *);
s32 func_001423A0(s8 *);
void func_001F38A8(s8 *);
extern s32 B_002DFBC4;
extern M2C_UNK B_003DD490;
extern s32 D_002BF5B0;
extern f32 D_FLT_002BF5B4;
extern f32 D_FLT_002BF5B8;
extern M2C_UNK FFilterOxa;
extern M2C_UNK g_2a2dc0;
extern f32 g_2dded0;
#define sp310 (*(s32 *)(sp + 0x310))
#define sp320 (*(s32 *)(sp + 0x320))
#define sp324 (*(s8 ** *)(sp + 0x324))
#define sp328 (*(s32 *)(sp + 0x328))
#define sp32C (*(s32 *)(sp + 0x32C))
#define sp330 (*(s32 *)(sp + 0x330))
#define sp334 (*(s32 *)(sp + 0x334))
#define sp350 (*(s128 *)(sp + 0x350))
#define sp360 (*(s128 *)(sp + 0x360))
void UpdateAttachInput(s8 *arg0) {
    s8 sp[0x3A0] __attribute__((aligned(16)));
    M2C_UNK temp_f20;
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    f32 *var_v1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a3;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_5;
    s32 var_a0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s5;
    s32 var_v0_2;
    s8 **var_a1_3;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a2_3;
    s8 *temp_a2_4;
    s8 *temp_a2_5;
    s8 *temp_a2_6;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s0_3;
    s8 *temp_s1;
    s8 *temp_s7;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *temp_v0_7;
    s8 *temp_v0_8;
    s8 *temp_v1;
    s8 *temp_v1_4;
    s8 *var_a3;
    s8 *var_v0;
    temp_s7 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0x150);
loop_1:
    temp_v0 = M2C_FIELD(arg0, s32 *, 8);
    sp334 = M2C_FIELD(arg0, s32 *, 0xC);
    switch (temp_v0) {                              /* switch 1 */
    case 1:                                         /* switch 1 */
        if (((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x10)) > 0.15f) && (var_a1 = 7, (FButtonPressedWithin(temp_s7, 0x40, 0x3E800000) != 0))) {
            var_a3 = M2C_FIELD(arg0, s8 **, 0x14);
block_68:
            SetJmpState((int)(M2C_FIELD(arg0, s8 **, 0) + 0x2C0), var_a1, 0, var_a3);
        } else {
block_6:
            if (GrfbtnVjoyPressedWithin(temp_s7, 0x400, 0x3E19999A) != 0) {
                temp_a2 = M2C_FIELD(arg0, s8 **, 0);
                temp_v1 = M2C_FIELD(temp_a2, s8 **, 0xC);
                if (M2C_FIELD(temp_v1, s32 (**)(s8 *, M2C_UNK, s8 *), 0x31C)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 0x318), 3, temp_a2) != 0) {
block_73:
                    ClearVjoyPresses(temp_s7, 0x400);
                    StartBinoc(M2C_FIELD(arg0, s8 **, 0) + 0xF00, 0, 0, 0);
                }
            }
        }
block_80:
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0xC);
        if ((temp_v1_2 == sp334) || (temp_v1_2 == -1)) {
            return;
        }
        goto loop_1;
    case 3:                                         /* switch 1 */
    case 4:                                         /* switch 1 */
        if (FButtonPressedWithin(temp_s7, 0x40, 0x3DCCCCCD) == 0) {
            goto block_6;
        }
block_67:
        var_a1 = 1;
        var_a3 = NULL;
        goto block_68;
        goto block_80;
    case 7:                                         /* switch 1 */
        temp_a2_2 = M2C_FIELD(arg0, s8 **, 0);
        temp_s0 = M2C_FIELD(arg0, s8 **, 0x14);
        temp_v0_2 = M2C_FIELD(temp_a2_2, s8 **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x2C4)(temp_a2_2 + M2C_FIELD(temp_v0_2, s16 *, 0x2C0), 0, temp_a2_2);
        temp_v0_3 = M2C_FIELD(temp_s0, s8 **, 0xC);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *), 0x19C)(temp_s0 + M2C_FIELD(temp_v0_3, s16 *, 0x198), M2C_FIELD(arg0, s8 **, 0));
        goto block_80;
    case 8:                                         /* switch 1 */
        switch (sp334) {                            /* switch 2; irregular */
        case 7:                                     /* switch 2 */
            if (FAsegaGone(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1030), sp334) != 0) {
                SetAttachSubstate(arg0, 9);
            }
            break;
        case 8:                                     /* switch 2 */
            if (FAsegaGone(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1030), sp334) != 0) {
block_61:
                var_a1_2 = 0;
block_62:
                var_v0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0xC);
block_63:
                M2C_FIELD(var_v0, M2C_UNK (**)(s32, M2C_UNK, s8 *), 0x2C4)((s32)(M2C_FIELD(arg0, s8 **, 0) + M2C_FIELD(var_v0, s16 *, 0x2C0)), var_a1_2, M2C_FIELD(arg0, s8 **, 0));
            }
            break;
        default:                                    /* switch 2 */
            CStackFrame_Construct(sp, sp334);
            var_s2 = 0;
            asm volatile("lqc2 vf2, 0x240(%0)" : : "r"(M2C_FIELD(arg0, s8 **, 0)));
            asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
            asm volatile("qmtc2.ni %0, vf3" : : "r"(D_002BF5B0));
            asm volatile("qmtc2.ni %0, vf4" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0))));
            asm volatile("vmulx.xyzw vf1, vf1, vf3x");
            asm volatile("vadd.xyzw vf2, vf4, vf2");
            asm volatile("vadd.xyzw vf4, vf2, vf1");
            asm volatile("sqc2 vf4, 0x340(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x390(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x310(%0)" : : "r"(sp));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
            bevy_camera_follow_push_out(&B_003DD490, sp340, vu_1, &FFilterOxa);
            asm volatile("lqc2 vf2, 0x390(%0)" : : "r"(sp));
            if (sp320 > 0) {
loop_21:
                asm volatile("sqc2 vf2, 0x390(%0)" : : "r"(sp));
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
                temp_v0_4 = ClsgClipEdgeToObject(sp324[var_s2], vu_2, sp340, 8);
                var_a0 = 0;
                asm volatile("lqc2 vf2, 0x390(%0)" : : "r"(sp));
                if (temp_v0_4 > 0) {
                    var_v1 = (f32 *)(sp + 0x50);
loop_23:
                    var_a0 += 1;
                    if (*var_v1 == 0.0f) {
                        var_v1 += 0x60;
                        if (var_a0 >= temp_v0_4) {
                            goto block_25;
                        }
                        goto loop_23;
                    }
                } else {
block_25:
                    var_s2 += 1;
                    if (var_s2 >= sp320) {
                        goto block_26;
                    }
                    goto loop_21;
                }
            } else {
block_26:
                var_s5 = 0;
                temp_s1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0x268);
                temp_s0_2 = temp_s1 + 0x90;
                func_001F38A8(temp_s1);
                sp350 = VecMinOfVerts(M2C_FIELD(temp_s1, s32 *, 0x90), M2C_FIELD(temp_s0_2, s32 *, 4));
                sp360 = VecMaxOfVerts(M2C_FIELD(temp_s1, s32 *, 0x90), M2C_FIELD(temp_s0_2, s32 *, 4));
                bevy_camera_follow_push_out(&B_003DD490, sp350, sp360, &FFilterOxa);
                if (sp320 > 0) {
                    var_a1_3 = sp324;
                    var_s2_2 = sp320;
                    do {
                        temp_v0_5 = *var_a1_3;
                        var_s2_2 -= 1;
                        var_a1_3 += 4;
                        temp_v1_3 = M2C_FIELD(temp_v0_5, s32 *, 0x6C);
                        var_s5 = (temp_v1_3 >= var_s5) ? temp_v1_3 : var_s5;
                    } while (var_s2_2 != 0);
                }
                temp_s5 = (var_s5 > 0x1554) ? 0x1555 : var_s5;
                var_s2_3 = 0;
                sp310 = temp_s5 * 0xC;
                M2C_FIELD(&sp310, s32 *, 4) = 0x10;
                temp_s6 = PvAllocStackImpl__Fi(&sp310, 0x10, &sp310);
                asm volatile("lqc2 vf1, 0x350(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf2" : : "r"(0x3F000000));
                asm volatile("lqc2 vf3, 0x360(%0)" : : "r"(sp));
                asm volatile("vmulax.xyzw ACC, vf1, vf2x");
                asm volatile("vmaddx.xyzw vf1, vf3, vf2x");
                asm volatile("sqc2 vf2, 0x310(%0)" : : "r"(sp));
                asm volatile("sqc2 vf1, 0x370(%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, 0x350(%0)" : : "r"(sp));
                asm volatile("lqc2 vf4, 0x370(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf1, vf4, vf2");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                temp_f20 = vu_3;
                if (sp320 > 0) {
loop_31:
                    temp_s0_3 = sp324[var_s2_3];
                    sp328 = 0;
                    if (M2C_FIELD(temp_s0_3, s64 *, 0x10) & (0x8000 << 0x22)) {
                        MarkSoContactsSphereBsp(&B_003DD490, temp_s0_3, temp_s1, 0);
                    } else {
                        sp32C = temp_s5;
                        sp330 = temp_s6;
                        if (PruneBsp__FP3BSPP6VECTORfPP3BSP(M2C_FIELD(temp_s0_3, s32 *, 0x74), 0x7FFFFFFF, sp370, &sp32C, temp_f20) == 2) {
                            temp_a3 = (sp330 - temp_s6) * 0xAAAAAAAB;
                            sp330 -= 0xC;
                            MarkSoContactsBspBsp(&B_003DD490, temp_s1, temp_s0_3, temp_a3 >> 2);
                        }
                    }
                    if (sp328 == 0) {
                        var_s2_3 += 1;
                        if (var_s2_3 >= sp320) {
                            goto block_39;
                        }
                        goto loop_31;
                    }
                    FreeSwMqList__FP2SWP2MQ(&B_003DD490, sp328);
                } else {
block_39:
                    SetAttachSubstate(arg0, 8);
                }
            }
            CStackFrame_Destructor(sp, 2);
            break;
        }
        goto block_80;
    case 9:                                         /* switch 1 */
        asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x14))));
        asm volatile("sqc2 vf1, 0x380(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x474))));
        asm volatile("lqc2 vf1, 0x380(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        var_v0_2 = 1;
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
        if (!(vu_4 < D_FLT_002BF5B4)) {
            var_v0_2 = 0;
        }
        if (var_v0_2 != 0) {
            Carry_Attach(arg0 + 0x440, M2C_FIELD(arg0, s8 **, 0x14));
            goto block_61;
        }
        goto block_80;
    case 10:                                        /* switch 1 */
        temp_a0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1030);
        if ((temp_a0 != 0) && (FAsegaGone(temp_a0, sp334) == 0)) {
            if ((D_FLT_002BF5B8 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 4))) && ((temp_a2_3 = M2C_FIELD(arg0, s8 **, 0), temp_v0_6 = M2C_FIELD(temp_a2_3, s8 **, 0x150), (M2C_FIELD(temp_v0_6, f32 *, 0x1C) > 0.0f)) || (M2C_FIELD(temp_v0_6, s32 *, 0x30) & 0xD0))) {
                temp_v0_7 = M2C_FIELD(temp_a2_3, s8 **, 0xC);
                M2C_FIELD(temp_v0_7, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x2C4)(temp_a2_3 + M2C_FIELD(temp_v0_7, s16 *, 0x2C0), 0, temp_a2_3);
                return;
            }
            goto block_80;
        }
        goto block_61;
    case 11:                                        /* switch 1 */
    case 12:                                        /* switch 1 */
        temp_a0_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1030);
        if (temp_a0_2 != 0) {
            if (FAsegaGone(temp_a0_2, sp334) != 0) {
                goto block_61;
            }
        } else {
            goto block_61;
        }
        goto block_80;
    case 5:                                         /* switch 1 */
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x14), 0xB) != 0) {
            var_a1_2 = 8;
            if (func_001423A0(M2C_FIELD(arg0, s8 **, 0)) != 0) {
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0xF5C) = (s8 *) M2C_FIELD(arg0, s8 **, 0x14);
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), f32 *, 0xF60) = (f32) M2C_FIELD(arg0, f32 *, 0x20);
                goto block_62;
            }
        }
        goto block_80;
    case 2:                                         /* switch 1 */
        if (GetJtPower(M2C_FIELD(arg0, s8 **, 0), sp334) > 0) {
            temp_a2_4 = M2C_FIELD(arg0, s8 **, 0);
            if (M2C_FIELD(temp_a2_4, s32 *, 0x10EC) == 4) {
                var_v0 = M2C_FIELD(temp_a2_4, s8 **, 0xC);
                var_a1_2 = 0;
                goto block_63;
            }
            if (!(B_002DFBC4 & 1) && !(M2C_FIELD(temp_s7, s32 *, 0x30) & GrfbtnJtGadget(temp_a2_4, 0x28, temp_a2_4))) {
                goto block_61;
            }
        } else {
            goto block_61;
        }
        goto block_80;
    default:                                        /* switch 1 */
        if (FButtonPressedWithin(temp_s7, 0x40, 0x3DCCCCCD) == 0) {
            if (GrfbtnVjoyPressedWithin(temp_s7, 0x400, 0x3E19999A) != 0) {
                temp_a2_5 = M2C_FIELD(arg0, s8 **, 0);
                temp_v1_4 = M2C_FIELD(temp_a2_5, s8 **, 0xC);
                if ((M2C_FIELD(temp_v1_4, s32 (**)(s8 *, M2C_UNK, s8 *), 0x31C)(temp_a2_5 + M2C_FIELD(temp_v1_4, s16 *, 0x318), 3, temp_a2_5) != 0) && ((temp_v1_5 = M2C_FIELD(arg0, s32 *, 8), (temp_v1_5 == 0)) || (temp_v1_5 == 0xD))) {
                    goto block_73;
                }
            }
            if ((M2C_FIELD(arg0, s32 *, 0x500) == 0) && !(B_002DFBC4 & 1) && !(M2C_FIELD(temp_s7, s32 *, 0x30) & 0x20)) {
                temp_a2_6 = M2C_FIELD(arg0, s8 **, 0);
                temp_v0_8 = M2C_FIELD(temp_a2_6, s8 **, 0xC);
                M2C_FIELD(temp_v0_8, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x2C4)(temp_a2_6 + M2C_FIELD(temp_v0_8, s16 *, 0x2C0), 0, temp_a2_6);
            }
        } else {
            goto block_67;
        }
        goto block_80;
    }
}
}
