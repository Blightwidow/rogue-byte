typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_OriginateSplineSinkParticles__FiP5EMITBR7EMITGENT2 {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ s128 spF0;                          /* inferred */
    /* 0x100 */ s128 sp100;                         /* inferred */
    /* 0x110 */ s128 sp110;                         /* inferred */
    /* 0x120 */ s128 sp120;                         /* inferred */
    /* 0x130 */ s128 sp130;                         /* inferred */
    /* 0x140 */ s128 sp140;                         /* inferred */
    /* 0x150 */ s128 sp150;                         /* inferred */
    /* 0x160 */ s128 sp160;                         /* inferred */
    /* 0x170 */ s128 sp170;                         /* inferred */
    /* 0x180 */ s32 sp180;                          /* inferred */
    /* 0x184 */ s8 *sp184;                        /* inferred */
    /* 0x188 */ s32 sp188;                          /* inferred */
    /* 0x18C */ char pad18C[0xB4];
};                                                  /* size = 0x240 */
#define sp110 (*(s128 *)(sp + 0x110))
#define sp120 (*(s128 *)(sp + 0x120))
#define sp130 (*(s128 *)(sp + 0x130))
#define sp150 (*(s128 *)(sp + 0x150))
#define sp160 (*(s128 *)(sp + 0x160))
#define sp170 (*(s128 *)(sp + 0x170))
s32 FFloatsNear__Ffff(s32, s8 *, f32, f32, M2C_UNK); /* extern */
M2C_UNK OriginateParticles__FiP5EMITBP7EMITGEN(s32, s8 *, s8 *); /* extern */
M2C_UNK PredictXfTransform(s32, M2C_UNK, s128 *, s128 *, f32); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(...); /* extern */
extern f32 g_2dded0;
void OriginateSplineSinkParticles__FiP5EMITBR7EMITGENT2(s32 arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    s8 sp[0x130] __attribute__((aligned(16)));
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    s128 sp80;
    s128 sp90;
    s128 spA0;
    s128 spB0;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    s128 spF0;
    s128 sp100;
    s128 sp140;
    s32 sp180;
    s8 *sp184;
    s32 sp188;
    f32 temp_f20;
    f32 var_f21;
    s128 var_v0;
    s32 *temp_v1;
    s32 temp_a0;
    s32 temp_fp;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_s4;
    s32 var_s6;
    s8 *temp_a1;
    s8 *temp_s5;
    s8 *temp_v1_2;
    sp180 = arg0;
    sp184 = arg2;
    temp_s5 = M2C_FIELD(M2C_FIELD(arg1, s8 **, 8), s8 **, 8);
    temp_v1 = M2C_FIELD(M2C_FIELD(temp_s5, s8 **, 0xE4), s32 **, 8);
    temp_v0 = *temp_v1;
    sp188 = temp_v0;
    if (temp_v0 == 0) {
        *temp_v1 = M2C_FIELD(temp_s5, s32 *, 0x10);
    }
    M2C_FIELD(arg3, s32 *, 0x10) = 0;
    var_s6 = 0;
    OriginateParticles__FiP5EMITBP7EMITGEN(sp180, M2C_FIELD(temp_s5, s8 **, 0xE4), arg3);
    var_f21 = 3.4028235e38f;
    M2C_FIELD(M2C_FIELD(temp_s5, s8 **, 0xE4), s32 *, 0x1C) = 0;
    temp_v1_2 = M2C_FIELD(temp_s5, s8 **, 0xC);
    temp_fp = M2C_FIELD(temp_v1_2, s32 (**)(s8 *, s128 *), 0x104)(temp_s5 + M2C_FIELD(temp_v1_2, s16 *, 0x100), &sp100);
    spD0 = sp110;
    spC0 = sp100;
    spE0 = sp120;
    spF0 = sp130;
    if (sp180 > 0) {
        var_s4 = 0;
        do {
            temp_a0 = M2C_FIELD(sp184, s32 *, 0xC);
            temp_a1 = M2C_FIELD(temp_s5, s8 **, 0xE4);
            temp_s1 = M2C_FIELD(temp_a1, s32 *, 0x18);
            temp_f20 = *(f32 *)((var_s6 * 4) + temp_a0) - g_2dded0;
            if (FFloatsNear__Ffff(temp_a0, temp_a1, temp_f20, var_f21, 0x38D1B717) == 0) {
                var_f21 = temp_f20;
                PredictXfTransform(temp_fp, 0, (s128 *)(sp), NULL, temp_f20);
                __ml__FRC7MATRIX4T0(&sp140, (s128 *)(sp), &spC0);
                if (temp_s1 != 3) {
                    PredictXfTransform(temp_fp, 0, &sp40, &sp80, temp_f20);
                    __ml__FRC7MATRIX4T0(&sp140, &sp40, &sp100);
                    sp60 = sp160;
                    sp70 = sp170;
                    sp40 = sp140;
                    sp50 = sp150;
                    __ml__FRC7MATRIX4T0(&sp140, &sp80, &sp100, sp150);
                    sp80 = sp140;
                    sp90 = sp150;
                    spA0 = sp160;
                    spB0 = sp170;
                }
            }
            asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
            temp_v0_2 = var_s4 + M2C_FIELD(arg3, s32 *, 0);
            asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf4, (%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf3, vf4x");
            asm volatile("vmadday.xyz ACC, vf5, vf4y");
            asm volatile("vmaddaz.xyz ACC, vf2, vf4z");
            asm volatile("vmaddw.xyz vf3, vf1, vf0w");
            asm volatile("sqc2 vf3, (%0)" : : "r"(temp_v0_2));
            if (temp_s1 != 3) {
                asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(sp));
                temp_v0_3 = var_s4 + M2C_FIELD(arg3, s32 *, 4);
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(&sp40));
                asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v0_3));
                asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(&sp40));
                asm volatile("vmulax.xyz ACC, vf4, vf1x");
                asm volatile("vmadday.xyz ACC, vf3, vf1y");
                asm volatile("vmaddz.xyz vf1, vf2, vf1z");
                asm volatile("sqc2 vf1, (%0)" : : "r"(temp_v0_3));
                if (temp_s1 != 2) {
                    var_v0 = sp70;
                    if (temp_s1 == 1) {
                        var_v0 = *(s32 *)(var_s4 + M2C_FIELD(arg3, s32 *, 0));
                    }
                    sp140 = var_v0;
                    asm volatile("lqc2 vf6, 0x140(%0)" : : "r"(sp));
                    temp_v0_4 = var_s4 + M2C_FIELD(arg3, s32 *, 4);
                    asm volatile("lqc2 vf3, 0x80(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf5, 0x90(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf4, 0xa0(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf2, 0xb0(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v0_4));
                    asm volatile("vmulax.xyz ACC, vf3, vf6x");
                    asm volatile("vmadday.xyz ACC, vf5, vf6y");
                    asm volatile("vmaddaz.xyz ACC, vf4, vf6z");
                    asm volatile("vmaddw.xyz vf3, vf2, vf0w");
                    asm volatile("vadd.xyzw vf1, vf1, vf3");
                    asm volatile("sqc2 vf1, (%0)" : : "r"(temp_v0_4));
                }
            }
            var_s6 += 1;
            temp_v0_5 = var_s4 + M2C_FIELD(arg3, s32 *, 4);
            asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
            asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v0_5));
            var_s4 += 0x10;
            asm volatile("vmulx.xyzw vf1, vf1, vf2x");
            asm volatile("sqc2 vf2, 0x140(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, (%0)" : : "r"(temp_v0_5));
        } while (var_s6 < sp180);
    }
    *M2C_FIELD(M2C_FIELD(temp_s5, s8 **, 0xE4), s32 **, 8) = sp188;
}
}
