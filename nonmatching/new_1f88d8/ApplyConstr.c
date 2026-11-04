#include "m2c_macros.h"

s32 ApplyConstr(void *arg0) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x10);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf4 */);
    if (temp_v1 != 2) {
        if (temp_v1 < 3) {
            if (temp_v1 != 1) {
                return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf4, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf4, $vf2 */);
            var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
            /* Duplicate return node #8. Try simplifying control flow for better match */
            return var_v0;
        }
        var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
        if (temp_v1 == 3) {
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf0, $vf0 */);
            return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
        }
        return var_v0;
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf1, $vf2x */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
}
