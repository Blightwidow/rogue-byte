#include "m2c_macros.h"

M2C_UNK CheckReg__4GIFSii(M2C_UNK, M2C_UNK);        /* extern */

void GIFS_ListXYZ(void *arg0, s32 arg1, s32 arg2, s64 arg3) {
    s64 *temp_v1;

    CheckReg__4GIFSii(0, 5);
    temp_v1 = M2C_FIELD(arg0, s64 **, 0xC);
    M2C_FIELD(arg0, s64 **, 0xC) = (s64 *) (temp_v1 + 8);
    *temp_v1 = arg1 | (arg2 << 0x10) | (arg3 << 0x20);
}
