#include "m2c_macros.h"

M2C_UNK ReinsertSwRoot(M2C_UNK *, s32);             /* extern */
extern M2C_UNK B_003DD490;

void InvalidateXfmMatWorld(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x54) = -1;
    if ((M2C_FIELD(arg0, s32 *, 0x10) == 0) && (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1)) {
        ReinsertSwRoot(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x14));
    }
}
