#include "m2c_macros.h"

void SetSearchGoal(void *arg0, void *arg1) {
    void *temp_a1;
    void *temp_v0;
    void *temp_v0_2;

    temp_a1 = M2C_FIELD(arg0, void **, 0x44);
    if (arg1 != temp_a1) {
        if (temp_a1 != NULL) {
            temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x14)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x10), temp_a1);
        }
        M2C_FIELD(arg0, void **, 0x44) = arg1;
        if (arg1 != NULL) {
            temp_v0_2 = M2C_FIELD(arg1, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0xC)(arg1 + M2C_FIELD(temp_v0_2, s16 *, 8));
        }
        M2C_FIELD(arg0, s32 *, 0x48) = 1;
    }
}
