#include "m2c_macros.h"

M2C_UNK func_001CB518();                            /* extern */

void OnHbskPoolClaim(void *arg0) {
    func_001CB518();
    M2C_FIELD(arg0, s32 *, 0x17C) = 0;
}
