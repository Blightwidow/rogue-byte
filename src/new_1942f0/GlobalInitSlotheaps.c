#include "m2c_macros.h"

M2C_UNK StaticInitSlotheaps(M2C_UNK, M2C_UNK);      /* extern */

void GlobalInitSlotheaps(void) {
    StaticInitSlotheaps(1, 0xFFFF);
}
