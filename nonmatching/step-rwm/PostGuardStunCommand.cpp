#include "m2c_macros.h"
extern "C" {

M2C_UNK GoalBrain_SetCommand(s32, void *, f32, s32); /* extern */
s32 func_00205458(void);                         /* extern */
M2C_UNK memset(void *, M2C_UNK);           /* extern */

void PostGuardStunCommand(s32 arg1) {
    char sp[0x70];
    s32 temp_s0;

    temp_s0 = func_00205458();
    memset(sp, 0);
    GoalBrain_SetCommand(temp_s0, sp, 6, arg1);
}
}
