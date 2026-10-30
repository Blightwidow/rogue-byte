typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00167DA0 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
extern M2C_UNK D_002BE570;
s32 func_00167DA0(s32 arg0, s32 arg1, f32 *arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_f1;
    f32 temp_v0;
    s32 var_v0;
    asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf4, (%0)" : : "r"(&D_002BE570));
    asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf2, (%0)" : : "r"(arg0));
    asm volatile("vmulax.xyz ACC, vf2, vf4x");
    asm volatile("vmadday.xyz ACC, vf3, vf4y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf4z");
    asm volatile("vmaddw.xyz vf2, vf5, vf0w");
    asm volatile("qmtc2.ni %0, vf6" : : "r"(arg1));
    asm volatile("vsub.xyzw vf2, vf2, vf6");
    temp_f1 = *arg2;
    asm volatile("vmul.xyz vf1, vf2, vf2");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf3, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v0 = vu_1;
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_2));
    var_v0 = vu_2;
    if (temp_f1 < temp_v0) {
        *arg2 = (temp_v0 + temp_f1) * 0.5f;
        asm volatile("qmtc2.ni %0, vf1" : : "r"(((temp_v0 - temp_f1) * 0.5f) / temp_v0));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vadda.xyzw ACC, vf0, vf6");
        asm volatile("vmaddx.xyzw vf6, vf2, vf1x");
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_3));
        var_v0 = vu_3;
    }
    return var_v0;
}
}
