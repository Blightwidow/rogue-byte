#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(M2C_UNK, M2C_UNK, M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK RemoveSoLoHierarchy();                      /* extern */

void func_001B0C68(s32 arg0) {
    RemoveSoLoHierarchy();
    ApplyAsegToHandle(0, 0, 0, arg0 + 0x1C4, 0, 0);
}
