#include "m2c_macros.h"

s32 FCheckLm__FP2LMf(s32, M2C_UNK, M2C_UNK);        /* extern */
f32 HitFx_GIntensity(void *);                       /* extern */

s32 FHitFxCoversPos(void *arg0) {
    s32 var_v0;

    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
    if (FCheckLm__FP2LMf(M2C_FIELD(arg0, s32 *, 0x14) + 0x58, M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */)) == 0) {
        return 0;
    }
    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    var_v0 = 1;
    if (!(HitFx_GIntensity(arg0) < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */))) {
        var_v0 = 0;
    }
    return var_v0 ^ 1;
}
