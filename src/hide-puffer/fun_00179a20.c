#include "m2c_macros.h"

M2C_UNK GoalHit_Deactivate();                       /* extern */
M2C_UNK RecalcSwOxfFilterForObject(M2C_UNK *, s32); /* extern */
extern M2C_UNK B_003DD490;

void func_00179A20(void *arg0) {
    GoalHit_Deactivate();
    RecalcSwOxfFilterForObject(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x10));
}
