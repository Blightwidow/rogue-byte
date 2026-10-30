typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateJtActiveHang__FP2JTP3JOY {
    /* 0x000 */ char pad0[0x20];
    /* 0x020 */ f32 sp20;                           /* inferred */
    /* 0x024 */ char pad24[4];
    /* 0x028 */ f32 sp28;                           /* inferred */
    /* 0x02C */ char pad2C[0x34];                   /* maybe part of sp28[0xE]? */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x30];
    /* 0x090 */ f32 sp90;                           /* inferred */
    /* 0x094 */ char pad94[0xC];                    /* maybe part of sp90[4]? */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ char padB0[0x70];
};                                                  /* size = 0x120 */
#define sp20 (*(f32 *)(sp + 0x020))
#define sp28 (*(f32 *)(sp + 0x028))
void CalculateJtHangAccel__FP2JT(s8 *);
void ClearVjoyPresses(s8 *, M2C_UNK);
f32 GLimitAbs__Fff(f32 *, f32 *, f32, f32);
f32 GSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, M2C_UNK, f32);
void GetJtHangHeading__FP2JTPf(f32 *);
s32 GrfbtnVjoyPressedWithin(s8 *, M2C_UNK, M2C_UNK);
s32 LoadRotateMatrixRad(M2C_UNK *, s128, f32);
s32 PosLoWorld(...);
f32 RadNormalize__Ff(f32);
void ReblendAsegbl(s8 *);
void SetJtState(s8 *, M2C_UNK, s32);
void SetStepRadTarget(s8 *, f32);
void StartBinoc(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
f32 atan2f(f32, f32);
void func_001F5078(s32);
extern M2C_UNK D_002BF570;
extern M2C_UNK D_002BF580;
extern f32 D_FLT_002BF554;
extern f32 D_FLT_002BF558;
extern f32 D_FLT_002BF55C;
extern f32 D_FLT_002BF560;
extern f32 D_FLT_002BF564;
extern f32 D_FLT_002BF568;
extern f32 D_FLT_002BF56C;
extern f32 D_FLT_002BF58C;
extern f32 D_FLT_002BF590;
extern s128 g_2a2dc0;
extern f32 g_2dded0;
void UpdateJtActiveHang__FP2JTP3JOY(s8 *arg0) {
    f32 saved_reg_f20;
    f32 saved_reg_f22;
    s8 sp[0x80] __attribute__((aligned(16)));
    M2C_UNK sp60;
    f32 sp90;
    s128 spA0;
    M2C_UNK var_f20;
    M2C_UNK var_f22;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f21;
    f32 temp_f2;
    f32 var_f1;
    s128 temp_v0;
    s32 temp_v1_4;
    s32 var_a2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    s8 *temp_v0_2;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    var_f20 = saved_reg_f20;
    var_f22 = saved_reg_f22;
    var_s1 = 0;
    var_s3 = 0;
    GetJtHangHeading__FP2JTPf(&sp90);
    if (M2C_FIELD(arg0, s32 *, 0x18FC) != 0) {
        sp90 = RadNormalize__Ff(sp90 + 3.1415927f);
    }
    SetStepRadTarget(arg0, sp90);
    temp_f2 = RadNormalize__Ff(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18) - M2C_FIELD(arg0, f32 *, 0x1A8));
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C) > 0.3f) {
        temp_f1 = fabsf(temp_f2);
        if (temp_f1 < 1.0471976f) {
            var_s1 = 1;
            goto block_7;
        }
        if (temp_f1 > 2.0943952f) {
            var_s3 = 1;
block_7:
            M2C_FIELD(arg0, f32 *, 0x18F4) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0);
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x18F8) = -1;
    }
    temp_v0 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x18C4));
    spA0 = temp_v0;
    asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0, temp_v0)));
    asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf3, vf1, vf2");
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    if (vu_1 < 0.0001f) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2dc0));
    } else {
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf3, Q");
    }
    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
    LoadRotateMatrixRad(&sp60, g_2a2dc0, M2C_FIELD(arg0, f32 *, 0x1A8));
    asm volatile("lqc2 vf2, 0x60(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x80(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("vmul.xyzw vf7, vf2, vf1");
    asm volatile("vmaxw.xyzw vf8, vf0, vf0w");
    asm volatile("vmul.xyzw vf6, vf3, vf1");
    asm volatile("vmul.xyzw vf5, vf4, vf1");
    asm volatile("vadday.x ACC, vf7, vf7y");
    asm volatile("vmaddz.x vf1, vf8, vf7z");
    asm volatile("vaddax.y ACC, vf6, vf6x");
    asm volatile("vmaddz.y vf1, vf8, vf6z");
    asm volatile("vaddax.z ACC, vf5, vf5x");
    asm volatile("vmaddy.z vf1, vf8, vf5y");
    asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x40(%0)" : : "r"(sp));
    asm volatile("sqc2 vf4, 0x50(%0)" : : "r"(sp));
    var_s0 = M2C_FIELD(arg0, s32 *, 0x18D0);
    temp_f21 = RadNormalize__Ff(atan2f(sp28, sp20) - 1.5707964f);
    if (var_s0 != 1) {
        if (var_s0 < 2) {
            var_a2 = var_s0;
            if (var_s0 != 0) {
            } else {
                if (var_s3 != 0) {
                    var_s0 = 2;
                    goto block_52;
                }
                if (var_s1 != 0) {
                    var_a2 = var_s0;
                    if (D_FLT_002BF554 < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x18D4))) {
                        M2C_FIELD(arg0, s32 *, 0x18F8) = 0;
                        var_s0 = 1;
                        goto block_52;
                    }
                } else {
                    goto block_29;
                }
            }
        } else if (var_s0 != 2) {
            var_a2 = var_s0;
            if (var_s0 != 3) {
            } else {
                if ((var_s1 != 0) && (M2C_FIELD(arg0, s32 *, 0x18F8) != 0)) {
                    goto block_43;
                }
                if ((var_s3 != 0) && (M2C_FIELD(arg0, s32 *, 0x18F8) != 2)) {
                    goto block_46;
                }
                var_a2 = var_s0;
                if (D_FLT_002BF564 < fabsf(temp_f21)) {
                    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(M2C_FIELD(temp_v1, s32 (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108))));
                    var_v1 = 1;
                    asm volatile("vmul.xyz vf1, vf3, vf3");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_2;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                    if (!(D_FLT_002BF56C < vu_2)) {
                        var_v1 = 0;
                    }
                    var_v0 = 1;
                    goto block_51;
                }
            }
        } else {
            if (var_s1 != 0) {
                var_s0 = 0;
                goto block_52;
            }
            if (var_s3 != 0) {
                var_a2 = var_s0;
                if (D_FLT_002BF558 < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x18D4))) {
                    M2C_FIELD(arg0, s32 *, 0x18F8) = var_s0;
                    var_s0 = 1;
                    goto block_52;
                }
            } else {
block_29:
                if (D_FLT_002BF55C < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x18F4))) {
                    var_s0 = 1;
                }
                goto block_52;
            }
        }
    } else if ((var_s1 == 0) || (M2C_FIELD(arg0, s32 *, 0x18F8) == 0)) {
        if ((var_s3 == 0) || (M2C_FIELD(arg0, s32 *, 0x18F8) == 2)) {
            var_a2 = var_s0;
            if (fabsf(temp_f21) < D_FLT_002BF560) {
                temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                asm volatile("qmtc2.ni %0, vf3" : : "r"(M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x108))));
                var_v1 = 1;
                asm volatile("vmul.xyz vf1, vf3, vf3");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                if (!(vu_3 < D_FLT_002BF568)) {
                    var_v1 = 0;
                }
                var_v0 = 3;
block_51:
                var_s0 = (var_v1 != 0) ? var_v0 : var_s0;
                goto block_52;
            }
        } else {
block_46:
            var_s0 = 2;
            M2C_FIELD(arg0, s32 *, 0x18F8) = -1;
            goto block_52;
        }
    } else {
block_43:
        var_s0 = 0;
        M2C_FIELD(arg0, s32 *, 0x18F8) = -1;
block_52:
        var_a2 = var_s0;
    }
    SetJtState(arg0, 3, var_a2);
    CalculateJtHangAccel__FP2JT(arg0);
    temp_v0_2 = M2C_FIELD(arg0, s8 **, 0x1900);
    if (temp_v0_2 != NULL) {
        func_001F5078(M2C_FIELD(temp_v0_2, s32 *, 4));
    }
    if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x400, 0x3E19999A) != 0) {
        temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
        if (M2C_FIELD(temp_v1_3, s32 (**)(s8 *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x318), 3) != 0) {
            ClearVjoyPresses(M2C_FIELD(arg0, s8 **, 0x150), 0x400);
            StartBinoc(arg0 + 0xF00, 0, 0, 0);
        }
    }
    temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x18D0);
    switch (temp_v1_4) {                            /* irregular */
    case 3:
        break;
    case 0:
        var_f22 = 0x3F800000;
        var_f20 = 0x3F800000;
block_69:
    default:
block_70:
        M2C_FIELD(arg0, f32 *, 0x199C) = GSmooth__FfffP3SMPPf(&D_002BF570, 0, M2C_FIELD(arg0, f32 *, 0x199C), var_f20, M2C_FIELD(&g_2dded0, f32 *, 4));
        temp_f0 = GSmooth__FfffP3SMPPf(&D_002BF580, 0, M2C_FIELD(arg0, f32 *, 0x1998), var_f22, M2C_FIELD(&g_2dded0, f32 *, 4));
        temp_f1_2 = M2C_FIELD(arg0, f32 *, 0x199C);
        M2C_FIELD(arg0, f32 *, 0x1998) = temp_f0;
        M2C_FIELD(arg0, f32 *, 0x1970) = (f32) (temp_f1_2 * temp_f0);
        M2C_FIELD(arg0, f32 *, 0x1988) = (f32) (1.0f - temp_f1_2);
        M2C_FIELD(arg0, f32 *, 0x197C) = (f32) (temp_f1_2 * (1.0f - temp_f0));
        ReblendAsegbl(M2C_FIELD(arg0, s8 **, 0x1994));
        var_f1 = -1.0f;
        temp_f0_2 = temp_f21 / D_FLT_002BF58C;
        if (!(temp_f0_2 < -1.0f)) {
            var_f1 = temp_f0_2;
            if (temp_f0_2 > 1.0f) {
                var_f1 = 1.0f;
            }
        }
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1030), f32 *, 0x40) = GLimitAbs__Fff(&g_2dded0, &D_FLT_002BF590, ((M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1994), f32 *, 0x74) * (var_f1 + 1.0f) * 0.5f) - M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1030), f32 *, 0x1C)) / M2C_FIELD(&g_2dded0, f32 *, 4), D_FLT_002BF590);
        break;
    case 2:
        var_f20 = 0x3F800000;
        var_f22 = 0;
        goto block_70;
    case 1:
        var_f20 = 0;
        var_f22 = 0;
        if (M2C_FIELD(arg0, f32 *, 0x1998) > 0.5f) {
            var_f22 = 0x3F800000;
        }
        goto block_69;
    }
}
}
