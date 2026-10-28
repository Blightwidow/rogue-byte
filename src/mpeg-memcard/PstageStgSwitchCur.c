#include "m2c_macros.h"

s32 FStgSwitchInStageRange();                       /* extern */

s32 PstageStgSwitchCur(void *arg0) {
    if (FStgSwitchInStageRange() == 0) {
        return 0;
    }
    return M2C_FIELD(arg0, s32 *, 0x164) + (M2C_FIELD(arg0, s32 *, 0x15C) * 0x10);
}
