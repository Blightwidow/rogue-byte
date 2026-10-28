#include "m2c_macros.h"

M2C_UNK StaticInitMemory(M2C_UNK, M2C_UNK);         /* extern */

void StaticInitMemory_thunk(void) {
    StaticInitMemory(1, 0xFFFF);
}
