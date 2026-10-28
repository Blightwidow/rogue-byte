#include "m2c_macros.h"

M2C_UNK StaticInitSw(M2C_UNK, M2C_UNK);             /* extern */

void GlobalDtorSw(void) {
    StaticInitSw(0, 0xFFFF);
}
