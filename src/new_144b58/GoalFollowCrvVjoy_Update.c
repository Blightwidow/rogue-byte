#include "m2c_macros.h"

M2C_UNK GoalFollowCrv_Update();                     /* extern */
M2C_UNK func_001448F0(s32, s128);                   /* extern */

void GoalFollowCrvVjoy_Update(void *arg0) {
    GoalFollowCrv_Update();
    func_001448F0(M2C_FIELD(arg0, s32 *, 0x10) + 0xFD0, M2C_FIELD(arg0, s128 *, 0x80));
}
