#include "m2c_macros.h"

f32 PackColorVecToU8_11dd30(void *arg0, s8 arg1, void *arg2) {
    M2C_FIELD(arg2, s8 *, 0) = (s8) M2C_ERROR(/* Read from unset register $f3 */);
    M2C_FIELD(arg2, s8 *, 1) = (s8) M2C_ERROR(/* Read from unset register $f3 */);
    M2C_FIELD(arg2, s8 *, 3) = arg1;
    M2C_FIELD(arg2, s8 *, 2) = 0x3F000000;
    return (M2C_FIELD(arg0, f32 *, 8) * 255.0f) + 0.5f;
}
