#include "m2c_macros.h"

s32 FMatchesSaaOid();                               /* extern */

s32 PsaiFromEyesShd__FP4EYESP3SHD(void *arg0, s32 *arg1) {
    s32 var_v0;

    if ((FMatchesSaaOid() != 0) || (var_v0 = 0, (*arg1 == M2C_FIELD(arg0, s32 *, 0x60)))) {
        var_v0 = 1;
    }
    return var_v0;
}
