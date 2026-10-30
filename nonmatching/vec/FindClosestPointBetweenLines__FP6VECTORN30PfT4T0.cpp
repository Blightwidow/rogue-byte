typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FindClosestPointBetweenLines__FP6VECTORN30PfT4T0 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
extern s128 g_2a2dc0;
void FindClosestPointBetweenLines__FP6VECTORN30PfT4T0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 *arg4, s32 *arg5, s32 arg6) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_f1;
    f32 temp_v0;
    s32 temp_cond;
    asm volatile("qmtc2.ni %0, vf1" : : "r"(arg0));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(arg2));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(arg1));
    asm volatile("vsub.xyzw vf6, vf2, vf1");
    asm volatile("vsub.xyzw vf4, vf3, vf1");
    asm volatile("qmtc2.ni %0, vf1" : : "r"(arg3));
    asm volatile("vsub.xyzw vf3, vf1, vf2");
    asm volatile("vopmula.xyz ACC, vf4, vf3");
    asm volatile("vopmsub.xyz vf5, vf3, vf4");
    asm volatile("vmul.xyz vf1, vf5, vf5");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v0 = vu_1;
    if (temp_v0 < 0.0001f) {
        asm volatile("vmove.xyzw vf5, vf6");
        M2C_FIELD(arg4, f32 *, 0) = 0.0f;
        M2C_FIELD(arg4, f32 *, 4) = 0.0f;
    } else {
        asm volatile("vopmula.xyz ACC, vf6, vf3");
        asm volatile("vopmsub.xyz vf1, vf3, vf6");
        asm volatile("vopmula.xyz ACC, vf6, vf4");
        asm volatile("vopmsub.xyz vf2, vf4, vf6");
        asm volatile("vmul.xyz vf1, vf1, vf5");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf3, vf1z");
        asm volatile("vmul.xyz vf2, vf2, vf5");
        asm volatile("vaddw.x vf4, vf0, vf0w");
        asm volatile("vadday.x ACC, vf2, vf2y");
        asm volatile("vmaddz.x vf2, vf4, vf2z");
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
        temp_f1 = vu_2 / temp_v0;
        asm volatile("vmul.xyz vf1, vf6, vf5");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
        temp_cond = vu_3 < 0.0f;
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
        M2C_FIELD(arg4, f32 *, 0) = (f32) (vu_4 / temp_v0);
        M2C_FIELD(arg4, f32 *, 4) = temp_f1;
        if (temp_cond) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("vmulx.xyzw vf5, vf5, vf1x");
        }
    }
    asm volatile("vmul.xyz vf1, vf5, vf5");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_5;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_5));
    if (vu_5 < 0.0001f) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2dc0));
    } else {
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf5, Q");
    }
    asm volatile("vmove.xyzw vf5, vf1");
    asm volatile("vmul.xyz vf1, vf5, vf6");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    s32 vu_6;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_6));
    *arg5 = vu_6;
    asm volatile("sqc2 vf5, (%0)" : : "r"(arg6));
}
}
