#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK StickGadgetObj(void *, s32);                /* extern */
M2C_UNK UpdateSo();                                 /* extern */

void UpdateGadgetObj(void *arg0) {
    s32 var_v0;
    void *temp_v1;

    UpdateSo();
    if ((M2C_FIELD(arg0, s32 *, 0x150) == 1) && (M2C_FIELD(arg0, s32 *, 0x158) != -1)) {
        StickGadgetObj(arg0, M2C_FIELD(arg0, s32 *, 0x1A0));
    }
    if (M2C_FIELD(arg0, void **, 0x16C) != NULL) {
        PosLoWorld(arg0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        PosLoWorld(M2C_FIELD(arg0, void **, 0x16C));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        var_v0 = 1;
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(M2C_FIELD(arg0, f32 *, 0x170) < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            temp_v1 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK), 0x25C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x258), 0);
        }
    }
}
