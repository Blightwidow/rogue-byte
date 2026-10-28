#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_001EC910 (initial). */

s32 func_001EC910(s32 arg0) {
    return M2C_ERROR(/* Read from unset register $v0 */) + arg0;
}
