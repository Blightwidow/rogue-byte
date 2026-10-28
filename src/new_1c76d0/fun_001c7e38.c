#include "m2c_macros.h"

M2C_UNK InitDprize();                               /* extern */

void func_001C7E38(void *arg0) {
    InitDprize();
    M2C_FIELD(arg0, f32 *, 0x1DC) = 50.0f;
}
