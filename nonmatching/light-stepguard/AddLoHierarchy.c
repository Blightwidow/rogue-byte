#include "m2c_macros.h"

void AddLoHierarchy(void *arg0) {
    void *temp_a3;

    M2C_FIELD(arg0, s64 *, 0x28) = (s64) (M2C_FIELD(arg0, s64 *, 0x28) | (0x8000 << 0x2D));
    M2C_FIELD(temp_a3, M2C_UNK (**)(void *, M2C_UNK, void *, void *), 0x24)(arg0 + M2C_FIELD(temp_a3, s16 *, 0x20), 0, arg0, temp_a3);
    temp_a3 = M2C_FIELD(arg0, void **, 0xC);
}
