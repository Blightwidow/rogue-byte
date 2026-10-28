#include "m2c_macros.h"

f32 GModPositive__Fff(f32);                         /* extern */

f32 SWrapCrv(void *arg0, f32 fparg0) {
    f32 temp_f13;
    f32 var_f0;

    var_f0 = fparg0;
    if ((M2C_FIELD(arg0, s32 *, 0xE4) != 0) && ((temp_f13 = M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0xE8) * 4) + M2C_FIELD(arg0, s32 *, 0xF0)), f32 *, -4), !(fparg0 >= 0.0f)) || (var_f0 = fparg0, !(fparg0 <= temp_f13)))) {
        var_f0 = GModPositive__Fff(temp_f13);
    }
    return var_f0;
}
