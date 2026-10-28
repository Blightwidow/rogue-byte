#include "m2c_macros.h"

void SetScrollerMasterSpeeds__FP8SCROLLERff(void *arg0, f32 fparg0, f32 fparg1) {
    M2C_FIELD(arg0, f32 *, 0x60) = fparg0;
    M2C_FIELD(arg0, f32 *, 0x64) = fparg1;
}
