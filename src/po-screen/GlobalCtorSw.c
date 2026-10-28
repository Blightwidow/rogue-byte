#include "m2c_macros.h"

M2C_UNK StaticInitSw(M2C_UNK, M2C_UNK);             /* extern */

void GlobalCtorSw(void) {
    StaticInitSw(1, 0xFFFF);
}
