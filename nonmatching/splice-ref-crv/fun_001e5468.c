#include "m2c_macros.h"

void func_001E5468(void *arg0) {
    void *temp_a1;
    void *temp_v0;

    temp_a1 = M2C_FIELD(arg0, void **, 0x64);
    if (temp_a1 != NULL) {
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x194)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x190), temp_a1);
        temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
        M2C_FIELD(arg0, void **, 0x64) = NULL;
    }
}
