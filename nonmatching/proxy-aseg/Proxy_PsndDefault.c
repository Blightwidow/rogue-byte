#include "m2c_macros.h"

M2C_UNK AddProxySnd(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

s32 Proxy_PsndDefault(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xE0) == 0) {
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE8) + (M2C_FIELD(arg0, s32 *, 0xE4) * 0x14));
        AddProxySnd(-1, 0x12C, 0xBB8, 0x3F800000, 0);
    }
    return M2C_FIELD(arg0, s32 *, 0xE0);
}
