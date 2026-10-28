#include "m2c_macros.h"

M2C_UNK GoalStack_Pop(s32);                         /* extern */

void Goal_Pop(void **arg0) {
    s32 temp_s0;
    void *temp_a1;
    void *temp_v0;

    temp_a1 = *arg0;
    if (temp_a1 != NULL) {
        temp_s0 = M2C_FIELD(temp_a1, s32 *, 0x10) + 0x26C;
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x48), temp_a1);
        temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
        GoalStack_Pop(temp_s0);
        *arg0 = NULL;
    }
}
