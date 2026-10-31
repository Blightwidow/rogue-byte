typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EvaluateAcsb__FP4ACSBP3ALOfiP7MATRIX3 {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ f32 sp10;                           /* inferred */
    /* 0x014 */ f32 sp14;                           /* inferred */
    /* 0x018 */ f32 sp18;                           /* inferred */
    /* 0x01C */ char pad1C[4];
    /* 0x020 */ M2C_UNK sp20;                       /* inferred */
    /* 0x020 */ char pad20[0x80];
    /* 0x0A0 */ f32 spA0;                           /* inferred */
    /* 0x0A4 */ f32 spA4;                           /* inferred */
    /* 0x0A8 */ f32 *spA8;                          /* inferred */
    /* 0x0AC */ char padAC[0x34];                   /* maybe part of spA8[0xE]? */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ s128 spF0;                          /* inferred */
    /* 0x100 */ s128 sp100;                         /* inferred */
    /* 0x110 */ s128 sp110;                         /* inferred */
    /* 0x120 */ char pad120[0x10];
    /* 0x130 */ f32 sp130;                          /* inferred */
    /* 0x134 */ f32 sp134;                          /* inferred */
    /* 0x138 */ char pad138[8];                     /* maybe part of sp134[3]? */
    /* 0x140 */ s128 sp140;                         /* inferred */
    /* 0x150 */ s128 sp150;                         /* inferred */
    /* 0x160 */ char pad160[0x90];
};                                                  /* size = 0x1F0 */
#define sp10 (*(f32 *)(sp + 0x10))
#define sp14 (*(f32 *)(sp + 0x14))
#define sp18 (*(f32 *)(sp + 0x18))
#define sp20 (*(M2C_UNK *)(sp + 0x20))
#define spA8 (*(f32 **)(sp + 0xA8))
#define sp130 (*(f32 *)(sp + 0x130))
#define sp134 (*(f32 *)(sp + 0x134))
#define sp150 (*(s128 *)(sp + 0x150))
#define spA0 (*(f32 *)(sp + 0x0A0))
#define spA4 (*(f32 *)(sp + 0x0A4))
#define spE0 (*(s128 *)(sp + 0x0E0))
#define spF0 (*(s128 *)(sp + 0x0F0))
#define sp100 (*(s128 *)(sp + 0x100))
#define sp110 (*(s128 *)(sp + 0x110))
#define sp140 (*(s128 *)(sp + 0x140))
void EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, f32, f32, f32);
s32 ImrsgLookUp__FffiP4MRSGPf(f32, f32, s32, s32, f32 *);
s32 memset(M2C_UNK *, M2C_UNK, M2C_UNK);
void EvaluateAcsb__FP4ACSBP3ALOfiP7MATRIX3(s8 *arg0, s8 *arg1) {
    s32 saved_reg_s6;
    s8 sp[0x160] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    f32 var_f20;
    f32 var_f21;
    s128 temp_v1;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_s4;
    s32 var_s6;
    s8 **temp_a2;
    s8 **temp_s0;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a0_3;
    s8 *temp_s3;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v1_2;
    var_s6 = saved_reg_s6;
    temp_a0 = M2C_FIELD(arg0, s8 **, 4);
    temp_v0 = M2C_FIELD(temp_a0, s32 *, 0xD4);
    if (temp_v0 >= 0) {
        temp_a2 = (s8 **)(*(s32 *)((temp_v0 * 4) + M2C_FIELD(arg0, s32 *, 0xC)));
        if (temp_a2 == NULL) {
            temp_v1 = M2C_FIELD(arg0, s128 *, 0x10);
            M2C_FIELD(arg1, s16 *, 0x9A) = 2;
            temp_a0_2 = arg1 + 0xD0;
            M2C_FIELD(arg1, s32 *, 0xD0) = 0;
            temp_v0_2 = arg1 + 0xF0;
            M2C_FIELD(arg1, s128 *, 0xC0) = temp_v1;
            M2C_FIELD(arg1, s32 *, 0x80) = 0;
            M2C_FIELD(temp_a0_2, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_2, s32 *, 8) = 0;
            M2C_FIELD(temp_a0_2, s32 *, 8) = 0;
            M2C_FIELD(arg1, s8 **, 0x8C) = (s8 *) (arg1 + 0x84);
            M2C_FIELD(temp_v0_2, s32 *, 4) = 0;
            M2C_FIELD(arg1, f32 **, 0x88) = (f32 *) (arg1 + 0x80);
            M2C_FIELD(arg1, s32 *, 0xF0) = 0;
            M2C_FIELD(arg1, f32 *, 0x84) = 1.0f;
            M2C_FIELD(arg1, s128 *, 0xE0) = temp_v1;
            return;
        }
        temp_v0_3 = *temp_a2;
        M2C_FIELD((s8 **)((s8 **)((s8 **)((s8 **)((s8 **)(temp_v0_3))))), M2C_UNK (**)(s8 *), 0x14)((s8 *)(temp_a2 + M2C_FIELD((s8 **)((s8 **)((s8 **)((s8 **)((s8 **)(temp_v0_3))))), s16 *, 0x10)));
        return;
    }
    temp_v1_2 = M2C_FIELD(arg0, s8 **, 8);
    temp_f12 = *M2C_FIELD(arg1, f32 **, 0x88);
    if (temp_v1_2 == NULL) {
        var_f21 = temp_f12 / M2C_FIELD(temp_a0, f32 *, 0x74);
    } else {
        var_s6 = ImrsgLookUp__FffiP4MRSGPf(temp_f12, M2C_FIELD(temp_a0, f32 *, 0x74), M2C_FIELD(temp_v1_2, s32 *, 4), M2C_FIELD(temp_v1_2, s32 *, 8), &sp130);
        var_f21 = sp130 / M2C_FIELD(((var_s6 * 8) + M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s32 *, 8)), f32 *, 4);
    }
    asm volatile("vsub.xyzw vf1, vf0, vf0");
    asm volatile("sqc2 vf1, 0x140(%0)" : : "r"(sp));
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    sp150 = vu_1;
    var_s4 = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s32 *, 0xC4) > 0) {
        do {
            temp_s3 = (s8 *)(M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s32 *, 0xC8) + (var_s4 * M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s32 *, 0xC0)));
            if (M2C_FIELD(temp_s3, f32 *, 0) != 0.0f) {
                temp_s0 = *(s8 ***)((var_s4 * 4) + M2C_FIELD(arg0, s32 *, 0xC));
                if (temp_s0 != NULL) {
                    temp_a0_3 = M2C_FIELD(arg0, s8 **, 8);
                    if (temp_a0_3 != NULL) {
                        temp_a1 = var_s6 * 8;
                        temp_v0_4 = temp_s3 + M2C_FIELD(temp_a0_3, s32 *, 0) + temp_a1;
                        temp_f2 = M2C_FIELD(M2C_FIELD(temp_s3, s8 **, 4), f32 *, 0x74);
                        temp_f14 = M2C_FIELD(temp_v0_4, f32 *, 4);
                        temp_f0 = M2C_FIELD(temp_v0_4, f32 *, 0) + (var_f21 * temp_f14);
                        sp134 = temp_f0;
                        if (temp_f2 < temp_f0) {
                            sp134 = temp_f0 - temp_f2;
                        }
                        var_f20 = temp_f14 / M2C_FIELD((temp_a1 + M2C_FIELD(temp_a0_3, s32 *, 8)), f32 *, 4);
                    } else {
                        temp_f0_2 = M2C_FIELD(M2C_FIELD(temp_s3, s8 **, 4), f32 *, 0x74);
                        var_f20 = temp_f0_2 / M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), f32 *, 0x74);
                        sp134 = var_f21 * temp_f0_2;
                    }
                    memset(&sp20, 0, 0x100);
                    spA8 = &sp134;
                    temp_v0_5 = *temp_s0;
                    M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK *), 0x14)((s8 *)(temp_s0 + M2C_FIELD(temp_v0_5, s16 *, 0x10)), &sp20);
                    EvaluateBezierPos__FfffP6VECTORN63(spE0, spF0, sp100, sp110, spA4 - spA0, sp134 - spA0, var_f20);
                } else {
                    sp10 = 0.0f;
                    sp18 = 0.0f;
                    sp14 = 0.0f;
                }
                asm volatile("qmtc2.ni %0, vf1" : : "r"(M2C_FIELD(temp_s3, f32 *, 0)));
                asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, 0x140(%0)" : : "r"(sp));
                asm volatile("vadda.xyzw ACC, vf0, vf3");
                asm volatile("vmaddx.xyzw vf3, vf2, vf1x");
                asm volatile("sqc2 vf1, 0x120(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0x140(%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, 0x150(%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                asm volatile("vadda.xyzw ACC, vf0, vf2");
                asm volatile("vmaddx.xyzw vf2, vf3, vf1x");
                asm volatile("sqc2 vf2, 0x150(%0)" : : "r"(sp));
            }
            var_s4 += 1;
        } while (var_s4 < M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s32 *, 0xC4));
    }
    M2C_FIELD(arg1, s16 *, 0x9A) = 4;
    M2C_FIELD(arg1, s128 *, 0xC0) = sp140;
    M2C_FIELD(arg1, s32 *, 0xD0) = sp150;
}
}
