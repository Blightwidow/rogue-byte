#include "m2c_macros.h"

s32 PloNew(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK PostGuardLoad();                            /* extern */

void func_0014B1D8(void *arg0) {
    PostGuardLoad();
    M2C_FIELD(arg0, s32 *, 0x1010) = PloNew(3, 0, 0x62B, -1);
}
