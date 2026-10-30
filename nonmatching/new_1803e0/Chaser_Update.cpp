typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Chaser_Update {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x10];
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x038 */ s32 sp38;                           /* overlap; inferred */
    /* 0x040 */ s8 *sp40;                         /* inferred */
    /* 0x044 */ char pad44[0x10C];                  /* maybe part of sp40[0x44]? */
    /* 0x150 */ s128 sp150;                         /* inferred */
    /* 0x160 */ s128 sp160;                         /* inferred */
    /* 0x170 */ s128 sp170;                         /* inferred */
    /* 0x180 */ s128 sp180;                         /* inferred */
    /* 0x190 */ char pad190[0xC0];
};                                                  /* size = 0x250 */
#define sp20 (*(s128 *)(sp + 0x020))
#define sp180 (*(s128 *)(sp + 0x180))
void Chaser_SetState(s8 *, s32);
s32 ConvertXfVec(M2C_UNK, s32, M2C_UNK);
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 FCheckLm__FP2LMf(s8 *, f32);
s32 FFindPathzoneCrv(s32, s128, s128, s32);
void FindCrvClosestPointFromS(s32, s128, M2C_UNK, s8 *, f32);
f32 GetSuck(M2C_UNK *);
s32 LimitVectorLength__FP6VECTORfT0(s128, f32);
s32 PosLoWorld(s8 *);
f32 RadNormalize__Ff(f32);
f32 SMaxCrv(s32);
void UpdateSo();
f32 atan2f(f32, s32);
s32 bevy_camera_follow_track_heading_weight(M2C_UNK, s8 *, s128);
s32 func_0017F550(s8 *);
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003DD490;
extern s32 D_002BE828;
extern f32 D_FLT_002BE820;
extern f32 D_FLT_002BE824;
extern M2C_UNK D_FLT_002BE830;
extern M2C_UNK D_FLT_002BE840;
extern M2C_UNK D_FLT_002BE850;
extern M2C_UNK D_FLT_002BE860;
extern s128 g_2a2da0;
extern s128 g_2a2dd0;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded0;
#define sp10 (*(M2C_UNK *)(sp + 0x10))
#define sp30 (*(s128 *)(sp + 0x30))
#define sp38 (*(s32 *)(sp + 0x38))
#define sp40 (*(s8 * *)(sp + 0x40))
#define sp150 (*(s128 *)(sp + 0x150))
#define sp160 (*(s128 *)(sp + 0x160))
#define sp170 (*(s128 *)(sp + 0x170))
#define unksp24 (*(s32 *)(sp + 0x24))
void Chaser_Update(s8 *arg0) {
    s8 sp[0x1A0] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f7;
    f32 temp_v1_5;
    f32 temp_v1_6;
    f32 var_f0;
    f32 var_f2;
    f32 var_f3;
    f32 var_f3_2;
    f32 var_f6;
    f32 var_f6_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 var_a0;
    s32 var_s0;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_2;
    u32 temp_v1;
    u32 temp_v1_2;
    s8 **var_s2_2;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v0_4;
    s8 *temp_v0_6;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *var_s2;
    UpdateSo();
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x1C0);
    if ((temp_v1 == 2) || (temp_v1 == 4)) {
        if (func_0017F550(arg0) != 0) {
            Chaser_SetState(arg0, 0);
        }
    }
    if ((M2C_FIELD(arg0, u32 *, 0x1C0) != 0) && (M2C_FIELD(arg0, u32 *, 0x1C0) != 4)) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0x1D4);
        if (temp_v0 != NULL) {
            if (!(((u64) M2C_FIELD(temp_v0, u64 *, 0x28) >> 0x3C) & 1)) {
                goto block_10;
            }
        } else {
block_10:
            Chaser_SetState(arg0, 0);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x1CC) == 0) {
        temp_a0 = M2C_FIELD(arg0, s8 **, 0x1D4);
        if ((temp_a0 != NULL) && (((u64) M2C_FIELD(temp_a0, u64 *, 0x28) >> 0x3C) & 1)) {
            temp_s0 = arg0 + ((M2C_FIELD(arg0, u32 *, 0x1C0) * 0x28) + 0x270);
            asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(temp_a0)));
            asm volatile("sqc2 vf1, 0x190(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x190(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0)));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            asm volatile("vmul.xyz vf2, vf1, vf1");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf3, vf2z");
            asm volatile("vsqrt Q, vf2x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf2, vf0, Q");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
            temp_f21 = vu_1;
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
            temp_v0_2 = bevy_camera_follow_track_heading_weight(0, arg0, vu_2);
            s64 vu_3;
            asm volatile("prot3w %0, %1" : "=r"(vu_3) : "r"(temp_v0_2));
            temp_f20 = RadNormalize__Ff(atan2f(vu_3, temp_v0_2));
            if (M2C_FIELD(temp_s0, s32 *, 0) == 0) {
                var_v0 = M2C_FIELD(temp_s0, s32 *, 4);
            } else {
                var_v0 = FCheckLm__FP2LMf(temp_s0 + 0x10, temp_f21);
            }
            var_s3 = 4;
            if (var_v0 != 0) {
                if ((M2C_FIELD(temp_s0, s32 *, 4) != 0) && (FCheckLm__FP2LMf(temp_s0 + 0x20, temp_f20) == 0)) {
                    var_s3 = 4;
                    goto block_21;
                }
            } else {
block_21:
                var_s2 = arg0 + 0x310;
loop_23:
                if (var_s3 > 0) {
                    if (M2C_FIELD(var_s2, s32 *, 0) == 0) {
                        var_v0_2 = M2C_FIELD(var_s2, s32 *, 4);
                    } else {
                        var_v0_2 = FCheckLm__FP2LMf(var_s2 + 8, temp_f21);
                    }
                    if (var_v0_2 == 0) {
                        var_s2 -= 0x28;
                        goto block_22;
                    }
                    if (M2C_FIELD(var_s2, s32 *, 4) != 0) {
                        if (FCheckLm__FP2LMf(var_s2 + 0x18, temp_f20) == 0) {
                            var_s2 -= 0x28;
block_22:
                            var_s3 -= 1;
                            goto loop_23;
                        }
                    }
                }
                Chaser_SetState(arg0, var_s3);
            }
        }
    }
    temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x1C0);
    switch (temp_v1_2) {
    case 1:
    case 2:
        if (M2C_FIELD(arg0, s32 *, 0x1C8) == 0) {
            temp_s0_2 = M2C_FIELD(arg0, s8 **, 0x5C);
            sp150 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x1D4));
            asm volatile("lqc2 vf1, 0x150(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0)));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            s32 vu_4;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
            temp_v0_3 = ConvertXfVec(0, M2C_FIELD(temp_s0_2, s32 *, 0xA0), vu_4);
            s64 vu_5;
            asm volatile("prot3w %0, %1" : "=r"(vu_5) : "r"(temp_v0_3));
            temp_f0 = RadNormalize__Ff(atan2f(vu_5, temp_v0_3));
            temp_v0_4 = arg0 + 0x360;
            temp_f4 = M2C_FIELD(arg0, f32 *, 0x370);
            var_f3 = M2C_FIELD(arg0, f32 *, 0x360) + (temp_f0 * (M2C_FIELD(temp_v0_4, f32 *, 4) + (temp_f0 * M2C_FIELD(temp_v0_4, f32 *, 8))));
            temp_f5 = M2C_FIELD(arg0, f32 *, 0x374);
            if (var_f3 < temp_f4) {
                var_f3 = temp_f4;
            } else if (temp_f5 < var_f3) {
                var_f3 = temp_f5;
            }
            M2C_FIELD(arg0, f32 *, 0x204) = var_f3;
        default:
        case 0:
        case 4:
            ;
        }
        break;
    case 3:
        sp160 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x1D4));
        sp170 = PosLoWorld(arg0);
        temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v1_3, M2C_UNK (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x108));
        asm volatile("lqc2 vf2, 0x160(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x1f0(%0)" : : "r"(arg0));
        var_a0 = 0;
        asm volatile("vsub.xyzw vf1, vf2, vf1");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_6;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_6));
        asm volatile("lqc2 vf1, 0x1e0(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf2, 0x170(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf2, vf1");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_7;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_7));
        if ((D_FLT_002BE820 < vu_7) || (D_FLT_002BE820 < vu_6) || (D_FLT_002BE824 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x200)))) {
            var_a0 = 1;
        }
        if (var_a0 != 0) {
            FFindPathzoneCrv(M2C_FIELD(arg0, s32 *, 0x1D0), sp170, sp160, M2C_FIELD(arg0, s32 *, 0x1D8));
            M2C_FIELD(arg0, f32 *, 0x1DC) = 0.0f;
            M2C_FIELD(arg0, s128 *, 0x1F0) = sp160;
            M2C_FIELD(arg0, s128 *, 0x1E0) = sp170;
            M2C_FIELD(arg0, f32 *, 0x200) = (f32) g_2dded0;
        }
        FindCrvClosestPointFromS(M2C_FIELD(arg0, s32 *, 0x1D8), sp170, 0, sp, M2C_FIELD(arg0, f32 *, 0x1DC));
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(D_002BE828));
        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("vadda.xyzw ACC, vf0, vf2");
        asm volatile("vmaddx.xyzw vf2, vf1, vf3x");
        asm volatile("lqc2 vf1, 0x170(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf4, vf2, vf1");
        asm volatile("vmul.xyz vf1, vf4, vf4");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(sp));
        s32 vu_8;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_8));
        if (vu_8 < 0.0001f) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2dd0));
        } else {
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf1, vf4, Q");
        }
        asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
        temp_f20_2 = SMaxCrv(M2C_FIELD(arg0, s32 *, 0x1D8)) - M2C_FIELD(arg0, f32 *, 0x1DC);
        temp_v0_5 = bevy_camera_follow_track_heading_weight(0, arg0, sp20);
        s64 vu_9;
        asm volatile("prot3w %0, %1" : "=r"(vu_9) : "r"(temp_v0_5));
        temp_f21_2 = atan2f(vu_9, temp_v0_5);
        temp_v1_4 = arg0 + 0x340;
        temp_f7 = GetSuck(&B_002DE578);
        temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x340) + (temp_f20_2 * (M2C_FIELD(temp_v1_4, f32 *, 4) + (temp_f20_2 * M2C_FIELD(temp_v1_4, f32 *, 8))));
        if (temp_f0_2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f6 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f6 = temp_f0_2;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f0_2) {
                var_f6 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        temp_v0_6 = arg0 + 0x350;
        var_f3_2 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        temp_f0_3 = M2C_FIELD(arg0, f32 *, 0x350) + (temp_f21_2 * (M2C_FIELD(temp_v0_6, f32 *, 4) + (temp_f21_2 * M2C_FIELD(temp_v0_6, f32 *, 8))));
        if (!(temp_f0_3 < var_f3_2)) {
            var_f3_2 = temp_f0_3;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f0_3) {
                var_f3_2 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        temp_f0_4 = M2C_FIELD(&D_FLT_002BE830, f32 *, 0) + (temp_f7 * (M2C_FIELD(&D_FLT_002BE830, f32 *, 4) + (temp_f7 * M2C_FIELD(&D_FLT_002BE830, f32 *, 8))));
        if (temp_f0_4 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f2 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f2 = temp_f0_4;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f0_4) {
                var_f2 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
        temp_f20_3 = var_f6 * var_f3_2 * var_f2 * M2C_FIELD(arg0, f32 *, 0x338);
        asm volatile("qmtc2.ni %0, vf1" : : "r"(temp_f20_3));
        asm volatile("vmulx.xyzw vf3, vf2, vf1x");
        asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x180(%0)" : : "r"(sp));
        temp_v0_7 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x49, 0);
        if (temp_v0_7 > 0) {
            var_s2_2 = &sp40;
            var_s0 = temp_v0_7;
            do {
                temp_a0_2 = *var_s2_2;
                if ((temp_a0_2 != arg0) && (M2C_FIELD(temp_a0_2, s32 *, 0xEC) != M2C_FIELD(arg0, s32 *, 0xEC))) {
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_a0_2)));
                    asm volatile("lqc2 vf2, 0x170(%0)" : : "r"(sp));
                    asm volatile("vsub.xyzw vf1, vf2, vf3");
                    asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
                    sp38 = 0;
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(sp30));
                    asm volatile("vmul.xyz vf1, vf3, vf3");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf2, vf0, Q");
                    s32 vu_10;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_10));
                    if (vu_10 < 0.0001f) {
                        sp30 = g_2a2da0;
                    } else {
                        asm volatile("vdiv Q, vf0w, vf2x");
                        asm volatile("vwaitq");
                        asm volatile("vmulq.xyzw vf1, vf3, Q");
                        asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
                    }
                    s32 vu_11;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_11));
                    temp_v1_5 = vu_11;
                    temp_f0_5 = M2C_FIELD(&D_FLT_002BE840, f32 *, 0) + (temp_v1_5 * (M2C_FIELD(&D_FLT_002BE840, f32 *, 4) + (temp_v1_5 * M2C_FIELD(&D_FLT_002BE840, f32 *, 8))));
                    if (temp_f0_5 < M2C_FIELD(&D_FLT_002BE850, f32 *, 0)) {
                        var_f6_2 = M2C_FIELD(&D_FLT_002BE850, f32 *, 0);
                    } else {
                        var_f6_2 = temp_f0_5;
                        if (M2C_FIELD(&D_FLT_002BE850, f32 *, 4) < temp_f0_5) {
                            var_f6_2 = M2C_FIELD(&D_FLT_002BE850, f32 *, 4);
                        }
                    }
                    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
                    asm volatile("vmul.xyz vf2, vf2, vf1");
                    asm volatile("vaddw.x vf3, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf2, vf2y");
                    asm volatile("vmaddz.x vf2, vf3, vf2z");
                    s32 vu_12;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_12));
                    temp_v1_6 = vu_12;
                    temp_f3 = M2C_FIELD(&D_FLT_002BE860, f32 *, 0) + (temp_v1_6 * (M2C_FIELD(&D_FLT_002BE860, f32 *, 4) + (temp_v1_6 * M2C_FIELD(&D_FLT_002BE860, f32 *, 8))));
                    if (temp_f3 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
                        var_f0 = M2C_FIELD(&g_2bbb60, f32 *, 0);
                    } else {
                        var_f0 = temp_f3;
                        if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f3) {
                            var_f0 = M2C_FIELD(&g_2bbb60, f32 *, 4);
                        }
                    }
                    asm volatile("lqc2 vf3, 0x180(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f6_2 * var_f0));
                    asm volatile("vadda.xyzw ACC, vf0, vf3");
                    asm volatile("vmaddx.xyzw vf3, vf2, vf1x");
                    asm volatile("sqc2 vf1, 0x140(%0)" : : "r"(sp));
                    asm volatile("sqc2 vf3, 0x180(%0)" : : "r"(sp));
                }
                var_s0 -= 1;
                var_s2_2 += 4;
            } while (var_s0 != 0);
        }
        M2C_FIELD(arg0, s128 *, 0x210) = LimitVectorLength__FP6VECTORfT0(sp180, temp_f20_3);
        M2C_FIELD(arg0, f32 *, 0x204) = atan2f(unksp24, (s32) sp20);
        break;
    }
}
}
