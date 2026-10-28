#include "m2c_macros.h"

void EnableFallCheck(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
}
