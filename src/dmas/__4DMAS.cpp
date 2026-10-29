#include "m2c_macros.h"
extern "C" {

void Clear__4DMAS(void *);                             /* extern */
extern M2C_UNK D_002CE488;

void *__4DMAS(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x18) = &D_002CE488;
    Clear__4DMAS(arg0);
    return arg0;
}
}
