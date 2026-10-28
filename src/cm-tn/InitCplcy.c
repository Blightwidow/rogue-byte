#include "m2c_macros.h"

extern M2C_UNK D_002CD570;

void *InitCplcy(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002CD570;
    return arg0;
}
