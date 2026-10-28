#include "m2c_macros.h"

M2C_UNK GoalGoto_SetState(void *, M2C_UNK);         /* extern */
M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, s32);                   /* extern */

void GoalGoto_Deactivate(void *arg0) {
    s32 temp_a1;

    Goal_Deactivate();
    GoalGoto_SetState(arg0, -1);
    temp_a1 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_a1 != -1) {
        RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), temp_a1);
    }
}
