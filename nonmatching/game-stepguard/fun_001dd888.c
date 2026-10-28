#include "m2c_macros.h"

void func_001DD888(void *arg0) {
    void *temp_a1;
    void *temp_v0;
    void *temp_v0_2;

    if (M2C_FIELD(arg0, void **, 0x24) != NULL) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x5C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x58));
        temp_a1 = M2C_FIELD(arg0, void **, 0x24);
        temp_v0_2 = M2C_FIELD(temp_a1, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x194)(temp_a1 + M2C_FIELD(temp_v0_2, s16 *, 0x190), temp_a1);
    }
}
