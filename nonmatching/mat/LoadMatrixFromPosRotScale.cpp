typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadMatrixFromPosRotScale {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
s8 *LoadMatrixFromPosRotScale(s8 *arg0, s128 arg1, s32 arg2, s8 *arg3) {
    s8 sp[0x10] __attribute__((aligned(16)));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(arg3, s32 *, 0)));
    asm volatile("lqc2 vf1, (%0)" : : "r"(arg2));
    asm volatile("vmulx.xyzw vf1, vf1, vf2x");
    asm volatile("sqc2 vf1, (%0)" : : "r"(arg0));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(arg2));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(M2C_FIELD(arg3, s32 *, 4)));
    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
    asm volatile("vmulx.xyzw vf1, vf1, vf3x");
    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg2));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(arg3, s32 *, 8)));
    asm volatile("vmulx.xyzw vf1, vf1, vf2x");
    M2C_FIELD(arg0, s128 *, 0x30) = arg1;
    asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(arg0));
    asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
    M2C_FIELD(arg0, f32 *, 0xC) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
    M2C_FIELD(arg0, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1C) = 0.0f;
    return arg0;
}
}
