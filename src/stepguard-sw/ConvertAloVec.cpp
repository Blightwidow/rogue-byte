typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ConvertAloVec {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
M2C_UNK InvertMatrix3(s8 *);                      /* extern */
s128 ConvertAloVec(s32 arg0, s32 arg1, s128 arg2) {
    s8 sp[0x40] __attribute__((aligned(16)));
    s32 fence;
    asm("qmtc2.ni %1, vf4" : "=r"(fence) : "r"(arg2));
    if (arg0 != 0) {
        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(arg0), "r"(fence));
        asm volatile("lqc2 vf2, (%0)" : : "r"(arg0));
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(arg0));
        asm volatile("vmulax.xyz ACC, vf2, vf4x");
        asm volatile("vmadday.xyz ACC, vf1, vf4y");
        asm volatile("vmaddz.xyz vf4, vf3, vf4z");
    }
    if (arg1 != 0) {
        asm volatile("sqc2 vf4, 0x30(%0)" : : "r"(sp));
        InvertMatrix3(sp);
        asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf3, vf4x");
        asm volatile("vmadday.xyz ACC, vf2, vf4y");
        asm volatile("vmaddz.xyz vf4, vf1, vf4z");
    }
    s128 vu_1;
    asm("qmfc2.ni %0, vf4" : "=r"(vu_1));
    return vu_1;
}
}
