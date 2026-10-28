#include "m2c_macros.h"

f32 GLimitAbs__Fff(f32, f32);                       /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */

void RadLimitLm(void *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0);
    temp_f20 = M2C_FIELD(arg0, f32 *, 4);
    temp_f21 = (temp_f20 + temp_f0) * 0.5f;
    RadNormalize__Ff(temp_f21 + GLimitAbs__Fff(RadNormalize__Ff(fparg0 - temp_f21), (temp_f20 - temp_f0) * 0.5f));
}
