#include "m2c_macros.h"

s32 FInScreenBox(s32 arg0, f32 fparg0) {
    f32 temp_f1;
    f32 temp_v1;
    s32 var_v0;

    var_v0 = 0;
    if (M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $a0 */) > 0.0001f) {
        temp_f1 = -fparg0;
        if ((temp_f1 < M2C_BITWISE(f32, arg0)) && (M2C_BITWISE(f32, arg0) < fparg0)) {
            temp_v1 = M2C_ERROR(/* unknown instruction: prot3w $v1, $a0 */);
            if ((temp_f1 < temp_v1) && (temp_v1 < fparg0)) {
                var_v0 = 1;
            }
        }
    }
    return var_v0;
}
