#include "m2c_macros.h"

void PleaseAcquire(s32, s32);

void ClonePool_AcquireLeaseCallback(s32 arg0) {
    PleaseAcquire(arg0, 2);
}
