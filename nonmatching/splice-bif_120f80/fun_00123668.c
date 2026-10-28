#include "m2c_macros.h"

void *func_00123668(void *arg0, void *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = 0x15;
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_ERROR(/* Read from unset register $f1 */);
    return arg0;
}
