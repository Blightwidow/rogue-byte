typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x10];
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ f32 spA0;                           /* inferred */
    /* 0x0A4 */ char padA4[0x6C];
};                                                  /* size = 0x110 */
#define sp80 (*(s128 *)(sp + 0x080))
#define sp90 (*(s128 *)(sp + 0x090))
M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s32, s32);    /* extern */
s32 ConvertXfVec(M2C_UNK, s32, M2C_UNK);            /* extern */
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, f32 *, M2C_UNK *, s128); /* extern */
M2C_UNK MatMulMatTransMat(s128 *, s8 *, s8 *);  /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(s8 *, s128, s128, s128, s128); /* extern */
extern f32 g_2dded4;
void AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(s8 *arg0, s32 arg1, s8 *arg2, s32 arg3, s8 *arg4) {
    s8 sp[0x80] __attribute__((aligned(16)));
    s128 sp30;
    s128 sp40;
    s128 sp50;
    M2C_UNK sp60;
    s128 sp70;
    f32 spA0;
    M2C_UNK temp_a2;
    M2C_UNK temp_s4;
    f32 temp_f0;
    f32 temp_v0;
    f32 var_f1;
    s8 *temp_s1;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg3));
    temp_s4 = vu_1;
    temp_s1 = M2C_FIELD(arg0, s8 **, 0x5C);
    if (arg2 != NULL) {
        ConvertXfMat(&sp70, 0, M2C_FIELD(temp_s1, s32 *, 0xA0), arg1);
        NormalizeRotateMatrix3__FP7MATRIX3(sp, sp70, sp70, sp80, sp90);
        MatMulMatTransMat(&sp70, temp_s1, sp);
        sp30 = sp70;
        sp40 = sp80;
        sp50 = sp90;
        DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp30, &spA0, &sp60, sp70);
        asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
        if (spA0 > 0.0001f) {
            asm volatile("lqc2 vf2, 0xf0(%0)" : : "r"(temp_s1));
            asm volatile("qmtc2.ni %0, vf1" : : "r"((M2C_FIELD(arg2, f32 *, 8) * spA0 * spA0) + (M2C_FIELD(arg2, f32 *, 4) * spA0) + M2C_FIELD(arg2, f32 *, 0)));
            asm volatile("vadda.xyzw ACC, vf0, vf2");
            asm volatile("vmaddx.xyzw vf2, vf3, vf1x");
            asm volatile("sqc2 vf1, 0x70(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0xf0(%0)" : : "r"(temp_s1));
        }
    }
    s64 vu_2;
    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s4));
    temp_a2 = vu_2;
    if (arg4 != NULL) {
        asm volatile("qmtc2.ni %0, vf2" : : "r"(ConvertXfVec(0, M2C_FIELD(temp_s1, s32 *, 0xA0), temp_a2)));
        asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_s1));
        asm volatile("vsub.xyzw vf3, vf2, vf1");
        asm volatile("vmul.xyz vf1, vf3, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
        temp_v0 = vu_3;
        if (temp_v0 > 0.0001f) {
            temp_f0 = 1.0f / g_2dded4;
            var_f1 = (M2C_FIELD(arg4, f32 *, 8) * temp_v0) + M2C_FIELD(arg4, f32 *, 4) + (M2C_FIELD(arg4, f32 *, 0) / temp_v0);
            if (temp_f0 < var_f1) {
                var_f1 = temp_f0;
            }
            asm volatile("lqc2 vf1, 0xf0(%0)" : : "r"(temp_s1));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(var_f1));
            asm volatile("vadda.xyzw ACC, vf0, vf1");
            asm volatile("vmaddx.xyzw vf1, vf3, vf2x");
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0xf0(%0)" : : "r"(temp_s1));
        }
    }
}
}
