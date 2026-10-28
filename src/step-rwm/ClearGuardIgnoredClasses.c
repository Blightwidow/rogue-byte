#include "m2c_macros.h"

void ClearGuardIgnoredClasses(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3A8) = 0;
}
