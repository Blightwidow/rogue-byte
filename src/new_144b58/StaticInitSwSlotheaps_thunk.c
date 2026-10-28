#include "m2c_macros.h"

M2C_UNK StaticInitSwSlotheaps(M2C_UNK, M2C_UNK);    /* extern */

void StaticInitSwSlotheaps_thunk(void) {
    StaticInitSwSlotheaps(1, 0xFFFF);
}
