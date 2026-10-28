#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */
M2C_UNK SetSearchGoal(void *, M2C_UNK);             /* extern */
M2C_UNK SetSearchState(void *, M2C_UNK);            /* extern */

void func_00171FD0(void *arg0) {
    Goal_Deactivate();
    SetSearchState(arg0, -1);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x1F);
    SetSearchGoal(arg0, 0);
}
