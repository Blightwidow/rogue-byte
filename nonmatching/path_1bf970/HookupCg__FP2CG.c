#include "m2c_macros.h"

void HookupCg__FP2CG(void *arg0) {
    s32 temp_a0;
    s32 var_a1;
    s32 var_a1_2;
    void *temp_a2;

    var_a1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0) > 0) {
loop_2:
        temp_a2 = M2C_FIELD(arg0, s32 *, 4) + (var_a1 << 5);
        var_a1_2 = 0;
        if (M2C_FIELD(temp_a2, s32 *, 0x10) > 0) {
loop_4:
            temp_a0 = var_a1_2 * 8;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a2) */);
            var_a1_2 += 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_FIELD((M2C_FIELD(temp_a2, s32 *, 0x14) + temp_a0), s32 *, 4) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            if (var_a1_2 < M2C_FIELD(temp_a2, s32 *, 0x10)) {
                goto loop_4;
            }
        }
        var_a1 += 1;
        if (var_a1 < M2C_FIELD(arg0, s32 *, 0)) {
            goto loop_2;
        }
    }
}
