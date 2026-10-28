#include "m2c_macros.h"

M2C_UNK Menu_ResetState();                          /* extern */
extern M2C_UNK D_002D85E8;

void *Menu_Construct(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D85E8;
    M2C_FIELD(arg0, s32 *, 0x20) = -1;
    Menu_ResetState();
    return arg0;
}
