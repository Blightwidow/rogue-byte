#include "m2c_macros.h"

void func_001DD6C8(void *arg0) {
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;

    if (M2C_FIELD(arg0, void **, 0x24) != NULL) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x54)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x50));
        temp_a2 = M2C_FIELD(arg0, void **, 0x24);
        temp_v0_2 = M2C_FIELD(temp_a2, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *), 0x18C)(temp_a2 + M2C_FIELD(temp_v0_2, s16 *, 0x188), -1, temp_a2);
    }
}
