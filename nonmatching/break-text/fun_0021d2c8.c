#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
extern f32 D_FLT_002C40C0;

void func_0021D2C8(void *arg0) {
    PostLoLoad();
    if (M2C_FIELD(arg0, f32 *, 0x38) == 1e10f) {
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) (M2C_FIELD(arg0, f32 *, 0xEC) + D_FLT_002C40C0);
    }
}
