#include "m2c_macros.h"

M2C_UNK CheckReg__4GIFSii(M2C_UNK, M2C_UNK);        /* extern */

void ListRGBAQ__4GIFSUif(void *arg0, s64 arg1, f32 fparg0) {
    s64 *temp_a0;

    CheckReg__4GIFSii(0, 1);
    temp_a0 = M2C_FIELD(arg0, s64 **, 0xC);
    M2C_FIELD(arg0, s64 **, 0xC) = (s64 *) (temp_a0 + 8);
    *temp_a0 = ((u64) (arg1 << 0x20) >> 0x20) | (M2C_BITWISE(s64, fparg0) << 0x20);
}
