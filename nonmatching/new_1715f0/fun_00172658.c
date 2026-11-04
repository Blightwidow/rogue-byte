#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK func_00172760(void *);                      /* extern */

s32 func_00172658(void *arg0) {
    s32 var_v0;
    void *temp_a0;
    void *temp_a0_2;

    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    if (M2C_FIELD(temp_a0, s32 *, 0xFE8) & 2) {
        if (M2C_FIELD(temp_a0, s32 *, 0xE78) != 2) {
            temp_a0_2 = M2C_FIELD(temp_a0, void **, 0xE74);
            var_v0 = 0;
            if (temp_a0_2 != NULL) {
                PosLoWorld(temp_a0_2);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                func_00172760(arg0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                var_v0 = 1;
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) + 50.0f))) {
                    var_v0 = 0;
                }
            }
        } else {
            goto block_4;
        }
    } else {
block_4:
        var_v0 = 1;
    }
    return var_v0;
}
