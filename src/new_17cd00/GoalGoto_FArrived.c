#include "m2c_macros.h"

s32 GoalFollowCrv_FAtEnd(s32);                      /* extern */

s32 GoalGoto_FArrived(void *arg0) {
    s32 temp_s0;
    s32 var_v1;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x30);
    var_v1 = 0;
    if (temp_s0 == 1) {
        var_v1 = (GoalFollowCrv_FAtEnd(M2C_FIELD(arg0, s32 *, 0x18)) != 0) ? temp_s0 : 0;
    }
    return var_v1;
}
