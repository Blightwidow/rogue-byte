#include "m2c_macros.h"

void *PstageStgSwitchCur(M2C_UNK *);                /* extern */

void SetStgSwitchStageHits(void *arg0, s32 arg1) {
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x15C) != -1) {
        temp_v0 = PstageStgSwitchCur("LOOP");
        if ((temp_v0 != NULL) && (arg1 != 0)) {
            M2C_FIELD(temp_v0, s32 *, 4) = arg1;
        }
    }
}
