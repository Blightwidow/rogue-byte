typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateStepPhys__FP4STEP {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ f32 sp40;                           /* inferred */
    /* 0x044 */ char pad44[0xC];                    /* maybe part of sp40[4]? */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ M2C_UNK sp90;                       /* inferred */
    /* 0x090 */ char pad90[0x40];
    /* 0x0D0 */ f32 *spD0;                          /* inferred */
    /* 0x0D4 */ char padD4[0xAC];
};                                                  /* size = 0x180 */
#define sp60 (*(s128 *)(sp + 0x060))
#define sp70 (*(s128 *)(sp + 0x070))
#define sp80 (*(s128 *)(sp + 0x080))
f32 GSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, f32, f32);
void InvertMatrix4Affine(M2C_UNK *, s32);
s32 __ml__FRC7MATRIX4T0(s128 *, M2C_UNK *, s32);
extern M2C_UNK D_002C3C68;
extern M2C_UNK g_2dded0;
void UpdateStepPhys__FP4STEP(s8 *arg0) {
    s8 sp[0xb0] __attribute__((aligned(16)));
    f32 sp40;
    s128 sp50;
    M2C_UNK sp90;
    f32 *spD0;
    f32 *var_s0;
    f32 *var_s1;
    f32 *var_s2_2;
    f32 *var_s3;
    f32 *var_s4;
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;
    s32 var_a0;
    s32 var_s2;
    s32 var_s3_2;
    s8 *temp_a0;
    s8 *temp_v1;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x258);
    if (temp_v1 != NULL) {
        temp_a0 = M2C_FIELD(arg0, s8 **, 0x25C);
        if (temp_a0 != NULL) {
            var_s2 = M2C_FIELD(temp_a0, s32 *, 0x7C);
            var_s3 = M2C_FIELD(temp_v1, f32 **, 0x7C);
            var_s4 = *M2C_FIELD(temp_v1, f32 ***, 0x10);
            InvertMatrix4Affine(&sp90, M2C_FIELD(temp_v1, s32 *, 0) + 0x40);
            __ml__FRC7MATRIX4T0(&sp50, &sp90, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x25C), s32 *, 0) + 0x40);
            var_a0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x25C), s32 *, 0x1C) - 1;
            if (var_a0 >= 0) {
                spD0 = &sp40;
                do {
                    asm volatile("lqc2 vf5, (%0)" : : "r"(var_s2));
                    asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                    var_s2_2 = var_s4;
                    asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
                    var_s1 = var_s3;
                    asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
                    asm volatile("vmulax.xyz ACC, vf2, vf5x");
                    asm volatile("vmadday.xyz ACC, vf4, vf5y");
                    asm volatile("vmaddaz.xyz ACC, vf3, vf5z");
                    asm volatile("vmaddw.xyz vf2, vf1, vf0w");
                    var_s0 = spD0;
                    asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
                    var_s4 += 0x10;
                    var_s3_2 = 2;
loop_5:
                    temp_f13 = *var_s0;
                    var_s0 += 4;
                    var_s3_2 -= 1;
                    temp_f0 = GSmooth__FfffP3SMPPf(&D_002C3C68, 0, *var_s1, temp_f13, M2C_FIELD(&g_2dded0, f32 *, 4));
                    temp_f1 = *var_s1;
                    var_s1 += 4;
                    *var_s2_2 = (temp_f0 - temp_f1) / M2C_FIELD(&g_2dded0, f32 *, 4);
                    var_s2_2 += 1;
                    if (var_s3_2 >= 0) {
                        goto loop_5;
                    }
                    var_s2 += 0x10;
                    var_a0 -= 1;
                    var_s3 += 0x10;
                } while (var_a0 >= 0);
            }
        }
    }
}
}
