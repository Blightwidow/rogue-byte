#include "m2c_macros.h"

M2C_UNK FreeSlotheapPv(s32, s32);                   /* extern */
s32 PvAllocSlotheapImpl();                          /* extern */

void PrimeSlotheap(s32 arg0) {
    FreeSlotheapPv(arg0, PvAllocSlotheapImpl());
}
