#include "m2c_macros.h"

void *PvAllocSlotheapImpl(s32);                     /* extern */

void AllocSwOx(s32 arg0, void *arg1, void *arg2) {
    void *temp_v0;

    temp_v0 = PvAllocSlotheapImpl(arg0 + 0x3CF8);
    M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_FIELD(arg2, s32 *, 0x60);
    M2C_FIELD(temp_v0, void **, 4) = (void *) M2C_FIELD(arg1, void **, 0x64);
    M2C_FIELD(arg1, void **, 0x64) = temp_v0;
}
