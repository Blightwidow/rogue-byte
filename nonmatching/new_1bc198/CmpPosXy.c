#include "m2c_macros.h"

s32 CmpPosXy(s32 arg0, s32 arg1) {
    f32 temp_v0;
    f32 temp_v0_2;
    s32 var_v0;

    var_v0 = -1;
    if (!(M2C_BITWISE(f32, arg0) < M2C_BITWISE(f32, arg1))) {
        var_v0 = 1;
        if (!(M2C_BITWISE(f32, arg1) < M2C_BITWISE(f32, arg0))) {
            temp_v0 = M2C_ERROR(/* unknown instruction: prot3w $v0, $a0 */);
            temp_v0_2 = M2C_ERROR(/* unknown instruction: prot3w $v0, $a1 */);
            var_v0 = -1;
            if (!(temp_v0 < temp_v0_2)) {
                var_v0 = 1;
                if (!(temp_v0_2 < temp_v0)) {
                    return 0;
                }
            }
        }
    }
    return var_v0;
}
