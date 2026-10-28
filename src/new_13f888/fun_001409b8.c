#include "m2c_macros.h"

s32 FSwHandsOff(M2C_UNK *);                         /* extern */
extern M2C_UNK B_003DD490;

s32 func_001409B8(void) {
    return (FSwHandsOff(&B_003DD490) != 0) ? 0 : -1;
}
