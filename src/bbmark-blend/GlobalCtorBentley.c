#include "m2c_macros.h"

M2C_UNK StaticInitBentley(M2C_UNK, M2C_UNK);        /* extern */

void GlobalCtorBentley(void) {
    StaticInitBentley(1, 0xFFFF);
}
