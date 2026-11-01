#include "m2c_macros.h"

M2C_UNK SetLoPosMatFromXf();                        /* extern */
M2C_UNK func_0022D148(s128 *, s32, M2C_UNK);        /* extern */

void func_001F4A80(void *arg0, s32 arg1) {
    s128 sp40;
    void *temp_v0;
    void *temp_v0_2;

    SetLoPosMatFromXf();
    if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
        func_0022D148(&sp40, arg1, 0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_ERROR(/* unknown instruction: pextlw $s0, $v1, $s0 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($s2) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf1z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf2, $vf0w */);
        sp40 = M2C_ERROR(/* unknown instruction: pcpyld $s0, $v1, $s0 */);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf6 */));
        temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK), 0x124)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x120), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */));
    }
}
