#include "m2c_macros.h"

s32 VecMaxOfVerts(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    if (var_a0 > 0) {
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
            var_a0 -= 1;
            M2C_ERROR(/* unknown instruction: vmax.xyz $vf2, $vf1, $vf2 */);
        } while (var_a0 != 0);
    }
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
}
