#include "m2c_macros.h"

M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001A5EE8(s32, s128 *, f32, f32);       /* extern */

void func_001A5FB8(s32 arg0, f32 fparg0, f32 fparg1) {
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK unksp3C;
    s128 sp30;
    s32 sp4C;
    s32 sp5C;
    M2C_UNK sp60;

    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf7, $vf1, $vf8 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($v0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf8, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf7 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf6, $vf7, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf6, $vf6 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) > 0.01f) {
        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf6, $vf7 */);
        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf7, $vf6 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf6, $vf3x */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf7, $vf5x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x70($sp) */);
        __as__6VECTORG9VU_VECTOR(&sp60, M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf8 */), M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */));
        sp30 = sp0;
        M2C_FIELD(&sp30, s128 *, 0x10) = sp10;
        M2C_FIELD(&sp30, s128 *, 0x20) = sp20;
        sp5C = 0;
        sp4C = 0;
        unksp3C = 0;
        M2C_FIELD(&sp30, f32 *, 0x3C) = 1.0f;
        func_001A5EE8(arg0, &sp30, fparg1, fparg1);
    }
}
