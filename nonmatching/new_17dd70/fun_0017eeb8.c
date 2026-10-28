#include "m2c_macros.h"

f32 SMaxCrv(void *);                                /* extern */
f32 SMinCrv(void *);                                /* extern */
extern f32 D_FLT_002BE7B8;

s32 func_0017EEB8(void *arg0) {
    f32 var_f0;
    s32 var_v0;
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x30);
    var_v0 = 0;
    if (M2C_FIELD(temp_a0, s32 *, 0xE4) == 0) {
        if (M2C_FIELD(arg0, s32 *, 0x34) != 0) {
            var_f0 = SMaxCrv(temp_a0);
        } else {
            var_f0 = SMinCrv(temp_a0);
        }
        var_v0 = 0;
        if (!(D_FLT_002BE7B8 < fabsf(M2C_FIELD(arg0, f32 *, 0x38) - var_f0))) {
            var_v0 = 1;
        }
    }
    return var_v0;
}
