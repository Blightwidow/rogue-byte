#include "m2c_macros.h"

void ClearGuardClassFilters(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3C0) = 0;
}
