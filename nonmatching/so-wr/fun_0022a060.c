#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, s32);               /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
void *PpoSwFocusBase(M2C_UNK *);                    /* extern */
M2C_UNK UpdateSo();                                 /* extern */
extern M2C_UNK B_003DD490;

void func_0022A060(void *arg0) {
    f32 var_f20;
    s32 temp_v1;
    s32 var_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_2;

    UpdateSo();
    temp_v0 = PpoSwFocusBase(&B_003DD490);
    var_s2 = 0;
    if (temp_v0 != NULL) {
        var_s2 = 0;
        if (FIsBasicDerivedFrom(temp_v0, M2C_FIELD(arg0, s32 *, 0x154)) != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x164) == 0) {
                var_f20 = M2C_FIELD(arg0, f32 *, 0x158);
            } else {
                var_f20 = M2C_FIELD(arg0, f32 *, 0x15C);
            }
            var_s2 = 1;
            PosLoWorld(temp_v0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            PosLoWorld(arg0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < var_f20)) {
                var_s2 = 0;
            }
        }
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    if ((temp_v1 == 0) || (temp_v1 == 2)) {
        var_s2 = (M2C_FIELD(&B_003DD490, s32 *, 0x3B0C) != 0) ? 0 : var_s2;
    }
    if ((var_s2 != 0) && (FIsBasicDerivedFrom(temp_v0, 0x34) != 0) && ((M2C_FIELD(temp_v0, s32 *, 0x2DC) != -1) || (temp_v1_2 = M2C_FIELD(temp_v0, void **, 0xC), (M2C_FIELD(temp_v1_2, s32 (**)(void *), 0x26C)(temp_v0 + M2C_FIELD(temp_v1_2, s16 *, 0x268)) == 2)))) {
        var_s2 = M2C_FIELD(arg0, s32 *, 0x164);
    }
    if (var_s2 != M2C_FIELD(arg0, s32 *, 0x164)) {
        M2C_FIELD(arg0, s32 *, 0x164) = var_s2;
        if (var_s2 != 0) {
            temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x18), 5, 0, 0);
        } else {
            temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x18), 6, 0, 0);
        }
    }
}
