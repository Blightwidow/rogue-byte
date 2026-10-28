#include "m2c_macros.h"

M2C_UNK Mount_SetState(void *, M2C_UNK);            /* extern */
M2C_UNK OnPoActive();                               /* extern */

void Mount_OnPoActive(void *arg0, s32 arg1) {
    OnPoActive();
    if (arg1 != 0) {
        Mount_SetState(arg0, 1);
    } else if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        Mount_SetState(arg0, 0);
    }
}
