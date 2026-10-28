#include "m2c_macros.h"

f32 SMaxCrv(void *);                                /* extern */
f32 SMinCrv(void *);                                /* extern */

s32 AttachCrv_FGetWrapRange(void *arg0, void *arg1) {
    if (M2C_FIELD(arg0, s32 *, 0xE4) == 0) {
        return 0;
    }
    M2C_FIELD(arg1, f32 *, 0) = SMinCrv(arg0);
    M2C_FIELD(arg1, f32 *, 4) = SMaxCrv(arg0);
    return 1;
}
