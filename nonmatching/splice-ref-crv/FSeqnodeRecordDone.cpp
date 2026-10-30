typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
struct QV_1E3890 { float v[4]; };
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
static inline f32 BitsToFloat(s32 v) { union { s32 i; f32 f; } u; u.i = v; return u.f; }
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FSeqnodeRecordDone {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x80];
};                                                  /* size = 0x90 */
s32 CGc_FFindScreen(M2C_UNK *);
s32 ConsumeJoyButton(M2C_UNK *, s32);
s32 FAsegaGone(s8 *);
s32 FFloatsNear__Ffff(f32, f32, f32);
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);
s32 FJoyButtonPressed(M2C_UNK *, s32);
s32 FLoHasOid(s32, s32);
s32 FSggHasAlarm(s8 *, s32);
s32 FSmaRetracted(s32);
s32 FStreamPlaying(M2C_UNK *, s32);
s32 FVjoyButtonPressed(s8 *, s32);
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);
void GetSeqnodeObjectPosRad(s8 *, s8 *, M2C_UNK *, M2C_UNK);
s32 GetSmaCur(s32);
s32 GoalFollowCrv_FAtEnd(s32);
s32 GoalGotoPos_FArrived(s32);
void GoalStack_Clear(s32);
void JT_EndPose(s8 *);
s32 JT_FPosing(s32);
f32 MarkClockTickRealOnly__FP5CLOCK(M2C_UNK *);
s32 *PloFindSeqnodeObject(s8 *, s32);
s32 PosLoWorld(s8 *);
s32 PseqnodeFind(s8 *, s32, s8 *);
void ReleaseSeqnodeSma(s8 *);
void StopSeqnodeCameraMove(s8 *, s32);
f32 TStream(M2C_UNK *);
void bevy_player_p14_19e110(s32, M2C_UNK *);
s32 func_001423A0(s8 *);
s32 func_001424C0(s8 *);
s32 func_001424D0(s8 *);
s32 func_00142530(s8 *);
f32 func_001448F0(s8 *, M2C_UNK);
s32 func_00150F58(M2C_UNK *);
s32 func_00151018(M2C_UNK *);
s32 func_001510D8(M2C_UNK *);
s32 func_00171DA8(s32, s32);
void func_001E0070(s8 *, s32);
void func_001E5468(s8 *);
s32 func_00205458(s8 *, M2C_UNK);
s32 func_002121C8(s32);
extern M2C_UNK B_002DE460;
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_003DA530;
extern M2C_UNK B_003DD040;
extern s8 *B_003E133C;
extern s32 B_004435F8;
extern f32 RO_002BD850;
extern f32 RO_002C3620;
extern f32 RO_002C3624;
extern f32 RO_002C3628;
extern f32 RO_002C362C;
extern f32 g_2dded0;
extern f32 g_2ddf0c;
s32 FSeqnodeRecordDone(s8 *arg0, s8 *arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    f32 temp_f20;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f2_4;
    QV_1E3890 temp_s0;
    QV_1E3890 temp_s1_3;
    s32 *var_s1;
    s32 temp_a0;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a1_3;
    s32 temp_v0;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_a0_7;
    s32 var_a1;
    s32 var_condition_bit;
    s32 var_f1;
    s32 var_s2;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u64 temp_v0_9;
    s8 *temp_a0_10;
    s8 *temp_a0_11;
    s8 *temp_a0_12;
    s8 *temp_a0_13;
    s8 *temp_a0_14;
    s8 *temp_a0_15;
    s8 *temp_a0_16;
    s8 *temp_a0_17;
    s8 *temp_a0_18;
    s8 *temp_a0_19;
    s8 *temp_a0_20;
    s8 *temp_a0_21;
    s8 *temp_a0_22;
    s8 *temp_a0_23;
    s8 *temp_a0_24;
    s8 *temp_a0_2;
    s8 *temp_a0_5;
    s8 *temp_a0_6;
    s8 *temp_a0_7;
    s8 *temp_a0_8;
    s8 *temp_a0_9;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *temp_a1_4;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a2_3;
    s8 *temp_s1;
    s8 *temp_s1_2;
    s8 *temp_v0_10;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_8;
    s8 *temp_v1_3;
    s8 *var_s0;
    s8 *var_v1;
    temp_v0 = M2C_FIELD(arg1, s32 *, 0);
    switch (temp_v0) {
    case 0x3:
        var_s2 = 1;
        var_s4 = 0;
        var_s1 = (s32 *)(arg1 + 0x14);
loop_5:
        if (var_s4 < M2C_FIELD(arg1, s32 *, 0x10)) {
            var_s1 += 4;
            if (PseqnodeFind(M2C_FIELD(arg0, s8 **, 0x14), *var_s1, arg0) != 0) {
                var_s2 = 0;
            } else {
                var_s4 += 1;
                goto loop_5;
            }
        }
block_213:
        var_v0 = var_s2;
        break;
    case 0x4:
        var_s2 = FSggHasAlarm(M2C_FIELD(arg0, s8 **, 0x14), M2C_FIELD(arg1, s32 *, 0x10));
        var_v0 = var_s2;
        if (var_s2 != 0) {
            var_v0 = var_s2;
            if (M2C_FIELD(arg1, s32 *, 0x14) != 0) {
                func_001E0070(M2C_FIELD(arg0, s8 **, 0x14), M2C_FIELD(arg1, s32 *, 0x10));
                goto block_213;
            }
        }
        break;
    case 0xA:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x54);
        if (temp_a0 != 0) {
            var_v0 = 0;
            if (JT_FPosing(temp_a0) == 0) {
                M2C_FIELD(arg0, s32 *, 0x54) = 0;
            default:
block_212:
                var_s2 = 1;
                goto block_213;
            }
        } else {
            temp_a0_2 = M2C_FIELD(arg0, s8 **, 0x4C);
            if ((temp_a0_2 != NULL) && (FAsegaGone(temp_a0_2) != 0)) {
                temp_a1 = M2C_FIELD(arg0, s8 **, 0x4C);
                temp_v0_2 = M2C_FIELD(temp_a1, s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *), 0x14)(temp_a1 + M2C_FIELD(temp_v0_2, s16 *, 0x10), temp_a1);
                M2C_FIELD(arg0, s8 **, 0x4C) = NULL;
            }
            var_s2 = M2C_FIELD(arg0, s8 **, 0x4C) == NULL;
            goto block_213;
        }
        break;
    case 0xB:
        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0x50);
        var_s2 = temp_v0_3 == NULL;
        if (temp_v0_3 != NULL) {
            if (M2C_FIELD(temp_v0_3, s32 *, 0x74) == 0) {
                M2C_FIELD(arg0, s8 **, 0x50) = NULL;
            }
            var_s2 = M2C_FIELD(arg0, s8 **, 0x50) == NULL;
        }
        goto block_213;
    case 0xD:
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x58);
        if ((temp_a0_3 != 0) && ((FSmaRetracted(temp_a0_3) != 0) || (M2C_FIELD(arg0, s32 *, 0x5C) != 0))) {
            ReleaseSeqnodeSma(arg0);
        }
        var_s2 = M2C_FIELD(arg0, s32 *, 0x58) == 0;
        goto block_213;
    case 0xE:
        temp_a0_4 = M2C_FIELD(arg0, s32 *, 0x64);
        if ((temp_a0_4 != 0) && (func_002121C8(temp_a0_4) != 0)) {
            func_001E5468(arg0);
        }
        var_s2 = M2C_FIELD(arg0, s32 *, 0x64) == 0;
        goto block_213;
    case 0x1A:
        temp_a0_5 = M2C_FIELD(arg0, s8 **, 0x44);
        if (temp_a0_5 != NULL) {
            bevy_player_p14_19e110((int)(temp_a0_5 + 0xF50), (M2C_UNK *)(sp));
            var_condition_bit = fabsf(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x44), f32 *, 0xF60) - GLimitLm__FP2LMf((M2C_UNK *)(sp), M2C_FIELD(arg0, f32 *, 0x7C))) < BitsToFloat(M2C_FIELD(arg1, s32 *, 0x14));
block_174:
            var_v0 = 1;
            if (!var_condition_bit) {
                var_s2 = 0;
                goto block_213;
            }
        } else {
            goto block_212;
        }
        break;
    case 0x1B:
        temp_a0_6 = M2C_FIELD(arg0, s8 **, 0x24);
        var_s2 = 1;
        if ((temp_a0_6 != NULL) && (var_s2 = 1, (FIsBasicDerivedFrom(temp_a0_6, 0x34) != 0)) && (temp_a2 = M2C_FIELD(arg0, s8 **, 0x24), var_s2 = 0, (((u32) (M2C_FIELD(temp_a2, s32 *, 0x2DC) - 0xB) < 3U) == 0)) && (var_s2 = 1, (M2C_FIELD(temp_a2, s32 *, 0x4CC) != -1))) {
            temp_v1 = M2C_FIELD(temp_a2, s32 *, 0x4C8);
            if ((temp_v1 == 0) || (var_v0 = 1, (temp_v1 == 0xD))) {
                temp_v0_4 = M2C_FIELD(temp_a2, s8 **, 0xC);
                var_s2 = 1;
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x2C4)(temp_a2 + M2C_FIELD(temp_v0_4, s16 *, 0x2C0), 0, temp_a2);
                goto block_213;
            }
        } else {
            goto block_213;
        }
        break;
    case 0x1C:
        temp_a0_7 = M2C_FIELD(arg0, s8 **, 0x24);
        var_s2 = 1;
        if (temp_a0_7 != NULL) {
            if (FIsBasicDerivedFrom(temp_a0_7, 0x35) != 0) {
                temp_v1_2 = M2C_FIELD(arg1, s32 *, 0x14);
                temp_a0_8 = M2C_FIELD(arg0, s8 **, 0x24);
                if (temp_v1_2 != 4) {
                    if (temp_v1_2 < 5) {
                        var_s2 = 1;
                        if (temp_v1_2 != 2) {
                        } else {
                            var_v0_2 = M2C_FIELD(temp_a0_8, s32 *, 0x18D8);
block_211:
                            var_s2 = ~var_v0_2 == 0;
                        }
                    } else {
                        var_s2 = 1;
                        if (temp_v1_2 != 8) {
                        } else {
                            var_s2 = M2C_FIELD(temp_a0_8, s32 *, 0x18C8) != 9;
                        }
                    }
                } else {
                    var_s2 = M2C_FIELD(temp_a0_8, s32 *, 0x18C8) != 2;
                }
            } else {
                goto block_212;
            }
        }
        goto block_213;
    case 0x1D:
    case 0x21:
        temp_a0_9 = M2C_FIELD(arg0, s8 **, 0x44);
        var_s2 = 1;
        if (temp_a0_9 != NULL) {
            var_s2 = func_001423A0(temp_a0_9);
        }
        goto block_213;
    case 0x1E:
        temp_a0_10 = M2C_FIELD(arg0, s8 **, 0x44);
        var_s2 = 1;
        if (temp_a0_10 != NULL) {
            var_s2 = func_001424C0(temp_a0_10);
        }
        goto block_213;
    case 0x1F:
        temp_a0_11 = M2C_FIELD(arg0, s8 **, 0x44);
        var_s2 = 1;
        if (temp_a0_11 != NULL) {
            var_s2 = func_001424D0(temp_a0_11);
        }
        goto block_213;
    case 0x22:
        temp_a0_12 = M2C_FIELD(arg0, s8 **, 0x44);
        var_s2 = 1;
        if (temp_a0_12 != NULL) {
            var_s2 = func_00142530(temp_a0_12);
        }
        goto block_213;
    case 0x23:
        var_a0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x40);
        if ((var_a0 ^ 1) & 1) {
            var_a0 = *(s32 *)var_a0;
        }
        if (var_a0 & 0x100) {
            var_f2 = g_2ddf0c;
        } else {
            var_f2 = g_2dded0;
        }
        var_f1 = M2C_FIELD(arg1, s32 *, 0x10);
block_173:
        var_condition_bit = BitsToFloat(var_f1) < (var_f2 - M2C_FIELD(arg0, f32 *, 0x34));
        goto block_174;
    case 0x24:
        temp_s1 = M2C_FIELD(arg0, s8 **, 0x44);
        var_s2 = 1;
        if (temp_s1 != NULL) {
            temp_v0_5 = (s8 *)(PloFindSeqnodeObject(arg0, M2C_FIELD(arg1, s32 *, 0x10)));
            if (temp_v0_5 != NULL) {
                GetSeqnodeObjectPosRad(arg0, temp_v0_5, (M2C_UNK *)(sp + 0x10), 0);
                var_s2 = 1;
                asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s1)));
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf1, vf3, vf2");
                asm volatile("vmul.xy vf1, vf1, vf1");
                asm volatile("vaddy.x vf1, vf1, vf1y");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                if (!(vu_1 < M2C_FIELD(arg1, f32 *, 0x18))) {
                    var_s2 = 0;
                }
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
                func_001448F0(temp_s1 + 0xFD0, vu_2);
            } else {
                var_s2 = 1;
            }
            if (var_s2 != 0) {
                var_v0 = var_s2;
                if (M2C_FIELD(arg1, s32 *, 0x20) != -1) {
                    JT_EndPose(temp_s1);
                    goto block_213;
                }
            } else {
                goto block_213;
            }
        } else {
            goto block_213;
        }
        break;
    case 0x27:
        temp_a0_13 = M2C_FIELD(arg0, s8 **, 0x24);
        var_s2 = 1;
        if (temp_a0_13 != NULL) {
            if (FIsBasicDerivedFrom(temp_a0_13, 0x34) != 0) {
                var_s2 = 0;
                temp_v0_6 = func_00205458(M2C_FIELD(arg0, s8 **, 0x24), 0xA8);
                if (temp_v0_6 != 0) {
                    var_v0_3 = GoalFollowCrv_FAtEnd(temp_v0_6);
block_82:
                    if (var_v0_3 != 0) {
                        goto block_83;
                    }
                } else {
block_83:
                    var_s2 = 1;
                }
block_84:
                var_v0 = var_s2;
                if (var_s2 != 0) {
                    GoalStack_Clear((int)(M2C_FIELD(arg0, s8 **, 0x24) + 0x26C));
                    var_v0 = var_s2;
                    if (M2C_FIELD(arg1, s32 *, 0x24) != -1) {
                        JT_EndPose(M2C_FIELD(arg0, s8 **, 0x24));
                        goto block_213;
                    }
                }
            } else {
                goto block_212;
            }
        } else {
            goto block_213;
        }
        break;
    case 0x28:
        temp_a0_14 = M2C_FIELD(arg0, s8 **, 0x24);
        var_s2 = 1;
        if (temp_a0_14 != NULL) {
            if (FIsBasicDerivedFrom(temp_a0_14, 0x34) != 0) {
                var_s2 = 0;
                temp_v0_7 = func_00205458(M2C_FIELD(arg0, s8 **, 0x24), 0xC1);
                if (temp_v0_7 != 0) {
                    var_v0_3 = GoalGotoPos_FArrived(temp_v0_7);
                    goto block_82;
                }
                goto block_83;
                goto block_84;
            }
            goto block_212;
        }
        goto block_213;
    case 0x29:
        temp_s1_2 = M2C_FIELD(arg0, s8 **, 0x44);
        if ((temp_s1_2 != NULL) && (M2C_FIELD(temp_s1_2, s32 *, 0x4CC) != -1)) {
            var_s2 = 1;
            if (M2C_FIELD(temp_s1_2, s32 *, 0x4C8) == 8) {
                temp_v0_8 = (s8 *)(PloFindSeqnodeObject(arg0, M2C_FIELD(arg1, s32 *, 0x10)));
                if (temp_v0_8 != NULL) {
                    GetSeqnodeObjectPosRad(arg0, temp_v0_8, (M2C_UNK *)sp, 0);
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s1_2)));
                    asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                    asm volatile("vsub.xyzw vf1, vf3, vf2");
                    asm volatile("vmul.xy vf1, vf1, vf1");
                    asm volatile("vaddy.x vf1, vf1, vf1y");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_3;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                    var_condition_bit = vu_3 < M2C_FIELD(arg1, f32 *, 0x18);
                    goto block_174;
                }
                goto block_212;
            }
            goto block_213;
        }
        goto block_212;
    case 0x2A:
        temp_a0_15 = M2C_FIELD(arg0, s8 **, 0x44);
        var_s2 = 1;
        if (temp_a0_15 != NULL) {
            var_v0_2 = M2C_FIELD(temp_a0_15, s32 *, 0x2DC);
            goto block_211;
        }
        goto block_213;
    case 0x2B:
        temp_a0_16 = M2C_FIELD(arg0, s8 **, 0x24);
        var_s2 = 1;
        if (temp_a0_16 != NULL) {
            var_s2 = 1;
            if (FIsBasicDerivedFrom(temp_a0_16, 0x34) != 0) {
                var_v1 = M2C_FIELD(arg0, s8 **, 0x24);
block_210:
                var_v0_2 = M2C_FIELD(var_v1, s32 *, 0x2DC);
                goto block_211;
            }
        }
        goto block_213;
    case 0x2C:
    case 0x2D:
        temp_a0_17 = M2C_FIELD(arg0, s8 **, 0x60);
        if (temp_a0_17 != NULL) {
            temp_v0_9 = M2C_FIELD(temp_a0_17, u64 *, 0x28);
            if (M2C_FIELD(arg1, s32 *, 0) == 0x2C) {
                if (((temp_v0_9 >> 0x3C) & 1) && (M2C_FIELD(temp_a0_17, f32 *, 0x12C) == 1.0f)) {
                    goto block_103;
                }
            } else if (!((temp_v0_9 >> 0x3C) & 1)) {
block_103:
                M2C_FIELD(arg0, s8 **, 0x60) = NULL;
            }
        }
        var_s2 = M2C_FIELD(arg0, s8 **, 0x60) == NULL;
        goto block_213;
    case 0x32:
        var_a0_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x40);
        if ((var_a0_2 ^ 1) & 1) {
            var_a0_2 = *(s32 *)var_a0_2;
        }
        if (var_a0_2 & 0x100) {
            var_f2 = g_2ddf0c;
        } else {
            var_f2 = g_2dded0;
        }
        var_f1 = *(s32 *)&RO_002BD850;
        goto block_173;
    case 0x33:
        var_a0_3 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x40);
        if ((var_a0_3 ^ 1) & 1) {
            var_a0_3 = *(s32 *)var_a0_3;
        }
        if (var_a0_3 & 0x100) {
            var_f2 = g_2ddf0c;
        } else {
            var_f2 = g_2dded0;
        }
        var_f1 = M2C_FIELD(arg1, s32 *, 0x10);
        goto block_173;
    case 0x39:
        var_s2 = 1;
        if (!(M2C_FIELD(arg0, f32 *, 0x80) <= g_2dded0)) {
            var_s2 = 0;
        }
        var_v0 = var_s2;
        if (var_s2 != 0) {
            if (M2C_FIELD(arg1, s32 *, 0x40) == 0) {
                M2C_FIELD(arg0, s32 *, 0x9C) = 0;
            } else {
                StopSeqnodeCameraMove(arg0, M2C_FIELD(arg1, s32 *, 0x44));
            }
            goto block_213;
        }
        break;
    case 0x3B:
        temp_a0_18 = M2C_FIELD(arg0, s8 **, 0xA0);
        var_s2 = 1;
        if (temp_a0_18 != NULL) {
            var_s2 = M2C_FIELD(temp_a0_18, s32 *, 0xF28) == 1;
        }
        goto block_213;
    case 0x3C:
        temp_a0_19 = M2C_FIELD(arg0, s8 **, 0xA0);
        var_s2 = 1;
        if (temp_a0_19 != NULL) {
            var_v0_2 = M2C_FIELD(temp_a0_19, s32 *, 0xF28);
            goto block_211;
        }
        goto block_213;
    case 0x3D:
        var_s2 = func_00150F58(&B_002DE460);
        goto block_213;
    case 0x3E:
        var_s2 = func_00151018(&B_002DE460);
        goto block_213;
    case 0x40:
        var_s2 = func_001510D8(&B_002DE460);
        goto block_213;
    case 0x42:
        if (M2C_FIELD(arg1, s32 *, 0x14) == -1) {
            var_s2 = FJoyButtonPressed(&B_002DFC00, M2C_FIELD(arg1, s32 *, 0x10));
            goto block_143;
        }
        var_s0 = B_003E133C;
loop_134:
        if (var_s0 != NULL) {
            if (FLoHasOid(M2C_FIELD(var_s0, s32 *, 0x7C), M2C_FIELD(arg1, s32 *, 0x14)) == 0) {
                var_s0 = M2C_FIELD(var_s0, s8 **, 0x84);
                goto loop_134;
            }
            var_s2 = 0;
            if ((var_s0 == NULL) || (FVjoyButtonPressed(var_s0, M2C_FIELD(arg1, s32 *, 0x10)) != 0)) {
                goto block_140;
            }
        } else {
block_140:
            var_s2 = 1;
        }
        if (var_s2 != 0) {
            ConsumeJoyButton(&B_002DFC00, M2C_FIELD(arg1, s32 *, 0x10));
block_143:
            if (var_s2 != 0) {
                B_004435F8 = 0;
            }
        }
        goto block_213;
    case 0x43:
        temp_a0_20 = M2C_FIELD(arg0, s8 **, 0x24);
        var_s2 = 1;
        if (temp_a0_20 != NULL) {
            var_s2 = 1;
            if (FIsBasicDerivedFrom(temp_a0_20, 0x34) != 0) {
                temp_a1_2 = M2C_FIELD(arg0, s8 **, 0x24);
                temp_v1_3 = M2C_FIELD(temp_a1_2, s8 **, 0xC);
                var_s2 = M2C_FIELD(temp_v1_3, s32 (**)(s8 *, s8 *), 0x2CC)(temp_a1_2 + M2C_FIELD(temp_v1_3, s16 *, 0x2C8), temp_a1_2) == M2C_FIELD(arg1, s32 *, 0x10);
            }
        }
        goto block_213;
    case 0x44:
        var_s2 = CGc_FFindScreen(&B_003DA530) == 0;
        goto block_213;
    case 0x45:
        var_s2 = FStreamPlaying(&B_003DD040, M2C_FIELD(arg1, s32 *, 0x10)) == 0;
        goto block_213;
    case 0x52:
        temp_a0_21 = M2C_FIELD(arg0, s8 **, 0x68);
        var_a1 = -1;
        if (temp_a0_21 != NULL) {
            var_a1 = M2C_FIELD(temp_a0_21, s32 *, 0x10);
        }
        var_s2 = 1;
        if (FStreamPlaying(&B_003DD040, var_a1) != 0) {
            var_s2 = 0;
            if (!(BitsToFloat(M2C_FIELD(arg1, s32 *, 0x10)) < 0.0f)) {
                var_condition_bit = (TStream(&B_003DD040) - BitsToFloat(M2C_FIELD(arg1, s32 *, 0x10))) >= 0.0f;
                goto block_174;
            }
        }
        goto block_213;
    case 0x4A:
        var_condition_bit = BitsToFloat(M2C_FIELD(arg1, s32 *, 0x10)) <= MarkClockTickRealOnly__FP5CLOCK(&B_003DD040);
        goto block_174;
    case 0x4E:
        var_condition_bit = BitsToFloat(M2C_FIELD(arg1, s32 *, 0x10)) <= MarkClockTickRealOnly__FP5CLOCK(&B_003DD040);
        goto block_174;
    case 0x4F:
        var_s2 = 0;
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x24), 0x36) != 0) {
            temp_a0_22 = M2C_FIELD(arg0, s8 **, 0x24);
            if (M2C_FIELD(temp_a0_22, s32 *, 0x13D0) == 6) {
                var_v0 = 0;
                if (M2C_FIELD(arg1, s32 *, 0x1C) != -1) {
                    var_s2 = GetSmaCur(M2C_FIELD(temp_a0_22, s32 *, 0x1034)) == M2C_FIELD(arg1, s32 *, 0x1C);
                    goto block_213;
                }
            } else {
                goto block_212;
            }
        } else {
            goto block_213;
        }
        break;
    case 0x50:
        temp_a0_23 = M2C_FIELD(arg0, s8 **, 0x44);
        if (temp_a0_23 != NULL) {
            var_v0 = 0;
            if (M2C_FIELD(temp_a0_23, s32 *, 0x13D0) == 6) {
                goto block_212;
            }
        } else {
            goto block_212;
        }
        break;
    case 0x51:
        temp_a0_24 = M2C_FIELD(arg0, s8 **, 0x44);
        if (temp_a0_24 != NULL) {
            var_v0 = 0;
            if (M2C_FIELD(temp_a0_24, s32 *, 0x13D0) != 6) {
                goto block_212;
            }
        } else {
            goto block_212;
        }
        break;
    case 0x53:
        var_a0_4 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x40);
        if ((var_a0_4 ^ 1) & 1) {
            var_a0_4 = *(s32 *)var_a0_4;
        }
        if (var_a0_4 & 0x100) {
            var_f2 = g_2ddf0c;
        } else {
            var_f2 = g_2dded0;
        }
        var_f1 = M2C_FIELD(arg1, s32 *, 0x14);
        goto block_173;
    case 0x55:
        temp_a1_3 = M2C_FIELD(arg0, s32 *, 0xDC);
        if ((temp_a1_3 != 0) && (func_00171DA8(M2C_FIELD(arg0, s32 *, 0xD8), temp_a1_3) == 0)) {
            M2C_FIELD(arg0, s32 *, 0xD8) = 0;
            M2C_FIELD(arg0, s32 *, 0xDC) = 0;
        }
        var_s2 = M2C_FIELD(arg0, s32 *, 0xDC) == 0;
        goto block_213;
    case 0x58:
        var_s2 = 1;
        if (M2C_FIELD(arg0, s8 **, 0x44) != NULL) {
            temp_a1_4 = (s8 *)PloFindSeqnodeObject(arg0, M2C_FIELD(arg1, s32 *, 0x10));
            var_a0_5 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x40);
            if ((var_a0_5 ^ 1) & 1) {
                var_a0_5 = *(s32 *)var_a0_5;
            }
            if (var_a0_5 & 0x100) {
                var_f2_2 = g_2ddf0c;
            } else {
                var_f2_2 = g_2dded0;
            }
            var_s2 = 1;
            if (!(RO_002C3620 < (var_f2_2 - M2C_FIELD(arg0, f32 *, 0x34)))) {
                temp_v1_4 = M2C_FIELD(temp_a1_4, s32 *, 0x1914);
                var_s2 = 0;
                if (temp_v1_4 < 7) {
                    var_s2 = temp_v1_4 >= 4;
                }
            }
        }
        goto block_213;
    case 0x59:
        temp_a2_2 = M2C_FIELD(arg0, s8 **, 0x44);
        var_s2 = 1;
        if (temp_a2_2 != NULL) {
            var_a0_6 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x40);
            if ((var_a0_6 ^ 1) & 1) {
                var_a0_6 = *(s32 *)var_a0_6;
            }
            if (var_a0_6 & 0x100) {
                var_f2_3 = g_2ddf0c;
            } else {
                var_f2_3 = g_2dded0;
            }
            var_s2 = 1;
            if (!(RO_002C3624 < (var_f2_3 - M2C_FIELD(arg0, f32 *, 0x34)))) {
                temp_s1_3 = M2C_FIELD(temp_a2_2, QV_1E3890 *, 0x19F0);
                temp_f20 = RO_002C3628;
                temp_s0 = M2C_FIELD(temp_a2_2, QV_1E3890 *, 0x1A20);
                var_v0 = 0;
                if (FFloatsNear__Ffff(temp_s0.v[0], temp_s1_3.v[0], temp_f20) != 0) {
                    var_v0 = 0;
                                        if (FFloatsNear__Ffff(temp_s0.v[1], temp_s1_3.v[1], temp_f20) != 0) {
                                                                        var_s2 = FFloatsNear__Ffff(temp_s0.v[2], temp_s1_3.v[2], temp_f20) != 0;
                        goto block_213;
                    }
                }
            } else {
                goto block_213;
            }
        } else {
            goto block_213;
        }
        break;
    case 0x5A:
        temp_a2_3 = M2C_FIELD(arg0, s8 **, 0x44);
        var_s2 = 1;
        if (temp_a2_3 != NULL) {
            var_a0_7 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x40);
            if ((var_a0_7 ^ 1) & 1) {
                var_a0_7 = *(s32 *)var_a0_7;
            }
            if (var_a0_7 & 0x100) {
                var_f2_4 = g_2ddf0c;
            } else {
                var_f2_4 = g_2dded0;
            }
            var_s2 = 1;
            if (!(RO_002C362C < (var_f2_4 - M2C_FIELD(arg0, f32 *, 0x34)))) {
                temp_v1_5 = M2C_FIELD(temp_a2_3, s32 *, 0x1914);
                var_s2 = 0;
                if ((u32) (temp_v1_5 + 1) < 2U) {
                    if (temp_v1_5 == 0) {
                        temp_v0_10 = M2C_FIELD(temp_a2_3, s8 **, 0xC);
                        M2C_FIELD(temp_v0_10, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x2C4)(temp_a2_3 + M2C_FIELD(temp_v0_10, s16 *, 0x2C0), 0, temp_a2_3);
                    }
                    var_v1 = (s8 *)M2C_FIELD(arg1, s32 *, 0x18);
                    goto block_210;
                }
            }
        }
        goto block_213;
    }
    return var_v0;
}
}
