#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK SetWipeWipes(void *, M2C_UNK);              /* extern */
extern M2C_UNK B_003DD490;

void PostLoadWipe(void *arg0) {
    s32 temp_v0;

    temp_v0 = PloFindSwObject_thunk(&B_003DD490, 0x405, M2C_FIELD(arg0, s32 *, 0x58), 0);
    M2C_FIELD(arg0, s32 *, 0x54) = temp_v0;
    if ((temp_v0 == 0) || (M2C_FIELD(arg0, s32 *, 0) != 3)) {
        SetWipeWipes(arg0, 0);
        return;
    }
    SetWipeWipes(arg0, 2);
}
