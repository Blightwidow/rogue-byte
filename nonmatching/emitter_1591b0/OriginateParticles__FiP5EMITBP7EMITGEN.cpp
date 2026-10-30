typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_OriginateParticles__FiP5EMITBP7EMITGEN {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of sp10[4]? */
    /* 0x20 */ M2C_UNK sp20;                        /* inferred */
    /* 0x20 */ char pad20[0xB0];
};                                                  /* size = 0xD0 */
void CalculateEmitvx__FiP2LMiP6EMITVX(s32, s32, s32, M2C_UNK *);
void ChooseEmitoPos(s8 *, s32, s32, s32, s32 *);
void ChooseEmitvVelocityAge__FP5EMITVP6EMITVXP5EMITOiP6VECTORN24PfT7(s8 *, M2C_UNK *, s8 *, s32, s32, s32 *, s32, s32, s32);
void ConvertEmitoPosVec__FP5EMITOP6VECTORT1(s8 *, s32, s32);
s32 PvAllocStackImpl__Fi(s32 *);
void OriginateParticles__FiP5EMITBP7EMITGEN(s32 arg0, s8 *arg1, s8 *arg2) {
    s32 sp10;
    M2C_UNK sp20;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s5;
    temp_s2 = arg0 * 0x10;
    temp_s3 = arg0 * 4;
    sp10 = temp_s2;
    var_s5 = 0;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0 = PvAllocStackImpl__Fi(&sp10);
    sp10 = temp_s2;
    M2C_FIELD(arg2, s32 *, 0) = temp_v0;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocStackImpl__Fi(&sp10);
    sp10 = temp_s3;
    M2C_FIELD(arg2, s32 *, 4) = temp_v0_2;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0_3 = PvAllocStackImpl__Fi(&sp10);
    sp10 = temp_s3;
    M2C_FIELD(arg2, s32 *, 8) = temp_v0_3;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg2, s32 *, 0xC) = PvAllocStackImpl__Fi(&sp10);
    CalculateEmitvx__FiP2LMiP6EMITVX(M2C_FIELD(arg1, s32 *, 0x84), (int)(arg1 + 0x90), arg0, &sp20);
    if (arg0 > 0) {
loop_2:
        temp_s0 = var_s5 * 0x10;
        ChooseEmitoPos(arg1, var_s5, arg0, M2C_FIELD(arg2, s32 *, 0) + temp_s0, &sp10);
        temp_v1 = var_s5 * 4;
        ChooseEmitvVelocityAge__FP5EMITVP6EMITVXP5EMITOiP6VECTORN24PfT7(arg1 + 0x50, &sp20, arg1 + 0x10, var_s5, M2C_FIELD(arg2, s32 *, 0) + temp_s0, &sp10, M2C_FIELD(arg2, s32 *, 4) + temp_s0, M2C_FIELD(arg2, s32 *, 8) + temp_v1, M2C_FIELD(arg2, s32 *, 0xC) + temp_v1);
        temp_a1 = M2C_FIELD(arg1, s32 *, 0x1C);
        temp_a0 = temp_a1 + 0x10;
        if (temp_a1 != 0) {
            asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(temp_a1));
            temp_v0_4 = temp_s0 + M2C_FIELD(arg2, s32 *, 0);
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(temp_a0));
            asm volatile("lqc2 vf3, (%0)" : : "r"(temp_v0_4));
            asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_a0));
            asm volatile("vmulax.xyz ACC, vf5, vf3x");
            asm volatile("vmadday.xyz ACC, vf4, vf3y");
            asm volatile("vmaddz.xyz vf3, vf1, vf3z");
            asm volatile("lqc2 vf2, (%0)" : : "r"(temp_a1));
            asm volatile("vadd.xyzw vf3, vf3, vf2");
            asm volatile("sqc2 vf3, (%0)" : : "r"(temp_v0_4));
            asm volatile("lqc2 vf1, (%0)" : : "r"(temp_a1));
            asm volatile("lqc2 vf5, (%0)" : : "r"(temp_s0 + M2C_FIELD(arg2, s32 *, 0)));
            temp_v1_2 = temp_s0 + M2C_FIELD(arg2, s32 *, 4);
            asm volatile("vsub.xyzw vf5, vf5, vf1");
            asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(temp_a0));
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_a0));
            asm volatile("lqc2 vf2, (%0)" : : "r"(temp_v1_2));
            asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_a1));
            asm volatile("vmulax.xyz ACC, vf3, vf2x");
            asm volatile("vmadday.xyz ACC, vf1, vf2y");
            asm volatile("vmaddz.xyz vf2, vf6, vf2z");
            asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(temp_a1));
            asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(temp_a1));
            asm volatile("vadd.xyzw vf2, vf2, vf4");
            asm volatile("vopmula.xyz ACC, vf1, vf5");
            asm volatile("vopmsub.xyz vf1, vf5, vf1");
            asm volatile("vadd.xyzw vf2, vf2, vf1");
            asm volatile("sqc2 vf2, (%0)" : : "r"(temp_v1_2));
        }
        if (M2C_FIELD(arg2, s32 *, 0x10) != 0) {
            ConvertEmitoPosVec__FP5EMITOP6VECTORT1(arg1, M2C_FIELD(arg2, s32 *, 0) + temp_s0, M2C_FIELD(arg2, s32 *, 4) + temp_s0);
        }
        var_s5 += 1;
        if (var_s5 < arg0) {
            goto loop_2;
        }
    }
}
}
