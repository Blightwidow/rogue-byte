#include "m2c_macros.h"

M2C_UNK PauseMenu_Close();                          /* extern */
M2C_UNK PauseMenu_SetState(void *, M2C_UNK);        /* extern */

void func_001AE970(void *arg0) {
    PauseMenu_Close();
    PauseMenu_SetState(arg0, 0);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
}
