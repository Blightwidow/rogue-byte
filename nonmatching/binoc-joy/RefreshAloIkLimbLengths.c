#include "m2c_macros.h"

void RefreshAloIkLimbLengths(void *arg0) {
    s32 *var_a3;
    s32 var_a0;
    s32 var_v0;
    void *temp_a0;

    if (M2C_FIELD(arg0, s64 *, 0x148) & (0x8000 << 0x15)) {
        var_a0 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x50) > 0) {
loop_3:
            var_a3 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x54) + (var_a0 << 8)), s32 **, 0x90);
            if (var_a3 != NULL) {
                var_v0 = *var_a3;
loop_5:
                if (var_v0 == 7) {
                    temp_a0 = M2C_FIELD(var_a3, void **, 0x1C);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($v1) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x30($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xb0($a0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($a2) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf3x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf3y */);
                    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf4, $vf3z */);
                    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf6, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($a1) */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                    M2C_FIELD(temp_a0, s32 *, 0xC4) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    M2C_FIELD(temp_a0, s32 *, 0xC0) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                }
                var_a3 = M2C_FIELD(var_a3, s32 **, 0x10);
                if (var_a3 != NULL) {
                    var_v0 = *var_a3;
                    goto loop_5;
                }
            }
            var_a0 += 1;
            if (var_a0 < M2C_FIELD(arg0, s32 *, 0x50)) {
                goto loop_3;
            }
        }
    }
}
