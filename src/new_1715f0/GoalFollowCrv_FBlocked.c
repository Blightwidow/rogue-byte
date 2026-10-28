#include "m2c_macros.h"

s32 GoalFollowCrv_FBlocked(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x4C) == 3;
}
