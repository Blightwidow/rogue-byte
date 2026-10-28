#include "m2c_macros.h"

M2C_UNK InitAmbBase();                              /* extern */
M2C_UNK SetAmbGrf(void *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK D_002D9C70;

void *InitAmb(void *arg0, s32 arg1) {
    InitAmbBase();
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D9C70;
    SetAmbGrf(arg0, 1, 1);
    return arg0;
}
