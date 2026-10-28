#include "m2c_macros.h"

M2C_UNK UpdateSwFog();                              /* extern */

void func_0020F2F8(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x3E20) = fparg0;
    UpdateSwFog();
}
