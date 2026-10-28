#include "m2c_macros.h"

M2C_UNK CheckReg__4GIFSii(M2C_UNK, M2C_UNK);        /* extern */

void ListUV__4GIFSii(void *arg0, s32 arg1, s32 arg2) {
    s64 *temp_v1;

    CheckReg__4GIFSii(0, 3);
    temp_v1 = M2C_FIELD(arg0, s64 **, 0xC);
    M2C_FIELD(arg0, s64 **, 0xC) = (s64 *) (temp_v1 + 8);
    *temp_v1 = arg1 | (arg2 << 0x10);
}
