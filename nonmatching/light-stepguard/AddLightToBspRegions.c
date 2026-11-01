#include "m2c_macros.h"

M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */

void AddLightToBspRegions(void *arg0, void *arg1, s128 arg2, s32 arg3, f32 fparg0) {
    char sp[0x400];
    M2C_UNK sp10;
    s128 sp20;
    s128 sp30;
    f32 temp_v0;
    s32 *temp_a0;
    s32 *temp_a0_2;
    void *temp_a1;
    void *temp_a1_2;

    sp20 = arg2;
    sp30 = M2C_FIELD(arg1, s128 *, 0);
    func_002564B8(sp);
    func_002564B8(&sp10);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf4 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf1, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmsubw.x $vf2, $vf1, $vf3w */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    if (temp_v0 < fparg0) {
        temp_a1 = M2C_FIELD(arg1, void **, 0x10);
        if (temp_a1 != NULL) {
            AddLightToBspRegions(arg0, temp_a1, sp20, arg3, fparg0);
        } else {
            temp_a0 = (M2C_FIELD(arg1, s32 *, 0x18) << 5) + M2C_FIELD(arg0, s32 *, 0x4564) + (((s32) ((arg3 > -1) ? arg3 : (arg3 + 0x1F)) >> 5) * 4);
            *temp_a0 |= 1 << arg3;
        }
    }
    if (-fparg0 < temp_v0) {
        temp_a1_2 = M2C_FIELD(arg1, void **, 0x14);
        if (temp_a1_2 != NULL) {
            AddLightToBspRegions(arg0, temp_a1_2, sp20, arg3, fparg0);
            return;
        }
        temp_a0_2 = (M2C_FIELD(arg1, s32 *, 0x1C) << 5) + M2C_FIELD(arg0, s32 *, 0x4564) + (((s32) ((arg3 > -1) ? arg3 : (arg3 + 0x1F)) >> 5) * 4);
        *temp_a0_2 |= 1 << arg3;
    }
}
