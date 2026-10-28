#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(M2C_UNK *, M2C_UNK, s128); /* extern */
M2C_UNK PxpAdd(M2C_UNK *, s32, s32, s128, f32, s32 *); /* extern */
void *func_001A5BF0(s32);                           /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dc0;

void func_00205008(void *arg0, s32 arg1, s32 arg2, s128 arg3) {
    M2C_UNK sp10;
    s128 sp40;
    s128 sp50;
    s32 sp60;
    f32 temp_s0;
    s32 *var_s2;
    s32 *var_s7;
    s32 *var_v1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    void *temp_a0;
    void *var_a0;
    void *var_v0;

    M2C_ERROR(/* unknown instruction: por $fp, $zero, $t0 */);
    sp50 = arg3;
    sp40 = M2C_ERROR(/* Read from unset register $t1 */);
    var_v0 = func_001A5BF0(arg2);
    if (var_v0 != NULL) {
        var_a0 = M2C_FIELD(var_v0, void **, 0xEC);
        var_s3 = arg1 & 1;
        var_s5 = arg1 & 2;
        sp60 = arg1 & 4;
        if (var_a0 == NULL) {
            var_v0 = M2C_FIELD(var_v0, void **, 0x10);
loop_3:
            if (var_v0 != NULL) {
                var_a0 = M2C_FIELD(var_v0, void **, 0xEC);
                if (var_a0 == NULL) {
                    var_v0 = M2C_FIELD(var_v0, void **, 0x10);
                    goto loop_3;
                }
                goto block_7;
            }
            goto block_14;
        }
block_7:
        if (var_v0 != NULL) {
            var_v1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), s32 **, 0x64);
            temp_a0 = M2C_FIELD(var_a0, void **, 0x60);
loop_9:
            if (var_v1 != NULL) {
                if (M2C_FIELD(var_v1, s32 *, 0xC) != temp_a0) {
                    var_v1 = M2C_FIELD(var_v1, s32 **, 4);
                    goto loop_9;
                }
            }
            var_s2 = var_v1;
            var_s7 = M2C_FIELD(var_s2, s32 **, 8);
            var_s4 = M2C_FIELD(M2C_FIELD(temp_a0, void **, 0xEC), s32 *, 0x34);
        } else {
            goto block_14;
        }
    } else {
block_14:
        var_s4 = 0;
        var_s3 = arg1 & 1;
        var_s5 = arg1 & 2;
        var_s7 = M2C_FIELD(arg0, void **, 0xEC) + 0x68;
        var_s2 = var_s7;
        sp60 = arg1 & 4;
    }
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp10, M2C_ERROR(/* unknown instruction: por $a1, $zero, $fp */), g_2a2dc0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf6, $vf8, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf7, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf5, $vf1, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf4, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf6, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf9, $vf7, $vf6z */);
    M2C_ERROR(/* unknown instruction: vaddax.y $acc, $vf5, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmaddz.y $vf9, $vf7, $vf5z */);
    M2C_ERROR(/* unknown instruction: vaddax.z $acc, $vf4, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmaddy.z $vf9, $vf7, $vf4y */);
    temp_s0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $s0, $vf9 */);
    if ((var_s3 != 0) || ((arg1 & 8) && (temp_s0 < 0.0001f))) {
        M2C_ERROR(/* unknown instruction: qmfc2.ni $t0, $vf8 */);
        PxpAdd(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x258), var_s4, sp40, temp_s0, var_s2);
    }
    if ((var_s5 != 0) || ((arg1 & 0x10) && (M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */) < 0.0001f))) {
        PxpAdd(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x258), var_s4, sp40, M2C_ERROR(/* unknown instruction: prot3w $v1, $s0 */), var_s2);
    }
    if ((sp60 != 0) || ((arg1 & 0x20) && (M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */) < 0.0001f))) {
        PxpAdd(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x258), var_s4, sp40, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), var_s2);
    }
    *var_s7 = *var_s2;
}
