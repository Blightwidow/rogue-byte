#include "m2c_macros.h"

void *PentryAddBootQueue(M2C_UNK);                  /* extern */

void AddBootQueueLevel(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 var_v0;
    void *temp_v0;

    var_v0 = 0;
    if (arg1 != NULL) {
        var_v0 = M2C_FIELD(arg1, s32 *, 4) != M2C_FIELD(arg1, s32 *, 0x3C);
    }
    if (var_v0 != 0) {
        temp_v0 = PentryAddBootQueue(2);
        M2C_FIELD(temp_v0, void **, 8) = arg1;
        M2C_FIELD(temp_v0, s32 *, 0xC) = arg2;
        M2C_FIELD(temp_v0, s32 *, 0x10) = arg3;
    }
}
