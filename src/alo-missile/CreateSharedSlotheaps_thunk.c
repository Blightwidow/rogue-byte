#include "m2c_macros.h"

M2C_UNK CreateSharedSlotheaps(M2C_UNK, M2C_UNK);    /* extern */

void CreateSharedSlotheaps_thunk(void) {
    CreateSharedSlotheaps(1, 0xFFFF);
}
