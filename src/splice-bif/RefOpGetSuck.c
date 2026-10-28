#include "m2c_macros.h"

f32 GetSuck(M2C_UNK *);                             /* extern */
extern M2C_UNK B_002DE578;

void *RefOpGetSuck(void *arg0) {
    M2C_FIELD(arg0, f32 *, 4) = GetSuck(&B_002DE578);
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    return arg0;
}
