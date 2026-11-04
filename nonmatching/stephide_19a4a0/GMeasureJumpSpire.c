#include "m2c_macros.h"

M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(M2C_UNK, M2C_UNK, s128, s128, f32, f32, M2C_UNK); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK PredictSurfaceLanding(s32, M2C_UNK, M2C_UNK, s128, f32, f32); /* extern */

f32 GMeasureJumpSpire(void *arg0, f32 fparg0) {
    s128 sp10;
    s128 sp20;
    M2C_UNK sp30;
    M2C_UNK sp40;
    s32 temp_s4;
    void *temp_s1;

    temp_s4 = M2C_FIELD(arg0, s32 *, 4);
    temp_s1 = *M2C_FIELD(arg0, void ***, 0);
    PosLoWorld(temp_s1);
    M2C_ERROR(/* unknown instruction: por $s2, $zero, $v0 */);
    PredictSurfaceLanding(temp_s4, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s2 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s3 */), M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xE8), s128 *, 0x80), M2C_FIELD(temp_s1, f32 *, 0x1F30), fparg0);
    EvaluateBezierPos__FfffP6VECTORN63(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s2 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s3 */), sp10, sp20, fparg0, 0.0f, 0x3F800000);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    EvaluateBezierPos__FfffP6VECTORN63(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s2 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s3 */), sp10, sp20, fparg0, fparg0, 0x3F800000);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    return M2C_ERROR(/* unknown instruction: min.s $f20, $f20, $f1 */);
}
