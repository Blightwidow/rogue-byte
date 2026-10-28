#include "m2c_macros.h"

M2C_UNK GoalStack_Clear(s32);                       /* extern */
M2C_UNK RemoveSoLoHierarchy();                      /* extern */
M2C_UNK RetractAsegaHandle(s32);                    /* extern */

void func_00141928(s32 arg0) {
    RemoveSoLoHierarchy();
    RetractAsegaHandle(arg0 + 0xEFC);
    RetractAsegaHandle(arg0 + 0xF14);
    GoalStack_Clear(arg0 + 0x26C);
}
