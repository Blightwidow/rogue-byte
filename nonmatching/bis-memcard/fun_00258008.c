#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_00258008 (initial). */

void *func_00258008(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
    return arg0;
}
