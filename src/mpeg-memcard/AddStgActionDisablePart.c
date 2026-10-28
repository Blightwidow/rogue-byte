#include "m2c_macros.h"

s32 FStgSwitchInStageRange();                       /* extern */
void *PactAddStgAction(s32, M2C_UNK);               /* extern */
M2C_UNK func_001F6B48(s32, s32);                    /* extern */

void AddStgActionDisablePart(s32 arg0, s32 arg1) {
    if (FStgSwitchInStageRange() == 0) {
        func_001F6B48(arg0, arg1);
        return;
    }
    M2C_FIELD(PactAddStgAction(arg0, 5), s32 *, 4) = arg1;
}
