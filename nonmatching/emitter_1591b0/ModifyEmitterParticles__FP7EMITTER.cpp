typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ModifyEmitterParticles__FP7EMITTER {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ f32 sp8;                             /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ f32 sp10;                            /* inferred */
    /* 0x14 */ f32 sp14;                            /* inferred */
    /* 0x18 */ f32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ f32 sp20;                            /* inferred */
    /* 0x24 */ f32 sp24;                            /* inferred */
    /* 0x28 */ f32 sp28;                            /* inferred */
    /* 0x2C */ char pad2C[4];
    /* 0x30 */ f32 sp30;                            /* inferred */
    /* 0x34 */ f32 sp34;                            /* inferred */
    /* 0x38 */ f32 sp38;                            /* inferred */
    /* 0x3C */ char pad3C[0x64];
};                                                  /* size = 0xA0 */
#define sp10 (*(f32 *)(sp + 0x10))
#define sp14 (*(f32 *)(sp + 0x14))
#define sp18 (*(f32 *)(sp + 0x18))
#define sp20 (*(f32 *)(sp + 0x20))
#define sp24 (*(f32 *)(sp + 0x24))
#define sp28 (*(f32 *)(sp + 0x28))
f32 GModPositive__Fff(f32, f32);                    /* extern */
s32 PosLoWorld(s32);                                /* extern */
void ModifyEmitterParticles__FP7EMITTER(s8 *arg0) {
    s8 sp[0x60] __attribute__((aligned(16)));
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    s32 temp_a0;
    s32 var_s2;
    s32 var_v1;
    s8 *temp_a0_2;
    s8 *var_s0;
    s8 *var_s1;
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x140);
    if (temp_f1 > 0.0001f) {
        sp0 = temp_f1;
        sp8 = temp_f1;
        sp4 = temp_f1;
        temp_a0 = *M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE4), s32 **, 8);
        asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
        if (temp_a0 != 0) {
            asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_a0)));
            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf2, vf3, vf1");
            asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(*M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE4), s32 **, 8))));
            asm volatile("vadd.xyzw vf2, vf3, vf1");
            asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
        } else {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
            asm volatile("vmulx.xyzw vf2, vf3, vf1x");
            asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
        }
        temp_f0 = 2.0f * M2C_FIELD(arg0, f32 *, 0x140);
        sp0 = temp_f0;
        sp8 = temp_f0;
        sp4 = temp_f0;
        if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE4), s32 *, 4) == 0) {
            temp_a0_2 = M2C_FIELD(arg0, s8 **, 0x150);
            if (temp_a0_2 != NULL) {
                var_s1 = M2C_FIELD(temp_a0_2, s8 **, 0x448);
                if (var_s1 != NULL) {
                    var_v1 = M2C_FIELD(var_s1, s32 *, 0x1080);
loop_8:
                    var_s2 = 0;
                    if (M2C_FIELD(var_s1, s32 *, 0x1084) > 0) {
                        var_s0 = (var_v1 * 0x840) + var_s1;
                        do {
                            temp_f12 = M2C_FIELD(var_s0, f32 *, 0);
                            if ((temp_f12 < sp10) || (sp20 < temp_f12)) {
                                temp_f1_2 = (sp10 + GModPositive__Fff(temp_f12 - sp10, sp0)) - M2C_FIELD(var_s0, f32 *, 0);
                                sp30 = temp_f1_2;
                                M2C_FIELD(var_s0, f32 *, 0) = (f32) (M2C_FIELD(var_s0, f32 *, 0) + temp_f1_2);
                            }
                            temp_f12_2 = M2C_FIELD(var_s0, f32 *, 4);
                            if ((temp_f12_2 < sp14) || (sp24 < temp_f12_2)) {
                                temp_f1_3 = (sp14 + GModPositive__Fff(temp_f12_2 - sp14, sp4)) - M2C_FIELD(var_s0, f32 *, 4);
                                sp34 = temp_f1_3;
                                M2C_FIELD(var_s0, f32 *, 4) = (f32) (M2C_FIELD(var_s0, f32 *, 4) + temp_f1_3);
                            }
                            temp_f12_3 = M2C_FIELD(var_s0, f32 *, 8);
                            if ((temp_f12_3 < sp18) || (sp28 < temp_f12_3)) {
                                temp_f1_4 = (sp18 + GModPositive__Fff(temp_f12_3 - sp18, sp8)) - M2C_FIELD(var_s0, f32 *, 8);
                                sp38 = temp_f1_4;
                                M2C_FIELD(var_s0, f32 *, 8) = (f32) (M2C_FIELD(var_s0, f32 *, 8) + temp_f1_4);
                            }
                            var_s2 += 1;
                            var_s0 += 0x10;
                        } while (var_s2 < M2C_FIELD(var_s1, s32 *, 0x1084));
                    }
                    var_s1 = M2C_FIELD(var_s1, s8 **, 0x1090);
                    if (var_s1 != NULL) {
                        var_v1 = M2C_FIELD(var_s1, s32 *, 0x1080);
                        goto loop_8;
                    }
                }
            }
        }
    }
}
}
