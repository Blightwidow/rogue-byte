#include "m2c_macros.h"

M2C_UNK AdjustJtZapNewXp(void *, void *, s32);      /* extern */
M2C_UNK AdjustStepNewXp();                          /* extern */
M2C_UNK func_001374E0(void *, void *, s32);         /* extern */
M2C_UNK func_0019E9C8(void *, void *, s32);         /* extern */
extern f32 D_FLT_002BF298;
extern f32 D_FLT_002BF29C;
extern f32 g_2dded0;

void AdjustSlyNewXp(void *arg0, void *arg1, s32 arg2) {
    f32 var_f0;
    s32 temp_v0;

    AdjustStepNewXp();
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x18C8);
    switch (temp_v0) {
    case 8:
        func_0019E9C8(arg0 + 0xF50, arg1, arg2);
        return;
    case 7:
        if ((M2C_FIELD(arg1, s32 *, 0x9C) == 0xE) && (M2C_FIELD(arg0, s32 *, 0x4C8) == 3) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x4D4), s32 *, 0x1BC) != 0)) {
            M2C_FIELD(arg1, s32 *, 0x98) = 0;
            if (M2C_FIELD(arg0, s32 *, 0x4CC) != 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($s1) */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                var_f0 = (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) / M2C_FIELD(arg1, f32 *, 0x88)) + 0.5f;
                if (var_f0 < 0.5f) {
                    var_f0 = 0.5f;
                } else if (var_f0 > 1.5f) {
                    var_f0 = 1.5f;
                }
block_22:
                M2C_FIELD(arg1, f32 *, 0x94) = var_f0;
            } else {
                M2C_FIELD(arg1, f32 *, 0x94) = 0.0f;
                return;
            }
        } else {
        default:
            return;
        }
        break;
    case 4:
        AdjustJtZapNewXp(arg0 + 0xDF0, arg1, arg2);
        return;
    case 6:
        func_001374E0(arg0 + 0x1FF0, arg1, arg2);
        return;
    case 24:
        M2C_FIELD(arg1, s32 *, 0x98) = 0;
        M2C_FIELD(arg1, f32 *, 0x94) = 0.0f;
        return;
    case 5:
        if (((u32) (M2C_FIELD(arg0, s32 *, 0x18D0) - 8) < 2U) && ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x18D4)) < D_FLT_002BF298)) {
            var_f0 = D_FLT_002BF29C;
            goto block_22;
        }
        break;
    }
}
