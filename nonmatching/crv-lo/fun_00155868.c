#include "m2c_macros.h"

M2C_UNK PosLoWorld(s32);                            /* extern */
extern s32 g_2bdc50;

void *func_00155868(void *arg0) {
    f32 temp_f0;
    f32 var_f20;
    s32 var_s2;
    s32 var_s4;
    void *temp_s0;
    void *var_s3;

    var_s3 = NULL;
    var_s4 = 0;
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0x38));
    var_f20 = -3.4028235e38f;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x1010) > 0) {
        var_s2 = 0;
        do {
            temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x1014) + var_s2;
            if (g_2bdc50 == 0) {
                if (M2C_FIELD(temp_s0, s32 *, 0x20) != 0) {

                } else {
                    goto block_6;
                }
            } else {
block_6:
                PosLoWorld(M2C_FIELD(temp_s0, s32 *, 4));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                PosLoWorld(M2C_FIELD(temp_s0, s32 *, 0x14));
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf2 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                temp_f0 = M2C_ERROR(/* unknown instruction: min.s $f0, $f0, $f1 */);
                if (var_f20 < temp_f0) {
                    var_f20 = temp_f0;
                    var_s3 = temp_s0;
                }
            }
            var_s4 += 1;
            var_s2 += 0x24;
        } while (var_s4 < M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x1010));
    }
    return var_s3;
}
