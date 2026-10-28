#include "m2c_macros.h"

M2C_UNK UpdateSwFog();                              /* extern */

void func_0020F2D8(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x3E24) = fparg0;
    UpdateSwFog();
}
