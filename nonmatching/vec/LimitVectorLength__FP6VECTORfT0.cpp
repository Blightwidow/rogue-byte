typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LimitVectorLength__FP6VECTORfT0 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
s32 LimitVectorLength__FP6VECTORfT0(s32 arg0, f32 fparg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_v0;
    s32 var_v0;
    asm volatile("qmtc2.ni %0, vf3" : : "r"(arg0));
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v0 = vu_1;
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
    var_v0 = vu_2;
    if (fparg0 < temp_v0) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(fparg0 / temp_v0));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf2, vf3, vf1x");
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
        var_v0 = vu_3;
    }
    return var_v0;
}
}
