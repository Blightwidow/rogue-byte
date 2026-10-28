#include "m2c_macros.h"

M2C_UNK CheckReg__4GIFSii(M2C_UNK, M2C_UNK);        /* extern */

void PackAD__4GIFSll(void *arg0, s64 arg1, s64 arg2) {
    void *temp_v0;

    CheckReg__4GIFSii(1, 0xE);
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (temp_v0 + 0x10);
    M2C_FIELD(temp_v0, s64 *, 8) = arg1;
    M2C_FIELD(temp_v0, s64 *, 0) = arg2;
}
