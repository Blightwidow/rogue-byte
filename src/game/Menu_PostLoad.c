#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void Menu_PostLoad(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = PloFindSwObject_thunk(&B_003DD490, 5, M2C_FIELD(arg0, s32 *, 0x20), 0);
}
