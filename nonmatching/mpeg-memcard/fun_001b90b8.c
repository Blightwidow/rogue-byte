#include "m2c_macros.h"

M2C_UNK func_00204E38(void *, void *, f32);         /* extern */

s32 func_001B90B8(void *arg0) {
    s32 temp_v1;
    s32 var_v0;
    void *temp_a1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1840);
    var_v0 = 3;
    if ((temp_v1 == 1) || (temp_v1 == 3)) {
        temp_a1 = M2C_FIELD(arg0, void **, 0x1030);
        func_00204E38(arg0, temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C));
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s0) */);
        M2C_FIELD(arg0, f32 *, 0x180) = 1.0f;
    }
    return var_v0;
}
