#include "m2c_macros.h"

M2C_UNK GoalStack_Clear(s32);                       /* extern */
void *func_00205438(s32, M2C_UNK);                  /* extern */

void func_001B9CA0(s32 arg0, s32 arg1) {
    M2C_UNK (*temp_a1)(void *, M2C_UNK);
    void *temp_v0;
    void *temp_v1;

    GoalStack_Clear(arg0 + 0x26C);
    if (arg1 != 0) {
        temp_v0 = func_00205438(arg0, 0xC6);
        temp_v1 = M2C_FIELD(temp_v0, void **, 0xC);
        temp_a1 = M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK), 0x44);
        temp_a1(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x40), temp_a1);
    }
}
