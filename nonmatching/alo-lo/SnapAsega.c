#include "m2c_macros.h"

M2C_UNK BuildXfLocalMatrix(s128 *, void *, M2C_UNK); /* extern */
M2C_UNK DecomposeRotateMatrixEuler(void *);         /* extern */
M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, f32, f32, f32); /* extern */
s32 FActDrivesXf(void *);                           /* extern */
s32 FAsegaGone();                                   /* extern */
M2C_UNK GetXfDofValue(void *, void *);              /* extern */
M2C_UNK RefreshXfActSegment(s32, void *);           /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;

void SnapAsega(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp60;
    M2C_UNK sp70;
    M2C_UNK sp80;
    s128 sp40;
    s128 sp50;
    s32 sp90;
    f32 temp_f0;
    s16 temp_v1;
    s16 temp_v1_3;
    s32 *temp_v1_2;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s5;
    s32 var_v0;
    void ***var_s0_3;
    void **var_a3;
    void **var_s1;
    void **var_v1;
    void *temp_s1;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_a1;
    void *var_s3;

    sp90 = arg1;
    if (FAsegaGone() == 0) {
        var_s3 = M2C_FIELD(arg0, void **, 0x34);
        var_s5 = 0;
        if (var_s3 != NULL) {
            do {
                if (FActDrivesXf(var_s3) != 0) {
                    temp_s1 = M2C_FIELD(var_s3, void **, 8);
                    temp_s2 = M2C_FIELD(var_s3, s32 *, 4);
                    RefreshXfActSegment(temp_s2, temp_s1);
                    temp_v1 = M2C_FIELD(temp_s1, s16 *, 0x98);
                    switch (temp_v1) {              /* switch 1 */
                    case 7:                         /* switch 1 */
                    case 8:                         /* switch 1 */
                    case 9:                         /* switch 1 */
                    case 11:                        /* switch 1 */
                        if (sp90 != 0) {
                        default:                    /* switch 1 */
                            var_s0 = 0;
                            if (var_s5 > 0) {
                                var_v0 = var_s5 > 0;
                                if (temp_s2 != sp0) {
                                    var_v1 = sp;
loop_10:
                                    var_s0 += 1;
                                    var_v1 += 4;
                                    if (var_s0 < var_s5) {
                                        if (temp_s2 == *var_v1) {
                                            var_v0 = var_s0 < var_s5;
                                            goto block_13;
                                        }
                                        goto loop_10;
                                    }
                                    goto block_14;
                                }
block_13:
                                if (var_v0 == 0) {
                                    goto block_14;
                                }
                            } else {
block_14:
                                if ((u32) var_s5 < 0x10U) {
                                    temp_v1_2 = sp + (var_s5 * 4);
                                    var_s5 += 1;
                                    *temp_v1_2 = temp_s2;
                                }
                            }
                            temp_v1_3 = M2C_FIELD(temp_s1, s16 *, 0x9A);
                            switch (temp_v1_3) {    /* switch 2 */
                            case 0:                 /* switch 2 */
                                GetXfDofValue(temp_s1, temp_s1);
                                break;
                            case 1:                 /* switch 2 */
                                temp_f0 = M2C_FIELD(temp_s1, f32 *, 0x80);
                                EvaluateBezierPos__FfffP6VECTORN63(M2C_FIELD(temp_s1, s128 *, 0xC0), M2C_FIELD(temp_s1, s128 *, 0xD0), M2C_FIELD(temp_s1, s128 *, 0xE0), M2C_FIELD(temp_s1, s128 *, 0xF0), M2C_FIELD(temp_s1, f32 *, 0x84) - temp_f0, *M2C_FIELD(temp_s1, f32 **, 0x88) - temp_f0, *M2C_FIELD(temp_s1, f32 **, 0x8C));
                                break;
                            case 2:                 /* switch 2 */
                            case 3:                 /* switch 2 */
                            case 4:                 /* switch 2 */
                                break;
                            case 5:                 /* switch 2 */
                                DecomposeRotateMatrixEuler(temp_s1 + 0xC0);
                                break;
                            default:                /* switch 2 */
                                break;
                            }
                            BuildXfLocalMatrix(&sp50, temp_s1, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
                            M2C_FIELD(temp_s1, s128 *, 0) = sp50;
                            M2C_FIELD(temp_s1, s128 *, 0x10) = sp60;
                            M2C_FIELD(temp_s1, s128 *, 0x20) = sp70;
                            M2C_FIELD(temp_s1, s128 *, 0x30) = sp80;
                            M2C_FIELD(temp_s1, s128 *, 0xB0) = (s128) g_2a2dd0;
                            temp_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
                            M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0;
                            M2C_FIELD(temp_s1, s32 *, 0xA4) = temp_v0;
                        }
                        break;
                    }
                }
                var_s3 = M2C_FIELD(var_s3, void **, 0x28);
            } while (var_s3 != NULL);
        }
        var_s0_2 = var_s5;
        if (var_s5 > 0) {
            var_s1 = sp;
            var_a1 = *sp;
loop_27:
            var_s0_2 -= 1;
            var_s1 += 4;
            temp_v0_2 = M2C_FIELD(var_a1, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x94)(var_a1 + M2C_FIELD(temp_v0_2, s16 *, 0x90), var_a1);
            if (var_s0_2 != 0) {
                var_a1 = *var_s1;
                goto loop_27;
            }
        }
        var_s0_3 = M2C_FIELD(arg0, void ****, 0x38);
        if (var_s0_3 != NULL) {
            var_a3 = *var_s0_3;
loop_32:
            temp_v0_3 = *var_a3;
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, s32, M2C_UNK, void **, f32, f32), 0x14)(var_a3 + M2C_FIELD(temp_v0_3, s16 *, 0x10), M2C_FIELD(var_s0_3, s32 *, 4), 0, var_a3, M2C_FIELD(arg0, f32 *, 0x1C), M2C_FIELD(arg0, f32 *, 0x40));
            var_s0_3 = M2C_FIELD(var_s0_3, void ****, 0x10);
            if (var_s0_3 != NULL) {
                var_a3 = *var_s0_3;
                goto loop_32;
            }
        }
    }
}
