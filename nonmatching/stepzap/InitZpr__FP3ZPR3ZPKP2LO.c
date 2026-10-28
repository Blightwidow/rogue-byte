#include "m2c_macros.h"

M2C_UNK memset(M2C_UNK, M2C_UNK);                   /* extern */

void InitZpr__FP3ZPR3ZPKP2LO(void *arg0, s32 arg1, s32 arg2) {
    memset(0, 0x630);
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}
