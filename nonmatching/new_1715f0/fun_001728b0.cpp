typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001728B0 {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ f32 sp10;                           /* inferred */
    /* 0x014 */ s32 sp14;                           /* inferred */
    /* 0x018 */ char pad18[8];                      /* maybe part of sp14[3]? */
    /* 0x020 */ M2C_UNK sp20;                       /* inferred */
    /* 0x020 */ char pad20[0x800];
    /* 0x820 */ s128 sp820;                         /* inferred */
    /* 0x830 */ char pad830[8];
    /* 0x838 */ s32 sp838;                          /* inferred */
    /* 0x83C */ char pad83C[0x14];                  /* maybe part of sp838[6]? */
    /* 0x850 */ s8 *sp850;                        /* inferred */
    /* 0x854 */ char pad854[0x3FC];                 /* maybe part of sp850[0x100]? */
    /* 0xC50 */ s8 *spC50;                        /* inferred */
    /* 0xC54 */ char padC54[0x7C];                  /* maybe part of spC50[0x20]? */
    /* 0xCD0 */ s8 *spCD0;                        /* inferred */
    /* 0xCD4 */ char padCD4[0x1FC];                 /* maybe part of spCD0[0x80]? */
    /* 0xED0 */ s128 spED0;                         /* inferred */
    /* 0xEE0 */ char padEE0[0xB0];
};                                                  /* size = 0xF90 */
#define sp0 (*(s128 *)(sp + 0))
#define sp10 (*(f32 *)(sp + 0x10))
#define sp14 (*(s32 *)(sp + 0x14))
#define sp20 (*(s8 *)(sp + 0x20))
#define sp820 (*(s128 *)(sp + 0x820))
#define sp838 (*(s32 *)(sp + 0x838))
#define sp850 (*(s8 **)(sp + 0x850))
#define spC50 (*(s8 **)(sp + 0xC50))
#define spCD0 (*(s8 **)(sp + 0xCD0))
#define spED0 (*(s128 *)(sp + 0xED0))
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, void *);
s32 FAddSearchCand(s8 *);
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);
void FindCrvClosestPointAll(s8 *, s128, M2C_UNK, s128 *, M2C_UNK, M2C_UNK, M2C_UNK);
f32 GRandInRange(f32, f32);
s32 PosLoWorld(...);
f32 RadYawSo(s8 *);
s32 SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK);
void qsort(M2C_UNK *, s32, M2C_UNK, M2C_UNK *);
extern M2C_UNK B_003DD490;
extern s8 *B_003E13B4;
extern s8 *B_003E13C0;
extern s8 *B_003E13CC;
extern s8 *B_003E13D8;
extern s8 *B_003E13E4;
extern s8 *B_003E13F0;
extern s8 *B_003E13FC;
extern s8 *B_003E1408;
extern s8 *B_003E1450;
extern M2C_UNK D_FLT_002BE5A8;
extern M2C_UNK D_FLT_002BE5B0;
extern M2C_UNK func_00172888;
extern s128 g_2a2da0;
extern M2C_UNK g_2a2dc0;
void func_001728B0(s8 *arg0) {
    s8 sp[0xEF0] __attribute__((aligned(16)));
    M2C_UNK *var_a0_3;
    f32 var_f21;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a2;
    s32 var_s0_10;
    s32 var_s0_11;
    s32 var_s0_9;
    s32 var_v0;
    u32 var_s1_4;
    s8 **var_s1;
    s8 **var_s1_2;
    s8 **var_s1_3;
    s8 *temp_a0;
    s8 *var_a0;
    s8 *var_a0_2;
    s8 *var_a1;
    s8 *var_a3;
    s8 *var_s0;
    s8 *var_s0_12;
    s8 *var_s0_13;
    s8 *var_s0_2;
    s8 *var_s0_3;
    s8 *var_s0_4;
    s8 *var_s0_5;
    s8 *var_s0_6;
    s8 *var_s0_7;
    s8 *var_s0_8;
    sp0 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10));
    var_s0 = B_003E13FC;
    sp10 = RadYawSo(M2C_FIELD(arg0, s8 **, 0x10));
    sp14 = 0;
    if (var_s0 != NULL) {
        do {
            asm volatile("qmtc2.ni %0, vf5" : : "r"(PosLoWorld(var_s0)));
            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf1, vf5");
            asm volatile("sqc2 vf1, 0x830(%0)" : : "r"(sp));
            sp838 = 0;
            asm volatile("lqc2 vf3, 0x830(%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf2, vf3, vf3");
            asm volatile("vaddw.x vf1, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf1, vf2z");
            asm volatile("vsqrt Q, vf2x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            asm volatile("qmtc2.ni %0, vf4" : : "r"(M2C_FIELD(var_s0, s32 *, 0x10C)));
            asm volatile("sqc2 vf4, 0x840(%0)" : : "r"(sp));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            if (vu_1 < 0.0001f) {
                asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
            } else {
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf3, Q");
            }
            asm volatile("vadda.xyzw ACC, vf0, vf5");
            asm volatile("vmaddx.xyzw vf1, vf1, vf4x");
            asm volatile("sqc2 vf1, 0x820(%0)" : : "r"(sp));
            FAddSearchCand(sp);
            var_s0 = M2C_FIELD(var_s0, s8 **, 0x104);
        } while (var_s0 != NULL);
    }
    var_s0_2 = B_003E13F0;
    if (var_s0_2 != NULL) {
        do {
            FindCrvClosestPointAll(var_s0_2, sp0, 0, (s128 *)(sp + 0x820), 0, 0, 0);
            FAddSearchCand(sp);
            var_s0_2 = M2C_FIELD(var_s0_2, s8 **, 0x1B4);
        } while (var_s0_2 != NULL);
    }
    var_s0_3 = B_003E1408;
    if (var_s0_3 != NULL) {
        do {
            sp820 = PosLoWorld(var_s0_3);
            FAddSearchCand(sp);
            var_s0_3 = M2C_FIELD(var_s0_3, s8 **, 0x104);
        } while (var_s0_3 != NULL);
    }
    var_s0_4 = B_003E13E4;
    if (var_s0_4 != NULL) {
        do {
            sp820 = PosLoWorld(var_s0_4);
            FAddSearchCand(sp);
            var_s0_4 = M2C_FIELD(var_s0_4, s8 **, 0x174);
        } while (var_s0_4 != NULL);
    }
    var_s0_5 = B_003E13C0;
    if (var_s0_5 != NULL) {
        do {
            FindCrvClosestPointAll(var_s0_5, sp0, 0, (s128 *)(sp + 0x820), 0, 0, 0);
            FAddSearchCand(sp);
            var_s0_5 = M2C_FIELD(var_s0_5, s8 **, 0x1B4);
        } while (var_s0_5 != NULL);
    }
    var_s0_6 = B_003E13D8;
    if (var_s0_6 != NULL) {
        do {
            sp820 = PosLoWorld(var_s0_6);
            FAddSearchCand(sp);
            var_s0_6 = M2C_FIELD(var_s0_6, s8 **, 0x104);
        } while (var_s0_6 != NULL);
    }
    var_s0_7 = B_003E13CC;
    if (var_s0_7 != NULL) {
        do {
            FindCrvClosestPointAll(var_s0_7, sp0, 0, (s128 *)(sp + 0x820), 0, 0, 0);
            FAddSearchCand(sp);
            var_s0_7 = M2C_FIELD(var_s0_7, s8 **, 0x1B4);
        } while (var_s0_7 != NULL);
    }
    var_s0_8 = B_003E13B4;
    if (var_s0_8 != NULL) {
        var_v0 = M2C_FIELD(var_s0_8, s32 *, 0xE8);
loop_27:
        if ((var_v0 & 1) && (FIsBasicDerivedFrom(var_s0_8, 0x13) != 0)) {
            sp820 = PosLoWorld(var_s0_8);
            FAddSearchCand(sp);
        }
        var_s0_8 = M2C_FIELD(var_s0_8, s8 **, 0xE0);
        if (var_s0_8 != NULL) {
            var_v0 = M2C_FIELD(var_s0_8, s32 *, 0xE8);
            goto loop_27;
        }
    }
    temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 0x505, 0x23, 0, 0x100, sp + 0x850);
    if (temp_v0 > 0) {
        var_s1 = (s8 **)(sp + 0x850);
        var_s0_9 = temp_v0;
        do {
            temp_a0 = *var_s1;
            var_s0_9 -= 1;
            var_s1 += 4;
            sp820 = PosLoWorld(temp_a0);
            FAddSearchCand(sp);
        } while (var_s0_9 != 0);
    }
    temp_v0_2 = CploFindSwObjectsByClass(&B_003DD490, 0x505, 0x67, 0, 0x20, sp + 0xC50);
    var_s0_10 = temp_v0_2;
    if (temp_v0_2 > 0) {
        var_s1_2 = (s8 **)(sp + 0xC50);
        var_a0 = *var_s1_2;
loop_38:
        var_s0_10 -= 1;
        var_s1_2 += 4;
        sp820 = PosLoWorld(var_a0);
        FAddSearchCand(sp);
        if (var_s0_10 != 0) {
            var_a0 = *var_s1_2;
            goto loop_38;
        }
    }
    temp_v0_3 = CploFindSwObjectsByClass(&B_003DD490, 0x505, 0x1B, 0, 0x80, sp + 0xCD0);
    var_s0_11 = temp_v0_3;
    if (temp_v0_3 > 0) {
        var_s1_3 = (s8 **)(sp + 0xCD0);
        var_a0_2 = *var_s1_3;
loop_43:
        var_s0_11 -= 1;
        var_s1_3 += 4;
        sp820 = PosLoWorld(var_a0_2);
        FAddSearchCand(sp);
        if (var_s0_11 != 0) {
            var_a0_2 = *var_s1_3;
            goto loop_43;
        }
    }
    var_s0_12 = B_003E1450;
    if (var_s0_12 != NULL) {
        do {
            sp820 = PosLoWorld(var_s0_12, sp14);
            FAddSearchCand(sp);
            var_s0_12 = M2C_FIELD(var_s0_12, s8 **, 0x174);
        } while (var_s0_12 != NULL);
    }
    var_f21 = 0.0f;
    qsort((M2C_UNK *)(sp + 0x20), sp14, 0x20, &func_00172888);
    var_s1_4 = 0;
    var_a3 = NULL;
    var_a2 = 0;
    if (sp14 > 0) {
        asm volatile("lqc2 vf6, (%0)" : : "r"(sp));
        var_a0_3 = (M2C_UNK *)(sp + 0x20);
        var_a1 = arg0 + 0x50;
loop_50:
        asm volatile("lqc2 vf5, (%0)" : : "r"(var_a0_3));
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("vsub.xyzw vf3, vf5, vf6");
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
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
        if (vu_2 < 0.0001f) {
            asm volatile("qmtc2.ni %0, vf2" : : "r"(g_2a2da0));
        } else {
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf2, vf2, Q");
        }
        asm volatile("qmtc2.ni %0, vf1" : : "r"(0x43480000));
        asm volatile("vadda.xyzw ACC, vf0, vf6");
        asm volatile("vmaddx.xyzw vf3, vf2, vf1x");
        asm volatile("sqc2 vf1, 0x830(%0)" : : "r"(sp));
        asm volatile("vmove.xyzw vf2, vf3");
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
        asm volatile("vaddq.x vf1, vf0, Q");
        asm volatile("vwaitq");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vmul.xy vf1, vf1, vf1");
        asm volatile("vsub.xyzw vf1, vf2, vf1");
        asm volatile("lqc2 vf1, (%0)" : : "r"(var_a3));
        if ((var_a3 == NULL) || !(vu_3 < 150.0f)) {
            var_a3 = var_a1;
            var_f21 = M2C_FIELD(var_a0_3, f32 *, 0x10);
            var_a1 += 0x20;
            var_s1_4 += 1;
            asm volatile("sqc2 vf5, -0x10(%0)" : : "r"(var_a1));
            asm volatile("sqc2 vf3, -0x20(%0)" : : "r"(var_a1));
        }
        var_a2 += 1;
        var_a0_3 += 0x20;
        if ((var_a2 < sp14) && (var_s1_4 < 4U)) {
            goto loop_50;
        }
    }
    spED0 = sp0;
    asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorCylind__FP6VECTORfff(sp10 + 3.1415927f, -350.0f, 0)));
    asm volatile("lqc2 vf1, 0xed0(%0)" : : "r"(sp));
    asm volatile("vadd.xyzw vf2, vf1, vf2");
    asm volatile("sqc2 vf2, 0xee0(%0)" : : "r"(sp));
    if (var_s1_4 < 4U) {
        var_s0_13 = (var_s1_4 << 5) + 0x50 + arg0;
        do {
            var_s1_4 += 1;
            var_f21 += GRandInRange(M2C_FIELD(&D_FLT_002BE5A8, f32 *, 0), M2C_FIELD(&D_FLT_002BE5A8, f32 *, 4));
            asm volatile("lqc2 vf3, 0xee0(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorCylind__FP6VECTORfff(var_f21 + sp10, GRandInRange(M2C_FIELD(&D_FLT_002BE5B0, f32 *, 0), M2C_FIELD(&D_FLT_002BE5B0, f32 *, 4)), 0)));
            asm volatile("vadd.xyzw vf1, vf3, vf2");
            asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(var_s0_13));
            asm volatile("sqc2 vf1, (%0)" : : "r"(var_s0_13));
            var_s0_13 += 0x20;
        } while (var_s1_4 < 4U);
    }
    M2C_FIELD(arg0, s32 *, 0xD0) = 0;
    M2C_FIELD(arg0, f32 *, 0x3C) = -3.4028235e38f;
}
}
