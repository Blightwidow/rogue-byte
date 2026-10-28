#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(M2C_UNK, s32, M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK RemoveSoLoHierarchy();                      /* extern */
M2C_UNK func_0012E460(s32);                         /* extern */

void func_001B1E38(s32 arg0) {
    RemoveSoLoHierarchy();
    ApplyAsegToHandle(0, arg0, 0, arg0 + 0x234, 0, 0x3F800000);
    func_0012E460(arg0 + 0x268);
}
