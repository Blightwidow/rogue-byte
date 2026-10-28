#include "m2c_macros.h"

s32 FClueFound(s32);                                /* extern */
M2C_UNK PostLoLoad();                               /* extern */
extern M2C_UNK B_003DD490;

void PostClueLoad(void *arg0) {
    void *temp_v0;

    PostLoLoad();
    M2C_FIELD(arg0, s32 *, 0x100) = (s32) M2C_FIELD(&B_003DD490, s32 *, 0x4760);
    M2C_FIELD(&B_003DD490, s32 *, 0x4760) = (s32) (M2C_FIELD(&B_003DD490, s32 *, 0x4760) + 1);
    if (FClueFound(M2C_FIELD(arg0, s32 *, 0x100)) != 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x4C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x48));
    }
}
