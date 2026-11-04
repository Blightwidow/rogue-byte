#include "m2c_macros.h"

s32 InvertMatrix4Affine(s32 arg0) {
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($a1) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf5, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf3 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf6, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf7, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf10, $vf3, $vf5 */);
    M2C_ERROR(/* unknown instruction: vmulax.w $acc, $vf0, $vf10x */);
    M2C_ERROR(/* unknown instruction: vmadday.w $acc, $vf0, $vf10y */);
    M2C_ERROR(/* unknown instruction: vmaddz.w $vf10, $vf0, $vf10z */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf10, $vf0, $vf5 */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf9, $vf0, $vf6 */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf4, $vf0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf10w */);
    M2C_ERROR(/* unknown instruction: vaddx.y $vf5, $vf0, $vf6x */);
    M2C_ERROR(/* unknown instruction: vaddx.z $vf5, $vf0, $vf7x */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf6, $vf0, $vf10y */);
    M2C_ERROR(/* unknown instruction: vaddy.z $vf6, $vf0, $vf7y */);
    M2C_ERROR(/* unknown instruction: vaddz.x $vf7, $vf0, $vf10z */);
    M2C_ERROR(/* unknown instruction: vaddz.y $vf7, $vf0, $vf9z */);
    M2C_ERROR(/* unknown instruction: vmulq.xyz $vf5, $vf5, $q */);
    M2C_ERROR(/* unknown instruction: vsub.w $vf5, $vf0, $vf0 */);
    M2C_ERROR(/* unknown instruction: vmulq.xyz $vf6, $vf6, $q */);
    M2C_ERROR(/* unknown instruction: vsub.w $vf6, $vf0, $vf0 */);
    M2C_ERROR(/* unknown instruction: vmulq.xyz $vf7, $vf7, $q */);
    M2C_ERROR(/* unknown instruction: vsub.w $vf7, $vf0, $vf0 */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf8, $vf7, $vf4z */);
    M2C_ERROR(/* unknown instruction: vaddx.w $vf8, $vf0, $vf0x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($a0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x20($a0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x30($a0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($a0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x30($sp) */);
    return arg0;
}
