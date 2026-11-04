#include "m2c_macros.h"

s32 ClsgClipEdgeToObstacle(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 FObstacleContainsPos(void *, M2C_UNK);          /* extern */

s32 func_001BD8A8(void *arg0, void *arg1) {
    M2C_UNK sp40;
    s32 var_s1;
    void *temp_v1;
    void *temp_v1_2;

    var_s1 = 1;
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf1, $vf2, $vf0w */);
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 1) {
loop_1:
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf3z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf1, $vf1, $vf0w */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
        if (ClsgClipEdgeToObstacle(arg1, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */), 1) == 0) {
            var_s1 += 1;
            if (var_s1 < M2C_FIELD(arg0, s32 *, 0xE8)) {
                goto loop_1;
            }
        }
        if (var_s1 < M2C_FIELD(arg0, s32 *, 0xE8)) {
            return 1;
        }
        goto block_6;
    }
block_6:
    temp_v1_2 = M2C_FIELD(arg1, void **, 0xC);
    M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0xFC)(arg1 + M2C_FIELD(temp_v1_2, s16 *, 0xF8));
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf4z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf5, $vf0w */);
    return FObstacleContainsPos(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf6 */)) != 0;
}
