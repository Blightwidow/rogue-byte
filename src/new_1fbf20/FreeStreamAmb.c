#include "m2c_macros.h"

M2C_UNK FreeSlotheapPv(M2C_UNK *, s32);             /* extern */
extern M2C_UNK B_003DD074;

void FreeStreamAmb(s32 arg0) {
    FreeSlotheapPv(&B_003DD074, arg0);
}
