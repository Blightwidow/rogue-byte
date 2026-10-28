#include "m2c_macros.h"

M2C_UNK GoalAnim_SetState(void *, M2C_UNK);         /* extern */
M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, s32);                   /* extern */

void func_00174B28(void *arg0) {
    Goal_Deactivate();
    GoalAnim_SetState(arg0, 1);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x3C));
}
