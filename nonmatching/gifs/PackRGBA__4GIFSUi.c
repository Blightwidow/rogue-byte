#include "m2c_macros.h"

M2C_UNK CheckReg__4GIFSii(M2C_UNK, M2C_UNK);        /* extern */

void PackRGBA__4GIFSUi(void *arg0, u32 arg1) {
    void *temp_v0;

    CheckReg__4GIFSii(1, 1);
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (temp_v0 + 0x10);
    M2C_FIELD(temp_v0, s32 *, 0) = (s32) (arg1 & 0xFF);
    M2C_FIELD(temp_v0, u32 *, 0xC) = (u32) (arg1 >> 0x18);
    M2C_FIELD(temp_v0, u32 *, 4) = (u32) ((u32) (arg1 & 0xFF00) >> 8);
    M2C_FIELD(temp_v0, s32 *, 8) = (s32) ((arg1 >> 0x10) & 0xFF);
}
