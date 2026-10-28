#include "m2c_macros.h"

M2C_UNK UpdateSwFog();                              /* extern */

void SetSwFogHsv(void *arg0, s128 arg1) {
    M2C_FIELD(arg0, s128 *, 0x3E10) = arg1;
    UpdateSwFog();
}
