#include "m2c_macros.h"

M2C_UNK PostSoLoad();                               /* extern */
M2C_UNK SetSoProperties(void *, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK D_002BD380;

void PostWipeLoad(void *arg0) {
    void *temp_v1;

    PostSoLoad();
    SetSoProperties(arg0, 2, &D_002BD380);
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, s32 *, 0x150) = -1;
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x4C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x48));
}
