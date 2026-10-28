#include "m2c_macros.h"

s32 FBootQueueHasEntries(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x1C4) < M2C_FIELD(arg0, s32 *, 0);
}
