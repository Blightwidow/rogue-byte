#include "m2c_macros.h"

M2C_UNK CloneXfm();                                 /* extern */
M2C_UNK PattachCrv(void *, M2C_UNK);                /* extern */

void CloneCrv(void *arg0) {
    CloneXfm();
    if (M2C_FIELD(arg0, s32 *, 0x17C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x17C) = 0;
        PattachCrv(arg0, 0);
    }
}
