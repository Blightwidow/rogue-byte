#include "m2c_macros.h"

M2C_UNK StaticInitBbmark(M2C_UNK, M2C_UNK);         /* extern */

void GlobalCtorBbmark(void) {
    StaticInitBbmark(1, 0xFFFF);
}
