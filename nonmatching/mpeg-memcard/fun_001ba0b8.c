#include "m2c_macros.h"

M2C_UNK OnGuardAdd();                               /* extern */

void func_001BA0B8(void *arg0) {
    void *temp_a1;
    void *temp_v0;

    OnGuardAdd();
    temp_a1 = M2C_FIELD(arg0, void **, 0x1050);
    if (temp_a1 != NULL) {
        temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x48), temp_a1);
    }
}
