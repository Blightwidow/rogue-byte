#include "m2c_macros.h"

M2C_UNK DetonateBomb(void *);                       /* extern */
M2C_UNK UpdateBombCustomXps(void *);                /* extern */
M2C_UNK UpdateSo();                                 /* extern */
extern f32 g_2dded0;

void UpdateBomb__FP4BOMBf(void *arg0) {
    s32 var_v0;
    void *temp_v1;

    UpdateSo();
    if (!(M2C_FIELD(arg0, f32 *, 0x154) <= g_2dded0)) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        var_v0 = 1;
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < M2C_FIELD(arg0, f32 *, 0x158))) {
            var_v0 = 0;
        }
        if (var_v0 == 0) {
            if (M2C_FIELD(arg0, s32 *, 0x1F4) != 0) {
                UpdateBombCustomXps(arg0);
            }
            return;
        }
        goto block_6;
    }
block_6:
    DetonateBomb(arg0);
}
