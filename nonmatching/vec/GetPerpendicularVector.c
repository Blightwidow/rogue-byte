#include "m2c_macros.h"

s32 GetPerpendicularVector(s32 arg0) {
    s128 sp0;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f5;

    temp_f5 = fabsf(M2C_BITWISE(f32, arg0));
    temp_f0 = fabsf(M2C_ERROR(/* unknown instruction: prot3w $v0, $a0 */));
    temp_f4 = fabsf(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $a0 */));
    if (temp_f5 <= temp_f0) {
        if (!(temp_f5 <= temp_f4)) {
            M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
            M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
        } else {
            M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
            M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
        }
        goto block_8;
    }
    if (temp_f0 <= temp_f4) {
        M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
        M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
block_8:
        sp0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
        sp0 = M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    }
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf1, $q */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
}
