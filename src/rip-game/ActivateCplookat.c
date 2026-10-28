#include "m2c_macros.h"

M2C_UNK ActivateCplcy();                            /* extern */

void ActivateCplookat(void *arg0, s32 arg1, s32 arg2) {
    ActivateCplcy();
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
    M2C_FIELD(arg0, s32 *, 0x10) = arg2;
}
