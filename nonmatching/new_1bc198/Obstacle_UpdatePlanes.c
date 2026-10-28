#include "m2c_macros.h"

M2C_UNK InitPlaneFromNormalPos(s32, M2C_UNK, M2C_UNK); /* extern */

void Obstacle_UpdatePlanes(void *arg0) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    void *temp_v0;
    void *temp_v1;

    temp_v0 = M2C_FIELD(arg0, void **, 0x50);
    var_s3 = 0;
    if (temp_v0 != NULL) {
        var_s3 = M2C_FIELD(temp_v0, s32 *, 0xA4);
    }
    var_s1 = 1;
    if (M2C_FIELD(arg0, s32 *, 0x1E8) != var_s3) {
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
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf2, $vf0w */);
        if (M2C_FIELD(arg0, s32 *, 0xE8) > 1) {
            var_s2 = 0;
            do {
                M2C_ERROR(/* unknown instruction: vmove.xyzw $vf2, $vf5 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
                temp_a0 = M2C_FIELD(arg0, s32 *, 0x1EC) + var_s2;
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                var_s1 += 1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf7, ($sp) */);
                var_s2 += 0x10;
                M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf7, $vf5x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf5y */);
                M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
                M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf1, $vf0w */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($s4) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf5, $vf2 */);
                M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf4 */);
                M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf4, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf2, $q */);
                InitPlaneFromNormalPos(temp_a0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */));
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($sp) */);
            } while (var_s1 < M2C_FIELD(arg0, s32 *, 0xE8));
        }
        M2C_FIELD(arg0, s32 *, 0x1E8) = var_s3;
    }
}
