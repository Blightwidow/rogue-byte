#include "m2c_macros.h"

s32 FStgSwitchInStageRange();                       /* extern */

s32 FStgSwitchDone(void) {
    return FStgSwitchInStageRange() == 0;
}
