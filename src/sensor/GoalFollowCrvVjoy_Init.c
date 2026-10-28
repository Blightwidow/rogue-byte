#include "m2c_macros.h"

M2C_UNK GoalFollowCrv_Init();                       /* extern */

void GoalFollowCrvVjoy_Init(void *arg0) {
    GoalFollowCrv_Init();
    M2C_FIELD(arg0, f32 *, 0xD0) = 1.0f;
}
