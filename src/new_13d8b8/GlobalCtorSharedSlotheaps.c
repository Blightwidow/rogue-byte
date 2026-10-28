#include "m2c_macros.h"

M2C_UNK StaticInitSharedSlotheaps(M2C_UNK, M2C_UNK); /* extern */

void GlobalCtorSharedSlotheaps(void) {
    StaticInitSharedSlotheaps(1, 0xFFFF);
}
