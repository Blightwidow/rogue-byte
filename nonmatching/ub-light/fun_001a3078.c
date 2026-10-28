#include "m2c_macros.h"

M2C_UNK func_00227788(M2C_UNK *);                   /* extern */
extern M2C_UNK B_004435F0;

void func_001A3078(void **arg0) {
    void *temp_a2;
    void *temp_v0;

    if (*arg0 != NULL) {
        func_00227788(&B_004435F0);
        temp_a2 = *arg0;
        temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x18C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x188), -1, temp_a2);
    }
}
