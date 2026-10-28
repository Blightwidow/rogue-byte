#include "m2c_macros.h"

M2C_UNK RemoveAloHierarchy();                       /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, s32);              /* extern */
extern M2C_UNK B_003E1480;

void func_00227E58(s32 arg0) {
    RemoveAloHierarchy();
    RemoveDlEntry(&B_003E1480, arg0);
}
