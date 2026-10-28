#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK PloNew(M2C_UNK, s32, M2C_UNK, M2C_UNK);     /* extern */
extern M2C_UNK B_003DD490;

void func_001F7B98(s32 arg0) {
    if (PloFindSwObject_thunk(&B_003DD490, 2, 0x187, arg0) == 0) {
        PloNew(0x12, arg0, 0x187, -1);
    }
}
