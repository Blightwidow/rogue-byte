#include "m2c_macros.h"

M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(M2C_UNK, M2C_UNK, s128, s128, f32, f32, M2C_UNK); /* extern */
s32 FTimeJtJumpToTarget(void **, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
s128 VelocityXfAtPos(s32, M2C_UNK, M2C_UNK);        /* extern */

void MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(void **arg0, void *arg2, s128 *arg_sp0) {
    M2C_UNK sp0;
    M2C_UNK sp70;
    M2C_UNK sp10;
    M2C_UNK sp20;
    f32 sp40;
    s128 sp50;
    s128 sp60;
    f32 *temp_s5;
    f32 *temp_s6;
    f32 temp_f1;
    s128 *temp_s7;
    void *temp_v1;

    M2C_ERROR(/* unknown instruction: por $s1, $zero, $a3 */);
    M2C_ERROR(/* unknown instruction: por $s3, $zero, $a1 */);
    temp_s5 = M2C_ERROR(/* Read from unset register $t1 */);
    temp_s6 = M2C_ERROR(/* Read from unset register $t2 */);
    temp_s7 = M2C_ERROR(/* Read from unset register $t3 */);
    sp60 = M2C_ERROR(/* Read from unset register $t0 */);
    PosLoWorld(*arg0);
    temp_v1 = M2C_FIELD(arg2, void **, 0xC);
    M2C_ERROR(/* unknown instruction: por $s2, $zero, $v0 */);
    sp50 = VelocityXfAtPos(M2C_FIELD(temp_v1, s32 (**)(void *, M2C_UNK), 0x104)(arg2 + M2C_FIELD(temp_v1, s16 *, 0x100), 0), 0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $s1 */));
    M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
    M2C_ERROR(/* unknown instruction: por $t0, $zero, $s0 */);
    if (FTimeJtJumpToTarget(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s2 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s3 */), M2C_ERROR(/* unknown instruction: por $a3, $zero, $s1 */)) == 0) {
        temp_f1 = M2C_ERROR(/* unknown instruction: max.s $f1, $f1, $f5 */);
        if (temp_s5 != NULL) {
            *temp_s5 = temp_f1;
        }
        if (temp_s6 != NULL) {
            *temp_s6 = 1010000.0f - ((M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $s2 */) - M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */)) + ((M2C_FIELD(M2C_FIELD(*arg0, void **, 0xE8), f32 *, 0x88) * (temp_f1 * 0.5f) * temp_f1) + ((M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s3 */) - M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $s0 */)) * temp_f1)));
        }
    } else {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $s1, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: min.s $f0, $f0, $f1 */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        if (temp_s5 != NULL) {
            *temp_s5 = sp40;
        }
        if (temp_s6 != NULL) {
            EvaluateBezierPos__FfffP6VECTORN63(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s2 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s3 */), sp0, sp70, sp40, 0.0f, 0x3F800000);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            EvaluateBezierPos__FfffP6VECTORN63(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s2 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s3 */), sp0, sp70, sp40, sp40, 0x3F800000);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
            *temp_s6 = M2C_ERROR(/* unknown instruction: min.s $f20, $f20, $f2 */);
        }
        if (temp_s7 != NULL) {
            *temp_s7 = sp0;
        }
        if (arg_sp0 != NULL) {
            *arg_sp0 = sp70;
        }
    }
}
