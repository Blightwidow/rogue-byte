#include "m2c_macros.h"

M2C_UNK StaticInitMenus(M2C_UNK, M2C_UNK);          /* extern */

void StaticInitMenus_thunk(void) {
    StaticInitMenus(1, 0xFFFF);
}
