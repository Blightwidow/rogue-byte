#include "m2c_macros.h"

s32 bevy_player_p14_1c4768(s32 arg0) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f1;

    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($a0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf6, $vf2, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf7, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf5, $vf1, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf4, $vf3, $vf8 */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf6, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf7, $vf6z */);
    M2C_ERROR(/* unknown instruction: vaddax.y $acc, $vf5, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmaddz.y $vf2, $vf7, $vf5z */);
    M2C_ERROR(/* unknown instruction: vaddax.z $acc, $vf4, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmaddy.z $vf2, $vf7, $vf4y */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    temp_f1 = sp8;
    temp_f0 = -sp4;
    sp8 = 0.0f;
    sp4 = temp_f1;
    sp0 = temp_f0;
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    }
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
}
