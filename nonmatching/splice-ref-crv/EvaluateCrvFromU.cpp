typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EvaluateCrvFromU {
    /* 0x00 */ char pad0[0x50];
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ f32 sp54;                            /* inferred */
    /* 0x58 */ char pad58[0x58];
};                                                  /* size = 0xB0 */
M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, f32, f32, M2C_UNK); /* extern */
s32 IcvFindCrvU(f32 *, f32 *);                      /* extern */
void EvaluateCrvFromU(s8 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x50] __attribute__((aligned(16)));
    f32 sp50;
    f32 sp54;
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s8 *temp_t3;
    s8 *temp_v1;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    temp_s2 = IcvFindCrvU(&sp50, &sp54);
    temp_v0 = M2C_FIELD(temp_v1, s32 (**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    asm volatile("lqc2 vf8, (%0)" : : "r"(temp_v0));
    asm volatile("sqc2 vf8, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf7, 0x10(%0)" : : "r"(temp_v0));
    asm volatile("sqc2 vf7, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(temp_v0));
    asm volatile("sqc2 vf6, 0x20(%0)" : : "r"(sp));
    asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(temp_v0));
    asm volatile("sqc2 vf5, 0x30(%0)" : : "r"(sp));
    if (M2C_FIELD(arg0, s32 *, 0xE0) == 0) {
        if (arg1 != 0) {
            temp_f1 = sp50 / sp54;
            temp_v1_2 = (temp_s2 * 0x10) + M2C_FIELD(arg0, s32 *, 0xF4);
            asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_f1));
            asm volatile("qmtc2.ni %0, vf1" : : "r"(1.0f - temp_f1));
            asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, (%0)" : : "r"(temp_v1_2));
            asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v1_2));
            asm volatile("vmulax.xyzw ACC, vf3, vf1x");
            asm volatile("vmaddx.xyzw vf1, vf2, vf4x");
            asm volatile("vmulax.xyz ACC, vf8, vf1x");
            asm volatile("vmadday.xyz ACC, vf7, vf1y");
            asm volatile("vmaddaz.xyz ACC, vf6, vf1z");
            asm volatile("vmaddw.xyz vf1, vf5, vf0w");
            asm volatile("sqc2 vf1, (%0)" : : "r"(arg1));
        }
        if (arg2 != 0) {
            asm volatile("lqc2 vf5, (%0)" : : "r"(sp));
            temp_a0 = (temp_s2 * 0x10) + M2C_FIELD(arg0, s32 *, 0xF4);
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, (%0)" : : "r"(temp_a0));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_a0));
            asm volatile("vsub.xyzw vf2, vf2, vf1");
            goto block_9;
        }
    } else {
        temp_v0_2 = temp_s2 * 0x10;
        temp_t3 = (s8 *)(temp_v0_2 + M2C_FIELD(arg0, s32 *, 0xF4));
        EvaluateBezierPos__FfffP6VECTORN63(M2C_FIELD(temp_t3, s128 *, 0), *(s32 *)(temp_v0_2 + M2C_FIELD(arg0, s32 *, 0x144)), M2C_FIELD(temp_t3, s128 *, 0x10), M2C_FIELD((temp_v0_2 + M2C_FIELD(arg0, s32 *, 0x140)), s128 *, 0x10), sp54, sp50, 0x3F800000);
        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
        if (arg1 != 0) {
            asm volatile("lqc2 vf5, (%0)" : : "r"(arg1));
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf2, vf5x");
            asm volatile("vmadday.xyz ACC, vf4, vf5y");
            asm volatile("vmaddaz.xyz ACC, vf3, vf5z");
            asm volatile("vmaddw.xyz vf2, vf1, vf0w");
            asm volatile("sqc2 vf2, (%0)" : : "r"(arg1));
        }
        asm volatile("lqc2 vf5, (%0)" : : "r"(sp));
        if (arg2 != 0) {
            asm volatile("lqc2 vf2, (%0)" : : "r"(arg2));
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
block_9:
            asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf5, vf2x");
            asm volatile("vmadday.xyz ACC, vf4, vf2y");
            asm volatile("vmaddz.xyz vf2, vf3, vf2z");
            asm volatile("vmul.xyz vf1, vf2, vf2");
            asm volatile("vaddw.x vf6, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf6, vf1z");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf1, vf2, Q");
            asm volatile("sqc2 vf1, (%0)" : : "r"(arg2));
        }
    }
}
}
