#include "m2c_macros.h"

M2C_UNK AddDmaBulk__4DMASiP2QW(void *, s32, s32);   /* extern */
M2C_UNK Align__4VIFSi(M2C_UNK);                     /* extern */

void AddVifDirect__4VIFSiP2QWi(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_a1;

    Align__4VIFSi(3);
    temp_a1 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_a1 + 4);
    *temp_a1 = arg1 | ((arg3 << 0x1F) | 0x50000000);
    AddDmaBulk__4DMASiP2QW(arg0, arg1, arg2);
}
