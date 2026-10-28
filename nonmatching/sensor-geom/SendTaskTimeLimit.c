#include "m2c_macros.h"

s32 FTaskRunning(s32);                              /* extern */

void SendTaskTimeLimit(void *arg0, s32 arg1) {
    M2C_UNK sp4;
    void *temp_v1;

    if (FTaskRunning(arg1) != 0) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 0x17, 0, 1);
    }
}
