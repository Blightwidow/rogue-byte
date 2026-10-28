#include "m2c_macros.h"

M2C_UNK ApplyOptionsFromSave(M2C_UNK *);            /* extern */
M2C_UNK PauseMenu_SetState(s32, M2C_UNK);           /* extern */
extern M2C_UNK B_003D4A60;

void PauseMenu_CancelOption(s32 arg0) {
    ApplyOptionsFromSave(&B_003D4A60);
    PauseMenu_SetState(arg0, 9);
}
