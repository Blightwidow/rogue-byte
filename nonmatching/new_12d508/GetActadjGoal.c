#include "m2c_macros.h"

s32 func_0012CF28(void *, void *);                  /* extern */

s32 GetActadjGoal(void *arg0) {
    void *temp_a1;
    void *temp_v0;

    temp_a1 = M2C_FIELD(arg0, void **, 0x1C);
    if (temp_a1 != NULL) {
        temp_v0 = M2C_FIELD(temp_a1, void **, 0x18);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x24)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x20), temp_a1);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc0($v0) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xc0($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($v1) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xe0($v1) */);
        return M2C_FIELD(arg0, s32 *, 8);
    }
    return func_0012CF28(arg0, temp_a1);
}
