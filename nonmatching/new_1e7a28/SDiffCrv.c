#include "m2c_macros.h"

f32 SMaxCrv();                                      /* extern */

f32 SDiffCrv(void *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    f32 var_f20;

    var_f20 = fparg1 - fparg0;
    if (M2C_FIELD(arg0, s32 *, 0xE4) != 0) {
        temp_f0 = SMaxCrv();
        if ((temp_f0 * 0.5f) < var_f20) {
            var_f20 -= temp_f0;
        } else if (var_f20 < (temp_f0 * -0.5f)) {
            var_f20 += temp_f0;
        }
    }
    return var_f20;
}
