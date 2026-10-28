#include "m2c_macros.h"

M2C_UNK SetAmbGrf(s64, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK StopAmb(s64, M2C_UNK);                      /* extern */

void OnAmbVoicePolled(s32 arg0, s64 arg1) {
    s64 temp_s0;
    void *temp_v0;

    temp_s0 = (s64) (arg1 << 0x20) >> 0x20;
    if (arg0 == 0) {
        StopAmb(temp_s0, 0);
    } else {
        SetAmbGrf(temp_s0, 0x400, 0x400);
    }
    temp_v0 = M2C_FIELD(temp_s0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32), 0x14)(temp_s0 + M2C_FIELD(temp_v0, s16 *, 0x10));
}
