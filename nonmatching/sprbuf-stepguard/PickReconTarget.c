#include "m2c_macros.h"

s32 FInsideCmFrustrum(M2C_UNK *, M2C_UNK, M2C_UNK, s128); /* extern */
s32 FInsideCmMrd(M2C_UNK *, M2C_UNK, M2C_UNK *, f32); /* extern */
s32 FReconTargetPickable(void *);                   /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK ProbeReconTargetVisibility(void *, void *); /* extern */
M2C_UNK bevy_ui_binoc_recon_202768(void *, M2C_UNK); /* extern */
extern M2C_UNK B_002DDF40;

void PickReconTarget(void *arg0) {
    M2C_UNK sp10;
    s128 sp20;
    f32 temp_v0_2;
    f32 var_f21;
    s32 var_s5;
    void **var_s3;
    void *temp_a2;
    void *temp_s0;
    void *temp_v0;
    void *var_s4;

    var_s5 = 0;
    var_s4 = NULL;
    temp_a2 = *M2C_FIELD(arg0, void ***, 0xA8);
    temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s32, void *), 0x30C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x308), arg0 + 0x20, temp_a2);
    var_f21 = 3.4028235e38f;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + 20.0f);
    if (M2C_FIELD(arg0, s32 *, 0x30) > 0) {
        var_s3 = arg0 + 0x34;
        do {
            temp_s0 = *var_s3;
            if (FReconTargetPickable(temp_s0) != 0) {
                sp20 = PosLoWorld(temp_s0);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
                if (FInsideCmFrustrum(&B_002DDF40, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), (s128) M2C_FIELD(temp_s0, s32 *, 0xE0)) != 0) {
                    PosLoWorld(temp_s0);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                    if (FInsideCmMrd(&B_002DDF40, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), &sp10, M2C_FIELD(temp_s0, f32 *, 0x38)) != 0) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s1) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                        if (temp_v0_2 < var_f21) {
                            ProbeReconTargetVisibility(arg0, temp_s0);
                            if (M2C_FIELD(temp_s0, s32 *, 0x108) != 2) {
                                var_s4 = temp_s0;
                                var_f21 = temp_v0_2;
                            }
                        }
                    }
                }
            }
            var_s5 += 1;
            var_s3 += 4;
        } while (var_s5 < M2C_FIELD(arg0, s32 *, 0x30));
    }
    if (var_s4 != M2C_FIELD(arg0, void **, 0x8C)) {
        M2C_FIELD(arg0, void **, 0x8C) = var_s4;
        bevy_ui_binoc_recon_202768(arg0, 2);
    }
}
