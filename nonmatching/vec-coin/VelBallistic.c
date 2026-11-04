#include "m2c_macros.h"

s32 VelBallistic(f32 fparg0) {
    M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $a2 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf5, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf5, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf5, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf5 */);
}
