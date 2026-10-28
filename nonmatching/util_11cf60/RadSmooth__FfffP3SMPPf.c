#include "m2c_macros.h"

f32 GSmooth__FfffP3SMPPf(s32, s32, M2C_UNK, f32, f32); /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */

void RadSmooth__FfffP3SMPPf(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    RadNormalize__Ff(fparg0 + GSmooth__FfffP3SMPPf(arg0, arg1, 0, RadNormalize__Ff(fparg1 - fparg0), fparg2));
}
