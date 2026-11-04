#include "m2c_macros.h"

s128 VelocityXfAtPos(s32, M2C_UNK, M2C_UNK);        /* extern */
extern s128 g_2a2dd0;

s128 GetXfmVelocity(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_v1 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x90($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf5z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf4, $vf0w */);
        return VelocityXfAtPos(temp_v1, 0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf6 */));
    }
    return g_2a2dd0;
}
