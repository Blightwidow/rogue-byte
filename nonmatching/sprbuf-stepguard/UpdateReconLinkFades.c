#include "m2c_macros.h"

M2C_UNK FadeAloIn(void *, M2C_UNK);                 /* extern */
M2C_UNK FadeAloOut(void *, M2C_UNK);                /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */

void UpdateReconLinkFades(void *arg0) {
    f32 temp_f0;
    f32 temp_v0;
    s32 var_s2;
    void **var_s1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x30) > 0) {
        var_s1 = arg0 + 0x34;
        do {
            temp_s0 = *var_s1;
            if (M2C_FIELD(temp_s0, void **, 0x100) != NULL) {
                PosLoWorld(temp_s0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                temp_f0 = M2C_FIELD(temp_s0, f32 *, 0x104);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s4) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf2, $vf2, $vf2 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf2, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                if ((temp_f0 < temp_v0) && (temp_a0 = M2C_FIELD(temp_s0, void **, 0x100), ((((u64) M2C_FIELD(temp_a0, u64 *, 0x28) >> 0x3C) & 1) == 0))) {
                    FadeAloIn(temp_a0, 0x3E800000);
                } else if (temp_v0 <= temp_f0) {
                    temp_a0_2 = M2C_FIELD(temp_s0, void **, 0x100);
                    if (((u64) M2C_FIELD(temp_a0_2, u64 *, 0x28) >> 0x3C) & 1) {
                        FadeAloOut(temp_a0_2, 0x3E800000);
                    }
                }
            }
            var_s2 += 1;
            var_s1 += 4;
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x30));
    }
}
