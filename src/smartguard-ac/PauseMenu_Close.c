#include "m2c_macros.h"

void PauseMenu_SetState();                /* extern */

void PauseMenu_Close(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x1E8) == 7) {
        if (M2C_FIELD(arg0, s32 *, 0x24) >= 2) {
            M2C_FIELD(arg0, s32 *, 0x24) = 1;
        }
        PauseMenu_SetState(arg0, 8);
    }
}
