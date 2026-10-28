#include "m2c_macros.h"

M2C_UNK GoalIdle_SetState(M2C_UNK);                 /* extern */
M2C_UNK Goal_Deactivate(void *);                    /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */

void GoalIdle_Deactivate(void *arg0) {
    GoalIdle_SetState(-1);
    Goal_Deactivate(arg0);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x1E);
}
