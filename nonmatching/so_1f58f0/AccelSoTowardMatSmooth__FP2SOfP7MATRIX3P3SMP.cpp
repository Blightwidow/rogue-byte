typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x40];
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ f32 spE0;                           /* inferred */
    /* 0x0E4 */ char padE4[0x5C];
};                                                  /* size = 0x140 */
#define spC0 (*(s128 *)(sp + 0x0C0))
#define spD0 (*(s128 *)(sp + 0x0D0))
M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s32, s32);    /* extern */
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, f32 *, M2C_UNK *, s128); /* extern */
f32 GLimitAbs__Fff(f32, f32);                       /* extern */
M2C_UNK MatMulMatTransMat(s128 *, s8 *, s8 *);  /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(s8 *, s128, s128, s128, s128); /* extern */
extern M2C_UNK g_2dded0;
void AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(s8 *arg0, s32 arg1, s8 *arg2) {
    s8 sp[0xb0] __attribute__((aligned(16)));
    s128 sp30;
    s128 sp40;
    s128 sp50;
    M2C_UNK sp60;
    s128 spA0;
    s128 spB0;
    f32 spE0;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_v0;
    f32 temp_v0_2;
    f32 var_f0;
    f32 var_f5;
    s8 *temp_s0;
    temp_f20 = M2C_FIELD(arg2, f32 *, 0);
    temp_s0 = M2C_FIELD(arg0, s8 **, 0x5C);
    asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_s0));
    temp_f22 = (temp_f20 - M2C_FIELD(arg2, f32 *, 4)) / M2C_FIELD(arg2, f32 *, 8);
    asm volatile("vmul.xyz vf1, vf1, vf1");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v0 = vu_1;
    temp_f21 = (temp_f20 * temp_f20) / (2.0f * temp_f22);
    if (temp_f20 < temp_v0) {
        asm volatile("qmtc2.ni %0, vf2" : : "r"(((temp_f20 - temp_v0) * 2.5f) / temp_v0));
        asm volatile("sqc2 vf2, 0xa0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_s0));
        asm volatile("vmulx.xyzw vf2, vf1, vf2x");
        asm volatile("sqc2 vf2, 0x80(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0xf0(%0)" : : "r"(temp_s0));
        asm volatile("vadd.xyzw vf1, vf1, vf2");
        asm volatile("sqc2 vf1, 0xf0(%0)" : : "r"(temp_s0));
    }
    ConvertXfMat(&spB0, 0, M2C_FIELD(temp_s0, s32 *, 0xA0), arg1);
    NormalizeRotateMatrix3__FP7MATRIX3(sp, spB0, spB0, spC0, spD0);
    MatMulMatTransMat(&spA0, temp_s0, sp);
    sp50 = spC0;
    sp30 = spA0;
    sp40 = spB0;
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp30, &spE0, &sp60, spA0);
    asm volatile("lqc2 vf2, 0xb0(%0)" : : "r"(temp_s0));
    asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf2, vf2, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    var_f5 = GLimitAbs__Fff((spE0 / temp_f21) * temp_f20, temp_f20);
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
    temp_f0 = spE0 - ((vu_2 + var_f5) * (M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f));
    if (temp_f0 < temp_f21) {
        var_f5 = GLimitAbs__Fff((temp_f0 / temp_f21) * temp_f20, temp_f20);
    }
    asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f5));
    asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
    asm volatile("vmulx.xyzw vf3, vf3, vf1x");
    asm volatile("sqc2 vf1, 0xa0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0xb0(%0)" : : "r"(temp_s0));
    asm volatile("qmtc2.ni %0, vf4" : : "r"(M2C_FIELD(&g_2dded0, f32 *, 4)));
    asm volatile("sqc2 vf4, 0xa0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0xf0(%0)" : : "r"(temp_s0));
    asm volatile("vadda.xyzw ACC, vf0, vf2");
    asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
    asm volatile("vsub.xyzw vf4, vf3, vf2");
    asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf1, vf4, vf4");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf3, vf1z");
    asm volatile("sqc2 vf4, 0x80(%0)" : : "r"(sp));
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
    temp_v0_2 = vu_3;
    if (temp_v0_2 < (temp_f22 * M2C_FIELD(&g_2dded0, f32 *, 4))) {
        var_f0 = 1.0f / M2C_FIELD(&g_2dded0, f32 *, 4);
    } else {
        var_f0 = temp_f22 / temp_v0_2;
    }
    asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f0));
    asm volatile("vmulx.xyzw vf2, vf4, vf1x");
    asm volatile("sqc2 vf1, 0xa0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x80(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0xf0(%0)" : : "r"(temp_s0));
    asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(sp));
    asm volatile("vadd.xyzw vf1, vf1, vf2");
    asm volatile("sqc2 vf1, 0xf0(%0)" : : "r"(temp_s0));
}
}
