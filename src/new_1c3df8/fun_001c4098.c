#include "m2c_macros.h"

s32 GetPoVjoyMode();                                /* extern */

s32 func_001C4098(void) {
    return ~GetPoVjoyMode() != 0;
}
