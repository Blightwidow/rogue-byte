#include "m2c_macros.h"

f32 RadNormalize__Ff(M2C_UNK, f32);                 /* extern */
extern f32 g_2dded0;

s32 CblipeProjectBlipTransformAccel__FP7MATRIX4G8VU_FLOATP5BLIPPP5BLIPVP5BLIPXi6BLIPOKP6VECTORT7(s32 arg2, void *arg3, s32 arg_sp0) {
    s32 sp0;
    s32 sp4;
    s32 sp8;
    f32 temp_f21;
    s32 var_s5;
    s32 var_s6;
    void *var_s1;
    void *var_s2;
    void *var_s3;

    var_s6 = 0;
    sp8 = M2C_ERROR(/* Read from unset register $t3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf28, 0x30($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf25, ($v0) */);
    sp0 = arg2;
    temp_f21 = g_2dded0;
    M2C_ERROR(/* unknown instruction: lqc2 $vf31, ($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf30, 0x10($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf29, 0x20($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf26, ($t3) */);
    sp4 = M2C_ERROR(/* Read from unset register $t2 */);
    if (M2C_ERROR(/* Read from unset register $t1 */) > 0) {
        var_s1 = M2C_ERROR(/* Read from unset register $t0 */);
        var_s5 = M2C_ERROR(/* Read from unset register $t1 */);
        var_s3 = arg3;
        var_s2 = var_s1 - 0x10;
        do {
            if (!(M2C_FIELD(var_s3, f32 *, 0xC) <= temp_f21)) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf24, ($s3) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf23, ($s4) */);
                M2C_ERROR(/* unknown instruction: vcallms 0x10 */);
                var_s2 += 0x10;
                M2C_FIELD(var_s2, s128 *, 0) = (s128) M2C_FIELD(var_s1, s128 *, 0);
                if (sp4 == 2) {
                    M2C_FIELD(var_s2, f32 *, 0xC) = RadNormalize__Ff(2, M2C_FIELD(var_s1, f32 *, 0xC) + (M2C_FIELD(var_s1, f32 *, 8) * M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf27 */)));
                }
                M2C_ERROR(/* unknown instruction: cfc2.i $v0, $vi0 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf22, ($v1) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf21, ($v0) */);
            } else {
                var_s6 += 1;
            }
            var_s1 += 0x10;
            var_s5 -= 1;
            var_s3 += 0x10;
        } while (var_s5 != 0);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf26, ($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf25, ($v1) */);
    return var_s6;
}
