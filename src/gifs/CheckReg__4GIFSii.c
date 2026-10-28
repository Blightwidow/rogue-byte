#include "m2c_macros.h"

void CheckReg__4GIFSii(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + 1);
}
