#include "m2c_macros.h"

M2C_UNK GoalBrain_SetCommand(s32, void *);          /* extern */
s32 func_00205458(void *, M2C_UNK, s32);            /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void func_001BA980(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_v0;

    memset(arg0 + 0x1090, 0, 0xC);
    M2C_FIELD(arg0, s32 *, 0x108C) = arg1;
    memset(sp, 0, 0x70);
    temp_v0 = func_00205458(arg0, 0x9C, 0xF);
    if (temp_v0 != 0) {
        GoalBrain_SetCommand(temp_v0, sp);
    }
}
