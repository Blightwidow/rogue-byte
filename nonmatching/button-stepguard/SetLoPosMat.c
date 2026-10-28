#include "m2c_macros.h"

void SetLoPosMat(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;

    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s128), 0xEC)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xE8), M2C_FIELD(arg1, s128 *, 0x30));
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0xF4)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0xF0), arg1);
}
