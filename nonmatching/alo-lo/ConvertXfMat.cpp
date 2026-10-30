typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ConvertXfMat {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ M2C_UNK sp30;                       /* inferred */
    /* 0x030 */ char pad30[0x30];
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0xA0];
};                                                  /* size = 0x100 */
M2C_UNK InvertMatrix3(M2C_UNK *, s32);              /* extern */
M2C_UNK memcpy(s32, s8 *, M2C_UNK);               /* extern */
s32 ConvertXfMat(s32 arg0, s32 arg1, s32 arg2, s8 *arg3) {
    s8 sp[0xb0] __attribute__((aligned(16)));
    M2C_UNK sp30;
    M2C_UNK sp60;
    s32 temp_v0;
    s32 temp_v0_2;
    if (arg1 != 0) {
        if (arg2 != 0) {
            InvertMatrix3(&sp60, arg2 + 0x40);
            asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(arg1));
            temp_v0 = arg1 + 0x40;
            asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
            asm volatile("lqc2 vf7, 0x70(%0)" : : "r"(sp));
            asm volatile("lqc2 vf5, 0x80(%0)" : : "r"(sp));
            asm volatile("lqc2 vf8, 0x20(%0)" : : "r"(arg3));
            asm volatile("vmulax.xyz ACC, vf3, vf4x");
            asm volatile("vmadday.xyz ACC, vf7, vf4y");
            asm volatile("vmaddz.xyz vf4, vf5, vf4z");
            asm volatile("sqc2 vf4, 0x30(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0));
            asm volatile("lqc2 vf6, (%0)" : : "r"(arg3));
            asm volatile("vmulax.xyz ACC, vf3, vf1x");
            asm volatile("vmadday.xyz ACC, vf7, vf1y");
            asm volatile("vmaddz.xyz vf1, vf5, vf1z");
            asm volatile("lqc2 vf9, 0x10(%0)" : : "r"(arg3));
            asm volatile("sqc2 vf4, 0x90(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_v0));
            asm volatile("vmulax.xyz ACC, vf3, vf2x");
            asm volatile("vmadday.xyz ACC, vf7, vf2y");
            asm volatile("vmaddz.xyz vf3, vf5, vf2z");
            asm volatile("sqc2 vf1, 0xa0(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf4, vf8x");
            asm volatile("vmadday.xyz ACC, vf1, vf8y");
            asm volatile("vmaddz.xyz vf8, vf3, vf8z");
            asm volatile("vmulax.xyz ACC, vf4, vf6x");
            asm volatile("vmadday.xyz ACC, vf1, vf6y");
            asm volatile("vmaddz.xyz vf6, vf3, vf6z");
            asm volatile("vmulax.xyz ACC, vf4, vf9x");
            asm volatile("vmadday.xyz ACC, vf1, vf9y");
            asm volatile("vmaddz.xyz vf4, vf3, vf9z");
            asm volatile("sqc2 vf3, 0xb0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, (%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf8, 0x20(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, 0x90(%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0xa0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf8, 0xb0(%0)" : : "r"(sp));
            memcpy(arg0, sp, 0x30);
        } else {
            temp_v0_2 = arg1 + 0x40;
            asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(arg1));
            asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(arg3));
            asm volatile("lqc2 vf2, (%0)" : : "r"(arg3));
            asm volatile("vmulax.xyz ACC, vf4, vf6x");
            asm volatile("vmadday.xyz ACC, vf1, vf6y");
            asm volatile("vmaddz.xyz vf6, vf5, vf6z");
            asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(arg3));
            asm volatile("vmulax.xyz ACC, vf4, vf2x");
            asm volatile("vmadday.xyz ACC, vf1, vf2y");
            asm volatile("vmaddz.xyz vf2, vf5, vf2z");
            asm volatile("vmulax.xyz ACC, vf4, vf3x");
            asm volatile("vmadday.xyz ACC, vf1, vf3y");
            asm volatile("vmaddz.xyz vf4, vf5, vf3z");
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, 0x20(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, 0x50(%0)" : : "r"(sp));
            memcpy(arg0, sp, 0x30);
        }
    } else if (arg2 != 0) {
        InvertMatrix3(&sp30, arg2 + 0x40);
        asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(arg3));
        asm volatile("lqc2 vf2, (%0)" : : "r"(arg3));
        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(arg3));
        asm volatile("vmulax.xyz ACC, vf4, vf6x");
        asm volatile("vmadday.xyz ACC, vf3, vf6y");
        asm volatile("vmaddz.xyz vf6, vf1, vf6z");
        asm volatile("vmulax.xyz ACC, vf4, vf2x");
        asm volatile("vmadday.xyz ACC, vf3, vf2y");
        asm volatile("vmaddz.xyz vf2, vf1, vf2z");
        asm volatile("sqc2 vf6, 0x20(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf4, vf5x");
        asm volatile("vmadday.xyz ACC, vf3, vf5y");
        asm volatile("vmaddz.xyz vf4, vf1, vf5z");
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf4, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x60(%0)" : : "r"(sp));
        asm volatile("sqc2 vf4, 0x70(%0)" : : "r"(sp));
        asm volatile("sqc2 vf6, 0x80(%0)" : : "r"(sp));
        memcpy(arg0, sp, 0x30);
    } else {
        memcpy(arg0, arg3, 0x30);
    }
    return arg0;
}
}
