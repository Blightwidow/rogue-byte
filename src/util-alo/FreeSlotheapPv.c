#include "m2c_macros.h"

void FreeSlotheapPv(void *arg0, M2C_UNK *arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) - 1);
    *arg1 = M2C_FIELD(arg0, M2C_UNK **, 0xC);
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = arg1;
}
