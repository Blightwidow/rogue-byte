#include "m2c_macros.h"

M2C_UNK FIsSgsInGrfsgs(s64);                        /* extern */

void FIsGuardInSgs(void *arg0) {
    FIsSgsInGrfsgs(M2C_FIELD(arg0, s64 *, 0x2C0));
}
