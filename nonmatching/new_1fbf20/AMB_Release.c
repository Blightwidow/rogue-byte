#include "m2c_macros.h"

M2C_UNK BASIC_Destruct(M2C_UNK);                    /* extern */
M2C_UNK FreeAmb(void *);                            /* extern */

void AMB_Release(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x4C) - 1;
    M2C_FIELD(arg0, u16 *, 0x4C) = temp_v0;
    if (((temp_v0 << 0x10) == 0) && (arg0 != NULL)) {
        BASIC_Destruct(0);
        FreeAmb(arg0);
    }
}
