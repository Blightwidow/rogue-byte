#include "m2c_macros.h"

M2C_UNK StaticInitMpeg(M2C_UNK, M2C_UNK);           /* extern */

void GlobalCtorMpeg(void) {
    StaticInitMpeg(1, 0xFFFF);
}
