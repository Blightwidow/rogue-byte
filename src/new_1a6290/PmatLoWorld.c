#include "m2c_macros.h"

void PmatLoWorld(void *arg0) {
    s16 temp_a1;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    temp_a1 = M2C_FIELD(temp_v1, s16 *, 0xF8);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, s16), 0xFC)(arg0 + temp_a1, temp_a1);
}
