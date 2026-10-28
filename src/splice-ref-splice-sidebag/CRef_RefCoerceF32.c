#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct();                       /* extern */

void *CRef_RefCoerceF32(void *arg0, void *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0) == 0x16) {
        CRef_CopyConstruct();
    } else {
        M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0) = 0x16;
    }
    return arg0;
}
