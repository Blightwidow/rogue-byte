#include "m2c_macros.h"
extern "C" {

void GoalBrain_SetCommand(s32, s8 *);     /* extern */
M2C_UNK func_001EEF70();                            /* extern */
void *memset(void *, s32, s32);           /* extern */

void GoalBrain_Activate(s32 arg0) {
    s8 sp[0x70] __attribute__((aligned(16)));

    func_001EEF70();
    memset(sp, 0, 0x70);
    *(s32 *)sp = 0;
    GoalBrain_SetCommand(arg0, sp);
}

}
