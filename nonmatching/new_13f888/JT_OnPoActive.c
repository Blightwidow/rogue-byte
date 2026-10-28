#include "m2c_macros.h"

M2C_UNK OnPoActive();                               /* extern */
M2C_UNK RetractAsegaHandle(void *);                 /* extern */

void JT_OnPoActive(void *arg0, s32 arg1) {
    void *temp_v0;

    OnPoActive();
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x34C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x348));
    if (arg1 == 0) {
        RetractAsegaHandle(arg0 + 0x1310);
        M2C_FIELD(arg0, s32 *, 0x1314) = -1;
    }
}
