#include "m2c_macros.h"

M2C_UNK RebuildLight();                             /* extern */

void SetLightHighlightColor(void *arg0, s128 arg1) {
    M2C_FIELD(arg0, s128 *, 0xF0) = arg1;
    RebuildLight();
}
