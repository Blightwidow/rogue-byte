typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EvaluateAcpbl {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ M2C_UNK sp20;                        /* inferred */
    /* 0x20 */ char pad20[0x10];
    /* 0x30 */ M2C_UNK sp30;                        /* inferred */
    /* 0x30 */ char pad30[0x20];
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ char pad54[0x9C];
};                                                  /* size = 0xF0 */
s32 ImrsgLookUp__FffiP4MRSGPf(f32, f32, s32, s32, f32 *);
extern s128 g_2a2dd0;
#define sp0 (*(s128 *)(sp + 0x00))
#define sp10 (*(s128 *)(sp + 0x10))
#define sp20 (*(M2C_UNK *)(sp + 0x20))
#define sp30 (*(M2C_UNK *)(sp + 0x30))
#define sp50 (*(f32 *)(sp + 0x50))
void EvaluateAcpbl(s8 *arg0, s128 *arg1, s128 *arg2, f32 fparg0, f32 fparg1) {
    s32 saved_reg_s3;
    s32 saved_reg_s4;
    s8 sp[0x60] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f4;
    f32 var_f12;
    f32 var_f13;
    f32 var_f20;
    s32 var_s1;
    s32 var_s4;
    s8 **temp_a3;
    s8 *temp_s0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *var_s3;
    var_s3 = (s8 *)(saved_reg_s3);
    var_s4 = saved_reg_s4;
    temp_v1 = M2C_FIELD(arg0, s8 **, 8);
    if (temp_v1 == NULL) {
        var_f20 = fparg0 / M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), f32 *, 0x74);
    } else {
        var_s4 = ImrsgLookUp__FffiP4MRSGPf(fparg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), f32 *, 0x74), M2C_FIELD(temp_v1, s32 *, 4), M2C_FIELD(temp_v1, s32 *, 8), &sp50);
        var_s3 = (s8 *)(M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s32 *, 8) + (var_s4 * 8));
        var_f20 = sp50 / M2C_FIELD(var_s3, f32 *, 4);
    }
    sp10 = g_2a2dd0;
    sp0 = g_2a2dd0;
    var_s1 = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s32 *, 0xC4) > 0) {
        do {
            temp_s0 = (s8 *)(M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s32 *, 0xC8) + (var_s1 * M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s32 *, 0xC0)));
            if (M2C_FIELD(temp_s0, f32 *, 0) != 0.0f) {
                temp_a3 = (s8 **)(*(s32 *)((var_s1 * 4) + M2C_FIELD(arg0, s32 *, 0xC)));
                if (temp_a3 != NULL) {
                    temp_v0 = M2C_FIELD(arg0, s8 **, 8);
                    if (temp_v0 != NULL) {
                        temp_v0_2 = temp_s0 + M2C_FIELD(temp_v0, s32 *, 0) + (var_s4 * 8);
                        temp_f4 = M2C_FIELD(M2C_FIELD(temp_s0, s8 **, 4), f32 *, 0x74);
                        temp_f0 = M2C_FIELD(temp_v0_2, f32 *, 4);
                        var_f12 = M2C_FIELD(temp_v0_2, f32 *, 0) + (var_f20 * temp_f0);
                        var_f13 = (fparg1 * temp_f0) / M2C_FIELD(var_s3, f32 *, 4);
                        if (temp_f4 < var_f12) {
                            var_f12 -= temp_f4;
                        }
                    } else {
                        temp_f0_2 = M2C_FIELD(M2C_FIELD(temp_s0, s8 **, 4), f32 *, 0x74);
                        var_f13 = (fparg1 * temp_f0_2) / M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), f32 *, 0x74);
                        var_f12 = var_f20 * temp_f0_2;
                    }
                    temp_v1_2 = *temp_a3;
                    M2C_FIELD((s8 **)((s8 **)(temp_v1_2)), M2C_UNK (**)(s8 *, M2C_UNK *, M2C_UNK *, s8 *, f32, f32), 0x1C)((s8 *)(temp_a3 + M2C_FIELD((s8 **)((s8 **)(temp_v1_2)), s16 *, 0x18)), &sp20, &sp30, (s8 *)(temp_a3), var_f12, var_f13);
                } else {
                    *(f32 *)(sp + 0x10) = 0.0f;
                    sp0 = M2C_FIELD(arg0, s128 *, 0x10);
                    *(f32 *)(sp + 0x18) = 0.0f;
                    *(f32 *)(sp + 0x14) = 0.0f;
                }
                asm volatile("qmtc2.ni %0, vf5" : : "r"(M2C_FIELD(temp_s0, f32 *, 0)));
                asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
                asm volatile("vadda.xyzw ACC, vf0, vf2");
                asm volatile("vmaddx.xyzw vf2, vf1, vf5x");
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf4" : : "r"(M2C_FIELD(temp_s0, f32 *, 0)));
                asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
                asm volatile("vadda.xyzw ACC, vf0, vf3");
                asm volatile("vmaddx.xyzw vf3, vf1, vf4x");
                asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
            }
            var_s1 += 1;
        } while (var_s1 < M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s32 *, 0xC4));
    }
    if (arg1 != NULL) {
        *arg1 = sp0;
    }
    if (arg2 != NULL) {
        *arg2 = (s128) sp10;
    }
}
}
