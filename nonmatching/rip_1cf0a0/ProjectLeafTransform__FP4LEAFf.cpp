typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ProjectLeafTransform__FP4LEAFf {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ M2C_UNK sp40;                        /* inferred */
    /* 0x40 */ char pad40[0x50];
    /* 0x90 */ s128 sp90;                           /* inferred */
    /* 0xA0 */ char padA0[0x40];
};                                                  /* size = 0xE0 */
M2C_UNK LoadRotateMatrixRad(s8 *, M2C_UNK, s128, f32, f32); /* extern */
M2C_UNK ProjectRipTransform__FP3RIPf(s8 *);       /* extern */
M2C_UNK SProjectVector__FP6VECTORT0(M2C_UNK, s128, s128 *, M2C_UNK *); /* extern */
extern s128 g_2a2da0;
extern M2C_UNK g_2c2010;
extern M2C_UNK g_2c2020;
extern f32 g_2c2028;
extern f32 g_2c202c;
extern M2C_UNK g_2dded0;
void ProjectLeafTransform__FP4LEAFf(s8 *arg0) {
    s8 sp[0x80] __attribute__((aligned(16)));
    s128 sp30;
    M2C_UNK sp40;
    s128 sp90;
    M2C_UNK temp_a0;
    f32 temp_a3;
    f32 temp_f20;
    f32 var_f0;
    s128 temp_a2;
    s8 *temp_v0;
    sp90 = M2C_FIELD(arg0, s128 *, 0x40);
    asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf1, vf1, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_a3 = vu_1;
    temp_a2 = M2C_FIELD(arg0, s128 *, 0x50);
    var_f0 = M2C_FIELD(&g_2c2010, f32 *, 0) + (temp_a3 * (M2C_FIELD(&g_2c2010, f32 *, 4) + (temp_a3 * M2C_FIELD(&g_2c2010, f32 *, 8))));
    if (var_f0 < M2C_FIELD(&g_2c2020, f32 *, 0)) {
        var_f0 = M2C_FIELD(&g_2c2020, f32 *, 0);
    } else if (M2C_FIELD(&g_2c2020, f32 *, 4) < var_f0) {
        var_f0 = M2C_FIELD(&g_2c2020, f32 *, 4);
    }
    s64 vu_2;
    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_a2));
    LoadRotateMatrixRad(sp, vu_2, temp_a2, temp_a3, var_f0 * M2C_FIELD(&g_2dded0, f32 *, 4));
    asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
    temp_v0 = arg0 + 0x40;
    asm volatile("lqc2 vf6, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(arg0));
    asm volatile("vmulax.xyz ACC, vf3, vf1x");
    asm volatile("vmadday.xyz ACC, vf6, vf1y");
    asm volatile("vmaddz.xyz vf1, vf5, vf1z");
    asm volatile("vmulax.xyz ACC, vf3, vf4x");
    asm volatile("vmadday.xyz ACC, vf6, vf4y");
    asm volatile("vmaddz.xyz vf4, vf5, vf4z");
    asm volatile("sqc2 vf1, 0x90(%0)" : : "r"(arg0));
    temp_f20 = M2C_FIELD(arg0, f32 *, 0xC4);
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
    temp_a0 = vu_3;
    asm volatile("sqc2 vf4, 0x30(%0)" : : "r"(sp));
    asm volatile("sqc2 vf4, 0x60(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
    asm volatile("vmulax.xyz ACC, vf3, vf2x");
    asm volatile("vmadday.xyz ACC, vf6, vf2y");
    asm volatile("vmaddz.xyz vf2, vf5, vf2z");
    asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0));
    asm volatile("vmulax.xyz ACC, vf3, vf1x");
    asm volatile("vmadday.xyz ACC, vf6, vf1y");
    asm volatile("vmaddz.xyz vf3, vf5, vf1z");
    asm volatile("sqc2 vf2, 0x50(%0)" : : "r"(arg0));
    asm volatile("sqc2 vf3, 0x60(%0)" : : "r"(arg0));
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
    asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(arg0));
    asm volatile("sqc2 vf3, 0x80(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
    SProjectVector__FP6VECTORT0(temp_a0, sp90, &sp30, &sp40);
    asm volatile("qmtc2.ni %0, vf3" : : "r"(sp30));
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    s32 vu_4;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_4));
    if (vu_4 < 0.0001f) {
        sp30 = g_2a2da0;
    } else {
        asm volatile("vdiv Q, vf0w, vf2x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf3, Q");
        asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
    }
    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(sp));
    asm volatile("qmtc2.ni %0, vf3" : : "r"((temp_f20 * M2C_FIELD(&g_2dded0, f32 *, 4)) + 1.0f));
    s32 vu_5;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_5));
    asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2c2028 + (((g_2c202c * M2C_FIELD(&g_2dded0, f32 *, 4)) + 1.0f) * (vu_5 - g_2c2028))));
    asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(sp));
    asm volatile("vmulax.xyzw ACC, vf2, vf1x");
    asm volatile("vmaddx.xyzw vf2, vf4, vf3x");
    asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(arg0));
    asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
    ProjectRipTransform__FP3RIPf(arg0);
    M2C_FIELD(arg0, f32 *, 0xC4) = temp_f20;
}
}
