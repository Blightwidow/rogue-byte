#include "m2c_macros.h"

s32 FCheckLm__FP2LMf(void *, M2C_UNK);              /* extern */
M2C_UNK PosLoWorld();                               /* extern */

s32 FHitFxSensorReaches(void *arg0, void *arg1) {
    s32 var_v0;
    s32 var_v1;
    void *temp_s0;

    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        temp_s0 = M2C_FIELD(arg1, void **, 0x14);
        var_v0 = 0;
        if (M2C_FIELD(temp_s0, s32 *, 0x50) == 0) {
            PosLoWorld();
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
            if (FCheckLm__FP2LMf(temp_s0 + 0x58, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */)) != 0) {
                var_v1 = 1;
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < M2C_FIELD(temp_s0, f32 *, 0x54))) {
                    var_v1 = 0;
                }
                var_v0 = 1;
                if (var_v1 == 0) {
                    goto block_6;
                }
            } else {
                goto block_6;
            }
        }
    } else {
block_6:
        var_v0 = 0;
    }
    return var_v0;
}
