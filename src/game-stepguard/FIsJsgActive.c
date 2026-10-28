#include "m2c_macros.h"

s32 FIsJsgActive(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x74);
}
