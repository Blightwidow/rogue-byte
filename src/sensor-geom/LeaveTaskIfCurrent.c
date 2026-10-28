#include "m2c_macros.h"

s32 FIsCurrentTask();                               /* extern */
M2C_UNK LeaveTask(s32);                             /* extern */

void LeaveTaskIfCurrent(s32 arg0) {
    if (FIsCurrentTask() != 0) {
        LeaveTask(arg0);
    }
}
