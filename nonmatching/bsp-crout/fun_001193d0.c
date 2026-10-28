#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_001193D0 (initial). */

void func_001193D0(void *arg0) {
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_ERROR(/* Read from unset register $f0 */);
}
