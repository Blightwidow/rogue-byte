#include "m2c_macros.h"

M2C_UNK PosLoWorld(s32);                            /* extern */

s32 GoalFollowCrv_FAtEnd(void *arg0) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($s0) */);
        var_v1 = 1;
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) <= M2C_FIELD(arg0, f32 *, 0x64))) {
            var_v1 = 0;
        }
        var_v0 = var_v1;
    }
    return var_v0;
}
