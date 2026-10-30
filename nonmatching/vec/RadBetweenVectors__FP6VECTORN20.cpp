typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RadBetweenVectors__FP6VECTORN20 {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s32 GetPerpendicularVector(M2C_UNK);                /* extern */
f32 acosf(f32);                                     /* extern */
extern s128 g_2a2da0;
f32 RadBetweenVectors__FP6VECTORN20(s32 arg0, s32 arg1, s128 *arg2) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK temp_a0;
    f32 temp_f20;
    f32 temp_v0;
    f32 temp_v0_2;
    asm volatile("qmtc2.ni %0, vf4" : : "r"(arg0));
    asm volatile("vmul.xyz vf1, vf4, vf4");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v0 = vu_1;
    asm volatile("qmtc2.ni %0, vf5" : : "r"(arg1));
    asm volatile("vmul.xyz vf2, vf5, vf5");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
    temp_f20 = vu_2;
    if ((temp_v0 < 0.0001f) || (temp_f20 < 0.0001f)) {
        if (arg2 != NULL) {
            *arg2 = g_2a2da0;
        }
        return 0.0f;
    }
    if (arg2 != NULL) {
        asm volatile("vopmula.xyz ACC, vf4, vf5");
        asm volatile("vopmsub.xyz vf3, vf5, vf4");
        asm volatile("vmul.xyz vf1, vf3, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
        temp_v0_2 = vu_3;
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_4));
        temp_a0 = vu_4;
        if (temp_v0_2 > 1e-8f) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(temp_v0_2));
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf3, vf3, Q");
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        } else {
            asm volatile("sqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf5, 0x20(%0)" : : "r"(sp));
            asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(sp));
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf3" : : "r"(GetPerpendicularVector(temp_a0)));
        }
        asm volatile("sqc2 vf3, (%0)" : : "r"(arg2));
    }
    asm volatile("vmul.xyz vf1, vf4, vf5");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    s32 vu_5;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_5));
    return acosf(vu_5 / (temp_v0 * temp_f20));
}
}
