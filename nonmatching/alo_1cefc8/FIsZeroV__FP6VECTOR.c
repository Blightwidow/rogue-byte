#include "m2c_macros.h"

s32 FIsZeroV__FP6VECTOR(void) {
    s32 var_v0;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    var_v0 = 1;
    if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 4.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
