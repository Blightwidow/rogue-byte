typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadRotateMatrixSinCos {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 LoadRotateMatrixSinCos(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0x30] __attribute__((aligned(16)));
    asm volatile("qmtc2.ni %0, vf6" : : "r"(arg2));
    asm volatile("qmtc2.ni %0, vf7" : : "r"(arg1));
    asm volatile("qmtc2.ni %0, vf8" : : "r"(arg3));
    asm volatile("vsubx.w vf5, vf0, vf6x");
    asm volatile("vsub.w vf1, vf0, vf0");
    asm volatile("vsub.w vf2, vf0, vf0");
    asm volatile("vsub.w vf3, vf0, vf0");
    asm volatile("vmulw.xyz vf5, vf8, vf5w");
    asm volatile("vmulx.xyz vf4, vf8, vf7x");
    asm volatile("vmulx.xyz vf1, vf5, vf8x");
    asm volatile("vmuly.xyz vf2, vf5, vf8y");
    asm volatile("vmulz.xyz vf3, vf5, vf8z");
    asm volatile("vaddx.x vf1, vf1, vf6x");
    asm volatile("vaddx.y vf2, vf2, vf6x");
    asm volatile("vaddx.z vf3, vf3, vf6x");
    asm volatile("vaddz.y vf1, vf1, vf4z");
    asm volatile("vsubz.x vf2, vf2, vf4z");
    asm volatile("vsuby.z vf1, vf1, vf4y");
    asm volatile("vaddy.x vf3, vf3, vf4y");
    asm volatile("vaddx.z vf2, vf2, vf4x");
    asm volatile("vsubx.y vf3, vf3, vf4x");
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(arg0));
    asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(arg0));
    asm volatile("sqc2 vf1, (%0)" : : "r"(arg0));
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
    return arg0;
}
}
