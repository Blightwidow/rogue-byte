#include "m2c_macros.h"

M2C_UNK StaticInitializeRefSlotheaps(M2C_UNK, M2C_UNK); /* extern */

void StaticInitializeRefSlotheaps_thunk(void) {
    StaticInitializeRefSlotheaps(1, 0xFFFF);
}
