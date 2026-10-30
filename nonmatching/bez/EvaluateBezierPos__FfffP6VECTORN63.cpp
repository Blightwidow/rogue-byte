typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EvaluateBezierPos__FfffP6VECTORN63 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
void EvaluateBezierPos__FfffP6VECTORN63(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 fparg0, f32 fparg1, f32 fparg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f5;
    temp_f13 = fparg1 / fparg0;
    asm volatile("qmtc2.ni %0, vf7" : : "r"(arg0));
    asm volatile("qmtc2.ni %0, vf9" : : "r"(arg1));
    asm volatile("qmtc2.ni %0, vf6" : : "r"(arg2));
    asm volatile("qmtc2.ni %0, vf8" : : "r"(arg3));
    temp_f5 = 1.0f - temp_f13;
    if (arg4 != 0) {
        temp_f3 = temp_f13 * temp_f13;
        temp_f2 = temp_f13 * temp_f5 * temp_f5;
        temp_f1 = temp_f3 * temp_f5;
        asm volatile("qmtc2.ni %0, vf1" : : "r"((temp_f5 * temp_f5 * temp_f5) + (temp_f2 * 3.0f)));
        asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_f2 * fparg0));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(-temp_f1 * fparg0));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf3" : : "r"((temp_f3 * temp_f13) + (temp_f1 * 3.0f)));
        asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
        asm volatile("vmulax.xyzw ACC, vf7, vf1x");
        asm volatile("vmaddax.xyzw ACC, vf9, vf4x");
        asm volatile("vmaddax.xyzw ACC, vf8, vf2x");
        asm volatile("vmaddx.xyzw vf1, vf6, vf3x");
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, (%0)" : : "r"(arg4));
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
    }
    if (arg5 != 0) {
        asm volatile("vsub.xyzw vf5, vf6, vf7");
        temp_f0 = temp_f13 * 3.0f;
        asm volatile("qmtc2.ni %0, vf3" : : "r"(fparg2));
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_f13 * (temp_f0 + -2.0f)));
        asm volatile("qmtc2.ni %0, vf1" : : "r"((temp_f13 * (6.0f - (temp_f13 * 6.0f))) / fparg0));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(1.0f - (temp_f13 * (4.0f - temp_f0))));
        asm volatile("vmulax.xyzw ACC, vf5, vf1x");
        asm volatile("vmaddax.xyzw ACC, vf9, vf2x");
        asm volatile("vmaddx.xyzw vf1, vf8, vf4x");
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf3, vf1, vf3x");
        asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, (%0)" : : "r"(arg5));
    }
    if (arg6 != 0) {
        asm volatile("vsub.xyzw vf4, vf6, vf7");
        temp_f1_2 = temp_f13 * 6.0f;
        asm volatile("qmtc2.ni %0, vf2" : : "r"((fparg2 * fparg2) / fparg0));
        asm volatile("qmtc2.ni %0, vf5" : : "r"(temp_f1_2 - 2.0f));
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_f1_2 - 4.0f));
        asm volatile("qmtc2.ni %0, vf1" : : "r"((6.0f - (temp_f13 * 12.0f)) / fparg0));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vmulax.xyzw ACC, vf4, vf1x");
        asm volatile("vmaddax.xyzw ACC, vf9, vf3x");
        asm volatile("vmaddx.xyzw vf4, vf8, vf5x");
        asm volatile("vmulx.xyzw vf2, vf4, vf2x");
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, (%0)" : : "r"(arg6));
        asm volatile("sqc2 vf5, (%0)" : : "r"(sp));
    }
}
}
