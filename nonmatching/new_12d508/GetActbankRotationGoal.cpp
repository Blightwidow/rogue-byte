typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetActbankRotationGoal {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ s128 sp60;                           /* inferred */
    /* 0x70 */ s128 sp70;                           /* inferred */
    /* 0x80 */ char pad80[0x50];
};                                                  /* size = 0xD0 */
#define sp0 (*(s128 *)(sp + 0x00))
#define sp50 (*(s128 *)(sp + 0x50))
#define sp60 (*(s128 *)(sp + 0x60))
M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, s128, s128); /* extern */
M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s8 *, s128 *); /* extern */
M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, M2C_UNK, s8 *, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK RefreshXfActSegment(s32, s8 *, s8 *);   /* extern */
extern s128 D_002BC380;
extern s128 g_2a2dc0;
extern s128 g_2a2dd0;
void GetActbankRotationGoal(s8 *arg0, s8 *arg2) {
    s8 sp[0x70] __attribute__((aligned(16)));
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp70;
    f32 temp_f0;
    f32 temp_f12;
    s128 var_a1;
    s128 var_a1_2;
    s128 var_a2_2;
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_a1;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v1_3;
    s8 *temp_a0;
    s8 *temp_a3;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s1;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_4;
    s8 *var_a0;
    s8 *var_a2;
    var_a2 = arg2;
    if (M2C_FIELD(arg0, s8 **, 0x24) == NULL) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 8);
        var_a0 = M2C_FIELD(temp_v0, s8 **, 0xA0);
        var_a2 = temp_v0;
        if (var_a0 != NULL) {
            if (M2C_FIELD(var_a0, s32 *, 0x94) != 1) {
                var_a0 = M2C_FIELD(var_a0, s8 **, 0xA0);
loop_4:
                if (var_a0 != NULL) {
                    if (M2C_FIELD(var_a0, s32 *, 0x94) != 1) {
                        var_a0 = M2C_FIELD(var_a0, s8 **, 0xA0);
                        goto loop_4;
                    }
                    goto block_8;
                }
                goto block_11;
            }
block_8:
            if (var_a0 != NULL) {
                M2C_FIELD(arg0, s8 **, 0x24) = var_a0;
                goto block_12;
            }
            goto block_11;
        }
block_11:
        temp_a0 = var_a2 + 0xC0;
        M2C_FIELD(var_a2, s128 *, 0xC0) = (s128) M2C_FIELD(var_a2, s128 *, 0);
        M2C_FIELD(temp_a0, s128 *, 0x10) = (s128) M2C_FIELD(var_a2, s128 *, 0x10);
        M2C_FIELD(temp_a0, s128 *, 0x20) = (s128) M2C_FIELD(var_a2, s128 *, 0x20);
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s16 *, 0x9A) = 5;
        return;
    }
block_12:
    temp_s0 = M2C_FIELD(arg0, s8 **, 0x24);
    temp_v0_2 = M2C_FIELD(temp_s0, s8 **, 0x90);
    if (temp_v0_2 != NULL) {
        RefreshXfActSegment(M2C_FIELD(temp_v0_2, s32 *, 4), temp_s0, var_a2);
    }
    temp_v1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x24), u16 *, 0x98) - 1;
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
    case 6:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
    case 8:                                         /* switch 1 */
    case 10:                                        /* switch 1 */
    case 16:                                        /* switch 1 */
    case 17:                                        /* switch 1 */
    case 19:                                        /* switch 1 */
    case 20:                                        /* switch 1 */
        asm volatile("lqc2 vf5, 0xb0(%0)" : : "r"(temp_s0));
        break;
    case 4:                                         /* switch 1 */
    case 5:                                         /* switch 1 */
        temp_v1_2 = M2C_FIELD(temp_s0, s16 *, 0x9A);
        switch (temp_v1_2) {                        /* switch 2 */
        case 3:                                     /* switch 2 */
        case 4:                                     /* switch 2 */
            var_a1 = M2C_FIELD(temp_s0, s128 *, 0xD0);
            break;
        case 1:                                     /* switch 2 */
            temp_f0 = M2C_FIELD(temp_s0, f32 *, 0x80);
            EvaluateBezierPos__FfffP6VECTORN63(M2C_FIELD(temp_s0, s128 *, 0xC0), M2C_FIELD(temp_s0, s128 *, 0xD0), M2C_FIELD(temp_s0, s128 *, 0xE0), M2C_FIELD(temp_s0, s128 *, 0xF0), 0, sp, 0, M2C_FIELD(temp_s0, f32 *, 0x84) - temp_f0, *M2C_FIELD(temp_s0, f32 **, 0x88) - temp_f0, *M2C_FIELD(temp_s0, f32 **, 0x8C));
            var_a1 = sp0;
            break;
        default:                                    /* switch 2 */
        case 0:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
        case 5:                                     /* switch 2 */
            var_a1 = g_2a2dd0;
            break;
        }
        asm volatile("qmtc2.ni %0, vf5" : : "r"(var_a1));
        break;
    default:                                        /* switch 1 */
        asm volatile("vsub.xyzw vf5, vf0, vf0");
        break;
    }
    temp_v1_3 = M2C_FIELD(temp_s0, s32 *, 0xA0);
    temp_v0_3 = temp_v1_3 + 0x40;
    if (temp_v1_3 != 0) {
        asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(temp_v1_3));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_v0_3));
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0_3));
        asm volatile("vmulax.xyz ACC, vf3, vf5x");
        asm volatile("vmadday.xyz ACC, vf1, vf5y");
        asm volatile("vmaddz.xyz vf5, vf2, vf5z");
    }
    asm volatile("vmul.xyz vf1, vf5, vf5");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    if (vu_1 < 100.0f) {
        var_a2_2 = g_2a2dc0;
        var_a1_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s128 *, 0x40);
    } else {
        temp_f12 = M2C_FIELD(arg0, f32 *, 0x20);
        sp70 = D_002BC380;
        if ((temp_f12 > 0.0f) && (M2C_FIELD(arg0, f32 *, 0x1C) > 0.0f)) {
            temp_a3 = M2C_FIELD(temp_s0, s8 **, 0x90);
            if (temp_a3 != NULL) {
                temp_v0_4 = M2C_FIELD(temp_a3, s8 **, 0x18);
                asm volatile("sqc2 vf5, 0x80(%0)" : : "r"(sp));
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, M2C_UNK, s8 *, s8 *, f32), 0x2C)(temp_a3 + M2C_FIELD(temp_v0_4, s16 *, 0x28), 0, sp, temp_a3, temp_f12);
                temp_a1 = M2C_FIELD(temp_s0, s32 *, 0xA0);
                asm volatile("lqc2 vf5, 0x80(%0)" : : "r"(sp));
                if (temp_a1 != 0) {
                    temp_v0_5 = temp_a1 + 0x40;
                    asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(temp_a1));
                    asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0_5));
                    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0_5));
                    asm volatile("vmulax.xyz ACC, vf4, vf1x");
                    asm volatile("vmadday.xyz ACC, vf2, vf1y");
                    asm volatile("vmaddz.xyz vf1, vf3, vf1z");
                    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                }
                asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf1, vf1, vf5");
                asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(arg0, f32 *, 0x1C) / M2C_FIELD(arg0, f32 *, 0x20)));
                asm volatile("vadda.xyzw ACC, vf0, vf3");
                asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
                asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(sp));
            }
        }
        var_a2_2 = sp70;
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_2));
        var_a1_2 = vu_2;
    }
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp40, var_a1_2, var_a2_2);
    sp20 = sp50;
    sp30 = sp60;
    sp10 = sp40;
    temp_s0_2 = M2C_FIELD(arg0, s8 **, 8);
    temp_s1 = temp_s0_2 + 0xC0;
    ConvertXfMat(&sp40, 0, M2C_FIELD(temp_s0_2, s8 **, 0xA0), &sp10);
    M2C_FIELD(temp_s0_2, s128 *, 0xC0) = sp40;
    M2C_FIELD(temp_s1, s128 *, 0x10) = sp50;
    M2C_FIELD(temp_s1, s128 *, 0x20) = sp60;
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s16 *, 0x9A) = 5;
}
}
