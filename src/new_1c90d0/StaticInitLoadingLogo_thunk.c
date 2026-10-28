#include "m2c_macros.h"

M2C_UNK StaticInitLoadingLogo(M2C_UNK, M2C_UNK);    /* extern */

void StaticInitLoadingLogo_thunk(void) {
    StaticInitLoadingLogo(1, 0xFFFF);
}
