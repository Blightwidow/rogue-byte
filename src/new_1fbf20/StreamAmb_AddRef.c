#include "m2c_macros.h"

void StreamAmb_AddRef(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0x4C) = (u16) (M2C_FIELD(arg0, u16 *, 0x4C) + 1);
}
