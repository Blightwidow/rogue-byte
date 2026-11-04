#include "m2c_macros.h"

f32 SProjectVector__FP6VECTORT0(s32 arg0, s32 arg1, s128 *arg2, s32 arg3) {
    f32 var_v0;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf4, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf4, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf4, $vf2, $vf4z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf4x */);
    if (arg2 != NULL) {
        *arg2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    }
    var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
    if (arg3 != 0) {
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a3) */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
    }
    return var_v0;
}
