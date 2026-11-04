#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK func_001C1EC0(s32, M2C_UNK);                /* extern */

s32 func_001C1FA0(s32 arg0, void *arg1, f32 fparg0) {
    s32 var_v0;

    var_v0 = 1;
    if (FIsBasicDerivedFrom(arg1, 0x40) == 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        func_001C1EC0(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        var_v0 = 1;
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) <= fparg0)) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
