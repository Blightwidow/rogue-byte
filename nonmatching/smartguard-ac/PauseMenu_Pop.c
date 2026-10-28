#include "m2c_macros.h"

M2C_UNK PauseMenu_SetState(M2C_UNK);                /* extern */
s32 func_001B0108(void *);                          /* extern */

void PauseMenu_Pop(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x1E8) == 7) {
        PauseMenu_SetState(2);
        if (func_001B0108(arg0) != 0) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0x24) - 1;
            M2C_FIELD(arg0, s32 *, 0x24) = temp_v0;
            M2C_FIELD(arg0, s32 *, 0x1EC) = temp_v0;
        }
    }
}
