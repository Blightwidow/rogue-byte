#include "m2c_macros.h"

f32 GModPositive__Fff(f32, f32);                    /* extern */

f32 UWrapCrv(void *arg0, f32 fparg0) {
    f32 *temp_v1;
    f32 temp_f13;
    f32 temp_f20;
    f32 var_f0;

    var_f0 = fparg0;
    if (M2C_FIELD(arg0, s32 *, 0xE4) != 0) {
        temp_v1 = M2C_FIELD(arg0, f32 **, 0xEC);
        temp_f20 = *temp_v1;
        temp_f13 = M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0xE8) * 4) + temp_v1), f32 *, -4);
        if (!(temp_f20 <= var_f0) || !(var_f0 <= temp_f13)) {
            var_f0 = temp_f20 + GModPositive__Fff(var_f0 - temp_f20, temp_f13 - temp_f20);
        }
    }
    return var_f0;
}
