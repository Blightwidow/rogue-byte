typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RenderSmack {
    /* 0x000 */ char pad0[0x90];
    /* 0x090 */ M2C_UNK sp90;                       /* inferred */
    /* 0x090 */ char pad90[0x30];
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ s128 spF0;                          /* inferred */
    /* 0x100 */ char pad100[0x60];                  /* maybe part of spF0[7]? */
    /* 0x160 */ f32 sp160;                          /* inferred */
    /* 0x164 */ char pad164[0x7C];
};                                                  /* size = 0x1E0 */
#define spE0 (*(s128 *)(sp + 0x0E0))
#define spF0 (*(s128 *)(sp + 0x0F0))
s32 ConvertCmScreenToWorld(M2C_UNK *, s128);
void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s8 *, f32 *, s128 *, s128, s128, s128, s128);
s32 FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(s8 *, M2C_UNK, M2C_UNK *);
s32 LoadRotateMatrixRad(...);
s32 MatMulMatTransMat(s128 *, s32, s8 *);
extern M2C_UNK B_002DDF40;
extern f32 g_2dded0;
void RenderSmack(s8 *arg0) {
    s8 sp[0x130] __attribute__((aligned(16)));
    M2C_UNK sp90;
    s128 spC0;
    s128 spD0;
    f32 sp160;
    M2C_UNK temp_s4;
    f32 temp_f20;
    s32 temp_s3;
    temp_s3 = (s32)(arg0 + 0x40);
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(ConvertCmScreenToWorld(&B_002DDF40, M2C_FIELD(arg0, s128 *, 0x100))));
    temp_s4 = vu_1;
    MatMulMatTransMat(&spD0, temp_s3, (s8 *)(&B_002DDF40 + 0x60));
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(sp, &sp160, &spC0, spD0, spD0, spE0, spF0);
    temp_f20 = (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x14)) / M2C_FIELD(arg0, f32 *, 0x18);
    LoadRotateMatrixRad(&spD0, spC0, sp160 * temp_f20);
    LoadRotateMatrixRad(&spD0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xF0), s128 *, 0x40), 2.0f * temp_f20 * 3.1415927f, spD0, spE0, spF0);
    asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
    asm volatile("lqc2 vf9, 0xd0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf7, 0xf0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf3, vf7x");
    asm volatile("vmadday.xyz ACC, vf2, vf7y");
    asm volatile("vmaddz.xyz vf5, vf1, vf7z");
    asm volatile("vmulax.xyz ACC, vf3, vf9x");
    asm volatile("vmadday.xyz ACC, vf2, vf9y");
    asm volatile("vmaddz.xyz vf4, vf1, vf9z");
    asm volatile("lqc2 vf8, 0xe0(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf3, vf8x");
    asm volatile("vmadday.xyz ACC, vf2, vf8y");
    asm volatile("vmaddz.xyz vf3, vf1, vf8z");
    asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(temp_s3));
    asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(arg0));
    asm volatile("vmulax.xyz ACC, vf4, vf6x");
    asm volatile("vmadday.xyz ACC, vf3, vf6y");
    asm volatile("vmaddz.xyz vf6, vf5, vf6z");
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_s3));
    asm volatile("vmulax.xyz ACC, vf4, vf1x");
    asm volatile("vmadday.xyz ACC, vf3, vf1y");
    asm volatile("vmaddz.xyz vf1, vf5, vf1z");
    asm volatile("vmulax.xyz ACC, vf4, vf2x");
    asm volatile("vmadday.xyz ACC, vf3, vf2y");
    asm volatile("vmaddz.xyz vf2, vf5, vf2z");
    asm volatile("sqc2 vf4, 0x130(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x140(%0)" : : "r"(sp));
    asm volatile("sqc2 vf5, 0x150(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x90(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0xa0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf6, 0xb0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf9, 0x60(%0)" : : "r"(sp));
    asm volatile("sqc2 vf8, 0x70(%0)" : : "r"(sp));
    asm volatile("sqc2 vf7, 0x80(%0)" : : "r"(sp));
    asm volatile("sqc2 vf4, 0x100(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x110(%0)" : : "r"(sp));
    asm volatile("sqc2 vf5, 0x120(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x130(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0xd0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x140(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0xe0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf6, 0x150(%0)" : : "r"(sp));
    asm volatile("sqc2 vf6, 0xf0(%0)" : : "r"(sp));
    s64 vu_2;
    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s4));
    FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(arg0, vu_2, &sp90);
}
}
