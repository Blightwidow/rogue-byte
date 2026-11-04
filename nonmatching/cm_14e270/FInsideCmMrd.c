#include "m2c_macros.h"

s32 FInsideCmMrd(void *arg0, f32 *arg2, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_v0;
    f32 var_f0;

    temp_f1 = M2C_FIELD(arg0, f32 *, 0x1C);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    temp_f12 = fparg0 * temp_f1;
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    temp_f2 = temp_f12 * temp_f12;
    if (!(temp_f2 < temp_v0)) {
        temp_f0 = temp_f12 - (temp_f1 * 400.0f);
        temp_f0_2 = temp_f0 * temp_f0;
        if (temp_f0_2 < temp_v0) {
            var_f0 = (temp_f2 - temp_v0) / (temp_f2 - temp_f0_2);
        } else {
            var_f0 = 1.0f;
        }
        *arg2 = var_f0;
        return 1;
    }
    return 0;
}
