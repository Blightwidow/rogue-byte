#include "m2c_macros.h"

s32 GoalPartnerAttackMurray_FIdle(void *arg0) {
    return ~M2C_FIELD(arg0, s32 *, 0x30) == 0;
}
