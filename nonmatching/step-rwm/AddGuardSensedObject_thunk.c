#include "m2c_macros.h"

M2C_UNK AddGuardSensedObject(M2C_UNK);              /* extern */

void AddGuardSensedObject_thunk(void) {
    AddGuardSensedObject(0);
}
