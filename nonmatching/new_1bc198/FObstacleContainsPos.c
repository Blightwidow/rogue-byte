#include "m2c_macros.h"

M2C_UNK Obstacle_UpdatePlanes();                    /* extern */
M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */

s32 FObstacleContainsPos(void *arg0, s128 arg1) {
    char sp[0x400];
    M2C_UNK sp10;
    s128 sp20;
    s32 var_s0;
    s32 var_v0;

    var_s0 = 0;
    sp20 = arg1;
    Obstacle_UpdatePlanes();
    if ((M2C_FIELD(arg0, s32 *, 0xE8) - 1) > 0) {
loop_2:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
        func_002564B8(sp);
        func_002564B8(&sp10);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vmsubw.x $vf1, $vf2, $vf1w */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        var_v0 = 0;
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) > 0.0f)) {
            var_s0 += 1;
            if (var_s0 < (M2C_FIELD(arg0, s32 *, 0xE8) - 1)) {
                goto loop_2;
            }
            goto block_6;
        }
    } else {
block_6:
        var_v0 = 1;
    }
    return var_v0;
}
