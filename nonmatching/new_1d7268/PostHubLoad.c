#include "m2c_macros.h"

M2C_UNK PostSoLoad();                               /* extern */

void PostHubLoad(void *arg0) {
    void *temp_v0;

    PostSoLoad();
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x27C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x278), 0);
}
