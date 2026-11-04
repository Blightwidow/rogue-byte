#include "m2c_macros.h"

M2C_UNK FillCrvcCache(void *, s32);                 /* extern */
M2C_UNK InvalidateCrvCache();                       /* extern */
M2C_UNK RemeasureRopeSim(s32, s32);                 /* extern */

void MeasureCrv(void *arg0) {
    f32 var_f1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s1;
    void *temp_v0;
    void *temp_v1;
    void *temp_v1_3;
    void *var_a1;

    InvalidateCrvCache();
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    temp_v0 = M2C_FIELD(temp_v1, void *(**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
    var_a1 = M2C_FIELD(arg0, void **, 0xE0);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x100($s0) */);
    M2C_FIELD(arg0, s128 *, 0x110) = (s128) M2C_FIELD(temp_v0, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x120) = (s128) M2C_FIELD(temp_v0, s128 *, 0x20);
    M2C_FIELD(arg0, s128 *, 0x130) = (s128) M2C_FIELD(temp_v0, s128 *, 0x30);
    if (var_a1 == NULL) {
        var_a2 = 1;
        var_f1 = 0.0f;
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($a0) */);
        *M2C_FIELD(arg0, M2C_UNK32 **, 0xF0) = 0;
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf4z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf1, $vf0w */);
        var_a1 = arg0 + 0x100;
        if (M2C_FIELD(arg0, s32 *, 0xE8) > 1) {
            do {
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($a1) */);
                temp_a0 = var_a2 * 4;
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($a1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
                var_a2 += 1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x100($s0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($a1) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf4y */);
                M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf4z */);
                M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf1, $vf0w */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf6, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: vmove.xyzw $vf6, $vf3 */);
                var_f1 += M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                *(temp_a0 + M2C_FIELD(arg0, M2C_UNK32 **, 0xF0)) = var_f1;
            } while (var_a2 < M2C_FIELD(arg0, s32 *, 0xE8));
        }
    } else {
        *M2C_FIELD(arg0, M2C_UNK32 **, 0xF0) = 0;
        var_s1 = 0;
        if ((M2C_FIELD(arg0, s32 *, 0xE8) - 1) > 0) {
            var_a1 = NULL;
            do {
                FillCrvcCache(arg0, (s32) var_a1);
                temp_v1_2 = var_s1 * 4;
                var_s1 += 1;
                temp_v1_3 = temp_v1_2 + M2C_FIELD(arg0, M2C_UNK32 **, 0xF0);
                M2C_FIELD(temp_v1_3, f32 *, 4) = (f32) (M2C_FIELD(temp_v1_3, f32 *, 0) + M2C_FIELD(arg0, f32 *, 0x174));
                var_a1 = (void *) var_s1;
            } while (var_s1 < (M2C_FIELD(arg0, s32 *, 0xE8) - 1));
        }
    }
    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x17C);
    if (temp_a0_2 != 0) {
        RemeasureRopeSim(temp_a0_2, (s32) var_a1);
    }
}
