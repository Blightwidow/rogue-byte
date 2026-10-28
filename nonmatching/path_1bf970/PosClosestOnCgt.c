#include "m2c_macros.h"

M2C_UNK ClosestPointOnSegment(M2C_UNK, M2C_UNK, M2C_UNK, void *); /* extern */

s128 PosClosestOnCgt(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK var_a0;
    M2C_UNK var_a1;
    M2C_UNK var_a2;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf4 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v1) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf4, $vf6 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf9, $vf5, $vf6 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf9 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf9, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf8, $vf6 */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf7, $vf3 */);
    if (M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v1 */) > 0.0f) {
        var_a0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf4 */);
        var_a1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf6 */);
        var_a2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf5 */);
        goto block_6;
    }
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf4, $vf5 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf5 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    var_a0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf4 */);
    if (M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */) > 0.0f) {
        var_a1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf5 */);
        var_a2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */);
        goto block_6;
    }
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf4, $vf3 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf6, $vf3 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    var_a0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf4 */);
    if (M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v1 */) > 0.0f) {
        var_a1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */);
        var_a2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf6 */);
block_6:
        ClosestPointOnSegment(var_a0, var_a1, var_a2, sp);
    } else {
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf7, $vf8 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf8, $vf4 */);
        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf9, $vf1 */);
        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf1, $vf9 */);
        M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
        M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v1 */);
        M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    }
    return sp0;
}
