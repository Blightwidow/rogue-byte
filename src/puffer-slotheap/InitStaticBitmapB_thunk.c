#include "m2c_macros.h"

M2C_UNK InitStaticBitmapB(M2C_UNK, M2C_UNK);        /* extern */

void InitStaticBitmapB_thunk(void) {
    InitStaticBitmapB(1, 0xFFFF);
}
