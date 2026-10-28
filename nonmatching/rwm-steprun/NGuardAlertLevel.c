#include "m2c_macros.h"

s32 GrfsgsFromSgs(M2C_UNK);                         /* extern */

s32 NGuardAlertLevel(void *arg0) {
    s32 temp_s0;

    if (M2C_FIELD(arg0, s64 *, 0x2C0) & GrfsgsFromSgs(7)) {
        return 2;
    }
    temp_s0 = GrfsgsFromSgs(5);
    return !(M2C_FIELD(arg0, s64 *, 0x2C0) & (temp_s0 | GrfsgsFromSgs(6))) ? 0 : 1;
}
