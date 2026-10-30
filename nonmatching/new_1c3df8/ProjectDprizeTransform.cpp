typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ProjectDprizeTransform {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x008 */ s32 sp8;                            /* overlap; inferred */
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x10];
    /* 0x020 */ M2C_UNK sp20;                       /* inferred */
    /* 0x020 */ char pad20[0x10];
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x10];
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ char pad80[0x30];                   /* maybe part of sp70[4]? */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ char padE0[0xD0];
};                                                  /* size = 0x1B0 */
#define sp0 (*(s128 *)(sp + 0x000))
#define spC0 (*(s128 *)(sp + 0x0C0))
#define spD0 (*(s128 *)(sp + 0x0D0))
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, s128, s128);
void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(s128 *, s128);
void ProjectSoTransform(...);
f32 __as__6VECTORG9VU_VECTOR(s8 *, M2C_UNK);
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;
extern f32 RO_002C0D4C;
extern s128 g_2a2dc0;
extern M2C_UNK g_2dded0;
void ProjectDprizeTransform(s8 *arg0) {
    s8 sp[0x110] __attribute__((aligned(16)));
#define sp8 (*(s32 *)(sp + 0x08))
#define sp10 (*(M2C_UNK *)(sp + 0x10))
#define sp20 (*(M2C_UNK *)(sp + 0x20))
#define sp30 (*(s128 *)(sp + 0x30))
#define sp40 (*(M2C_UNK *)(sp + 0x40))
#define sp50 (*(s128 *)(sp + 0x50))
#define sp60 (*(s128 *)(sp + 0x60))
#define sp70 (*(s128 *)(sp + 0x70))
#define spB0 (*(s128 *)(sp + 0xB0))
    f32 var_f0;
    s32 temp_a1;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s2;
    s8 **var_s4;
    s8 **var_s5;
    s8 *temp_a0;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s0_3;
    s8 *temp_s3;
    s8 *temp_s6;
    s8 *temp_v0;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    if (temp_v1 == 6) {
        ProjectSoTransform();
        return;
    }
    {
        if (temp_v1 == 0 || temp_v1 == 5) {
            var_f0 = (RO_002C0D4C * M2C_FIELD(&g_2dded0, f32 *, 4)) + 1.0f;
        } else {
            var_f0 = 1.0f;
        }
        asm volatile("qmtc2.ni %0, vf3" : : "r"(var_f0));
        asm volatile("lqc2 vf2, 0x180(%0)" : : "r"(arg0));
        asm volatile("qmtc2.ni %0, vf4" : : "r"(M2C_FIELD(&g_2dded0, s32 *, 4)));
        asm volatile("lqc2 vf1, 0x190(%0)" : : "r"(arg0));
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("vmulax.xyzw ACC, vf2, vf3x");
        asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
        asm volatile("sqc2 vf2, 0x180(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf1, 0x170(%0)" : : "r"(arg0));
        temp_s0 = M2C_FIELD(arg0, s8 **, 0x58);
        asm volatile("qmtc2.ni %0, vf3" : : "r"(M2C_FIELD(&g_2dded0, s32 *, 4)));
        asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
        asm volatile("vadda.xyzw ACC, vf0, vf1");
        asm volatile("vmaddx.xyzw vf1, vf2, vf3x");
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x170(%0)" : : "r"(arg0));
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        __as__6VECTORG9VU_VECTOR(temp_s0 + 0x30, vu_1);
        M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x58), s128 *, 0xB0) = (s128) M2C_FIELD(arg0, s128 *, 0x180);
        temp_v1_2 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
        M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v1_2;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x58), s32 *, 0xA4) = temp_v1_2;
        temp_v0 = M2C_FIELD(arg0, s8 **, 0x168);
        if (temp_v0 != NULL) {
            temp_s6 = M2C_FIELD(temp_v0, s8 **, 0x30);
            var_s5 = NULL;
            if (temp_s6 != NULL) {
                temp_s3 = M2C_FIELD(temp_s6, s8 **, 0x14);
                var_s2 = 0;
                var_s4 = NULL;
                if (M2C_FIELD(temp_s3, s32 *, 0x5C) > 0) {
loop_10:
                    temp_s0_2 = (s8 *)(M2C_FIELD(temp_s3, s32 *, 0x60) + (var_s2 * 8));
                    temp_a1 = M2C_FIELD(temp_s0_2, s32 *, 0);
                    if ((temp_a1 & 0x40000000) && (((s32) (temp_a1 << 0xC) >> 0xC) == M2C_FIELD(arg0, s32 *, 0x18))) {
                        temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
                        temp_v0_2 = M2C_FIELD(temp_v1_3, s32 (**)(s8 *, s32), 0x19C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x198), (s32) (temp_a1 * 4) >> 0x16);
                        if ((s8 *)temp_v0_2 != M2C_FIELD(arg0, s8 **, 0x58)) {
                            if ((s8 *)temp_v0_2 == M2C_FIELD(arg0, s8 **, 0x5C)) {
                                var_s4 = M2C_FIELD(temp_s0_2, s8 ***, 4);
                            }
                        } else {
                            var_s5 = M2C_FIELD(temp_s0_2, s8 ***, 4);
                        }
                        if ((var_s5 == NULL) || (var_s4 == NULL)) {
                            goto block_20;
                        }
                    } else {
block_20:
                        var_s2 += 1;
                        if (var_s2 < M2C_FIELD(temp_s3, s32 *, 0x5C)) {
                            goto loop_10;
                        }
                    }
                }
                if ((var_s5 != NULL) || (var_s4 != NULL)) {
                    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(M2C_FIELD(arg0, s8 **, 0x58)));
                    asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(&B_002DDF40));
                    asm volatile("vsub.xyzw vf1, vf1, vf2");
                    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                    sp8 = 0;
                    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&spB0, sp0, g_2a2dc0);
                    sp50 = spB0;
                    sp60 = spC0;
                    sp70 = spD0;
                    if (var_s5 != NULL) {
                        temp_v1_4 = (s8 *)*var_s5;
                        M2C_FIELD(temp_v1_4, M2C_UNK (**)(s8 *, M2C_UNK *, M2C_UNK *, f32, f32), 0x1C)((s8 *)var_s5 + M2C_FIELD(temp_v1_4, s16 *, 0x18), &sp10, &sp20, M2C_FIELD(temp_s6, f32 *, 0x1C), M2C_FIELD(temp_s6, f32 *, 0x40));
                        temp_s0_3 = M2C_FIELD(arg0, s8 **, 0x58);
                        asm volatile("lqc2 vf5, 0x50(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf4, 0x60(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf5, vf3x");
                        asm volatile("vmadday.xyz ACC, vf4, vf3y");
                        asm volatile("vmaddz.xyz vf3, vf1, vf3z");
                        asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(temp_s0_3));
                        asm volatile("vadd.xyzw vf1, vf2, vf3");
                        s32 vu_2;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                        __as__6VECTORG9VU_VECTOR(temp_s0_3 + 0x30, vu_2);
                        M2C_FIELD(temp_s0_3, f32 *, 0x3C) = 1.0f;
                        temp_v1_5 = M2C_FIELD(arg0, s8 **, 0x58);
                        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf5, 0x50(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf4, 0x60(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_v1_5));
                        asm volatile("vmulax.xyz ACC, vf5, vf3x");
                        asm volatile("vmadday.xyz ACC, vf4, vf3y");
                        asm volatile("vmaddz.xyz vf3, vf2, vf3z");
                        asm volatile("vadd.xyzw vf1, vf1, vf3");
                        asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(temp_v1_5));
                        temp_v0_3 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
                        M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_3;
                        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x58), s32 *, 0xA4) = temp_v0_3;
                    }
                    if (var_s4 != NULL) {
                        temp_v1_6 = (s8 *)*var_s4;
                        M2C_FIELD(temp_v1_6, M2C_UNK (**)(s8 *, s128 *, M2C_UNK *, f32, f32), 0x1C)((s8 *)var_s4 + M2C_FIELD(temp_v1_6, s16 *, 0x18), &sp30, &sp40, M2C_FIELD(temp_s6, f32 *, 0x1C), M2C_FIELD(temp_s6, f32 *, 0x40));
                        LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&spB0, sp30);
                        asm volatile("lqc2 vf2, 0x60(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf8, 0xb0(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf5, 0xc0(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf6, 0xd0(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf3, 0x50(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf3, vf8x");
                        asm volatile("vmadday.xyz ACC, vf2, vf8y");
                        asm volatile("vmaddz.xyz vf4, vf1, vf8z");
                        asm volatile("vmulax.xyz ACC, vf3, vf6x");
                        asm volatile("vmadday.xyz ACC, vf2, vf6y");
                        asm volatile("vmaddz.xyz vf7, vf1, vf6z");
                        temp_a0 = M2C_FIELD(arg0, s8 **, 0x5C);
                        asm volatile("vmulax.xyz ACC, vf3, vf5x");
                        asm volatile("vmadday.xyz ACC, vf2, vf5y");
                        asm volatile("vmaddz.xyz vf3, vf1, vf5z");
                        asm volatile("sqc2 vf3, 0xc0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf7, 0xd0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf4, 0xe0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf4, 0xb0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf3, 0xf0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf8, 0x80(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf5, 0x90(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf6, 0xa0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf7, 0x100(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf4, (%0)" : : "r"(temp_a0));
                        M2C_FIELD(temp_a0, s128 *, 0x10) = spC0;
                        M2C_FIELD(temp_a0, s32 *, 0xC) = 0;
                        M2C_FIELD(temp_a0, s128 *, 0x20) = spD0;
                        M2C_FIELD(temp_a0, s32 *, 0x2C) = 0;
                        M2C_FIELD(temp_a0, s32 *, 0x1C) = 0;
                        asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf4, 0x50(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf4, vf2x");
                        asm volatile("vmadday.xyz ACC, vf3, vf2y");
                        asm volatile("vmaddz.xyz vf2, vf1, vf2z");
                        asm volatile("sqc2 vf2, 0xb0(%0)" : : "r"(M2C_FIELD(arg0, s8 **, 0x5C)));
                        temp_v0_4 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
                        M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_4;
                        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x5C), s32 *, 0xA4) = temp_v0_4;
                    }
                }
            }
        }
        ProjectSoTransform(arg0);
        return;
    }
}
}
