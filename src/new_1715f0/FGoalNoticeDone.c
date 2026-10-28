#include "m2c_macros.h"

s32 FGoalNoticeDone(void *arg0) {
    return ~M2C_FIELD(arg0, s32 *, 0x34) == 0;
}
