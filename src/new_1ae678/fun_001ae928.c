#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void func_001AE928(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x20) = PloFindSwObject_thunk(&B_003DD490, 0x405, 0x370, 0);
    M2C_FIELD(arg0, s32 *, 0x1EC) = -1;
    M2C_FIELD(arg0, s32 *, 0x1E8) = 0;
}
