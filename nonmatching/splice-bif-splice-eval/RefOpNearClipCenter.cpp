typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefOpNearClipCenter {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK CRef_ConstructVectorValue(s32, M2C_UNK, s128, s128); /* extern */
extern M2C_UNK B_002DDF40;
s32 RefOpNearClipCenter(s32 arg0) {
    s128 temp_a2;
    s8 *temp_v1;
    temp_v1 = (s8 *)(&B_002DDF40 + 0x60);
    s64 vu_1;
    asm volatile("pextlw %0, %1, %0" : "=r"(vu_1) : "r"(0), "r"(M2C_FIELD(&B_002DDF40, f32 *, 0x4C)));
    s64 vu_2;
    asm volatile("pcpyld %0, %1, %0" : "=r"(vu_2) : "r"(0), "r"(vu_1));
    temp_a2 = vu_2;
    asm volatile("lqc2 vf4, 0x60(%0)" : : "r"(&B_002DDF40));
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(temp_v1));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v1));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v1));
    asm volatile("qmtc2.ni %0, vf5" : : "r"(temp_a2));
    asm volatile("vmulax.xyz ACC, vf4, vf5x");
    asm volatile("vmadday.xyz ACC, vf2, vf5y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf5z");
    asm volatile("vmaddw.xyz vf5, vf3, vf0w");
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_3));
    CRef_ConstructVectorValue(arg0, vu_3, temp_a2, temp_a2);
    return arg0;
}
}
