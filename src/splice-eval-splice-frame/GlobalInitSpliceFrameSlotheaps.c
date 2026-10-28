#include "m2c_macros.h"

M2C_UNK StaticInitSpliceFrameSlotheaps(M2C_UNK, M2C_UNK); /* extern */

void GlobalInitSpliceFrameSlotheaps(void) {
    StaticInitSpliceFrameSlotheaps(1, 0xFFFF);
}
