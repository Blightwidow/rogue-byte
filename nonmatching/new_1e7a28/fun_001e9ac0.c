#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(); /* extern */
M2C_UNK EvaluateCrvFromU(); /* extern */
M2C_UNK PmatLoWorld();                        /* extern */
M2C_UNK UMaxCrv();                               /* extern */
M2C_UNK func_001F3C70();                      /* extern */

void func_001E9AC0(void *arg0) {
    char sp[0x400];
    s128 sp10;
    M2C_UNK sp50;
    s32 var_a1;
    s32 var_s4;
    void *temp_s2;
    void *var_s0;
    void *var_s3;

    func_001F3C70();
    UMaxCrv(M2C_FIELD(arg0, s32 *, 0x150));
    PmatLoWorld(arg0);
    var_s3 = M2C_FIELD(arg0, void **, 0xDC);
    if (var_s3 != NULL) {
        do {
            var_a1 = 0;
            if (M2C_FIELD(var_s3, s32 *, 4) > 0) {
loop_3:
                var_s4 = 0;
                temp_s2 = M2C_FIELD(var_s3, s32 *, 8) + (var_a1 << 5);
                var_s0 = M2C_FIELD(temp_s2, void **, 0xC);
                if (M2C_FIELD(temp_s2, s32 *, 0) > 0) {
                    do {
                        var_s4 += 1;
                        EvaluateCrvFromU(M2C_FIELD(arg0, s32 *, 0x150), sp, &sp10, M2C_ERROR(/* unknown instruction: min.s $f12, $f20, $f12 */));
                        BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp50, sp10, M2C_ERROR(/* unknown instruction: por $a2, $zero, $s6 */));
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x60($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s1) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf1x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf2, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf1, $vf3 */);
                        M2C_FIELD(var_s0, s32 *, 0) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                        M2C_FIELD(var_s0, f32 *, 8) = (f32) M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */);
                        M2C_FIELD(var_s0, f32 *, 4) = (f32) M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */);
                        var_s0 += 0x10;
                    } while (var_s4 < M2C_FIELD(temp_s2, s32 *, 0));
                }
                var_a1 += 1;
                if (var_a1 < M2C_FIELD(var_s3, s32 *, 4)) {
                    goto loop_3;
                }
            }
            var_s3 = M2C_FIELD(var_s3, void **, 0xC);
        } while (var_s3 != NULL);
    }
    func_001F3C70(arg0);
}
