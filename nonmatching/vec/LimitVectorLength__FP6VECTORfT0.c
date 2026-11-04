#include "m2c_macros.h"

s32 LimitVectorLength__FP6VECTORfT0(f32 fparg0) {
    s32 var_v0;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
    if (fparg0 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */)) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    }
    return var_v0;
}
