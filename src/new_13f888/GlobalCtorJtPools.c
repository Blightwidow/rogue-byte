#include "m2c_macros.h"

M2C_UNK StaticInitJtPools(M2C_UNK, M2C_UNK);        /* extern */

void GlobalCtorJtPools(void) {
    StaticInitJtPools(1, 0xFFFF);
}
