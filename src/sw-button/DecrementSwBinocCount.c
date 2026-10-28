#include "m2c_macros.h"

void DecrementSwBinocCount(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3D84) = (s32) (M2C_FIELD(arg0, s32 *, 0x3D84) - 1);
}
