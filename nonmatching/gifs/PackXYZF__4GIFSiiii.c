#include "m2c_macros.h"

M2C_UNK CheckReg__4GIFSii(M2C_UNK, M2C_UNK);        /* extern */

void PackXYZF__4GIFSiiii(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v1;

    CheckReg__4GIFSii(1, 4);
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (temp_v1 + 0x10);
    M2C_FIELD(temp_v1, s32 *, 0xC) = (s32) ((M2C_ERROR(/* Read from unset register $t0 */) & 0xFF) * 0x10);
    M2C_FIELD(temp_v1, s32 *, 0) = arg1;
    M2C_FIELD(temp_v1, s32 *, 4) = arg2;
    M2C_FIELD(temp_v1, s32 *, 8) = arg3;
}
