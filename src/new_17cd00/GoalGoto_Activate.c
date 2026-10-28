#include "m2c_macros.h"

M2C_UNK AddGuardSgs(s32, s32);                      /* extern */
M2C_UNK GoalGoto_Replan(void *);                    /* extern */
M2C_UNK GoalGoto_SetState(void *, M2C_UNK);         /* extern */
M2C_UNK func_001EEF70(void *);                      /* extern */

void GoalGoto_Activate(void *arg0) {
    s32 temp_a1;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_a1 != -1) {
        AddGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), temp_a1);
    }
    func_001EEF70(arg0);
    GoalGoto_SetState(arg0, 4);
    GoalGoto_Replan(arg0);
}
