#include "m2c_macros.h"

M2C_UNK InitDynamicTextStatics(M2C_UNK, M2C_UNK);   /* extern */

void InitDynamicTextStatics_thunk(void) {
    InitDynamicTextStatics(1, 0xFFFF);
}
