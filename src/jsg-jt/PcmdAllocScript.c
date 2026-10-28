#include "m2c_macros.h"

M2C_UNK AppendSlEntry(s32, void *);                 /* extern */
void *PvAllocSlotheapImpl(M2C_UNK *);               /* extern */
extern M2C_UNK B_003E1548;

void *PcmdAllocScript(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = PvAllocSlotheapImpl(&B_003E1548);
    M2C_FIELD(temp_v0, s32 *, 0) = arg1;
    M2C_FIELD(temp_v0, s32 *, 4) = arg2;
    AppendSlEntry(arg0 + 0x50, temp_v0);
    return temp_v0;
}
