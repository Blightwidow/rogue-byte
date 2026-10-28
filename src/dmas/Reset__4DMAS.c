#include "m2c_macros.h"

void Reset__4DMAS(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 4);
}
