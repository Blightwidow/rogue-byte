#include "m2c_macros.h"

M2C_UNK AddRefSharedSlotheaps(M2C_UNK, M2C_UNK);    /* extern */

void AddRefSharedSlotheaps_thunk(void) {
    AddRefSharedSlotheaps(1, 0xFFFF);
}
