#include "m2c_macros.h"

M2C_UNK StaticInitStgSwitch(M2C_UNK, M2C_UNK);      /* extern */

void GlobalCtorStgSwitch(void) {
    StaticInitStgSwitch(1, 0xFFFF);
}
