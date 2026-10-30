typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SpewPrizes {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ M2C_UNK sp30;                       /* inferred */
    /* 0x030 */ char pad30[0x30];
    /* 0x060 */ s32 sp60;                           /* inferred */
    /* 0x064 */ char pad64[0xC];                    /* maybe part of sp60[4]? */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ char padA0[0xC0];
};                                                  /* size = 0x160 */
M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(M2C_UNK *, M2C_UNK, s128); /* extern */
M2C_UNK ClearPrizeSpewer(s8 *);                   /* extern */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
f32 GRandInRange(f32, f32);                         /* extern */
s8 *PloLeaseCloneObject(s32, M2C_UNK);            /* extern */
s128 PosLoWorld(s32);                               /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
s128 SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
s32 VelBallistic(s128, M2C_UNK, M2C_UNK, f32);      /* extern */
M2C_UNK func_001C6BD0(s8 *, s128, M2C_UNK, f32, f32); /* extern */
extern M2C_UNK B_003DD490;
extern s128 D_002C0D60;
extern M2C_UNK D_FLT_002C0CE0;
extern f32 D_FLT_002C0CE8;
extern f32 D_FLT_002C0CEC;
extern M2C_UNK D_FLT_002C0CF0;
extern M2C_UNK D_FLT_002C0CF8;
extern s128 g_2a2da0;
extern s128 g_2a2dc0;
s8 *SpewPrizes(s8 *arg0, s32 arg1) {
    s8 sp[0xa0] __attribute__((aligned(16)));
    M2C_UNK sp30;
    s32 sp60;
    s128 sp70;
    s128 sp80;
    s128 sp90;
    M2C_UNK temp_s0_2;
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f13;
    f32 var_f2;
    s128 temp_s0;
    s32 var_s3;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *var_s1;
    s8 *var_s4;
    var_s3 = 0;
    var_s4 = NULL;
    sp60 = arg1;
loop_14:
    if (var_s3 < sp60) {
        if (var_s3 != 0) {
            var_s1 = PloLeaseCloneObject(M2C_FIELD(arg0, s32 *, 0x154), 0);
            if (var_s1 != NULL) {
                if (FIsBasicDerivedFrom(var_s1, 0x5A) != 0) {
                    temp_v0 = M2C_FIELD(var_s1, s8 **, 0xC);
                    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK), 0x264)(var_s1 + M2C_FIELD(temp_v0, s16 *, 0x260), 2);
                }
                goto block_22;
            }
        } else {
            var_s1 = M2C_FIELD(arg0, s8 **, 0x158);
block_22:
            if (var_s1 != NULL) {
                var_s4 = (var_s4 == NULL) ? var_s1 : var_s4;
                sp70 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s128 *, 0x70);
                sp80 = PosLoWorld(PpoSwFocusBase(&B_003DD490));
                temp_f20 = GRandInRange(M2C_FIELD(&D_FLT_002C0CF0, f32 *, 0), M2C_FIELD(&D_FLT_002C0CF0, f32 *, 4));
                sp90 = SetVectorCylind__FP6VECTORfff(temp_f20, GRandInRange(M2C_FIELD(&D_FLT_002C0CF8, f32 *, 0), M2C_FIELD(&D_FLT_002C0CF8, f32 *, 4)), 0xC2960000);
                asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf3, vf1, vf2");
                asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
                asm volatile("vmul.xyz vf2, vf3, vf1");
                asm volatile("vaddw.x vf4, vf0, vf0w");
                asm volatile("vadday.x ACC, vf2, vf2y");
                asm volatile("vmaddz.x vf2, vf4, vf2z");
                asm volatile("vmulx.xyzw vf2, vf1, vf2x");
                asm volatile("vsub.xyzw vf2, vf3, vf2");
                asm volatile("vmul.xyz vf1, vf2, vf2");
                asm volatile("vaddw.x vf4, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf4, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                if (vu_1 < 0.0001f) {
                    asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
                } else {
                    asm volatile("vdiv Q, vf0w, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf1, vf2, Q");
                }
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp30, vu_2, g_2a2dc0);
                asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(sp));
                asm volatile("lqc2 vf4, 0x50(%0)" : : "r"(sp));
                asm volatile("lqc2 vf5, 0x90(%0)" : : "r"(sp));
                asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("vmulax.xyz ACC, vf2, vf5x");
                asm volatile("vmadday.xyz ACC, vf3, vf5y");
                asm volatile("vmaddz.xyz vf1, vf4, vf5z");
                asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
                asm volatile("sqc2 vf4, 0x20(%0)" : : "r"(sp));
                asm volatile("lqc2 vf5, 0x80(%0)" : : "r"(sp));
                asm volatile("vadd.xyzw vf1, vf5, vf1");
                temp_s0 = D_002C0D60;
                asm volatile("sqc2 vf1, 0xa0(%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
                s64 vu_3;
                asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_s0));
                s32 vu_4;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
                s64 vu_5;
                asm volatile("por %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(VelBallistic(sp70, vu_4, vu_3, GRandInRange(M2C_FIELD(&D_FLT_002C0CE0, f32 *, 0), M2C_FIELD(&D_FLT_002C0CE0, f32 *, 4)))));
                temp_s0_2 = vu_5;
                if (FIsBasicDerivedFrom(var_s1, 0x5A) == 0) {
                    temp_v0_2 = M2C_FIELD(var_s1, s8 **, 0xC);
                    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *), 0x44)(var_s1 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
                    temp_v0_3 = M2C_FIELD(var_s1, s8 **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *), 0x13C)(var_s1 + M2C_FIELD(temp_v0_3, s16 *, 0x138), M2C_FIELD(arg0, s8 **, 0x150));
                    temp_v0_4 = M2C_FIELD(var_s1, s8 **, 0xC);
                    s64 vu_6;
                    asm volatile("por %0, %1, %2" : "=r"(vu_6) : "r"(0), "r"(temp_s0_2));
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, M2C_UNK), 0x11C)(var_s1 + M2C_FIELD(temp_v0_4, s16 *, 0x118), vu_6);
                } else {
                    if ((FIsBasicDerivedFrom(var_s1, 0x5B) != 0) || (FIsBasicDerivedFrom(var_s1, 0x5D) != 0)) {
                        temp_f0 = (f32) var_s3;
                        var_f2 = temp_f0;
                        var_f13 = temp_f0 * D_FLT_002C0CEC;
                    } else {
                        var_f2 = (f32) var_s3;
                        var_f13 = 3.4028235e38f;
                    }
                    s64 vu_7;
                    asm volatile("por %0, %1, %2" : "=r"(vu_7) : "r"(0), "r"(temp_s0_2));
                    func_001C6BD0(var_s1, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s128 *, 0x70), vu_7, var_f2 * D_FLT_002C0CE8, var_f13);
                }
                var_s3 += 1;
                goto loop_14;
            }
        }
    }
    ClearPrizeSpewer(arg0);
    return var_s4;
}
}
