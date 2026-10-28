#include "m2c_macros.h"

s32 PmatWorldSo(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x60) + 0x40;
}
