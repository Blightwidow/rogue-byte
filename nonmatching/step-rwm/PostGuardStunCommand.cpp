#include "m2c_macros.h"
extern "C" {

M2C_UNK GoalBrain_SetCommand(s32, void *, s32, s32); /* extern */
s32 func_00205458(M2C_UNK);                         /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void PostGuardStunCommand(s32 arg1) {
    char sp[0x70];
    s32 temp_s0;

    temp_s0 = func_00205458(0x9C);
    memset(sp, 0, 0x70);
    GoalBrain_SetCommand(temp_s0, sp, 6, arg1);
}
}
