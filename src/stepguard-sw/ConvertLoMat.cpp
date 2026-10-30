typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ConvertLoMat {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ char pad30[0x30];                   /* maybe part of sp20[4]? */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0xA0];
};                                                  /* size = 0x100 */
M2C_UNK InvertMatrix3(M2C_UNK *, s32);              /* extern */
s32 PmatLoWorld(s32);                               /* extern */
s8 *ConvertLoMat(s8 *arg0, s32 arg1, s32 arg2, s8 *arg3) {
    s8 sp[0xC0] __attribute__((aligned(16)));
    s32 temp_v0;
    if (arg1 != 0) {
        temp_v0 = PmatLoWorld(arg1);
        asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(temp_v0));
        asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v0));
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
        asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(arg3));
        asm volatile("lqc2 vf3, (%0)" : : "r"(arg3));
        asm volatile("vmulax.xyz ACC, vf1, vf6x");
        asm volatile("vmadday.xyz ACC, vf2, vf6y");
        asm volatile("vmaddz.xyz vf6, vf4, vf6z");
        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(arg3));
        asm volatile("vmulax.xyz ACC, vf1, vf3x");
        asm volatile("vmadday.xyz ACC, vf2, vf3y");
        asm volatile("vmaddz.xyz vf3, vf4, vf3z");
        asm volatile("vmulax.xyz ACC, vf1, vf5x");
        asm volatile("vmadday.xyz ACC, vf2, vf5y");
        asm volatile("vmaddz.xyz vf1, vf4, vf5z");
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf6, 0x20(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x60(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x70(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
        asm volatile("sqc2 vf6, 0x80(%0)" : : "r"(sp));
        asm volatile("sqc2 vf6, 0x50(%0)" : : "r"(sp));
    } else {
        M2C_FIELD(sp, s128 *, 0x0) = M2C_FIELD(arg3, s128 *, 0);
        M2C_FIELD(sp, s128 *, 0x10) = M2C_FIELD(arg3, s128 *, 0x10);
        M2C_FIELD(sp, s128 *, 0x20) = M2C_FIELD(arg3, s128 *, 0x20);
    }
    if (arg2 != 0) {
        InvertMatrix3((M2C_UNK *)(sp + 0x60), PmatLoWorld(arg2));
        asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x70(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf1, vf3x");
        asm volatile("vmadday.xyz ACC, vf4, vf3y");
        asm volatile("vmaddz.xyz vf3, vf2, vf3z");
        asm volatile("vmulax.xyz ACC, vf1, vf5x");
        asm volatile("vmadday.xyz ACC, vf4, vf5y");
        asm volatile("vmaddz.xyz vf5, vf2, vf5z");
        asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf1, vf6x");
        asm volatile("vmadday.xyz ACC, vf4, vf6y");
        asm volatile("vmaddz.xyz vf1, vf2, vf6z");
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf5, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x90(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf5, 0xa0(%0)" : : "r"(sp));
        asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(sp));
    }
    M2C_FIELD(arg0, s128 *, 0) = M2C_FIELD(sp, s128 *, 0x0);
    M2C_FIELD(arg0, s128 *, 0x10) = M2C_FIELD(sp, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x20) = M2C_FIELD(sp, s128 *, 0x20);
    return arg0;
}
}
