#include "m2c_macros.h"

M2C_UNK PleaseAcquire(M2C_UNK);                     /* extern */

void ClonePool_AcquireLeaseCallback(void) {
    PleaseAcquire(2);
}
