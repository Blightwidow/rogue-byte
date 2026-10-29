#include "m2c_macros.h"
extern "C" {
M2C_UNK AddGrfusr__Fi(M2C_UNK);
M2C_UNK IncrementSwBinocCount(s8 *);
M2C_UNK IncrementSwShowCount(s8 *);

void SetHandsOff(s8 *arg0, s32 arg1) {
    s32 count = *(s32 *)(arg0 + 0x3D78) + 1;
    *(s32 *)(arg0 + 0x3D78) = count;
    if (count == 1) {
        AddGrfusr__Fi(2);
    }
    if (arg1 & 1) {
        IncrementSwShowCount(arg0);
    }
    if (arg1 & 2) {
        IncrementSwBinocCount(arg0);
    }
}
}
