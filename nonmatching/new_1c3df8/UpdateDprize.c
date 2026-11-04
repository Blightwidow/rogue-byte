#include "m2c_macros.h"

M2C_UNK CheckDprizeBounce();         /* extern */
M2C_UNK CheckDprizeCollect();                 /* extern */
M2C_UNK UpdateSo();                                 /* extern */
M2C_UNK func_001C6308();                      /* extern */
extern f32 D_FLT_002C0D50;
extern f32 g_2dded0;

void UpdateDprize(void *arg0) {
    M2C_UNK var_a1;
    u32 temp_v1;
    void *temp_v0;

    UpdateSo();
    func_001C6308(arg0);
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x150);
    switch (temp_v1) {
    case 0:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x180($s0) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) > 10000.0f) {
            CheckDprizeBounce(arg0);
        }
        /* fallthrough */
    case 5:
        CheckDprizeCollect(arg0);
        return;
    case 3:
        var_a1 = 4;
        if (M2C_FIELD(arg0, f32 *, 0x188) < 0.0f) {
block_11:
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), var_a1);
            return;
        }
    default:
        return;
    case 4:
        if (M2C_FIELD(arg0, s32 *, 0x1C4) != 0) {
            var_a1 = 0;
            if (M2C_FIELD(arg0, f32 *, 0x188) < 25.0f) {
                M2C_FIELD(arg0, s32 *, 0x1C4) = 0;
                goto block_11;
            }
        }
        var_a1 = 2;
        if (D_FLT_002C0D50 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x154))) {
            goto block_11;
        }
        CheckDprizeBounce(arg0, 2);
        CheckDprizeCollect(arg0);
        break;
    }
}
