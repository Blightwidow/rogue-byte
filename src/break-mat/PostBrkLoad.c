#include "m2c_macros.h"

M2C_UNK PostSoLoad();                               /* extern */

void PostBrkLoad(void) {
    PostSoLoad();
}
