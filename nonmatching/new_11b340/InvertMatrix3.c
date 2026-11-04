#include "m2c_macros.h"

s32 InvertMatrix3(s32 arg0) {
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf3 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf4, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf5, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf6, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf9, $vf2, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmulax.w $acc, $vf0, $vf9x */);
    M2C_ERROR(/* unknown instruction: vmadday.w $acc, $vf0, $vf9y */);
    M2C_ERROR(/* unknown instruction: vmaddz.w $vf9, $vf0, $vf9z */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf8, $vf0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf7, $vf0, $vf5 */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf9w */);
    M2C_ERROR(/* unknown instruction: vaddx.y $vf4, $vf0, $vf5x */);
    M2C_ERROR(/* unknown instruction: vaddx.z $vf4, $vf0, $vf6x */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf5, $vf0, $vf8y */);
    M2C_ERROR(/* unknown instruction: vaddy.z $vf5, $vf0, $vf6y */);
    M2C_ERROR(/* unknown instruction: vaddz.x $vf6, $vf0, $vf8z */);
    M2C_ERROR(/* unknown instruction: vaddz.y $vf6, $vf0, $vf7z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyz $vf4, $vf4, $q */);
    M2C_ERROR(/* unknown instruction: vmulq.xyz $vf5, $vf5, $q */);
    M2C_ERROR(/* unknown instruction: vmulq.xyz $vf6, $vf6, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($a0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x20($a0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($a0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x20($sp) */);
    return arg0;
}
