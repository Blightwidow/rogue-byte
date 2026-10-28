#include "m2c_macros.h"

M2C_UNK PaloAbsorbWkr(void *, s32, s32, s32, s32);  /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void GoalBrain_AbsorbDamage(void *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    memset(sp, 0, 0x60);
    PaloAbsorbWkr(sp, arg2, M2C_FIELD(arg0, s32 *, 0x10), 0x40000, arg1);
}
