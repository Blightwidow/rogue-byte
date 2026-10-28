#include "m2c_macros.h"

void GetActadjPositionGoal(void *arg0, s32 arg1) {
    void *temp_a3;
    void *temp_v0;

    temp_a3 = M2C_FIELD(arg0, void **, 0x1C);
    temp_v0 = M2C_FIELD(temp_a3, void **, 0x18);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x2C)(temp_a3 + M2C_FIELD(temp_v0, s16 *, 0x28), temp_a3);
    if (arg1 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s0) */);
    }
}
