#include "m2c_macros.h"

s32 GoalFollowCrv_FAtEnd(void *);                   /* extern */

s32 GoalGotoPos_FArrived(void *arg0) {
    s32 var_v0;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x18);
    if ((GoalFollowCrv_FAtEnd(temp_s0) != 0) || (var_v0 = 0, (M2C_FIELD(temp_s0, s32 *, 0x4C) == 2))) {
        var_v0 = 1;
    }
    return var_v0;
}
