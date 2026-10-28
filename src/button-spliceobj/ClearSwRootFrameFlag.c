#include "m2c_macros.h"

void ClearSwRootFrameFlag(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3A14) = 0;
}
