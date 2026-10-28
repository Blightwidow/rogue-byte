#include "m2c_macros.h"

M2C_UNK PvAllocSlotheapImpl(M2C_UNK *);             /* extern */
extern M2C_UNK B_003DD05C;

void PvAllocAmb(void) {
    PvAllocSlotheapImpl(&B_003DD05C);
}
