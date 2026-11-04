#include "m2c_macros.h"

M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, f32, f32, f32); /* extern */
M2C_UNK GetXfLocalRateMatrix(s128 *, void *);       /* extern */
M2C_UNK InvertMatrix4Affine(s128 *, void *);        /* extern */
M2C_UNK RefreshXfActSegment(s32, void *);           /* extern */
extern s128 g_2a2dd0;

s128 VelocityXfAtPos(void *arg0, s32 arg1, s128 arg2) {
    M2C_UNK sp90;
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
    void *temp_v0_3;
    void *temp_v0_4;
    void *var_s0;

    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf0, $vf0 */);
    var_s0 = arg0;
    spB0 = arg2;
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
    if (var_s0 != arg1) {
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
                        temp_v0_3 = M2C_FIELD(var_s0, void **, 0x90);
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
                    if (M2C_FIELD(var_s0, void **, 0xA0) != NULL) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($v1) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xa0($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf4y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf3, $vf4z */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($sp) */);
                        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
                    } else {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x90($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xa0($sp) */);
                        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf2, $vf3 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
                    }
                    break;
                default:                            /* switch 2 */
                    temp_v0_4 = M2C_FIELD(var_s0, void **, 0x90);
                    if (temp_v0_4 != NULL) {
                        RefreshXfActSegment(M2C_FIELD(temp_v0_4, s32 *, 4), var_s0);
                    }
                    GetXfLocalRateMatrix(&sp50, var_s0);
                    if (M2C_FIELD(var_s0, void **, 0xA0) != NULL) {
                        InvertMatrix4Affine(&sp40, var_s0 + 0x40);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xb0($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf3x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf3y */);
                        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf3z */);
                        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf4, $vf1, $vf0w */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x40($s1) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf4y */);
                        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf4z */);
                        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf1, $vf0w */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf6, $vf3x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf3y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf2, $vf3z */);
                        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf4, $vf4, $vf3 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x90($sp) */);
                    } else {
                        InvertMatrix4Affine(&sp40, var_s0 + 0x40);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf2z */);
                        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf4, $vf1, $vf0w */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf4y */);
                        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf4z */);
                        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
                        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf3, $vf2 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
                    }
                    break;
                }
                break;
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0xA0);
        } while (var_s0 != arg1);
    }
    if (arg1 != 0) {
        InvertMatrix4Affine(&sp40, arg1 + 0x40);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf3, $vf4z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x90($sp) */);
    }
    return sp90;
}
