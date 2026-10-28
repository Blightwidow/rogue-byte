#include "m2c_macros.h"

M2C_UNK PredictXfLocal(); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(); /* extern */
M2C_UNK memset();           /* extern */

void PredictXfTransformAdjust(void *arg0, s32 arg1, void *arg2, void *arg3, f32 fparg0) {
    char sp[0x400];
    M2C_UNK sp110;
    M2C_UNK sp120;
    M2C_UNK sp130;
    M2C_UNK sp40;
    s128 sp80;                                      /* compiler-managed */
    s128 sp90;
    s128 spA0;
    s128 spB0;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    s128 spF0;
    s128 sp100;
    s128 sp140;
    s128 sp180;
    s32 var_v1;
    void *var_s0;

    if (arg3 != NULL) {
        spC0 = M2C_FIELD(arg3, s128 *, 0);
        spD0 = M2C_FIELD(arg3, s128 *, 0x10);
        spE0 = M2C_FIELD(arg3, s128 *, 0x20);
        spF0 = M2C_FIELD(arg3, s128 *, 0x30);
    } else {
        memset(&spC0, 0, 0x40);
    }
    if (arg2 != NULL) {
        sp80 = M2C_FIELD(arg2, s128 *, 0);
        sp90 = M2C_FIELD(arg2, s128 *, 0x10);
        spA0 = M2C_FIELD(arg2, s128 *, 0x20);
        spB0 = M2C_FIELD(arg2, s128 *, 0x30);
    } else {
        memset(&sp80, 0, 0x40);
        M2C_FIELD(&sp80, f32 *, 0x14) = 1.0f;
        M2C_FIELD(&sp80, f32 *, 0x3C) = 1.0f;
        M2C_FIELD(&sp80, f32 *, 0x28) = 1.0f;
        sp80 = 1.0f;
    }
    var_s0 = arg0;
    if (var_s0 != arg1) {
        do {
            PredictXfLocal(var_s0, sp, &sp40, fparg0);
            __ml__FRC7MATRIX4T0(&sp140, sp, &spC0);
            __ml__FRC7MATRIX4T0(&sp180, &sp40, (s128 *) &sp80);
            var_v1 = 3;
loop_9:
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
            var_v1 -= 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v0) */);
            if (var_v1 >= 0) {
                goto loop_9;
            }
            spE0 = sp120;
            spF0 = sp130;
            spC0 = sp100;
            spD0 = sp110;
            __ml__FRC7MATRIX4T0(&sp100, sp, (s128 *) &sp80, sp110);
            sp80 = sp100;
            sp90 = sp110;
            spA0 = sp120;
            spB0 = sp130;
            var_s0 = M2C_FIELD(var_s0, void **, 0xA0);
        } while (var_s0 != arg1);
    }
    if (arg2 != NULL) {
        M2C_FIELD(arg2, s128 *, 0) = sp80;
        M2C_FIELD(arg2, s128 *, 0x30) = spB0;
        M2C_FIELD(arg2, s128 *, 0x10) = sp90;
        M2C_FIELD(arg2, s128 *, 0x20) = spA0;
    }
    if (arg3 != NULL) {
        M2C_FIELD(arg3, s128 *, 0) = spC0;
        M2C_FIELD(arg3, s128 *, 0x30) = spF0;
        M2C_FIELD(arg3, s128 *, 0x10) = spD0;
        M2C_FIELD(arg3, s128 *, 0x20) = spE0;
    }
}
