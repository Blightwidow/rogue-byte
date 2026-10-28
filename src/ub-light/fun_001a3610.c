#include "m2c_macros.h"

M2C_UNK RebuildLight();                             /* extern */

void func_001A3610(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x150) = fparg0;
    RebuildLight();
}
