typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s128 GetPerpendicularVector(M2C_UNK);               /* extern */
extern s128 g_2a2da0;
s8 *BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s8 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(arg1));
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("qmtc2.ni %0, vf2" : : "r"(arg2));
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    if (vu_1 < 0.0001f) {
        asm volatile("qmtc2.ni %0, vf4" : : "r"(g_2a2da0));
    } else {
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf4, vf3, Q");
    }
    asm volatile("vopmula.xyz ACC, vf2, vf4");
    asm volatile("vopmsub.xyz vf1, vf4, vf2");
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(arg0));
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("sqc2 vf4, (%0)" : : "r"(arg0));
    asm volatile("vdiv Q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf2, vf1, Q");
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(arg0));
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
    if (vu_2 < 0.0001f) {
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
        M2C_FIELD(arg0, s128 *, 0x10) = GetPerpendicularVector(vu_3);
    }
    asm volatile("lqc2 vf1, (%0)" : : "r"(arg0));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(arg0));
    asm volatile("vopmula.xyz ACC, vf1, vf2");
    asm volatile("vopmsub.xyz vf1, vf2, vf1");
    asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(arg0));
    return arg0;
}
}
