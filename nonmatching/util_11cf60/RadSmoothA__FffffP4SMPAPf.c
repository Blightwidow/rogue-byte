#include "m2c_macros.h"

f32 GSmoothA__FffffP4SMPAPf(s32, s32, M2C_UNK, f32, f32, f32); /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */

void RadSmoothA__FffffP4SMPAPf(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    RadNormalize__Ff(fparg0 + GSmoothA__FffffP4SMPAPf(arg0, arg1, 0, fparg1, RadNormalize__Ff(fparg2 - fparg0), fparg3));
}
