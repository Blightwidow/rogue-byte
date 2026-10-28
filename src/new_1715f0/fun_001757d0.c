#include "m2c_macros.h"

M2C_UNK GoalNotice_SetState(void *, M2C_UNK);       /* extern */
M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */

void func_001757D0(void *arg0) {
    Goal_Deactivate();
    GoalNotice_SetState(arg0, -1);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x1D);
}
