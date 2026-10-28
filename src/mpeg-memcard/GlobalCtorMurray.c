#include "m2c_macros.h"

M2C_UNK StaticInitMurray(M2C_UNK, M2C_UNK);         /* extern */

void GlobalCtorMurray(void) {
    StaticInitMurray(1, 0xFFFF);
}
