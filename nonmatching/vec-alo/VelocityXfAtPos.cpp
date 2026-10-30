typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_VelocityXfAtPos {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ char padC0[0x40];
};                                                  /* size = 0x100 */
#define sp60 (*(s128 *)(sp + 0x060))
#define sp70 (*(s128 *)(sp + 0x070))
#define sp80 (*(s128 *)(sp + 0x080))
#define sp90 (*(s128 *)(sp + 0x090))
M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, f32, f32, f32); /* extern */
M2C_UNK GetXfLocalRateMatrix(s128 *, s8 *);       /* extern */
M2C_UNK InvertMatrix4Affine(s128 *, s8 *);        /* extern */
M2C_UNK RefreshXfActSegment(s32, s8 *);           /* extern */
extern s128 g_2a2dd0;
s128 VelocityXfAtPos(s8 *arg0, s32 arg1, s128 arg2) {
    s8 sp[0xa0] __attribute__((aligned(16)));
    s128 sp40;
    s128 sp50;
    s128 spA0;
    s128 spB0;
    f32 temp_f0;
    s128 var_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s8 *temp_s1;
    s8 *temp_v0_3;
    s8 *temp_v0_5;
    s8 *temp_v1_3;
    s8 *var_s0;
    asm volatile("vsub.xyzw vf1, vf0, vf0");
    var_s0 = arg0;
    spB0 = arg2;
    asm volatile("sqc2 vf1, 0x90(%0)" : : "r"(sp));
    if ((s32)var_s0 != arg1) {
        do {
            temp_v1 = M2C_FIELD(var_s0, s16 *, 0x98);
            switch (temp_v1) {                      /* switch 1 */
            case 0:                                 /* switch 1 */
            case 3:                                 /* switch 1 */
            case 10:                                /* switch 1 */
            case 12:                                /* switch 1 */
            case 15:                                /* switch 1 */
            case 19:                                /* switch 1 */
                break;
            default:                                /* switch 1 */
            case 1:                                 /* switch 1 */
            case 2:                                 /* switch 1 */
            case 4:                                 /* switch 1 */
            case 5:                                 /* switch 1 */
            case 6:                                 /* switch 1 */
            case 7:                                 /* switch 1 */
            case 8:                                 /* switch 1 */
            case 9:                                 /* switch 1 */
            case 11:                                /* switch 1 */
            case 13:                                /* switch 1 */
            case 14:                                /* switch 1 */
            case 16:                                /* switch 1 */
            case 17:                                /* switch 1 */
            case 18:                                /* switch 1 */
                temp_v0 = M2C_FIELD(var_s0, s32 *, 0x94);
                switch (temp_v0) {                  /* switch 2 */
                case 1:                             /* switch 2 */
                case 4:                             /* switch 2 */
                case 5:                             /* switch 2 */
                case 9:                             /* switch 2 */
                case 10:                            /* switch 2 */
                    temp_v0_2 = (u16) M2C_FIELD(var_s0, s16 *, 0x98) - 1;
                    switch (temp_v0_2) {            /* switch 3 */
                    case 0:                         /* switch 3 */
                    case 1:                         /* switch 3 */
                    case 6:                         /* switch 3 */
                    case 7:                         /* switch 3 */
                    case 8:                         /* switch 3 */
                    case 10:                        /* switch 3 */
                    case 16:                        /* switch 3 */
                    case 17:                        /* switch 3 */
                    case 19:                        /* switch 3 */
                    case 20:                        /* switch 3 */
                        var_v0 = M2C_FIELD(var_s0, s128 *, 0xB0);
block_15:
                        spA0 = var_v0;
                        break;
                    case 4:                         /* switch 3 */
                    case 5:                         /* switch 3 */
                        temp_v0_3 = M2C_FIELD(var_s0, s8 **, 0x90);
                        if (temp_v0_3 != NULL) {
                            RefreshXfActSegment(M2C_FIELD(temp_v0_3, s32 *, 4), var_s0);
                        }
                        temp_v1_2 = M2C_FIELD(var_s0, s16 *, 0x9A);
                        switch (temp_v1_2) {        /* switch 4 */
                        case 3:                     /* switch 4 */
                        case 4:                     /* switch 4 */
                            var_v0 = M2C_FIELD(var_s0, s128 *, 0xD0);
                            break;
                        case 1:                     /* switch 4 */
                            temp_f0 = M2C_FIELD(var_s0, f32 *, 0x80);
                            EvaluateBezierPos__FfffP6VECTORN63(M2C_FIELD(var_s0, s128 *, 0xC0), M2C_FIELD(var_s0, s128 *, 0xD0), M2C_FIELD(var_s0, s128 *, 0xE0), M2C_FIELD(var_s0, s128 *, 0xF0), M2C_FIELD(var_s0, f32 *, 0x84) - temp_f0, *M2C_FIELD(var_s0, f32 **, 0x88) - temp_f0, *M2C_FIELD(var_s0, f32 **, 0x8C));
                            var_v0 = sp40;
                            break;
                        default:                    /* switch 4 */
                        case 0:                     /* switch 4 */
                        case 2:                     /* switch 4 */
                        case 5:                     /* switch 4 */
                            var_v0 = g_2a2dd0;
                            break;
                        }
                        goto block_15;
                    }
                    temp_v1_3 = M2C_FIELD(var_s0, s8 **, 0xA0);
                    temp_v0_4 = (s32)(temp_v1_3 + 0x40);
                    if (temp_v1_3 != NULL) {
                        asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(temp_v1_3));
                        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0_4));
                        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0_4));
                        asm volatile("lqc2 vf4, 0xa0(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf2, vf4x");
                        asm volatile("vmadday.xyz ACC, vf1, vf4y");
                        asm volatile("vmaddz.xyz vf2, vf3, vf4z");
                        asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(sp));
                        asm volatile("vadd.xyzw vf1, vf1, vf2");
                        asm volatile("sqc2 vf1, 0x90(%0)" : : "r"(sp));
                    } else {
                        asm volatile("lqc2 vf2, 0x90(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf3, 0xa0(%0)" : : "r"(sp));
                        asm volatile("vadd.xyzw vf2, vf2, vf3");
                        asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(sp));
                    }
                    break;
                default:                            /* switch 2 */
                    temp_v0_5 = M2C_FIELD(var_s0, s8 **, 0x90);
                    if (temp_v0_5 != NULL) {
                        RefreshXfActSegment(M2C_FIELD(temp_v0_5, s32 *, 4), var_s0);
                    }
                    GetXfLocalRateMatrix(&sp50, var_s0);
                    temp_s1 = M2C_FIELD(var_s0, s8 **, 0xA0);
                    if (temp_s1 != NULL) {
                        InvertMatrix4Affine(&sp40, var_s0 + 0x40);
                        asm volatile("lqc2 vf5, 0x50(%0)" : : "r"(sp));
                        temp_v0_6 = (s32)(temp_s1 + 0x40);
                        asm volatile("lqc2 vf2, 0x60(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf3, 0xb0(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf4, vf3x");
                        asm volatile("vmadday.xyz ACC, vf5, vf3y");
                        asm volatile("vmaddaz.xyz ACC, vf2, vf3z");
                        asm volatile("vmaddw.xyz vf4, vf1, vf0w");
                        asm volatile("lqc2 vf6, 0x40(%0)" : : "r"(temp_s1));
                        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
                        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf3, vf4x");
                        asm volatile("vmadday.xyz ACC, vf5, vf4y");
                        asm volatile("vmaddaz.xyz ACC, vf2, vf4z");
                        asm volatile("vmaddw.xyz vf3, vf1, vf0w");
                        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_v0_6));
                        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0_6));
                        asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf6, vf3x");
                        asm volatile("vmadday.xyz ACC, vf1, vf3y");
                        asm volatile("vmaddz.xyz vf3, vf2, vf3z");
                        asm volatile("vadd.xyzw vf4, vf4, vf3");
                        asm volatile("sqc2 vf4, 0x90(%0)" : : "r"(sp));
                    } else {
                        InvertMatrix4Affine(&sp40, var_s0 + 0x40);
                        asm volatile("lqc2 vf5, 0x50(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf2, 0xb0(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf4, vf2x");
                        asm volatile("vmadday.xyz ACC, vf5, vf2y");
                        asm volatile("vmaddaz.xyz ACC, vf3, vf2z");
                        asm volatile("vmaddw.xyz vf4, vf1, vf0w");
                        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf2, vf4x");
                        asm volatile("vmadday.xyz ACC, vf5, vf4y");
                        asm volatile("vmaddaz.xyz ACC, vf3, vf4z");
                        asm volatile("vmaddw.xyz vf2, vf1, vf0w");
                        asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
                        asm volatile("vadd.xyzw vf3, vf3, vf2");
                        asm volatile("sqc2 vf3, 0x90(%0)" : : "r"(sp));
                    }
                    break;
                }
                break;
            }
            var_s0 = M2C_FIELD(var_s0, s8 **, 0xA0);
        } while ((s32)var_s0 != arg1);
    }
    if (arg1 != 0) {
        InvertMatrix4Affine(&sp40, (s8 *)(arg1 + 0x40));
        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(&sp40));
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(&sp40));
        asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf2, vf4x");
        asm volatile("vmadday.xyz ACC, vf1, vf4y");
        asm volatile("vmaddz.xyz vf4, vf3, vf4z");
        asm volatile("sqc2 vf4, 0x90(%0)" : : "r"(sp));
    }
    return sp90;
}
}
