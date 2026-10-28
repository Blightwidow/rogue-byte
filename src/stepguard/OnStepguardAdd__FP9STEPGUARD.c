#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK SubscribeLoObject(s32, void *);             /* extern */

void OnStepguardAdd__FP9STEPGUARD(void *arg0) {
    s32 temp_a0;

    PostLoLoad();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0xEC);
    if (temp_a0 != 0) {
        SubscribeLoObject(temp_a0, arg0);
    }
}
