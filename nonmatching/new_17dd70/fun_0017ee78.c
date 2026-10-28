#include "m2c_macros.h"

s32 GoalGoto_FArrived(s32);                         /* extern */
s32 func_0017EEB8();                                /* extern */

s32 func_0017EE78(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (func_0017EEB8() != 0) {
        var_v0 = GoalGoto_FArrived(M2C_FIELD(arg0, s32 *, 0x18));
    }
    return var_v0;
}
