#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */

void *func_001C4AF8(void *arg0, s128 arg1) {
    f32 temp_v0;
    f32 var_f20;
    s32 var_s4;
    void **var_s1;
    void *temp_s0;
    void *var_s2;

    var_s2 = NULL;
    var_s4 = 0;
    var_f20 = 3.4028235e38f;
    if (M2C_FIELD(arg0, s32 *, 0x3EB8) > 0) {
        var_s1 = arg0 + 0x3EBC;
        do {
            temp_s0 = *var_s1;
            if (!(((u64) M2C_FIELD(temp_s0, u64 *, 0x28) >> 0x3C) & 1)) {

            } else {
                PosLoWorld(temp_s0);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                if (temp_v0 < var_f20) {
                    var_f20 = temp_v0;
                    var_s2 = temp_s0;
                }
            }
            var_s4 += 1;
            var_s1 += 4;
        } while (var_s4 < M2C_FIELD(arg0, s32 *, 0x3EB8));
    }
    return var_s2;
}
