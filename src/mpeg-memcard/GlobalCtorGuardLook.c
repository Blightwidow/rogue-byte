#include "m2c_macros.h"

M2C_UNK StaticInitGuardLook(M2C_UNK, M2C_UNK);      /* extern */

void GlobalCtorGuardLook(void) {
    StaticInitGuardLook(1, 0xFFFF);
}
