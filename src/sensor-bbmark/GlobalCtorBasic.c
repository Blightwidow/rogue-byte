#include "m2c_macros.h"

M2C_UNK StaticInitBasic(M2C_UNK, M2C_UNK);          /* extern */

void GlobalCtorBasic(void) {
    StaticInitBasic(1, 0xFFFF);
}
