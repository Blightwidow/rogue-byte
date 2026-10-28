#include "m2c_macros.h"

M2C_UNK InitJumper(void *);                         /* extern */
M2C_UNK __4CRef(void *);                            /* extern */
extern M2C_UNK D_002D44C8;
extern M2C_UNK D_002D9978;

void *ConstructMurray(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D9978;
    __4CRef(arg0 + 0x80);
    M2C_FIELD(arg0, s32 *, 0x174) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D44C8;
    InitJumper(arg0 + 0x1890);
    return arg0;
}
