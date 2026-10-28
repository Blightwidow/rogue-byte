#include "m2c_macros.h"

M2C_UNK AddGuardAimOid();                           /* extern */
M2C_UNK ResolveGuardAimObjects(s32);                /* extern */

void AddGuardAimOidResolve(s32 arg0) {
    AddGuardAimOid();
    ResolveGuardAimObjects(arg0);
}
