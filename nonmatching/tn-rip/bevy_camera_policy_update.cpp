typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_camera_policy_update {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ char pad10[0x10];
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0xC];
    /* 0x3C */ s32 sp3C;                            /* inferred */
    /* 0x40 */ char pad40[0xC];                     /* maybe part of sp3C[4]? */
    /* 0x4C */ s32 sp4C;                            /* inferred */
    /* 0x50 */ M2C_UNK sp50;                        /* inferred */
    /* 0x50 */ char pad50[0x10];
    /* 0x60 */ f32 sp60;                            /* inferred */
    /* 0x64 */ f32 sp64;                            /* inferred */
    /* 0x68 */ f32 sp68;                            /* inferred */
    /* 0x6C */ char pad6C[0x14];                    /* maybe part of sp68[6]? */
    /* 0x80 */ s128 sp80;                           /* inferred */
    /* 0x90 */ s128 sp90;                           /* inferred */
    /* 0xA0 */ s128 spA0;                           /* inferred */
    /* 0xB0 */ char padB0[0x40];
};                                                  /* size = 0xF0 */
#define sp0 (*(s128 *)(sp + 0x00))
#define sp90 (*(s128 *)(sp + 0x90))
#define spA0 (*(s128 *)(sp + 0xA0))
void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(s128 *, M2C_UNK, s8 *, s8 *);
void SetCmFov(M2C_UNK *, f32);
s32 SetCmPosMat(M2C_UNK *, s128 *, s128);
void UpdateCplcy();
f32 __as__6VECTORG9VU_VECTOR(M2C_UNK *, s128);
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_002BDA70;
extern f32 g_2dded0;
void bevy_camera_policy_update(s8 *arg0) {
    s32 unksp2C;
    s8 sp[0x90] __attribute__((aligned(16)));
    s128 sp20;
    s32 sp3C;
    s32 sp4C;
    M2C_UNK sp50;
    f32 sp60;
    f32 sp64;
    f32 sp68;
    s128 sp80;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_v0;
    f32 var_f2;
    s8 *temp_a2;
    s8 *temp_a3;
    UpdateCplcy();
    temp_f0 = (g_2dded0 - M2C_FIELD(&B_002DDF40, f32 *, 0x390)) / M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), f32 *, 8);
    var_f2 = 0.0f;
    if (!(temp_f0 < 0.0f)) {
        var_f2 = temp_f0;
        if (temp_f0 > 1.0f) {
            var_f2 = 1.0f;
        }
    }
    temp_f1 = var_f2 * var_f2;
    sp68 = var_f2;
    temp_a2 = M2C_FIELD(arg0, s8 **, 0x10);
    sp64 = temp_f1;
    sp60 = temp_f1 * var_f2;
    asm volatile("lqc2 vf2, 0x60(%0)" : : "r"(sp));
    temp_a3 = M2C_FIELD(temp_a2, s8 **, 4);
    asm volatile("lqc2 vf1, (%0)" : : "r"((M2C_FIELD(temp_a2, s32 *, 0x10) * 0x10) + &D_002BDA70));
    asm volatile("vmul.xyz vf2, vf2, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
    temp_v0 = vu_1;
    temp_f20 = 1.0f - temp_v0;
    asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_v0));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_f20));
    asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, (%0)" : : "r"(M2C_FIELD(temp_a2, s8 **, 0)));
    asm volatile("sqc2 vf4, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, (%0)" : : "r"(temp_a3));
    asm volatile("vmulax.xyzw ACC, vf3, vf2x");
    asm volatile("vmaddx.xyzw vf3, vf1, vf4x");
    asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(M2C_FIELD(temp_a2, s8 **, 0)));
    asm volatile("sqc2 vf4, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(M2C_FIELD(temp_a2, s8 **, 4)));
    asm volatile("vmulax.xyzw ACC, vf3, vf2x");
    asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
    temp_f20_2 = (temp_f20 * M2C_FIELD(M2C_FIELD(temp_a2, s8 **, 0), f32 *, 0x20)) + (temp_v0 * M2C_FIELD(M2C_FIELD(temp_a2, s8 **, 4), f32 *, 0x20));
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&sp80, vu_2, temp_a2, temp_a3);
    __as__6VECTORG9VU_VECTOR(&sp50, sp0);
    sp20 = sp80;
    M2C_FIELD(&sp20, s128 *, 0x10) = sp90;
    M2C_FIELD(&sp20, s128 *, 0x20) = spA0;
    sp4C = 0;
    sp3C = 0;
    unksp2C = 0;
    M2C_FIELD(&sp20, f32 *, 0x3C) = 1.0f;
    SetCmPosMat(&B_002DDF40, &sp20, sp80);
    SetCmFov(&B_002DDF40, temp_f20_2);
}
}
