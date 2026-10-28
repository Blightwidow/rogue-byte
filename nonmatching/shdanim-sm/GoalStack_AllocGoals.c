#include "m2c_macros.h"

s32 CbGoalMax();                                    /* extern */
s32 PvAllocSwImpl__Fi(void *, s32, s32);            /* extern */

void GoalStack_AllocGoals(s32 arg0) {
    char sp[0x400];
    s32 *var_s0;
    u32 var_s1;

    var_s0 = arg0 + 8;
    var_s1 = 0;
    do {
        var_s1 += 1;
        *var_s0 = PvAllocSwImpl__Fi(sp, CbGoalMax(), 0x10);
        var_s0 += 4;
    } while (var_s1 < 8U);
}
