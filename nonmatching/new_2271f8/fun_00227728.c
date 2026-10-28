#include "m2c_macros.h"

M2C_UNK func_002275B8(void *, s32);                 /* extern */
M2C_UNK func_00227788();                            /* extern */

void func_00227728(void *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    M2C_UNK sp0;
    func_00227788();
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    func_002275B8(sp, arg2);
    M2C_FIELD(arg0, M2C_UNK *, 4) = M2C_UNALIGNED32(sp0);
}
