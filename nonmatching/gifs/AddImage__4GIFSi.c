#include "m2c_macros.h"

void AddImage__4GIFSi(void *arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8), 0);
    temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (temp_v0_2 + 0x10);
    M2C_FIELD(temp_v0_2, s64 *, 0) = (s64) (arg1 | (0x8000 << 0x2C));
    M2C_FIELD(temp_v0_2, s64 *, 8) = 0;
}
