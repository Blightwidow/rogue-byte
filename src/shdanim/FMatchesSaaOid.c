#include "m2c_macros.h"

s32 FMatchesSaaOid(void *arg0, s32 *arg1) {
    return *arg1 == M2C_FIELD(arg0, s32 *, 0x14);
}
