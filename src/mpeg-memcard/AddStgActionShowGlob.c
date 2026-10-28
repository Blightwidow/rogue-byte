#include "m2c_macros.h"

s32 FStgSwitchInStageRange();                       /* extern */
void *PactAddStgAction(s32, M2C_UNK);               /* extern */
M2C_UNK func_001F6978(s32, s32);                    /* extern */

void AddStgActionShowGlob(s32 arg0, s32 arg1) {
    if (FStgSwitchInStageRange() == 0) {
        func_001F6978(arg0, arg1);
        return;
    }
    M2C_FIELD(PactAddStgAction(arg0, 2), s32 *, 4) = arg1;
}
