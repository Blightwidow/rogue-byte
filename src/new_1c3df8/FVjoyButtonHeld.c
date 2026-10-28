#include "m2c_macros.h"

s32 FVjoyButtonHeld(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, s32 *, 0x30) & arg1) != 0;
}
