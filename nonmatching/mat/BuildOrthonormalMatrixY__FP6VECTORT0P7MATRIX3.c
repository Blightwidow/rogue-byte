#include "m2c_macros.h"

s128 GetPerpendicularVector(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void *BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(void *arg0) {
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf4, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf4 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf4, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($s0) */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($s0) */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($s0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) < 0.0001f) {
        M2C_FIELD(arg0, s128 *, 0x10) = GetPerpendicularVector(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf4 */), M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf3 */), M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf2 */));
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s0) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($s0) */);
    return arg0;
}
