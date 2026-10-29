typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0017A468 {};                 /* size 0x0 */
void func_0017A468(s8 *arg0) {
    s8 *temp_a1;
    s8 *temp_a2;
    temp_a1 = M2C_FIELD(arg0, s8 **, 0x10);
    temp_a2 = arg0 + 0x70;
    asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(temp_a2));
    asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(M2C_FIELD(temp_a1, s32 *, 0xF90)));
    asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(M2C_FIELD(temp_a1, s32 *, 0x60)));
    asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(temp_a2));
    asm volatile("vsub.xyzw vf1, vf1, vf4");
    asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(arg0));
    asm volatile("vmulax.xyz ACC, vf2, vf3x");
    asm volatile("vmadday.xyz ACC, vf5, vf3y");
    asm volatile("vmaddz.xyz vf3, vf6, vf3z");
    asm volatile("vsub.xyzw vf1, vf1, vf3");
    asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(arg0));
}
}
