#include "m2c_macros.h"

void SetGuardDamageSource(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
}
