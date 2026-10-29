typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PosCplookAnchor {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0x20];
};                                                  /* size = 0x40 */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);
s32 PosLoWorld(s32);
extern M2C_UNK g_2a2dc0;
s128 PosCplookAnchor(s32 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    s128 sp10;
    sp10 = PosLoWorld(*arg0);
    if (FIsBasicDerivedFrom(*arg0, 0x34) != 0) {
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(0x43160000));
        asm volatile("vadda.xyzw ACC, vf0, vf3");
        asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
    }
    return sp10;
}
}
