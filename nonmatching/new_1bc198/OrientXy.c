#include "m2c_macros.h"

extern f32 D_FLT_002C0AB0;

s32 OrientXy(s32 arg0, s32 arg1, s32 arg2) {
    f32 temp_f0;
    f32 temp_v0;
    s32 var_v0;

    temp_v0 = M2C_ERROR(/* unknown instruction: prot3w $v0, $a1 */);
    temp_f0 = ((M2C_BITWISE(f32, arg0) - M2C_BITWISE(f32, arg1)) * (temp_v0 - M2C_ERROR(/* unknown instruction: prot3w $v0, $a2 */))) - ((M2C_ERROR(/* unknown instruction: prot3w $v0, $a0 */) - temp_v0) * (M2C_BITWISE(f32, arg1) - M2C_BITWISE(f32, arg2)));
    var_v0 = -1;
    if (!(temp_f0 < -D_FLT_002C0AB0)) {
        var_v0 = 1;
        if (!(D_FLT_002C0AB0 < temp_f0)) {
            return 0;
        }
    }
    return var_v0;
}
