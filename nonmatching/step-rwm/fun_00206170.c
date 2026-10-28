#include "m2c_macros.h"

void func_00206170(void *arg0) {
    M2C_UNK sp4;
    void *temp_v0;
    void *temp_v1;

    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0xD4)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xD0), 0);
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 0xE, 1, 1, 0);
}
