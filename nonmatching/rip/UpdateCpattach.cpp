typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateCpattach {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ M2C_UNK spE0;                       /* inferred */
    /* 0x0E0 */ char padE0[0x60];
    /* 0x140 */ f32 sp140;                          /* inferred */
    /* 0x144 */ char pad144[0x5C];
};                                                  /* size = 0x1A0 */
#define spC0 (*(s128 *)(sp + 0x0C0))
#define spD0 (*(s128 *)(sp + 0x0D0))
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, f32 *, s128 *, s128); /* extern */
f32 GSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, M2C_UNK, f32); /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
M2C_UNK MatMulMatTransMat(s128 *, s8 *, s8 *);  /* extern */
M2C_UNK SetCmFov(M2C_UNK *, f32);                   /* extern */
M2C_UNK SetCmPosMat(M2C_UNK *, s8 *);             /* extern */
M2C_UNK UpdateCplcy();                              /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s128 *, M2C_UNK);  /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_002BDAB0;
extern M2C_UNK D_002BDAC0;
extern f32 g_2dded4;
void UpdateCpattach(s8 **arg0) {
    s32 unksp1C;
    s32 unksp2C;
    s32 unksp3C;
    s32 unkspC;
    s8 sp[0xf0] __attribute__((aligned(16)));
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    s128 sp80;
    s128 sp90;
    s128 spA0;
    s128 spB0;
    M2C_UNK spE0;
    f32 sp140;
    f32 temp_v0_2;
    s8 *temp_a1;
    s8 *temp_s1;
    s8 *temp_v0;
    s8 *temp_v1;
    UpdateCplcy();
    temp_s1 = *arg0;
    temp_a1 = M2C_FIELD(temp_s1, s8 **, 0x1D0);
    temp_v1 = M2C_FIELD(temp_a1, s8 **, 0xC);
    temp_v0 = M2C_FIELD(temp_v1, s8 *(**)(s8 *, s8 *), 0xFC)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0xF8), temp_a1);
    sp0 = M2C_FIELD(temp_v0, s128 *, 0);
    sp10 = M2C_FIELD(temp_v0, s128 *, 0x10);
    sp20 = M2C_FIELD(temp_v0, s128 *, 0x20);
    sp30 = M2C_FIELD(temp_v0, s128 *, 0x30);
    if ((M2C_FIELD(&B_002DDF40, s32 *, 0x300) == 0) && (M2C_FIELD(temp_s1, s32 *, 0x1D4) != 0)) {
        MatMulMatTransMat(&spB0, sp, (s8 *)(&B_002DDF40 + 0x60));
        sp40 = spB0;
        sp50 = spC0;
        sp60 = spD0;
        DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp40, &sp140, &spA0, spB0);
        if (sp140 < 0.0001f) {
            sp70 = sp0;
            sp80 = sp10;
            sp90 = sp20;
        } else {
            LoadRotateMatrixRad(&spE0, spA0, GSmooth__FfffP3SMPPf(&D_002BDAB0, 0, sp140, 0, g_2dded4));
            asm volatile("lqc2 vf1, 0xe0(%0)" : : "r"(sp));
            asm volatile("lqc2 vf4, 0xf0(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x100(%0)" : : "r"(sp));
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
            asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(sp));
            asm volatile("sqc2 vf5, 0x80(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0x90(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x110(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0xb0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf5, 0x120(%0)" : : "r"(sp));
            asm volatile("sqc2 vf5, 0xc0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0x130(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0xd0(%0)" : : "r"(sp));
        }
        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(&B_002DDF40));
        asm volatile("vsub.xyzw vf3, vf1, vf4");
        asm volatile("vmul.xyz vf1, vf3, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_v0_2 = vu_1;
        asm volatile("vmove.xyzw vf1, vf4");
        if (!(temp_v0_2 < 0.0001f)) {
            asm volatile("sqc2 vf3, 0x150(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, 0x150(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf1" : : "r"(GSmooth__FfffP3SMPPf(&D_002BDAC0, 0, temp_v0_2, 0, g_2dded4) / temp_v0_2));
            asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(sp));
            asm volatile("vadda.xyzw ACC, vf0, vf2");
            asm volatile("vmaddx.xyzw vf1, vf3, vf1x");
        }
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
        __as__6VECTORG9VU_VECTOR(&sp30, vu_2);
        sp0 = sp70;
        sp10 = sp80;
        sp20 = sp90;
        unksp3C = 1.0f;
        unksp2C = 0;
        unksp1C = 0;
        unkspC = 0;
    }
    SetCmPosMat(&B_002DDF40, sp);
    if (M2C_FIELD(&B_002DDF40, f32 *, 0x24) == M2C_FIELD(&B_002DDF40, f32 *, 0x20)) {
        SetCmFov(&B_002DDF40, M2C_FIELD(temp_s1, f32 *, 0x1BC));
        return;
    }
    M2C_FIELD(&B_002DDF40, f32 *, 0x24) = (f32) M2C_FIELD(temp_s1, f32 *, 0x1BC);
}
}
