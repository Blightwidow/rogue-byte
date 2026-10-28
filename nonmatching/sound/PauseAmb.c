#include "m2c_macros.h"

M2C_UNK SetAmbGrf(void *, M2C_UNK, M2C_UNK);        /* extern */

void PauseAmb(void *arg0) {
    s16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x4E) + 1;
    M2C_FIELD(arg0, u16 *, 0x4E) = (u16) temp_v1;
    if (temp_v1 == 1) {
        SetAmbGrf(arg0, 6, 2);
    }
}
