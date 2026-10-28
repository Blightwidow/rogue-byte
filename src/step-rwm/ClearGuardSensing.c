#include "m2c_macros.h"

M2C_UNK ClearGuardClassFilters(void *);             /* extern */
M2C_UNK ClearGuardIgnoredClasses();                 /* extern */

void ClearGuardSensing(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xF64), s32 *, 0xFC) = 0;
    M2C_FIELD(arg0, s32 *, 0x394) = 0;
    M2C_FIELD(arg0, s32 *, 0x3A4) = 0;
    ClearGuardIgnoredClasses();
    ClearGuardClassFilters(arg0);
}
