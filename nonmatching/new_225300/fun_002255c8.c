#include "m2c_macros.h"

M2C_UNK AccelSoTowardPosSpring(void *, M2C_UNK, M2C_UNK *, s128); /* extern */
M2C_UNK AddSoAcceleration(void *, M2C_UNK);         /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
extern M2C_UNK D_002C43D0;
extern s128 g_2a2dd0;

void func_002255C8(void *arg0, void *arg1) {
    void *temp_s0;
    void *var_a0;

    temp_s0 = M2C_FIELD(arg1, void **, 4);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($v0) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    AddSoAcceleration(temp_s0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
    var_a0 = M2C_FIELD(arg0, void **, 0x1B0);
    if (var_a0 == NULL) {
        var_a0 = arg0;
    }
    PosLoWorld(var_a0);
    AccelSoTowardPosSpring(temp_s0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), &D_002C43D0, g_2a2dd0);
}
