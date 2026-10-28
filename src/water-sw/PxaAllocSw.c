#include "m2c_macros.h"

M2C_UNK PvAllocSlotheapImpl(s32);                   /* extern */

void PxaAllocSw(s32 arg0) {
    PvAllocSlotheapImpl(arg0 + 0x40E8);
}
