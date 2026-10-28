#include "m2c_macros.h"

M2C_UNK func_001A6CA8(void *, s32);                     /* extern */

void AddGuardBusyGoal(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xFFC) == 0) {
        func_001A6CA8(arg0, 1);
    }
    M2C_FIELD(arg0, s32 *, 0xFFC) = (s32) (M2C_FIELD(arg0, s32 *, 0xFFC) + 1);
}
