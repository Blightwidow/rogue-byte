#include "m2c_macros.h"

M2C_UNK CSo_LoadFromBrx();                            /* extern */
M2C_UNK SetSoProperties(s32, M2C_UNK, M2C_UNK *);   /* extern */
extern M2C_UNK D_002C0258;

void func_001B1E00(s32 arg0) {
    CSo_LoadFromBrx();
    SetSoProperties(arg0, 1, &D_002C0258);
}
