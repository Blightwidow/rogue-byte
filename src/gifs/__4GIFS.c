#include "m2c_macros.h"

M2C_UNK __4DMAS();                                  /* extern */
extern M2C_UNK D_002CF508;

void *__4GIFS(void *arg0) {
    __4DMAS();
    M2C_FIELD(arg0, s32 *, 0x14) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x18) = &D_002CF508;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    return arg0;
}
