#include "m2c_macros.h"

M2C_UNK PosLoWorld(s32);                            /* extern */

s32 func_0017AA78(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0x5C));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
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
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf4 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s1) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf6 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf1, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf5, $vf6x */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s2) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf5, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s3) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
}
