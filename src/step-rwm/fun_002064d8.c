#include "m2c_macros.h"

M2C_UNK GoalStack_Clear(s32);                       /* extern */
M2C_UNK RemoveSoLoHierarchy();                      /* extern */
M2C_UNK RetractAsegaHandle(s32);                    /* extern */
M2C_UNK func_00208540(s32, M2C_UNK);                /* extern */

void func_002064D8(s32 arg0) {
    RemoveSoLoHierarchy();
    func_00208540(arg0, 0);
    GoalStack_Clear(arg0 + 0x26C);
    RetractAsegaHandle(arg0 + 0x34C);
}
