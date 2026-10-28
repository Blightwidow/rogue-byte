#include "m2c_macros.h"

M2C_UNK GoalBrain_SetCommand(s32, void *, s32);     /* extern */
M2C_UNK func_001EEF70();                            /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void GoalBrain_Activate(s32 arg0) {
    char sp[0x400];
    func_001EEF70();
    memset(sp, 0, 0x70);
    GoalBrain_SetCommand(arg0, sp, 0);
}
