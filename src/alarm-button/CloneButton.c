#include "m2c_macros.h"

M2C_UNK CSo_Clone();                                  /* extern */

void CloneButton(void *arg0) {
    CSo_Clone();
    M2C_FIELD(arg0, void **, 0x150) = arg0;
}
