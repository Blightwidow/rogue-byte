typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CpdprizeAttractSwDprizes {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x018 */ f32 sp18;                           /* overlap; inferred */
    /* 0x020 */ M2C_UNK sp20;                       /* inferred */
    /* 0x020 */ char pad20[0x10];
    /* 0x030 */ s32 sp30;                           /* inferred */
    /* 0x034 */ char pad34[0x1C];                   /* maybe part of sp30[8]? */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ char pad60[0x10];
    /* 0x070 */ s32 sp70;                           /* inferred */
    /* 0x074 */ s32 sp74;                           /* inferred */
    /* 0x078 */ char pad78[8];                      /* maybe part of sp74[3]? */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ char padA0[0xE0];
};                                                  /* size = 0x180 */
#define sp0 (*(s128 *)(sp + 0x000))
#define sp90 (*(s128 *)(sp + 0x090))
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
f32 DtSolveJumpLaunch(M2C_UNK, s128, f32, f32, f32, f32); /* extern */
s32 FClipEdgeToPathzone(s32, s128, s128, M2C_UNK);  /* extern */
s32 FFindPathzoneClosestPoint(s32, s128, s128 *, M2C_UNK); /* extern */
f32 GRandInRange(M2C_UNK, M2C_UNK);                 /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
s32 PpathzoneFindPos(s128, M2C_UNK, s128 *);        /* extern */
s8 *PpoSwFocusBase(s32);                          /* extern */
s8 **PvAllocStackImpl__Fi(s32 *, s32 *);          /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
s32 SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK, s32 *, s32 *); /* extern */
M2C_UNK func_001C6BD0(s8 *, M2C_UNK, M2C_UNK, f32, f32); /* extern */
s32 func_001C6CE8(s32, s32, s32, s8 **);          /* extern */
s32 func_001C6DE8(M2C_UNK, s32, s32, s128 *, M2C_UNK, M2C_UNK, f32); /* extern */
extern M2C_UNK B_003DD490;
extern s128 D_002C0D60;
extern f32 D_FLT_002C0D70;
extern f32 D_FLT_002C0E80;
extern f32 D_FLT_002C0E84;
extern f32 D_FLT_002C0E88;
extern f32 D_FLT_002C0E8C;
extern f32 D_FLT_002C0E90;
extern f32 D_FLT_002C0E94;
extern M2C_UNK D_FLT_002C0EA0;
extern M2C_UNK D_FLT_002C0EB0;
extern f32 D_FLT_002C0EB8;
extern f32 D_FLT_002C0EBC;
extern f32 D_FLT_002C0EC0;
extern f32 D_FLT_002C0EC4;
extern M2C_UNK FFilterDprizeObjects;
extern M2C_UNK RO_002A2DE0;
extern s128 g_2a2da0;
extern M2C_UNK g_2a2dc0;
void CpdprizeAttractSwDprizes(s32 arg0, s32 arg1, s32 arg2, s32 arg4) {
    s32 unksp8;
    s8 sp[0x90] __attribute__((aligned(16)));
    s128 sp10;
    f32 sp18;
    M2C_UNK sp20;
    s32 sp30;
    s128 sp50;
    s32 sp70;
    s32 sp74;
    s128 sp80;
    M2C_UNK temp_a0;
    M2C_UNK temp_s0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f20;
    f32 var_f21;
    f32 var_f22;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s3;
    s32 var_s5;
    s32 var_v0;
    s32 var_v1_2;
    s8 **temp_v0_3;
    s8 **var_s0_2;
    s8 **var_s2;
    s8 *temp_a0_2;
    s8 *temp_a2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_5;
    s8 *var_v1;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg2));
    if (func_001C6DE8(vu_1, 0, 0, (s128 *)(sp), 0, 0x43960000, -3.4028235e38f) != 0) {
        var_s5 = 0;
        temp_v0 = PpoSwFocusBase(arg0);
        if (temp_v0 != NULL) {
            temp_v0_2 = M2C_FIELD(temp_v0, s8 **, 0xE8);
            var_v1 = NULL;
            if (temp_v0_2 != NULL) {
                var_v1 = M2C_FIELD(temp_v0_2, s8 **, 0xDC);
            }
            var_v0 = 0;
            if (var_v1 != NULL) {
                var_v0 = M2C_FIELD(var_v1, s32 *, 0x10);
            }
            var_s5 = var_v0;
        }
        if (var_s5 == 0) {
            var_s5 = PpathzoneFindPos(sp0, 1, &sp10);
        }
        var_f0 = unksp8;
        if (FFindPathzoneClosestPoint(var_s5, sp0, &sp10, 1) == 0) {
            s64 vu_2;
            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(PosLoWorld(temp_v0)));
            temp_s0 = vu_2;
            s64 vu_3;
            asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_s0));
            if (FFindPathzoneClosestPoint(var_s5, vu_3, &sp10, 1) != 0) {
                s64 vu_4;
                asm volatile("pextuw %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s0));
                var_f0 = vu_4;
                goto block_12;
            }
        } else {
block_12:
            sp18 = var_f0;
            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
            var_v1_2 = 1;
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            asm volatile("vmul.xy vf1, vf1, vf1");
            asm volatile("vaddy.x vf1, vf1, vf1y");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            s32 vu_5;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_5));
            if (!(D_FLT_002C0E80 < vu_5)) {
                var_v1_2 = 0;
            }
            s32 vu_6;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_6));
            if ((var_v1_2 == 0) && (func_001C6DE8(vu_6, 0, 0, &sp10, 0xC37A0000, 0x44BB8000, -3.4028235e38f) != 0)) {
                CStackFrame_Construct(&sp20);
                sp30 = arg4 * 4;
                M2C_FIELD(&sp30, s32 *, 4) = 0x10;
                temp_v0_3 = PvAllocStackImpl__Fi(&sp30, &sp30);
                temp_v0_4 = func_001C6CE8(arg0, arg1, arg4, temp_v0_3);
                if (temp_v0_4 == 0) {
                    CStackFrame_Destructor(&sp20, 2);
                } else {
                    asm volatile("lqc2 vf2, (%0)" : : "r"(&RO_002A2DE0));
                    asm volatile("qmtc2.ni %0, vf5" : : "r"(D_FLT_002C0E84));
                    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
                    asm volatile("vadda.xyzw ACC, vf0, vf1");
                    asm volatile("vmaddx.xyzw vf4, vf2, vf5x");
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(-D_FLT_002C0E84));
                    asm volatile("vadda.xyzw ACC, vf0, vf1");
                    asm volatile("vmaddx.xyzw vf1, vf2, vf3x");
                    asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
                    asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
                    asm volatile("sqc2 vf5, 0x50(%0)" : : "r"(sp));
                    var_s3 = 0;
                    asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
                    var_s1 = 0;
                    s32 vu_7;
                    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_7));
                    s32 vu_8;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_8));
                    bevy_camera_follow_push_out(&B_003DD490, vu_8, vu_7, &FFilterDprizeObjects, 0, &sp70, &sp74);
                    var_f22 = GRandInRange(0xC0490FDB, 0x40490FDB);
                    var_f21 = D_FLT_002C0E8C;
                    if (temp_v0_4 > 0) {
                        var_s2 = temp_v0_3;
loop_20:
                        temp_f0 = (f32) var_s3 * 0.02f;
                        temp_f4 = M2C_FIELD(&D_FLT_002C0EA0, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002C0EA0, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002C0EA0, f32 *, 8))));
                        if (temp_f4 < M2C_FIELD(&D_FLT_002C0EB0, f32 *, 0)) {
                            var_f20 = M2C_FIELD(&D_FLT_002C0EB0, f32 *, 0);
                        } else {
                            var_f20 = temp_f4;
                            if (M2C_FIELD(&D_FLT_002C0EB0, f32 *, 4) < temp_f4) {
                                var_f20 = M2C_FIELD(&D_FLT_002C0EB0, f32 *, 4);
                            }
                        }
                        sp80 = sp10;
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorCylind__FP6VECTORfff(var_f22, var_f21, 0)));
                        asm volatile("qmtc2.ni %0, vf6" : : "r"(var_f20));
                        asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(sp));
                        asm volatile("vadd.xyzw vf5, vf1, vf2");
                        asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
                        asm volatile("vsub.xyzw vf3, vf5, vf3");
                        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
                        asm volatile("vmul.xyz vf2, vf3, vf1");
                        asm volatile("vaddw.x vf4, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf2, vf2y");
                        asm volatile("vmaddz.x vf2, vf4, vf2z");
                        asm volatile("vmulx.xyzw vf2, vf1, vf2x");
                        asm volatile("vmove.xyzw vf7, vf5");
                        asm volatile("vsub.xyzw vf2, vf3, vf2");
                        asm volatile("sqc2 vf6, 0x50(%0)" : : "r"(sp));
                        asm volatile("vmul.xyz vf1, vf2, vf2");
                        asm volatile("vaddw.x vf4, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf4, vf1z");
                        asm volatile("vsqrt Q, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf1, vf0, Q");
                        s32 vu_9;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_9));
                        if (vu_9 < 0.0001f) {
                            asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
                        } else {
                            asm volatile("vdiv Q, vf0w, vf1x");
                            asm volatile("vwaitq");
                            asm volatile("vmulq.xyzw vf1, vf2, Q");
                        }
                        asm volatile("vadda.xyzw ACC, vf0, vf7");
                        asm volatile("vmaddx.xyzw vf2, vf1, vf6x");
                        var_s0 = 0;
                        asm volatile("sqc2 vf5, 0xb0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf5, 0xb0(%0)" : : "r"(sp));
                        s32 vu_10;
                        asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_10));
                        if (FClipEdgeToPathzone(var_s5, sp10, vu_10, 0) == 0) {
                            asm volatile("lqc2 vf5, 0xb0(%0)" : : "r"(sp));
                            s32 vu_11;
                            asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_11));
                            var_s0 = FClipEdgeToPathzone(var_s5, vu_11, sp90, 0) == 0;
                        }
                        s32 vu_12;
                        asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_12));
                        temp_a0 = vu_12;
                        if ((var_s0 != 0) && (func_001C6DE8(temp_a0, sp70, sp74, &sp50, 0xC3960000, 0x43960000, 0.7f) != 0)) {
                            asm volatile("lqc2 vf4, 0x50(%0)" : : "r"(sp));
                            asm volatile("lqc2 vf3, (%0)" : : "r"(&g_2a2dc0));
                            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                            asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(*var_s2, f32 *, 0x1D8) - 1.0f));
                            asm volatile("vadda.xyzw ACC, vf0, vf4");
                            asm volatile("vmaddx.xyzw vf4, vf3, vf2x");
                            asm volatile("vsub.xyzw vf3, vf4, vf1");
                            asm volatile("sqc2 vf2, 0x60(%0)" : : "r"(sp));
                            asm volatile("sqc2 vf4, 0xa0(%0)" : : "r"(sp));
                            temp_f1 = (f32) var_s1;
                            var_s1 += 1;
                            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                            asm volatile("lqc2 vf4, 0xa0(%0)" : : "r"(sp));
                            s32 vu_13;
                            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_13));
                            temp_f0_2 = DtSolveJumpLaunch(vu_13, D_002C0D60, D_FLT_002C0EB8, D_FLT_002C0EBC, D_FLT_002C0EC0, D_FLT_002C0EC0) + (temp_f1 * D_FLT_002C0EC4);
                            asm volatile("lqc2 vf3, (%0)" : : "r"(&D_002C0D60));
                            asm volatile("vsub.xyzw vf4, vf4, vf1");
                            asm volatile("qmtc2.ni %0, vf1" : : "r"(temp_f0_2 * -0.5f));
                            asm volatile("qmtc2.ni %0, vf2" : : "r"(1.0f / temp_f0_2));
                            asm volatile("sqc2 vf2, 0x60(%0)" : : "r"(sp));
                            asm volatile("vmulax.xyzw ACC, vf4, vf2x");
                            asm volatile("vmaddx.xyzw vf5, vf3, vf1x");
                            asm volatile("sqc2 vf1, 0x60(%0)" : : "r"(sp));
                            temp_a0_2 = *var_s2;
                            var_s2 += 4;
                            s32 vu_14;
                            asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_14));
                            s32 vu_15;
                            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_15));
                            func_001C6BD0(temp_a0_2, vu_15, vu_14, (f32) var_s1 * D_FLT_002C0D70, 3.4028235e38f);
                        }
                        var_f21 += D_FLT_002C0E90;
                        var_f22 = RadNormalize__Ff(var_f22 + D_FLT_002C0E94);
                        if (D_FLT_002C0E84 < var_f21) {
                            var_f21 -= D_FLT_002C0E84 - D_FLT_002C0E88;
                        }
                        var_s3 += 1;
                        temp_v1 = var_s1 < temp_v0_4;
                        if ((var_s3 < 0x32) && (temp_v1 != 0)) {
                            goto loop_20;
                        }
                        if (temp_v1 != 0) {
                            var_s0_2 = &temp_v0_3[var_s1];
                            var_s1_2 = temp_v0_4 - var_s1;
                            do {
                                temp_a2 = *var_s0_2;
                                var_s0_2 += 4;
                                var_s1_2 -= 1;
                                temp_v0_5 = M2C_FIELD(temp_a2, s8 **, 0xC);
                                M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x264)(temp_a2 + M2C_FIELD(temp_v0_5, s16 *, 0x260), 2, temp_a2);
                            } while (var_s1_2 != 0);
                        }
                    }
                    CStackFrame_Destructor(&sp20, 2);
                }
            }
        }
    }
}
}
