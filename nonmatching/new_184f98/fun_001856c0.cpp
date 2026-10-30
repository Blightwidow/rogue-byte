typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001856C0 {
    /* 0x000 */ char pad0[0x70];
    /* 0x070 */ M2C_UNK sp70;                       /* inferred */
    /* 0x070 */ char pad70[0x10];
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ f32 sp90;                           /* inferred */
    /* 0x094 */ f32 sp94;                           /* inferred */
    /* 0x098 */ s32 sp98;                           /* inferred */
    /* 0x09C */ s32 sp9C;                           /* inferred */
    /* 0x0A0 */ char padA0[0x10];                   /* maybe part of sp9C[5]? */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s32 spD0;                           /* inferred */
    /* 0x0D4 */ s32 spD4;                           /* inferred */
    /* 0x0D8 */ char padD8[0xF8];
};                                                  /* size = 0x1D0 */
M2C_UNK ClosestPointOnSegment(M2C_UNK, s128, s128, M2C_UNK *, M2C_UNK, f32 *); /* extern */
M2C_UNK GSmooth__FfffP3SMPPf(s8 *, f32 *, f32, M2C_UNK, f32); /* extern */
M2C_UNK SetPlane(s128 *, M2C_UNK, f32);             /* extern */
extern f32 g_2dded4;
void func_001856C0(s8 *arg0, s32 *arg1, s32 arg2, s32 arg3, s8 *arg4, f32 fparg0) {
    s32 saved_reg_s7;
    s8 sp[0xc0] __attribute__((aligned(16)));
    M2C_UNK sp70;
    s128 sp80;
    f32 sp90;
    f32 sp94;
    s32 sp98;
    s32 sp9C;
    s128 spB0;
    s128 spC0;
    s32 spD0;
    s32 spD4;
    f32 temp_f22;
    f32 temp_f23;
    f32 var_f20;
    s128 temp_a0_2;
    s128 temp_v1_4;
    s128 var_s7;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    s8 *temp_a0;
    s8 *temp_a1;
    s8 *temp_v1;
    var_s7 = saved_reg_s7;
    var_s3 = 0;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    sp98 = arg2;
    sp9C = arg3;
    M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    temp_f23 = g_2dded4 * 0.5f;
    temp_f22 = M2C_FIELD(arg4, f32 *, 8) * ((M2C_FIELD(arg4, f32 *, 0) + M2C_FIELD(arg4, f32 *, 4)) * 0.5f);
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
        do {
            temp_v1_2 = var_s3 * 0xC;
            temp_a1 = (s8 *)(temp_v1_2 + M2C_FIELD(arg0, s32 *, 0xF0));
            temp_a0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0xEC) + temp_v1_2);
            if ((M2C_FIELD(temp_a1, s32 *, 0) == -1) || (M2C_FIELD(temp_a1, s32 *, 4) == -1) || (spD0 = var_s3 + 1, (M2C_FIELD(temp_a1, s32 *, 8) == -1))) {
                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0xE4);
                var_a1 = 0;
                spD4 = var_s3 * 2;
                asm volatile("lqc2 vf4, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, (%0)" : : "r"((M2C_FIELD(temp_a0, s32 *, 0) * 0x10) + temp_v1_3));
                asm volatile("lqc2 vf7, 0x10(%0)" : : "r"(sp));
                asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(sp));
                asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(sp));
                asm volatile("vmulax.xyz ACC, vf4, vf3x");
                asm volatile("vmadday.xyz ACC, vf7, vf3y");
                asm volatile("vmaddaz.xyz ACC, vf6, vf3z");
                asm volatile("vmaddw.xyz vf3, vf5, vf0w");
                spD0 = var_s3 + 1;
                asm volatile("sqc2 vf3, 0x40(%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, (%0)" : : "r"((M2C_FIELD(temp_a0, s32 *, 4) * 0x10) + temp_v1_3));
                asm volatile("vmulax.xyz ACC, vf4, vf2x");
                asm volatile("vmadday.xyz ACC, vf7, vf2y");
                asm volatile("vmaddaz.xyz ACC, vf6, vf2z");
                asm volatile("vmaddw.xyz vf2, vf5, vf0w");
                asm volatile("sqc2 vf2, 0x50(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf2, vf2, vf3");
                asm volatile("lqc2 vf1, (%0)" : : "r"((M2C_FIELD(temp_a0, s32 *, 8) * 0x10) + temp_v1_3));
                asm volatile("vmulax.xyz ACC, vf4, vf1x");
                asm volatile("vmadday.xyz ACC, vf7, vf1y");
                asm volatile("vmaddaz.xyz ACC, vf6, vf1z");
                asm volatile("vmaddw.xyz vf4, vf5, vf0w");
                asm volatile("vsub.xyzw vf3, vf4, vf3");
                asm volatile("sqc2 vf4, 0x60(%0)" : : "r"(sp));
                asm volatile("vopmula.xyz ACC, vf2, vf3");
                asm volatile("vopmsub.xyz vf1, vf3, vf2");
                asm volatile("sqc2 vf1, 0xa0(%0)" : : "r"(sp));
                do {
                    temp_s2 = var_a1 + 1;
                    if (*(s32 *)(((spD4 + var_s3 + var_a1) * 4) + M2C_FIELD(arg0, s32 *, 0xF0)) == -1) {
                        temp_v1_4 = M2C_FIELD((((temp_s2 % 3) * 0x10) + sp), s128 *, 0x40);
                        var_f20 = 3.4028235e38f;
                        spB0 = temp_v1_4;
                        temp_a0_2 = M2C_FIELD(((((s32) (var_a1 + 2) % 3) * 0x10) + sp), s128 *, 0x40);
                        spC0 = temp_a0_2;
                        if (sp98 > 0) {
                            asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_a0_2));
                            var_s1 = sp9C;
                            asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_v1_4));
                            var_s0 = sp98;
                            asm volatile("vsub.xyzw vf1, vf2, vf3");
                            asm volatile("lqc2 vf2, 0xa0(%0)" : : "r"(sp));
                            asm volatile("vopmula.xyz ACC, vf2, vf1");
                            asm volatile("vopmsub.xyz vf4, vf1, vf2");
                            do {
                                asm volatile("lqc2 vf5, (%0)" : : "r"(var_s1));
                                asm volatile("sqc2 vf4, 0xf0(%0)" : : "r"(sp));
                                asm volatile("sqc2 vf5, 0x100(%0)" : : "r"(sp));
                                s32 vu_1;
                                asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_1));
                                ClosestPointOnSegment(vu_1, spB0, spC0, &sp70, 0, &sp90);
                                asm volatile("lqc2 vf4, 0xf0(%0)" : : "r"(sp));
                                asm volatile("lqc2 vf5, 0x100(%0)" : : "r"(sp));
                                if (sp90 < (fparg0 + temp_f22)) {
                                    asm volatile("vmul.xyz vf2, vf4, vf4");
                                    asm volatile("vaddw.x vf1, vf0, vf0w");
                                    asm volatile("vadday.x ACC, vf2, vf2y");
                                    asm volatile("vmaddz.x vf2, vf1, vf2z");
                                    asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(sp));
                                    asm volatile("vsqrt Q, vf2x");
                                    asm volatile("vwaitq");
                                    asm volatile("vaddq.x vf2, vf0, Q");
                                    asm volatile("vsub.xyzw vf3, vf5, vf3");
                                    asm volatile("vdiv Q, vf0w, vf2x");
                                    asm volatile("vwaitq");
                                    asm volatile("vmulq.xyzw vf2, vf4, Q");
                                    asm volatile("vmul.xyz vf3, vf2, vf3");
                                    asm volatile("vaddw.x vf1, vf0, vf0w");
                                    asm volatile("vadday.x ACC, vf3, vf3y");
                                    asm volatile("vmaddz.x vf3, vf1, vf3z");
                                    asm volatile("sqc2 vf2, 0xe0(%0)" : : "r"(sp));
                                    s32 vu_2;
                                    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
                                    GSmooth__FfffP3SMPPf(arg4, &sp94, fparg0, vu_2, temp_f23);
                                    asm volatile("lqc2 vf2, 0xe0(%0)" : : "r"(sp));
                                    asm volatile("lqc2 vf4, 0xf0(%0)" : : "r"(sp));
                                    if (sp94 < var_f20) {
                                        var_f20 = sp94;
                                        s32 vu_3;
                                        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
                                        SetPlane(&sp80, vu_3, var_f20);
                                        asm volatile("lqc2 vf4, 0xf0(%0)" : : "r"(sp));
                                        var_s7 = sp80;
                                    }
                                }
                                var_s0 -= 1;
                                var_s1 += 0x10;
                            } while (var_s0 != 0);
                        }
                        var_a1 = temp_s2;
                        if (var_f20 != 3.4028235e38f) {
                            temp_v0 = *arg1;
                            *arg1 = temp_v0 + 1;
                            M2C_FIELD(((temp_v0 * 0x10) + arg1), s128 *, 0x10) = var_s7;
                            goto block_15;
                        }
                    } else {
block_15:
                        var_a1 = temp_s2;
                    }
                } while (var_a1 < 3);
            }
            var_s3 = spD0;
        } while (var_s3 < M2C_FIELD(arg0, s32 *, 0xE8));
    }
}
}
