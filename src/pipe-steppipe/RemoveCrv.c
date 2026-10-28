#include "m2c_macros.h"

M2C_UNK RemoveAloHierarchy();                       /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, s32);              /* extern */
extern M2C_UNK B_003E13C0;

void RemoveCrv(s32 arg0) {
    RemoveAloHierarchy();
    RemoveDlEntry(&B_003E13C0, arg0);
}
