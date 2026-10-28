#include "m2c_macros.h"

M2C_UNK CRef_Destruct();                            /* extern */

void *CRef_SetF32(void *arg0, f32 fparg0) {
    CRef_Destruct();
    M2C_FIELD(arg0, f32 *, 4) = fparg0;
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    return arg0;
}
