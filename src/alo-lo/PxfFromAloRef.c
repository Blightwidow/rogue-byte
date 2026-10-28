#include "m2c_macros.h"

M2C_UNK PxfFromRef(s32, s32, void *);               /* extern */

void PxfFromAloRef(void *arg0, s32 arg1) {
    PxfFromRef(arg1, M2C_FIELD(arg0, s32 *, 0x10), arg0);
}
