typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FillCrvcCache {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ char pad60[0x70];
};                                                  /* size = 0xD0 */
#define sp20 (*(s128 *)(sp + 0x20))
#define sp30 (*(s128 *)(sp + 0x30))
#define sp40 (*(s128 *)(sp + 0x40))
#define sp50 (*(s128 *)(sp + 0x50))
M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, s128 *, M2C_UNK, M2C_UNK, f32, f32, M2C_UNK); /* extern */
void FillCrvcCache(s8 *arg0, s32 arg1) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s128 sp10;
    f32 temp_f20;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_s2;
    s8 *temp_a0;
    s8 *temp_a1;
    s8 *var_s0;
    temp_a1 = arg0 + 0x100;
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x148)) {
        temp_v0 = arg1 * 0x10;
        temp_a2 = temp_v0 + M2C_FIELD(arg0, s32 *, 0xF4);
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_a1));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_a1));
        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(temp_v0 + M2C_FIELD(arg0, s32 *, 0x140)));
        asm volatile("lqc2 vf6, 0x30(%0)" : : "r"(temp_a1));
        var_s2 = 0;
        asm volatile("lqc2 vf4, (%0)" : : "r"(temp_a2));
        asm volatile("lqc2 vf7, 0x10(%0)" : : "r"(temp_a2));
        var_s0 = arg0 + 0x14C;
        asm volatile("lqc2 vf8, (%0)" : : "r"(temp_v0 + M2C_FIELD(arg0, s32 *, 0x144)));
        M2C_FIELD(arg0, s32 *, 0x14C) = 0;
        asm volatile("lqc2 vf1, 0x100(%0)" : : "r"(arg0));
        temp_a0 = (s8 *)((arg1 * 4) + M2C_FIELD(arg0, s32 *, 0xEC));
        asm volatile("vmulax.xyz ACC, vf1, vf5x");
        asm volatile("vmadday.xyz ACC, vf3, vf5y");
        asm volatile("vmaddz.xyz vf9, vf2, vf5z");
        asm volatile("sqc2 vf9, 0x50(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf1, vf7x");
        asm volatile("vmadday.xyz ACC, vf3, vf7y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf7z");
        asm volatile("vmaddw.xyz vf5, vf6, vf0w");
        asm volatile("vmulax.xyz ACC, vf1, vf4x");
        asm volatile("vmadday.xyz ACC, vf3, vf4y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf4z");
        asm volatile("vmaddw.xyz vf9, vf6, vf0w");
        asm volatile("vmulax.xyz ACC, vf1, vf8x");
        asm volatile("vmadday.xyz ACC, vf3, vf8y");
        asm volatile("vmaddz.xyz vf4, vf2, vf8z");
        asm volatile("sqc2 vf5, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf9, 0x20(%0)" : : "r"(sp));
        temp_f20 = M2C_FIELD(temp_a0, f32 *, 4) - M2C_FIELD(temp_a0, f32 *, 0);
        asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
        do {
            EvaluateBezierPos__FfffP6VECTORN63(sp20, sp40, sp30, sp50, &sp10, 0, 0, temp_f20, (f32) var_s2 * 0.1f * temp_f20, 0x3F800000);
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
            if (var_s2 > 0) {
                asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf1, vf1, vf2");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                M2C_FIELD(var_s0, f32 *, 0) = (f32) (M2C_FIELD(var_s0, f32 *, -4) + vu_1);
            }
            var_s2 += 1;
            var_s0 += 4;
        } while (var_s2 < 0xB);
        M2C_FIELD(arg0, s32 *, 0x148) = arg1;
    }
}
}
