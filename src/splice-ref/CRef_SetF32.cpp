#include "m2c_macros.h"
extern "C" {

void CRef_Destruct(void *arg0);

void *CRef_SetF32(void *arg0, f32 fparg0) {
    CRef_Destruct(arg0);
    M2C_FIELD(arg0, f32 *, 4) = fparg0;
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    return arg0;
}
}
