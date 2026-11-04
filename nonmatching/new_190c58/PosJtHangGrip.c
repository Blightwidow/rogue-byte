#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */

s32 PosJtHangGrip(void *arg0) {
    PosLoWorld(M2C_FIELD(arg0, void **, 0x18C4));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v1) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f)) {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
}
