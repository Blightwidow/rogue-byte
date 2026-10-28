#include "m2c_macros.h"

M2C_UNK ActivateAct(void *, void *);                /* extern */

void ActivateActseg(void *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x20);
    if (temp_a0 != 0) {
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0xA8), s32 *, 0xD0) = temp_a0;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0xA8), s32 *, 0xD4) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + 0x1C);
        return;
    }
    ActivateAct(arg0, arg0);
}
