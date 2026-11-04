#include "m2c_macros.h"

M2C_UNK PosLoWorld();                    /* extern */

s32 NCompareHitfxForGuard(s32 arg0, void *arg1, void *arg2) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_v0;
    f32 temp_v0_2;
    s32 var_v0;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg1, void **, 0x14);
    var_v0 = M2C_FIELD(temp_a1, s32 *, 0x50) - M2C_FIELD(M2C_FIELD(arg2, void **, 0x14), s32 *, 0x50);
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(arg2, s32 *, 0x54) - M2C_FIELD(arg1, s32 *, 0x54);
        if (var_v0 == 0) {
            temp_f1 = M2C_FIELD(arg1, f32 *, 0x4C);
            temp_f0 = M2C_FIELD(arg2, f32 *, 0x4C);
            var_v0 = -1;
            if (!(temp_f0 < temp_f1)) {
                var_v0 = 1;
                if (!(temp_f1 < temp_f0)) {
                    PosLoWorld(arg0, temp_a1);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s1) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                    PosLoWorld(arg0);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s0) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                    temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                    var_v0 = -1;
                    if (!(temp_v0 < temp_v0_2)) {
                        if (temp_v0 < temp_v0_2) {
                            return 1;
                        }
                        var_v0 = (s32) ((arg1 - arg2) * 0xAAAAAAAB) >> 5;
                        /* Duplicate return node #9. Try simplifying control flow for better match */
                        return var_v0;
                    }
                }
            }
        }
    }
    return var_v0;
}
