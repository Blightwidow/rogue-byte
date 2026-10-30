typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ProjectRipTransform__FP3RIPf {
    /* 0x00 */ char pad0[0x50];
    /* 0x50 */ M2C_UNK sp50;                        /* inferred */
    /* 0x50 */ char pad50[0x90];
};                                                  /* size = 0xE0 */
M2C_UNK CalculateEmitdvMatrix(s8 *, s8 *);      /* extern */
s32 FIsZeroDv__FP6VECTOR(s128);                     /* extern */
s32 FIsZeroV__FP6VECTOR(s128);                      /* extern */
s32 FIsZeroW__FP6VECTOR(s128);                      /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, M2C_UNK, f32); /* extern */
extern M2C_UNK g_2dded0;
extern s32 g_2dded4;
void ProjectRipTransform__FP3RIPf(s8 *arg0) {
    s8 sp[0xa0] __attribute__((aligned(16)));
    M2C_UNK sp50;
    f32 temp_v1;
    s32 var_s1;
    s8 *temp_v0;
    if (FIsZeroW__FP6VECTOR(M2C_FIELD(arg0, s128 *, 0xD0)) == 0) {
        asm volatile("lqc2 vf1, 0xd0(%0)" : : "r"(arg0));
        asm volatile("qmtc2.ni %0, vf2" : : "r"((M2C_FIELD(arg0, f32 *, 0xE4) * M2C_FIELD(&g_2dded0, f32 *, 4)) + 1.0f));
        asm volatile("vmulx.xyzw vf4, vf1, vf2x");
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("vmul.xyz vf1, vf4, vf4");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf3, vf1z");
        asm volatile("sqc2 vf4, 0xd0(%0)" : : "r"(arg0));
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_v1 = vu_1;
        if (temp_v1 > 0.0001f) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(temp_v1));
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf2, vf4, Q");
            asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
            LoadRotateMatrixRad(&sp50, vu_2, temp_v1 * M2C_FIELD(&g_2dded0, f32 *, 4));
            asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(arg0));
            temp_v0 = arg0 + 0x40;
            asm volatile("lqc2 vf3, 0x50(%0)" : : "r"(sp));
            asm volatile("lqc2 vf6, 0x60(%0)" : : "r"(sp));
            asm volatile("lqc2 vf5, 0x70(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf3, vf4x");
            asm volatile("vmadday.xyz ACC, vf6, vf4y");
            asm volatile("vmaddz.xyz vf4, vf5, vf4z");
            asm volatile("sqc2 vf4, 0x20(%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0x80(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
            asm volatile("vmulax.xyz ACC, vf3, vf2x");
            asm volatile("vmadday.xyz ACC, vf6, vf2y");
            asm volatile("vmaddz.xyz vf2, vf5, vf2z");
            asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0));
            asm volatile("vmulax.xyz ACC, vf3, vf1x");
            asm volatile("vmadday.xyz ACC, vf6, vf1y");
            asm volatile("vmaddz.xyz vf3, vf5, vf1z");
            asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(arg0));
            asm volatile("sqc2 vf2, 0x50(%0)" : : "r"(arg0));
            asm volatile("sqc2 vf3, 0x60(%0)" : : "r"(arg0));
            asm volatile("sqc2 vf3, 0xa0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x40(%0)" : : "r"(sp));
        }
    }
    var_s1 = 0;
    M2C_FIELD(arg0, s128 *, 0x80) = (s128) M2C_FIELD(arg0, s128 *, 0x70);
    if ((FIsZeroV__FP6VECTOR(M2C_FIELD(arg0, s128 *, 0x90)) == 0) || (FIsZeroDv__FP6VECTOR(M2C_FIELD(arg0, s128 *, 0xA0)) == 0)) {
        var_s1 = 1;
    }
    if (var_s1 != 0) {
        CalculateEmitdvMatrix(sp, arg0 + 0xA0);
        asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf6, 0x90(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf3, vf6x");
        asm volatile("vmadday.xyz ACC, vf5, vf6y");
        asm volatile("vmaddaz.xyz ACC, vf4, vf6z");
        asm volatile("vmaddw.xyz vf3, vf1, vf0w");
        asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(arg0));
        asm volatile("sqc2 vf3, 0x90(%0)" : : "r"(arg0));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2dded4));
        asm volatile("vadda.xyzw ACC, vf0, vf2");
        asm volatile("vmaddx.xyzw vf2, vf3, vf1x");
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(arg0));
    }
}
}
