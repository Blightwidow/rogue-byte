#include "m2c_macros.h"

M2C_UNK LoadSoFromBrx();                            /* extern */
M2C_UNK ResolveSlotSoAsegs(void *);                 /* extern */
M2C_UNK SetXfKind(void *, void *, M2C_UNK);         /* extern */

void func_001B0CA8(void *arg0) {
    void *temp_v0;
    void *temp_v1;

    LoadSoFromBrx();
    SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x58), 1);
    temp_v1 = M2C_FIELD(arg0, void **, 0x58);
    temp_v0 = temp_v1 + 0xF0;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v1, s32 *, 0xF0) = 0;
    M2C_FIELD(arg0, s32 *, 0x1D4) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x98);
    ResolveSlotSoAsegs(arg0);
}
