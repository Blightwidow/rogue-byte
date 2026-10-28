#include "m2c_macros.h"

s32 PshdframesFromOid();                            /* extern */
extern s32 B_003E1590;

s32 PshdframesOrFirst(void) {
    s32 var_v0;

    var_v0 = PshdframesFromOid();
    if (var_v0 == 0) {
        var_v0 = B_003E1590;
    }
    return var_v0;
}
