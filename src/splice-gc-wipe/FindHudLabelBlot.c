#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void FindHudLabelBlot(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x28) = PloFindSwObject_thunk(&B_003DD490, 0x405, 0x371, 0);
}
