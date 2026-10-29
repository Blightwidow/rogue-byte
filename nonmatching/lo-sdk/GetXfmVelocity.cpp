typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetXfmVelocity {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
s128 VelocityXfAtPos(s32, M2C_UNK, M2C_UNK);        /* extern */
extern s128 g_2a2dd0;
s128 GetXfmVelocity(s8 *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    temp_v0 = temp_v1 + 0x40;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_v1 != 0) {
        asm volatile("lqc2 vf5, 0x90(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(temp_v0));
        asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(temp_v1));
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0));
        asm volatile("vmulax.xyz ACC, vf3, vf5x");
        asm volatile("vmadday.xyz ACC, vf2, vf5y");
        asm volatile("vmaddaz.xyz ACC, vf1, vf5z");
        asm volatile("vmaddw.xyz vf6, vf4, vf0w");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_1));
        return VelocityXfAtPos(temp_v1, 0, vu_1);
    }
    return g_2a2dd0;
}
}
