#include "m2c_macros.h"

M2C_UNK InitStaticBitmapA(M2C_UNK, M2C_UNK);        /* extern */

void InitStaticBitmapA_thunk(void) {
    InitStaticBitmapA(1, 0xFFFF);
}
