#include "m2c_macros.h"

M2C_UNK GetPathPosFromS(void *, M2C_UNK *);         /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */

void AttachCrv_GetPosFromParam(void *arg1, s32 arg2, f32 *arg3) {
    char sp[0x400];
    M2C_UNK sp10;
    M2C_UNK var_v0;

    GetPathPosFromS(sp, &sp10);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf4, $vf1 */);
    if (arg2 != 0) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x240($s0) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf1x */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
    }
    if (arg3 != NULL) {
        var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
        if (M2C_FIELD(arg1, s32 *, 0x1040) == 1) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf4, $vf1x */);
            var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
        }
        *arg3 = atan2f(M2C_ERROR(/* unknown instruction: prot3w $v0, $v0 */), var_v0);
    }
}
