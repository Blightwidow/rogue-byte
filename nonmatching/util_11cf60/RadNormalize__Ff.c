#include "m2c_macros.h"

f32 GModPositive__Fff(f32, M2C_UNK);                /* extern */

f32 RadNormalize__Ff(f32 fparg0) {
    f32 var_f12;

    var_f12 = fparg0;
    if ((var_f12 < -3.1415927f) || (var_f12 > 3.1415927f)) {
        var_f12 = GModPositive__Fff(var_f12 + 3.1415927f, 0x40C90FDB) - 3.1415927f;
    }
    return var_f12;
}
