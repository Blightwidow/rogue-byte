#include "m2c_macros.h"

M2C_UNK FindClosestScriptCmd(s32, M2C_UNK, void *); /* extern */
M2C_UNK GoalIdle_SetState(void *, M2C_UNK);         /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK func_001EEF70();                            /* extern */
s32 func_00209098(void *);                          /* extern */

void GoalIdle_Activate(void *arg0) {
    s32 temp_v0;
    void *temp_a0;
    void *temp_v1;

    func_001EEF70();
    temp_v1 = M2C_FIELD(arg0, void **, 0x10);
    temp_v0 = M2C_FIELD(temp_v1, s32 *, 0x2E8);
    if (temp_v0 == 0) {
        if (!(M2C_FIELD(temp_v1, s32 *, 0xFE8) & 2)) {
            M2C_FIELD(arg0, s32 *, 0x40) = 0;
            GoalIdle_SetState(arg0, 2);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(temp_v1, s32 *, 0x2EC);
        goto block_9;
    }
    M2C_FIELD(arg0, s32 *, 0x40) = temp_v0;
block_9:
    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    if (M2C_FIELD(temp_a0, s32 *, 0x2DC) != 0) {
        PosLoWorld(temp_a0);
        FindClosestScriptCmd(M2C_FIELD(arg0, s32 *, 0x40), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), M2C_FIELD(arg0, void **, 0x10) + 0x2DC);
    }
    if (func_00209098(M2C_FIELD(arg0, void **, 0x10)) != 0) {
        GoalIdle_SetState(arg0, 3);
        return;
    }
    GoalIdle_SetState(arg0, 0);
}
