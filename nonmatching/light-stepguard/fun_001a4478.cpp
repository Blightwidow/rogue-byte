typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A4478 {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ s8 *sp4;                          /* inferred */
    /* 0x008 */ char pad8[0x28];                    /* maybe part of sp4[0xB]? */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ char pad70[0xC];
    /* 0x07C */ s32 sp7C;                           /* inferred */
    /* 0x080 */ char pad80[0xC];                    /* maybe part of sp7C[4]? */
    /* 0x08C */ s32 sp8C;                           /* inferred */
    /* 0x090 */ M2C_UNK sp90;                       /* inferred */
    /* 0x090 */ char pad90[0x10];
    /* 0x0A0 */ s32 spA0;                           /* inferred */
    /* 0x0A4 */ f32 spA4;                           /* inferred */
    /* 0x0A8 */ char padA8[8];                      /* maybe part of spA4[3]? */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ f32 spC0;                           /* inferred */
    /* 0x0C4 */ char padC4[0x1C];                   /* maybe part of spC0[8]? */
    /* 0x0E0 */ f32 spE0;                           /* inferred */
    /* 0x0E4 */ char padE4[0x1C];                   /* maybe part of spE0[8]? */
    /* 0x100 */ s32 sp100;                          /* inferred */
    /* 0x104 */ char pad104[0xC];                   /* maybe part of sp100[4]? */
    /* 0x110 */ s128 sp110;                         /* inferred */
    /* 0x120 */ s128 sp120;                         /* inferred */
    /* 0x130 */ char pad130[0x90];
};                                                  /* size = 0x1C0 */
#define sp40 (*(s128 *)(sp + 0x040))
#define sp50 (*(s128 *)(sp + 0x050))
#define sp120 (*(s128 *)(sp + 0x120))
M2C_UNK FindSwLights(s128, M2C_UNK, f32 *);         /* extern */
M2C_UNK GetNormalVectors__FP6VECTORN30(M2C_UNK, s128, s128, s128 *); /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, s128);  /* extern */
s32 func_001A4258(s128, M2C_UNK, s128 *, M2C_UNK *, f32); /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_002BFC60;
extern s128 g_2a2da0;
extern s128 g_2a2db0;
extern M2C_UNK g_2a2dc0;
extern f32 g_2bfc90;
extern f32 g_2bfc94;
extern M2C_UNK g_2dea28;
void func_001A4478(s32 arg1, s8 *arg2) {
    s32 unksp6C;
    s8 sp[0x110] __attribute__((aligned(16)));
    s8 *sp4;
    s128 sp30;
    s128 sp60;
    s32 sp7C;
    s32 sp8C;
    M2C_UNK sp90;
    s32 spA0;
    f32 spA4;
    s128 spB0;
    f32 spC0;
    f32 spE0;
    s32 sp100;
    s128 sp110;
    M2C_UNK *var_a3_2;
    f32 *var_s0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f2;
    f32 var_f20;
    f32 var_f21;
    s128 *var_s0_2;
    s128 temp_v0;
    s32 *temp_v0_2;
    s32 *temp_v0_4;
    s32 *temp_v1;
    s32 *temp_v1_3;
    s32 *temp_v1_6;
    s32 *var_a0;
    s32 *var_a0_2;
    s32 *var_a2;
    s32 *var_a2_2;
    s32 *var_a2_3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_v0_3;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 temp_v1_7;
    s32 var_a3_3;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t0_3;
    s32 var_v0;
    s32 var_v0_2;
    u32 temp_t1;
    u32 var_s2;
    u32 var_t5;
    s8 *temp_v1_5;
    s8 *var_a1;
    s8 *var_a1_2;
    s8 *var_a3;
    temp_v0 = *M2C_FIELD(arg2, s128 **, 4);
    sp110 = temp_v0;
    if (arg1 != 0) {
        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(arg1));
        asm volatile("lqc2 vf3, (%0)" : : "r"(arg1));
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(arg1));
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg1));
        asm volatile("qmtc2.ni %0, vf5" : : "r"(temp_v0));
        asm volatile("vmulax.xyz ACC, vf3, vf5x");
        asm volatile("vmadday.xyz ACC, vf2, vf5y");
        asm volatile("vmaddaz.xyz ACC, vf1, vf5z");
        asm volatile("vmaddw.xyz vf5, vf4, vf0w");
        asm volatile("sqc2 vf5, 0x110(%0)" : : "r"(sp));
    }
    FindSwLights(sp110, 4, (f32 *)(sp));
    if (M2C_FIELD(arg2, f32 *, 0x10) == 0.0f) {
        M2C_FIELD(arg2, s32 *, 0x14) = 0;
        M2C_FIELD(arg2, s32 **, 0x18) = NULL;
    } else {
        var_a1 = sp4;
        var_t0 = 0;
        var_t5 = 0;
        M2C_FIELD(arg2, s32 **, 0x18) = (s32 *) M2C_FIELD(&g_2dea28, s32 **, 0xC);
        if (var_a1 != NULL) {
            var_v0 = 0 * 2;
loop_6:
            var_a3 = var_a1 + 0x120;
            *M2C_FIELD(&g_2dea28, s32 **, 0xC) = (var_v0 + var_t0 + 0x15) | 0x6C03C000;
            temp_v1 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
            var_a2 = temp_v1;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1;
            temp_t1 = var_t5 + 1;
            var_t0_2 = 8;
            do {
                var_t0_2 -= 4;
                temp_v1_2 = M2C_FIELD(var_a3, s32 *, 4);
                temp_a0 = M2C_FIELD(var_a3, s32 *, 8);
                temp_a1 = M2C_FIELD(var_a3, s32 *, 0xC);
                M2C_FIELD(var_a2, s32 *, 0) = M2C_FIELD(var_a3, s32 *, 0);
                var_a3 += 0x10;
                M2C_FIELD(var_a2, s32 *, 4) = temp_v1_2;
                M2C_FIELD(var_a2, s32 *, 8) = temp_a0;
                M2C_FIELD(var_a2, s32 *, 0xC) = temp_a1;
                var_a2 += 0x10;
            } while (var_t0_2 >= 0);
            var_t0 += 1;
            var_t5 = temp_t1;
            M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x30);
            if (temp_t1 < 4U) {
                var_a1 = *(&sp4 + (temp_t1 * 8));
                var_v0 = var_t0 * 2;
                if (var_a1 != NULL) {
                    goto loop_6;
                }
            }
        }
        if (var_t0 < 4) {
            do {
                var_a3_2 = &D_002BFC60;
                *M2C_FIELD(&g_2dea28, s32 **, 0xC) = ((var_t0 * 3) + 0x15) | 0x6C03C000;
                temp_v1_3 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                var_a2_2 = temp_v1_3;
                M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1_3;
                var_t0_3 = 8;
loop_13:
                var_t0_3 -= 4;
                temp_v1_4 = M2C_FIELD(var_a3_2, s32 *, 4);
                temp_a0_2 = M2C_FIELD(var_a3_2, s32 *, 8);
                temp_a1_2 = M2C_FIELD(var_a3_2, s32 *, 0xC);
                M2C_FIELD(var_a2_2, s32 *, 0) = M2C_FIELD(var_a3_2, s32 *, 0);
                var_a3_2 += 0x10;
                M2C_FIELD(var_a2_2, s32 *, 4) = temp_v1_4;
                M2C_FIELD(var_a2_2, s32 *, 8) = temp_a0_2;
                M2C_FIELD(var_a2_2, s32 *, 0xC) = temp_a1_2;
                var_a2_2 += 0x10;
                if (var_t0_3 >= 0) {
                    goto loop_13;
                }
                var_t0 += 1;
                M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x30);
            } while (var_t0 < 4);
        }
        var_a0 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
        if ((s32) var_a0 & 0xF) {
            do {
                *var_a0 = 0;
                temp_v0_2 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                var_a0 = temp_v0_2;
                M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0_2;
            } while ((s32) var_a0 & 0xF);
        }
        M2C_FIELD(arg2, s32 *, 0x14) = (s32) ((s32) (M2C_FIELD(&g_2dea28, s32 **, 0xC) - M2C_FIELD(arg2, s32 **, 0x18)) >> 4);
    }
    if (M2C_FIELD(arg2, f32 *, 0x1C) != 0.0f) {
        var_a1_2 = sp4;
        var_f20 = 0.0f;
        asm volatile("vsub.xyzw vf4, vf0, vf0");
        var_s2 = 0;
        if (var_a1_2 != NULL) {
            var_s0 = (f32 *)(sp);
            var_v0_2 = M2C_FIELD(var_a1_2, s32 *, 0x158);
loop_23:
            if (var_v0_2 != 0) {
                temp_v0_3 = M2C_FIELD(var_a1_2, s32 *, 0xE0);
                if (temp_v0_3 != 0) {
                    if (temp_v0_3 == 1) {
                        temp_f0 = *var_s0;
                        temp_v1_5 = M2C_FIELD(var_a1_2, s8 **, 0xC);
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_f0));
                        var_f20 += temp_f0;
                        asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf2, 0x130(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf4, 0x140(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(M2C_FIELD(temp_v1_5, s32 (**)(s8 *, s8 *), 0xFC)(var_a1_2 + M2C_FIELD(temp_v1_5, s16 *, 0xF8), var_a1_2)));
                        asm volatile("lqc2 vf2, 0x130(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf4, 0x140(%0)" : : "r"(sp));
                        asm volatile("vadda.xyzw ACC, vf0, vf4");
                        asm volatile("vmaddx.xyzw vf4, vf1, vf2x");
                    }
                } else {
                    temp_f1 = *var_s0;
                    asm volatile("lqc2 vf5, 0x110(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_f1));
                    var_f20 += temp_f1;
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(-g_2bfc90));
                    asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(var_a1_2));
                    asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
                    asm volatile("vadda.xyzw ACC, vf0, vf5");
                    asm volatile("vmaddx.xyzw vf2, vf1, vf2x");
                    asm volatile("vadda.xyzw ACC, vf0, vf4");
                    asm volatile("vmaddx.xyzw vf4, vf2, vf3x");
                }
            }
            var_s2 += 1;
            var_s0 += 8;
            if (var_s2 < 4U) {
                var_a1_2 = M2C_FIELD(var_s0, s8 **, 4);
                if (var_a1_2 != NULL) {
                    var_v0_2 = M2C_FIELD(var_a1_2, s32 *, 0x158);
                    goto loop_23;
                }
            }
        }
        if (var_f20 == 0.0f) {
            goto block_33;
        }
        asm volatile("qmtc2.ni %0, vf2" : : "r"(var_f20));
        asm volatile("lqc2 vf3, 0x110(%0)" : : "r"(sp));
        asm volatile("vdiv Q, vf0w, vf2x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf4, Q");
        asm volatile("sqc2 vf1, 0x120(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf4, vf3, vf1");
        asm volatile("vmul.xyz vf1, vf4, vf4");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf3, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        var_f21 = vu_1;
        temp_f1_2 = g_2bfc94 * M2C_FIELD(arg2, f32 *, 0x1C);
        asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
        if (var_f21 < temp_f1_2) {
            if (var_f21 < 1.0f) {
                asm volatile("lqc2 vf4, (%0)" : : "r"(&g_2a2dc0));
            } else {
                asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f21));
                asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf4, vf4, Q");
            }
            asm volatile("lqc2 vf2, 0x110(%0)" : : "r"(sp));
            var_f21 = temp_f1_2;
            asm volatile("qmtc2.ni %0, vf1" : : "r"(-temp_f1_2));
            asm volatile("vadda.xyzw ACC, vf0, vf2");
            asm volatile("vmaddx.xyzw vf2, vf4, vf1x");
            asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x120(%0)" : : "r"(sp));
        } else {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f21));
            asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf4, vf4, Q");
        }
        temp_f20 = var_f21 + M2C_FIELD(arg2, f32 *, 0x20);
        asm volatile("sqc2 vf4, 0x140(%0)" : : "r"(sp));
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_2));
        GetNormalVectors__FP6VECTORN30(vu_2, g_2a2db0, g_2a2da0, &sp30);
        var_s0_2 = &sp60;
        asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_f20));
        asm volatile("lqc2 vf4, 0x140(%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf1, vf4, vf2x");
        asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
        __as__6VECTORG9VU_VECTOR(&sp90, sp120);
        sp60 = sp30;
        temp_f2 = M2C_FIELD(arg2, f32 *, 0x1C);
        M2C_FIELD(var_s0_2, s128 *, 0x10) = sp40;
        M2C_FIELD(var_s0_2, s128 *, 0x20) = sp50;
        sp8C = 0;
        sp7C = 0;
        unksp6C = 0;
        M2C_FIELD(var_s0_2, f32 *, 0x3C) = 1.0f;
        asm volatile("qmtc2.ni %0, vf3" : : "r"(0x3FC00000));
        asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x120(%0)" : : "r"(sp));
        asm volatile("vadda.xyzw ACC, vf0, vf4");
        asm volatile("vmaddx.xyzw vf2, vf1, vf3x");
        asm volatile("vadd.xyzw vf1, vf4, vf1");
        spA4 = var_f21 / temp_f20;
        spB0 = sp110;
        asm volatile("sqc2 vf1, 0xd0(%0)" : : "r"(sp));
        spE0 = (temp_f2 * temp_f20) / var_f21;
        asm volatile("sqc2 vf2, 0xf0(%0)" : : "r"(sp));
        spC0 = temp_f2;
        asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
        sp100 = 0;
        spA0 = func_001A4258(M2C_FIELD(&B_002DDF40, s128 *, 0x90), 3, &spB0, &B_002DDF40, M2C_FIELD(&B_002DDF40, f32 *, 0x48));
        M2C_FIELD(arg2, s32 **, 0x2C) = (s32 *) M2C_FIELD(&g_2dea28, s32 **, 0xC);
        M2C_FIELD(arg2, s8 **, 0x24) = (s8 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x10);
        var_a0_2 = M2C_FIELD(&g_2dea28, s32 **, 0xC);
        if (((s32) var_a0_2 & 0xF) != 0xC) {
            do {
                *var_a0_2 = 0;
                temp_v0_4 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
                var_a0_2 = temp_v0_4;
                M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v0_4;
            } while (((s32) var_a0_2 & 0xF) != 0xC);
        }
        *M2C_FIELD(&g_2dea28, s32 **, 0xC) = 0x6C05C00E;
        temp_v1_6 = M2C_FIELD(&g_2dea28, s32 **, 0xC) + 4;
        var_a2_3 = temp_v1_6;
        M2C_FIELD(&g_2dea28, s32 **, 0xC) = temp_v1_6;
        var_a3_3 = 0x10;
        do {
            var_a3_3 -= 4;
            temp_v1_7 = M2C_FIELD(var_s0_2, s32 *, 4);
            temp_a0_3 = M2C_FIELD(var_s0_2, s32 *, 8);
            temp_a1_3 = M2C_FIELD(var_s0_2, s32 *, 0xC);
            M2C_FIELD(var_a2_3, s32 *, 0) = M2C_FIELD(var_s0_2, s32 *, 0);
            var_s0_2 += 0x10;
            M2C_FIELD(var_a2_3, s32 *, 4) = temp_v1_7;
            M2C_FIELD(var_a2_3, s32 *, 8) = temp_a0_3;
            M2C_FIELD(var_a2_3, s32 *, 0xC) = temp_a1_3;
            var_a2_3 += 0x10;
        } while (var_a3_3 >= 0);
        M2C_FIELD(&g_2dea28, s32 **, 0xC) = (s32 *) (M2C_FIELD(&g_2dea28, s32 **, 0xC) + 0x50);
        M2C_FIELD(arg2, s32 *, 0x28) = (s32) ((s32) (M2C_FIELD(&g_2dea28, s32 **, 0xC) - M2C_FIELD(arg2, s32 **, 0x2C)) >> 4);
        return;
    }
block_33:
    M2C_FIELD(arg2, s8 **, 0x24) = NULL;
    M2C_FIELD(arg2, s32 *, 0x28) = 0;
    M2C_FIELD(arg2, s32 **, 0x2C) = NULL;
}
}
