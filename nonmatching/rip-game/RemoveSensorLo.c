#include "m2c_macros.h"

s32 PentryFindSensorLo();                           /* extern */
M2C_UNK SetSensorEntryState(void *, s32, M2C_UNK);  /* extern */
M2C_UNK memmove(s32, s32, s32);                     /* extern */

void RemoveSensorLo(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = PentryFindSensorLo();
    if (temp_v0 != 0) {
        SetSensorEntryState(arg0, temp_v0, 0);
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0xFC) - 1;
        M2C_FIELD(arg0, s32 *, 0xFC) = temp_v0_2;
        memmove(temp_v0, temp_v0 + 0x10, ((s32) ((arg0 + ((temp_v0_2 * 0x10) + 0x100)) - temp_v0) >> 4) * 0x10);
    }
}
