#include "m2c_macros.h"

s128 PosLoWorld();                            /* extern */
M2C_UNK SetSlotSoHeading();              /* extern */
f32 atan2f();                               /* extern */
void *func_001C4AF8();            /* extern */
extern M2C_UNK B_003DD490;

s32 SenseSlotSoTargetState(void *arg0) {
    M2C_UNK sp0;
    M2C_UNK sp4;
    s128 sp10;
    f32 temp_v0_2;
    s32 temp_s2;
    s32 var_v0;
    void *temp_v0;
    void *temp_v1;

    temp_s2 = M2C_FIELD(arg0, s32 *, 0x220);
    sp10 = PosLoWorld();
    temp_v0 = func_001C4AF8(&B_003DD490, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    var_v0 = temp_s2;
    if (temp_v0 != NULL) {
        PosLoWorld(temp_v0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
        temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
        var_v0 = temp_s2;
        if (!(M2C_FIELD(arg0, f32 *, 0x154) < temp_v0_2)) {
            if (M2C_FIELD(arg0, f32 *, 0x150) < temp_v0_2) {
                temp_v1 = M2C_FIELD(temp_v0, void **, 0xC);
                M2C_FIELD(temp_v1, M2C_UNK (**)(void *, f32), 0x10C)(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x108), sp4);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                var_v0 = temp_s2;
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 150.0f)) {
                    goto block_5;
                }
            } else {
block_5:
                SetSlotSoHeading(arg0, atan2f(sp4, sp0));
                var_v0 = 3;
            }
        }
    }
    return var_v0;
}
