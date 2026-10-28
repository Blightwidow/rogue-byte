#include "m2c_macros.h"

M2C_UNK GetXfLocalRateMatrix(s128 *, void *);       /* extern */
M2C_UNK InvertMatrix4Affine(s128 *, void *);        /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, s128 *, s128 *); /* extern */
M2C_UNK memcpy(s128 *, s128 *, M2C_UNK);            /* extern */
M2C_UNK memset(M2C_UNK, M2C_UNK);                   /* extern */

s128 *func_0022D148(s128 *arg0, void *arg1, s32 arg2) {
    char sp[0x400];
    s128 sp40;
    s128 sp80;
    s128 spC0;
    s128 sp100;
    s16 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    void *temp_a1;
    void *var_s3;

    var_s3 = arg1;
    memset(0, 0x40);
    if (var_s3 != arg2) {
        var_v1 = M2C_FIELD(var_s3, s16 *, 0x98);
loop_2:
        switch (var_v1) {
        case 0:
        case 3:
        case 10:
        case 12:
        case 15:
        case 19:
            break;
        default:
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 16:
        case 17:
        case 18:
            GetXfLocalRateMatrix(&sp40, var_s3);
            temp_a1 = M2C_FIELD(var_s3, void **, 0xA0);
            if (temp_a1 != NULL) {
                __ml__FRC7MATRIX4T0(&spC0, temp_a1 + 0x40, sp);
                InvertMatrix4Affine(&sp100, var_s3 + 0x40);
                __ml__FRC7MATRIX4T0(&sp80, &spC0, &sp100);
                var_v1_2 = 3;
                do {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s2) */);
                    var_v1_2 -= 1;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a0) */);
                } while (var_v1_2 >= 0);
                memcpy(arg0, &sp40, 0x40);
            } else {
                InvertMatrix4Affine(&spC0, var_s3 + 0x40);
                __ml__FRC7MATRIX4T0(&sp80, sp, &spC0);
                var_v1_3 = 3;
                do {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s1) */);
                    var_v1_3 -= 1;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a0) */);
                } while (var_v1_3 >= 0);
                memcpy(arg0, &sp40, 0x40);
            }
            break;
        }
        var_s3 = M2C_FIELD(var_s3, void **, 0xA0);
        if (var_s3 != arg2) {
            var_v1 = M2C_FIELD(var_s3, s16 *, 0x98);
            goto loop_2;
        }
    }
    if (arg2 != 0) {
        InvertMatrix4Affine(&sp80, arg2 + 0x40);
        __ml__FRC7MATRIX4T0(&sp40, &sp80, arg0);
        memcpy(arg0, &sp40, 0x40);
    }
    return arg0;
}
