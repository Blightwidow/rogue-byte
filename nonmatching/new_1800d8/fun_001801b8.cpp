typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001801B8 {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ M2C_UNK sp30;                       /* inferred */
    /* 0x030 */ char pad30[0x30];
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x60];
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ char padD0[0x40];
};                                                  /* size = 0x110 */
f32 GLimitAbs__Fff(f32, f32);
s32 LoadRotateMatrixRad(M2C_UNK *, s128, f32);
s32 PosLoWorld(s8 *);
f32 RadNormalize__Ff(f32);
void UpdateSo();
f32 atan2f(M2C_UNK, M2C_UNK);
extern s128 g_2a2dc0;
extern f32 g_2dded0;
extern f32 g_2dded4;
void func_001801B8(s8 *arg0) {
    s8 sp[0xa0] __attribute__((aligned(16)));
    M2C_UNK sp30;
    M2C_UNK sp60;
    s128 spC0;
    M2C_UNK temp_s0;
    M2C_UNK temp_v0_2;
    f32 temp_f20;
    s8 *temp_a0;
    s8 *temp_v0;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v1;
    UpdateSo();
    if ((M2C_FIELD(arg0, s32 *, 0x18C) == 0) && (M2C_FIELD(arg0, f32 *, 0x1C0) <= g_2dded0)) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK), 0x294)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x290), 0);
    }
    temp_a0 = M2C_FIELD(arg0, s8 **, 0x1D0);
    if ((temp_a0 != NULL) && (M2C_FIELD(arg0, f32 *, 0x1D4) != 0.0f)) {
        spC0 = PosLoWorld(temp_a0);
        asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0)));
        asm volatile("lqc2 vf1, 0xc0(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_v0_2 = vu_1;
        temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
        s64 vu_2;
        asm volatile("prot3w %0, %1" : "=r"(vu_2) : "r"(temp_v0_2));
        temp_f20 = atan2f(vu_2, temp_v0_2);
        s64 vu_3;
        asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(M2C_FIELD(temp_v1, s32 (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108))));
        temp_s0 = vu_3;
        s64 vu_4;
        asm volatile("prot3w %0, %1" : "=r"(vu_4) : "r"(temp_s0));
        LoadRotateMatrixRad(&sp60, g_2a2dc0, GLimitAbs__Fff(RadNormalize__Ff(temp_f20 - atan2f(vu_4, temp_s0)), M2C_FIELD(arg0, f32 *, 0x1D4) * g_2dded4));
        asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x80(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_s0));
        asm volatile("vmulax.xyz ACC, vf1, vf4x");
        asm volatile("vmadday.xyz ACC, vf2, vf4y");
        asm volatile("vmaddz.xyz vf4, vf3, vf4z");
        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
        s32 vu_5;
        asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_5));
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x118), vu_5);
        asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf6, 0x40(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf3, vf5x");
        asm volatile("vmadday.xyz ACC, vf2, vf5y");
        asm volatile("vmaddz.xyz vf5, vf1, vf5z");
        asm volatile("vmulax.xyz ACC, vf3, vf6x");
        asm volatile("vmadday.xyz ACC, vf2, vf6y");
        asm volatile("vmaddz.xyz vf6, vf1, vf6z");
        asm volatile("lqc2 vf4, 0x50(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf3, vf4x");
        asm volatile("vmadday.xyz ACC, vf2, vf4y");
        asm volatile("vmaddz.xyz vf3, vf1, vf4z");
        asm volatile("sqc2 vf5, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf6, 0x40(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
        asm volatile("sqc2 vf5, 0x60(%0)" : : "r"(sp));
        asm volatile("sqc2 vf6, 0x70(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x80(%0)" : : "r"(sp));
        temp_v0_4 = M2C_FIELD(arg0, s8 **, 0xC);
        asm volatile("sqc2 vf5, 0x90(%0)" : : "r"(sp));
        asm volatile("sqc2 vf6, 0xa0(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0xb0(%0)" : : "r"(sp));
        M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, M2C_UNK *), 0xF4)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0xF0), &sp30);
    }
}
}
