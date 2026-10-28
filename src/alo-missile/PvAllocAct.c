#include "m2c_macros.h"

M2C_UNK PvAllocSlotheapImpl(M2C_UNK *);             /* extern */
extern M2C_UNK B_003E123C;

void PvAllocAct(void) {
    PvAllocSlotheapImpl(&B_003E123C);
}
