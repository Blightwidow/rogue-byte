#include "m2c_macros.h"

M2C_UNK CheckReg__4GIFSii(M2C_UNK, M2C_UNK);        /* extern */

void PackXYZ__4GIFSiii(void *arg0, s32 arg1, s32 arg2, s64 arg3) {
    void *temp_v0;

    CheckReg__4GIFSii(1, 5);
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (temp_v0 + 0x10);
    M2C_FIELD(temp_v0, s64 *, 8) = arg3;
    M2C_FIELD(temp_v0, s32 *, 0) = arg1;
    M2C_FIELD(temp_v0, s32 *, 4) = arg2;
}
