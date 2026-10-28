#include "m2c_macros.h"

M2C_UNK PloLeaseCloneObject(s32, M2C_UNK);          /* extern */
s32 PloLeased();                                    /* extern */

void EnsureLeasedObject(s32 arg0) {
    if (PloLeased() == 0) {
        PloLeaseCloneObject(arg0, 1);
    }
}
