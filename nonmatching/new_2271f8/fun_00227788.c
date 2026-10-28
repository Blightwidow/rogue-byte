#include "m2c_macros.h"

M2C_UNK func_002275B8(void *, M2C_UNK);             /* extern */

void func_00227788(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_FIELD(arg0, s32 *, 0) = -1;
    func_002275B8(sp, -1);
    M2C_FIELD(arg0, M2C_UNK *, 4) = M2C_UNALIGNED32(sp0);
    M2C_FIELD(arg0, s32 *, 8) = 0;
}
