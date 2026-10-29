#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_00259D80 (initial). */

f32 func_00259D80(f32 fparg0) {
    return fparg0 + (fparg0 + M2C_ERROR(/* Read from unset register $f0 */));
}