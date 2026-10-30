typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LaunchMatch__FP5MATCH {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ s128 sp60;                           /* inferred */
    /* 0x70 */ char pad70[0x10];
    /* 0x80 */ s128 sp80;                           /* inferred */
    /* 0x90 */ s128 sp90;                           /* inferred */
    /* 0xA0 */ s128 spA0;                           /* inferred */
    /* 0xB0 */ char padB0[0x20];
};                                                  /* size = 0xD0 */
#define sp90 (*(s128 *)(sp + 0x90))
#define spA0 (*(s128 *)(sp + 0xA0))
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, s8 *, s8 *, s128); /* extern */
M2C_UNK MatMulMatTransMat(s128 *);  /* extern */
s8 *PmatLoWorld(s8 *);                          /* extern */
s128 PosLoWorld(s8 *);                            /* extern */
M2C_UNK PredictXfTransform(s32, M2C_UNK, s8 *, M2C_UNK); /* extern */
void LaunchMatch__FP5MATCH(s8 *arg0) {
    s8 sp[0x90] __attribute__((aligned(16)));
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp80;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    s8 *temp_a1;
    s8 *temp_v0;
    s8 *temp_v0_2;
    M2C_FIELD(arg0, s128 *, 0x70) = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x104));
    temp_v0 = PmatLoWorld(M2C_FIELD(arg0, s8 **, 0x104));
    M2C_FIELD(arg0, s128 *, 0x40) = (s128) M2C_FIELD(temp_v0, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) M2C_FIELD(temp_v0, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(temp_v0, s128 *, 0x20);
    PredictXfTransform(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1C), s32 *, 0x60), 0, sp, 0);
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x18);
    asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf2, vf2, vf1");
    asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(arg0));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(1.0f / temp_f1));
    asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_f1 * -0.5f));
    asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(sp));
    asm volatile("vmulax.xyzw ACC, vf2, vf3x");
    asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
    asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(arg0));
    asm volatile("sqc2 vf4, 0x70(%0)" : : "r"(sp));
    MatMulMatTransMat(&sp80);
    sp40 = sp80;
    sp50 = sp90;
    sp60 = spA0;
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp40, arg0 + 0x100, arg0 + 0xF0, sp80);
    temp_f1_2 = M2C_FIELD(arg0, f32 *, 0x100);
    if (temp_f1_2 > 0.0f) {
        var_f0 = temp_f1_2 + 6.2831855f;
    } else {
        var_f0 = temp_f1_2 - 6.2831855f;
    }
    M2C_FIELD(arg0, f32 *, 0x100) = var_f0;
    temp_a1 = M2C_FIELD(arg0, s8 **, 0x104);
    temp_v0_2 = M2C_FIELD(temp_a1, s8 **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0_2, s16 *, 0x48), temp_a1);
    M2C_FIELD(arg0, s8 **, 0x104) = NULL;
}
}
