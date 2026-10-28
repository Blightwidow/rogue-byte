#include "m2c_macros.h"

s32 FTaskRunning();                                 /* extern */

void SendTaskEvent(void *arg0, s32 arg1, s32 arg2) {
    s32 sp10;
    s32 sp14;
    void *temp_v1;

    sp10 = arg1;
    sp14 = arg2;
    if (FTaskRunning() != 0) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32 *, s32 *), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 0x11, 0, 2, &sp10, &sp14);
    }
}
