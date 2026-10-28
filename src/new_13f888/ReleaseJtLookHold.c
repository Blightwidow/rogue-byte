#include "m2c_macros.h"

void ReleaseJtLookHold(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x1100) = 0;
}
