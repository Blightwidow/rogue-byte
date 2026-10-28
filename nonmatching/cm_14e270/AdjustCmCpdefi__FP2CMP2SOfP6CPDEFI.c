#include "m2c_macros.h"

M2C_UNK CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(s32); /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(void *, void *, void *, s128, M2C_UNK, M2C_UNK); /* extern */
extern s128 g_2a2dd0;

void AdjustCmCpdefi__FP2CMP2SOfP6CPDEFI(void *arg0, void *arg1, s32 arg2) {
    M2C_UNK var_f12;
    M2C_UNK var_f13;
    s128 var_a3;
    s32 temp_a0;

    CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(arg2);
    M2C_ERROR(/* unknown instruction: por $s1, $zero, $v0 */);
    if (FIsBasicDerivedFrom(arg1, 0x34) != 0) {
        temp_a0 = M2C_FIELD(arg1, s32 *, 0x4F4);
        if (temp_a0 != 1) {
            if (temp_a0 >= 2) {
                if (temp_a0 != 2) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x2c0($s0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s3) */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($s3) */);
                    return;
                }
                SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(arg0, arg0 + 0x2C0, arg0 + 0x2D0, M2C_ERROR(/* unknown instruction: por $a3, $zero, $s1 */), 0x40A00000, 0xC0600000);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x2c0($s0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s3) */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($s3) */);
                return;
            }
            if (temp_a0 != 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x2c0($s0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s3) */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($s3) */);
                return;
            }
            SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(arg0, arg0 + 0x2C0, arg0 + 0x2D0, M2C_ERROR(/* unknown instruction: por $a3, $zero, $s1 */), 0x40A00000, 0xC0600000);
            var_f12 = 0x40A00000;
            var_f13 = 0xC0600000;
            var_a3 = g_2a2dd0;
            goto block_11;
        }
        SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(arg0, arg0 + 0x2C0, arg0 + 0x2D0, M2C_ERROR(/* unknown instruction: por $a3, $zero, $s1 */), 0x3F800000, 0xC1200000);
        var_a3 = M2C_FIELD(arg0, s128 *, 0x2E0);
        var_f13 = 0xC1200000;
        var_f12 = 0;
block_11:
        SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(arg0, arg0 + 0x2E0, arg0 + 0x2F0, var_a3, var_f12, var_f13);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x2c0($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s3) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($s3) */);
        return;
    }
    SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(arg0, arg0 + 0x2C0, arg0 + 0x2D0, M2C_ERROR(/* unknown instruction: por $a3, $zero, $s1 */), 0x40A00000, 0xC0600000);
    SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(arg0, arg0 + 0x2E0, arg0 + 0x2F0, g_2a2dd0, 0x40A00000, 0xC0600000);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x2c0($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s3) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($s3) */);
}
