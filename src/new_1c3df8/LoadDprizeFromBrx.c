#include "m2c_macros.h"

M2C_UNK CSo_LoadFromBrx();                            /* extern */
M2C_UNK SetSoProperties(void *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK SetXfKind(void *, s32, M2C_UNK);            /* extern */
void *func_001F7B98(void *);                        /* extern */
extern M2C_UNK D_002C0D40;

void LoadDprizeFromBrx(void *arg0) {
    CSo_LoadFromBrx();
    M2C_FIELD(func_001F7B98(arg0), s32 *, 0xF0) = 1;
    SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 0x15);
    SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 0x15);
    SetSoProperties(arg0, 1, &D_002C0D40);
}
