#include "m2c_macros.h"

M2C_UNK GoalHit_Deactivate();                       /* extern */

void func_00179820(void *arg0) {
    void *temp_a1;
    void *temp_v0;

    GoalHit_Deactivate();
    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xFEC);
    if (temp_a1 != NULL) {
        temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x48), temp_a1);
    }
}
