#include "m2c_macros.h"

M2C_UNK InitCplcy();                                /* extern */
extern M2C_UNK D_002CD408;

void *func_00151610(void *arg0) {
    InitCplcy();
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002CD408;
    return arg0;
}
