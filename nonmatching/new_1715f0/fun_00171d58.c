#include "m2c_macros.h"

M2C_UNK GoalBrain_SetCommand(s32, void *, s32);     /* extern */
s32 func_00205458(M2C_UNK);                         /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void func_00171D58(void) {
    char sp[0x400];
    s32 temp_v0;

    temp_v0 = func_00205458(0x9C);
    if (temp_v0 != 0) {
        memset(sp, 0, 0x70);
        GoalBrain_SetCommand(temp_v0, sp, 1);
    }
}
