#include "m2c_macros.h"

void DecrementCounterB_1feec0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) - 1);
}
