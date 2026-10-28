#include "m2c_macros.h"

M2C_UNK StaticInitMark(M2C_UNK, M2C_UNK);           /* extern */

void GlobalCtorMark(void) {
    StaticInitMark(1, 0xFFFF);
}
