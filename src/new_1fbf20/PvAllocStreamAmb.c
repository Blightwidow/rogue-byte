#include "m2c_macros.h"

M2C_UNK PvAllocSlotheapImpl(M2C_UNK *);             /* extern */
extern M2C_UNK B_003DD074;

void PvAllocStreamAmb(void) {
    PvAllocSlotheapImpl(&B_003DD074);
}
