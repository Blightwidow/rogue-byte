#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
extern f32 D_FLT_002BE900;

void func_00183F50(void *arg0) {
    PostLoLoad();
    if (M2C_FIELD(arg0, s32 *, 0xFC) == 0) {
        M2C_FIELD(arg0, s32 *, 0xFC) = 7;
    }
    if (M2C_FIELD(arg0, f32 *, 0x38) == 1e10f) {
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) D_FLT_002BE900;
    }
}
