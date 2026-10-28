#include "m2c_macros.h"

void *PentryAddBootQueue(M2C_UNK);                  /* extern */

void AddBootQueueMovie(s32 arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg1 != NULL) {
        var_v0 = M2C_FIELD(arg1, s32 *, 4) != M2C_FIELD(arg1, s32 *, 0x3C);
    }
    if (var_v0 != 0) {
        M2C_FIELD(PentryAddBootQueue(0), void **, 4) = arg1;
    }
}
