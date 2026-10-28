#include "m2c_macros.h"

M2C_UNK AppendSlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK ResetVjoy();                                /* extern */
extern M2C_UNK B_003E133C;
extern M2C_UNK D_002CA240;

void *VJOY_constructor(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002CA240;
    ResetVjoy();
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x80) = -1;
    AppendSlEntry(&B_003E133C, arg0);
    return arg0;
}
