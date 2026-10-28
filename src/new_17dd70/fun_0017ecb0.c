#include "m2c_macros.h"

s32 GoalGoto_FArrived(s32);                         /* extern */
M2C_UNK func_0017ECF0(void *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF98();                            /* extern */

void func_0017ECB0(void *arg0) {
    func_001EEF98();
    if (GoalGoto_FArrived(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
        func_0017ECF0(arg0, 0);
    }
}
