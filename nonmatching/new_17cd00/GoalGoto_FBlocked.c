#include "m2c_macros.h"

s32 GoalFollowCrv_FBlocked(s32);                    /* extern */

s32 GoalGoto_FBlocked(void *arg0) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x30);
    var_v0 = 0;
    if (temp_v1 < 3) {
        if (temp_v1 > 0) {
            var_v0 = GoalFollowCrv_FBlocked(M2C_FIELD(arg0, s32 *, 0x18));
        }
    }
    return var_v0;
}
