#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK StepHubState(s32, M2C_UNK);                 /* extern */
M2C_UNK func_002013D8(void *, M2C_UNK, M2C_UNK);    /* extern */

void SetHubAllowedStates(s32 arg0) {
    char sp[0x400];
    func_002013D8(sp, 6, 6);
    CRef_Destruct(sp);
    StepHubState(arg0, 0);
}
