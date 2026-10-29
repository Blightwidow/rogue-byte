typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ConvertMatPos {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
M2C_UNK InvertMatrix4Affine(s8 *);                /* extern */
s128 ConvertMatPos(s32 arg0, s32 arg1, s128 arg2) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s32 fence;
    asm("qmtc2.ni %1, vf5" : "=r"(fence) : "r"(arg2));
    if (arg0 != 0) {
        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(arg0), "r"(fence));
        asm volatile("lqc2 vf3, (%0)" : : "r"(arg0));
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg0));
        asm volatile("vmulax.xyz ACC, vf3, vf5x");
        asm volatile("vmadday.xyz ACC, vf2, vf5y");
        asm volatile("vmaddaz.xyz ACC, vf1, vf5z");
        asm volatile("vmaddw.xyz vf5, vf4, vf0w");
    }
    if (arg1 != 0) {
        asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
        InvertMatrix4Affine(sp);
        asm volatile("lqc2 vf4, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, 0x40(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf4, vf5x");
        asm volatile("vmadday.xyz ACC, vf3, vf5y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf5z");
        asm volatile("vmaddw.xyz vf5, vf1, vf0w");
    }
    s128 vu_1;
    asm("qmfc2.ni %0, vf5" : "=r"(vu_1));
    return vu_1;
}
}
